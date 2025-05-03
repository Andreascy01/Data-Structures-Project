#ifndef PROJECT_NONSORTEDARRAY_H
#define PROJECT_NONSORTEDARRAY_H
#include<iostream>

using namespace std;


class NonSortedArray {

private:
    struct KAST *NSA, *NSAI;
    int lekseis, size=4096;

public:
    NonSortedArray();

    void Insert(string);
    bool Delete(string);
    int Search(string);
    void display();
};

#endif //PROJECT_NONSORTEDARRAY_H

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */