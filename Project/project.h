#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>

using namespace std;

struct singlyNode{

    std::string fileName;
    
    std::string fileVersion;

    singlyNode * next;


};

struct doublyNode{

    int commitNumber;

    singlyNode * head;

    doublyNode * previous;

    doublyNode * next;


};

class linkedList

{

    private:

        singlyNode * head;

        // string fileVersion;

        // int commitNumber;

    public:
        linkedList(){
	    
            head = NULL;

        }

        singlyNode* searchList(string fileName);
        void insert(singlyNode* previous, string newFileName);
        void remove(singlyNode * previous, string newFileName);
        bool deleteAtIndex(string newFileName);
        void searchFileName();
        void printList();


    
        

};

#endif