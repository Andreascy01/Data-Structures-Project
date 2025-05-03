#ifndef PROJECT_SORTEDARRAY_H
#define PROJECT_SORTEDARRAY_H

#include<iostream>

using namespace std;


class SortedArray {

private:
    struct KAST *SA, *SAI;
    int lekseis, size=4096;

public:
    SortedArray();

    void Insert(string);
    int pos(string);
    bool Delete(string);
    int Search(string);
    void display();
};

#endif //PROJECT_SORTEDARRAY_H

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */
