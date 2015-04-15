/*
*	Simple program for testing use of the Windows Clipboard functionality. 
*/

#include <iostream>
#include <sstream>

#include "Clipboard.h"

using std::cin;
using std::cout;
using std::string;

int main()
{
	int waitForUser;
	string str;
	Clipboard clipboard;

	cout << "Enter a string to be copied to the clipboard:";
	getline(cin, str);
	clipboard.copy_to_clipboard(str);

	cin >> waitForUser;
	return 0;
}