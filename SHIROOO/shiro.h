#ifndef SHIRO_H
#define SHIRO_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class SHIRO;
}
QT_END_NAMESPACE

class SHIRO : public QMainWindow
{
    Q_OBJECT

public:
    explicit SHIRO(QWidget *parent = nullptr);
    ~SHIRO();

signals:
    void startClicked();

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_returnPressed();
    void on_EXIT_clicked();
    void onCohereResponse(QNetworkReply *reply);
    void hideMenu();
    void openAboutFile();
    void on_startButton_clicked();
    void on_aboutButton_clicked();


    void on_MENU_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::SHIRO *ui;
    QNetworkAccessManager *networkManager;
    QString currentPattern;
    QString currentLanguage = "английский";
    QString updateLanguage();
    QWidget* createMessageBubble(const QString &text, bool isUser);
    void sendMessageToCohere(const QString &message);
    void scrollToBottom();
    void setupLogo();
    QWidget *menuWidget;
    QLabel *videoLabel;

    QMovie *movie;
    QPushButton *startButton;
    QPushButton *aboutButton;
    void setupMainMenu();


};

#endif // SHIRO_H


