#include "NonSortedArray.h"
#include<iomanip>
using namespace std;

struct KAST {
    string word;
    int times;
};


NonSortedArray::NonSortedArray() { //  Κατασκευαστής του Αταξινόμητου Πίνακα
    NSA=new KAST [size];            //Δημιουργία Πίνακα NSA
    lekseis=0;
}

void NonSortedArray::Insert(string leksi) {

    for(int i=0; i<leksi.length(); i++)
        if(leksi[i]>=65 && leksi[i]<=90)           //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            leksi[i]+=32;

    for (int i=0; i<lekseis; i++)
        if (leksi==NSA[i].word) {       //Αν υπάρχει ήδη η λέξη τοτε εμφανισεις++
            NSA[i].times++;
            return;
        }

    if (lekseis<size) {                 //Αν δεν υπάρχει και έχουμε αρκετές θέσεις στον πίνακα
        NSA[lekseis].word=leksi;
        NSA[lekseis].times=1;
        lekseis++;
        return;
    }
    if (lekseis==size) {            //Αν δεν έχουμε άλλες κενές θέσεις στον πίνακα, αυξάνουμε τις θέσεις του δυναμικά
        size*=2;
        NSAI=new KAST [size];
        for (int i=0; i<lekseis; i++) {
            NSAI[i]=NSA[i];
        }

        NSA=new KAST [size];
        for (int i=0; i<lekseis; i++)
            NSA[i]=NSAI[i];
    }
}


int NonSortedArray::Search(string leksi) {
    for(int i=0; i<leksi.length(); i++)
        if(leksi[i]>=65 && leksi[i]<=90)        //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            leksi[i]+=32;


        for(int i=0; i<lekseis; i++) {      //Σειριακή Αναζήτηση της λέξης στον πίνακα
        if (leksi == NSA[i].word)
            return NSA[i].times;            //Επιστροφή των εμφανίσεων της αν υπάρχει
        }

    return -1;
}

bool NonSortedArray::Delete(string leksi) {
    for(int i=0; i<leksi.length(); i++)
        if(leksi[i]>=65 && leksi[i]<=90)            //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            leksi[i]+=32;

    int position=-1;

    for (int i=0; i<lekseis; i++) {
        if (leksi==NSA[i].word) {       //Σειριακή Αναζήτηση της λέξης αν υπάρχει για εύρεση της θέσης της
            position=i;
            break;
        }
    }

    if (position!=-1) { //Αν υπάρχει η λέξη
        NSA[position].times--;      //-1 εμφάνιση
        if(NSA[position].times==0) {    //Αν το times γίνει 0 τότε σβήνουμε ολόκληρη την λέξη από τον πίνακα
            lekseis--;
            if (position==lekseis) {
                NSA[position].word="";
            }
            else {
                for (int i=position; i<lekseis; i++)
                    NSA[i]=NSA[i+1];
                NSA[lekseis].word="";
                NSA[lekseis].times=0;
            }
        }
    return true;
    }
    return false;
}

void NonSortedArray::display() {        //Εμφάνιση του Αταξινόμητου Πινακα
    cout<<endl;
    cout<<setw(70)<<"* * * * * * * * * *\n";
    cout<<setw(75)<<"U N S O R T E D          A R R A Y\n";
    cout<<setw(71)<<"* * * * * * * * * *\n\n";

    for (int i=0; i<lekseis; i++)
        cout<<NSA[i].word<<"("<<NSA[i].times<<") ";
    cout<<endl<<endl;
    //cout<<"Words in Unsorted: "<<lekseis<<endl;
}

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */