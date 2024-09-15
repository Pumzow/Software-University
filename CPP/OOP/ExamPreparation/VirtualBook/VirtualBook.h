#ifndef VIRTUALBOOK_H
#define VIRTUALBOOK_H

#include "VirtualPage.h"
#include <vector>

using namespace std;

class VirtualBook
{
private:
	vector<VirtualPage> pages;
public:
	void addPage(VirtualPage page)
	{
		pages.push_back(page);
	}
	void printContent()
	{
		if (pages.size() <= 0) return;
		for (VirtualPage page : pages) {
			page.printContent();
		}
	}
	void removeLastPage()
	{
		if (pages.size() <= 0) return;
		pages.pop_back();
	}
	void removeAllPages()
	{
		if (pages.size() <= 0) return;
		pages.clear();
	}
};

#endif // VIRTUALBOOK_H