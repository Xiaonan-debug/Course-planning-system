#ifndef COURSE_H
#define COURSE_H

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

#include <iostream>
#include "Node.h"
using namespace std;

class Semester;//不能 #include "Semester.h" 所以需要这行

class Course {

private:

    std::string name{""};

    Semester* semester;

    int credit{0};

    std::string pre_req;
    std::string co_req;
    std::string exclusion;

    Node* prereq_tree;

    Node* coreq_tree;

    Node* exclusion_tree;

    bool prereq_satisfied, coreq_satisfied, exclusion_found;

public:

    Course(std::string &course_name, Semester* semester)/*{
        ......other work
        string prereq_info = ...(读txt文件以获取)
        build_prereq_tree(prereq_info);
        similar for coreq and exclusion
    }*/;

    ~Course();

    int get_credit();

    std::string get_name();

    std::string get_warning_msg() const;

    inline bool have_problem() const;

    void verify_prereq()/*{
        check nullptr
        prereq_satisfied = prereq_tree -> verify(ptr_to_前一个semester);
        if not prereq_satisfied:
            改prereq_satisfied...
    }*/;

    void verify_coreq()/*{
        check nullptr
        coreq_satisfied = coreq_tree -> verify(ptr_to_this_semester);
        if not coreq_satisfied:
            ......
    }*/;

    void verify_exclusion()/*{
        check nullptr
        exclusion_found = exclusion_tree -> verify(ptr_to_this_semester);
        if exclusion_found:
            ......
    }*/;

    //以下全都放到constructor里
    void build_prereq_tree(string info)/*{
        if info != "None":
            prereq_tree = new Node(info);
        else:
            prereq_tree = nullptr;
    }*/;
    void build_coreq_tree(string info);
    void build_exclusion_tree(string info);

};

#endif // COURSE_H