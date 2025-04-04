#include<iostream>
#include<ctime>
using namespace std;
class ATM
{
	private:
		string name,address,location;
		double accountnum,balance;
	public:
		ATM(string n,string a,string l,double accno,double b)
		{
			name = n;
			address = a;
			location = l;
			accountnum = accno;
			balance = b;
		}
		void display()
		{
			cout<<"\n The name of account holder is = "<<name;
			cout<<"\n The address of account holder's is = "<<address;
			cout<<"\n The location of branch is = "<<location;
			cout<<"\n Account number = "<<accountnum;
			cout<<"\n-------------------------------------------------------";
		}
		void displayhelp()
		{
			cout << "\n************* HELP SCREEN *************" ;
			cout<<"\nYou must Enter the correct pin number to access the Account.";
            cout<<"\nSee your Bank representative for more assistance during bank opening hours.";
			cout<<"\nThanks for your choice Today !! \n";
		}
		void checkbalance()
		{
			cout<<"\n Your account balance is = "<<balance<<endl;
		}
		void deposit(double deposit)
		{
			if(deposit>0)
			{
				balance = balance + deposit;
				cout<<"\n Your balance after deposit is = "<<balance<<endl ;
			}
			else
			{
				cout<<"\nIncurrect value ! ";
			}

		}
		void withdraw(double withdraw)
		{
			if(balance>withdraw && withdraw>0)
			{
				balance = balance-withdraw;
				cout<<"\n Your balance after withdraw is = "<<balance<<endl;
			}
			else
			{
				cout<<"\nIncurrect value ! ";	
			}
		}
};
int main()
{
	double pin = 12345,deposit,withdraw;
	int choice,count;
	cout << "******** WELCOME TO ATM ********" ;
	time_t tt=time(0);
	char*dt=ctime(&tt);
	cout<<"\nCurrent date and time = "<<dt;
	ATM a1("Dhruv Patel","Ahmedabad","Gujrat",1234,60000);
	start:        
	cout << "1. Access your Account" ;
    cout << "\n2. Help" ;
	cout<<  "\nEnter The choice = ";
	cin>>choice;
	switch(choice)
	{
		
	case 1:
	{
		double atmpin;
		cout<<"\nEnter the pin(Default pin is = 12345 ) ";
        	cout<<"\nonly one attampt allowed";
        	cout<<"\nATM pin = ";
		cin>>atmpin;
			
		if(pin == atmpin)
		{
			menu:
			cout <<"\n*********** ATM MENU ***********" ;
			cout<<"\n 1. Check balance";
			cout<<"\n 2. deposit";
			cout<<"\n 3. withdraw";
			cout<<"\n 4. exit";
			cout<<"\n Enter The choice = ";
			cin>>choice;
			switch(choice)
			{
				case 1 :
				{
					a1.display();
					a1.checkbalance();
					break;
				}
				case 2 :
				{
					a1.display();
					a1.checkbalance();
					cout<<"\nEnter the amount you want to deposit = ";
					cin>>deposit;
					a1.deposit(deposit);
					break;
				}
				case 3 :
				{
					a1.display();
					a1.checkbalance();					
					cout<<"\nEnter the amount you want to withdraw = ";
					cin>>withdraw;
					a1.withdraw(withdraw);
					break;
				}
                                case 4 :
				{
					cout<<"Exiting...";
					goto end;
					break;
				}
				default:
				{
					cout<<"Invalid choice";
				}
			}
		}
		else
		{
			cout<<"Your Attamped failed !! No more attamped allowed !!";
			break;
		}
			goto menu;		
		}
        case 2:
		{
			a1.displayhelp();
			goto start;
			break;
		}
		default:
		{
			cout<<"Invalid choice!";
		}
	}
end:
	return 0;
}
