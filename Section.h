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
        };//新 移到了public里

        Section::Type get_type();
        virtual vector<string> get_course_list() = 0;//新加的
        bool is_satisfied();
        virtual Node* get_section_tree() const = 0;//新加的
        virtual void verify_if_satisfied() = 0;

    protected:
        Type type;

        bool satisfied = false;
};
#endif

 
