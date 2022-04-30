#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	string user,UN;
	int pass,PW;
	char sel;
	
	cout<<"\t=========================="<<endl;
	cout<<"\tWelcome to Best Auto Parts "<<endl;
	cout<<"\t=========================="<<endl;
	
	cout<<"\n l).Loging "<<endl;
	cout<<" s).Signup "<<endl;
	cout<<" e).Exit "<<endl;
		
	cout<<"\n Do you want to logging(l) , signup(s) or exit(e)? ";
	cin>>sel;
	
	
	if(sel=='l' || sel=='L')
	{
		void loging();
		loging();
		
	}
	
	else if(sel=='s' || sel == 'S')
	{
		void signup();
		signup();
	}
	
	else if(sel ='e'|| sel=='E')
	{
		cout<<"\n Thank you "<<endl;
		
	}
	
	else
	{
	cout<<" Error...Please Try Again "<<endl;
		
	}
	
	

	
}



void loging()
{
	char selec;
	
	ifstream userFile;
	userFile.open("Member.txt");
	
	string user,pass,UN,PW;
	
	cout<<"\n Input Username : ";
	cin>>user;
	
	cout<<"\n Input passward : ";
	cin>>pass;
	
	userFile>>UN>>PW;
	
	while(userFile)
	{
		cout<<UN<<endl;
		if( user==UN && pass==PW )
		{
			
			do{
		system("cls");
		cout<<"\n\t=========================="<<endl;
		cout<<"  \tWelcome to System Settings "<<endl;
		cout<<"\t=========================="<<endl;
		
			cout<<"\na. Available list "<<endl;
			cout<<"b. Search "<<endl;
			cout<<"c. Add "<<endl;
			cout<<"d. Delete "<<endl;
			cout<<"e. Update "<<endl;
			cout<<"f. Logout"<<endl;
			cout<<"g. Exit "<<endl;
		
		cout<<"\nPlease press the letter : ";
		cin>>selec;
		
		
			if(selec=='a' || selec=='A')
			{
				cout<<"\n"<<endl;
				cout<<"\n\t===========Available List=============="<<endl;
				void list();
				list();
				
			}
			else if(selec=='b'||selec=='B')
			{
				void search();
				search();
			
				
			}
			else if(selec=='c'||selec=='C')
			{
				void addFinal();
				addFinal();
				
				cout<<"\n\t===========Available List=============="<<endl;
				void list();
				list();
		
			}
			else if(selec=='d'||selec=='D')
			{
				cout<<"\n\t===========Available List=============="<<endl;
				void list();
				list();
				
				void deleteFinal();
				deleteFinal();
				
				cout<<"\n\t===========Available List(After delete)=============="<<endl;
				void list();
				list();
				
			}
			else if(selec=='e'||selec=='E')
			{
				cout<<"\n\t===========Available List=============="<<endl;
				void list();
				list();
				
				void updateFinal();
				updateFinal();
				
				cout<<"\n\t===========Available List(After update)=============="<<endl;
				void list();
				list();
				
			}
			else if(selec=='f'||selec=='F')
			{
				system("cls");
				int main();
				main();
				
			}
			else if(selec=='g'||selec=='G')
			{
				cout<<"\n To exit please press 0...";
			}
			else
			{
				cout<<"\n You entered wrong letter....Please try again... ";
			}
			cout<<"\n"<<endl;
		system("pause");
			
		}while(selec!='g');
			
			
		break;
		
		}
	/*	else
		{
			cout<<"\n User not Found...Please Signup.."<<endl;
			break;
		}*/
		
		userFile>>UN>>PW;
	
	}
		if( user!=UN && pass!=PW )
		{
			cout<<"\n User not Found...Please Signup.."<<endl;
		
		}
	userFile.close();
}

void signup()
{
	ofstream userFile;
	userFile.open("Member.txt",ios::app);
	string user,pass;
	
	cout<<" Input User Name : ";
	cin>>user;
	
	cout<<" Input Password : ";
	cin>>pass;
	
	userFile<<user<<" "<<pass<<endl;
	
		cout<<"\n\tNow you can login....."<<endl;
	
		system("pause");
		system("cls");
		int main();
		main();
	
	userFile.close();
	
}


struct Service
{
	int serviceNo;				//structure for service add,delete,update,print
	int serviceID;
	string serviceName;
	double servicePrice; 
	
	
}; 

void add(ofstream &write)		//write similar to userfile.
{
	Service s1;					//s1 get the object
	
	cout<<"\n\tEnter No:";
	cin>>s1.serviceNo;
	cout<<"\n\tEnter ID :";
	cin>>s1.serviceID;
	cout<<"\n\tEnter name :";
	cin.get();
	getline(cin,s1.serviceName);
	cout<<"\n\tPrice :";
	cin>>s1.servicePrice;
	
	write<<"\n"<<s1.serviceNo<<endl;		//print in file
	write<<s1.serviceID<<endl;
	write<<s1.serviceName<<endl;
	write<<s1.servicePrice<<endl;
	
	
	 
}

Service getData(ifstream &read)		//read also similar to userFile
{
	Service obj;					//obj object
	read>>obj.serviceNo;
	read>>obj.serviceID;
	read.get();
	getline(read,obj.serviceName);
	read>>obj.servicePrice;
	
	return obj;
	
	
}


void printData(Service s)			
{
	cout<<"\n\n\tService/Product :";
	cout<<"\n\tNO : "<<s.serviceNo;
	cout<<"\n\tID : "<<s.serviceID;
	cout<<"\n\tName :"<<s.serviceName;
	cout<<"\n\tPrice :"<<s.servicePrice;
	
	
	
}

void addFinal()				//add file Main
{
	ofstream write("tesla.txt",ios::app);
	cout<<"\n\tEnter Service or Product " ;
	add(write);
	//cout<<"\n\tEnter Service 2" ;
	//add(write);
	//cout<<"\n\tEnter Service 3" ;
	//add(write);
	

	
}

void list()			//print File Main
{
	ifstream read;
	read.open("tesla.txt",ios::in);
	Service s1;
	
	s1= getData(read);
	while(!read.eof())
{
//	s1= getData(read);
	printData(s1);
	s1= getData(read);
}

}

void deleteData(int servNo,ifstream &read)
{
	//we get all data from our file i.e record.txt
	//we have to write data into temp file
	//we have to use rename and remove
	ofstream nf;
	nf.open("temp.txt",ios::out);
	
	cout<<"\n\n input Service/Product No that you want delete:";
	cin>>servNo;
	
	Service s1;
	s1= getData(read);
	while(!read.eof())
	{
		//there we delete the record
		if (s1.serviceNo!=servNo)
		{
		nf<<"\n"<<s1.serviceNo<<endl;
		nf<<s1.serviceID<<endl;
		nf<<s1.serviceName<<endl;
		nf<<s1.servicePrice<<endl;
			
			
		}
		s1= getData(read);
	}
	
	nf.close();	
	read.close();
	
	remove("tesla.txt");
	rename("temp.txt","tesla.txt");
	
}


void deleteFinal() // delete file Main
{
	int servNo;
	
	ifstream read("tesla.txt",ios::in);
	deleteData(servNo,read);
//	cout<<" Serve No :";
//	cin>>servNo;
	
}


void updateData(int servNo,ifstream&read)
{
	ofstream write("temp1.txt");
	
	Service s;
	cout<<"\n\n input Service/Prduct No that you want update:";
	cin>>servNo;
	
	s=getData(read);
	while(!read.eof())
	{
		//update data
		if(s.serviceNo==servNo)
		{
			cout<<"\n\tEnter new record for No :"<<servNo;
			add(write);
		}
		else
		{
			write<<"\n"<<s.serviceNo<<endl;
			write<<s.serviceID<<endl;	
			write<<s.serviceName<<endl;
			write<<s.servicePrice<<endl;
		}
			s=getData(read);
	}
	write.close();
	read.close();
	remove("tesla.txt");
	rename("temp1.txt","tesla.txt");
}

void updateFinal() // update file Main
{
	int servNo;
	
	ifstream read("tesla.txt",ios::in);
	updateData(servNo,read);
//	cout<<" Serve No :";
//	cin>>servNo;
	

}


void search()
{
		ifstream userFile;
	userFile.open("tesla.txt");
	
	int serviceNo,serviceID,servicePrice,inputServNo;
	string serviceName,inputServName;
	bool found = false;

	cout<<" Input Service/Product no. that you want to find : ";
	cin>>inputServNo;
	

	
	userFile>>serviceNo>>serviceID>>serviceName>>servicePrice;
	
	/*userFile>>serviceNo>>serviceID;
	userFile.ignore();
	getline(userFile,serviceName);
	userFile>>servicePrice;*/
	

	
	cout<<"\nService/Product:-"<<endl;
	cout<<left<<setw(15)<<"No."<<setw(15)<<"ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<endl;	

	
	while(userFile)
	{
		//cout<<serviceName;
		if(inputServNo == serviceNo)
		{
			found = true;
			cout<<left<<setw(15)<<serviceNo<<setw(15)<<serviceID<<setw(15)<<serviceName<<setw(15)<<servicePrice<<endl;
			cout<<"\nSearch Found.."<<endl;
		
		//	break;	
		}
		userFile>>serviceNo>>serviceID>>serviceName>>servicePrice;
		
	/*userFile>>serviceNo>>serviceID;
	userFile.ignore();
	getline(userFile,serviceName);
	userFile>>servicePrice;*/
		
		
		
	}
	if(found!=true)	
	cout<<" Error...please try again "<<endl;
		
	}
