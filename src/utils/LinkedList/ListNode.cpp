#include "ListNode.h"

#include <sstream>
#include <string>
#include <vector>

ListNode* CreateLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

std::string PrintLinkedList(const ListNode* head) {
    std::ostringstream oss;
    oss << "[ ";

    while (head) {
        oss << head->val;
        if (head->next) oss << ", ";
        head = head->next;
    }
    oss << " ]";
    return oss.str();
}
