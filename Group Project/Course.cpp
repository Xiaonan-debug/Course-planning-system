#include "Course.h"
#include <iostream>
#include <fstream>
#include "Semester.h"
using namespace std;

//Implement 3 helper functions that simplify the constructor
void Course::build_prereq_tree(string info) {
    if (info != "None")
        prereq_tree = new Node(info);
    else
        prereq_tree = nullptr;
}

void Course::build_coreq_tree(string info){
    if (info != "None")
        prereq_tree = new Node(info);
    else
        prereq_tree = nullptr;
}
void Course::build_exclusion_tree(string info){
    if (info != "None")
            prereq_tree = new Node(info);
    else
        prereq_tree = nullptr;
}

//Constructor
Course::Course(std::string &course_name, Semester* semester){
    string file_name = "./Courses/" + course_name + ".txt";
    ifstream input;
    input.open(file_name);

    //basic information
    this->semester = semester;
    input >> name;
    input >> credit;
    input >> pre_req;
    input >> co_req;
    input >> exclusion;
    prereq_satisfied = false;
    coreq_satisfied = false;
    exclusion_found = true;

    //information about pre, co, exclusion...
    std::string pre = pre_req;
    std::string co = co_req;
    std::string ex = exclusion;
    build_prereq_tree(pre);
    build_coreq_tree(co);
    build_exclusion_tree(ex);

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
    if(!exclusion_found){
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

bool Course::have_problem() const{
    return (!(prereq_satisfied && coreq_satisfied && (!(exclusion_found))));
}

//Verify all the pre-req, co-req or exclusion for a this course
//Call verify in all the Nodes trees
void Course::verify_prereq(){
    if(this->prereq_tree == nullptr){
        prereq_satisfied = true;
    }
    else{
        prereq_satisfied = prereq_tree->verify(semester->get_prev());
    }    
}

void Course::verify_coreq(){
    if(this->coreq_tree == nullptr)
        coreq_satisfied = true;
    else
        coreq_satisfied = coreq_tree->verify(this->semester);
}

void Course::verify_exclusion(){
    if(this->exclusion_tree == nullptr)
        exclusion_found = false;
    else
        exclusion_found = exclusion_tree->verify(this->semester);
}

//Destructor: delete all the possible memory leak created by new Node
Course::~Course(){
    if(prereq_tree)
        delete prereq_tree;
    if(coreq_tree)
        delete coreq_tree;
    if(exclusion_tree)
        delete exclusion_tree;
}


