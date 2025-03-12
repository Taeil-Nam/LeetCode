/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* newNode = &dummy;
        Node* node = head;
        while (node){
            newNode->next = new Node(node->val);
            newNode = newNode->next;
            node = node->next;
        }

        vector<Node*> v;
        unordered_map<Node*, int> um;
        int i = 0;
        node = head;
        newNode = dummy.next;
        while (node){
            v.push_back(newNode);
            um[node] = i;
            i++;
            newNode = newNode->next;
            node = node->next;
        }

        node = head;
        newNode = dummy.next;
        while (node){
            if (node->random)
                newNode->random = v[um[node->random]];
            else
                newNode->random = nullptr;
            newNode = newNode->next;
            node = node->next;
        }
        return dummy.next;
    }
};