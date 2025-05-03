#include "HashTable.h"
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;


struct KAST {
    string word;
    int times;
};

HashTable::HashTable() {
    //size=524287;
    size=55557389;
    lekseis=0;
    HashTab = new KAST[size];           //Δημιουργία HASHING TABLE HashTab

    for (int i = 0; i < size; i++) {    //Αρχικοποίηση HashTab

        HashTab[i].word = "";
        HashTab[i].times = 0;
    }
}

long long HashTable::HashValue(string a) { //Υπολογισμός HASH VALUE
    int p = 31;         //31 ο επόμενος πρώτος μετά το 26(λατινικοί χαρακτήρες)
    int m =  55557389; //μεγαλος πρωτος αριθμος //524287 //55557389
    long long power_of_p = 1;
    long long hash_val = 0;

    // Loop για υπολογισμό του HASH VALUE
    // με τις ASCII τιμές των στοιχείων της λέξης
    for (int i = 0; i < a.length(); i++) {
        hash_val = (hash_val + (a[i]-'a'+1) * power_of_p) % m;

        power_of_p = (power_of_p * p) % m;

    }
    if (hash_val<0)     //Αν προκύψει αρνητικό HASH VALUE πολλαπλασιάζουμε με το -1
        hash_val*=(-1);
    return hash_val;
}



void HashTable::Insert(string leksi)
{
    for(int i=0; i<leksi.length(); i++)
        if(leksi[i]>=65 && leksi[i]<=90)            //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            leksi[i]+=32;


    long long int pos= HashValue(leksi);         //Υπολογισμός HASH VALUE της λέξης

    if(HashTab[pos].word=="")                       //Αν έχει κενό στην θέση καταχωρούμε τη λέξη με μια εμφάνιση
    {
        HashTab[pos].word=leksi;
        HashTab[pos].times=1;
        lekseis++;
    }
    else
    {
        while (HashTab[pos].word != leksi && HashTab[pos].word!="") {   //Αναζήτηση επόμενου κενού ή της λέξης
            pos++;
            if (pos==size-1 && HashTab[pos].word!=leksi)
                pos = 0;
        }

        if (HashTab[pos].word == leksi)     //Αν βρεθεί η λέξη, εμφανίσεις++
            HashTab[pos].times++;
        else {
            HashTab[pos].word=leksi;        //Αν βρεθεί κενό, καταχωρούμε την λέξη με μία εμφάνιση
            HashTab[pos].times=1;
            lekseis++;
        }
    }
}

int HashTable::Search(string leksi) {
    for(int i=0; i<leksi.length(); i++)
        if(leksi[i]>=65 && leksi[i]<=90)            //Μετατροπή Κεφαλαίων της λέξης σε Πεζά
            leksi[i]+=32;

    long long int pos= HashValue(leksi);        //Υπολογισμός HASH VALUE της λέξης

    if (HashTab[pos].word=="")      //Αν δεν υπάρχει η λέξη επιστρέφουμε -1
        return -1;
    else {
        if (HashTab[pos].word==leksi)       //Αν βρεθεί η λέξη
        return HashTab[pos].times;          //Επιστρέφουμε τις εμφανίσεις της
        else {
            while (HashTab[pos].word!=leksi) { //pos++ μέχρι να βρεθεί η λέξη
                pos++;
                if (pos == size - 1 && HashTab[pos].word != leksi)
                    pos = 0;                    //Όταν pos=size ξαναξεκινούμε το pos από το 0
            }
            return HashTab[pos].times;         //Επιστρέφουμε τις εμφανίσεις της
        }
    }
}

void HashTable::display() {         //Εμφάνιση HASHING TABLE
    cout<<endl;
    cout<<setw(70)<<"* * * * * * * * * *\n";
    cout<<setw(75)<<"H A S H          T A B L E\n";
    cout<<setw(71)<<"* * * * * * * * * *\n\n";

    for (int i=0; i<size; i++)
        cout<<HashTab[i].word<<"("<<HashTab[i].times<<") ";
    cout<<endl<<endl;
    //cout<<"Words in Hash Table: "<<lekseis<<endl;
}

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */