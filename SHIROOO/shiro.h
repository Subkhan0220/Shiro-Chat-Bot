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

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_returnPressed();
    void on_EXIT_clicked();
    void onCohereResponse(QNetworkReply *reply);

private:
    Ui::SHIRO *ui;
    QNetworkAccessManager *networkManager;

    QWidget* createMessageBubble(const QString &text, bool isUser);
    void sendMessageToCohere(const QString &message);
    void scrollToBottom();
    void setupLogo();
};

#endif // SHIRO_H


