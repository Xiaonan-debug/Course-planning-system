#include "ElectiveSection.h"
#include "Requirement.h"
#include "Semester.h"
#include  <iostream>
using namespace std;

extern vector<Requirement*> req_list;
extern vector<Semester*> sem_list;

int Elective_Section::get_min_credit(){
    return min_required_credit;
}

vector<string> Elective_Section::get_course_list() {
    return course_list;
}

void Elective_Section::verify_if_satisfied(){
    int credit_earned = 0;
    for (int i = 0; i < course_list.size(); i++){
        for(int j = 0; j<8;++j){
            if (sem_list[j]->can_find_course(course_list[i]) == true);
                credit_earned += sem_list[j]->find_course(course_list[i])->get_credit();//add course credit from semester
        }
    }
    satisfied=(credit_earned >= this -> min_required_credit) ;
}


void Elective_Section::show(){}//先不写

Elective_Section::Elective_Section(int min_required_credit,string info): min_required_credit(min_required_credit){
    type = Elective;
    for (int i = 0; i < info.length()/9+1; i+=9){
        course_list.push_back(info.substr(i,8));
    }
}

Elective_Section::~Elective_Section(){
        course_list.clear();
}