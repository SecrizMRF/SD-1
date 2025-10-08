#include <iostream> //Library standar c++
#include <vector>   // library untuk pake vector
using namespace std;    //biar input output ga ribet

void merge(vector<int>& arr, int left, int mid, int right) {    //fungsi untuk mengurutkan nantinya (dari besar ke kecil)
   
    int n1 = mid - left + 1;   //nanti bakal nyimpan berapa jumlah ruas kiri
    int n2 = right - mid;       //kalau ini ruas kanan nya

    vector<int> L(n1), R(n2);   //mendeklarasi vektor bertipe integer dengan nama L sebanyak n1 dan R sebanyak n2 

    for (int i = 0; i < n1; i++)    ///perulangan dari 0 hingga n1 - 1
        L[i] = arr[left + i];       //mengisikan nilai ruas kiri, mulai dari index 0 dari ruas tersebut
    for (int j = 0; j < n2; j++)    //perulangan dari 0 hinga n2 - 1
        R[j] = arr[mid + 1 + j];    //mengisikan nilai ruas kanan, mulai dari index 0 dari ruas tersebut

    int i = 0;  //deklarasi var i = 0
    int j = 0;  //deklarasi var j = 0
    int k = left;   //menyamakan nilai var k sama dengan nilai left

    while (i < n1 && j < n2) {  //perulangan dengan kondisi selama nilai i < banyak ruas kiri dan j < banyak ruas kanan
        if (L[i] <= R[j]) {     //kondisi jika nilai array ruas kiri dengan index i kurang dari sama dengan nilai array ruas kanan dengan index j
            arr[k] = L[i];      //mengubah nilai var arr dengan index k = nilai L[i]
            i++;                //increament var i
        } else {    //kalau dia ga memenuhi kondisi if, lari ke sini
            arr[k] = R[j];      //mengubah nilai var arr denhan index k = nilai R[j]
            j++;                //increament var j
        }
        k++;           //increament var k
    }

    while (i < n1) {    //perulangan dengan kondisi selama nilai var i kurang dari nilai n1
        arr[k] = L[i];  //mengubah nilai var arr dengan index k = nilai L[i]
        i++;            //increament var i
        k++;            //increament var k
    }

    while (j < n2) {    //perulangan dengan kondisi selama nilai var j  kurang dari nilai n2
        arr[k] = R[j];  //mengubah nilai var arr dengan index k = nilai R[j]
        j++;            //increament var j
        k++;            //increament var k
    }       
}

// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) { //fungsi rekursif untuk membagi array menjadi ruas kanan dan kiri
   
    if (left >= right)  //kondisi jika nilai left lebih dari sama dengan nilai right
        return; //direturn langsung, keluar dari fungsi

    int mid = left + (right - left) / 2; //menghitung nilai mid, untuk cari tengah dari sebuah array

    mergeSort(arr, left, mid);  //manggil fungsi mergeSort lagi (rekursif) dengan parameter arr, left dan mid
    mergeSort(arr, mid + 1, right); //rekursif dengan parameter arr, mid+1 dan right
   
    merge(arr, left, mid, right);   //manggil fungsi merge dengan parameter arr, left, mid, right dengan tujuan untuk mengurutkan nilai array
}

void printArray(const vector<int>& arr) {   //untuk menampilkan hasil array
    for (int i = 0; i < arr.size(); i++) {  //perulangan mulai dari 0-ukuran array - 1, agar sesuai dengan index dari array
        cout << arr[i] << " ";  //membarikan output berupa angka dalam array dengan index i, kemudian diberikan spasi
    }
    cout << endl;   //enter, biar kebawah, biar estetik, biar rapih, biar ga beserak kaya demokrasi suatu negara
}

int main() {
    int n;  //deklarasi variabel n bertipe integer
    cout << "Masukkan jumlah elemen data: ";    //output biasa, biar user ga tebengong
    cin >> n;   //meminta inputan user yg akan disimpan dalam var n
   
    vector<int> data(n);    // membuat vektor bertipe integer dengan nama data sebanyak n
    cout << "Masukkan elemen-elemen data: ";    //output biasa lagi
    for (int i = 0; i < n; i++) {   //perulangan sampai sejumlah n
        cin >> data[i];     //meminta inputan dari user yang akan dimasukkan ke dalam array sebanyak n
    }
   
    cout << "Array sebelum diurutkan: ";    //output biasa
    printArray(data);   //memanggil fungsi printArray untuk menampilkan array
   
    mergeSort(data, 0, n - 1);  //memanggil fungsi mergeSort untuk memulai mengurutkan array
   
    cout << "Array setelah diurutkan: ";    //output biasa.. again
    printArray(data);   //memanggil fungsi printArray untuk menampilkan array
   
    return 0;   //nandain kalau program udah berhasil dijalankan
}