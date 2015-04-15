#include <Windows.h>
#include <iostream>

#include "Clipboard.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

Clipboard::Clipboard()
{
}


Clipboard::~Clipboard()
{
}

void Clipboard::copy_to_clipboard(string &str)
{
	HWND handle = GetConsoleWindow();
	if (!OpenClipboard(handle))
	{
		cerr << "Clipboard failed to open" << endl;
	}
	else // opened clipboard
	{
		cout << "opened the clipboard!" << endl;

		if (!EmptyClipboard())
		{
			cerr << "Failed to empty clipboard" << endl;
		}
		else // emptied clipboard contents, clipboard should be ready to use
		{
			cout << "successfully emptied clipboard" << endl;

			HGLOBAL text = GlobalAlloc(GMEM_MOVEABLE, str.size() + 1);
			if (!text)
			{
				cerr << "global memory allocation failed" << endl;
			}
			else // allocated global memory for copying to clipboard
			{
				cout << "successfully allocated global memory for string" << endl;

				memcpy(GlobalLock(text), str.c_str(), str.size() + 1);
				GlobalUnlock(text);
				if (!SetClipboardData(CF_TEXT, text))
				{
					cerr << "failed to set clipboard data" << endl;
				}
				else // copied contents to clipboard
				{
					cout << "successfully set clipboard data" << endl;
				}
				GlobalFree(text);
			}
		}

		if (!CloseClipboard())
		{
			cerr << "failed to close clipboard" << endl;
		}
		else
		{
			cout << "successfully closed clipbaord after opening" << endl;
		}
	}
}