//James Cole & Isaac Sipma
//December 02, 2025
//Password strength checker, it checks your password and checks it on 
//different criteria to see if its a good password or whether you should chnage
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

string checkstrength(string password){
	int length = password.length();

	bool haslower = false;
	bool hasupper = false;
	bool hasdigit = false;
	bool hasspecial = false;

	for(char c : password){
		if(islower(c)){
			haslower = true;
		} else if(isupper(c)){
			hasupper = true;
		} else if(isdigit(c)){
			hasdigit = true;
		} else if(ispunct(c)){
			hasspecial = true;
		}
		
	}

	if(length >= 8 && haslower && hasupper && hasdigit && hasspecial){
		return "Strong";
	}else if(length >= 6 && (haslower||hasupper) && (hasdigit||hasspecial)){
		return "Moderate";
	}else{
		return "Weak";
	}
}

int main() {
	string password;
	vector<string> strongpasswords;

	char choice = 'y';

	cout<<"Welcome to the password strength checker(nothing else)"<< endl;
	while(choice == 'y'){
		cout<< "enter a password to check its strength: ";
		cin >> password;

		string strength = checkstrength(password);
		cout<< "Your passowrd strength is: "<<strength<<"!" << endl;

		if(strength == "Strong"){
			strongpasswords.push_back(password);
			cout << "Wow thats a great password I might use that!" << endl;
		}
		cout<< "continue checking passwords? (y/n)"<< endl;
		cin >> choice;	
	}
	cout << "Here are all the strong passwords I didnt steal" << endl;
	for(string stolenpass : strongpasswords){
		cout << stolenpass << endl;
	}
			
	return 0;
}
