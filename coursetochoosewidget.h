#ifndef COURSETOCHOOSEWIDGET_H
#define COURSETOCHOOSEWIDGET_H

#include <QPushButton>
using namespace std;

class CourseToChooseWidget : public QPushButton
{
    Q_OBJECT
public:
    CourseToChooseWidget(string course_name);

private:
    string course_name;

private slots:
    void on_clicked();

signals:
    void is_clicked(string course_name);
};

#endif // COURSETOCHOOSEWIDGET_H
