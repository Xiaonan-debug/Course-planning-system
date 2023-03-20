#include "RequiredSection.h"
#include "Requirement.h"
#include "Semester.h"
#include  <iostream>
using namespace std;

extern Requirement* req_list[3];
extern Semester* sem_list[8];

Node* Required_Section::get_section_tree() const{//新加的
    return section_tree;
}

vector<string> Required_Section::get_course_list() {//新加的
    return section_tree -> get_course_list();
}

void Required_Section::verify_if_satisfied(){
    satisfied = section_tree -> verify(sem_list[7]);
}

Required_Section::Required_Section(string info) {
    type = Required;
    section_tree = new Node(info);
}

Required_Section::~Required_Section(){
    if(section_tree!=nullptr){
        delete section_tree;
        section_tree = nullptr;
    }
}