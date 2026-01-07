#include <iostream>
using namespace std;

int main() {
    int jumlahPemilih;

    cout << "=== Voting Bubur ===" << endl;
    cout << "1. Bubur aduk" << endl;
    cout << "2. Bubur tidak diaduk" << endl;
    cout << "Masukkan jumlah pemilih:";
    cin >> jumlahPemilih;

    int suara[jumlahPemilih];
    int aduk = 0, tidakdiaduk = 0;

    for (int i =0; i < jumlahPemilih; i++ ) {
        cout << "Pemilih ke-" << i + 1 << "pilihan (1/2)";
        cin >> suara[i];

    if (suara[i] == 1) {
        aduk++;
    } else if (suara[i] == 2) {
        tidakdiaduk++;
    } else { 
        cout << "Pilihan tidak valid. suara tidak dihitung!." << endl;
    }
}

    cout << "Hasil Voting:" << endl;
    cout << "Bubur diaduk: " << aduk << "suara" << endl;
    cout << "Bubur tidak diaduk: " << tidakdiaduk << "suara" << endl;

    if (aduk > tidakdiaduk) {
        cout << "TIM bubur diaduk menang" << endl;
    } else if (tidakdiaduk > aduk) {
        cout << "TIM bubur tidak diaduk menang" << endl;
    } else {  
    cout << "Hasil seri!" << endl;
    }

    return 0;
}