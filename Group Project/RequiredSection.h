#ifndef REQUIREDSECTION_H
#define REQUIREDSECTION_H

#include <vector>
#include <iostream>
#include "Node.h"
#include "Section.h"
using namespace std;
class Required_Section : public Section{
    private:
        Node* section_tree = nullptr;

    public:
        inline Node* get_section_tree() const override;//新加的
        vector<string> get_course_list();//新加的
        void verify_if_satisfied();/*{
        section_satisfied = section_tree -> verify(ptr_to_最后一个semester);
        if not section_satisfied:
            this -> satisfied = false;
        else:
            this -> satisfied = true;
    }*/
        void show();//先不写
        Required_Section(string info)/*{
            ...other work
            this -> section_tree = new Node(info);
        }*/;//type; build tree

        ~Required_Section();
};


#endif //REQUIREDSECTION_H