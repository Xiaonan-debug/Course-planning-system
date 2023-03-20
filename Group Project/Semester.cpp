#include "Semester.h"
#include <iostream>
using namespace std;
#include <vector>

Semester::Semester(int i, Semester* prev_seme) {
    //Initiate basic data member
    no_of_semester = i;
    prev = prev_seme;

    //Initiate total credits of this semester
    for(int i = 0; i < course_this_semester.size(); i++)
    {
        this->credit_this_semester += course_this_semester[i]->get_credit();
    }
}

Semester* Semester::get_prev(){
    return this->prev;
}

void Semester::add_course(Course* new_course){
    credit_this_semester += new_course -> get_credit();
    course_this_semester.push_back(new_course);
}

void Semester::delete_course(string target_course){
    for(int i = 0; i < course_this_semester.size(); i++)
    {
        if(course_this_semester[i]->get_name() == target_course)//get the target course
        {
            credit_this_semester -= course_this_semester[i] -> get_credit();
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

int Semester::get_no_of_semester() const {
    return no_of_semester;
}

int Semester::get_credit_this_semester(){
    return this->credit_this_semester;
}

vector<Course*> Semester::get_course_list() const{
    return course_this_semester;
}

void Semester::adjust(){
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

void Semester::show(){}

Semester::~Semester(){
    for(int i = 0; i<course_this_semester.size();++i){
        delete course_this_semester[i];
        course_this_semester[i] = nullptr;
    }
    prev = nullptr;
}