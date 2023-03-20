#include "Course.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Semester.h"
using namespace std;

//Implement 3 helper functions that simplify the constructor
void Course::build_prereq_tree(string info) {
    if (info != "None") {
        prereq_tree = new Node(info);
    }
    else {
        prereq_tree = nullptr;
    }
}

void Course::build_coreq_tree(string info){
    if (info != "None") {
        coreq_tree = new Node(info);
    }
    else {
        coreq_tree = nullptr;
    }
}
void Course::build_exclusion_tree(string info){
    if (info != "None") {
        exclusion_tree = new Node(info);
    }
    else {
        exclusion_tree = nullptr;
    }
}

//Constructor
Course::Course(std::string &course_name, Semester* semester):semester(semester),prereq_satisfied(false),coreq_satisfied(false),exclusion_found(true){
    string filename = "./Courses/" + course_name + ".txt";
    ifstream ifs(filename);
    string c;

    //basic information
    getline(ifs,name);
    getline(ifs,c);
    credit = atoi(c.c_str());

    //information about pre, co, exclusion...
    getline(ifs,c);
    build_prereq_tree(c);
    getline(ifs,c);
    build_coreq_tree(c);
    getline(ifs,c);
    build_exclusion_tree(c);
    ifs.close();
}

//get useful information for possible usage
int Course::get_credit(){
    return this->credit;
}
std::string Course::get_name(){
    return this->name;
}



std::string Course::get_warning_msg() const{
    string msg = name + ":\n";
    bool no_problem = true;
    if(!prereq_satisfied){
        msg+= "Prerequisite(s) not satisfied\n";
        no_problem = false;
    }
    if(!coreq_satisfied){
        msg+= "Corequisite(s) not satisfied\n";
        no_problem = false;
    }
    if(exclusion_found){
        msg+= "Exclusion(s) found in your other course(s)\n";
        no_problem = false;
    }
    if(no_problem){
        msg+="OK to choose.";
    }
    else{
        msg+= "Cannot choose this course!";
    }
    return msg;

}

bool Course::have_problem() const{//新加的
    return (!(prereq_satisfied && coreq_satisfied && (!(exclusion_found))));
}

//Verify all the pre-req, co-req or exclusion for a this course
//Call verify in all the Nodes trees
void Course::verify_prereq(){
    if(this->prereq_tree == nullptr){
        prereq_satisfied = true;
    }
    else{
        if (semester -> get_prev() == nullptr) {//&& prereq_tree != nullptr 新加的
            prereq_satisfied = false;
            return;
        }
        prereq_satisfied = prereq_tree->verify(semester->get_prev());
    }    
}

void Course::verify_coreq(){
    if(this->coreq_tree == nullptr){
        coreq_satisfied = true;
    }
    else {
        coreq_satisfied = coreq_tree->verify(this->semester);
    }
}

void Course::verify_exclusion(){
    if(this->exclusion_tree == nullptr) {
        exclusion_found = false;
    }
    else {
        string real_name = this -> name;//To avoid regarding itself as exclusion 新加的，但会造成delete course的小问题
        this -> name = "Desmond";
        exclusion_found = exclusion_tree->verify(this->semester);
        this -> name = real_name;
    }
}

//Destructor: delete all the possible memory leak created by new Node
Course::~Course(){
    if(prereq_tree){
        delete prereq_tree;
        prereq_tree = nullptr;
    }
    if(coreq_tree){
        delete coreq_tree;
        coreq_tree = nullptr;
    }
    if(exclusion_tree){
        delete exclusion_tree;
        exclusion_tree = nullptr;
    }
}


