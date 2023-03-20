/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *Right4;
    QTextEdit *txt_warning;
    QGridLayout *Left2;
    QLabel *label_shown_req;
    QScrollArea *scrollArea_sections;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *Right1;
    QPushButton *btn_add;
    QLineEdit *txt_search_box;
    QLabel *label_total_cre;
    QLabel *label_input_crs;
    QLineEdit *txt_total_cre;
    QGridLayout *Left1;
    QLabel *label_top;
    QPushButton *btn_school;
    QComboBox *choice_school;
    QPushButton *btn_major;
    QLabel *label_ccc;
    QLabel *label_school;
    QPushButton *btn_ccc;
    QLabel *label_major;
    QComboBox *choice_ccc;
    QComboBox *choice_major;
    QGridLayout *Right3;
    QScrollArea *scrollArea_semesters;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *Right2;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(932, 505);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Right4 = new QGridLayout();
        Right4->setObjectName(QString::fromUtf8("Right4"));
        txt_warning = new QTextEdit(centralwidget);
        txt_warning->setObjectName(QString::fromUtf8("txt_warning"));

        Right4->addWidget(txt_warning, 0, 0, 1, 1);


        gridLayout_2->addLayout(Right4, 3, 2, 1, 1);

        Left2 = new QGridLayout();
        Left2->setObjectName(QString::fromUtf8("Left2"));
        label_shown_req = new QLabel(centralwidget);
        label_shown_req->setObjectName(QString::fromUtf8("label_shown_req"));
        label_shown_req->setAlignment(Qt::AlignCenter);

        Left2->addWidget(label_shown_req, 0, 1, 1, 1);

        scrollArea_sections = new QScrollArea(centralwidget);
        scrollArea_sections->setObjectName(QString::fromUtf8("scrollArea_sections"));
        scrollArea_sections->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_sections->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 178, 442));
        scrollArea_sections->setWidget(scrollAreaWidgetContents);

        Left2->addWidget(scrollArea_sections, 1, 1, 1, 1);

        Left2->setRowStretch(0, 1);
        Left2->setRowStretch(1, 15);

        gridLayout_2->addLayout(Left2, 0, 1, 4, 1);

        Right1 = new QGridLayout();
        Right1->setObjectName(QString::fromUtf8("Right1"));
        btn_add = new QPushButton(centralwidget);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        sizePolicy.setHeightForWidth(btn_add->sizePolicy().hasHeightForWidth());
        btn_add->setSizePolicy(sizePolicy);

        Right1->addWidget(btn_add, 1, 2, 1, 1);

        txt_search_box = new QLineEdit(centralwidget);
        txt_search_box->setObjectName(QString::fromUtf8("txt_search_box"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txt_search_box->sizePolicy().hasHeightForWidth());
        txt_search_box->setSizePolicy(sizePolicy2);

        Right1->addWidget(txt_search_box, 1, 1, 1, 1);

        label_total_cre = new QLabel(centralwidget);
        label_total_cre->setObjectName(QString::fromUtf8("label_total_cre"));
        label_total_cre->setLayoutDirection(Qt::LeftToRight);
        label_total_cre->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Right1->addWidget(label_total_cre, 0, 0, 1, 1);

        label_input_crs = new QLabel(centralwidget);
        label_input_crs->setObjectName(QString::fromUtf8("label_input_crs"));
        label_input_crs->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Right1->addWidget(label_input_crs, 1, 0, 1, 1);

        txt_total_cre = new QLineEdit(centralwidget);
        txt_total_cre->setObjectName(QString::fromUtf8("txt_total_cre"));
        sizePolicy2.setHeightForWidth(txt_total_cre->sizePolicy().hasHeightForWidth());
        txt_total_cre->setSizePolicy(sizePolicy2);

        Right1->addWidget(txt_total_cre, 0, 1, 1, 2);


        gridLayout_2->addLayout(Right1, 0, 2, 1, 1);

        Left1 = new QGridLayout();
        Left1->setObjectName(QString::fromUtf8("Left1"));
        label_top = new QLabel(centralwidget);
        label_top->setObjectName(QString::fromUtf8("label_top"));
        label_top->setAlignment(Qt::AlignCenter);

        Left1->addWidget(label_top, 0, 0, 1, 1);

        btn_school = new QPushButton(centralwidget);
        btn_school->setObjectName(QString::fromUtf8("btn_school"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_school->sizePolicy().hasHeightForWidth());
        btn_school->setSizePolicy(sizePolicy3);

        Left1->addWidget(btn_school, 5, 0, 1, 1);

        choice_school = new QComboBox(centralwidget);
        choice_school->setObjectName(QString::fromUtf8("choice_school"));
        sizePolicy.setHeightForWidth(choice_school->sizePolicy().hasHeightForWidth());
        choice_school->setSizePolicy(sizePolicy);

        Left1->addWidget(choice_school, 6, 0, 1, 1);

        btn_major = new QPushButton(centralwidget);
        btn_major->setObjectName(QString::fromUtf8("btn_major"));
        sizePolicy3.setHeightForWidth(btn_major->sizePolicy().hasHeightForWidth());
        btn_major->setSizePolicy(sizePolicy3);

        Left1->addWidget(btn_major, 8, 0, 1, 1);

        label_ccc = new QLabel(centralwidget);
        label_ccc->setObjectName(QString::fromUtf8("label_ccc"));
        label_ccc->setAlignment(Qt::AlignCenter);

        Left1->addWidget(label_ccc, 1, 0, 1, 1);

        label_school = new QLabel(centralwidget);
        label_school->setObjectName(QString::fromUtf8("label_school"));
        label_school->setAlignment(Qt::AlignCenter);

        Left1->addWidget(label_school, 4, 0, 1, 1);

        btn_ccc = new QPushButton(centralwidget);
        btn_ccc->setObjectName(QString::fromUtf8("btn_ccc"));
        sizePolicy3.setHeightForWidth(btn_ccc->sizePolicy().hasHeightForWidth());
        btn_ccc->setSizePolicy(sizePolicy3);

        Left1->addWidget(btn_ccc, 2, 0, 1, 1);

        label_major = new QLabel(centralwidget);
        label_major->setObjectName(QString::fromUtf8("label_major"));
        label_major->setAlignment(Qt::AlignCenter);

        Left1->addWidget(label_major, 7, 0, 1, 1);

        choice_ccc = new QComboBox(centralwidget);
        choice_ccc->setObjectName(QString::fromUtf8("choice_ccc"));
        sizePolicy.setHeightForWidth(choice_ccc->sizePolicy().hasHeightForWidth());
        choice_ccc->setSizePolicy(sizePolicy);

        Left1->addWidget(choice_ccc, 3, 0, 1, 1);

        choice_major = new QComboBox(centralwidget);
        choice_major->setObjectName(QString::fromUtf8("choice_major"));
        sizePolicy.setHeightForWidth(choice_major->sizePolicy().hasHeightForWidth());
        choice_major->setSizePolicy(sizePolicy);

        Left1->addWidget(choice_major, 9, 0, 1, 1);

        Left1->setRowStretch(0, 1);
        Left1->setRowStretch(1, 1);
        Left1->setRowStretch(2, 2);
        Left1->setRowStretch(3, 2);
        Left1->setRowStretch(4, 1);
        Left1->setRowStretch(5, 2);
        Left1->setRowStretch(6, 2);
        Left1->setRowStretch(7, 1);
        Left1->setRowStretch(8, 2);
        Left1->setRowStretch(9, 2);

        gridLayout_2->addLayout(Left1, 0, 0, 4, 1);

        Right3 = new QGridLayout();
        Right3->setObjectName(QString::fromUtf8("Right3"));
        Right3->setVerticalSpacing(7);
        scrollArea_semesters = new QScrollArea(centralwidget);
        scrollArea_semesters->setObjectName(QString::fromUtf8("scrollArea_semesters"));
        scrollArea_semesters->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_semesters->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 477, 258));
        scrollArea_semesters->setWidget(scrollAreaWidgetContents_2);

        Right3->addWidget(scrollArea_semesters, 0, 0, 1, 1);


        gridLayout_2->addLayout(Right3, 2, 2, 1, 1);

        Right2 = new QHBoxLayout();
        Right2->setObjectName(QString::fromUtf8("Right2"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        Right2->addWidget(label_10);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        Right2->addWidget(label_9);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        Right2->addWidget(label_8);


        gridLayout_2->addLayout(Right2, 1, 2, 1, 1);

        gridLayout_2->setRowStretch(0, 2);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 7);
        gridLayout_2->setRowStretch(3, 2);
        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 2);
        gridLayout_2->setColumnStretch(2, 5);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_shown_req->setText(QApplication::translate("MainWindow", "No Requirement Shown", nullptr));
        btn_add->setText(QApplication::translate("MainWindow", "Add", nullptr));
        label_total_cre->setText(QApplication::translate("MainWindow", "Total Credit:", nullptr));
        label_input_crs->setText(QApplication::translate("MainWindow", "Manually Input a Course:", nullptr));
        label_top->setText(QApplication::translate("MainWindow", "Showing Requirement:", nullptr));
        btn_school->setText(QApplication::translate("MainWindow", "Show School Requirement", nullptr));
        btn_major->setText(QApplication::translate("MainWindow", "Show Major Requirement", nullptr));
        label_ccc->setText(QApplication::translate("MainWindow", "Common Core Requirement", nullptr));
        label_school->setText(QApplication::translate("MainWindow", "School Requirement", nullptr));
        btn_ccc->setText(QApplication::translate("MainWindow", "Show Common Core", nullptr));
        label_major->setText(QApplication::translate("MainWindow", "Major Requirement", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Year", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Fall", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Spring", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
