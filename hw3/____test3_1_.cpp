#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
 class a_book	
 { 
 public:
	 char name[50];
	 char writer[20];
	 char publisher[30];
	 char year[10];
 };
	 void save_change(a_book book[], int& length)
	 {
		 ofstream outfile;
		 outfile.open("ordered.txt", ios::out);
		 for (int i = 0; i < length; i++)
			 outfile<< setw(50) << setiosflags(ios::left) << book[i].name << setw(20) << setiosflags(ios::left) << book[i].writer << setw(30) << setiosflags(ios::left) << book[i].publisher << setw(10) << setiosflags(ios::left) << book[i].year<<endl;
		 outfile.close();
		 return;
	 }
	 bool cmpname(const a_book& x, const a_book& y)
	 {
		 return strcmp(x.name, y.name) < 0;
	 }
	 int main()
	 {
		 a_book book[99]; int length = 0;
		 ifstream infile;
		 infile.open("books.txt", ios::in);
		
		 while (!infile.eof())
		 { 
			 infile >> book[length].name>> book[length].writer>> book[length].publisher >> book[length].year;
			 length++;
		 }
		 infile.close();
		 sort(book, book + length, cmpname);
		 save_change(book, length);
		 int instruct;
		 cin >> instruct;
		 while (instruct != EOF)
		 {
			 switch (instruct)
			 {
			 case 1:
			 { 
				 cin >> book[length].name >> book[length].writer >> book[length].publisher >> book[length].year;
				 length++;
				 sort(book, book + length, cmpname);
				 save_change(book, length);
				break; 
			 }
			 case 2:
			 { 
				 char name[50];
				 cin >> name;
				 for (int i = 0; i < length; i++)
					 if ((strstr(book[i].name, name)) != NULL)
					 {
						 cout << setw(50) << setfill(' ') << book[i].name << setw(20) << setfill(' ') << book[i].writer << setw(30) << setfill(' ') << book[i].publisher << setw(10) << setfill(' ') << book[i].year;
					 }
				 save_change(book, length);
				 break; 
			 }
			 case 3:
			 { 
				 char name[50];
				 cin >> name;
				 for (int i = 0; i < length; i++)
					 if ((strstr(book[i].name, name)) != NULL)
					 {
						 for (int j = i; j < length; j++)
							 book[j] = book[j + 1];
						 length--;
						 i--;
					 }
				 save_change(book, length);
				break; 
			 }
			 default:
				 break;
			 }
			 if (instruct == 0)
			 {
				 break;
			 }
			 cin >> instruct;
		 }
		 return 0;
	 }
