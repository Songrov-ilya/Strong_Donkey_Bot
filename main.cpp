//#include "mainwindow.h"

#include "ManagerBot.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

    ManagerBot managerBot("1074139558:AAHPrCJFleoqGnMAYmO2aKldpLTbxvAtplc");
    managerBot.startBot();

    return a.exec();
}
