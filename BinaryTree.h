#pragma once
#include<iostream>
using namespace std;

class BinaryTree
{
    struct KAST {
        string word;
        int times;
    };

    struct TreeNode
    {
        struct KAST value;
        TreeNode* left;
        TreeNode* right;
        int height;
    };

    TreeNode* root;

    TreeNode* insert(string , TreeNode*);

    TreeNode* Min(TreeNode*);

    TreeNode* Max(TreeNode*);

    TreeNode* remove(string, TreeNode*);

    int search (string, TreeNode *);

    int height(TreeNode*);

    void inorder(TreeNode*);

    void preorder(TreeNode*);

    void postorder(TreeNode*);

public:
    BinaryTree();

    void insert(string);

    int search(string);

    void remove(string);

    void inorder();

    void preorder();

    void postorder();
};

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */