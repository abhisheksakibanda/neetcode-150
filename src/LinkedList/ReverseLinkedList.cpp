// 206. Reverse Linked List (https://leetcode.com/problems/reverse-linked-list)

#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"
#include "../utils/LinkedList/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* temp = current->next;
            current->next = prev;

            prev = current;
            current = temp;
        }

        return prev;
    }
};

int main() {
    vector<vector<int>> testCases = {{1, 2, 3, 4, 5}, {1, 2}, {}};

    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> testCase = testCases[i];

        ListNode* head = CreateLinkedList(testCase);
        ListNode* result = Solution().reverseList(head);

        cout << i + 1 << ": " << PrintContainer(testCase) << " -> " << PrintLinkedList(result) << endl;
    }

    return 0;
}
