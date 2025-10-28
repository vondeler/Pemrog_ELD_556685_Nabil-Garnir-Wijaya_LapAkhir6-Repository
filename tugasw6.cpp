#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
struct Karyawan {
	string nama;
	int umur;
	string nik;
	string jabatan;
	};
int main() {
	int opsi,tambah,temp,hapus;
	string nik;
	bool nemu;
	Karyawan karyawan[1000];
	int count = 0;
	ifstream inputFile("karyawan.txt");
	if (!inputFile) {
	cerr << "Tidak dapat membuka file!" << endl;
	return 1;
	}
	string line;
	while (getline(inputFile, line) && count < 1000) {
	stringstream ss(line);
	ss >> karyawan[count].nama >> karyawan[count].umur >> karyawan[count].nik >> karyawan[count].jabatan;
	count++;
	}
	inputFile.close();
	while (true){
		nemu = false;
		cout<<"[1]Lihat Data Karyawan"<<endl;
		cout<<"[2]Tambah Data Karyawan"<<endl;
		cout<<"[3]Edit Data Karyawan"<<endl;
		cout<<"[4]Hapus Data Karyawan"<<endl;
		cout<<"[0]Keluar"<<endl;
		cout<<"Pilih Menu: ";
		cin>>opsi;
		switch (opsi){
		case 1:
			cout << "Data Karyawan:" << endl;
			for (int i = 0; i < count; i++) {
			cout << "Karyawan " << i + 1 << ":" << endl;
			cout << "Nama: " << karyawan[i].nama << endl;
			cout << "Umur: " << karyawan[i].umur << endl;
			cout << "NIK: " << karyawan[i].nik << endl;
			cout << "Jabatan: " << karyawan[i].jabatan << endl;
			cout << endl; }
			break;
		case 2:
			cout << "Berapakah Karyawan Yang Ingin Anda Tambah: ";
			cin>>tambah;
			temp = count;
			count += tambah;
			cout << "Data Karyawan:" << endl;
			for (temp; temp < count; temp++) {
			cin.ignore();
			cout << "Karyawan " << temp + 1 << ":" << endl;
			cout << "Nama: " ;
			getline(cin,karyawan[temp].nama);
			cout << "Umur: " ;
			cin>>karyawan[temp].umur ;
			cout << "NIK: " ;
			cin>>karyawan[temp].nik ;
			cin.ignore();
			cout << "Jabatan: " ; 
			getline(cin,karyawan[temp].jabatan);
			cout << endl; 
			if (tambah>1){
				cout <<"Tekan Enter Untuk Melanjutkan"<< endl; 
			}
			}
		break;
		case 3: 
		cout<<"Data Siapa Yang Ingin Anda Edit?"<<endl;
		cout<<"Masukan NIK: ";
		cin>>nik;
			for (int i = 0; i < count; i++) {
				if (nik == karyawan[i].nik){
					cin.ignore();
					cout << "Update Data Karyawan " << i + 1 << ":" << endl;
					cout << "Nama: " ;
					getline(cin,karyawan[i].nama);
					cout << "Umur: " ;
					cin>>karyawan[i].umur ;
					cout << "NIK: " ;
					cin>>karyawan[i].nik ;
					cin.ignore();
					cout << "Jabatan: " ; 
					getline(cin,karyawan[i].jabatan);
					cout << endl; 
					nemu = true;
				}
			}
			cout << endl; 
			if (nemu == false){
				cout<<"NIK yang Anda Masukan Tidak Ada"<<endl;
			}
			cout << endl; 
			break;
		case 4:
		cout<<"Data Siapa Yang Ingin Anda Hapus?"<<endl;
		cout<<"Masukan NIK: ";
		cin>>nik;
		hapus = 0;
			for (int i = 0; i < count; i++) {
				if (nik == karyawan[i].nik){
					nemu = true;
					count --;
					continue;
				}
				else{
				karyawan[hapus].nama = karyawan[i].nama; 
				karyawan[hapus].umur = karyawan[i].umur;
				karyawan[hapus].nik = karyawan[i].nik;
				karyawan[hapus].jabatan = karyawan[i].jabatan;
				hapus++;	
				}
			}
			cout << endl; 
			if (nemu == false){
				cout<<"NIK yang Anda Masukan Tidak Ada"<<endl;
			}
			else {
				cout<<"Data Berhasil Dihapus"<<endl;
			}
			cout << endl; 
			break;
		default:
		return 0;
			
		}
	}
}
