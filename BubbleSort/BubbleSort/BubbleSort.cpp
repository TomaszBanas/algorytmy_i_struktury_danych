// BubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Node
{
	public:
		int Val;
		Node* Next;
};

void PrintList(Node* H)
{
	Node* p = H;
	cout << " H => ";
	while (p != NULL)
	{
		cout << p->Val << " => ";
		p = p->Next;
	}
	cout << " NULL" << endl;
}

void Add(Node*& H, int val)
{
	Node* p = new Node;
	p->Val = val;
	p->Next = H;
	H = p;
}

void AddSorted(Node*& H, int val)
{
	if (H == NULL || H->Val > val)
	{
		Node* p = new Node;
		p->Val = val;
		p->Next = H;
		H = p;
	}
	else
	{
		Node* p = H;
		while(p != NULL && p->Next != NULL && p->Next->Val < val)
		{
			p = p->Next;
		}
		Node* q = new Node;
		q->Val = val;
		q->Next = p->Next;
		p->Next = q;
	}	
}

void Swap(Node*& H)
{
	if (H->Next != NULL)
	{
		int tmp = H->Val;
		H->Val = H->Next->Val;
		H->Next->Val = tmp;
	}
	//Node* p = H->Next;
	//H->Next = p->Next;
	//p->Next = H;
	//H = p;
}

void BubbleSort(Node*& H)
{
	Node* lastSwap = NULL;
	Node* p = H;
	Node* tmpLastSwap = p;
	while (tmpLastSwap != lastSwap)
	{
		if (p == lastSwap)
		{
			p = H;
			lastSwap = tmpLastSwap;
			tmpLastSwap = p;
			continue;
		}
		if (p->Next != NULL && p->Val > p->Next->Val)
		{
			Swap(p);
			tmpLastSwap = p->Next;
		}
		p = p->Next;
	}
}

int main()
{
	//int* arr = new int[] {6, 4, 3, 7, 8, 4, 3, 7, 3, 4, 8, 9};
	int* arr = new int[] {8, 4, 5, 9, 1};
	Node* H = NULL;
	/*for (int i = 0; i < 12; i++)
	{
		Add(H, arr[i]);
	}*/
	/*Add(H, 1);
	Add(H, 9);
	Add(H, 5);
	Add(H, 4);
	Add(H, 8);*/

	AddSorted(H, 1);
	AddSorted(H, 9);
	AddSorted(H, 5);
	AddSorted(H, 4);
	AddSorted(H, 8);
	
	PrintList(H);
	//BubbleSort(H);
	//PrintList(H);
	/*
	BubbleSort(arr, 12);
	Print(arr, 12);*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
