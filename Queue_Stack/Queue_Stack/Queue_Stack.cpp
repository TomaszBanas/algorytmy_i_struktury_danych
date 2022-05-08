#include <iostream>

using namespace std;

class Node
{
    public: 
		int Value;
		Node* Next;
};

class Queue
{
	private:
		Node* Front = NULL;
		Node* Rear = NULL;
	public:		
		bool IsEmpty()
		{
			return Front == NULL;
		}

		void Enqueue(int val)
		{
			Node* NewNode = new Node;
			NewNode->Value = val;
			NewNode->Next = NULL;
			if (IsEmpty())
			{
				Front = NewNode;
				Rear = NewNode;
			}
			else
			{
				Rear->Next = NewNode;
				Rear = NewNode;
			}
		}

		int Dequeue()
		{
			if (IsEmpty())
			{
				return NULL;
			}

			int val = Front->Value;
			Front = Front->Next;
			return val;
		}

		int FrontValue()
		{
			if (IsEmpty())
			{
				return NULL;
			}
			return Front->Value;
		}

		void PrintQueue()
		{
			Node* temp = Front;
			while (temp != NULL)
			{
				cout << temp->Value << " ";
				temp = temp->Next;
			}
		}
};


int main()
{
    cout << "Start!\n";
	cout << endl << "---------------------------------" << endl;
	Queue* q = new Queue;
	q->Enqueue(1);
	q->Enqueue(2);
	q->Enqueue(3);
	q->PrintQueue();
	int de = q->Dequeue();
	
	cout << endl << "---------------------------------" << endl;
	cout << de;
	cout << endl << "---------------------------------" << endl;
	q->PrintQueue();
	cout << endl << "---------------------------------" << endl;
    cout << "End!\n";
}