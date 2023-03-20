#ifndef SECTION_H
#define SECTION_H

/*
 * .cpp的文件名应与.h一致
 * 尽可能不要改 #include "xxx.h" 除非我写的确实不对
 * 在.cpp中实现除show()以外的所有函数
 * 函数的细节设计，比如const, &, *, inline, explicit, virtual, = default, = 0 等等，根据需要随时加/改
 * 注释仅供参考
 * 有问题直接微信群联系
 */

/*
 * Readability 是很重要的评分标准！！！！！！
 * 写出的代码要结构非常清晰！做完这一步再开始下一步，不要混着来
 * 
 * Documentation非常重要！！用英文写注释！！最好每一步都注释一下这一步是干什么的！！用到比较tricky的技巧时也注释一下
 * （不一定严格按照此规则来，视情况而定。但注释一定要清楚）
 */

#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

class Section{
    public:
        enum Type{
            Required = 1,
            Elective = 2,
        };

        Section::Type get_type();
        virtual vector<string> get_course_list();//新加的
        bool is_satisfied();
        virtual inline Node* get_section_tree() const;//新加的
        virtual void verify_if_satisfied() = 0;
        virtual void show() = 0;//For each course, create an area to show the course... 先不写
        Section();//satisfied = false;
        ~Section()=default;

    protected:
        Type type;

        bool satisfied;
};
#endif//SECTION_H


/*class Required_Section : public Section{
    private:
        Node* section_tree = nullptr;

    public:
        bool verify_if_satisfied()/*{
        section_satisfied = section_tree -> verify(ptr_to_最后一个semester);
        if not section_satisfied:
            this -> satisfied = false;
        else:
            this -> satisfied = true;
    };
        void show();//先不写
        Required_Section(string info){
            ...other work
            this -> section_tree = new Node(info);
        };//type; build tree

        ~Required_Section();
};*/

/*class Elective_Section : public Section{
    private:
        vector<string> course_list;
        int min_required_credit;
    public:
        int get_min_credit();
        void verify_if_satisfied()/*{
            credit_earned = 0;
            for each course_name in course_list:
                if one of 8 semesters satisfies semester -> can_find_course(course_name) == true:
                    credit_earned += credit of this course;
            return (credit_earned >= this -> min_required_credit);
        };
        void show();//先不写
        Elective_Section(int required_credit,string info)/*{
            from txt file, read min_required_credit and initialize it
            ...other work
            for each course_name read from txt file:
                course_list.push_back(course_name);
        };//type; build course list
        ~Elective_Section();
};*/

 
