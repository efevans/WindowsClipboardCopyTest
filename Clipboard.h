/*
* Interface for dealing with the Windows Clipboard
*/

#pragma once

class Clipboard
{
public:
	Clipboard();
	~Clipboard();

	// copies the contents of str to the clipboard
	void copy_to_clipboard(std::string &str);
};

