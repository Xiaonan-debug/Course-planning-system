#ifndef COURSETOCHOOSEWIDGET_H
#define COURSETOCHOOSEWIDGET_H

#include <QToolButton>
using namespace std;

class CourseToChooseWidget : public QToolButton
{
    Q_OBJECT
public:
    CourseToChooseWidget(string course_name);

private:
    string course_name;

private slots:
    void on_clicked();
};

#endif // COURSETOCHOOSEWIDGET_H
