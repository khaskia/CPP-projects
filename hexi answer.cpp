#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int main(){
	
	
	/*
			BY/Mohamed Ali Khaskia
				mohamedalik88@gmail.com
				01276399758
				facebook.com/mo1994
		*/
		
	 cout << "welcome to mohamed ali khaskia ' s project "<<endl;
   string pass ="";
   char ch;
   string r;
   string ar[]={"h","e","x","i"," ","p","l","e","a","s","e"," ", "a","n","s","w","e","r"," ","t","h","i","s"," ","q","u","e","s","t","i","o","n"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
   cout << "Enter your Petition\n";
   ch = _getch();
 
   
   for (int x=0;x<=59;x++){
   	
   if(ch != 13){
   	  
      pass.push_back(ch);
      ch = _getch();
      cout << ar[x];
      
   }
}
   
   
   cout <<"\n inter your Qerstion now\n";
   cin>>r;
   
   for(int x=0;x<20;x++){
   	cout <<"*"<<endl;
   }
   
   cout <<pass;
   
   system("pause");
   return 0;
}