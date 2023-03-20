#include <iostream>
#include "global.h"
using namespace std;

vector<Requirement*> req_list(3);
vector<Semester*> sem_list(8);

void init(){
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

bool add_requirement(){//option 1
    cout << "Please choose one of the following:" << endl;
    cout << "1 - add a school requirement" << endl;
    cout << "2 - add a major requirement" << endl;
    cout << "3 - go back" << endl;
    cout << ">>> ";
    int option = 0;
    cin >> option;
    switch (option){
        case 1: {
            std::string name = "";
            cout << "name: ";
            cin >> name;
            req_list[1] = new Requirement(name, Requirement::Type::SCHOOL);
            return true;
        }
        case 2: {
            std::string name = "";
            cout << "name: ";
            cin >> name;
            req_list[2] = new Requirement(name, Requirement::Type::MAJOR);
            return true;
        }
        case 3: return false;
        default: {cerr << "invalid option" << endl; return false;}
    }
}

void choose_a_requirement(){//option 2
    cout << "Please input a existing requirement:" << endl;
    cout << ">>> ";
    std::string req_name = "";
    cin >> req_name;
    if (req_name == req_list[0] -> get_name()) {
        req_list[0] -> show();
    }
    else if (req_name == req_list[1] -> get_name()) {
        req_list[1] -> show();
    }
    else if (req_name == req_list[2] -> get_name()) {
        req_list[2] -> show();
    }
    cout << "Please input a course name and semester" << endl;
    cout << "Please input two 0s to go back" << endl;
    cout << ">>> ";
    string course_name = "";
    int semester_num = 0;
    cin >> course_name >> semester_num;
    if (course_name == "0" && semester_num == 0) {
        return;
    }
    else{
        Course* chosen_course = new Course(course_name, sem_list[semester_num - 1]);
        sem_list[semester_num-1] -> add_course(chosen_course);
        sem_list[semester_num - 1] -> show();
    }
}

void delete_a_requirement(){//option 3
    cout << "Please input the requirement type that you want to delete: (1,2,3)" << endl;
    cout << ">>> ";
    int type = 0;
    cin >> type;
    switch(type){
        case 1: req_list[0] -> ~Requirement(); break;
        case 2: req_list[1] -> ~Requirement(); break;
        case 3: req_list[2] -> ~Requirement(); break;
    }
    /*show_in_some_way();*/
}

void delete_a_course(){//option 4
    cout << "Please input the semester number. E.g. 4 stands for yr2 spring" << endl;
    cout << ">>> ";
    int semester_num = 0; cin >> semester_num;
    cout << "Please input the course name" << endl;
    cout << ">>> ";
    std::string course_name = ""; cin >> course_name;
    Course* target_course = sem_list[semester_num - 1] -> find_course(course_name);
    course_name = target_course->get_name();
    sem_list[semester_num - 1] -> delete_course(course_name);
}

void Verify(){//option 5
    //Course chosen correctly? 
    for (int i = 0; i < 8; i++){
        sem_list[i] -> adjust();
        sem_list[i] -> show();
    }
    //Requirements Satisfied?
    //依次verify ccc, school, major
    for (int i = 0; i < 3; i++){
        if (req_list[i] != nullptr) {
            req_list[i] -> adjust();
            req_list[i] -> show();
        }
    }
}

void Search_for_a_course_and_add(){//option 7
    cout << "Please input a course name and a semester:" << endl;
    cout << "Please input two 0s to go back" << endl;
    cout << ">>> ";
    string course_name = "";
    int semester_num = 0;
    cin >> course_name >> semester_num;
    if ((course_name == "0" && semester_num == 0)){
        return;
    }
    else if (!(find_course_from_txt(course_name))){
        cout << "This course cannot be found." << endl;
    }
    else{
        Course* chosen_course = new Course(course_name, sem_list[semester_num - 1]);
        sem_list[semester_num - 1] -> add_course(chosen_course);
        sem_list[semester_num - 1] -> show();
    }
}

void command_line_run(){
    init();
    while (true){
        bool quit = false;
        cout << "Please choose an option" << endl;
        cout << "1 - Add a Requirement" << endl;
        cout << "2 - Choose a existing requirement and add course to schedule" << endl;
        cout << "3 - delete a requirement" << endl;
        cout << "4 - delete a course from your schedule" << endl;
        cout << "5 - Verify" << endl;
        cout << "6 - Quit" << endl;
        cout << "7 - search for a course and add" << endl;
        cout << ">>> ";
        int option = 0;
        cin >> option;
        switch(option){
            case 1: add_requirement(); break;
            case 2: choose_a_requirement(); break;
            case 3: delete_a_requirement(); break;
            case 4: delete_a_course(); break;
            case 5: Verify(); break;
            case 6: quit = true; break;
            case 7: Search_for_a_course_and_add(); break;
            default: {cerr << "invalid option" << endl; break;}
        }
        if (quit) break;
    }
}

int main(){
    command_line_run();
    return 0;
}