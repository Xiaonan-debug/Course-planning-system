#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addedcoursewidget.h"
#include "coursetochoosewidget.h"
#include <QString>
#include <QToolButton>
#include <QMouseEvent>

vector<Requirement*> req_list(3);
vector<Semester*> sem_list(8);
vector<QVBoxLayout*> sem_layout_list(8);
vector<QLabel*> sem_total_cre_list(8);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init_back_end();

    sem_layout_list[0] = ui -> layout_sem_1;
    sem_layout_list[1] = ui -> layout_sem_2;
    sem_layout_list[2] = ui -> layout_sem_3;
    sem_layout_list[3] = ui -> layout_sem_4;
    sem_layout_list[4] = ui -> layout_sem_5;
    sem_layout_list[5] = ui -> layout_sem_6;
    sem_layout_list[6] = ui -> layout_sem_7;
    sem_layout_list[7] = ui -> layout_sem_8;

    sem_total_cre_list[0] = ui -> sem_1_cre;
    sem_total_cre_list[1] = ui -> sem_2_cre;
    sem_total_cre_list[2] = ui -> sem_3_cre;
    sem_total_cre_list[3] = ui -> sem_4_cre;
    sem_total_cre_list[4] = ui -> sem_5_cre;
    sem_total_cre_list[5] = ui -> sem_6_cre;
    sem_total_cre_list[6] = ui -> sem_7_cre;
    sem_total_cre_list[7] = ui -> sem_8_cre;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_back_end() const{
    req_list[0] = new Requirement("CCC", Requirement::Type::CCC);
    req_list[1] = nullptr;
    req_list[2] = nullptr;

    for (int i = 1; i <= 8; i++) {
        if (i == 1) {
            //Semester is not dynamic. There are always 8 of them.
            Semester new_semester(i, nullptr);
            sem_list[i-1] = &new_semester;
        }
        else {
            Semester new_semester(i, sem_list[i-2]);
            sem_list[i-1] = &new_semester;
        }
    }
}

void MainWindow::change_a_requirement(Requirement::Type type, string new_req_name) const{
    int i;
    switch(type){
    case Requirement::Type::CCC: i = 0; break;
    case Requirement::Type::SCHOOL: i = 1; break;
    case Requirement::Type::MAJOR: i = 2; break;
    }
    delete req_list[i];
    req_list[i] = nullptr;
    if (new_req_name != "") req_list[i] = new Requirement(new_req_name, type);
}


//See Semester.h
void MainWindow::add_course(string course_name, Semester* semester) const{
    Course* new_course = new Course(course_name, semester);
    semester -> add_course(new_course);
}

void MainWindow::delete_course(string course_name, Semester* semester) const{
    semester -> delete_course(course_name);
}

void MainWindow::adjust_verification() const{
    //Course chosen correctly?
    for (int i = 0; i < 8; i++){
        sem_list[i] -> adjust();
    }
    //Requirements Satisfied?
    //依次verify ccc, school, major
    for (int i = 0; i < 3; i++){
        if (req_list[i] != nullptr) req_list[i] -> adjust();
    }
}

void MainWindow::change_warning_msg_to(string new_msg){
    warning_msg = new_msg;
}

void MainWindow::change_chosen_req_to(Requirement* new_req){
    chosen_requirement = new_req;
}

void MainWindow::change_chosen_sem_to(Semester* new_sem){
    chosen_semester = new_sem;
}

void MainWindow::change_chosen_course_to(string new_course_name){
    chosen_course = new_course_name;
}


//front-end (previous "show" functions)
void MainWindow::display_sections(){
    //delete everything in the layout
    while(ui -> SectionLayout -> count() != 0){
        QLayoutItem* item = ui -> SectionLayout -> takeAt(0);
        delete item -> widget();
        delete item;
    }

    //adjust text at the top
    if (chosen_requirement == nullptr) {
        ui -> label_shown_req -> setText("No Requirement Shown");
    }
    else {
        ui -> label_shown_req -> setText(QString::fromStdString(chosen_requirement -> get_name()));
    }

    //create new section list
    if (chosen_requirement != nullptr) {
        vector<Section*> section_list = chosen_requirement -> get_section_list();
        for (int i = 0; i < section_list.size(); i++){
            //display all courses in this section
            vector<string> course_name_list = section_list[i] -> get_course_list();
            for (int j = 0; j < course_name_list.size(); ++j) {
                CourseToChooseWidget* new_course_btn = new CourseToChooseWidget(course_name_list[j]);
                if (section_list[i] -> is_satisfied()) {
                    new_course_btn -> setStyleSheet("background-color: rgb(180, 255, 180)");
                }
                if (course_name_list[j] == chosen_course) {
                    new_course_btn -> setStyleSheet("background-color: rgb(180, 180, 255");
                }
                ui -> SectionLayout -> addWidget(new_course_btn);
            }
            //add a line at the bottom
            QFrame* new_line = new QFrame;
            new_line = ui -> line_section_list;
            ui -> SectionLayout -> addWidget(new_line);//doable??
        }
    }
}

void MainWindow::display_semester(Semester* semester){
    int index = semester -> get_no_of_semester() - 1;
    //adjust credit
    sem_total_cre_list[index] -> setText(QString::number(semester -> get_credit_this_semester()));

    //delete old content
    while(sem_layout_list[index] -> count() != 0){
        QLayoutItem* item = sem_layout_list[index] -> takeAt(0);
        delete item -> widget();
        delete item;
    }

    //add course
    vector<Course*> course_list = semester -> get_course_list();
    for (int i = 0; i < course_list.size(); ++i) {
        //Create button; initialize name
        AddedCourseWidget* new_course_btn = new AddedCourseWidget(course_list[i], sem_list[index]);
        //set style based on course info
        if (course_list[i] -> have_problem()) {
            new_course_btn -> setStyleSheet("background-color: rgb(255, 180, 180)");
        }
        //add to form
        sem_layout_list[index] -> addWidget(new_course_btn);
    }
}

void MainWindow::display_total_credit(){
    ui -> txt_total_cre -> setText(QString::number(get_4_yr_credit()));
}

void MainWindow::display_warning_msg(){
    ui -> txt_warning -> setText(QString::fromStdString(warning_msg));
}

void MainWindow::delete_search_box(){
    ui -> txt_search_box -> setText(QString::fromStdString(""));
}

//slots
void MainWindow::user_click_a_course(string clicked_course_name){
    if (chosen_course == clicked_course_name) {
        change_chosen_course_to("");
    }
    else {
        change_chosen_course_to(clicked_course_name);
    }
    display_sections();
}

void MainWindow::user_delete_a_course(string course_name, Semester* semester){
    delete_course(course_name, semester);
    adjust_verification();
    display_semester(semester);
    display_total_credit();
    display_sections();
}

void MainWindow::user_view_a_course(Course* course){
    change_warning_msg_to(course -> get_warning_msg());
    display_warning_msg();
}

void MainWindow::user_leave_a_course(){
    change_warning_msg_to("");
    display_warning_msg();
}

void MainWindow::on_btn_ccc_clicked(){
    change_chosen_req_to(req_list[0]);
    display_sections();
}
void MainWindow::on_btn_school_clicked(){
    change_chosen_req_to(req_list[1]);
    display_sections();
}
void MainWindow::on_btn_major_clicked(){
    change_chosen_req_to(req_list[2]);
    display_sections();
}

void MainWindow::on_choice_ccc_currentTextChanged(QString text){
    bool need_to_change = false;
    if (chosen_requirement -> type == Requirement::Type::CCC) need_to_change = true;

    change_a_requirement(Requirement::Type::CCC, text.toStdString());

    adjust_verification();

    if (need_to_change) {
        change_chosen_req_to(req_list[0]);
        display_sections();
    }
}
void MainWindow::on_choice_school_currentTextChanged(QString text){
    bool need_to_change = false;
    if (chosen_requirement -> type == Requirement::Type::SCHOOL) need_to_change = true;

    change_a_requirement(Requirement::Type::SCHOOL, text.toStdString());

    adjust_verification();

    if (need_to_change) {
        change_chosen_req_to(req_list[1]);
        display_sections();
    }
}
void MainWindow::on_choice_major_currentTextChanged(QString text){
    bool need_to_change = false;
    if (chosen_requirement -> type == Requirement::Type::MAJOR) need_to_change = true;

    change_a_requirement(Requirement::Type::MAJOR, text.toStdString());

    adjust_verification();

    if (need_to_change) {
        change_chosen_req_to(req_list[2]);
        display_sections();
    }
}

void MainWindow::on_choice_semester_currentTextChanged(QString text){
    string info = text.toStdString();
    if (info == "Year1 Fall") {
        chosen_semester = sem_list[0];
    }
    else if (info == "Year1 Spring") {
        chosen_semester = sem_list[1];
    }
    else if (info == "Year2 Fall") {
        chosen_semester = sem_list[2];
    }
    else if (info == "Year2 Spring") {
        chosen_semester = sem_list[3];
    }
    else if (info == "Year3 Fall") {
        chosen_semester = sem_list[4];
    }
    else if (info == "Year3 Spring") {
        chosen_semester = sem_list[5];
    }
    else if (info == "Year4 Fall") {
        chosen_semester = sem_list[6];
    }
    else if (info == "Year4 Spring") {
        chosen_semester = sem_list[7];
    }
    else {
        chosen_semester = nullptr;
    }
}

void MainWindow::on_txt_search_box_currentTextChanged(QString text){
    string content = text.toStdString();
    change_chosen_course_to(content);
    display_sections();//maybe too expensive here
}

void MainWindow::on_btn_add_clicked(){
    if (chosen_semester == nullptr) {
        change_warning_msg_to("Please choose a semester.");
    }
    else if (chosen_course == ""){
        change_warning_msg_to("Please choose or input a course.");
    }
    else if (find_course_from_txt(chosen_course) == false){
        change_warning_msg_to("The course " + chosen_course + " does not exist.");
    }
    else{
        change_warning_msg_to("Successfully add " + chosen_course + ".");
        add_course(chosen_course, chosen_semester);
        adjust_verification();
        display_semester(chosen_semester);
        display_total_credit();
        change_chosen_course_to("");
        delete_search_box();
        display_sections();
    }
    display_warning_msg();
}


