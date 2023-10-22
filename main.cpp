#include "dll.h"

int main() {
    List Lmain{};
    address Pt;
    int select;
    infotype temp;
    string artist, song, choice;

    createList_1302220001(Lmain);

    select = menu_1302220001();
    while (select != 0) {
        switch (select) {
            case 1:
                cout << "Masukkan nama band : ";
                cin.ignore();
                getline(cin, artist);
                cout << "Masukkan judul lagu : ";
                getline(cin, song);

                temp.artist = artist;
                temp.song = song;

                Pt = createNewElm_1302220001(temp, NULL);
                insertFirst_1302220001(Lmain, Pt);
                cout << "Ditambahkan ke playlist" << endl;
                select = 2;
                break;
            case 2:
                cout << " " << endl;
                showPlaylist_1302220001(Lmain);
                cout << "Press [5] to main menu" << endl;
                cin >> select;
                break;
            case 3:
                cout << "Masukkan judul lagu : ";
                cin.ignore();
                getline(cin, song);

                Pt = findLagu_1302220001(song, Lmain);
                if (Pt != NULL) {
                    cout << info(Pt).artist << " - " << info(Pt).song << endl << endl;
                } else {
                    cout << "Lagu tidak ditemukan !!!" << endl;
                }
                cout << "[5] Kembali ke menu" << endl;
                cin >> select;
                break;
            case 4:
                cout << "Tulis judul lagu disini : ";
                cin.ignore();
                getline(cin, song);
                removeLagu_1302220001(song, Lmain);
                cout << "Kembali ke menu utama..." << endl;
                select = 5;
                break;
            case 5:
                cout << endl;
                select = menu_1302220001();
        }
    }
    cout << "Menutup Playlist..." << endl;
    return 0;
}
