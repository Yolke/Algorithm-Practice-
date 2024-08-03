#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};




struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* result = NULL;
    struct ListNode* result_cursor;

    while(list1 != NULL || list2 != NULL) {
        if (result == NULL) {
            result = (struct ListNode*) malloc(sizeof(struct ListNode));
            result->next = NULL;
            result_cursor = result;
        } else {
            result_cursor->next =
            (struct ListNode*) malloc(sizeof(struct ListNode));
            result_cursor = result_cursor->next;
            result_cursor->next = NULL;
        }

        if (list1 == NULL) {
            result_cursor->val = list2->val;
            list2 = list2->next;
        } else if (list2 == NULL) {
            result_cursor->val = list1->val;
            list1 = list1->next;
        } else if (list1->val < list2->val) {
            result_cursor->val = list1->val;
            list1 = list1->next;
        } else {
            result_cursor->val = list2->val;
            list2 = list2->next;
        }
    }

    return result;
}

int main(){

    

    return 0;
}