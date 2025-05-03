#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<iomanip>                       /* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */
#include "NonSortedArray.h"
#include "SortedArray.h"                /* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */
#include "BinaryTree.h"
#include "HashTable.h"
#include "AVL.h"

using namespace std;
using namespace std::chrono;

struct KAST {
    string word;
    int times;
};



void removePunc(string& s) { //Συνάρτηση που αφαιρεί τα σημεία στίξης, τα σύμβολα και τους αριθμούς

    for(int i=0; i<s.length(); i++)
        if(s[i]>=65 && s[i]<=90)            //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            s[i]+=32;

    string temp="";
    for (int i=0; i<s.length(); i++)
    if (s[i]>=97 && s[i]<=122) {
        temp+=s[i];
    }
    s=temp;
}

int main() {

    int  m,temps;
    long long int c1=0;
    string ch;

    ifstream f;
    string temp;

    f.open("small-file.txt");

    if (!f.is_open()) { //Εμφάνιση σφάλματος ανοίγματος αρχείου
        cerr << "File Error\n";
    }


    while(!f.eof()) { //Μέτρηση όλων των λέξεων του αρχείου με το c1
        f>>ch;
        c1++;
    }
    cout <<"All words in file: "<< c1 << endl;
    f.close();

    ifstream f1;
    f1.open("small-file.txt");

    if (!f1.is_open()) { //Εμφάνιση σφάλματος ανοίγματος αρχείου
        cerr << "File Error\n";
    }

    string *A1=new string[c1]; //388987307 //Δημιουργία πίνακα Α1 με τον μετρητή c1 με όλες τις λέξεις
    //string *A1 = (string *) malloc(1L<<64);

    int i = 0;


    while (!f1.eof()) { //Καταχώρηση όλων των λέξεων στον πίνακα Α1
        for (i=0; i<c1; i++) {
            f1 >> ch;
            removePunc(ch);
            if (ch!="")
                A1[i]=ch;
        }
    }

    f1.close();



    srand(time(NULL));
    //long long int Q = rand() % c1 + 1;        //Υπολογισμός τυχαίου αριθμού λέξεων Q
    long long int Q=100000;                     //Χειροκίνητο Q
    cout <<"Random Number of Words Taken: "<< Q << endl;
    string *A2;
    A2 = new string[Q];         //Δημιουργία πίνακα με Q τυχαίες λέξεις A2

    for (i = 0; i < Q; i++) {
        A2[i] = A1[rand() % c1]; //Καταχώρηση των Q τυχαίων λέξεων στον πίνακα Α2
    }


    //Δήλωση πινάκων εμφανίσεων για κάθε Δομή
    int *U=new int[Q];
    int *S=new int[Q];
    int *B=new int[Q], *A=new int[Q], *H=new int[Q];



    /*  ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺  N O N          S O R T E D          A R R A Y  ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺  */


    NonSortedArray Unsorted; //Δημιουργία Αταξινόμητου Πίνακα

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (i=0; i<c1; i++)
        Unsorted.Insert(A1[i]);             //Καταχώρηση όλων των λέξεων στον Αταξινόμητο

    high_resolution_clock::time_point t2 = high_resolution_clock::now(); //  Τέλος υπολογισμού χρόνου
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Construct NonSortedArray.\n";

    //Unsorted.display();

    t1 = high_resolution_clock::now(); // Αρχή υπολογισμού χρόνου για τις αναζητήσεις στον Αταξινόμητο
    for (i = 0; i < Q; i++)
        U[i]=Unsorted.Search(A2[i]); //Q Αναζητήσεις των Q τυχαίων λέξεων στον Αταξινόμητο


    t2 = high_resolution_clock::now(); //  Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Search in NonSortedArray.\n";




    //Unsorted.Insert("clowns");
    //if(Unsorted.Delete("im"))     //Παραδείγματα υπόλοιπων συναρτήσεων
        //cout<<"Success\n";



    /* ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺  S O R T E D          A R R A Y  ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺ */


    SortedArray Sorted; //Δημιουργία Ταξινομημένου Πίνακα

    t1 = high_resolution_clock::now();
    for (i=0; i<c1; i++) {
        Sorted.Insert(A1[i]);       //Καταχώρηση όλων των λέξεων στον Ταξινομημένο
    }

    t2 = high_resolution_clock::now(); //  Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Construct SortedArray.\n";

    //Sorted.display();

    t1 = high_resolution_clock::now(); //Αρχή υπολογισμού χρόνου για τις αναζητήσεις στον Ταξινομημένο

    for (i = 0; i < Q; i++)
        S[i]=Sorted.Search(A2[i]); //Q Αναζητήσεις των Q τυχαίων λέξεων στον Ταξινομημένο


    t2 = high_resolution_clock::now(); //Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Search in SortedArray.\n";


    //Sorted.Insert("zari");
    //if (Sorted.Delete("youve"))      //Παραδείγματα υπόλοιπων συναρτήσεων
        //cout<<"Success\n\n";


    /* ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺  H A S H I N G          T A B L E  ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺ */

    HashTable HT; //Δημιουργία του HASHING TABLE

    t1 = high_resolution_clock::now();
    for (i=0; i<c1; i++)
        HT.Insert(A1[i]); //Καταχώρηση όλων των λέξεων στον HASHING TABLE

    t2 = high_resolution_clock::now(); //Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Construct HashTable.\n";

    //HT.display();

    t1 = high_resolution_clock::now(); //Αρχή υπολογισμού χρόνου για τις αναζητήσεις στον HASHING TABLE

    for (i=0; i<Q; i++)
        H[i]=HT.Search(A2[i]); //Q Αναζητήσεις των Q τυχαίων λέξεων στον HASHING TABLE


    t2 = high_resolution_clock::now(); //Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Search in HashTable.\n";

    //HT.Insert("opening"); //Παραδείγματα υπόλοιπων συναρτήσεων



    /* ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺  B I N A R Y          T R E E  ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺ */


    BinaryTree tree; //Δημιουργία Binary Tree

    t1 = high_resolution_clock::now();
    for (i=0; i<c1; i++)
        tree.insert(A1[i]); //Καταχώρηση όλων των λέξεων στο Binary Tree

    t2 = high_resolution_clock::now();  //Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Construct BinaryTree.\n";



    t1 = high_resolution_clock::now(); //Αρχή υπολογισμού χρόνου για τις αναζητήσεις στο BINARY TREE

    for (i=0; i<Q; i++)
        B[i]=tree.search(A2[i]); //Q Αναζητήσεις των Q τυχαίων λέξεων στο BINARY TREE


    t2 = high_resolution_clock::now();  //Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Search in BinaryTree.\n";

    //tree.remove("wounds");                        //Παραδείγματα υπόλοιπων συναρτήσεων
    //cout<<tree.search("dark")<<endl;
                                                    //
    /* tree.inorder();
    cout<<"\n\n";                                   //
    tree.preorder();
    cout<<"\n\n";                                   //
    tree.postorder();
    cout<<"\n\n"; */                                //


    /* ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺  A V L         T R E E  ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺ */


    AVL avltr; //Δημιουργία AVL Tree

    t1 = high_resolution_clock::now();
    for (i=0; i<c1; i++)
        avltr.insert(A1[i]); //Καταχώρηση όλων των λέξεων στο AVL Tree

    t2 = high_resolution_clock::now(); //Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Construct AVLTree.\n";


    t1 = high_resolution_clock::now(); //Αρχή υπολογισμού χρόνου για τις αναζητήσεις στο AVL TREE

    for (i=0; i<Q; i++)
        A[i]=avltr.search(A2[i]); //Q Αναζητήσεις των Q τυχαίων λέξεων στο AVL TREE


    t2 = high_resolution_clock::now(); //Τέλος υπολογισμού χρόνου
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds to Search in AVLTree.\n";

    //avltr.remove("wounds");                       //Παραδείγματα υπόλοιπων συναρτήσεων
    //cout<<avltr.search("dark")<<endl;
                                                    //
    /* avltr.inorder();
    cout<<"\n\n";                                   //
    avltr.preorder();
    cout<<"\n\n";                                   //
    avltr.postorder();
    cout<<"\n\n"; */                                //


    ofstream f2;

    f2.open("ProjectOutput.txt");

    if (!f2.is_open()) { //Εμφάνιση σφάλματος ανοίγματος αρχείου
        cerr << "File Error\n";
    }

    //Τύπωμα στο αρχείο "ProjectOutput.txt"
    f2<<setw(25)<<"**********"<<setw(25)<<"**********"<<setw(25)<<"**********";
    f2<<setw(25)<<"**********"<<setw(25)<<"**********\n";
    f2<<setw(25)<<"UNSORTED ARRAY"<<setw(25)<<"SORTED ARRAY"<<setw(25)<<"HASHING TABLE";
    f2<<setw(25)<<"BINARY TREE"<<setw(25)<<"AVL TREE\n";
    f2<<setw(25)<<"**********"<<setw(25)<<"**********"<<setw(25)<<"**********";
    f2<<setw(25)<<"**********"<<setw(25)<<"**********\n\n";

    for(i=0; i<Q; i++) {
        f2 << setw(15) << A2[i] << setw(10) << U[i];
        f2 << setw(15) << A2[i] << setw(10) << S[i];
        f2 << setw(15) << A2[i] << setw(10) << H[i];
        f2 << setw(15) << A2[i] << setw(10) << B[i];
        f2 << setw(15) << A2[i] << setw(10) << A[i];
        f2 << endl;
    }

    f2.close();
}

                /* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

                /* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */