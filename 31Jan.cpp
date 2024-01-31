/*
Problem --> Insert and Search in a Trie
Complete the Insert and Search functions for a Trie Data Structure. 

Insert: Accepts the Trie's root and a string, modifies the root in-place, and returns nothing.
Search: Takes the Trie's root and a string, returns true if the string is in the Trie, otherwise false.
Note: To test the correctness of your code, the code-judge will be inserting a list of N strings called into the Trie, and then will search for the string key in the Trie. The code-judge will generate 1 if the key is present in the Trie, else 0.

Example 1:

Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = the
Output: 1
Explanation: 
"the" is present in the given set of strings. 
Example 2:

Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = geeks
Output: 0
Explanation: 
"geeks" is not present in the
given set of strings.
Your Task:
You do not have to take any input or print anything. Complete insert and search functions. 

Expected Time Complexity: O(M+|key|)
Expected Auxiliary Space: O(M)
Here M = sum of the length of all strings which are present in the list[] 

Constraints:
1 <= N <= 104
1 <= length of list[i] <= 30
All strings will constitute of lowercase alphabets only.

*/

class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
        
            TrieNode* head = root;
            int i = 0;
            while(i < key.size()) {
                int index = key[i++]-'a';
                if(head->children[index]) {
                    head = head->children[index];
                }
                else {
                    TrieNode* sub = new TrieNode();
                    head->children[index] = sub;
                    // head->isLeaf = false;
                    head = sub;
                }
            }
            
            head->isLeaf = true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            TrieNode* head = root;
            int i = 0;
            while( i < key.size()) {
                int index = key[i++]-'a';
                if(head->children[index]) {
                    head = head->children[index];
                }
                else return false;
            }
            
            if(i == key.size() && head->isLeaf) return true;
            
            return false;
        }
};
