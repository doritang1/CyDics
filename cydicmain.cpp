#include "cydicmain.h"
#include "ui_cydicmain.h"
#include "ckdbengine.h"

#include <QMessageBox>
#include <QWebFrame>
#include <QKeyEvent>

CyDicMain::CyDicMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CyDicMain)
{
    ui->setupUi(this);

    sqlDb = new CKDBEngine();
    sqlDb->createDb("QSQLITE", "CustomerInfos.sqlite"); //파일로 생성
    //sqlDb->createDb("QSQLITE"); //기본값(InMemory)로 생성


    ui->listViewTitle->setModel(sqlDb->modelTitle);
    ui->listViewTitle->setModelColumn(1);

    //ui->webViewBody->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOn);

    //prevents the QWebView of opening external links in the editor.
    ui->webViewBody->page()->setLinkDelegationPolicy(QWebPage::DelegateExternalLinks);
    connect(this, SIGNAL(selectImage()), this, SLOT(onSelectImage()));
    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    ui->webViewBody->setUrl(url);
    ui->webViewBody->installEventFilter(this);//웹뷰로부터 오는 이벤트를 받겠다는 뜻


    //insert QWebView object to javascript.
    ui->webViewBody->page()->mainFrame()->addToJavaScriptWindowObject("hostObject", this);

    ui->webViewBody->page()->mainFrame()->evaluateJavaScript("tinyMCE.get('mytextarea').execCommand('mceFullScreen');");
}

CyDicMain::~CyDicMain()
{
    delete ui;
}

void CyDicMain::on_listViewTitle_clicked(const QModelIndex &index)
{
    this->setContentToHtmlEditor("");
    int selfKey = sqlDb->getKeyNum(index, sqlDb->modelTitle);
    ui->labelPrimaryKey->setText(QString::number(selfKey));

    bodyArray = sqlDb->getRelatedData(selfKey);

    ui->lineEditTitle->setText(ui->listViewTitle->currentIndex().data(Qt::DisplayRole).toString());
//qDebug()<<ui->listViewTitle->currentIndex().data(Qt::DisplayRole).toString();
    ui->listWidgetBody->clear();
    for (int i = 0; i<=99; ++i)
    {
        strBodyHtml = bodyArray[i].get_itemText();
        if(strBodyHtml.isEmpty()){
            return;
        }
        // QRegExp("<[^>]*>")는 HTML에서 태그를 없앤다. 다만 완벽하지는 않다.
        // section()함수는 스트링을 "\n"을 기준으로 쪼갠 뒤 첫번째(0) 조각 부터 N-1번째 조각까지를 반환한다.
        // 다음에서는 0부터 0, 즉 첫번째 조각을 반환한다.
        strBodyPlainText = strBodyHtml.remove("&nbsp;").remove(QRegExp("<[^>]*>")).section("\n",0,0);
        ui->listWidgetBody->addItem(strBodyPlainText);
    }
    //    //CSS파일을 로드함
    //    QUrl url("file:///"+QApplication::applicationDirPath()+"/dictionary.css");
    //    ui->webViewBody->settings()->setUserStyleSheetUrl(url);
}

void CyDicMain::on_pushButtonNew_clicked()
{
    ui->labelPrimaryKey->clear();
    ui->lineEditTitle->clear();
    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    ui->webViewBody->setUrl(url);
}

void CyDicMain::on_pushButtonDelete_clicked()
{
    //listView의 selectionModel에서 현재 선택된 줄 번호를 얻어 온다.
    int row = ui->listViewTitle->selectionModel()->currentIndex().row();

    //줄번호를 주면 데이터를 삭제함
    sqlDb->deleteData(row);

    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    ui->webViewBody->setUrl(url);

//    이 코드는 tableView에만 적용되며 이번에는 이 코드 대신에 model의 sort()를 강제 적용하는 방법을 썼다.
//    //tableView는 삭제명령이 정상적으로 이뤄졌음에도 불구하고
//    //여전히 삭제된 줄의 헤더에 "!"표시만 해 두고 빈 칸을 유지하므로
//    //헤더에 묶인 줄 전체를 감춰서 이를 유저에게 보이지 않게 한다.
//    QHeaderView *hv = ui->tableViewTitle->verticalHeader();
//    hv->hideSection(row);

    //정상 완료되었음을 알린다.
    QMessageBox::information(this, "삭제", "삭제가 성공하였습니다.");
}

void CyDicMain::on_pushButtonTitleInsert_clicked()
{
    int foreignKey = ui->labelPrimaryKey->text().toInt();

    ItemTitle title;
    title.set_primaryKey(foreignKey);
    title.set_foreignKey(foreignKey);
    title.set_itemText(ui->lineEditTitle->text());
    int row = ui->listViewTitle->selectionModel()->currentIndex().row();
    sqlDb->insertData(title, row);

    ui->lineEditTitle->clear();
    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    ui->webViewBody->setUrl(url);

    QMessageBox::information(this, "삽입", "삽입이 성공하였습니다.");
}

//키입력을 감시해서 다른 행동을 하게 하기 위한 일종의 후킹함수
//한글입력후 엔터등을 눌렀을 때 캐럿이 사라지는 것을 막고자 포커스를 죽였다가 살린다.
//이 경우 올바른 해결책은 IME메시지를 받아 포커스를 조작하는 것인데 아직 못했다.
bool CyDicMain::eventFilter(QObject* obj, QEvent* event)
{
    if(obj == ui->webViewBody)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            int key = keyEvent->key();
            if(key == Qt::Key_Shift){
                return false;
            }else if(key == Qt::Key_Return||Qt::Key_Enter||Qt::Key_Space
                    ||Qt::Key_Insert||Qt::Key_Delete||Qt::Key_Home
                    ||Qt::Key_End||Qt::Key_PageUp||Qt::Key_PageDown
                    ||Qt::Key_Left||Qt::Key_Right||Qt::Key_Up||Qt::Key_Down)
            {
                ui->webViewBody->clearFocus();
                ui->webViewBody->setFocus();
                return false;
            }
        }else{
            return false;
        }
    }else{
        //pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
    }
}

QString CyDicMain::getContentFromHtmlEditor() const
{
    return ui->webViewBody->page()->mainFrame()->evaluateJavaScript("tinyMCE.activeEditor.getContent();").toString();
}

void CyDicMain::setContentToHtmlEditor(QString content)
{   //replace처리를 하지 않으면 개행문자에서 출력이 잘린다(multiline 처리)
    ui->webViewBody->page()->mainFrame()->evaluateJavaScript(QString("tinyMCE.activeEditor.setContent('%1')").arg(content).replace("\n","\\n"));
}

void CyDicMain::on_pushButtonConfirm_clicked()
{
    if(ui->labelPrimaryKey->text().isEmpty()){ //삽입시 처리
        ItemTitle title;
        title.set_itemText(ui->lineEditTitle->text());
        int row = ui->listViewTitle->selectionModel()->currentIndex().row();
        int foreignKey = sqlDb->insertData(title, row);

        ItemBody body;
        body.set_foreignKey(foreignKey);
        body.set_itemText(this->getContentFromHtmlEditor());
        sqlDb->insertData(body);

        ui->lineEditTitle->clear();
        QString CurDir =  qApp->applicationDirPath();
        QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
        ui->webViewBody->setUrl(url);

        QMessageBox::information(this, "삽입", "삽입이 성공하였습니다.");
    }else{ //수정시 처리
        ItemBody body;
        body.set_primaryKey(this->currentBodyPrimaryNumber);
        body.set_itemText(this->getContentFromHtmlEditor());
        body.set_foreignKey(ui->labelPrimaryKey->text().toInt());

        if(sqlDb->updateData(body)){
            QMessageBox::information(this, "수정", "수정이 성공하였습니다.");
        }else{
            QMessageBox::information(this, "수정", "수정이 실패하였습니다.");
        }

        ItemTitle title;
        title.set_itemText(ui->lineEditTitle->text());
        int row = ui->listViewTitle->selectionModel()->currentIndex().row();
        title.set_primaryKey(sqlDb->modelTitle->record(row).field("primaryKey").value().toInt());
        sqlDb->updateData(title, row);

        ui->listWidgetBody->clear();
        ui->lineEditTitle->clear();
        QString CurDir =  qApp->applicationDirPath();
        QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
        ui->webViewBody->setUrl(url);
    }
}

void CyDicMain::onSelectImage()
{
    qDebug()<<"Hello!";
}

void CyDicMain::on_pushButtonBodyInsert_clicked()
{
    int foreignKey = ui->labelPrimaryKey->text().toInt();
    ItemBody body;
    body.set_foreignKey(foreignKey);
    body.set_itemText(this->getContentFromHtmlEditor());
    sqlDb->insertData(body);

    ui->lineEditTitle->clear();
    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    ui->webViewBody->setUrl(url);

    QMessageBox::information(this, "삽입", "삽입이 성공하였습니다.");
}

void CyDicMain::on_listWidgetBody_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
    {
        return;
    }
    currentBodyPrimaryNumber = bodyArray[currentRow].get_primaryKey();
    this->setContentToHtmlEditor(bodyArray[currentRow].get_itemText());
}

void CyDicMain::on_pushButtonFullScreen_clicked()
{
    ui->webViewBody->page()->mainFrame()->evaluateJavaScript("tinyMCE.get('mytextarea').execCommand('mceFullScreen');");
    //ui->webViewBody->page()->mainFrame()->evaluateJavaScript("tinyMCE.get('mytextarea').execCommand('mcePreView');");
    //ui->webViewBody->page()->mainFrame()->evaluateJavaScript("tinyMCE.get('mytextarea').execCommand('mcePrint');");
}

void CyDicMain::on_pushButtonPrint_clicked()
{
    //ui->webViewBody->page()->mainFrame()->evaluateJavaScript("tinyMCE.get('mytextarea').show();");

    QPrinter *pTestPrint = new QPrinter();
    QPrintPreviewDialog *pPrintPreDia= new QPrintPreviewDialog(pTestPrint , this);
    connect(pPrintPreDia, SIGNAL(paintRequested(QPrinter*)), SLOT(slotPrint(QPrinter *)));
    pPrintPreDia->exec();
}

void CyDicMain::slotPrint(QPrinter *a_p)
{
    QWebView *webviewPrint = new QWebView();
    webviewPrint->setFixedSize(QSize(a_p->width(),a_p->height()));
    webviewPrint->setHtml(this->getContentFromHtmlEditor());
    //webviewPrint->setHtml(ui->webViewBody->page()->mainFrame()->toHtml());

    a_p->setPaperSize(QPrinter::A4);
    a_p->setOutputFormat(QPrinter::NativeFormat);
    a_p->setOrientation(QPrinter::Portrait);
    a_p->setResolution(120);  // DPI 세팅 Default로 96으로 되어있음
    webviewPrint->print(a_p);
}
