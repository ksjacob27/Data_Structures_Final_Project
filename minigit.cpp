#include "project.h"
#include <iostream>
#include <string>
#include <queue>
#include <fstream>

using namespace std;

void linkedList::printList(){
    singlyNode* temp = head;

    if(temp == NULL){

        cout << "Nothing in list :()" << endl;

        return;

    }

    while(temp->next != NULL){
    cout<< temp->fileName <<" -> ";
    temp = temp->next;
    }

    cout<<temp->fileName << endl;
}



singlyNode * linkedList::searchList(string fileName) {

    singlyNode* ptr = head;
    while (ptr != NULL && ptr->fileName != fileName)
    {
        ptr = ptr->next;
    }
    return ptr;
}


void linkedList::insert(singlyNode* previous, string newFileName){

    
    if(searchList(newFileName) == NULL){

    //Check if head is Null i.e list is empty
        if(head == NULL){
            head = new singlyNode;
            head->fileName = newFileName;
            head->fileVersion = "00";
            head->next = NULL;
        }

        // if list is not empty, look for prev and append our node there
        else if(previous == NULL)
        {
            singlyNode* newNode = new singlyNode;
            newNode->fileName = newFileName;
            newNode->fileVersion = "00";
            newNode->next = head;
            head = newNode;
        }

        else{

            singlyNode* newNode = new singlyNode;
            newNode->fileName = newFileName;
            newNode->fileVersion = "00";
            newNode->next = previous->next;
            previous->next = newNode;

        }
    }

  }

// void linkedList::remove(singlyNode* previous, string newFileName)
// {
//     singlyNode* a = head;
//     if (head = NULL)
//     {
//         cout << "List is empty nothing to delete!" << endl;
//     }
//     else if (searchList(newFileName) == NULL)
//     {
//         cout << "File does not exist." << endl;
//     }
//     else if(a->fileName.compare(newFileName)==0)
//     {
//         head = head->next;
//     }
//     else
//     {
//         while (a->next!=NULL)
//         {
//             singlyNode* a = previous;
//             remove(a , fileName);
//             if (a->next->fileName.compare(newFileName) == 0)
//             {
//                 singlyNode* b = a->next;
//                 a->next = b->next;
//                 delete b;
//                 break;
//             }
//             a = a->next;
//         }
//     }
// }


bool linkedList::deleteAtIndex(string newFileName)
{
  bool isDeleted = false;


  if(head == NULL){

    cout<< "List is already empty" << endl;

    return isDeleted;
  }



  // Special case to delete the head
    if (head->fileName.compare(newFileName) == 0) {

        
        singlyNode * temporary = head;
        
        head = head->next;

        delete temporary;

        return true;

    }

  singlyNode *pres = head;

  singlyNode *prev = NULL;

    while(pres->next != NULL){

      prev = pres;

      pres = pres->next;

    }
    

    prev->next = pres->next;


    delete pres;

    isDeleted = true;

	return isDeleted;
}