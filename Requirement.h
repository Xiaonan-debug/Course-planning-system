#ifndef REQUIREMENT_H
#define REQUIREMENT_H


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
#include <vector>
#include "Section.h"
#include "RequiredSection.h"
#include "ElectiveSection.h"

using namespace std;

class Requirement{
    private:
        vector<Section*> section_list;
        string name;
        
    public:
        enum Type{
            CCC =  1,
            SCHOOL = 2,
            MAJOR = 3,
        };
        
        Type type;

        Requirement(string name, Type type);
        Requirement::Type get_type() const;
        vector<Section*> get_section_list() const;//新加的
        ~Requirement();

        string get_name();

        void adjust()/*{
            for every section in section_list:
            section_list[...] -> verify_if_satisfied();
        }*/;
        void build_sections()/*{
            find txt file
            read txt file
            skip 前几行
            for every 2 lines:
            if first line == 1:
                section_list.push_back(new Required_section(second line));
            else if first line == 2:
                section_list.push_back(new Elective_section(second line));

        }*/;//放constructor里
};


#endif //REQUIREMENT_H