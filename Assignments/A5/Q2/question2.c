#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct Node {
    char *name;
    char *tea;
    struct Node *left;
    struct Node *right;
} Node;

int depth(Node *root) {
    if (root == NULL) {
        return 0;
    }

    int left_length = depth(root->left);
    int right_length = depth(root->right);
    int depth = 1;

    if (left_length > right_length) {
        depth += left_length;
    } else {
        depth += right_length;
    }
    return depth;
}

int check(Node *root, char *name) {
    int checker = 0;
    if (root == NULL) {
        return checker;
    }

    int left_check = check(root->left, name);
    int right_check = check(root->right, name);

    if (root->name == name) {
        checker += 1;
    }

    if (left_check == 1 || right_check == 1) {
        checker += 1;
    }
    return checker;
}

int count(Node *root, char *name) {
    if (root == NULL) {
        return -1;
    }
    int counter = 2;

    if (root->name == name) {
        return 1;
    }

    int left_count = count(root->left, name);
    int right_count = count(root->right, name);

    /*if (left_count > 1 && right_count == 0) {
        return 1 + left_count;
    }*/
    //return counter += left_count + right_count;
//}

/*int dfs(Node *root, char *name) {
    if (check(root, name) != 1) {
        return -1;
    } else {
        return count(root, name);
    }
}*/

typedef struct Node {
    char *name;
    char *tea;
    struct Node *left;
    struct Node *right;
} Node;

int depth(struct Node *node) {

    //checks if node is NULL or not, if it is then it will return 0 indicating no extra length
    if (node == NULL) {
        return 0;
    }

    //checks length of left side
    int left_length = depth(node->left);

    //checks legnth of right side
    int right_length = depth(node->right);

    //compares the two lengths, whichever one is bigger will be returned, the other will be eliminated
    //the one is to account for the current node it is on that will be returned to the previous node
    if (left_length > right_length) {
        return left_length + 1;
    }
    else {
        return right_length + 1;
    }
}

int search(struct Node *node,char *name,int *examinations,int *check) {

    //checks if its null, meaning that left or right node does not exist, not counting as examination
    if (node == NULL) {
        return 0;
    }
    //checks if name is name we are searching for, adds examination and sets check to 1 for program to know that
    //the name has been found
    else if (strcmp(node->name,name) == 0) {
        *check = 1;
        return *examinations+=1;
    }

    //First checks left side
    int left_check = search(node->left,name,examinations,check);
    //If name has been found, return immediately and add examination for each, never checks right side
    if (*check == 1) {
        return *examinations+=1;
    }
    //If name has not been found, check through right side and add examination regardless of if found or not
    else {
        int right_check = search(node->right,name,examinations,check);
        return *examinations+=1;
    }
}

int dfs(struct Node *root, char *name) {
    //Setting values for examinations and a bool for if name has been found or not
    int examinations = 0;
    int check = 0;

    //setting pointers so that we can pass to our function and manipulate multiple values
    int *examinationsPtr = &examinations;
    int *checkPtr = &check; 

    //call function at root, search will recursively go through the whole tree
    search(root,name,examinationsPtr,checkPtr);

    //checks if name has been found or not
    if (check == 0) {
        return -1;
    }
    else {
        return examinations;
    }
}

/******************The binary tree***********************
 * The following is an illustration of the binary tree
 * I *highly* recommend you test your algorithm on.
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 

int main() {
    // Testing code ^_^
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
}


