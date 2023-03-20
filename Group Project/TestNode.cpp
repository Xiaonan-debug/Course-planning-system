#include "Node.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Constructor with recursion (Constructing a tree)
Node::Node(string info) {
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

void output(Node* node){
    if (node->course_name != "") {
        cout << node->course_name << endl;
    }
    else {
        for (int i = 0; i < node->children.size(); i++){
            output(node->children[i]);
        }
    }
}

int main() {
    //                     modify below to test
    Node* test = new Node("( ( LANG2010 or LANG2010H ) or ( LANG2030 or LANG2030H ) ) and ( LANG3021 or LANG4030 )");
    test->output(test);
    delete test;
    return 0;
}