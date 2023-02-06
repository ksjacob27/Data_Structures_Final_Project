#include "project.h"
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

void current_path( const std::filesystem::path& p );

string getCurrentDirectory(){

   return fs::current_path();


}

int chdir(const char *path);

bool compareLines(string addFileName, string addFileName2){
    //addFileName2 = miniGit file name
    string directoryName = getCurrentDirectory();

    char * directory;

    string str_obj(directoryName + "/.minigit");

    directory = &str_obj[0];

    int ret;

    ret = chdir(directory);

    ifstream in_file;

    in_file.open(addFileName2);

    char * direct;

    string str_object(directoryName);

    direct = &str_object[0];

    int ret2;

    ret2 = chdir(direct);

    string lineMinigit;

    string lineDirectory;

    ifstream input_file;

    input_file.open(addFileName);

    while(!input_file.eof()){

        getline(input_file, lineDirectory);

        ret = chdir(directory);

        getline(in_file, lineMinigit);

        ret2 = chdir(direct);

        if(lineDirectory == lineMinigit){

            ;

    
        }

        else{

            return false;


        }



    }
        
                 
    return true;

}

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

void linkedList::searchFileName(){

  singlyNode * pointer  = head;

  while(pointer != NULL){

    string directorySearch = pointer->fileName;

    string minigitSearch = pointer->fileVersion + "_" + directorySearch;

    bool checker = false;

    checker = compareLines(directorySearch, minigitSearch);

    if(checker != true){

      string directoryName = getCurrentDirectory();

      string line;

      ifstream input_file;

      input_file.open(directorySearch);

      char * directory;

      string str_obj(directoryName + "/.minigit");

      directory = &str_obj[0];

      int ret;

      ret = chdir(directory);

      ofstream out_file;

      int x = 0;

      string a = pointer->fileVersion;

      stringstream temp(a);
      
      temp >> x;
      
      x++;

      to_string(x);

      pointer->fileVersion = x;

      cout << temp << endl;

      string outfileName = temp + directorySearch;

      out_file.open(outfileName); 

      char * direct;

      string str_obj2(directoryName);

      direct = &str_obj2[0];

      int ret2;

      ret2 = chdir(direct);

      if(!input_file.fail()){
          

          getline(input_file, line);

          if(line.empty()){
          
          ret = chdir(directory);

          out_file << endl;

          ret2 = chdir(direct);


          }
          else{

          ret = chdir(directory);

          out_file << line;

          ret2 = chdir(direct);
          
          }

          while(getline(input_file,line)){

            //  in_file >> line;

              ret = chdir(directory);

          //     current_path(/mnt/c/Users/DSM/Desktop/vs_code/2270/Project/.minigit); 

              out_file << line << endl;

          //     current_path(/mnt/c/Users/DSM/Desktop/vs_code/2270/Project);

              ret2 = chdir(direct);

          }

      }

          ret2 = chdir(direct);


    }

    pointer = pointer->next;


  }


}


void linkedList::insert(singlyNode* previous, string newFileName){

    
    if(searchList(newFileName) == NULL){

    //Check if head is Null i.e list is empty
        if(head == NULL){
            head = new singlyNode;
            head->fileName = newFileName;
            head->fileVersion = "0";
            head->next = NULL;
        }

        // if list is not empty, look for prev and append our node there
        else if(previous == NULL)
        {
            singlyNode* newNode = new singlyNode;
            newNode->fileName = newFileName;
            newNode->fileVersion = "0";
            newNode->next = head;
            head = newNode;
        }

        else{

            singlyNode* newNode = new singlyNode;
            newNode->fileName = newFileName;
            newNode->fileVersion = "0";
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