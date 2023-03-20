#ifndef GLOBAL_H
#define GLOBAL_H

/*
 * .cpp的文件名应与.h一致
 * 尽可能不要改 #include "xxx.h" 除非我写的确实不对
 * 在.cpp中实现除show()以外的所有函数
 * 函数的细节设计，比如const, &, *, inline, explicit, virtual, = default, = 0 等等，根据需要随时加/改
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
#include <fstream>
#include "Requirement.h"
#include "RequiredSection.h"
#include "ElectiveSection.h"
#include "Node.h"
#include "Course.h"
#include "Semester.h"
using namespace std;

int get_4_yr_credit();

bool find_course_from_txt(string name);//used in option 7

#endif //GLOBAL_H