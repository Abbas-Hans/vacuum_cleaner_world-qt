#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formnewmap.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Quit
void MainWindow::on_pushButton_8_clicked()
{
    this->close();
}

//Select map
void MainWindow::on_pushButton_clicked()
{
    FormNewMap* form = new FormNewMap(0);

    connect(form, SIGNAL(SendData(QString, int, int)),
                         this, SLOT(onNewMapData(QString, int, int)));

    form->show();
}

//SLOT, receives data from "select map" form
void MainWindow::onNewMapData(QString filename, int lifetime, int testcase)
{
    fileName = filename;
    lifeTime = lifetime;
    testCase = testcase;
}
