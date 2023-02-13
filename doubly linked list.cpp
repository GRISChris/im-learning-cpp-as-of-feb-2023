/*
*   Also called a Doubly-Linked List, but i didnt remember that when making this
*/

#include <iostream>

struct Linked{
    int data;

    //use * in variable declaration to indicate that this variable will be using some sort of pointer
    Linked *next;
    Linked *back;
};

/*
* function to add data to linked list
* use the '&' operator in function parameter so these happens:
*  1. it passes the head pointer by **reference**, which meant that: 
*      a. it has access to the passed pointer
*      b. it can modify the values in that pointer
*
*  2. without the operator, it will only modify the local "head" variable created by the function, which meant:
*      a. when i run the print function, it will print nothing because **it didnt modify the original pointer**
*/
void add(Linked *&head, int data){
    Linked *newData = new Linked;
    newData->data = data;
    newData->next = nullptr;
    newData->back = nullptr;

    //check if the pointer is null
    //if it is, then we just set the new value as head
    //else, we travel through the pointer and adds the data at the end
    if(head == nullptr){
        head = newData;
    }
    else{
        //this else clause travels through the pointer
        //and adds the data at the end
        //e.g the list is now
        // [Head]<=>[newData]
        Linked *cur = head;
        /*
        *   What this loop does:
        *       1. sets the last pointer BEFORE nullptr
        *       2. keeps looping cur until it hits the point of nullptr
        */
        while(cur->next != nullptr){
            cur = cur->next;
        }

        cur->next = newData;
        newData->back = cur;
    }
}


/*
* when dealing with null pointers, use nullptr, because:
*   1. it takes the type of std::nullptr_t, which meant:
*       a. you can convert it to any pointer type when overloading
*   
*   2. using null (which is 0 from C, brought to c++), causes some issues, such as:
*       a. type confusion between null pointers and integers, since NULL is more or less a 0
*       b. this can also mean bugs and unexpected behavior on certain situations, e.g overloading
*/  

//prints the values inside a pointer
void print(Linked *head){
    Linked *current = head;

    while(current != nullptr){
        std::cout << current->data << " ";

        current = current->next;
    }

    std::cout << std::endl;
}

//prints the values inside a pointer until it hits the end,
//AND then prints it back fron end until it hits the head
void printback(Linked *head){
    Linked *current = head;
    bool marked = 0;

    while(current != nullptr){
        std::cout << current->data << " ";

        if(marked){
            current = current->back;
        } 
        else{
            if (current->next == nullptr){
                marked = !marked;
                current = current->back;
            }
            else{
                current = current->next;
            }
        }

    }

    std::cout << std::endl;
}

//main function
int main(){
    //initialize new linked list with nullptr
    Linked *head = nullptr;

    add(head, 1);
    add(head, 1321);
    add(head, 14123);

    print(head);
    printback(head);

    return 0;
}