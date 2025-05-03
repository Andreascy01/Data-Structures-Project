#include "AVL.h"

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

AVL::AVL()
{
    root = NULL;
}

AVL::TreeNode* AVL::insert(string x, TreeNode* t)       //Private Insert
{
    if(t == NULL)           //Αν το TreeNode είναι κενό
    {
        t = new TreeNode;
        t->value.word = x;
        t->value.times=1;
        t->height = 0;
        t->left = t->right = NULL;
    }
    else if (x == t->value.word)        //Αν βρεθεί το TreeNode με την λέξη τότε εμφανίσεις++
        t->value.times++;

    else if(x < t->value.word)          //Αν η λέξη είναι μικρότερη από το word του TreeNode
    {
        t->left = insert(x, t->left);   //Πέρνουμε το αριστερό παιδί και αναδρομική
        if(height(t->left) - height(t->right) == 2)     //Αν το AVL δεν είναι ισοζυγισμένο
        {
            if(x < t->left->value.word)                 //Έλεγχος για το αν θα γίνει απλή ή διπλή δεξιά περιστροφή
                t = rightRotate(t);
            else
                t = drightRotate(t);
        }
    }
    else if(x > t->value.word)          //Αν η λέξη είναι μεγαλύτερη από το word του TreeNode
    {
        t->right = insert(x, t->right);     //Πέρνουμε το δεξί παιδί καί αναδρομική
        if(height(t->right) - height(t->left) == 2)     //Αν το AVL δεν είναι ισοζυγισμένο
        {
            if(x > t->right->value.word)                //Έλεγχος για το αν θα γίνει απλή ή διπλή αριστερή περιστροφή
                t = leftRotate(t);
            else
                t = dleftRotate(t);
        }
    }


    t->height = max(height(t->left), height(t->right))+1;       //Υπολογίζουμε το ύψος
    return t;
}

void AVL::insert(string x)      //Public Insert
{
    root = insert(x, root);
}

AVL::TreeNode* AVL::rightRotate(TreeNode* &t)   //Απλή δεξιά περιστροφή
{
    TreeNode* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(u->left), t->height)+1;
    return u;
}

AVL::TreeNode* AVL::leftRotate(TreeNode* &t)        //Απλή αριστερή περιστροφή
{
    TreeNode* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(t->right), t->height)+1 ;
    return u;
}

AVL::TreeNode* AVL::dleftRotate(TreeNode* &t)       //Διπλή αριστερή περιστροφή
{
    t->right = rightRotate(t->right);
    return leftRotate(t);
}

AVL::TreeNode* AVL::drightRotate(TreeNode* &t)      //Διπλή δεξιά περιστροφή
{
    t->left = leftRotate(t->left);
    return rightRotate(t);
}

AVL::TreeNode* AVL::Min(TreeNode* t)                //Υπολογισμός ελάχιστου
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return Min(t->left);
}

AVL::TreeNode* AVL::Max(TreeNode* t)                //Υπολογισμός μέγιστου
{
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return Max(t->right);
}

AVL::TreeNode* AVL::remove(string x, TreeNode* t)       //Private Remove
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

    t->height = max(height(t->left), height(t->right))+1;       //Υπολογισμός ύψους

    //Αν το AVL δεν είναι ισοζυγισμένο
    // Αν διαγραφτεί το αριστερό TreeNode
    if(height(t->left) - height(t->right) == 2)
    {
        if(height(t->left->left) - height(t->left->right) == 1) //Έλεγχος για το αν θα γίνει απλή ή διπλή αριστερή περιστροφή
            return leftRotate(t);
        else
            return dleftRotate(t);
    }
        // Αν διαγραφτεί το δεξί TreeNode
    else if(height(t->right) - height(t->left) == 2)
    {
        if(height(t->right->right) - height(t->right->left) == 1) //Έλεγχος για το αν θα γίνει απλή ή διπλή δεξιά περιστροφή
            return rightRotate(t);
        else
            return drightRotate(t);
    }
    return t;
}

void AVL::remove(string x)      //Public Remove
{
    root = remove(x, root);
}

int AVL::search (string val, TreeNode *t) {     //Private Search

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

int AVL::search(string x)       //Public Search
{
    int s=search(x, root);
    return s;
}

int AVL::height(TreeNode* t)    //Υπολογισμός ύψους
{
    return (t == NULL ? -1 : t->height);
}

void AVL::inorder(TreeNode* t)      //Private Inorder
{
    if(t == NULL)
        return;
    inorder(t->left);
    cout << t->value.word << "(" << t->value.times << ")  ";
    inorder(t->right);
}

void AVL::inorder()                 //Public Inorder
{
    inorder(root);
    cout << endl;
}

void AVL::preorder(TreeNode* t)     //Private Preorder
{
    if(t == NULL)
        return;
    cout << t->value.word << "(" << t->value.times << ")  ";
    preorder(t->left);
    preorder(t->right);
}

void AVL::preorder()                //Public Preorder
{
    preorder(root);
    cout << endl;
}

void AVL::postorder(TreeNode* t)    //Private Postorder
{
    if(t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    cout << t->value.word << "(" << t->value.times << ")  ";
}

void AVL::postorder()               //Public Postorder
{
    postorder(root);
    cout << endl;
}

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */