#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QFileDialog>
#include "kmeans.h"
#include "cleaner.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setValue(3);
    ui->spinBox->setRange(1,1000);
    ui->spinBox_2->setValue(99);
    ui->spinBox_2->setRange(1,1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateListWidget(const std::string &message)
{
    ui->listWidget->addItem(QString::fromStdString(message));
}

void MainWindow::on_pushButton_clicked()
{
    inputFile = QFileDialog::getOpenFileName(this, "Выберите таблицу (файл формата .csv) для кластеризации", QDir::currentPath());

    std::string input = inputFile.toStdString();
    if (input != "" && (input.size() < 4 || input.substr(input.size() - 4) != ".csv")){
        QString errorString = "Please upload a csv file";
        QListWidgetItem *item = new QListWidgetItem(errorString);
        item->setForeground(QBrush(Qt::red));
        ui->listWidget->addItem(item);
        return;
    }
    ui->lineEdit->setText(inputFile);

    std::ifstream in(inputFile.toStdString());
    if (in.is_open() == false)
    {
        ui->lineEdit->setText("input file is not chosen");
        return ;
    }
    in.close();
    //clean(inputFile.toStdString(), [this](const std::string &message){
    //    updateListWidget(message);
    //});
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    clusterAmount = arg1;
}


void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    clusterAmount = arg1.toInt();
}


void MainWindow::on_pushButton_2_clicked()
{
    if (!clusterAmount){
        QString errorString = "Clusterisation failed. 0 Clusters chosen";
        QListWidgetItem *item = new QListWidgetItem(errorString);
        item->setForeground(QBrush(Qt::red));
        ui->listWidget->addItem(item);
    }
    else{
        try{
            cluster(inputFile.toStdString(), clusterAmount, maxIterations, [this](const std::string &message){
                updateListWidget(message);
            });
        }
        catch(const std::runtime_error& error){
            QString errorString = error.what();
            QListWidgetItem *item = new QListWidgetItem(errorString);
            item->setForeground(QBrush(Qt::red));
            ui->listWidget->addItem(item);
        }
    }
}





void MainWindow::on_spinBox_2_textChanged(const QString &arg1)
{

    maxIterations = arg1.toInt();
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    maxIterations = arg1;
}




