//
// Created by reinhardsitumeang on 21/10/2023.
//

#include "dll.h"

bool isEmpty_1302220001(List L) {
    if (first(L) == NULL && last(L) == NULL) {
        return true;
    } else {
        return false;
    }
}

address createNewElm_1302220001(infotype X, address P) {
    P = new elmList;

    info(P).artist = X.artist;
    info(P).song = X.song;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void createList_1302220001(List &L) {
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst_1302220001(List &L, address P) {
    if (!isEmpty_1302220001(L)) {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
    }
}

void insertAfter_1302220001(List &L, address &P, address &Prec) {
    if (!isEmpty_1302220001(L)) {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    } else {
        first(L) = P;
        last(L) = P;
    }

}

void insertLast_1302220001(List &L, address P) {
    if (!isEmpty_1302220001(L)) {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
    }

}

void deleteFirst_1302220001(List &L, address P) {
    P = first(L);

    if (next(P) != NULL && prev(P) != NULL) {
        first(L) = next(first(L));
        next(P) = NULL;
        prev(first(L)) = NULL;
    } else {
        first(L) = NULL;
        last(L) = NULL;
    }
}

void deleteAfter_1302220001(List &L, address &P, address &Prec) {
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}

void deleteLast_1302220001(List &L, address P) {
    P = last(L);

    if (prev(P) != NULL && next(P) != NULL) {
        last(L) = prev(last(L));
        prev(P) = NULL;
        next(last(L)) = NULL;
    } else {
        first(L) = NULL;
        last(L) = NULL;
    }


}

void concat_1302220001(List L1, List L2, List L3) {
    address Q;
    next(last(L1)) = first(L2);
    prev(first(L2)) = last(L1);

    Q = first(L1);
    createList_1302220001(L3);
    while (Q != NULL) {
        insertLast_1302220001(L3, Q);
        Q = next(Q);
    }
}

address findLagu_1302220001(string Judul, List L) {
    address Pdpn, Pfound;

    Pdpn = first(L);

    while (Pdpn != NULL) {
        if (info(Pdpn).song == Judul) {
            Pfound = Pdpn;
        }
        Pdpn = next(Pdpn);
    }
    return Pfound;
}

void removeLagu_1302220001(string Judul, List &L) {
    address P, Q;

    Q = findLagu_1302220001(Judul, L);
    P = first(L);
    if (Q != NULL) {
        if (!isEmpty_1302220001(L)) {
            if (P != NULL) {
                deleteAfter_1302220001(L, P,Q);
            }
        } else {
            deleteLast_1302220001(L, P);
        }
    }
}

void showPlaylist_1302220001(List L) {
    address P;

    P = first(L);
    while (P != NULL) {
        cout << info(P).artist << " - " << info(P).song << endl;
        P = next(P);
    }
    cout << endl << endl;
}
int menu_1302220001() {
    int input;

    cout << "======= Playlist =======" << endl;
    cout << "1. Tambah daftar lagu   " << endl;
    cout << "2. Tampilkan daftar lagu" << endl;
    cout << "3. Cari playlist        " << endl;
    cout << "4. Hapus playlist       " << endl;
    cout << "0. Keluar               " << endl;

    cout << "Masukkan Menu : ";
    cin >> input;

    return input;
}