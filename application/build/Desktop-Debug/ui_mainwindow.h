/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QFrame *frame;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QFrame *frame_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QFrame *frame_3;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(879, 641);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 10, 211, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #f0f0f0; \n"
"    color: #333333; \n"
"    font-size: 16px; \n"
"    font-family: Arial, sans-serif;\n"
"    padding: 8px; \n"
"    border: 1px solid #cccccc; \n"
"    border-radius: 5px; \n"
"    box-shadow: 1px 1px 3px rgba(0, 0, 0, 0.1); \n"
"}\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 510, 111, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #d3d3d3;\n"
"    border-radius: 5px; \n"
"    padding: 5px 10px; \n"
"    margin: 2px; \n"
"    color: #000000; \n"
"    font-size: 14px; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #f0f0f0; \n"
"    border: 1px solid #b0b0b0; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e0e0e0; \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #f0f0f0; \n"
"    border: 1px solid #d3d3d3; \n"
"    color: #a0a0a0; \n"
"}"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(520, 70, 281, 391));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: #f0f0f0; \n"
"    border: 2px solid #d3d3d3;\n"
"    border-radius: 10px; \n"
"    padding: 5px;\n"
"    margin: 10px; \n"
"}\n"
"\n"
"QListWidget::item {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #d3d3d3; \n"
"    border-radius: 5px;\n"
"    padding: 5px; \n"
"    margin: 2px; \n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #a0c4ff; \n"
"    color: #ffffff; \n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #d3d3d3; \n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 12px;\n"
"    background: #e0e0e0;\n"
"    margin: 0px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #a0a0a0;\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
""));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 70, 361, 141));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"    border: 2px solid #d3d3d3; \n"
"    border-radius: 10px;\n"
"    padding: 15px;\n"
"    margin: 10px;\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 30, 251, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: #ffffff; \n"
"    border: 1px solid #d3d3d3; \n"
"    border-radius: 5px; \n"
"    padding: 5px;\n"
"    margin: 2px; \n"
"	qproperty-alignment: 'AlignCenter';\n"
"}\n"
"QLineEdit:focus {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #a0c4ff; \n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #b0b0b0; \n"
"}"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 80, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #d3d3d3; \n"
"    border-radius: 5px;\n"
"    padding: 5px 10px; \n"
"    margin: 2px; \n"
"    color: #000000; \n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e0e0e0; \n"
"    border: 1px solid #a0c4ff; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #b0b0b0; \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #d3d3d3; \n"
"    color: #a0a0a0;\n"
"}"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(30, 210, 361, 131));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    /* Background settings */\n"
"    background-color: #ffffff; /* White background */\n"
"\n"
"    /* Border settings */\n"
"    border: 2px solid #d3d3d3; /* Light gray border */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"\n"
"    /* Padding and margin */\n"
"    padding: 15px; /* Inner spacing */\n"
"    margin: 10px; /* Outer spacing */\n"
"\n"
"    /* Shadow settings */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3); /* Shadow effect */\n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 231, 41));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #d3d3d3; \n"
"    border-radius: 5px; \n"
"    padding: 5px; \n"
"    margin: 2px; \n"
"    color: #000000; \n"
"    font-size: 14px; \n"
"}"));
        spinBox = new QSpinBox(frame_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(270, 50, 61, 41));
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #d3d3d3; \n"
"    border-radius: 5px; \n"
"    padding: 5px; \n"
"    margin: 2px; \n"
"    color: #000000; \n"
"    font-size: 14px; \n"
"}\n"
"\n"
"QSpinBox:hover {\n"
"    background-color: #f0f0f0; \n"
"    border: 1px solid #b0b0b0;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"    background-color: #add8e6; \n"
"    border: none;\n"
"    width: 16px;\n"
"    height: 16px; \n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"    background-color: #87ceeb; \n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"    background-color: #98fb98; \n"
"    border: none;\n"
"    width: 16px;\n"
"    height: 16px; \n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #90ee90; \n"
"}\n"
"\n"
"QSpinBox::up-arrow, QSpinBox::down-arrow {\n"
"    width: 7px; \n"
"    height: 7px; \n"
"}\n"
""));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(30, 350, 361, 131));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    /* Background settings */\n"
"    background-color: #ffffff; /* White background */\n"
"\n"
"    /* Border settings */\n"
"    border: 2px solid #d3d3d3; /* Light gray border */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"\n"
"    /* Padding and margin */\n"
"    padding: 15px; /* Inner spacing */\n"
"    margin: 10px; /* Outer spacing */\n"
"\n"
"    /* Shadow settings */\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3); /* Shadow effect */\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 231, 41));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #d3d3d3; \n"
"    border-radius: 5px; \n"
"    padding: 5px; \n"
"    margin: 2px; \n"
"    color: #000000; \n"
"    font-size: 14px; \n"
"}"));
        spinBox_2 = new QSpinBox(frame_3);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(270, 50, 61, 41));
        spinBox_2->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #d3d3d3; \n"
"    border-radius: 5px; \n"
"    padding: 5px; \n"
"    margin: 2px; \n"
"    color: #000000; \n"
"    font-size: 14px; \n"
"}\n"
"\n"
"QSpinBox:hover {\n"
"    background-color: #f0f0f0; \n"
"    border: 1px solid #b0b0b0;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"    background-color: #add8e6; \n"
"    border: none;\n"
"    width: 16px;\n"
"    height: 16px; \n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"    background-color: #87ceeb; \n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"    background-color: #98fb98; \n"
"    border: none;\n"
"    width: 16px;\n"
"    height: 16px; \n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #90ee90; \n"
"}\n"
"\n"
"QSpinBox::up-arrow, QSpinBox::down-arrow {\n"
"    width: 7px; \n"
"    height: 7px; \n"
"}\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(620, 470, 91, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffffff; \n"
"    border: 1px solid #d3d3d3; \n"
"    border-radius: 5px;\n"
"    padding: 5px 10px; \n"
"    margin: 2px; \n"
"    color: #000000; \n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e0e0e0; \n"
"    border: 1px solid #a0c4ff; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #b0b0b0; \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #d3d3d3; \n"
"    color: #a0a0a0;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 879, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">K Means Clustering</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Cluster", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "No File Chosen", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Upload file", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Choose amount of clusters</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Choose maximum iterations</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Save File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
