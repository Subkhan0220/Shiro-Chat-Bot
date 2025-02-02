/********************************************************************************
** Form generated from reading UI file 'shiro.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIRO_H
#define UI_SHIRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SHIRO
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *image;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *MENU;
    QPushButton *EXIT;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *SHIRO)
    {
        if (SHIRO->objectName().isEmpty())
            SHIRO->setObjectName("SHIRO");
        SHIRO->resize(1920, 1080);
        SHIRO->setStyleSheet(QString::fromUtf8("background-color: rgb(9, 22, 46);\n"
""));
        centralwidget = new QWidget(SHIRO);
        centralwidget->setObjectName("centralwidget");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 750, 261, 81));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);\n"
"font: 700 20pt \"Segoe UI\";"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(260, 750, 261, 81));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);\n"
"font: 700 20pt \"Segoe UI\";"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 830, 261, 81));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);\n"
"font: 700 20pt \"Segoe UI\";"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(260, 830, 261, 81));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);\n"
"font: 700 20pt \"Segoe UI\";"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(700, 70, 1151, 791));
        textEdit->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"color: rgb(204, 204, 204);"));
        textEdit->setReadOnly(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1790, 870, 61, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(7, 52, 135);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(520, 870, 1271, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 38, 38);\n"
"color: rgb(184, 184, 184);"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(520, 70, 1331, 791));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("font: 20pt \"Arial\";"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1327, 787));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        image = new QLabel(centralwidget);
        image->setObjectName("image");
        image->setGeometry(QRect(20, 0, 481, 141));
        image->setPixmap(QPixmap(QString::fromUtf8(":/res/logo")));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 301, 481, 441));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 220, 501, 61));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(10, 160, 501, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(1860, 70, 61, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);\n"
"font: 700 16pt \"Terminal\";"));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(1860, 130, 61, 61));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);\n"
"font: 700 16pt \"Terminal\";"));
        MENU = new QPushButton(centralwidget);
        MENU->setObjectName("MENU");
        MENU->setGeometry(QRect(1860, 190, 61, 61));
        MENU->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);\n"
"font: 700 16pt \"Terminal\";"));
        EXIT = new QPushButton(centralwidget);
        EXIT->setObjectName("EXIT");
        EXIT->setGeometry(QRect(1860, 250, 61, 61));
        EXIT->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 40, 82);\n"
"font: 700 16pt \"Terminal\";"));
        SHIRO->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SHIRO);
        statusbar->setObjectName("statusbar");
        SHIRO->setStatusBar(statusbar);
        menubar = new QMenuBar(SHIRO);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 17));
        SHIRO->setMenuBar(menubar);

        retranslateUi(SHIRO);

        QMetaObject::connectSlotsByName(SHIRO);
    } // setupUi

    void retranslateUi(QMainWindow *SHIRO)
    {
        SHIRO->setWindowTitle(QCoreApplication::translate("SHIRO", "SHIRO", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SHIRO", "\320\224\321\200\321\203\320\266\320\265\321\201\320\272\320\270\320\271", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SHIRO", "\320\236\321\204\320\270\321\206\320\270\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        pushButton_5->setText(QCoreApplication::translate("SHIRO", "\320\240\320\260\320\267\320\262\321\221\321\200\320\275\321\203\321\202\321\213\320\271", nullptr));
        pushButton_6->setText(QCoreApplication::translate("SHIRO", "\320\241\320\266\320\260\321\202\321\213\320\271", nullptr));
        pushButton->setText(QCoreApplication::translate("SHIRO", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        image->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("SHIRO", "RU", nullptr));
        pushButton_10->setText(QCoreApplication::translate("SHIRO", "DARK", nullptr));
        MENU->setText(QCoreApplication::translate("SHIRO", "MENU", nullptr));
        EXIT->setText(QCoreApplication::translate("SHIRO", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SHIRO: public Ui_SHIRO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIRO_H
