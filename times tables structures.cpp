// jack kelly 20089844 times tables - using structure
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;
#define MAX_TIMESTAMP 13
const unsigned short int Numquestions = 10;
struct questions
{
	short int operand1;
	char arithmetic_operator;
	short int operand2;
	short int user_ans;
	short int true_ans;
	bool correct;
};


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool login_user(ifstream&, string&, string&, string&, unsigned short int&, unsigned short int&);// user log in
unsigned short int menu(unsigned short int, unsigned short int, string, unsigned short int&);// user choosing what they want to do
void user_number_choice (unsigned short int &);//choice in practice
void random_or_not(unsigned short int &);//random practice or not
void add_sub_mult_div(unsigned short int &);// user chooses what type of table to practice
void randomiser(unsigned short int[], unsigned short int, unsigned short int, unsigned short int, unsigned short int);//randomises order of questions
void tables(unsigned short int [], unsigned short int, unsigned short int, unsigned short int, unsigned short int&, unsigned short int&, unsigned short int);// asks tables
void results(unsigned short int, unsigned short int);//results for tables
void randomquiz(questions [], unsigned short int, string, unsigned short int);// quiz generator and questions to user
void randomquizresults(questions [], unsigned short int, string,string);//results for quiz to file and user
void addstudent();// add student to the class
string getdate();// date for file name
void viewfile(string);// teahcer can view results

int main() {
	unsigned short int option;
	bool found = false;
	ifstream fin, fout;
	string displayname, username, password;
	unsigned short int number, choice,choice2, i, j, correct, incorrect,lvl, agegroup;
	unsigned short int randomsum[13];
	char repeat;
	
	
	questions *num;
	num = new questions[Numquestions];
	if (num == NULL)
	{
		perror ("error defining dynamic structure \n") ;
		exit(1);
	}
	cout << "welcome to your maths practice facility\n";
	system("pause");
	system("cls");
	fin.open("users.txt", ios::in);
	if(fin.fail())
	{
		perror("error opening file for reading");
	}
	
	login_user(fin, username, password, displayname, lvl, agegroup);
	fin.close();
	do{
		correct = 0;
		incorrect = 0;
		i = 0;
		j = 0;
		choice = 0;
		choice2 = 0;
		number = 0;
		srand((unsigned)time(0));
		menu(lvl, agegroup, displayname, option);
		switch(option)
		{
			case 0:
				break;
			case 1:
				user_number_choice(number);
				random_or_not(choice2);
				add_sub_mult_div(choice);				
				randomiser(randomsum,i,j,choice2,number);
				
				tables(randomsum, i, choice2, choice, correct, incorrect, number);		//function calls for practicing tables
				results(correct, incorrect);
		 	break;
			case 2:
				randomquiz(num, i, username, agegroup); // for taking the quiz
		}
		
		
		cout << "if you are done with our facilities press y otherwise enter another key\n";
		cin >> repeat;	// repeat using the program but only as the same user
		
	}while(repeat != 'y' && repeat !='Y');
		
cout << "thank you for using our application!!";
	
	return 0;
}
unsigned short int menu (unsigned short int lvl, unsigned short int agegroup, string displayname, unsigned short int &option)
{
	short int choice;
	string file;
	if(lvl == 1)
	{
		cout << "welcome " << displayname << endl;
		do
		{
		
			cout << "If you would like to view student results press 1\n";
			cout << "If you would like to add a student to the class press 2\n";
			cin >> choice;
			while(cin.fail())
			{
				cin.clear();
		  		cin.ignore(80,'\n');		// testing for a non numeric entry
		  		cout << "invalid option please enter a number\n";
				cin >> choice;
				
			}
			if(choice > 2 || choice <1)// checking if entry is in the given range
				cout << "please enter either one of the listed options\n";
				system("pause");
				system("cls");
		}while(choice > 2 || choice < 1);
		if(choice == 1)
		{
			cout << "enter the file name with the students results\n";
			cin >> file;
			viewfile(file);			//viewing results of student
		}
		if(choice == 2)
		{
			addstudent();		// adding student ot the class
		}
		return 0;
	}
	else if (lvl == 2 && agegroup == 1) // first or second class
	{
	
		do
		{
			cout << "welcome " << displayname << " you are a 1st/2nd class student\n";
			cout << "if you would like to practice your tables enter 1\n";
			cout << "if you would like to take a quiz enter 2\n";
				cin >> option;
				while(cin.fail())
				{
					cin.clear();
			  		cin.ignore(80,'\n');		// testing for a non numeric entry
			  		cout << "invalid option please enter a number\n";
					cin >> option;
				}
				if(option > 2 || option <1)
				cout << "please enter either one of the listed options\n";
				system("pause");
				system("cls");

		}while(option > 2 || option <1);
		
	}
	
	else if (lvl == 2 && agegroup == 2) //3rd or 4th class
	{
	
		do
		{
			cout << "welcome " << displayname << " you are a 3rd/4th student\n";
			cout << "if you would like to practice your tables enter 1\n";
			cout << "if you would like to take a quiz enter 2\n";
				cin >> option;
				while(cin.fail())
				{
					cin.clear();
			  		cin.ignore(80,'\n');		// testing for a non numeric entry
			  		cout << "invalid option please enter a number\n";
					cin >> option;
					
				}
				if(option > 2 || option <1)
				cout << "please enter either one of the listed options\n";
				system("pause");
				system("cls");

		}while(option > 2 || option <1);
		
	}
	
	
	else if (lvl == 2 && agegroup == 3) //5th or 6th class
	{
	
		do
		{
			cout << "welcome " << displayname << " you are a 5th/6th student\n";
			cout << "if you would like to practice your tables enter 1\n";
			cout << "if you would like to take a quiz enter 2\n";
				cin >> option;
				while(cin.fail())
				{
					cin.clear();
			  		cin.ignore(80,'\n');		// testing for a non numeric entry
			  		cout << "invalid option please enter a number\n";
					cin >> option;
					
				}

			if(option > 2 || option <1)
				cout << "please enter either one of the listed options\n";
				system("pause");
				system("cls");
		}while(option > 2 || option <1);
		
	}
	else
		perror("problem in age and lvl section\n");
	
	return option;
}
void user_number_choice (unsigned short int &num)
{
	cout << "enter number for tables\n";
		cin >> num;
		while(cin.fail())
		{
			cin.clear();
	  		cin.ignore(80,'\n');		// testing for a non numeric entry
	  		cout << "invalid option please enter a number\n";
			cin >> num;
		}
	system("cls");
	return;
}

void random_or_not(unsigned short int &choice2)
{
	cout << "would you like to do your sums in order or would you like to do them int a random order?\n";
		do
		{
			cout << "press 1 for in order\n";
			cout << "press 2 for random\n";	// random order or in order
			cin >> choice2;
			while(cin.fail())
			{
				cin.clear();
		  		cin.ignore(80,'\n');		
		  		cout << "you entered an invalid option please choose from the options listed\n";
				cin >> choice2;
			}
			if (choice2 > 2 || choice2 < 1)
			cout << "invalid option, please select one of the choices listed above\n";
		}while(choice2 > 2 || choice2 < 1);
		system ("cls");
	
	return;
}


void add_sub_mult_div(unsigned short int &choice)
{
	do
		{
			cout << "choose from the options below\n";
			cout << "1. addition\n";
			cout << "2. subtraction\n";
			cout << "3. multiplication\n";
			cout << "4. division\n";
			cin >> choice;			//choosing which type of tables to do
			while(cin.fail())
			{
				cin.clear();
		  		cin.ignore(80,'\n');		
		  		cout << "you entered an invalid option please choose from the options listed\n";
				cin >> choice;
			}
			if(choice < 1 || choice > 4)
				cout <<"Error option can only be between 1 and 4\n";
		}
		while(choice < 1 || choice > 4);	// what you dont want choice to be
	system ("cls");
}

void randomiser(unsigned short int randomsum[], unsigned short int i, unsigned short int j, unsigned short int choice, unsigned short int number)
{
	switch (choice)
	{ case 1: case 3:
			for(i = 0; i <= 12; i++) 
			{
				
		         randomsum[i] = rand() % 13 + 0;
		         j = 0;
		         while(j < 12)
		         {														// random number generators
		            if(randomsum[j] == randomsum[i] && j != i) 
		            {
		              --i;         
		              break;        
		            }
		            else
		              ++j;        
		            
		     	} 
			}
			break;
		
		case 2:
			for(i = 0; i <= 12; i++) 
			{
				
		         randomsum[i] = rand() % 13 + number;
		         j = 0;
		         while(j < 12)
		         {
		            if(randomsum[j] == randomsum[i] && j != i)  	// uniqueness
		            {
		              --i;          
		              break;        
		            }
		            else
		              ++j;        
		            
		     	} 
			}
			break;
		case 4:
			for(i = 0; i <= 12; i++) 
			{
				
		         randomsum[i] = rand() % (number * 13) + 0;
		         j = 0;
		         while(j < 12)
		         {
		            if(randomsum[j] == randomsum[i] && j != i || randomsum[i]%number != 0) 
		            {
		              	--i;          
		              	break;        
		            }
		            else
		              ++j;        
		            
		     	} 
			}
			
			break;
	}
	return;
}
void tables(unsigned short int randomsum[], unsigned short int i, unsigned short int choice2, unsigned short int choice, unsigned short int &correct, unsigned short int &incorrect, unsigned short int number)
{
	switch(choice) // choice can only be the value 1,2,3,4
		{
			case 1:
				// addition
				cout << "this is the table for addition for " << number << endl;
				for(i=0;i <= 12; i++)
				{																	
					cout << number << " + " << i << " = " << number + i << endl;	//showing users answers before tables
				}
				system ("pause");
				system ("cls");
				if (choice2 == 1)
				{
					for(i=0;i <= 12; i++)
					{
						cout << "what is " << number << " + " << i << "?\n";
						cin >> choice;
						while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> choice;															// tables in order
						}
						if (choice == number + i)
						{
							cout << "correct answer\n";
							correct++;
						}
						else
						{
							cout << "incorrect answer, the correct answer was " << number + i << endl;
							incorrect++;
						}
						system("pause");
						system("cls");
					}
				}
				if (choice2 == 2)
				{
					for(i=0;i <= 12; i++)
					{
						cout << "what is " << number << " + " << randomsum[i] << "?\n";
						cin >> choice;
						while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> choice;
						}																		// tables asked in random order
						
						if (choice == number + randomsum[i])
						{
							cout << "correct answer\n";
							correct++;
						}
						else
						{
							cout << "incorrect answer, the correct answer was " << number + randomsum[i] << endl;
							incorrect++;
						}
						system("pause");
						system("cls");
					}
					
				}
				
				break;
			case 2:
				//subtraction
				cout << "this is the table for subtraction for " << number << endl;
				for(i=number; i<= number+12; i++)
				{
					cout << i << " - " << number << " = " << i - number << endl;
				}
				system ("pause");
				system ("cls");
				if(choice2 == 1)
				{
					for(i=number; i<= number+12; i++)
					{
						cout << "what is " << i << " - " << number << "?\n";
						cin >> choice;
						while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> choice;
						}
						if (choice == i - number)
						{
							cout << "correct answer\n";
							correct++;
						}
						else
						{
							cout << "incorrect answer, the correct answer was " << i - number << endl;
							incorrect++;
						}
						system("pause");
						system("cls");
					}
				}
				if (choice2 == 2)
				{
					for(i=0;i <= 12; i++)
					{
						cout << "what is " << randomsum[i] << " - " << number << "?\n";
						cin >> choice;
						while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> choice;
						}
						if (choice == randomsum[i] - number)
						{
							cout << "correct answer\n";
							correct++;
						}
						else
						{
							cout << "incorrect answer, the correct answer was " << randomsum[i] - number << endl;
							incorrect++;
						}
						system("pause");
						system("cls");
					}
					
				}
				
				break;
			case 3:
				// multiplication
				for(i=0; i <= 12; i++)
				{
					cout << number << " x " << i << " = " << number * i << endl;
				}
				system ("pause");
				system ("cls");
				if(choice2 == 1)
				{
					for(i=0; i <= 12; i++)
					{
						cout << "what is " << i << " x " << number << "?\n";
						cin >> choice;
						while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> choice;
						}
						if (choice == i * number)
						{
							cout << "correct answer\n";
							correct++;
						}
						else
						{
							cout << "incorrect answer, the correct answer was " << number * i << endl;
							incorrect++;
						}
						system("pause");
						system("cls");
					}
				}
				if(choice2 == 2)
				{
					for(i=0;i <= 12; i++)
					{
						cout << "what is " << randomsum[i] << " x " << number << "?\n";
						cin >> choice;
						while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> choice;
						}
						if (choice == randomsum[i] * number)
						{
							cout << "correct answer\n";
							correct++;
						}
						else
						{
							cout << "incorrect answer, the correct answer was " << number * randomsum[i] << endl;
							incorrect++;
						}
						system("pause");
						system("cls");
					}
				}
				
				break;
			case 4:
				// division
				for(i = 0; i <= 12 * number; i += number)
				{
					cout << i << "/" << number << " = " << i/number << endl;
				}
				system ("pause");
				system ("cls");
				if (choice2 == 1)
				{
					for(i = number; i <= 12 * number; i += number)
					{
						cout << "what is " << i << "/" << number << "?\n";
						cin >> choice;
						while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> choice;
						}
						if (choice == i / number)
						{
							cout << "correct answer\n";
							correct++;
						}
						else
						{
							cout << "incorrect answer, the correct answer was " << i/number << endl;
							incorrect++;
						}
						system("pause");
						system("cls");
					}
				}
				if(choice2 == 2)
				{
					for(i=0;i <= 12; i++)
					{
						cout << "what is " << randomsum[i] * number << " divided by " << number << "?\n";
						cin >> choice;
						while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> choice;
						}
						if (choice == (randomsum[i] * number)/number)
						{
							cout << "correct answer\n";
							correct++;
						}
						else
						{
							cout << "incorrect answer, the correct answer was " << randomsum[i] << endl;
							incorrect++;
						}
						system("pause");
						system("cls");
					}
				}
				break;
			default:
				cout << "Invalid option\n";
		}
	return;
}
void results(unsigned short int correct, unsigned short int incorrect)
{
	if (correct == 13)
			cout << "congratulations you got all 13 questions right!!!";
	if (correct < 13 && correct >= 8)
		cout << "congratulations, you got " << correct << " answers correct and only " << incorrect << " answers wrong\n";
	if (correct < 8 && correct >= 5)
		cout << "good effort, you got " << correct << " answers correct and " << incorrect << " answers wrong\n";				// students results
	if(correct < 5)
		cout << "more work needed, you got " << correct << " answers correct and " << incorrect << " answers wrong\n";
		system("pause");
		system("cls");
	return;
}
void randomquiz(questions a[], unsigned short int i, string username,unsigned short int agegroup)
{

	stringstream ss;
	unsigned short int unique = rand() % 999 + 1;
	ss << unique;
	string rnd = ss.str();						// for random number at end of student result file
	short int op1[Numquestions];
	short int arit[Numquestions];
	short int op2;
	short int use;
	short int tru;
	bool cor;
	for(i = 0; i <= Numquestions-1; i++) 
		{
			op1[i] = rand() % 20 + 0;
			if(agegroup < 3)			// making level 3 get the hardest questions
			{
				if(op1[i] > 10)
				{
					i--;			// different levels need different toughness of questions
				}
			}
	    }
	    
	for(i = 0; i <= Numquestions-1; i++) 
		{
			arit[i] = rand() % 4 + 1;
			if(agegroup == 1 && arit[i] > 2)
			{
				i--;
			}
	    }
	
	for(i = 0; i <= Numquestions-1; i++)
	{
		switch (arit[i])
		{ 
			case 1: 
				a[i].arithmetic_operator = '+';			// addition
				if(agegroup < 3)
				{
					op2 = rand() % 10 + 0;
				}
				else
					op2 = rand() % 20 + 0;
				tru = op2+op1[i];
				cout << "what is " << op1[i] << " + " << op2 << "?\n";
				cin >> use;
				while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> use;
						}
				if(tru == use)
					cor = true;
				else
					cor = false;
				system("pause");
				system("cls");
					
				break;
			
			case 2:
				a[i].arithmetic_operator = '-'; 		//subtraction
				if(agegroup < 3)
				{
					op2 = rand() % 10 + op1[i];
				}
				else
					op2 = rand() % 20 + op1[i];
				tru = op2-op1[i];
				cout << "what is " << op2 << " - " << op1[i] << "?\n";
				cin >> use;
				while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> use;
						}
				if(tru == use)
					cor = true;
				else
					cor = false;
				system("pause");
				system("cls");
					
				break;
				
			case 3:
		
				a[i].arithmetic_operator = 'X';			//multiplication
				if(agegroup == 2)
				{
					op2 = rand() % 10 + 0;
				}
				else
					op2 = rand() % 20 + 0;
				tru = op2*op1[i];
				cout << "what is " << op1[i] << " x " << op2 << "?\n";
				cin >> use;
				while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> use;
						}
				if(tru == use)
					cor = true;
				else
					cor = false;
				system("pause");
				system("cls");
				break;
				
			case 4:

				a[i].arithmetic_operator = '/';			//division
				if(agegroup == 2)
				{
					do
				{
					op2 = rand() % (op1[i] * 10) + op1[i];
				}
				while(op2%op1[i] != 0);
				}
				else
				do
				{
					op2 = rand() % (op1[i] * 20) + op1[i];
				}
				while(op2%op1[i] != 0);
				tru = op2/op1[i];
				cout << "what is " << op2 << "/" << op1[i] << "?\n";
				cin >> use;
				while(cin.fail())
						{
							cin.clear();
					  		cin.ignore(80,'\n');		// testing for a non numeric entry
					  		cout << "you entered a letter please enter a numeric answer\n";
							cin >> use;
						}
				if(tru == use)
					cor = true;
				else
					cor = false;
				system("pause");
				system("cls");
			    break;
			    
				default:
					cout << "invalid\n";
					
		}
		a[i].operand1 = op1[i];
		a[i].operand2 = op2;
		a[i].user_ans = use;			//putting values into structure
		a[i].true_ans = tru;
		a[i].correct = cor;
	}
	getdate(); // get file name
	randomquizresults(a,i, username, rnd); // put results in file and give them to user
	
	return;
}
void randomquizresults(questions a[], unsigned short int i, string username, string rnd)
{
	string filename;
	ifstream fin;
	ofstream fout;
	unsigned short int correct1 = 0, incorrect = 0;
	for(i = 0; i <= Numquestions-1; i++)
	{
		if(a[i].correct)
			correct1++;
		else
			incorrect++;
	}
	if(correct1 > (2*Numquestions)/3)
	cout << "congratulations you got " << correct1 << " of the answers right and only " << incorrect << " answers wrong!\n";
	if(correct1 <= (2*Numquestions)/3 && correct1 > Numquestions/3)
	cout << "good attempt you got " << correct1 << " of the answers right and  " << incorrect << " answers wrong\n";		//results
	if(correct1 <= Numquestions/3)
	cout << "you got " << correct1 << " of the answers right and " << incorrect << " answers wrong more work needed\n";
	
	filename = username +"-"+ getdate() + "-" + rnd + ".txt";// file name
	
	fout.open(filename.c_str(), ios::out);	// opening file for inputting results
	if(fout.fail())
	{
		perror("error opening file for reading");
		exit(1);
	}
	for(i=0; i < Numquestions; i++)
	{
		fout << a[i].operand1 << " ";
		fout << a[i].arithmetic_operator << " ";
		fout << a[i].operand2 << " ";
		fout << a[i].user_ans << " ";
		fout << a[i].true_ans << " ";			// putting results in file
		if(a[i].correct == true)
			fout << "correct\n";
		else
			fout << "incorrect\n";
	}
	  fout.close();
	delete []a; //deleting variable form memory
	return;
}

bool login_user(ifstream &fin, string &username,string &password,string &displayname,unsigned short int &lvl,unsigned short int &agegroup)
{
	string user, pass;
	do
	{
	
		cout << "please enter your enter username\n";
		cin >> user;
		cout << "please enter your password\n";
		cin >> pass;
		system("cls");
		transform(pass.begin(),pass.end(),pass.begin(), ::tolower);
		transform(user.begin(),user.end(),user.begin(), ::tolower);		// checking for user and password in users file
		while (!fin.eof())
		{	
			
			
			fin >> displayname >> username >> password >> lvl >> agegroup;
			if(user == username && pass == password)		// if a match
			{
				return true;
				break;
			}
			else if((username != user || password != pass) && fin.eof())		//if not a match
			{
				fin.clear();
				fin.seekg(0);
				cout << "username or password not found\n";
				cout << "please try again\n";
				system("pause");
				system("cls");
				break;
			}				
		}
	}while(username != user || password != pass);


}

string getdate()
{
	
	time_t now;
	char thedate[MAX_TIMESTAMP];
	thedate[0] = '\0';
	now = time(NULL);
	
	if(now != -1)
	{
		strftime(thedate, MAX_TIMESTAMP, "%y%m%d%H%M%S", gmtime(&now));			// getting the date and time for the file name
	}
	return string(thedate);
}

void viewfile(string file)
{

	ifstream fin;
	
	fin.open(file.c_str());
	if(fin.fail())
		perror ("file could not be opened");			// making the results visible for the teacher
	if(fin.is_open())
		cout << fin.rdbuf();
return;
}

void addstudent()
{
	int lvl, agegroup;
	string name, user, passw;
	ofstream fout;
	lvl = 2;
	cout << "what is the firstname of the student\n";
	cin >> name;
	system("pause");
	system("cls");
	cout << "what is the username of the student\n";
	cin >> user;										//adding student to the class
	system("pause");
	system("cls");
	cout << "please enter the students password\n";
	cin >> passw;
	system("pause");
	system("cls");
	do
		{
		
			cout << "please enter the students age group\n";
			cin >> agegroup;
			while(cin.fail())
			{
				cin.clear();
		  		cin.ignore(80,'\n');		// testing for a non numeric entry
		  		cout << "invalid option please enter a number\n";
				cin >> agegroup;
			}
			if(agegroup > 3 || agegroup < 1)
				cout << "please enter agegroup 1,2 or 3\n";
			system("pause");
			system("cls");
		}while(agegroup > 3 || agegroup < 1);
		
		
	fout.open("users.txt", ios::app);
	if(fout.fail())
	{
		perror("error opening file for appending");			// appending student to the file
		exit(1);
	}
	
	fout << name << " " << user << " " << passw << " " << lvl << " " << agegroup << endl; // adding student to the file
	
	fout.close();		// closing file
	
	return;
}
