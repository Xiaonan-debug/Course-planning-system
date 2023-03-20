#include "Semester.h"
#include <iostream>
using namespace std;
#include <vector>

Semester::Semester(int i, Semester* prev_seme) {
    course_this_semester.reserve(100);
    //Initiate basic data member
    no_of_semester = i;
    prev = prev_seme;

    credit_this_semester = 0;
}

Semester* Semester::get_prev(){
    return this->prev;
}
void Semester::add_course(string new_course){
    //Course* added_course = new Course(new_course,this);
    course_this_semester.push_back(new Course(new_course,this));
    credit_this_semester += course_this_semester.back() -> get_credit();
}

void Semester::delete_course(string target_course){
    for(int i = 0; i < course_this_semester.size(); i++)
    {
        if(course_this_semester[i]->get_name() == target_course)//get the target course
        {
            credit_this_semester-=course_this_semester[i]->get_credit();
            delete course_this_semester[i];
            course_this_semester[i] = nullptr;
            //delete the target course
            for(int j = i; j < course_this_semester.size() - 1; j++)
            {
                course_this_semester[j] = course_this_semester[j+1];
            }
            course_this_semester[course_this_semester.size()-1] = nullptr;

            course_this_semester.pop_back();
            //move all course after the target one 1 position forward and delete the last blank position of the vector
        }
    }
}

int Semester::get_no_of_semester() const {//新加的
    return no_of_semester;
}

int Semester::get_credit_this_semester(){
    return this->credit_this_semester;
}

vector<Course*> Semester::get_course_list() const{//新加的
    return course_this_semester;
}

void Semester::adjust(){
    if(course_this_semester.empty()){
        return;
    }
    for(int i = 0; i < course_this_semester.size(); i++)
    {//verify every course of the semester
        course_this_semester[i]->verify_prereq();
        course_this_semester[i]->verify_coreq();
        course_this_semester[i]->verify_exclusion();
    //verify 3 kinds of requirement
    }
}

bool Semester::can_find_course(string course_name){
    bool is_find = false;
    for(int i = 0; i < course_this_semester.size(); i++)
    {
        if(course_this_semester[i]->get_name() == course_name)
            is_find = true;
    }
    return is_find;
}

Course* Semester::find_course(string course_name){
    for(int i = 0; i < course_this_semester.size(); i++)
    {
        if(course_this_semester[i]->get_name() == course_name)
            return course_this_semester[i];
    }
    return nullptr;
}

void Semester::show(){
}

Semester::~Semester(){
    if(!course_this_semester.empty()){
        for(int i = 0; i<course_this_semester.size();++i){
            delete course_this_semester[i];
            course_this_semester[i] = nullptr;
        }
    }
    prev = nullptr;
}