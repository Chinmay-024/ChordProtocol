#include "Chord.h"
#include <bits/stdc++.h>

int main()
{
	vector<int> mSet(pow(2, mVal), 0);
	cout << "Enter the value of m where 2^m-1 is max value for a node or key and note all node index should be unique: ";
	cin >> mVal;
	cout << "Enter the number of nodes you want to insert in the network: ";
	int n;
	cin >> n;
	if (n > pow(2, mVal))
	{
		cout << "\033[31m"
			 << "WRONG INPUT\n"
			 << "\033[0m";
		return 0;
	}
	vector<Node *> nodes;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter node value : ";
		int a;
		cin >> a;
		if (a >= pow(2, mVal))
		{
			cout << "\033[31m"
				 << "WRONG INPUT\n"
				 << "\033[0m";
			return 0;
		}
		if (mSet[a] == 1)
		{
			cout << "\033[31m"
				 << "Index not unique\n"
				 << "\033[0m";
			return 0;
		}
		mSet[a] = 1;

		nodes.push_back(new Node(a));
	}

	// n0 join
	nodes[0]->join(NULL);
	for (int i = 1; i < n; i++)
	{
		nodes[i]->join(nodes[i - 1]);
	}

	cout << "Enter the number of keys to insert : ";
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << "Enter key value : ";
		int a;
		cin >> a;
		nodes[0]->insert_key(a, a);
	}
	cout << "\n\n";
	for (int z = 0; z < 2; z++)
	{
		for (int i = 0; i < n; i++)
		{
			nodes[i]->stabilize();
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "\n**** Pred ID : " << nodes[i]->predecessor->id << " ****";
		nodes[i]->fingertable->printFingerTable(nodes[i]->predecessor->id);
		cout << "\n\n";
	}

	std::ofstream outputFile("FingerTable.txt");

	// Redirect the cout stream to the output file stream
	std::streambuf *originalCoutStream = std::cout.rdbuf();
	std::cout.rdbuf(outputFile.rdbuf());

	for (int i = 0; i < n; i++)
	{
		cout << "\n**** Pred ID : " << nodes[i]->predecessor->id << " ****";
		nodes[i]->fingertable->printFingerTable(nodes[i]->predecessor->id);
		cout << "\n\n";
	}

	// Restore the original cout stream
	std::cout.rdbuf(originalCoutStream);

	// Close the output file
	outputFile.close();

	// keys being searched for, locally on them
	cout << "Enter number of keys to be searched : ";
	int nk;
	cin >> nk;
	for (int i = 0; i < nk; i++)
	{
		cout << "Enter key value to be searched : ";
		int a;
		cin >> a;
		nodes[0]->find_key(a);
	}

	if (nodes.size() == 1)
	{
		cout << "You cant remove more nodes only 1 rem";
		return 0;
	}
	cout << "Enter node to be removed : ";

	fflush(stdin);
	fflush(stdout);
	cin >> nk;
	int flag = 0;
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i]->id == nk)
		{
			flag = 1;
			nodes[i]->remove(nodes, i);
		}
	}
	if (!flag)
		cout << "No such node exist \n";
	if (nodes.size() > 1)
	{
		for (int z = 0; z < 2; z++)
		{
			for (int i = 0; i < nodes.size(); i++)
			{
				nodes[i]->stabilize();
			}
		}
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << "\n**** Pred ID : " << nodes[i]->predecessor->id << " ****";
		nodes[i]->fingertable->printFingerTable(nodes[i]->predecessor->id);
		cout << "\n\n";
	}

	return 0;
}
