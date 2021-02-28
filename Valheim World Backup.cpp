#define WINVER 0x0600
#define _WIN32_WINNT 0x0600
#include <windows.h>
#include <shlobj.h>
#include <iostream>
#include <stdlib.h> 
#include <direct.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <algorithm> 
#include <chrono>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

bool file_exists(string filename) {
    struct stat fileinfo;

    return !stat(filename.c_str(), &fileinfo);
}

bool world_exist( const std::string &Filename )
{
    return access( Filename.c_str(), 0 ) == 0;
}

inline std::string trim(std::string& str)
{
    str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
    str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces
    return str;
}



int main(){
	

	int backupInterval;
	string path;
	string worldName;
	string combined;
	string backupFolder;
	cout << "====================================================================================================================" << endl;
	cout << "\n\t\t\t\t\t\[ Valheim World Backup ]" << endl;
	cout << "\t\t\t\t\t\tv1.0a" << endl;
	cout << "\t\t\t\tDeveloped by Paul Gomez [Demos#3458]" << endl;
	cout << "\n====================================================================================================================" << endl;
	
	cout << "\nExample: [ C:\\Users\\Paul\\AppData\\LocalLow\\IronGate\\Valheim\\worlds ]";
	cout << "\n\n@vwb: Please Enter Your Valheim World Folder: "; 	
	cin >> path;
	if(file_exists(path)){
		cout << "\n@vwb: Directory Found";
//		cout<< ".";
//		sleep(1);
//		cout<< ".";
//		sleep(1);
//		cout<< ".";
//		sleep(1);
		cout << "\n\n@vwb: Enter World Name: ";
		cin >> worldName;
		combined = path + "\\"+worldName+".db";
		
			if(world_exist(combined)){
				cout << "\n@vwb: World Found";
				cout << "\n\n@vwb: Backup Interval(seconds): ";
				cin >> backupInterval;
				cout << "          +----Backup Interval: " << backupInterval << "s";
				
							
				backupFolder = path+"\\VWB_"+worldName;
				
				cout << "\n\nCreating Backup Folder: VWB_" +worldName;
						sleep(0.5);
						cout<< ".";
						sleep(1);
						cout<< ".";
						sleep(0.5);
						cout<< ".";

				char* char_arr;
			    string str_obj(backupFolder);
			    char_arr = &str_obj[0];
				mkdir(char_arr);
				
				
				 int milli_seconds=backupInterval*1000;
				 
				 string dbFileArg = combined;
				 string fwlFileArg= path + "\\"+worldName+".fwl";
				 string dbOldFile = combined + ".old";
				 string fwlOldFile = fwlFileArg + ".old";
				  while(1)
				  {
				  	cout << "\n" << dbFileArg <<endl;
				  	cout << fwlFileArg<<endl;
				  	cout << dbOldFile<<endl;
				  	cout << fwlOldFile<<endl;
				  	
				  	string bfolder = "VWB_"+worldName;
				  	
				  	string A = backupFolder + "\\" +  worldName + ".db";
				  	string B = backupFolder + "\\" + worldName + ".fwl";
				  	string C = backupFolder + "\\" + worldName + ".db.old";
				  	string D = backupFolder +  "\\" + worldName + ".fwl.old";
				  	
				  	/////////////////////////////////

				  	char* char_arr;
				    string str_obj(dbFileArg);
				    char_arr = &str_obj[0];
				    
				    char* char_arr2;
				    string str_obj2(A);
				    char_arr2 = &str_obj2[0];
				    
				  	/////////////////////////////////
				  	
					char* char_arr3;
				    string str_obj3(fwlFileArg);
				    char_arr3 = &str_obj3[0];
				    
				    char* char_arr4;
				    string str_obj4(B);
				    char_arr4 = &str_obj4[0];	
				    
				  	/////////////////////////////////
				  	
				  	char* char_arr5;
				    string str_obj5(dbOldFile);
				    char_arr5 = &str_obj5[0];
				    
				    char* char_arr6;
				    string str_obj6(C);
				    char_arr6 = &str_obj6[0];	
				    
				  	/////////////////////////////////
				  	
				  	char* char_arr7;
				    string str_obj7(fwlOldFile);
				    char_arr7 = &str_obj7[0];
				    
				    char* char_arr8;
				    string str_obj8(D);
				    char_arr8 = &str_obj8[0];	
				  	
				  	/////////////////////////////////
				  	
				  	if( remove(char_arr2) != 0 )
				    cout << "Error deleting file";
				  	else
				    cout << "File Overwritten";
				  	if( remove(char_arr4) != 0 )
				    cout << "Error deleting file";
				  	else
				    cout << "File Overwritten";
				    if( remove(char_arr6) != 0 )
				    cout << "Error deleting file";
				  	else
				    cout << "File Overwritten";
				    if( remove(char_arr8) != 0 )
				    cout << "Error deleting file";
				  	else
				    cout << "File Overwritten";
				  	
				  	CopyFile(char_arr,char_arr2,true);

				  	CopyFile(char_arr3,char_arr4,true);

					CopyFile(char_arr5,char_arr6,true);

				  	CopyFile(char_arr7,char_arr8,true);
			
					cout << "\n" << char_arr2 <<endl;
				  	cout << char_arr4<<endl;
				  	cout << char_arr6<<endl;
				  	cout << char_arr8<<endl;

				     Sleep(milli_seconds);
				  }
				
			} else {
				cout << combined << endl;
				cout << "\n@vwb: World not Found!";
			}
			
			
			
			
					
	} else {
		cout << "\n Directory doesnt exist";
	}
	
	

//	sleep(1);
// 	auto t1 = std::chrono::high_resolution_clock::now();
// 	
// 		
//	
//	
//
//	cout<< ".";
//	sleep(1);
//	cout<< ".";
//	sleep(1);
//	cout<< ".";
//	sleep(1);
//
//	    
//    auto t2 = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
//
//	cout << duration;
//	CopyFile("test.txt","test2.txt",true);
//	
//  
//    mkdir("backup");

	
	return 0;
}
