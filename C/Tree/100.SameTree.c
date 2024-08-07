#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

enum Direction { RIGHT, LEFT };

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Initialise le noeud de l'arbre
void initTree(struct TreeNode** root) {
    *root = malloc(sizeof(struct TreeNode));
    (*root)->val = 0;
    (*root)->left = NULL;
    (*root)->right = NULL;
}

// Ajoute un noeud à l'arbre
void addNode(struct TreeNode* root, int val, enum Direction direction) {
    if (direction == RIGHT) {
        root->right = malloc(sizeof(struct TreeNode));
        root->right->val = val;
        root->right->left = NULL;
        root->right->right = NULL;
    }
    if (direction == LEFT) {
        root->left = malloc(sizeof(struct TreeNode));
        root->left->val = val;
        root->left->left = NULL;
        root->left->right = NULL;
    }
}

// Affiche l'arbre en indiquant gauche et droite
void printTree(struct TreeNode* root, int level, enum Direction from) {
    if (root == NULL) {
        return;
    }

    // Afficher la valeur du noeud courant avec indentation et direction
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    if (from == LEFT) {
        printf("L--- ");
    } else if (from == RIGHT) {
        printf("R--- ");
    } else {
        printf("Root: ");
    }
    printf("%d\n", root->val);

    // Afficher le sous-arbre gauche
    printTree(root->left, level + 1, LEFT);
    // Afficher le sous-arbre droit
    printTree(root->right, level + 1, RIGHT);
}

int main() {
    struct TreeNode* root;
    struct TreeNode* root2;

    initTree(&root);
    initTree(&root2);

    addNode(root, 1, LEFT);          
    addNode(root->left, 2, LEFT);     
    addNode(root->left->left, 3, LEFT); 
    addNode(root->left->left->left, 4, LEFT); 
    addNode(root, 5, RIGHT);          

    addNode(root2, 1, LEFT);          
    addNode(root2->left, 2, LEFT);     
    addNode(root2->left->left, 3, LEFT); 
    addNode(root2->left->left->left, 4, LEFT); 
    addNode(root2, 5, RIGHT);   


    printTree(root, 0, -1);
    printf("Res : %d",isSameTree(root,root2));


    return 0;
}
