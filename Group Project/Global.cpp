#include "Global.h"
using namespace std;

extern vector<Requirement*> req_list;
extern vector<Semester*> sem_list;

//Total No. of credits of all courses that the user has chosen
int get_4_yr_credit(){
    int ans = 0;//answer is 0 if user does not choose any course
    for (int i = 0; i < 8; i++){
        ans += sem_list[i] -> get_credit_this_semester();
    }
    return ans;
}

//Check if a course exists in the database
bool find_course_from_txt(string name) {
    string filename = "./Courses/" + name + ".txt";
    ifstream target_file(filename);
    if (target_file) return true;//If corresponding file can be found
    else return false;
}