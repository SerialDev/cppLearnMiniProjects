#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

#include "DialogueTree.h"

using namespace std;

int main()
{
	DialogueTree dialogueTree;
	
	dialogueTree.init();
	int rv = dialogueTree.performDialogue();

	if (rv == 1) {
		cout << "\n You accepted your quest! Till you return brave warrior!\n"; 
	}

	dialogueTree.destroyTree();

	cout << "Enter any key to continue....\n";
	char tmp;
	cin >> tmp;
	return 0;
}