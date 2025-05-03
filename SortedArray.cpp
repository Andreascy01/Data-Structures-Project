#include "SortedArray.h"
#include<iomanip>

struct KAST {
    string word;
    int times;
};


SortedArray::SortedArray() {

    SA=new KAST[size];      //Δημιουργία πίνακα SA
    lekseis=0;
}

void SortedArray::Insert(string leksi){

    for(int i=0; i<leksi.length(); i++)
        if(leksi[i]>=65 && leksi[i]<=90)        //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            leksi[i]+=32;

    int position;

    if (lekseis==size-1) {        //Αν δεν έχουμε άλλες κενές θέσεις στον πίνακα, αυξάνουμε τις θέσεις του δυναμικά
        size*=2;
        SAI= new KAST [size];

        for (int i=0; i<lekseis; i++)
            SAI[i]=SA[i];
        SA=new KAST [size];
        for (int i=0; i<lekseis; i++)
            SA[i]=SAI[i];
    }

    if (lekseis!=0)
    position=pos(leksi);        //Υπολογισμός της θέσης της λέξης αν υπάρχει
    else {
        SA[lekseis].word = leksi;          //Καταχώρηση της πρώτης λέξης
        SA[lekseis].times = 1;
        lekseis++;
        return;
    }

    if (position!=-1) {             //Αν υπάρχει ήδη η λέξη, εμφανίσεις++
        SA[position].times++;
        return;
    }

    else {                          //Αν δεν υπάρχει η λέξη
        int first = 0, last = lekseis - 1, mid;

        if (leksi < SA[first].word) {   //Αν η λέξη είναι μικρότερη από όλες τις λέξεις καταχωρείται στην αρχή
            lekseis++;
            for (int i = lekseis; i > 0; i--) {
                SA[i] = SA[i - 1];
            }
            SA[first].word = leksi;
            SA[first].times = 1;
        }
        else if (leksi > SA[last].word) { //Αν η λέξη είναι μεγαλύτερη από όλες τις λέξεις καταχωρείται στο τέλος
            SA[lekseis].word = leksi;
            SA[lekseis].times = 1;
            lekseis++;
        }
        else {    //Αν ανήκει κάπου ενδιάμεσα ψάχνουμε την ακριβής θέση που πρέπει να καταχωρηθεί
            for (int i = 0; i < lekseis; i++)
                while (first <= last) {
                    mid = (first + last) / 2;
                    if (SA[mid].word < leksi && SA[mid + 1].word > leksi) { //Θέση που πρέπει να καταχωρηθεί
                        position = mid + 1;
                        break;
                    } else if (leksi < SA[mid].word)
                        last = mid - 1;
                    else
                        first = mid + 1;
                }

            lekseis++;
            for (int i = lekseis; i > position; i--) {
                SA[i] = SA[i - 1];          //Μετακίνηση μέρους του πίνακα προς τα πάνω για να καταχωρηθεί η νέα λέξη
            }
            SA[position].word = leksi;
            SA[position].times = 1;
        }
    }
}


int SortedArray::pos(string leksi) {    //Binary Search για να βρίσκουμε τη θέση που ψάχνουμε
    int first=0,last=lekseis-1,mid;
    int i;
    for(i=0; i<lekseis; i++)
        while(first<=last){
            mid=(first+last)/2;
            if(SA[mid].word==leksi)
                return mid;
            else if(leksi<SA[mid].word)
                last=mid-1;
            else
                first=mid+1;
        }
    return -1;
}

int SortedArray::Search(string leksi) { //Binary Search με χρήση του pos

    for(int i=0; i<leksi.length(); i++)
        if(leksi[i]>=65 && leksi[i]<=90)            //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            leksi[i]+=32;

        int thesi=pos(leksi);

    return SA[thesi].times;         //Επιστροφή των εμφανίσεων της λέξης
}

bool SortedArray::Delete(string leksi) {
    for(int i=0; i<leksi.length(); i++)
        if(leksi[i]>=65 && leksi[i]<=90)            //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            leksi[i]+=32;


    int thesi = pos(leksi);         //Εύρεση για το αν υπάρχει η λέξη και αν ναι που

    if (thesi!=-1) {                    //Αν υπάρχει
        SA[thesi].times--;
        if (SA[thesi].times == 0) {    //Αν το times γίνει 0 τότε σβήνουμε ολόκληρη την λέξη από τον πίνακα
            lekseis--;
            if (thesi == lekseis) {
                SA[thesi].word = "";
            } else {
                for (int i = thesi; i < lekseis; i++)
                    SA[i] = SA[i + 1];
                SA[lekseis].word = "";
                SA[lekseis].times = 0;
            }
        }
        return true;
    }
    return false;
}

void SortedArray::display() {       //Εμφάνιση του Ταξινομημένου Πίνακα
    cout<<endl;
    cout<<setw(70)<<"* * * * * * * * * *\n";
    cout<<setw(75)<<"S O R T E D          A R R A Y\n";
    cout<<setw(71)<<"* * * * * * * * * *\n\n";

    for (int i=0; i<lekseis; i++)
        cout<<SA[i].word<<"("<<SA[i].times<<") ";
    cout<<endl<<endl;
    //cout<<"Words in Sorted: "<<lekseis<<endl;
}

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */