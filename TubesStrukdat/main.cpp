#include "history.h"

using namespace std;

int main()
{
    /* PROGRAM SUDAH PERNAH DIJALANKAN DAN TIDAK
    TERJADI ERROR */
    List L;
    infotypeDate dataDate;
    infotypeHistory dataHistory;
    int menu,x,y;
    adrDate P,X;
    adrHistory Q;
    string tanggal,parameter,waktu, web;

    createList(L);
    database(L);
    selectMenu();
    cout << "Pilih menu: ";
    cin >> menu;
    while(menu != 0){
        if(menu == 1){
            cout << "Jumlah data hari yang akan ditambahkan: ";
            cin >> x;
            cout << endl;
            int counter1 = 1;
            while(counter1 <= x){
                cout << "[" << counter1 << "]" << endl;
                cout << "Tanggal    : ";
                cin >> tanggal;
                dataDate.tanggal = tanggal;

                cout << "Hari       : ";
                cin >> dataDate.hari;

                X = findDate(L,tanggal);
                if(X != NULL){
                    cout << "Jumlah history yang akan ditambahkan pada hari " << dataDate.hari << ": ";
                    cin >> y;
                    int counter2 = 1;
                    while(counter2 <= y){
                        cout << "Pukul      : ";
                        cin >> dataHistory.time;

                        cout << "Website    : ";
                        cin >> dataHistory.domain;

                        cout << "Judul/Title: ";
                        cin >> dataHistory.title;

                        Q = newElementHistory(dataHistory);
                        insertHistorySecondary(L,Q,X); //tahap ini menghubungkan child ke parent dengan insertFirst
                        cout << endl;
                        counter2++;
                    }
                }else{
                    P = newElementDate(dataDate);
                    insertDate(L,P);

                    cout << "Jumlah history yang akan ditambahkan pada hari " << dataDate.hari << ": ";
                    cin >> y;
                    int counter2 = 1;
                    while(counter2 <= y){
                        cout << "Pukul      : ";
                        cin >> dataHistory.time;

                        cout << "Website    : ";
                        cin >> dataHistory.domain;

                        cout << "Judul/Title: ";
                        cin >> dataHistory.title;

                        Q = newElementHistory(dataHistory);
                        insertHistoryMain(L,Q); //tahap ini menghubungkan child ke parent dengan insertFirst
                        cout << endl;
                        counter2++;
                        }
                }
                counter1++;
            }
            cout << endl;
            cout << "Data history berhasil ditambahkan" << endl;
        }else if(menu == 2){
            cout << "Berikut tanggal dan hari akses history" << endl;
            cout << endl;
            showAllDate(L);
        }else if(menu == 3){
            cout << "Berikut seluruh catatan history" << endl;
            cout << endl;
            showAllData(L);
        }else if(menu == 4){
            cout << "Tanggal yang ingin dihapus: ";
            cin >> tanggal;
            deleteDate(L,tanggal);
        }else if(menu == 5){
            cout << "Tanggal yang ingin dicari: ";
            cin >> tanggal;
            adrDate O = findDate(L,tanggal);
            if(O != NULL){
                cout << "Tanggal terdapat pada catatan history, hari di tanggal tersebut adalah ";
                cout << "hari " << infoDate(O).hari << endl;
            }else{
                cout << "tanggal tidak ditemukan" << endl;
            }
        }else if(menu == 6){
            cout << "Tanggal yang ingin dicari : ";
            cin >> tanggal;
            cout << "Masukkan waktu yang ingin dicari pada tanggal tersebut: ";
            cin >> waktu;
            findSomeHistory(L,tanggal,waktu);
            cout << endl;
        }else if(menu == 7){
            cout << "Tanggal yang ingin history-nya terhapus: ";
            cin >> tanggal;
            deleteHistory(L,tanggal);
        }else if(menu == 8){
            cout << "Tanggal yang ingin dicari: ";
            cin >> tanggal;
            cout << "Jumlah history pada tanggal "<< tanggal << " adalah ";
            cout << SumOfHistory(L,tanggal) << endl;
        }else{
            cout << "Pastikan anda memilih menu yang tersedia!" << endl;
        }
        cout << endl;
        selectMenu();
        cout << "Silakan Pilih Menu Berikutnya: ";
        cin >> menu;
    }
    cout << endl;
    cout << ">>>>> PROGRAM TELAH DI AKHIRI <<<<<" << endl;


    return 0;
}
