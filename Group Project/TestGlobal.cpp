#include "Global.h"
#include <fstream>
using namespace std;

//Check if a course exists in the database
bool find_course_from_txt(string name) {
    string filename = "./Courses/" + name + ".txt";
    ifstream target_file(filename);
    if (target_file) return true;//If corresponding file can be found
    else return false;
}

int main(){
    cout << find_course_from_txt("MATH4336") << endl;
    return 0;
}