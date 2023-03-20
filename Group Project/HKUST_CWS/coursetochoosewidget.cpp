#include "coursetochoosewidget.h"
#include "mainwindow.h"

extern MainWindow w;

CourseToChooseWidget::CourseToChooseWidget(string course_name)
{
    this -> course_name = course_name;
    this -> setText(QString::fromStdString(course_name));
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

void CourseToChooseWidget::on_clicked(){
    w.user_click_a_course(course_name);
}
