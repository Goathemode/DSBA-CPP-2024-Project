#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void updateListWidget(const std::string &message);

private:
    Ui::MainWindow *ui;
    QString inputFile;
    QList<QList<QVariant>> data;
    int clusterAmount;
};
#endif // MAINWINDOW_H
