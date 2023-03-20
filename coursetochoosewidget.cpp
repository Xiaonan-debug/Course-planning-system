#include "coursetochoosewidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern MainWindow w;

CourseToChooseWidget::CourseToChooseWidget(string course_name)
{
    this -> course_name = course_name;
    this -> setText(QString::fromStdString(course_name));
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

void CourseToChooseWidget::on_clicked(){
    emit is_clicked(course_name);
}
