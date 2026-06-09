#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

// Node structure for the Huffman tree
struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Function to generate Huffman codes
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If it's a leaf node, store the code
    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman tree and generate codes
unordered_map<char, string> buildHuffmanTree(const string& input) {
    // Step 1: Count the frequency of each character
    unordered_map<char, int> frequency;
    for (char c : input) {
        frequency[c]++;
    }

    // Step 2: Create a priority queue (min-heap)
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto& pair : frequency) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Step 3: Build the Huffman tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* merged = new HuffmanNode('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    // Step 4: Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(pq.top(), "", huffmanCodes);

    return huffmanCodes;
}

// Function to encode the input string using Huffman codes
string encode(const string& input, const unordered_map<char, string>& huffmanCodes) {
    string encodedString;
    for (char c : input) {
        encodedString += huffmanCodes.at(c);
    }
    return encodedString;
}

int main() {
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    // Build Huffman tree and generate codes
    unordered_map<char, string> huffmanCodes = buildHuffmanTree(input);

    // Output the Huffman codes
    cout << "Huffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Encode the input string
    string encodedString = encode(input, huffmanCodes);
    cout << "Encoded String: " << encodedString << "\n";

    return 0;
}