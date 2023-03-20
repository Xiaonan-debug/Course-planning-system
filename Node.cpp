#include "Node.h"
#include "Semester.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Accessor of course_name
inline string Node::get_name() const{
    return this -> course_name;
}

//Constructor with recursion (Constructing a tree)
Node::Node(string info) {
    children.reserve(100);
    //If whitespace is not in info, then info contains exactly one course name
    //In this case we construct a leaf node
    if (info.find(" ") == -1) {
        this -> logic = LEAF;
        this -> course_name = info;
    }
    //Otherwise, we construct a non-leaf node with children
    else {
        stringstream s(info);
        string word;
        while (s >> word) {
            //If we read a "(", then we use the info inside this parenthesis to construct a child non-leaf node
            if (word == "(") {
                string child_info = "";
                int stack_size = 0;//Stack data structure is used to determine which ")" is pairing with the outmost "("
                while(true){
                    string child_word;
                    s >> child_word;
                    if (child_word == "(") {//If we find another "(" inside the outermost parenthesis
                        child_info = child_info + child_word + " ";//Construct info for the new child
                        stack_size++;
                    }
                    else if (child_word == ")" && stack_size == 0) {//If we find the pairing ")"
                        break;
                    }
                    else if (child_word == ")" && stack_size > 0) {//If we find a ")" but it's not pairing with the outmost "("
                        child_info = child_info + child_word + " ";//Construct info for the new child
                        stack_size--;
                    }
                    else {//If we read some meaningful info other than parentheses
                        child_info = child_info + child_word + " ";//Construct info for the new child
                    }
                }
                child_info.pop_back();//Throw away the last whitespace
                children.push_back(new Node(child_info));
            }
            //If we read "and", then the logic between children should be "AND"
            else if (word == "and") {
                this -> logic = AND;
            }
            //If we read "or", then the logic between children should be "OR"
            else if (word == "or") {
                this -> logic = OR;
            }
            //If we read a course name, then we construct a child leaf node with this course name
            else {
                children.push_back(new Node(word));
            }
        }
    }
}

//Destructor with recursion (First delete children, then delete parent)
Node::~Node() {
    if (this -> logic != LEAF) {
        for (int i = 0; i < children.size(); i++){
            delete children[i];
        }
    }
}

//Verify if courses under this node is correctly chosen by the user
bool Node::verify(Semester* last_semester) const{
    //For leaf node, we verify if a course with name course_name exists in last_semester and previous semesters
    if (this -> logic == LEAF) {
        bool course_found = false;
        for (Semester* semester = last_semester; semester != nullptr; semester = semester -> get_prev()){
            course_found |= semester -> can_find_course(this -> course_name);
        }
        return course_found;
    }
    //For non-leaf node, we verify each of its children.
    //Based on the logic of this node, we combine the verification result
    //                      of its children together, to be the verification result of this node.
    else if (this -> logic == AND) {
        bool this_node_satisfied = true;
        for (int i = 0; i < children.size(); i++) {
                this_node_satisfied &= children[i] -> verify(last_semester);
        }
        return this_node_satisfied;
    }
    else {//if (this -> logic == OR)
        bool this_node_satisfied = false;
        for (int i = 0; i < children.size(); i++) {
            this_node_satisfied |= children[i] -> verify(last_semester);
        }
        return this_node_satisfied;
    }
}

vector<string> Node::get_course_list() const{//新加的
    vector<string> course_name_list(0);
    if (this -> logic == LEAF) {
        course_name_list.push_back(this -> course_name);
    }
    else {
        for (int i = 0; i < this -> children.size(); ++i) {
            vector<string> temp_list = children[i] -> get_course_list();
            for (int j = 0; j < temp_list.size(); ++j) {
                course_name_list.push_back(temp_list[j]);
            }
        }
    }
    return course_name_list;
}