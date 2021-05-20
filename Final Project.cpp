#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
		char name[20],pass[15];
	float pr; int quant;

public:
	void get();
	int show();
    void withd(int qty);
}st;
void stock::withd(int qty)
{
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<pr*qty;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();
		
	
}


void stock::get()
{
	cin>>name>>pr>>quant;
	
	
}


int stock::show()
{
	
	cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
	return quant*pr;
}
void addnew()
{
 	getch();
	
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
	
    
    if (n!=0)
    {
	
	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	
	{

		cout<<"\n\nInput the name, price and the quantity of item respectively\n\n";
	   	 st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nitem updated";
		cin.get();
		
		


    }
    cout<<"\n\nStock Updated!!";
    

    fout.close();
    cin.get();
    system("cls");
    disp();

    
}

	else
{

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";

}

}




void disp()
{
	int i=1,total=0;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tList of Products\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPRODUCT\t\t\tQUANTITY\t\t\t PRICE";
	cout<<"\n\n============================================================\n";	
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     total+=st.show();
	     
	  }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\t!!Empty record room!!";
	getch();
     }
     cout<<"\nTotal price to be paid: " <<total<<endl;
     fin.close();
    
}


int main(){
	int id,quant;
	char a;
	cout <<"Online Grocery Store"<<endl;
		cout<<"1. Sugar Per Kg Rs 105 "<<endl;
		cout<<"2. Mitchell's Jam Golden Apple 450g Rs 155.00 "<<endl;
		cout<<"3. Mitchell's Jam Apple Tin 1050g Rs 299.00 "<<endl;
		cout<<"4. Dollar Note Blue Ball Pen 0.7mm 10pcs Rs 199.00 "<<endl;
		cout<<"5. Italiano Cardamom Powder 30g Rs 399.00 "<<endl;
		cout<<"6. Dalda Banaspati Tin 2.5Kg Rs 775.00 "<<endl;
		cout<<"7. Cloves Spices 50gm Rs 88.00 "<<endl;
		cout<<"8. Long Grain Rice 1kg Rs 179.00"<<endl;
		cout<<"9. Super Basmati Rice 5kg Rs 675.00"<<endl;
		cout<<"10. Facemask KN-95 With Filter Blue Color 1pcs Rs 55.00 "<<endl;
		cout<<"11. Medicam Toothpaste Dental Cream 65g Rs 100.00 "<<endl;
		cout<<"12. Appollo Crisper Food Container Small… Rs 229.00 "<<endl;
		cout<<"13. Dollar Staples#10 Rs 50.00 "<<endl;
		cout<<"14. NESTLE EVERYDAY Powder Tea… Rs 550.00 "<<endl;
		cout<<"15. Dettol Hand Sanitizer Original 50ml Rs 240.00 "<<endl;
		cout<<"16. Sunridge Fortifide Chakki Aata 5kg Rs 360.00 "<<endl;
		cout<<"17. So Good! Tartar Sauce Gluten Free… Rs 269.00 "<<endl;
		cout<<"18. Dawn Family Paratha 20 Pcs 1600g Rs 399.00 "<<endl;
		cout<<"19. Hersheys Strawberry 35g Rs 229.00 "<<endl;
		addnew();	
}
