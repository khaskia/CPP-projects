#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstring>
#include <stdio.h>
using namespace std;

/*
made by Eng : Mohamed Ali Khaskia
facebook.com/1994
mohamedalik94@hotmail.com
*/



struct sys{
	char Id[5];
	char FName[15];
	char LName[15];
	char Dep[30];
	char Grade[5];
	char Rating[15];

};


int check_ID(char a[5]){
	sys s;
	fstream file;
	file.open("file.txt", ios::in);
	int f = 0;

	while (!file.eof()){
		file.getline(s.Id, 5, '|');
		file.getline(s.FName, 15, '|');
		file.getline(s.LName, 15, '|');
		file.getline(s.Dep, 30, '|');
		file.getline(s.Grade, 30, '|');
		file.getline(s.Rating, 15);
		if (strcmp(s.Id, a) == 0){
			f = 1;
		}


	}
	file.close();
	if (f == 1){ return 1; }
	else { return 0; }



}




void insert(){
	sys s;
	char ch='n';
	fstream file;
	file.open("file.txt", ios::out | ios::app);
	int f = 0;
	int v;
	do{

		cout << "Student_ID::";
		cin.getline(s.Id, 5);
		cin.getline(s.Id, 5);

		v = atoi(s.Id);

		f = check_ID(s.Id);
		if (f == 0){
			if (v <= 999 && v != 0){

				cout << "first name::";
				cin.getline(s.FName, 15);
				cout << "Last Name::";
				cin.getline(s.LName, 15);
				cout << "The Dapartment::";
				cin.getline(s.Dep, 30);
				cout << "The Grade::";
				cin.getline(s.Grade, 5);
				cout << "The Rating::";
				cin.getline(s.Rating, 15);




				file << s.Id << "|" << s.FName << "|" << s.LName << "|" << s.Dep << "|" << s.Grade << "|" << s.Rating << "\n";

				cout << "do u want to add another one (y|n)??";
				cin >> ch;
			}
			else{
				cout << "id Must be from 1 to 999\n";
			}

		}
		else{
			cout << "~~~ you enrerd repeated ID  Plz inter availed one \n";

		}


	} while (ch == 'y');
	file.close();

}







void viewdata(){

	sys s;
	fstream file;
	file.open("file.txt", ios::in);

	cout << "id:: " << "\t" << "FirstName" << "\t" << "SecondName" << "\t" << "Department" << "\t" << "Grade" << "\t" << "Rating" << "\n";

	while (!file.eof()){
		file.getline(s.Id, 5, '|');
		file.getline(s.FName, 15, '|');
		file.getline(s.LName, 15, '|');
		file.getline(s.Dep, 30, '|');
		file.getline(s.Grade, 30, '|');
		file.getline(s.Rating, 15);
		//if (s.Rating)

		cout << s.Id << "\t" << s.FName << "\t\t" << s.LName << "\t\t" << s.Dep << "\t\t" << s.Grade << "\t" << s.Rating << "\n";


	}



}







void search_id(){
sys s;
fstream file;
char id_search[25];

file.open("file.txt", ios::in);

cout << "enter search id ::";
cin >> id_search;

while (!file.eof()){
	file.getline(s.Id, 5, '|');
	file.getline(s.FName, 15, '|');
	file.getline(s.LName, 15, '|');
	file.getline(s.Dep, 30, '|');
	file.getline(s.Grade, 30, '|');
	file.getline(s.Rating, 15);


	if (strcmp(s.Id, id_search) == 0){




		cout << "id:: " << "\t" << "First Name" << "\t" << "Second Name" << "\t" << "The Department" << "\t" << "Grade" << "\t" << "Rating" << "\n";
		cout << s.Id << "\t" << s.FName << "\t\t" << s.LName << "\t\t" << s.Dep << "\t\t" << s.Grade << "\t" << s.Rating << "\n";
	}
}

}

void search_name(){
sys s;
fstream file;
char name_search[25];

file.open("file.txt", ios::in);

cout << "enter search name ::";
cin.getline(name_search,25);
cin.getline(name_search, 25);



while (!file.eof()){
	file.getline(s.Id, 5, '|');
	file.getline(s.FName, 15, '|');
	file.getline(s.LName, 15, '|');
	file.getline(s.Dep, 30, '|');
	file.getline(s.Grade, 30, '|');
	file.getline(s.Rating, 15);
if (strcmp(s.FName, name_search) == 0){

	cout << "id:: " << "\t" << "First Name" << "\t" << "Second Name" << "\t" << "The Department" << "\t" << "Grade" << "\t" << "Rating" << "\n";
	cout << s.Id << "\t" << s.FName << "\t\t" << s.LName << "\t\t" << s.Dep << "\t\t" << s.Grade << "\t" << s.Rating << "\n";
	}
}

}






void remove(){
sys s;
char id_re[25];
fstream file;
file.open("file.txt",ios::in);
fstream file2;
file2.open("help.txt",ios::out);
cout<<"enter id for removing \t";
cin>>id_re;

while(!file.eof()){
	file.getline(s.Id, 5, '|');
	file.getline(s.FName, 15, '|');
	file.getline(s.LName, 15, '|');
	file.getline(s.Dep, 30, '|');
	file.getline(s.Grade, 30, '|');
	file.getline(s.Rating, 15);
if(strcmp(s.Id,id_re)==0){
continue;

}//endif
else {
	file2 << s.Id << "|" << s.FName << "|" << s.LName << "|" << s.Dep << "|" << s.Grade << "|" << s.Rating << "\n";
}//endelse



}//while
cout << "Done --- Removed\n";
file.close();
file2.close();

rename("file.txt", "old.txt");
rename("help.txt", "file.txt");

}





void update(){
sys s;
int f=0;
int v = 0;
char id_s[25];
fstream file;
file.open("file.txt",ios::in);
fstream file2;
file2.open("help.txt",ios::out);
cout<<"enter id to update\t";
cin>>id_s;

char ex[] = { 'e', 'x', 'c', 'e', 'l', 'l', 'e', 'b','t' }; //   8
char vgood[] = { 'v', ' ', 'g', 'o', 'o', 'd', ' ', ' ' }; //8
char good[] = { 'g', 'o', 'o', 'd', ' ', ' ', 'y', 'm' }; // 8
char pass[] = { 'p', 'a', 's', 's', 'e', 'd',' ',' ' };// 8
char fail[] = { 'f', 'a', 'i', 'l', 'e', 'd',' ',' ' }; // 8

while(!file.eof()){
	file.getline(s.Id, 5, '|');
	file.getline(s.FName, 15, '|');
	file.getline(s.LName, 15, '|');
	file.getline(s.Dep, 30, '|');
	file.getline(s.Grade, 30, '|');
	file.getline(s.Rating, 15);
if(strcmp(s.Id,id_s)==0){
	/**/
	
	cout << "Student_ID::";
	cin.getline(s.Id, 5);
	cin.getline(s.Id, 5);
	int m = atoi(id_s);
	v = atoi(s.Id);

	f = check_ID(s.Id);
	if (f == 0 ){
		if (v <= 999 && v != 0){
			ki:
			cout << "first name::";
			cin.getline(s.FName, 15);
			cout << "Last Name::";
			cin.getline(s.LName, 15);
			cout << "The Dapartment::";
			cin.getline(s.Dep, 30);
		again:
			cout << "The Grade::";
			cin.getline(s.Grade, 5);

			/////////////////////////// calculating Grade
			int o = atoi(s.Grade);
			if (o <= 100 && o != 0){
				if (o >= 85 && o < 100){
					for (int i = 0; i < 9; i++)
					{
						
						s.Rating[i] = ex[i];
					}

				}else if(o >= 75 && o < 85){
					for (int i = 0; i < 9; i++)
					{
						
						s.Rating[i] = vgood[i];
					}

				}
				else if (o >= 65 && o < 75){
					for (int i = 0; i < 9; i++)
					{
						
						s.Rating[i] = good[i];
					}

				}
				else if (o >= 50 && o < 65){
					for (int i = 0; i < 9; i++)
					{
					
						s.Rating[i] = pass[i];
					}

				}
				else {
					for (int i = 0; i < 9; i++)
					{
					
						s.Rating[i] = fail[i];
					}

				}

				///////////////////////////////////////////////////////////////////



			}else{ cout << "Grade must be number to 100%"; goto again; }
			// cout << "The Rating::";
			// cin.getline(s.Rating, 15);


		}else{ cout << "wrong ID\n"; }
		
	}
	else if (v == m){
		goto ki;


	}else{ cout << "not found\n"; }

file2 << s.Id << "|" << s.FName << "|" << s.LName << "|" << s.Dep << "|" << s.Grade << "|" << s.Rating << "\n";
}else {
file2 << s.Id << "|" << s.FName << "|" << s.LName << "|" << s.Dep << "|" << s.Grade << "|" << s.Rating << "\n";

 }


}



file.close();
file2.close();

rename("file.txt", "old.txt");
rename("help.txt", "file.txt");


}
/*
void view(int arr[], int nelemes){
	for (int x = 0; x < nelemes; x++){
		cout << "" << arr[x] << "\n";

	}

}
void sortarray(int arr[], int nelemes){
	int fl = 0;
	for (int x = 0; x < nelemes; x++){
		for (int y = 0; y < nelemes; y++){
			if (arr[x]<arr[y]){
				fl = arr[x];
				arr[x] = arr[y];
				arr[y] = fl;
			}
		}

	}




}


void saveID(){
	sys s;
	fstream file;
	file.open("file.txt", ios::in);

	
	while (!file.eof()){
		file.getline(s.Id, 5, '|');
		file.getline(s.FName, 15, '|');
		file.getline(s.LName, 15, '|');
		file.getline(s.Dep, 30, '|');
		file.getline(s.Grade, 30, '|');
		file.getline(s.Rating, 15);
		
		
		v[x]=atoi(s.Id);
		x++;
	}
	
	sortarray(v, x);
	view(v, x);


}

*/

void binarysearch(){

	////////////// Set the valus ::: 

	sys s;
	fstream file;
	file.open("file.txt", ios::in);

	int x = 0;
	int v[100];
	while (!file.eof()){
		file.getline(s.Id, 5, '|');
		file.getline(s.FName, 15, '|');
		file.getline(s.LName, 15, '|');
		file.getline(s.Dep, 30, '|');
		file.getline(s.Grade, 30, '|');
		file.getline(s.Rating, 15);


		v[x] = atoi(s.Id);
		x++;
	}



	/// Start the binary Search

	char searchkey[5];
	//int searchkey;
	cout << "enter key\n";
	cin >> searchkey;
	cout << endl;
	int f = 0;





	//sortarray(v, x);
	int fl = 0;
	for (int q = 0; q < x; q++){
		for (int y = 0; y < x; y++){
			if (v[q]<v[y]){
				fl = v[q];
				v[q] = v[y];
				v[y] = fl;
			}
		}

	}



	//view(v, x);
	for (int q = 0; q < x; q++){
		cout << "" << v[q] << "\n";
	}


	int nelemes = x;
	int lower = 0;
	int upper = nelemes;
	int curin;
	while (true)
	{
		curin = (lower + upper) / 2;
		if (v[curin] == atoi(searchkey)){
			f = 1; break; // We Found it
		}
		else if (lower>upper){
			f = 0; break; // can't find it 
		}
		else{
			if (v[curin] < atoi(searchkey))
				lower = curin + 1;
			else
				upper = curin - 1;
		}

	}


	if (f == 1){
		cout << "found\n";

		//s.Id = searchkey;
		//cout << "id:: " << "\t" << "First Name" << "\t" << "Second Name" << "\t" << "The Department" << "\t" << "Grade" << "\t" << "Rating" << "\n";
		//cout << searchkey << "\t" << s.FName << "\t\t" << s.LName << "\t\t" << s.Dep << "\t\t" << s.Grade << "\t" << s.Rating << "\n";
		cout << file.rdbuf();
	}
	else
	{
		cout << "not fount\n";
	}

	// view
	

}


void Start(){


	int x;
	char f = 'y';
	while (f == 'y'){
		remove("old.txt");
		system("cls");
		cout << "\a welcome to 3th prepschool degrees \n";
		cout << "\tfor insert new data press 1:\n\tfor view all degrees press 2:\n\tfor make a search by id press 3:\n\tfor make a search by name press 4:\n\tfor delete record press 5:\n\tfor update old  record info press 6:\n\tfor Binary_Search 7\n for Exit Press 8 \n ";
		cout << "\n";
		cin >> x;
		if (x == 1){ insert(); }

		else if (x == 2){ viewdata(); }

		else if (x == 3){ search_id(); }

		else if (x == 4){ search_name(); }

		else if (x == 5){ remove(); }
		else if (x == 6){ update(); }
		else if (x == 7){ binarysearch(); }
		else if (x == 8){ break; }
		else{ cout << "\a\a\a\n\t%%%%% ERORR ENTRE %%%%%%%%\n"; }

		cout << "\n\tto Start over again press y :\n";
		cin >> f;
	}
	//remove("old.txt");
}


int main(){
	//	insert();
	//binarysearch();
	//saveID();



	//viewdata();



	Start();


	//search_id();
	//search_name();
	//remove();
	//update();

	cout << endl;
	system("pause");
	return 0;
}