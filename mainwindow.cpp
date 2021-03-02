#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSettings()
{
    this->setStyleSheet("background-color: lightblue;");
}

