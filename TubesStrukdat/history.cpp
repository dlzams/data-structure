#include "history.h"

void createList(List &L){
/* terbentuk sebuah list baru kosong */
    first(L) = NULL;
}

adrDate newElementDate(infotypeDate x){
/* membuat element baru date(parent), dimasukan sebuah infotype
F.S keluaran berupa address date */
    adrDate P = new elmDate;
    infoDate(P) = x;
    nextCH(P) = NULL;
    nextDate(P) = NULL;
    return P;
}

adrHistory newElementHistory(infotypeHistory x){
/* membuat element baru history(child), dimasukan sebuah infotype
F.S keluaran berupa address history */
    adrHistory P = new elmHistory;
    infoHistory(P) = x;
    nextHistory(P) = NULL;
    return P;
}

bool isEmpty(List L){
/* keluaran true jika list kosong,
dan sebaliknya */
    adrDate P = first(L);
    if(P == NULL){
        return true;
    }else{
        return false;
    }
}

void insertDate(List &L,adrDate P){
/* list mungkin kosong, insert first,
F.S list date terisi element baru */
    adrDate Q = first(L);
    if(Q != NULL){
        nextDate(P) = first(L);
        first(L) = P;
    }else{
        first(L) = P;
    }
}

void showAllDate(List L){
/* list mungkin kosong,
F.S menampilkan seluruh data tanggal (parent) jika ada */
    adrDate P = first(L);
    if(P != NULL){
        while(P != NULL){
            cout << "Tanggal    : " << infoDate(P).tanggal << endl;
            cout << "Hari       : " << infoDate(P).hari << endl;
            cout << endl;
            P = nextDate(P);
            cout << endl;
        }
    }else{
        cout << "history kosong" << endl;
    }
}

void deleteDate(List &L, string tanggal){
/* list mungkin kosong,
F.S data tanggal beserta history-nya akan hilang jika ditemukan */
    adrDate P,Prec/*,A*/;
    adrDate X = findDate(L,tanggal);
    if(!isEmpty(L)){
        if(X != NULL){
            P = first(L);
            if(nextDate(P) == NULL){
                /* list berisi 1 element, delete first */
                if(infoDate(P).tanggal == infoDate(X).tanggal){
                    Prec = P;
                    first(L) = NULL;
                    cout << endl;
                    cout << "data tanggal berhasil terhapus" << endl;
                }else{
                    cout << "history tidak ditemukan" << endl;
                }
            }else if(P == X){
                /* list berisi banyak element, tetapi tanggal ditemukan pada first(L), delete first */
                Prec = first(L);
                first(L) = nextDate(Prec);
                nextDate(Prec) = NULL;
                cout << "data tanggal berhasil terhapus" << endl;
            }else{
                /* list berisi banyak element, delete after */
                while(nextDate(P) != X){
                    P = nextDate(P);
                }
                Prec = nextDate(P);
                nextDate(P) = nextDate(Prec);
                nextDate(Prec) = NULL;
                cout << "data tanggal berhasil terhapus" << endl;
            }
        }else{
        cout << "tanggal atau history tidak ditemukan" <<endl;
        }
    }else{
        cout << "history kosong" << endl;
    }
}

adrDate findDate(List L, string tanggal){
/* mengembalikan address date jika ketemu,
jika tidak mengembalikan NULL */
    adrDate P = first(L);
    if(P != NULL){
        while(P != NULL){
            if(infoDate(P).tanggal == tanggal){
                return P;
            }
            P = nextDate(P);
        }
    }else{
        P = NULL;
        return P;
    }
}

adrHistory findHistory(List L, string tanggal, string time){
/* mengembalikan address history jika ketemu,
jika tidak mengembalikan NULL */
    adrDate X = findDate(L,tanggal);;
    adrHistory result;
    if(!isEmpty(L) && X != NULL){
        result = nextCH(X);
        if(result != NULL){
            while(result != NULL){
                if(infoHistory(result).time == time){
                    return result;
                }
                result = nextHistory(result);
            }
        return result;
        }else{
            return result;
        }
    }
}

void insertHistoryMain(List &L, adrHistory P){
/* list tidak kosong, insert first pada history(child)
F.S list history terisi alamat baru */
    adrDate Prec = first(L);
    if(nextCH(Prec) == NULL){
        nextCH(Prec) = P;
    }else{
        nextHistory(P) = nextCH(Prec);
        nextCH(Prec) = P;
    }
}

void insertHistorySecondary(List &L, adrHistory P, adrDate X){
/* list tidak kosong, insert first pada tanggal yang sudah ada
F.S list history terisi alamat baru */
    if(nextCH(X) == NULL){
        nextCH(X) = P;
    }else{
        nextHistory(P) = nextCH(X);
        nextCH(X) = P;
    }
}

void showAllData(List L){
/* list mungkin kosong, menampilkan seluruh data tanggal dan historynya, jika ada */
    int i = 1;
    adrDate P = first(L);
    if(!isEmpty(L)){
        while(P != NULL){
            cout << "Data ke-" << i << endl;
            cout << "Tanggal    : " << infoDate(P).tanggal << endl;
            cout << "Hari       : " << infoDate(P).hari << endl << endl;
            cout << "---==Catatan History==---" << endl ;
            if(nextCH(P) == NULL){
                    cout << "tidak ada catatan history pada tanggal " << infoDate(P).tanggal << endl;
            }else{
                adrHistory child = nextCH(P);
                while(child != NULL){
                    cout << "Pukul  : " << infoHistory(child).time << endl;
                    cout << "Title  : " << infoHistory(child).title << endl;
                    cout << "Web    : " << infoHistory(child).domain << endl;
                    cout  << endl;
                    child = nextHistory(child);
                }
            }
            cout << endl << endl;
            P = nextDate(P);
            i++;
        }
    }else{
        cout << "history kosong" << endl;
    }
}

void findSomeHistory(List L, string tanggal, string time){
/* list mungkin kosong, mencari data history pada tanggal tertentu, searching berdasarkan time,
F.S jika ditemukan mengembalikan address history */
    int i = 1;
    bool counter = false;
    adrDate X = findDate(L,tanggal);
    adrDate P = first(L);
    adrHistory Y;
    if(P != NULL && X != NULL){
        Y = nextCH(X);
        while(Y != NULL){
            if(infoHistory(Y).time == time){
                cout << "Berikut isi dari history yang dicari: " << endl;
                cout << "Waktu      : " << infoHistory(Y).time << endl;
                cout << "Website    : " << infoHistory(Y).domain << endl;
                cout << "Judul      : " << infoHistory(Y).title << endl;
                cout << "History terdapat diurutan ke-" << i << " pada tanggal tersebut" <<  endl;
                counter = true;
            }
            i++;
            Y = nextHistory(Y);
        }
        P = nextDate(P);
        if(counter == false){
            /*jika tanggal ada tetapi history tidak ada */
            cout << "history pada pukul tersebut tidak ditemukan" << endl;
            }
    }else{
        cout << "history tidak ditemukan" << endl;
    }
}

void deleteHistory(List &L, string tanggal){
/* list mungkin kosong, catatan history pada tanggal tertentu akan menjadi kosong */
    adrDate X = findDate(L,tanggal);
    adrDate P = first(L);
    if(P != NULL){
        if(X != NULL){
            nextCH(X) = NULL;
            cout << "history berhasil terhapus" << endl;
        }else{
            cout << "tanggal tidak ditemukan" << endl;
        }
    }else{
        cout << "history kosong" << endl;
    }
}

int SumOfHistory(List L, string tanggal){
/* list mungkin kosong, mengembalikan jumlah dari history yang diakses pada tanggal tertentu */
    int jmlHistory = 0;
    adrDate P = first(L);
    adrDate X = findDate(L,tanggal);
    adrHistory Y;
    if(P != NULL && X != NULL){
        while(P != NULL){
            Y = nextCH(P);
            if(infoDate(P).tanggal == infoDate(X).tanggal){
                while(Y != NULL){
                    Y = nextHistory(Y);
                    jmlHistory++;
                }
                return jmlHistory;
            }
            P = nextDate(P);
        }
    }else{
        return jmlHistory;
    }
}

void selectMenu(){
    cout << "======================================= M E N U =======================================" << endl;
    cout << "[1] Menambah N hari data history baru" << endl;
    cout << "[2] Menampilkan semua data tanggal dan hari akses history saja" << endl; //Menampilkan parent saja
    cout << "[3] Menampilkan semua data tanggal dan hari akses history beserta catatan history-nya" << endl; //Menampilkan parent dan child
    cout << "[4] Menghapus data tanggal akses history" << endl; //Menghapus data parent saja
    cout << "[5] Mencari tanggal tertentu pada history" << endl;
    cout << "[6] Mencari history tertentu pada tanggal tertentu berdasarkan waktu akses" << endl;
    cout << "[7] Menghapus history pada tanggal tertentu" << endl;
    cout << "[8] Menampilkan total history yang diakses pada tanggal tertentu" << endl;
    cout << "[0] Exit Program" << endl;
    cout << "=======================================================================================" << endl;
}

void database(List &L){
    adrDate P;
    adrHistory Q;
    infotypeDate x;
    infotypeHistory y;

//HISTORY KE-1
    x.hari = "Selasa";
    x.tanggal = "1/11/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "08:15";
    y.domain = "google.com";
    y.title = "TheBiggestCityInTheWorld?";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "11:09";
    y.domain = "instagram.com";
    y.title = "@telkomuniversity";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "13:32";
    y.domain = "google.com";
    y.title = "HowToSleepWell";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "20:02";
    y.domain = "google.com";
    y.title = "WhereIsTelkomUniversity?";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-2
    x.hari = "Rabu";
    x.tanggal = "2/11/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "03:11";
    y.domain = "youtube.com";
    y.title = "Murrotal";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "06:01";
    y.domain = "youtube.com";
    y.title = "DzikirPagi";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-3
    x.hari = "Sabtu";
    x.tanggal = "5/11/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "09:06";
    y.domain = "twitter.com";
    y.title = "@elonmusk";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "11:34";
    y.domain = "google.com";
    y.title = "KlasemenLigaInggris";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "11:45";
    y.domain = "google.com";
    y.title = "WorldCup2022Winner?";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "13:09";
    y.domain = "instagram.com";
    y.title = "@leomessi";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "14:21";
    y.domain = "twitter.com";
    y.title = "Explore";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "14:23";
    y.domain = "twitter.com";
    y.title = "Trending";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-4
    x.hari = "Minggu";
    x.tanggal = "6/11/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "13:01";
    y.domain = "lms.telkomuniversity.ac.id";
    y.title = "StrukturData";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "13:15";
    y.domain = "lms.telkomuniversity.ac.id";
    y.title = "StrukturData-Tree";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "14:12";
    y.domain = "lms.telkomuniversity.ac.id";
    y.title = "MatematikaRuangVektor";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "17:09";
    y.domain = "lms.telkomuniversity.ac.id";
    y.title = "MatematikaRuangVektor-Kuis";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-5
    x.hari = "Senin";
    x.tanggal = "14/11/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "13:22";
    y.domain = "meet.google.com/aaa-aaa-aaa";
    y.title = "GoogleMeet";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "17:01";
    y.domain = "meet.google.com/bbb-bbb-bbb";
    y.title = "GoogleMeet";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "19:10";
    y.domain = "youtube.com";
    y.title = "GadgetIn";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-6
    x.hari = "Jumat";
    x.tanggal = "25/11/2022";
    P = newElementDate(x);
    insertDate(L,P);

//HISTORY KE-7
    x.hari = "Selasa";
    x.tanggal = "29/11/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "08:53";
    y.domain = "igracias.telkomuniversity.ac.id";
    y.title = "Nilai";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "11:00";
    y.domain = "igracias.telkomuniversity.ac.id";
    y.title = "InputTAK";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-8
    x.hari = "Senin";
    x.tanggal = "5/12/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "09:20";
    y.domain = "stackoverflow";
    y.title = "HowToLearnJS";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "09:41";
    y.domain = "stackoverflow";
    y.title = "ErrorInJS";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "13:11";
    y.domain = "youtube.com";
    y.title = "HowToLearnJS";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-9
    x.hari = "Sabtu";
    x.tanggal = "17/12/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "21:59";
    y.domain = "tokopedia.com";
    y.title = "Transaksi";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "23:31";
    y.domain = "tokopedia.com";
    y.title = "Wishlist";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-10
    x.hari = "Rabu";
    x.tanggal = "21/12/2022";
    P = newElementDate(x);
    insertDate(L,P);

//HISTORY KE-11
    x.hari = "Sabtu";
    x.tanggal = "24/12/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "14:29";
    y.domain = "olx.com";
    y.title = "MobilBekas";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "15:19";
    y.domain = "olx.com";
    y.title = "ToyotaAlphard";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "17:46";
    y.domain = "olx.com";
    y.title = "Ferrari";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-12
    x.hari = "Sabtu";
    x.tanggal = "31/12/2022";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "19:01";
    y.domain = "google.com";
    y.title = "AkhirTahundiBandung";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "21:23";
    y.domain = "google.com";
    y.title = "PetasanBerisik";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-13
    x.hari = "Senin";
    x.tanggal = "2/1/2023";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "18:01";
    y.domain = "lms.telkomuniversity.ac.id";
    y.title = "StrukturData-Tubes";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

    y.time = "19:11";
    y.domain = "lms.telkomuniversity.ac.id";
    y.title = "StrukturData-Grades";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);

//HISTORY KE-14
    x.hari = "Jumat";
    x.tanggal = "6/1/2023";
    P = newElementDate(x);
    insertDate(L,P);

    y.time = "09:42";
    y.domain = "google.com";
    y.title = "DzikirPenenangTubes";
    Q = newElementHistory(y);
    insertHistoryMain(L,Q);
}
