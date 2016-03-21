//전자사전의 메인화면

#ifndef CYDICMAIN_H
#define CYDICMAIN_H

#include <QMainWindow>
#include "ckdbengine.h" //DB 관리를 위한 엔진을 include한다.
#include <QtWebKitWidgets/QWebView>
#include <QPrinter>
#include <QPrintPreviewDialog>

namespace Ui {
class CyDicMain;
}

class CyDicMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit CyDicMain(QWidget *parent = 0);
    ~CyDicMain();
    QString getContentFromHtmlEditor()const;
    void setContentToHtmlEditor(QString content);
protected:
     //키입력을 감시해서 다른 행동을 하게 하기 위한 일종의 후킹함수
    bool eventFilter(QObject* obj, QEvent* event);

signals:
    void selectImage(); //signal emitted from js

private slots:

    void on_listViewTitle_clicked(const QModelIndex &index);
    void on_pushButtonNew_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonConfirm_clicked();
    void on_pushButtonTitleInsert_clicked();

    void onSelectImage(); //slot connected to the js emitted signal

    void on_pushButtonBodyInsert_clicked();

    void on_listWidgetBody_currentRowChanged(int currentRow);

    void on_pushButtonFullScreen_clicked();

    void on_pushButtonPrint_clicked();

    void slotPrint(QPrinter *);

private:
    Ui::CyDicMain *ui;
    CKDBEngine *sqlDb;

    QString strBodyHtml;
    QString strBodyPlainText;

    ItemBody* bodyArray;
    int currentBodyPrimaryNumber;
};

#endif // CYDICMAIN_H
