// Raul Martinez
// raul.martinez01@utrgv.edu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class THING>
class minHeap
{
public:
	void insert(THING x);
	THING extractMin();
	void display();
	bool empty();

private:
	vector<THING> items;

	void bubbleUp(int i);
	void bubbleDown(int i);
	int parent(int i);
	int lChild(int i);
	int rChild(int i);
};

template <class THING>
void minHeap<THING>::bubbleUp(int i)
{
	if (i == 0)
	{
		return;
	}
	if (items[parent(i)] > items[i])
	{
		swap(items[i], items[parent(i)]);
		bubbleUp(parent(i));
	}
}

template <class THING>
void minHeap<THING>::bubbleDown(int i)
{
	if (lChild(i) >= items.size())
	{
		return;
	}

	int minI = i;

	if (items[i] > items[lChild(i)])
	{
		minI = lChild(i);

		if (minI != i)
		{
			swap(items[i], items[minI]);
			bubbleDown(minI);
		}
	}
	else if (rChild(i) < items.size() && items[minI] > items[rChild(i)])
	{
		minI = rChild(i);

		if (minI != i)
		{
			swap(items[i], items[minI]);
			bubbleDown(minI);
		}
	}
}

template <class THING>
int minHeap<THING>::parent(int i)
{
	return (i - 1) / 2;
}

template <class THING>
int minHeap<THING>::lChild(int i)
{
	return i + (i + 1);
}

template <class THING>
int minHeap<THING>::rChild(int i)
{
	return i + (i + 2);
}

template <class THING>
void minHeap<THING>::insert(THING x)
{
	items.push_back(x);
	bubbleUp(items.size() - 1);
	
}

template <class THING>
THING minHeap<THING>::extractMin()
{
	THING val = items[0];

	if (items.empty())
	{
		return 0;
	}
	else if (items.size() == 1)
	{
		items.pop_back();
		return val;
	}
	else
	{
		swap(items[items.size() - 1], items[0]);
		items.pop_back();
		bubbleDown(0);
		return val;
	}
}

template <class THING>
void minHeap<THING>::display()
{
	for (int i = 0; i < items.size(); i++)
		cout << "Index: " << i << ": " << items[i] << endl;
}

template <class THING>
bool minHeap<THING>::empty()
{
	if (items.size() == 0)
	{
		return true;
	}
	return false;
}