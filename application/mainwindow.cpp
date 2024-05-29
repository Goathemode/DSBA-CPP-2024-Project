#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    inputFile = QFileDialog::getOpenFileName(this, "Выберите таблицу (файл формата .csv) для кластеризации", QDir::currentPath());

    ui->textEdit->setText(inputFile);

    std::ifstream in(inputFile.toStdString());
    if (in.is_open() == false)
    {
        ui->lineEdit->setText("input file is not chosen");
        return ;
    }
    in.close();
    ui->lineEdit->setText("input file is opened correctly");
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{

}

