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
        unordered_map<Node*, int> um1;
        unordered_map<int, Node*> um2;
        Node dummy(0);
        Node* node = &dummy;
        Node* curr = head;
        int idx = 0;
        while (curr){
            node->next = new Node(curr->val);
            node = node->next;
            um1[curr] = idx;
            um2[idx] = node;
            curr = curr->next;
            idx++;
        }
        node = dummy.next;
        curr = head;
        while (curr){
            if (curr->random){
                node->random = um2[um1[curr->random]];
            }
            curr = curr->next;
            node = node->next;
        }
        return dummy.next;
    }
};
