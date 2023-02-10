#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <queue>

/*
*   Stack
*   loads data in a LIFO (last in first out) order
*   the *last data* inserted *gets removed first*
*/
std::stack<int> createStack(std::vector<int> &val){
    std::stack<int> st;

    for(int var : val){
        st.push(var);
    } 

    return st;
}

/*
*   Queue
*   loads data in a FIFO (first in first out) order
*   the first data inserted gets removed first
*/
std::queue<int> createQueue(std::vector<int> &val){
    std::queue<int> qq;

    for(int var : val){
        qq.push(var);
    }

    return qq;
}

// Use argv (argument value) to pass values when running this code
// use argc (argumemt count) to count the amount of arguments passed
// e.g ./data structures.exe val1 val2 val3 val4
int main(int argc, char *argv[]){
    std::vector<int> v;

       
    for (int i = 1; i < argc; ++i) {
    //atoi converts string into integer 
    v.push_back(atoi(argv[i]));
    }

    std::stack<int> s = createStack(v);
    std::queue<int> q = createQueue(v);

    std::cout << s.top() << ", " << q.front() << std::endl;
}