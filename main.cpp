//#include "mainwindow.h"

#include "ManagerBot.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

    const QString token = FileWorker::readFileJson("../config.json").object().value("token").toString();
    ManagerBot managerBot(token);
    managerBot.startBot();

    return a.exec();
}
