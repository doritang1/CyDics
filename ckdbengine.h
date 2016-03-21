//데이터베이스 생성 및 관리를 위한 엔진이다.
//updated Mar-22-2016

#ifndef CKDBENGINE_H
#define CKDBENGINE_H

#include <QtSql>
#include <QSqlTableModel>
#include "itemtitle.h"
#include "itembody.h"

class CKDBEngine
{
public:
    CKDBEngine();
    ~CKDBEngine();

    //DB 생성함수. DB파일의 이름과 DB타입을 문자열 참조자로 받는다.
    //dbType의 기본값은 QSQLITE이고,
    //fileName의 기본값은 ":memory:"이다.
    bool createDb(const QString &dbType = "QSQLITE", const QString &fileName = ":memory:");

    //model의 index값을 주면 그 row의 primary key값을 돌려준다.
    int getKeyNum(const QModelIndex &index, const QSqlTableModel *model);

    //타이틀의 key값을 주면 본문을 읽어 온다.
    ItemBody* getRelatedData(const int foreignkey);

    //title 테이블의 데이터를 제공하는 모델
    QSqlTableModel *modelTitle;

    //title 삽입, overloaded
    int insertData(ItemTitle &item, const int row);
    //body 삽입, overloaded
    int insertData(ItemBody &item);

    //title 수정, overloaded
    bool updateData(ItemTitle &item, const int row);

    //body 수정, overloaded
    bool updateData(ItemBody &item);

    //title 삭제, overloaded
    bool deleteData(const int row);
    //body 삭제, overloaded

private:
    //DB객체
    QSqlDatabase db;
};

#endif // CKDBENGINE_H
