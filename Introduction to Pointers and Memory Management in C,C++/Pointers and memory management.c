/*
Memory management and pointers in C, C++
Creating a memory safe storage application with C++

Course Objectives
#Learn how pointers and memory management differ in C vs C++.
#Practice using a debugger and VS Code to catch and solve memory related errors.
#Create memory-safe applications that incorporate the Big 3/5.
#Perform pointer manipulations and learn how to use C-Strings.
#Learn how pointers are used in C/C++ to refer to the memory location of a variable
#Learn how to update a legacy application to use standard library smart pointers
#Discover how to create, manage, and destroy memory on the heap and stack in C/C++

By the end of this course, you will learn how to create memory-safe applications in both C and C++, discover how to use pointers and dynamic memory in a modern application, and implement/customize the Big 3/5 for your own application
-----------------------------------------------------------------------------------------------------------
1. Memory management is the act of creating and destroying variables on memory(RAM) of a program.
2. Proper memory management ensures we don't have any memory leaks. This allows our programs to run for longer periods and on a variety of systems.
3. Some languages have fully automated memory management but it does add great deal of overhead in the execution of our programs, so if you want really fast programs which are essentials for great deal task such as enterprise programming like on high end applications, or like gaming where every single frame counts. You wanna make sure that you're as efficient as possible. And having manual control of your memory means that you can make sure that you program can run faster than an equivalent Java or Python program that needs automatic garbage collection.
Proper memory management in C++, though, is also essential because if you don't member manager memory correctly, you'll have memory leaks. These occur whenever you have memory that was created but not freed up, even though the variable is no longer in use.
We want to avoid all memory leaks in our applications, so we're gonna be discussing how we should build our programs to make sure that doesn't occur.
4. Now, Pointers are the way that memory management is handled in C++ & C as we'll see there's many different types of pointers, but in C & C++, you have standard pointers which were used with the new and delete keywords.
And we'll see that in C++, we have smart pointers, which here is a direct automatic memory management in C++ which can be helpful.
5. A Pointer is a variable that stores a memory location. IOW Pointers are special integers that hold a memory address.
6. To get the memory location of a pointer, use a & before the name of the variable.
7. Why do we need pointers?
-> We need them to manipulate arrays. All arrays in C & C++ are basically just fancy pointers, they are pointers to a single memory location and then every subsequent element in the array is distorted at a subsequent memory location. This is actually why array indexing in most programming is zero based because it measures the offset from the original memory location.
-> They can be used to save a great deal of memory and execution time for a project, because instead of copying a project, we can copy a pointer to a project and not have to actually copy over all the values.
-> Can be used to represent C-strings. You can use them to manipulate characters and to change how you want to represent a string. Pointers are essential because they can allow you to create constant strings, and they're a little different to how you traditionally use strings in C++.
-> Pointers to functions.
-> Essential to implement many data structures.
-> The Stack allows us to use automatically managed memory, but is rather small
-> The Heap allows us to dynamcially use memory and can be increased to take in large object/files we need for our programs.
-> Here, It is being used to build a Linked list but pointers are useful in many C & C++ applications.

8. New is how we allocate new dynamic memory in C/C++. It indicates that we want to create space in memory for a new variable. This memory stays allocated until we call delete.
If delete is never called, the memory has leaked, and isn't usable by other programs until our program terminates.
9. Delete allows us to free up memory as we know a variable is no longer in use. Simply sat delete and then the name of your variable: Delete intPtr;
This memory is now junk data, so if we try and access it will have a segmentation fault.
*/

#include<iostream>
#include<cstring>
#include<memory>
using namespace std;
struct node {
    int data;
    node *next;
};

class list {
private:
    node *head;
    node *tail;
    //int *size = new int(0);
    std::shared_ptr<int> size; //Try unique_ptr as well
public:
    list(): size(new int(0)) {
        head = nullptr;
        tail = nullptr;

    }

   /* list::~list(){ //destructors
        delete size; //getting rid of the destructor since we are working with smart pointers here/
    }
    */

    //If you were using the shared pointer, there'd have been use of the copy constructor but incase of unique pointer, there isn't a need of copy constructor
    list::list(const list &rhs){ //copy constructor, copying values without copying the exact references
        head = rhs.head; //We have the memory address of rhs in this case. Here, we are trying to get the actual head pointer from rhs not from its memory address so we are implicitly accessing it to get that value.
        tail = rhs.tail;
        size = new int (*(rhs.size)); //rhs.size is a pointer and we're going to dereference it.
    }

    const list& list::operator=(list &rhs){ //Copy assignment operator, a bit complicated, list& belonging to the list class, working with = operator.
        if(this != rhs){   //if this !=rhs or not the same, create the new object and swap the values
            list temp(rhs); //works coz we have already defined a copy constructor.
            std::swap(head, rhs.head);
            std::swap(tail, rhs.tail);
            std::swap(size, rhs.size);
        }
        return *this; //dereferencing a pointer since this refers as a pointer.
    }

    //BIG5
    list& operator=(list mylist){//list& : pass by reference
        if(this == &mylist){
            return *this;
        }
        *this = std::move(mylist); //moving the temp value of mylist over to this and that way we can actually keep it permanently.
        return *this; //since working with the pbref, dereference this and we don't want the pointer.
    }

    //Since copy assignment depends upon the copy constructor, similarly move constructor depends upon the move assignment.

    /*list(list&& mylist){  //list type, and list&& as arg value for 2ampersands, and mylist as a name for simplicity.
        if(this == &mylist){
            return; //done indicating the end of the constructor.
        }
        *this = std::move(mylist);
    }*/
    //END OF BIG5

    /*Importance of pointer in C/C++:
      Pointers are used for accessing the resources which are external to the program like heap memory. So for accessing the heap memory if anything is created inside heap memory Pointers are used.

      SMART POINTERS: are a wrapper class around pointers which allows for some automatic memory management by avoiding the memory leak option which are there in normal pointers as compared to C++11.
      It automatically deallocates the object when they are not in use when the pointer is going out of scope automatically it will deallocate the memory.
      Types: Unique, shared, weak pointers. */

    void createnode(int value) {
        node *temp = new node;
        temp->data = value;    //Manipulating one of the data members of the node. Also: (temp->data = value;) Standard way of dereferencing a pointer.
        std::shared_ptr<int> size2(size);
        temp->next = nullptr;
        if(head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    void display() {
        node *temp = new node;
        temp = head;
        while(temp != nullptr) {
            cout<< temp -> data << "\t";
            temp = temp -> next;
        }
    }
    void insert_start(int value) {
        node *temp = new node;
        temp -> data = value;
        temp -> next = head;
        head = temp;
    }
    void insert_position(int pos, int value) {
        node *pre = new node;
        node *cur = new node;
        node *temp = new node;
        cur = head;
        for(int i = 1;i < pos;i++) {
            pre = cur;
            cur = cur -> next;
        }
        temp -> data = value;
        pre -> next = temp;
        temp -> next = cur;
    }
    void delete_first() {
        node *temp = new node;
        temp = head;
        head = head -> next;
        delete temp;
    }
    void delete_last() {
        node *current = new node;
        node *previous = new node;
        current = head;
        while(current -> next != nullptr) {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous -> next = nullptr;
        delete current;
    }
    void delete_position(int pos) {
        node *current = new node;
        node *previous = new node;
        current = head;
        for(int i = 1;i < pos;i++) {
            previous = current;
            current = current -> next;
        }
        previous -> next=current -> next;
    }
};
int main(){
    list obj;
    obj.createnode(25);
    obj.createnode(50);
    obj.createnode(90);
    obj.createnode(40);
    cout<<"\n--------------------------------------------------\n";
    cout<<"---------------Displaying All nodes---------------";
    cout<<"\n--------------------------------------------------\n";
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-----------------Inserting At End-----------------";
    cout<<"\n--------------------------------------------------\n";
    obj.createnode(55);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Inserting At Start----------------";
    cout<<"\n--------------------------------------------------\n";
    obj.insert_start(50);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-------------Inserting At Particular--------------";
    cout<<"\n--------------------------------------------------\n";
    obj.insert_position(5,60);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Deleting At Start-----------------";
    cout<<"\n--------------------------------------------------\n";
    obj.delete_first();
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-----------------Deleing At End-------------------";
    cout<<"\n--------------------------------------------------\n";
    obj.delete_last();
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"--------------Deleting At Particular--------------";
    cout<<"\n--------------------------------------------------\n";
    obj.delete_position(4);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    char word[6] = "Hello"; /*C strings are null terminated i.e it has a end null character. So size of 6 even though 5 characters.*/
    const char *label = word;
    char word2[6];
    strcpy(word2, label);
    std::cout << word << std::endl;
    std::cout << label << std::endl;
    std::cout << word2 << std::endl;
    std::cout << word + 1<< std::endl;
    return 0;
}
