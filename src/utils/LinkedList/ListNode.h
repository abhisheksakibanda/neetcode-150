#pragma once

#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* CreateLinkedList(const std::vector<int>& arr);

std::string PrintLinkedList(const ListNode* head);