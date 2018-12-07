// Qi Guo Project2
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"
#include "list.h"

using namespace std;

int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}

int main(int argc, char* argv[])
{
  string dir; 
  vector<string> files = vector<string>();
  word *myword = new word;
  int used = 0;
  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }
  
  string slash("/");
  for (unsigned int i = 0;i < files.size();i++) {
    if(files[i][0]=='.')continue; //skip hidden files
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file...
    string word;
    while(true){
      fin>> word;
      if(fin.eof()) {cout << "EOF " << files[i] << endl; break;}
      else {
	cout<<files[i]<<"::"<< word <<endl;
	
	// Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
	// Use these two strings to search/insert in your array/list of 
	
	myword -> insert(word,files[i]);
      }
    }
    fin.close();    
  }
  cout << "--------------------------------------" << endl;
  cout << "This is the next part of the program " << endl;
//  myword -> printw();
//}
  string input1;
  string input2;
  
  do{
	cout << "Enter a word you want to search, "
	<< "or 'exit' to stop the program: ";
	cin >> input1;
	if(input1 == "exit"){
            break;
	}
        cout << "Enter another word you want to search, "
        << "or 'exit' to stop the program: ";
        cin >> input2;
        if(input2 == "exit"){
            break;    
        }
           
  }while(true);

}
