#include <iostream>
#include <queue>
#include <exception>

using namespace std;

struct EmptyStack : public exception{
	const char * what () const throw () {
		return "Empty Stack!";
	}
};

class queueStack
{
	private:
	queue<int> qOne;
	queue<int> qTwo;
	int size=0;
	public:
	queueStack():{};
	void push(const int elem)
	{
		if(this->isEmpty())
		{
			qOne.push(elem);
			size++;
		}
		else if(!this->isEmpty())
		{
			if(qOne.empty())
			{
				qOne.push(elem);
				size++;
				changeQueueContents(qTwo,qOne);
			}
			else if(qTwo.empty())
			{
				qTwo.push(elem);
				size++;
				changeQueueContents(qOne,qTwo);
			}
		}
	}
	void changeQueueContents(queue<int>& qA, queue<int>& qB)//move contents of qB into queue qA
	{
		while(!qB.empty())
		{
			qA.push(qB.front());
			qB.pop();
		}
	}
	int pop()
	{
		if(qOne.empty())
		{
			qTwo.pop();
			size--;
		}
		else if(qTwo.empty())
		{
			qOne.pop();
			size--;
		}
	}
	bool isEmpty()
	{
		return qOne.empty() & qTwo.empty();
	}
	int top()
	{
		if(this->isEmpty())
		{
			throw EmptyStack();
		}
		else if(qOne.empty())
		{
			return qTwo.front();
		}
		else if(qTwo.empty())
		{
			return qOne.front();
		}
	}
	int size() const {return size;}
	void printStack()
	{
		if(qOne.empty())
		{
			for(int i=0;i<qTwo.size();i++)
				cout<<qTwo.front()<<endl;
		}
	}
};

int main()
{
	queueStack stack1;
	for(int i=0; i<10;i++)
	{
		stack1.push(i);
	}



	return 0;
}