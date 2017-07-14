/**************************
Ricky J. Solorio
07/13/17
LinkedList Merge Sort

algorythems you need for Merge Sort: 
splitList, mergeList, qnd mergeSort                 that is all! :)


MergeSort is a recurssion function that takes one LinkList as its paramater. The base case checks
if the length of the Linkedlist is less than one. When the list is greater than one it gets split into two list; a Left and a Right list. 
Both Right and Left lists get inserted into their own MergeSort Function. The original Leftlist will have to reach its base case 
with its sub left and right sides until they all reach meet the 
in its mergeSort before the original right can begin its mergeSort.


****************************/

#include <iostream>
#include <string>
using namespace std;
//yolo17
// this is a implementation of Merge Sort using linked list. Starting of with SplitList
// which is apart of the Mergesort body code

struct node {

	int info;
	node *link;

};

void makeLinkedList(node **head, int value)
{
	
	node *newNode = new node;
	newNode->info = value;
	newNode->link = *head;
	*head = newNode;



}

void  splitList(node *list)
{
	node *fast, *slow, *front, *back;
	slow = list;
	fast = list; // slow and fast point to the list

	fast = fast->link;

	if(fast->link != NULL)
	{
		fast = fast->link;
		while (fast->link != NULL)
		{
			fast = fast->link;
			slow = slow->link;


		}

		back = fast;
		slow->link = NULL;
		front = list;

	}
};

void printN(node *head)
{
	node *current;
	current = head;
	while (current != NULL)
	{
		cout << current->info;
		current = current->link;

    }


	
}

int main()
{
	node *List = NULL;
	int listSize, numbs;
	char answer;

    cout << "Enter list size: ";
	cin >> listSize;

	for (int i = 0; i < listSize; i++)   // lets the user create the list size and data
	{
		cout << "Enter any number you want and I will split them for you..";
		cin >> numbs;
		makeLinkedList(&List, numbs);

	};

	cout << "Here is the list before I split it: ";
	printN(List);
	
	cout << "/n Do you want to go tru and split your list? Y/N /n";
	cin >> answer;
	if (answer == 'Y' || 'y')
	{
		cout << "/n/nHere is your front have you list: ";
		splitList(List);
		printN(List);
	}
	else 
		cout << "what ever then.. :)";


return 0;
};
