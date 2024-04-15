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

Peran* Walikota::buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_lahan, int col_lahan, int row_ternak, int col_ternak) {
    if (gulden >= 50) {
        string role, uname;
        cout << "Pilih role yang ingin dibuat: ";
        cin >> role;

        if (role == "Petani" || role == "Peternak") {
            cout << endl << "Masukkan username: ";
            cin >> uname;
            // cek apakah username telah digunakan
            for (int i = 0; i < listplayer.size(); i++) {
                if (listplayer[i]->getUname() == uname) {
                    cout << "Username telah digunakan!" << endl << endl;
                    return NULL;
                }
            }

            gulden -= 50;
            if (role == "Petani") {
                Peran* a = new Petani(uname, row_inv, col_inv, row_lahan, col_lahan);
                return a;
            }
            else {
                Peran* a = new Peternak(uname, row_inv, col_inv, row_ternak, col_ternak);
                return a;
            }
            cout << endl;
        }
        else {
            cout << "Role ini tidak bisa dibuat." << endl << endl;
            return NULL;
        }
    }
    else {
        cout << "Uang anda tidak cukup Pak Walikota." << endl << endl;
        return NULL;
    }
}

void Walikota::bangun(vector<Bangunan *> listbangunan) {
    // menampilkan resep bangunan
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    cout << "   1. SMALL_HOUSE (teak wood " 
         << listbangunan[0]->getTeakWoodCost() 
         << ", sandal wood " 
         << listbangunan[0]->getSandalwoodWoodCost()
         << ")" 
         << endl;
    cout << "   2. MEDIUM_HOUSE (aloe wood " 
         << listbangunan[1]->getAloeWoodCost()
         << ", ironwood wood " 
         << listbangunan[1]->getIronwoodWoodCost()
         << ")" 
         << endl;
    cout << "   3. LARGE_HOUSE (teak wood " 
         << listbangunan[2]->getTeakWoodCost()
         << ", aloe wood " 
         << listbangunan[2]->getAloeWoodCost()
         << ", ironwood wood " 
         << listbangunan[2]->getIronwoodWoodCost()
         << ")" 
         << endl;
    cout << "   4. HOTEL (teak wood " 
         << listbangunan[3]->getTeakWoodCost()
         << ", aloe wood " 
         << listbangunan[3]->getAloeWoodCost()
         << ", ironwood wood " 
         << listbangunan[3]->getIronwoodWoodCost()
         << ", sandal wood " 
         << listbangunan[3]->getSandalwoodWoodCost()
         << ")" 
         << endl;

    // memilih bangunan
    string pilihan_bangunan;
    cout << "Bangunan yang ingin dibangun: ";
    cin >> pilihan_bangunan;

    // cek keberadaan resep bangunan
    bool resep_exist = false;
    int index_listbangunan = 0;
    while (index_listbangunan < listbangunan.size() && !resep_exist) {
        if (listbangunan[index_listbangunan]->getNama() == pilihan_bangunan) {
            resep_exist = true;
        } else {
            ++index_listbangunan;
        }
    }
    if (!resep_exist) {
        throw BangunTidakAdaResepBangunanException();
    }

    // mengambil data biaya bahan-bahan bangunan
    int teak_wood_cost = listbangunan[index_listbangunan]->getTeakWoodCost();
    int sandalwood_wood_cost = listbangunan[index_listbangunan]->getSandalwoodWoodCost();
    int aloe_wood_cost = listbangunan[index_listbangunan]->getAloeWoodCost();
    int ironwood_wood_cost = listbangunan[index_listbangunan]->getIronwoodWoodCost();

    // mengambil data stok bahan-bahan bangunan
    int teak_wood_stock = 0;
    for (int i = 0; i < penyimpanan.getBaris(); ++i) {
        for (int j = 0; j < penyimpanan.getKolom(); ++j) {
            if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "TAW") {
                ++teak_wood_stock;
            }
        }
    }
    int sandalwood_wood_stock = 0;
    for (int i = 0; i < penyimpanan.getBaris(); ++i) {
        for (int j = 0; j < penyimpanan.getKolom(); ++j) {
            if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "SAW") {
                ++sandalwood_wood_stock;
            }
        }
    }
    int aloe_wood_stock = 0;
    for (int i = 0; i < penyimpanan.getBaris(); ++i) {
        for (int j = 0; j < penyimpanan.getKolom(); ++j) {
            if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "ALW") {
                ++aloe_wood_stock;
            }
        }
    }
    int ironwood_wood_stock = 0;
    for (int i = 0; i < penyimpanan.getBaris(); ++i) {
        for (int j = 0; j < penyimpanan.getKolom(); ++j) {
            if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "IRW") {
                ++ironwood_wood_stock;
            }
        }
    }

    // mengecek kecukupan sumber daya yang dimiliki
    if (teak_wood_stock < teak_wood_cost ||
        sandalwood_wood_stock < sandalwood_wood_cost ||
        aloe_wood_stock < aloe_wood_cost ||
        ironwood_wood_stock < ironwood_wood_cost) {
        throw BangunSumberDayaTidakCukupException();
    }

    // mengurangi sumber daya yang dimiliki
    int count = 0;
    for (int i = 0; i < penyimpanan.getBaris(); ++i) {
        for (int j = 0; j < penyimpanan.getKolom(); ++j) {
            if (count >= teak_wood_cost) {
                break;
            }
            
            if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "TAW") {
                delete penyimpanan[i][j];
                penyimpanan[i][j] = NULL;
                ++count;
            }
        }
    }
    count = 0;
    for (int i = 0; i < penyimpanan.getBaris(); ++i) {
        for (int j = 0; j < penyimpanan.getKolom(); ++j) {
            if (count >= sandalwood_wood_cost) {
                break;
            }

            if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "SAW") {
                delete penyimpanan[i][j];
                penyimpanan[i][j] = NULL;
                ++count;
            }
        }
    }
    count = 0;
    for (int i = 0; i < penyimpanan.getBaris(); ++i) {
        for (int j = 0; j < penyimpanan.getKolom(); ++j) {
            if (count >= aloe_wood_cost) {
                break;
            }

            if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "ALW") {
                delete penyimpanan[i][j];
                penyimpanan[i][j] = NULL;
                ++count;
            }
        }
    }
    count = 0;
    for (int i = 0; i < penyimpanan.getBaris(); ++i) {
        for (int j = 0; j < penyimpanan.getKolom(); ++j) {
            if (count >= ironwood_wood_cost) {
                break;
            }

            if (penyimpanan[i][j] != NULL && penyimpanan[i][j]->getKode() == "IRW") {
                delete penyimpanan[i][j];
                penyimpanan[i][j] = NULL;
                ++count;
            }
        }
    }

    // menaruh bangunan pada peti penyimpanan
    int id = listbangunan[index_listbangunan]->getID();
    string kode = listbangunan[index_listbangunan]->getKode();
    string nama = listbangunan[index_listbangunan]->getNama();
    int harga = listbangunan[index_listbangunan]->getHarga();
    map<string, int> bahan_baku;
    bahan_baku.insert({"TEAK_WOOD", listbangunan[index_listbangunan]->getTeakWoodCost()});
    bahan_baku.insert({"SANDALWOOD_WOOD", listbangunan[index_listbangunan]->getSandalwoodWoodCost()});
    bahan_baku.insert({"ALOE_WOOD", listbangunan[index_listbangunan]->getAloeWoodCost()});
    bahan_baku.insert({"IRONWOOD_WOOD", listbangunan[index_listbangunan]->getIronwoodWoodCost()});
    
    addPenyimpananInFirstEmpty(new Bangunan(id, kode, nama, harga, bahan_baku));
    cout << pilihan_bangunan << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
}

vector<vector<string>> Walikota::getDataLahan() {}

void Walikota::membeli(Toko* toko) {
    toko->cetakListBarang();
    int noBarang;
    int kuantitas;
    cout << "\nUang Anda : " << gulden << endl;
    cout << "Slot Penyimpanan tersedia : " << penyimpanan.getLahanKosong() << endl;
    cout << "Barang ingin dibeli : "; 
    cin >> noBarang;
    cout << "\nKuantitas : ";
    cin >> kuantitas;
    
    // handle error beli bangunan
    if (toko->getListBarang()[noBarang-1]->getTipe() == "BANGUNAN") {
        throw WalikotaTidakBisaBeliBangunanException();
    }
    
    
    Item* item = toko->jual(noBarang, kuantitas);
    if(this->getGulden() < item->getHarga()*kuantitas) {
        cout << "Uang yang anda miliki tidak cukup" << endl;
    }
    else {
        penyimpanan.print();
        for(int i = 0; i < kuantitas; i++) {
            string location;
            cout << "Masukkan lokasi untuk item ke-" << i << endl;
            cin >> location;
            vector<int> index = parse(location);
            penyimpanan.setElement(index[1], index[0], item);
        }
    }
}


void Walikota::menjual(Toko* toko){
    cout << "Berikut merupakan penyimpanan Anda\n";
    printPenyimpanan();
    int ulang;
    int total = 0;
    cout << "Berapa benda yang ingin anda jual: ";
    cin >> ulang;

    for(int i = 0; i < ulang; i++) {
        cout << "Silahkan pilih petak yang ingin Anda jual!\nPetak : ";
        string indeksinvent;
        cin >> indeksinvent;
        vector<int> idx = parse(indeksinvent);
        Item* barang;
        barang = penyimpanan[idx[1]][idx[0]];
    
        toko->beli(barang);
        gulden = gulden + barang->getHarga();
        total += barang->getHarga();
        penyimpanan[idx[1]][idx[0]] = NULL;
    }
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah "<< total << " gulden!\n";
}

void Walikota::simpan(vector<Peran*> list_pemain){
    string file_path;
    cout << "Masukkan lokasi berkas state : ";
    cin >> file_path;
    size_t pos = file_path.find_last_of("/");
    string namaFolder = file_path.substr(0, pos);

    struct stat info;
    if (stat(namaFolder.c_str(), &info) != 0 || !(info.st_mode & S_IFDIR))
    {
        throw FolderTidakAdaException();
    }

    ofstream outfile(file_path);

    if (!outfile.is_open())
    {
        throw FilePathTidakValid();
    }

    int banyak_pemain = list_pemain.size();

    outfile << banyak_pemain << endl;

    for (int i = 0; i < banyak_pemain; i++)
    {
        outfile << list_pemain[i]->getUname() << " " << list_pemain[i]->getType() << " " << to_string(list_pemain[i]->getBerat()) << " " << to_string(list_pemain[i]->getGulden()) << endl;

        int banyak_di_penyimpanan = (list_pemain[i]->getPenyimpanan().getBaris() * list_pemain[i]->getPenyimpanan().getKolom()) - list_pemain[i]->getPenyimpanan().getLahanKosong();

        outfile << banyak_di_penyimpanan << endl;

        for (int j = 0; j < list_pemain[i]->getPenyimpanan().getBaris(); j++)
        {
            for (int k = 0; k < list_pemain[i]->getPenyimpanan().getKolom(); k++)
            {
                if (list_pemain[i]->getPenyimpanan()[j][k] != NULL)
                {
                    outfile << list_pemain[i]->getPenyimpanan()[j][k]->getNama() << endl;
                }
            }
        }

        if (list_pemain[i]->getType() == "Peternak")
        {
            int banyak_ternak = list_pemain[i]->getBanyakItemLahan();

            outfile << banyak_ternak << endl;

            vector<vector<string>> temp = list_pemain[i]->getDataLahan();
            for (int j = 0; j < temp.size(); j++){
                outfile << temp[j][0] << " " << temp[j][1] << " " << temp[j][2] << endl;
            }
        }

        if (list_pemain[i]->getType() == "Petani"){
            int banyak_tandur = list_pemain[i]->getBanyakItemLahan();

            outfile << banyak_tandur << endl;

            vector<vector<string>> temp = list_pemain[i]->getDataLahan();
            for (int j = 0; j < temp.size(); j++){
                outfile << temp[j][0] << " " << temp[j][1] << " " << temp[j][2] << endl;
            }
        }
    }
    outfile.close();
}

int Walikota::getRowLahan(){
    return -1;
}

int Walikota::getKolLahan(){
    return -1;
}

int Walikota::getBanyakItemLahan(){
    return -1;
}