#include <iostream>
#include <unordered_map>
#include <vector>

/*
*   From stackoverflow:
*   std::unordered_map has an insert and access speed of O(1), and is pretty much a hashmap implementation
*   std::map is sorted by key, insert and access has a speed of O(log n), usually using the "red-black tree" implementation
*
*   There also exists the std::hash_map implementation by STL but it seems to be deprecated?
*/
std::unordered_map<std::string,std::string> createCharMap(std::vector<std::string> args){
    std::unordered_map<std::string,std::string> map;

    /*
    *   Q: Why start with 1? array indexes starts at 0
    *   A: because argv index 0 contains the filename, which would be hashtable.exe
    */
    for(int i = 1; i < args.size(); i += 2){
        //fill last key with 0 if index is odd amount
        if((i + 1) > args.size()-1)
        {
            map[args[i]] = "0";
        }
        else
        {
            map[args[i]] = args[i+1];
        }
    }

    return map;
}

/*
*   Template/generics provides a code/function that works with multiple data types
*/
template <class T>
void printmap(std::unordered_map<T, T> map){
    for(auto var : map)
    {
        std::cout << var.first << ": " << var.second << std::endl;
    }
}

int main(int argc, char *argv[]){
    //convert to vector
    std::vector<std::string> args(argv, argc + argv);

    std::unordered_map<std::string, std::string> hashmap = createCharMap(args);

    printmap(hashmap);
}