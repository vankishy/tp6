//
// Created by reinhardsitumeang on 21/10/2023.
//

#ifndef MODUL6_DLL_H
#define MODUL6_DLL_H
#include <iostream>

#define first(L) (L).first
#define last(L) (L).last
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev

using namespace std;

struct playlist {
    string artist;
    string song;
};

typedef playlist infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address prev, next;
};

struct List {
    address first, last;
};

bool isEmpty_1302220001(List L);
void createList_1302220001(List &L);
address createNewElm_1302220001(infotype X, address P);
void insertFirst_1302220001(List &L, address P);
void insertAfter_1302220001(List &L, address &P, address &Prec);
void insertLast_1302220001(List &L, address P);
void deleteFirst_1302220001(List &L, address P);
void deleteAfter_1302220001(List &L, address &P, address &Prec);
void deleteLast_1302220001(List &L, address P);
void concat_1302220001(List L1, List L2, List &L3);
address findLagu_1302220001(string Judul, List L);
void removeLagu_1302220001(string Judul, List &L);
void showPlaylist_1302220001(List L);
int menu_1302220001();

#endif //MODUL6_DLL_H
