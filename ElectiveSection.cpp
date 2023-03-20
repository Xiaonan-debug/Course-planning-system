#include "ElectiveSection.h"
#include "Requirement.h"
#include "Semester.h"
#include <iostream>
#include <sstream>
using namespace std;

extern Requirement* req_list[3];
extern Semester* sem_list[8];

int Elective_Section::get_min_credit(){
    return min_required_credit;
}

Node* Elective_Section::get_section_tree() const {return nullptr;}

vector<string> Elective_Section::get_course_list() {//新加的
    return course_list;
}

void Elective_Section::verify_if_satisfied(){
    int credit_earned = 0;
    for (int i = 0; i < course_list.size(); i++){
        for(int j = 0; j<8;++j){
            if (sem_list[j]->can_find_course(course_list[i]) == true){
                credit_earned += sem_list[j]->find_course(course_list[i])->get_credit();//add course credit from semester
            }
        }
    }
    satisfied=(credit_earned >= this -> min_required_credit);
}

Elective_Section::Elective_Section(int min_required_credit,string info): min_required_credit(min_required_credit){
    course_list.reserve(100);
    type = Elective;
    stringstream courseinfo(info);
    string course_name;
    while(courseinfo >> course_name){
        course_list.push_back(course_name);
        course_name = "";
    }
}

Elective_Section::~Elective_Section(){
    course_list.clear();
}