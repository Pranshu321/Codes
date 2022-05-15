#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct node
{
	node *next[ALPHABET_SIZE];
	bool end;
};

// Returns new trie node (initialized to NULLs)
node *getNode()
{
	node *t = new node;

	t->end = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		t->next[i] = NULL;

	return t;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(node *root, string key)
{
	node *it = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!it->next[index])
			it->next[index] = getNode();

		it = it->next[index];
	}

	// mark last node as leaf
	it->end = true;
}

// Returns true if key presents in trie, else
// false
bool search(node *root, string key)
{
	node *it = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!it->next[index])
			return false;

		it = it->next[index];
	}

	return (it->end);
}

// Driver
int main()
{
	// Input keys (use only 'a' through 'z'
	// and lower case)
	string keys[] = {"pranshu", "rashmi", "simran"};

	node *root = getNode();

	// Construct trie
	for (auto i : keys)
		insert(root, i);

	// Search for different keys
	search(root, "the") ? cout << "the present \n" : cout << "The letter [The] is Not present \n";
	search(root, "simran") ? cout << "The letter [simran]  is present \n" : cout << "The letter [simran]  is not present \n";
	return 0;
}
