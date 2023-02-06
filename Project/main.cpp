#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "project.h"
#include <filesystem>
#include <unistd.h>
#include <sstream>

namespace fs = std::filesystem;


using namespace std;

void init(){

    fs::remove_all(".minigit");

    fs::create_directory(".minigit");

}

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




int main(){

init();

int choice = 0;
string addFileName;
string removeFileName;
int commit;

singlyNode * link;

doublyNode * d;

d->commitNumber = 0;

d->head = link;

singlyNode * prev = NULL;

linkedList l; 

while(choice != 6)

    {
 
        cout << "Please select an option" << endl;
        cout << "1. Add file" << endl;
        cout << "2. Remove file" << endl;
        cout << "3. Commit Changes" << endl;
        cout << "4. Checkout" << endl;
        cout << "5. Print List" << endl;
        cout << "6. Quit" << endl;

        cout << "Option: ";
           cin >> choice;
    
        switch(choice)
            {
               case 1: //add a file
                {
                    int check = 0;
                    cout << "Enter File Name:" << endl;

                    cin >> addFileName;

                    ifstream in_file;

                   in_file.open(addFileName);

                    if(in_file.fail()){

                        while(check == 0){

                            cout << "Invalid File Name. Please enter a new file name" << endl;

                            cout << "Enter File Name:" << endl;
                            
                            cin >> addFileName;

                            ifstream in_file;

                            in_file.open(addFileName);

                            if(!in_file.fail()){
                                
                                check = 1;

                            } 

                        }

                    }

                    l.insert(prev, addFileName);

                    cout << "printing new LL" << endl;

                    l.printList();

                    cout << "adding to .minigit directory" << endl;

                    cout << endl;

                   // cout << "current directory" << " " << getCurrentDirectory() << endl;

                    string directoryName = getCurrentDirectory();

                    string line;

                    ifstream input_file;

                    input_file.open(addFileName);

                    char * directory;

                    string str_obj(directoryName + "/.minigit");

                    directory = &str_obj[0];

                    int ret;

                    ret = chdir(directory);

                    // current_path(/mnt/c/Users/DSM/Desktop/vs_code/2270/Project/.minigit);

                    link = l.searchList(addFileName);

                    ofstream out_file;

                    string outfileName = link->fileVersion + "_" + addFileName;

                    out_file.open(outfileName); 

                    
                    char * direct;

                    string str_obj2(directoryName);

                    direct = &str_obj2[0];

                    int ret2;

                    ret2 = chdir(direct);

                    // current_path(/mnt/c/Users/DSM/Desktop/vs_code/2270/Project);

                    // cout << "here" << endl;

                    if(!in_file.fail()){
                        

                        getline(in_file, line);

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

                        while(getline(in_file,line)){

                          //  in_file >> line;

                            ret = chdir(directory);

                        //     current_path(/mnt/c/Users/DSM/Desktop/vs_code/2270/Project/.minigit); 

                            out_file << line << endl;

                        //     current_path(/mnt/c/Users/DSM/Desktop/vs_code/2270/Project);

                            ret2 = chdir(direct);

                        }

                    }

                        ret2 = chdir(direct);

                    //  current_path(/mnt/c/Users/DSM/Desktop/vs_code/2270/Project);


                    // setCurrentDirectory(C:\Users\DSM\Desktop\vs_code\2270\Project\.minigit);
                    // setCurrentDirectory(C:\Users\DSM\Desktop\vs_code\2270\Project); //? this would change depending on whose system we are using

                    //idea: string line, take each line from files copy it into string line, change directory make new file 
                    //using out_file, rename with filesystem, then paste the line into the new file
                    //this probably should be a while loop similar to those from 1300


                    break;
                }
                
                    
            case 2: //remove a file
            {
            
            bool isDeleted;
            string filename;
            cout << "Which file would you like to delete?" << endl;
            
            cin >> filename;

            isDeleted = l.deleteAtIndex(filename);


                
                break;
            }

            case 3:
            { //commit 

                l.searchFileName();


                break;
            }

            case 4: //checkout 
            {
                int Number;

                int test;

                cout << "WARNING: YOUR CURRENT FILES WILL BE OVERWRITTEN, PLEASE COMMIT CURRENT CHANGES!" << endl;

                cout << endl;

                cout << "Input 0 to go back to menu, or any other number to continue" << endl;

                cin >> Number;

                if(Number == 0){

                    break;

                }
                else{

                cout << "Please enter a commit Number that you wish to go back to: ";

                cin >> Number;

                while(d != NULL){

                    test = d->commitNumber;

                    if(test == Number){

                        
                        //copy files from .minigit?


                    }

                    d = d->previous;


                }

                }
                
                
                        
                break;
            }
            case 5: //print
            {
   
                l.printList(); 

                break;

            }

            case 6: //quit

            {

                cout << "<3" << endl;

                return 0;
            
                break;    


            }

    default: cout << "Invalid input." << endl;

            break;



            }
    }


}
