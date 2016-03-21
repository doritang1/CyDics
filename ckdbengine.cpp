#include "ckdbengine.h"
#include <QMessageBox>

CKDBEngine::CKDBEngine()
{

}

//파일에 DB생성, 기본값이 있으므로 인자가 지정되지 않으면 기본값으로 InMemory DB가 생성됨
bool CKDBEngine::createDb(const QString &dbType, const QString &fileName)
{
    db = QSqlDatabase::addDatabase(dbType);
    db.setDatabaseName(fileName);
    if(!db.open()){
        return false;
    }

     QSqlQuery qry;
     QString qryStr = "CREATE TABLE Title ("
                      "primaryKey INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "itemText VARCHAR, "
                      "foreignKey INTEGER)";
     qry.prepare(qryStr);
     qry.exec();
//     qry.exec(QString("INSERT INTO Title VALUES(null, '%1')").arg("가나"));
//     qry.exec(QString("INSERT INTO Title VALUES(null, '%1')").arg("다라"));
//     qry.exec(QString("INSERT INTO Title VALUES(null, '%1')").arg("마바"));


     modelTitle = new QSqlTableModel();
     modelTitle->setTable("Title");
     modelTitle->setSort(1,Qt::AscendingOrder);
     modelTitle->select();

     qryStr = "CREATE TABLE Body ("
              "primaryKey INTEGER PRIMARY KEY AUTOINCREMENT, "
              "itemText VARCHAR, "
              "foreignKey INTEGER, "
              "FOREIGN KEY(foreignKey) references Title(primaryKey))";
     qry.prepare(qryStr);
     qry.exec();
//     qry.exec(QString("INSERT INTO Body VALUES(null, '%1', '%2')").arg("abc").arg(1));
//     qry.exec(QString("INSERT INTO Body VALUES(null, '%1', '%2')").arg("def").arg(2));
//     qry.exec(QString("INSERT INTO Body VALUES(null, '%1', '%2')").arg("ghi").arg(3));

     return true;
}

//선택된 index를 넘겨주면 모델에서 찾아서 primary key 값을 찾아준다.
int CKDBEngine::getKeyNum(const QModelIndex &index, const QSqlTableModel *model)
{
    QSqlRecord rec = model->record(index.row());
    return rec.field("foreignKey").value().toInt();
}

//외래키 값을 주면 해당 값을 찾아준다.
ItemBody* CKDBEngine::getRelatedData(const int foreignkey)
{
    QSqlQuery qryFilter;
    QString qryStrFilter = "SELECT primaryKey, foreignKey, itemText FROM Body WHERE foreignKey = :foreignKey";
    qryFilter.prepare(qryStrFilter);
    qryFilter.bindValue(":foreignKey", foreignkey);

    ItemBody* itemBodyArray = new ItemBody[100];
    if(!qryFilter.exec()){
        // Error Handling, check query.lastError(), probably return
        qDebug() << qryFilter.lastError().text();
    } else {
        int counter = 0;
        while(qryFilter.next()){
            //현재는 발견된 첫번째 데이터만을 리턴하고 끝남
            //수정요망
            itemBodyArray[counter].set_itemText(qryFilter.value("itemText").toString());
            itemBodyArray[counter].set_foreignKey(qryFilter.value("foreignKey").toInt());
            itemBodyArray[counter].set_primaryKey(qryFilter.value("primaryKey").toInt());
            counter++;
        }
        return itemBodyArray;
    }
    return itemBodyArray;
}

int CKDBEngine::insertData(ItemTitle &item, const int row)
{
    //model에 1줄을 빈줄을 하나 삽입한다.
    this->modelTitle->insertRows(row+1,1); //row는 삽입위치, 1은 삽입하는 줄의 갯수

    //삽입한 빈줄 내부의 itemText컬럼의 index값을 알아내어 그 위치에 값을 대입한다.
    //primaryKey컬럼은 자동증분이므로 필요 없다.
    int col_itemText = this->modelTitle->fieldIndex("itemText");
    int col_foreignKey = this->modelTitle->fieldIndex("foreignKey");
    QModelIndex idx_itemText = this->modelTitle->index(row+1, col_itemText);
    QModelIndex idx_foreignKey = this->modelTitle->index(row+1, col_foreignKey);
    this->modelTitle->setData(idx_itemText, item.get_itemText());

int selfKey;
    //실제 DB에 적용한다.
    this->modelTitle->database().transaction();//트랜잭션 시작
    if(this->modelTitle->submitAll()) //submitAll()이 성공하면
    {
        this->modelTitle->database().commit(); //database에 commit하고
        qDebug()<<item.get_primaryKey();
        if (item.get_primaryKey() > 0)
        {
            //primaryKey값이 selfKey값이 된다.
            selfKey = item.get_primaryKey();
        } else {
            //자동증분된 id값, 즉 primaryKey값을 반환한다.
            selfKey = this->modelTitle->query().lastInsertId().toInt();
        }
        this->modelTitle->setData(idx_foreignKey, selfKey);
        this->modelTitle->submitAll();
        this->modelTitle->database().commit();
    } else {
        this->modelTitle->database().rollback(); //실패하면 rollback한다.
    }

    //삽입후 다시 강제로 정렬한다.
    this->modelTitle->sort(1, Qt::AscendingOrder);

    //자동증분된 id값, 즉 primaryKey값을 반환한다.
    return selfKey;
}

int CKDBEngine::insertData(ItemBody &item)
{
    QSqlQuery qryInsert;
    QString qryInsertStatement = "INSERT INTO Body VALUES(null, :itemText, :foreignKey)";
    qryInsert.prepare(qryInsertStatement);

    //전달된 item객체의 내용을 읽는다.
    QString itemText = item.get_itemText();
    int foreignKey = item.get_foreignKey();

    //item객체의 내용에서 text를 INSERT 쿼리에 전달한다. key는 자동증분값이므로 필요 없다.
    qryInsert.bindValue(":itemText", itemText);
    qryInsert.bindValue(":foreignKey", foreignKey);
    qryInsert.exec();

    //쿼리를 실행한 후 자동증분값을 반환한다.
    return qryInsert.lastInsertId().toInt();
}

bool CKDBEngine::updateData(ItemTitle &item, const int row)
{
    //수정할 줄 내부의 itemText컬럼의 index값을 알아내어 그 위치에 값을 대입한다.
    //int col_primaryKey = this->modelTitle->fieldIndex("primaryKey");
    int col_itemText = this->modelTitle->fieldIndex("itemText");
    //QModelIndex idx_primaryKey = this->modelTitle->index(row, col_primaryKey);
    QModelIndex idx_itemText = this->modelTitle->index(row, col_itemText);
    //this->modelTitle->setData(idx_primaryKey, item.get_primaryKey());
    this->modelTitle->setData(idx_itemText, item.get_itemText());

    //실제 DB에 적용한다.
    this->modelTitle->database().transaction();//트랜잭션 시작
    if(this->modelTitle->submitAll()) //submitAll()이 성공하면
    {
        this->modelTitle->database().commit(); //database에 commit하고
    } else {
        this->modelTitle->database().rollback(); //실패하면 rollback한다.
    }
    return true;
}

bool CKDBEngine::updateData(ItemBody &item)
{
    QSqlQuery qryUpdate;
    QString qryUpdateStatement = "UPDATE Body SET foreignKey=:foreignKey, itemText=:itemText WHERE primaryKey=:primaryKey";
    qryUpdate.prepare(qryUpdateStatement);

    //전달된 item객체의 내용을 읽는다.
    QString itemText = item.get_itemText();
    int primaryKey = item.get_primaryKey();
    int foreignKey = item.get_foreignKey();

    //item객체의 내용에서 text를 UPDATE 쿼리에 전달한다.
    qryUpdate.bindValue(":foreignKey", foreignKey);
    qryUpdate.bindValue(":itemText", itemText);
    qryUpdate.bindValue(":primaryKey", primaryKey);

    return qryUpdate.exec();
}

bool CKDBEngine::deleteData(const int row)
{
    //body를 제외하고 title만 삭제할 경우. 다른 title은 그대로 남는다.

    //먼저 지우기 전에 title테이블의 foreign key값을 저장해 놓는다. 나중에 body테이블에서 삭제를 진행하기 위해
    int col_primaryKey = this->modelTitle->fieldIndex("foreignKey");
    int foreignKey = this->modelTitle->index(row, col_primaryKey).data().toInt();

    //row에서 1줄을 삭제
    this->modelTitle->removeRows(row, 1);

    this->modelTitle->database().transaction();
    if(this->modelTitle->submitAll()){
        this->modelTitle->database().commit();
    }else{
        this->modelTitle->database().rollback();
    }
    //삭제후 다시 강제로 정렬한다.
    this->modelTitle->sort(1, Qt::AscendingOrder);

    int i = QMessageBox::critical(0, "확인", "Title만 삭제라면 Yes, 본문까지 모두 삭제면 No를 누르세요",QMessageBox::Yes,QMessageBox::No);
    if(i == QMessageBox::No)
    {
        QSqlQuery qryDelete;

        QString qryDeleteStatement = "DELETE FROM Body WHERE foreignKey = :foreignKey";
        qryDelete.prepare(qryDeleteStatement);
        qryDelete.bindValue(":foreignKey", foreignKey);
        qryDelete.exec();

//        qryDeleteStatement = "DELETE FROM Title WHERE foreignKey = :foreignKey";
//        qryDelete.prepare(qryDeleteStatement);
//        qryDelete.bindValue(":foreignKey", foreignKey);
//        qryDelete.exec();

//        //삭제후 다시 강제로 정렬한다.
//        this->modelTitle->sort(1, Qt::AscendingOrder);

        return true;

    }else{
        return true;
    }
}
