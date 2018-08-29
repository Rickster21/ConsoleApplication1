/**************************
Ricky J. Solorio
07/13/17
LinkedList Merge Sort

algorythems you need for Merge Sort: 
splitList, mergeList, and mergeSort                 that is all! :)

This is an implementation of Merge Sort using linked list for C++. 


****************************/

#include <iostream>
#include <string>
using namespace std;



struct node {

	int info;
	node *link;

};
void makeLinkedList(node **head, int value)     // this make the linked lists making the nodes in the order you input.
{           					// so the last input will stay in the front and build the list as so
	
	node *newNode = new node;
	newNode->info = value;
	newNode->link = *head;
	*head = newNode;

}
int EnterListSize() { 			//this is a method I made to use in another method to make my code more consice.
	int listSize;
	cout << "Enter list size: ";
	cin >> listSize;

	return listSize;

}
void  splitLinkedList(node *head, node** front , node** back) // the front and back are not used be
{
	node *fast, *slow;

	if (head == NULL && head->link == NULL)
	{
		*front = head;
		*back = NULL;

	}

		slow = head;
		fast = head->link;

		while (fast != NULL) {
			fast = fast->link;
			if (fast != NULL)
			{
				slow = slow->link;
				fast = fast->link;


			}

		}

			*front = head;
			*back = slow->link;
			slow->link = NULL;	
	
};
void printLinkedList(node *head)
{
	node *current;
	current = head;
	while (current != NULL)
	{
		cout << current->info;
		current = current->link;

    }


	cout << endl;
	
}
node* merge(node *front, node *back) {  // NOTE: this merge will only work for sorted list not unsorted

	node* head, *f = front, *b = back, *s = NULL;  // 's' will only point to the beginning of one of the sorted list once because
	                                               // since both list are orderd both will have their lowest value
	                                               // at the beginning. The s->link will snake through (point) the rest of the list.
												   // Youtube explination of merge code below: https://youtu.be/j_UNYW6Ap0k
    
	
	if (front != NULL && back != NULL) 

		if (b->info < f->info){                     // 'b' stands for back & 'f' for front
			s = b;
			b = s->link;

		}
		else {
			s = f;
			f = s->link;
		};

		head = s;

		while(b!= NULL && f!= NULL)
		{
			if (b->info <= f->info)
			{
				s->link = b;
				s = b;
				b = s->link;
			}
			else
			{
				s->link = f;
				s = f;
				f = s->link;
			}
		}
		if (b == NULL)
		{
			s->link = f;

		}
		if (f == NULL){

			s->link = b;
		}

		return head;


}
void MergeSort(node ** MSHead) {

	node * head = *MSHead;                    // head points to the original list to be mergesorted
	node *front = NULL, *back = NULL;         // front and back are made so the split function can split the return values of front/back

	if (head == NULL || head->link == NULL) {

		return;
	}

	splitLinkedList(head, &front, &back);
	MergeSort(&front);
	MergeSort(&back);
	*MSHead = merge(front, back);

}

int main()
{
	node *List = NULL;     // initiates the Linkedlist to be created
	int  numbs;            // numbs is a variable to insert values into linkedlist with makeLinkedlist function
 
	
	int  size = EnterListSize();  // fucntion to make code a little cleaner it returns user input for size of linkedlist
	int count = size; 

	cout << "Enter " << size << " numbers: \n";
	cout << endl << endl;


	for(int i = 0; i < size; i++)   // forloop to create the linkedlist with user input using numbs variable
	{
		
		cout << count << ": ";
		cin >> numbs;
		makeLinkedList(&List, numbs);
		count--;
		
	};
	cout << endl << endl;

	MergeSort(&List);           // mergesorts the list
	printLinkedList(List);    // prints the reslut of the mergesorted linkedlist! :)

  
	
	return 0;
};


	



