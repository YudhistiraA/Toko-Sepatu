
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	 double /*MieAyam, Bakso, */ jumlah_menu_MieAyam, jumlah_menu_Bakso, diskon, bayar, kembalian, 
	    total_hrg_MieAyam, total_hrg_Bakso, harga_menu1, harga_menu2, total_pembayaran, hrg1=20000, hrg2=18000;
	    
	    cout<<"====================================================="<<endl;
	    cout<<">> TOKO SMK MEDIA INFORMATIKA <<"<<endl;
	    cout<<">> Jl. Papan I/Pisangan Kretek No. 99 <<"<<endl;
	    cout<<">> TELP.(021)22704966 Kode Pos 12260 <<"<<endl;
	    cout<<endl;
	    cout<<"Nama		: Canaia Tsabitah"<<endl;
	    cout<<"Nis		: 2122067"<<endl;
	    cout<<"Kelas	: XII RPL 2 "<<endl;
	    cout<<endl;
	    cout<<"====================================================="<<endl;
	    
	    //Paket
	    
	    cout<<"Menu Mie Ayam	:"<<endl;
	    cout<<"1. Mie ayam Spesial"<<endl;
	    cout<<"2. Es Teh"<<endl;
	    cout<<endl;
	    cout<<"Menu Bakso	:"<<endl;
	    cout<<"1. Bakso Spesial"<<endl;
	    cout<<"2. Es Teh"<<endl;
	    cout<<"====================================================="<<endl;
	    cout<<endl;
	    
	    //jumlah paket 
	    
	    cout<<"Masukkan jumlah pembelian untuk menu mie ayam :" ;
	    cin>>jumlah_menu_MieAyam;
	    cout<<"harga paket menu mie ayam : Rp."<<hrg1<<endl;
	    
	    //cin>>jumlahmenumieayam
	    
	    harga_menu1=hrg1*jumlah_menu_MieAyam;
	    cout<<"harga menu Mie ayam = Rp."<<harga_menu1<<endl;
	    cout<<endl;
	    
	    cout<<"Masukan jumlah pembelian untuk menu Bakso :";
	    cin>>jumlah_menu_Bakso;
	    cout<<" Harga paket menu Bakso = Rp."<<hrg2<<endl;
	    //cin>>Bakso;
	    harga_menu2=hrg2*jumlah_menu_Bakso;
	    cout<<" Total harga menu Bakso = Rp."<<harga_menu2<<endl;
	    
	    //Menu Mie Ayam
	    {
	    	if(jumlah_menu_MieAyam>=5&&jumlah_menu_MieAyam<10)
	    	{
	    		diskon=harga_menu1*5/100;
	    		total_hrg_MieAyam=harga_menu1-diskon;
	    		cout<<endl;
	    		cout<<"total harga mie ayam : Rp."<<harga_menu1<<"* 5% = Rp."<<total_hrg_MieAyam<<endl;
			}
			else if(jumlah_menu_MieAyam>=10)
			{
				diskon=harga_menu1*10/100;
				total_hrg_MieAyam=harga_menu1-diskon;
				cout<<endl;
				cout<<"total harga mie ayam : Rp."<<harga_menu1<<"* 10% = Rp."<<total_hrg_MieAyam<<endl;
			}
			else
			{
				total_hrg_MieAyam=harga_menu1;
				cout<<endl;
				cout<<"total pembayaran mie ayam ="<<total_hrg_MieAyam<<endl;
				cout<<"pembelian ini tidak mendapatkan diskon"<<endl;
				cout<<endl;
			}
		}
		
		//menu bakso
		{
			if(jumlah_menu_Bakso>=5&&jumlah_menu_Bakso<10)
			{
				diskon=harga_menu2*5/100;
				total_hrg_Bakso=harga_menu2-diskon;
				cout<<endl;
				cout<<"total harga bakso : Rp."<<harga_menu2<<"* 5% = Rp."<<total_hrg_Bakso<<endl;
			}
			else if(jumlah_menu_Bakso>=10)
			{
				diskon=harga_menu2*10/100;
				total_hrg_Bakso=harga_menu2-diskon;
				cout<<endl;
				cout<<"total harga bakso : Rp."<<harga_menu2<<"* 10% = Rp."<<total_hrg_Bakso<<endl;
			}
			else
			{
				total_hrg_Bakso=harga_menu2;
				cout<<endl;
				cout<<"total pembayaran bakso ="<<total_hrg_Bakso<<endl;
				cout<<"pembelian ini tidak mendapatkan diskon"<<endl;
				cout<<endl;
			}
			cout<<"==================================================================="<<endl;
		}
		
		//total;
		
		cout<<endl;
		total_pembayaran=total_hrg_MieAyam+total_hrg_Bakso;
		cout<<"total semua yang harus dibayar = Rp. "<<total_pembayaran<<endl;
		cout<<"uang pembayaran : Rp.";
		cin>>bayar;
		kembalian=bayar-total_pembayaran;
		cout<<"uang kembalian = Rp."<<kembalian;
		
	    
	    
}
