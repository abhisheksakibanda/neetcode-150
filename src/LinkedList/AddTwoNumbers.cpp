#include<bits/stdc++.h>
#include "../utils/PrettyPrinter.h"
#include "../utils/LinkedList/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        const auto dummy = new ListNode(0); // dummy head
        ListNode* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

int main() {
    vector testCases = {
        make_pair<vector<int>, vector<int>>({2, 4, 3}, {5, 6, 4}),
        make_pair<vector<int>, vector<int>>({0}, {0}),
        make_pair<vector<int>, vector<int>>({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}),
    };

    for (int i = 0; i < testCases.size(); ++i) {
        pair<vector<int>, vector<int>> testCase = testCases[i];
        ListNode* result = Solution().
            addTwoNumbers(CreateLinkedList(testCase.first), CreateLinkedList(testCase.second));
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintLinkedList(result) << endl;
    }
}
