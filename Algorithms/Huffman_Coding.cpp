#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child
	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq)

	{

		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->freq > r->freq);
	}
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string s)
{

	if (root==NULL)
		return;

	if (root->data != '$')
		cout << root->data << ": " << s << "\n";

	printCodes(root->left, s + "0");
	printCodes(root->right, s + "1");
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> pq;

	for (int i = 0; i < size; ++i)
		pq.push(new MinHeapNode(data[i], freq[i]));

	// Iterate while size of heap doesn't become 1
	while (pq.size() != 1) {

		// Extract the two minimum
		// freq items from min heap
		left = pq.top();
		pq.pop();

		right = pq.top();
		pq.pop();

		/*Create a new internal node with
		 frequency equal to the sum of the
		 two nodes frequencies. Make the
		 two extracted node as left and right children
		 of this new node. Add this node
		to the min heap '$' is a special value for internal nodes, not used */
		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		pq.push(top);
	}

	printCodes(pq.top(), "");
}

int main()
{

	char a[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(a) / sizeof(a[0]);

	HuffmanCodes(a, freq, size);

	return 0;
}
