#include "RequiredSection.h"
#include "Requirement.h"
#include "Semester.h"
#include  <iostream>
using namespace std;

extern vector<Requirement*> req_list;
extern vector<Semester*> sem_list;

Node* Required_Section::get_section_tree() const{
    return section_tree;
}

vector<string> Required_Section::get_course_list() {
    return section_tree -> get_course_list();
}

void Required_Section::verify_if_satisfied(){
    satisfied = section_tree -> verify(sem_list[7]);
};

void Required_Section::show(){}//先不写

Required_Section::Required_Section(string info) {
    type = Required;
    section_tree = new Node(info);
}