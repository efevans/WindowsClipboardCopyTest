#pragma once

class Clipboard
{
public:
	Clipboard();
	~Clipboard();
	void copy_to_clipboard(std::string &str);
};

