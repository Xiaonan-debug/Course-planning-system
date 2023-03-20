#include "Section.h"
#include  <iostream>
using namespace std;

//Section Part
bool Section:: is_satisfied(){
    return satisfied;
}

Section::Section(){
    satisfied = false;
}

Section::Type Section::get_type(){
    return type;
}


// Required_Section Part
/*void Required_Section::verify_if_satisfied(){
    satisfied = section_tree -> verify(sem_list[7]);
};

void show(){}//先不写

Required_Section::Required_Section(string info) {
    type = Required;
    section_tree = new Node(info);
}


// Elective Section Part
int Elective_Section::get_min_credit(){
    return min_required_credit;
}

void Elective_Section::verify_if_satisfied(){
    int credit_earned = 0;
    for (auto i = section_list.begin(); i != section_list.end(); ++i){
        for(int j = 0; j<8;++j){
            if (sem_list[j]->can_find_course(i) == true);
            //add course credit from semester
        }
    }
    satisfied=(credit_earned >= this -> min_required_credit) ;
}


void Elective_Section::show(){}//先不写

Elective_Section::Elective_Section(int min_required_credit,string info): min_required_credit(min_required_credit){
    type = Elective;
    for (auto i = info.begin(); i != info.end(); ++i){
        course_list.push_back(i);
    }
}

Elective_Section::~Elective_Section(){
    for (auto i = section_list.begin(); i != section_list.end(); ++i){
        delete i;
    }
}*/