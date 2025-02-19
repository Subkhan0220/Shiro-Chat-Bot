#include "shiro.h"
#include <QApplication>
#include "shiro.h"
#include <QDebug>
#include <QStringConverter>

    int main2(int argc, char *argv[]) {
    QApplication app(argc, argv);

    //utf
    qDebug() << QString::fromUtf8("кодировка установлена: UTF-8");

    SHIRO chat;
    chat.setWindowTitle("Чат-бот");
    chat.resize(400, 500);
    chat.show();

    return app.exec();
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SHIRO w;
    w.show();
    return a.exec();
}
