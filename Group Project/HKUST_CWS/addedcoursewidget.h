#ifndef ADDEDCOURSEWIDGET_H
#define ADDEDCOURSEWIDGET_H

#include <QPushButton>
#include "../Course.h"
#include "../Semester.h"
using namespace std;

class AddedCourseWidget : public QPushButton
{
    Q_OBJECT
private:
    Course* course;
    Semester* semester;

public:
    AddedCourseWidget(Course* course, Semester* semester);

    void enterEvent(QEvent *ev) {emit viewed();}
    void leaveEvent(QEvent *ev) {emit left();}

signals:
    void viewed();
    void left();

private slots:
    void on_clicked();
    void on_viewed();
    void on_left();
};

#endif // ADDEDCOURSEWIDGET_H
