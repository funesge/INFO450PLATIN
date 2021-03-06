// PigLatin.cpp : Defines the entry point for the console application.
//
//#define _CRT_SECURE_NO_WARNINGS was added to "stdafx.h" to avoid error.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

void translateToPigLatin(char wrd[50]);
bool checkForConjunction(char wrd[50]);

int main()
{
	char answer;
	// do while loop wraps code to run again if user wishes.
	do {
		char word[50];

		cout << "This program takes a user inputed word "
			"and translates it into pig latin." << endl;
		cout << "Words must be less than 50 characters" << endl;

		//checks input for correct length and correct input
		do
		{
			cout << "Please enter a word to translate to Pig Latin: ";
			cin.getline(word, 50);
			cout << endl;

			//if first character is not a number, or no blanks are 
			//found and word < 51 char translateToPigLatin function runs
			if (!isdigit(word[0]) && strlen(word)>0 && strlen(word)<51)
			{
				translateToPigLatin(word);
				break;
			}
			else
				cout << "Your word cannot be blank, begin with a number,"
				"or be longer than 50 characters!" << endl;
				cout << "To try again enter Y/y: ";
				cin >> answer;
				cin.ignore(); //If not included in code uses blank for next translation
				cout << endl;

		}while(answer == 'Y' || answer == 'y');

		cout << "Do you want to translate another word? (Y/y for yes): ";
		cin >> answer;
		cin.ignore(); //If not included in code uses blank for next translation
		cout << endl;

	} while (answer == 'Y' || answer == 'y');
	return 0;
}

//function translates word into pig latin
// wrd is short for word
void translateToPigLatin(char wrd[50])
{
	int uppercaseVowels, lowercaseVowels;
	

	uppercaseVowels = (wrd[0] == 'A' || wrd[0] == 'E' || wrd[0] == 'I' ||
		wrd[0] == 'O' || wrd[0] == 'U');

	lowercaseVowels= (wrd[0] == 'a' || wrd[0] == 'e' || wrd[0] == 'i' ||
		wrd[0] == 'o' || wrd[0] == 'u');

	// Checks word for vowels and translates vowel words and consonant words
	if (checkForConjunction(wrd) == false)
	{
		//if word is less than 3 characters remains same
		if (strlen(wrd) < 3)
		{
			cout << wrd << " translated into pig latin is: " << wrd << endl;
		}
		//checks for vowels
		else if (uppercaseVowels || lowercaseVowels)
		{
			cout << wrd << " translated into pig latin is: " << wrd << "ay" << endl;
		}
		else
			//when not vowel means its a consonant so 
			//moves first letter to end and adds ay
		{
			cout << wrd;
			char temp = wrd[0];
			int i;

			for (i = 0; i < 50 - 1 && wrd[i + 1] != 0; i++)
			{
				wrd[i] = wrd[i + 1];
			}
			wrd[i] = temp;
			cout << " translated into pig latin is: " << wrd << "ay" << endl;
			
		}
	}
	else
		cout << wrd << " translated into pig latin is: " << wrd << endl;
}

//Function checks if word is a conjunction or article
bool checkForConjunction(char wrd[50])
{
	if(!strcmp(wrd, "the"))
	{
		return true;
	}
	if(!strcmp(wrd, "a"))
	{
		return true;
	}
	if(!strcmp(wrd, "an"))
	{
		return true;
	}
	if (!strcmp(wrd, "and"))
	{
		return true;
	}
	if (!strcmp(wrd, "but"))
	{
		return true;
	}
	if (!strcmp(wrd, "for"))
	{
		return true;
	}
	if (!strcmp(wrd, "nor"))
	{
		return true;
	}
	if(!strcmp(wrd, "so"))
	{
		return true;
	}
	if (!strcmp(wrd, "yet"))
	{
		return true;
	}
	if(!strcmp(wrd, "or"))
	{
		return true;
	}
	else
		return false;
}