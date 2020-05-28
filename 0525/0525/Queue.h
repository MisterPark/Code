#pragma once

// rear로 들어가서 front로 뱉을거임.

template<class T>
class Queue
{
public:
	struct Node
	{
		Node* next = nullptr;
		Node* prev = nullptr;
		T data;
	};

	Queue()
	{
		front = new Node;
		rear = new Node;
		front->next = rear;
		rear->prev = front;
	}
	~Queue()
	{
		Clear();
		delete front;
		delete rear;
	}

	void Enqueue(T data)
	{
		Node* node = new Node;
		node->data = data;

		Node* back = rear->prev;

		back->next = node;
		node->prev = back;

		node->next = rear;
		rear->prev = node;
	}
	bool Dequeue(T* outData = nullptr)
	{
		if (IsEmpty()) return false;

		Node* node = front->next;

		Node* begin = node->next;

		front->next = begin;
		begin->prev = front;

		if (outData != nullptr)
		{
			*outData = node->data;
		}

		delete node;

		return true;
	}
	bool IsEmpty()
	{
		return (front->next == rear);
	}
	void Clear()
	{
		while (!IsEmpty())
		{
			Dequeue();
		}
	}

private:
	Node* front = nullptr;
	Node* rear = nullptr;
};

