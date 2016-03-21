/********************************************************************************
** Form generated from reading UI file 'cydicmain.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYDICMAIN_H
#define UI_CYDICMAIN_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CyDicMain
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QListView *listViewTitle;
    QListWidget *listWidgetBody;
    QGridLayout *gridLayout;
    QPushButton *pushButtonNew;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonConfirm;
    QPushButton *pushButtonTitleInsert;
    QPushButton *pushButtonBodyInsert;
    QPushButton *pushButtonFullScreen;
    QPushButton *pushButtonPrint;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPrimaryKey;
    QLineEdit *lineEditTitle;
    QWebView *webViewBody;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CyDicMain)
    {
        if (CyDicMain->objectName().isEmpty())
            CyDicMain->setObjectName(QStringLiteral("CyDicMain"));
        CyDicMain->resize(615, 714);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CyDicMain->sizePolicy().hasHeightForWidth());
        CyDicMain->setSizePolicy(sizePolicy);
        CyDicMain->setMinimumSize(QSize(615, 714));
        centralWidget = new QWidget(CyDicMain);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listViewTitle = new QListView(centralWidget);
        listViewTitle->setObjectName(QStringLiteral("listViewTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listViewTitle->sizePolicy().hasHeightForWidth());
        listViewTitle->setSizePolicy(sizePolicy1);
        listViewTitle->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewTitle->setModelColumn(0);

        verticalLayout->addWidget(listViewTitle);

        listWidgetBody = new QListWidget(centralWidget);
        listWidgetBody->setObjectName(QStringLiteral("listWidgetBody"));
        sizePolicy1.setHeightForWidth(listWidgetBody->sizePolicy().hasHeightForWidth());
        listWidgetBody->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(listWidgetBody);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonNew = new QPushButton(centralWidget);
        pushButtonNew->setObjectName(QStringLiteral("pushButtonNew"));

        gridLayout->addWidget(pushButtonNew, 0, 0, 1, 1);

        pushButtonDelete = new QPushButton(centralWidget);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));

        gridLayout->addWidget(pushButtonDelete, 0, 1, 1, 1);

        pushButtonConfirm = new QPushButton(centralWidget);
        pushButtonConfirm->setObjectName(QStringLiteral("pushButtonConfirm"));

        gridLayout->addWidget(pushButtonConfirm, 0, 2, 1, 1);

        pushButtonTitleInsert = new QPushButton(centralWidget);
        pushButtonTitleInsert->setObjectName(QStringLiteral("pushButtonTitleInsert"));

        gridLayout->addWidget(pushButtonTitleInsert, 1, 0, 1, 1);

        pushButtonBodyInsert = new QPushButton(centralWidget);
        pushButtonBodyInsert->setObjectName(QStringLiteral("pushButtonBodyInsert"));

        gridLayout->addWidget(pushButtonBodyInsert, 1, 1, 1, 1);

        pushButtonFullScreen = new QPushButton(centralWidget);
        pushButtonFullScreen->setObjectName(QStringLiteral("pushButtonFullScreen"));

        gridLayout->addWidget(pushButtonFullScreen, 1, 2, 1, 1);

        pushButtonPrint = new QPushButton(centralWidget);
        pushButtonPrint->setObjectName(QStringLiteral("pushButtonPrint"));

        gridLayout->addWidget(pushButtonPrint, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelPrimaryKey = new QLabel(centralWidget);
        labelPrimaryKey->setObjectName(QStringLiteral("labelPrimaryKey"));
        labelPrimaryKey->setMinimumSize(QSize(56, 20));
        labelPrimaryKey->setFrameShape(QFrame::StyledPanel);
        labelPrimaryKey->setFrameShadow(QFrame::Sunken);
        labelPrimaryKey->setLineWidth(2);
        labelPrimaryKey->setMidLineWidth(0);

        horizontalLayout->addWidget(labelPrimaryKey);

        lineEditTitle = new QLineEdit(centralWidget);
        lineEditTitle->setObjectName(QStringLiteral("lineEditTitle"));
        lineEditTitle->setMinimumSize(QSize(200, 20));

        horizontalLayout->addWidget(lineEditTitle);


        verticalLayout_2->addLayout(horizontalLayout);

        webViewBody = new QWebView(centralWidget);
        webViewBody->setObjectName(QStringLiteral("webViewBody"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(webViewBody->sizePolicy().hasHeightForWidth());
        webViewBody->setSizePolicy(sizePolicy2);
        webViewBody->setMinimumSize(QSize(320, 300));
        webViewBody->setBaseSize(QSize(900, 400));

        verticalLayout_2->addWidget(webViewBody);


        horizontalLayout_2->addLayout(verticalLayout_2);

        CyDicMain->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(CyDicMain);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CyDicMain->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CyDicMain);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CyDicMain->setStatusBar(statusBar);

        retranslateUi(CyDicMain);

        QMetaObject::connectSlotsByName(CyDicMain);
    } // setupUi

    void retranslateUi(QMainWindow *CyDicMain)
    {
        CyDicMain->setWindowTitle(QApplication::translate("CyDicMain", "CyDicMain", 0));
        pushButtonNew->setText(QApplication::translate("CyDicMain", "New", 0));
        pushButtonDelete->setText(QApplication::translate("CyDicMain", "Delete", 0));
        pushButtonConfirm->setText(QApplication::translate("CyDicMain", "Confirm", 0));
        pushButtonTitleInsert->setText(QApplication::translate("CyDicMain", "Title Insert", 0));
        pushButtonBodyInsert->setText(QApplication::translate("CyDicMain", "Body Insert", 0));
        pushButtonFullScreen->setText(QApplication::translate("CyDicMain", "Fill Editor", 0));
        pushButtonPrint->setText(QApplication::translate("CyDicMain", "Print", 0));
        labelPrimaryKey->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CyDicMain: public Ui_CyDicMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYDICMAIN_H
