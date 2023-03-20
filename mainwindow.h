#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <string>
#include "Requirement.h"
#include "Section.h"
#include "Node.h"
#include "Course.h"
#include "Semester.h"
#include "Global.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Requirement *chosen_requirement = nullptr;
    Semester *chosen_semester = nullptr;
    string chosen_course = "";
    string warning_msg = "";

    //back-end
    //functions previously in the engine
    void init_back_end() const;
    void change_a_requirement(Requirement::Type type, string new_req_name) const;
    void add_course(string course_name, Semester* semester) const;
    void delete_course(string course_name, Semester* semester) const;
    void adjust_verification() const;

    //functions to set private data members
    inline void change_warning_msg_to(string new_msg);
    inline void change_chosen_req_to(Requirement* new_req);
    inline void change_chosen_sem_to(Semester* new_sem);
    inline void change_chosen_course_to(string new_course_name);

    //front-end (previous "show" functions)
    void display_sections();
    void display_semester(Semester* semester);
    void display_total_credit();
    void display_warning_msg();
    void delete_search_box();

private slots:
    void on_btn_ccc_clicked();
    void on_btn_school_clicked();
    void on_btn_major_clicked();

    void on_choice_ccc_currentTextChanged(QString text);
    void on_choice_school_currentTextChanged(QString text);
    void on_choice_major_currentTextChanged(QString text);

    void on_choice_semester_currentTextChanged(QString text);

    void on_txt_search_box_textChanged(QString text);

    void on_btn_add_clicked();

    void user_click_a_course(string clicked_course_name);
    void user_delete_a_course(string course_name, Semester* semester);
    void user_view_a_course(Course* course);
    void user_leave_a_course();
};

#endif // MAINWINDOW_H
