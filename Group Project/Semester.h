#ifndef SEMESTER_H
#define SEMESTER_H

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

#include "Course.h"
#include <vector>
using namespace std;

class Semester{
    private:
        vector<Course*> course_this_semester;
        int credit_this_semester;
        int no_of_semester;
        Semester* prev;

    public:
        Semester(int i, Semester* prev_seme);
        ~Semester();

        Semester* get_prev();
        void add_course(Course* new_course);
        void delete_course(string target_course);
        inline int get_no_of_semester() const;//新加的
        int get_credit_this_semester();
        inline vector<Course*> get_course_list() const;//新加的

        //三个verify改为了合成一个
        void adjust();//对于this semester有的每个课，依次verify pre,co,ex.

        bool can_find_course(string course_name);
        Course* find_course(string course_name);
        void show();//For each chosen course, show something... 先不写

};

#endif //SEMESTER_H