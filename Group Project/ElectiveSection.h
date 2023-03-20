#ifndef ELECTIVESECTION_H
#define ELECTIVESECTION_H

#include <vector>
#include <iostream>
#include "Node.h"
#include "Section.h"
using namespace std;



class Elective_Section : public Section{
    private:
        vector<string> course_list;
        int min_required_credit;
    public:
        int get_min_credit();
        vector<string> get_course_list();//新加的
        void verify_if_satisfied()/*{
            credit_earned = 0;
            for each course_name in course_list:
                if one of 8 semesters satisfies semester -> can_find_course(course_name) == true:
                    credit_earned += credit of this course;
            return (credit_earned >= this -> min_required_credit);
        }*/;
        void show();//先不写
        Elective_Section(int min_required_credit,string info)/*{
            from txt file, read min_required_credit and initialize it
            ...other work
            for each course_name read from txt file:
                course_list.push_back(course_name);
        }*/;//type; build course list
        ~Elective_Section();
};

#endif //ELECTIVESECTION_H