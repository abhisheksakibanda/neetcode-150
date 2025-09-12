#include <bits/stdc++.h>
#include "../utils/PrettyPrinter.h"
#include "../utils/LinkedList/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // dummy head
        ListNode* current = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        current->next = list1 ? list1 : list2; // adds remaining numbers from list1 or list2

        return dummy.next;
    }
};

int main() {
    vector testCases = {
        make_pair<vector<int>, vector<int>>({1, 2, 4}, {1, 3, 4}),
        make_pair<vector<int>, vector<int>>({}, {}),
        make_pair<vector<int>, vector<int>>({}, {0}),
    };

    for (int i = 0; i < testCases.size(); ++i) {
        pair<vector<int>, vector<int>> testCase = testCases[i];
        ListNode* result = Solution().
            mergeTwoLists(CreateLinkedList(testCase.first), CreateLinkedList(testCase.second));
        cout << i + 1 << ": " << PrintElement(testCase) << " -> " << PrintLinkedList(result) << endl;
    }
}
