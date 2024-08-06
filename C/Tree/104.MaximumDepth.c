#include <stdlib.h>
#include <stdio.h>

enum Direction { RIGHT, LEFT };

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int max(int x,int y){
    return x > y ? x : y;
}

int maxDepth(struct TreeNode* root) {
    return !root ? 0 : max(maxDepth(root->left),maxDepth(root->right)) + 1;
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

    initTree(&root);

    addNode(root, 1, LEFT);          
    addNode(root->left, 2, LEFT);     
    addNode(root->left->left, 3, LEFT); 
    addNode(root->left->left->left, 4, LEFT); 
    addNode(root, 5, RIGHT);          

    printf("H max = %d\n",maxDepth(root));
    

    printTree(root, 0, -1);



    return 0;
}
