#include "Walikota.hpp"

Walikota::Walikota() : Peran() {}

Walikota::Walikota(string username, int row_inv, int col_inv) : 
    Peran(username, row_inv, col_inv) 
    {}

Walikota::Walikota(string username, int berat, int gulden, int row_inv, int col_inv) :
    Peran(username, berat, gulden, row_inv, col_inv)
    {}

Walikota::~Walikota() {}

Walikota& Walikota::operator= (const Walikota &other) {
    Peran::operator=(other);
    return *this;
}

string Walikota::getType() {
    return type;
}

int Walikota::getKekayaan() {
    return this->gulden + this->penyimpanan.getValue();
}

void Walikota::beternakBertani() {
    cout << "Kamu walikota, pekerjaanmu bukan ini!!!" << endl << endl;
}

void Walikota::beternakBertaniFile(string, string, int, vector<Item*>) {}

void Walikota::panen(vector<Produk*>) {
    cout << "Kamu walikota, pekerjaanmu bukan ini!!!" << endl << endl;
}

void Walikota::cetakLahan() {
    cout << "Emangnya kamu punya lahan!!!" << endl << endl;
}

void Walikota::beriMakan() {
    cout << "Emangnya kamu punya hewan???" << endl << endl;
}

void Walikota::addUmurTanaman() {}

int Walikota::calculateTax() {
    return 0;
}

void Walikota::ambilPajak(vector<Peran*> listPeran) {
    cout << endl << "Cring cring cring..." << endl;
    cout << "Pajak sudah di pungut" << endl << endl;
    
    int gulden_pajak = 0;
    int pajak_pemain = 0;
    
    struct detailPajak {
        int pajak;
        string uname;
        string peran;
    };

    vector<detailPajak> detailPajak;
    // mendapatkan semua detail pajak dari pemain
    for (int i = 0; i < listPeran.size(); i++) {
        if (listPeran[i]->getType() != "Walikota") {
            pajak_pemain = listPeran[i]->calculateTax();
            gulden_pajak += pajak_pemain;
            listPeran[i]->tambahGulden(-pajak_pemain);
            detailPajak.push_back({pajak_pemain, listPeran[i]->getUname(), listPeran[i]->getType()});
        }
    }

    // urutkan pajak dari yang terbesar
    for (int i = 0; i < detailPajak.size(); i++) {
        int max = i;
        for (int j = i+1; j < detailPajak.size(); j++) {
            if (detailPajak[j].pajak > detailPajak[max].pajak) {
                max = j;
            } else if (detailPajak[j].pajak == detailPajak[max].pajak) {
                // bandingkan username
                // username terkecil akan diurutkan terlebih dahulu
                if (detailPajak[j].uname < detailPajak[max].uname) {
                    max = j;
                }
            }
        }
        swap(detailPajak[i], detailPajak[max]);
    }

    // cetak pajak
    cout << "Berikut adalah detail dari pemungutan pajak:" << endl;
    for (int i = 0; i < detailPajak.size(); i++) {
        cout << "   " << i+1 << ". ";
        cout << detailPajak[i].uname << " - " << detailPajak[i].peran << " : " << detailPajak[i].pajak << endl;
    }
    // tambahkan pajak ke walikota
    this->tambahGulden(gulden_pajak);
    cout << "Negara mendapatkan pemasukan sebesar " << gulden_pajak << " gulden" << endl;
    cout << "Jangan dikorupsi ya!!!"<< endl << endl;
}

void Walikota::buatUser(vector<Peran*> listPlayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) {
    if (gulden >= 50) {
        string role, uname;
        cout << "Pilih role yang ingin dibuat: ";
        cin >> role;

        if (role == "Petani" || role == "Peternak") {
            cout << endl << "Masukkan username: ";
            gulden -= 50;

            if (role == "Petani") {
                Peran* a = new Petani(uname, row_inv, col_inv, row_farm, col_farm);
                listPlayer.push_back(a);
            }
            else {
                Peran* a = new Peternak(uname, row_inv, col_inv, row_pet, col_pet);
                listPlayer.push_back(a);
            }
            cout << endl;
        }
        else {
            cout << "Role ini tidak bisa dibuat." << endl << endl;
        }
    }
    else {
        cout << "Uang anda tidak cukup Pak Walikota." << endl << endl;
    }
}


// sementara belum
// void Walikota::bangun() {
//     cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
//     cout << "(sementara kosong)" << endl;

//     // memilih bangunan
//     string pilihan_bangunan;
//     cout << "Bangunan yang ingin dibangun: ";
//     cin >> pilihan_bangunan;

//     // sementara blm tau dapetin info angka resep dari mana?
//     int gulden_cost;
//     int teak_wood_cost;
//     int sandalwood_wood_cost;
//     int aloe_wood_cost;
//     int ironwood_wood_cost;

//     // menghitung stok beberapa jenis kayu
//     int teak_wood_stock = 0;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "TAW") {
//                 ++teak_wood_stock;
//             }
//         }
//     }
//     int sandalwood_wood_stock = 0;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "SAW") {
//                 ++sandalwood_wood_stock;
//             }
//         }
//     }
//     int aloe_wood_stock = 0;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "ALW") {
//                 ++aloe_wood_stock;
//             }
//         }
//     }
//     int ironwood_wood_stock = 0;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "IRW") {
//                 ++ironwood_wood_stock;
//             }
//         }
//     }

//     if (gulden < gulden_cost ||
//         teak_wood_stock < teak_wood_cost ||
//         sandalwood_wood_stock < sandalwood_wood_cost ||
//         aloe_wood_stock < aloe_wood_cost ||
//         ironwood_wood_stock < ironwood_wood_cost) {
//         cout << "Kamu tidak punya sumber daya yang cukup!" << endl;
//         return;
//     }

//     // mengurangi sumber daya yang dimiliki
//     gulden -= gulden_cost;
//     int count = 0;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "TAW") {
//                 delete penyimpanan[i][j];
//                 penyimpanan[i][j] = NULL;
//                 ++count;
//             }

//             if (count >= teak_wood_cost) {
//                 break;
//             }
//         }
//     }
//     count = 0;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "SAW") {
//                 delete penyimpanan[i][j];
//                 penyimpanan[i][j] = NULL;
//                 ++count;
//             }

//             if (count >= sandalwood_wood_cost) {
//                 break;
//             }
//         }
//     }
//     count = 0;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "ALW") {
//                 delete penyimpanan[i][j];
//                 penyimpanan[i][j] = NULL;
//                 ++count;
//             }

//             if (count >= aloe_wood_cost) {
//                 break;
//             }
//         }
//     }
//     count = 0;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "IRW") {
//                 delete penyimpanan[i][j];
//                 penyimpanan[i][j] = NULL;
//                 ++count;
//             }

//             if (count >= ironwood_wood_cost) {
//                 break;
//             }
//         }
//     }

//     // menaruh bangunan pada peti penyimpanan
//     int row, col;
//     for (int i = 0; i < penyimpanan.getBaris(); ++i) {
//         for (int j = 0; j < penyimpanan.getKolom(); ++j) {
//             if (penyimpanan[i][j] == NULL) {
//                 row = i;
//                 col = j;
//                 break;
//             }
//         }
//     }
//     int id; // sementara blm tau dapetin info resep dari mana?
//     string kode; // sementara blm tau dapetin info resep dari mana?
//     int harga; // sementara blm tau dapetin info resep dari mana?
//     penyimpanan[row][col] = new Bangunan(id, kode, pilihan_bangunan, harga);
//     cout << pilihan_bangunan << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
// }