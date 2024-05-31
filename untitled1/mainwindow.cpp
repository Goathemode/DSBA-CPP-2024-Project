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
            cluster(inputFile.toStdString(), clusterAmount, [this](const std::string &message){
                updateListWidget(message);
            });
        }
        catch(const std::runtime_error& error){
            QString errorString = "Clusterisation failed. No file chosen";
            QListWidgetItem *item = new QListWidgetItem(errorString);
            item->setForeground(QBrush(Qt::red));
            ui->listWidget->addItem(item);
        }
    }
}

