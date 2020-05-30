#include<conio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
static int p=0;
class a
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
	void install();
	void allot();
	void empty();
	void show();
	void avail();
	void position(int l);
}bus[10];
void vline(char ch)
{
	for(int i=80;i>0;i--)
	{
		cout<<ch;
	}
}
void a::install()
{
	cout<<"Enter the bus number:";
	cin>>bus[p].busn;
	cout<<"Enter the driver's name:";
	cin>>bus[p].driver;
	cout<<"Enter the arrival time:";
	cin>>bus[p].arrival;
	cout<<"Enter the departure time:";
	cin>>bus[p].depart;
	cout<<"From:";
	cin>>bus[p].from;
	cout<<"To:";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void a::allot()
{
	int seat;
	char number[5];
	top:
	cout<<"Enter bus number:";
	cin>>number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		{
			break;
		}
	}
	while(n<=p)
	{
		cout<<"\nSeat number:";
		cin>>seat;
		if(seat>32)
		{
			cout<<"\nSorry the bus is filled as there are only 32 seats available in this bus.";
		}
		else
		{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
			{
				cout<<"Enter passenger's name:";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
			{
      			cout<<"The seat no. is already reserved.\n";
      		}
      	}
    }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
}
void a::empty()
{
	for(int i=0; i<8;i++)
  	{
    	for(int j=0;j<4;j++)
    	{
      		strcpy(bus[p].seat[i][j], "Empty");
    	}
  	}
}
void a::show()
{
	int n;
  	char number[5];
  	cout<<"Enter bus no: ";
  	cin>>number;
  	for(n=0;n<=p;n++)
  	{
   		 if(strcmp(bus[n].busn, number)==0)
   		 {
    		break;
    	 }
  	}
	while(n<=p)
	{
  		vline('*');
  		cout<<"\nBus no: \t"<<bus[n].busn<<"\nDriver:"<<bus[n].driver<<"\nArrival time:"<<bus[n].arrival<<"\nDeparture time:"<<bus[n].depart<<"\nFrom:"<<bus[n].from<<"\nTo:"<<bus[n].to<<"\n";
  		vline('*');
  		bus[0].position(n);
  		int a=1;
  		for (int i=0; i<8; i++)
  		{
    		for(int j=0;j<4;j++)
    		{
      			a++;
      			if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      			{
      				cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
      			}	
    		}
  		}
 		break;
   }
   if(n>p)
   {
    cout<<"Enter correct bus no: ";
   }
}
void a::avail()
{
	for(int n=0;n<p;n++)
  	{
    	cout<<"\nBus no:"<<bus[n].busn<<"\nDriver:"<<bus[n].driver<<"\nArrival time:"<<bus[n].arrival<<"\nDeparture Time:"<<bus[n].depart<<"\nFrom:"<<bus[n].from<<"\nTo:"<<bus[n].to<<"\n";
    	vline('*');
  	}
}
void a::position(int l)
{
	int s=0;p=0;
  	for (int i =0; i<8;i++)
  	{
    	cout<<"\n";
    	for (int j = 0;j<4; j++)
   		{
      		s++;
      		if(strcmp(bus[l].seat[i][j], "Empty")==0)
        	{
          		cout.width(5);
          		cout.fill(' ');
          		cout<<s<<".";
          		cout.width(10);
          		cout.fill(' ');
          		cout<<bus[l].seat[i][j];
          		p++;
        	}
        	else
        	{
		    	cout.width(5);
		        cout.fill(' ');
		        cout<<s<<".";
		        cout.width(10);
		        cout.fill(' ');
		        cout<<bus[l].seat[i][j];
        	}
    	}
	}
}
int main()
{
	int w;
	while(1)
	{
		  cout<<"\n1.Install\n"<<"2.Reservation\n"<<"3.Show\n"<<"4.Buses Available\n"<<"5.Exit";
		  cout<<"\nEnter your choice:";
		  cin>>w;
  		  switch(w)
  		  {
    		case 1:  bus[p].install();
     				 break;
    		case 2:  bus[p].allot();
     				 break;
    		case 3:  bus[0].show();
      				 break;
    		case 4:  bus[0].avail();
      				 break;
    		case 5:  exit(0);
  	   	  }
	}
	return 0;
}
