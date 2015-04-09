#include "DialogueTree.h"

DialogueNode::DialogueNode(string Text)
{
	text = Text;
}

DialogueOption::DialogueOption(string Text, int ReturnCode, DialogueNode *NextNode)
{
	text = Text;
	returnCode = ReturnCode;
	nextNode = NextNode;
}


// Constructor
DialogueTree::DialogueTree()
{
	for (size_t i = 0; i < dialogueNodes.size(); i++){
		delete dialogueNodes[i];
	}
	dialogueNodes.clear();
}

// Sets up tree
void DialogueTree::init()
{
	DialogueNode * node0 = new DialogueNode("Hello brave warrior! ");
	DialogueNode * node1 = new DialogueNode("I don't want to talk to you ");
	DialogueNode * node2 = new DialogueNode("I have a quest for you! ");
	DialogueNode * node3 = new DialogueNode("You will get 5 gold you Greedy S! ");
	DialogueNode * node4 = new DialogueNode("Collect 10 Dandellions! ");

	// Node 0
	node0->dialogueOptions.push_back(DialogueOption("Herp O.o ", 0, node1));
	node0->dialogueOptions.push_back(DialogueOption("Hello Strange Voice...", 0, node2));
	dialogueNodes.push_back(node0);

	// Node 1
	node1->dialogueOptions.push_back(DialogueOption("Hmmmm..... ", 0, nullptr));
	dialogueNodes.push_back(node1);

	// Node 2
	node2->dialogueOptions.push_back(DialogueOption("K Bye. ", 0, nullptr));
	node2->dialogueOptions.push_back(DialogueOption("What is it? ", 0, node4));
	node2->dialogueOptions.push_back(DialogueOption("What's the pay? ", 0, node3));
	dialogueNodes.push_back(node2);

	// Node 3
	node3->dialogueOptions.push_back(DialogueOption("Ok, What is it? ", 0, node4));
	node3->dialogueOptions.push_back(DialogueOption("That sucks... I'm out... ", 0, nullptr));
	dialogueNodes.push_back(node3);

	// Node 4
	node4->dialogueOptions.push_back(DialogueOption("Let's do it! ", 1, nullptr));
	node4->dialogueOptions.push_back(DialogueOption("No way! ", 0, nullptr));
	dialogueNodes.push_back(node4);
}

void DialogueTree::destroyTree()
{
	for (size_t i = 0; i < dialogueNodes.size(); i++){
		delete dialogueNodes[i];
	}
	dialogueNodes.clear();
}

// Does the actual conversation and returns the outcome

int	DialogueTree::performDialogue()
{
	if (dialogueNodes.empty()) {
		return -1;
	}

	DialogueNode *currentNode = dialogueNodes[0];

	while (true) {
		cout << currentNode->text << "\n\n";

		for (size_t i = 0; i < currentNode->dialogueOptions.size; i++) {
			cout << i + 1 << ": " << currentNode->dialogueOptions[i].text << endl;
		}
		cout << endl;
		int input;
		cin >> input;
		input--;

		if (input < 0 || input > currentNode->dialogueOptions.size()){
			cout << "Invalid input!\n";
		}
		else{
			// Check for end of conversation
			if (currentNode->dialogueOptions[input].nextNode == nullptr){
				return currentNode->dialogueOptions[input].returnCode;
			}
			currentNode = currentNode->dialogueOptions[input].nextNode;
			cout << endl;

		}

	}
}
