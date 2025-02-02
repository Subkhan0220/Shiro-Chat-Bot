#include "shiro.h"
#include "./ui_shiro.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QFrame>
#include <QFont>
#include <QScrollBar>
#include <QDebug>
#include <QTimer>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

SHIRO::SHIRO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SHIRO)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    setupLogo();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignTop);
    ui->scrollAreaWidgetContents->setLayout(layout);

    QFont font("Courier New", 13);
    ui->lineEdit->setFont(font);
    ui->lineEdit->setPlaceholderText("Введите сообщение...");
    ui->lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->lineEdit->setMinimumHeight(40);
    ui->lineEdit->setMaximumHeight(150);

    // сигналы
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &SHIRO::on_lineEdit_returnPressed);
    connect(ui->pushButton, &QPushButton::clicked, this, &SHIRO::on_pushButton_clicked);
    connect(networkManager, &QNetworkAccessManager::finished, this, &SHIRO::onCohereResponse);  // Исправлен вызов
}

SHIRO::~SHIRO()
{
    delete ui;
}

void SHIRO::setupLogo()
{
    QPixmap pix(":/resources/res/logo.png");
    if (!pix.isNull()) {
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    } else {
        qDebug() << "Ошибка загрузки логотипа!";
    }
}

QWidget* SHIRO::createMessageBubble(const QString &text, bool isUser)
{
    QWidget *bubble = new QWidget(this);
    QLabel *label = new QLabel(text, bubble);
    label->setWordWrap(true);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setStyleSheet("color: white; font-size: 18px;");

    QFrame *frame = new QFrame(bubble);
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Raised);
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    frame->setStyleSheet(isUser
                             ? "background-color: #3a3a3a; border-radius: 25px; padding: 15px;"
                             : "background-color: #222222; border-radius: 25px; padding: 15px;");

    QVBoxLayout *frameLayout = new QVBoxLayout(frame);
    frameLayout->addWidget(label);
    frame->setLayout(frameLayout);

    QVBoxLayout *layout = new QVBoxLayout(bubble);
    layout->addWidget(frame);
    layout->setAlignment(isUser ? Qt::AlignRight : Qt::AlignLeft);
    bubble->setLayout(layout);

    return bubble;
}

void SHIRO::scrollToBottom()
{
    QScrollBar *scrollBar = ui->scrollArea->verticalScrollBar();
    scrollBar->setValue(scrollBar->maximum());
}

void SHIRO::on_pushButton_clicked()
{
    QString userMessage = ui->lineEdit->text().trimmed();
    if (userMessage.isEmpty()) return;

    ui->lineEdit->clear();

    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    layout->addWidget(createMessageBubble("<b>Вы:<b> " + userMessage, true));
    scrollToBottom();

    sendMessageToCohere(userMessage);
}

// энтер
void SHIRO::on_lineEdit_returnPressed()
{
    if (QApplication::keyboardModifiers() & Qt::ControlModifier) {
        ui->lineEdit->setText(ui->lineEdit->text() + "\n");
    } else {
        on_pushButton_clicked();
    }
}

void SHIRO::sendMessageToCohere(const QString &userInput)
{
    QUrl url("https://api.cohere.ai/v1/generate");
    QNetworkRequest request(url);


    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer 7ukEvGnTAhiEo2987Is7cOKUXVsvvPwX0V3Wd0dz");


    QJsonObject json;
    json["model"] = "command-r-plus-08-2024";
    json["prompt"] = userInput;
    json["max_tokens"] = 666;
    json["temperature"] = 0.8;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    networkManager->post(request, data);
}

// кохере
void SHIRO::onCohereResponse(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonResponse.object();

        if (jsonObject.contains("generations") && jsonObject["generations"].isArray()) {
            QJsonArray generations = jsonObject["generations"].toArray();
            if (!generations.isEmpty()) {
                QString botResponse = generations[0].toObject()["text"].toString();
                QStringList words = botResponse.split(" ", Qt::SkipEmptyParts);
                for (int i = 0; i < qMin(3, words.size()); ++i) {
                    words[i] = "<h>" + words[i] + "</h>";
                }
                botResponse = words.join(" ");
                QString formattedText;
                QString currentLine;

                for (int i = 0; i < words.size(); ++i) {
                    const QString &word = words[i];
                    if (currentLine.length() + word.length() + 1 > 20) {
                        formattedText += currentLine.trimmed() + "\n";
                        currentLine = word;
                    } else {
                        if (!currentLine.isEmpty()) currentLine += " ";
                        currentLine += word;
                    }
                }
                if (!currentLine.isEmpty()) {
                    formattedText += currentLine.trimmed();
                }
                QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
                layout->addWidget(createMessageBubble("<b>Широ</b>: " + formattedText, false));
                scrollToBottom();
            }
        } else {
            qDebug() << "Ошибка в JSON-ответе от Cohere";
        }
    } else {
        qDebug() << "Ошибка сети: " << reply->errorString();
    }

    reply->deleteLater();
}




void SHIRO::on_EXIT_clicked()
{
    close();
}
