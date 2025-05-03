#include "BinaryTree.h"

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

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::TreeNode* BinaryTree::insert(string x, TreeNode* t) //Private Insert
{
    if(t == NULL)       //Αν το TreeNode είναι κενό
    {
        t = new TreeNode;
        t->value.word = x;
        t->value.times=1;
        t->height = 0;
        t->left = t->right = NULL;
    }
    else if (x == t->value.word)    //Αν βρεθεί το TreeNode με την λέξη τότε εμφανίσεις++
        t->value.times++;

    else if(x < t->value.word)      //Αν η λέξη είναι μικρότερη από το word του TreeNode
    {
        t->left = insert(x, t->left);   //Πέρνουμε το αριστερό παιδί και αναδρομική
    }
    else if(x > t->value.word)      //Αν η λέξη είναι μεγαλύτερη από το word του TreeNode
    {
        t->right = insert(x, t->right); //Πέρνουμε το δεξί παιδί καί αναδρομική
    }


    t->height = max(height(t->left), height(t->right))+1; //Υπολογίζουμε το ύψος
    return t;
}

void BinaryTree::insert(string x) //Public Insert
{
    root = insert(x, root);
}


BinaryTree::TreeNode* BinaryTree::Min(TreeNode* t) //Υπολογισμός ελάχιστου
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return Min(t->left);
}

BinaryTree::TreeNode* BinaryTree::Max(TreeNode* t) //Υπολογισμός μέγιστου
{
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return Max(t->right);
}

BinaryTree::TreeNode* BinaryTree::remove(string x, TreeNode* t) //Private Remove
{
    TreeNode* temp;

    // Δεν βρέθηκε η λέξη
    if(t == NULL)
        return NULL;

        // Αναζήτηση της λέξης
    else if(x < t->value.word)
        t->left = remove(x, t->left);
    else if(x > t->value.word)
        t->right = remove(x, t->right);

        // Βρέθηκε η λέξη με 2 παιδιά
    else if(t->left && t->right)
    {
        temp = Min(t->right);
        t->value = temp->value;
        t->right = remove(t->value.word, t->right);
    }
        // Βρέθηκε η λέξη με 1 ή 0 παιδιά
    else
    {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }
    if(t == NULL)
        return t;

    t->height = max(height(t->left), height(t->right))+1; //Υπολογισμός ύψους

    return t;
}

void BinaryTree::remove(string x) //Public Remove
{
    root = remove(x, root);
}

int BinaryTree::search (string val, TreeNode *t) { //Private Search

    //Δεν υπάρχει η λέξη
    if (t == NULL){
        return -1;
    }
    else{
        if (t->value.word == val){
            //Επιτυχής εύρεση λέξης
            return t->value.times;
        }
        else if (val < t->value.word){
            // Ψάχνουμε αριστερά
            return search(val, t->left);
        }
        else {
            // Ψάχνουμε δεξιά
            return search(val, t->right);
        }
    }
}

int BinaryTree::search(string x) //Public Search
{
    int s=search(x, root);
    return s;
}

int BinaryTree::height(TreeNode* t)        //Υπολογισμός ύψους
{
    return (t == NULL ? -1 : t->height);
}


void BinaryTree::inorder(TreeNode* t)       //Private Inorder
{
    if(t == NULL)
        return;
    inorder(t->left);
    cout << t->value.word << "(" << t->value.times << ")  ";
    inorder(t->right);
}

void BinaryTree::inorder()                  //Public Inorder
{
    inorder(root);
    cout << endl;
}

void BinaryTree::preorder(TreeNode* t)      //Private Preorder
{
    if(t == NULL)
        return;
    cout << t->value.word << "(" << t->value.times << ")  ";
    preorder(t->left);
    preorder(t->right);
}

void BinaryTree::preorder()                 //Public Preorder
{
    preorder(root);
    cout << endl;
}

void BinaryTree::postorder(TreeNode* t)     //Private Postorder
{
    if(t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    cout << t->value.word << "(" << t->value.times << ")  ";
}

void BinaryTree::postorder()                //Public Postorder
{
    postorder(root);
    cout << endl;
}

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */