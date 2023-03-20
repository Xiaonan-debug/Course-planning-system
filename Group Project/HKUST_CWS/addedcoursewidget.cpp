#include "addedcoursewidget.h"
#include "mainwindow.h"

extern MainWindow w;

AddedCourseWidget::AddedCourseWidget(Course* course, Semester* semester)
{
    this -> course = course;
    this -> semester = semester;
    this -> setText(QString::fromStdString(course -> get_name()));
    this -> setMouseTracking(true);

    //connections
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
    QObject::connect(this, SIGNAL(viewed()), this, SLOT(on_viewed()));
    QObject::connect(this, SIGNAL(left()), this, SLOT(on_left()));
}

void AddedCourseWidget::on_clicked(){
    w.user_delete_a_course(course -> get_name(), semester);
}

void AddedCourseWidget::on_viewed(){
    w.user_view_a_course(course);
}

void AddedCourseWidget::on_left(){
    w.user_leave_a_course();
}
