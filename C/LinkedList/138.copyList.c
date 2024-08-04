#include <stdlib.h>
#include <stdio.h>


struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};


struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;

    // Étape 1 : Créer des copies des nœuds et les insérer à côté des originaux
    struct Node* current = head;
    while (current != NULL) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = current->val;
        copy->next = current->next;
        copy->random = NULL; // On ajustera le pointeur random plus tard
        current->next = copy;
        current = copy->next;
    }

    // Étape 2 : Ajuster les pointeurs random dans les nœuds copiés
    current = head;
    while (current != NULL) {
        struct Node* copy = current->next;
        copy->random = (current->random != NULL) ? current->random->next : NULL;
        current = copy->next;
    }

    // Étape 3 : Séparer la liste originale de la liste copiée
    struct Node* newHead = head->next;
    struct Node* copyCurrent = newHead;
    current = head;

    while (current != NULL) {
        current->next = copyCurrent->next;
        current = current->next;
        if (current != NULL) {
            copyCurrent->next = current->next;
            copyCurrent = copyCurrent->next;
        }
    }

    return newHead;
}

int main(){
    return 0;
}