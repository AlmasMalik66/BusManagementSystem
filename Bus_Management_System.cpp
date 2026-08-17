#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class bus
{
	private:
		string b_no,b_name,d_name;
		int b_seats;
	public:
		void menu();
		void new_bus();
		void view_bus();
		void single_view_bus();
		void all_view_bus();
		void update_bus();
		void dlt_bus();
		void rout_bus();
		void detail_bus();
		void booking();
		void renew_seats();
		void search_booking();
		void update_booking();
		void delete_booking();
};
 void bus::menu()
 {
 	p:
 	system("cls");
 	int choice;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	cout<<"\n\n 1. ADD BUS RECORD";
 	cout<<"\n 2. VIEW BUS DETAIL";
 	cout<<"\n 3. UPDATE BUS DETAIL";
 	cout<<"\n 4. DELETE BUS DETAIL";
 	cout<<"\n 5. ROUTS OF BUSES";
 	cout<<"\n 6. BUS SEATS DETAILS";
 	cout<<"\n 7. BOOKING RECORDS";
 	cout<<"\n 8. SEATS RENEW";
 	cout<<"\n 9. SEARCH BOOKING RECORDS";
 	cout<<"\n 10. UPDATE BOOKING RECORD";
 	cout<<"\n 11. DELETE BOOKING RECORD";
 	cout<<"\n 12. EXIT";
 	cout<<"\n\n Enter Your Choice : ";
 	cin>>choice;
 	switch(choice) 
	{
    case 1:
    	new_bus();
    	break;
    case 2:
		view_bus();
	    break;
	case 3:
		update_bus();
	    break;
	case 4:
		dlt_bus();
	    break;
	case 5:
		rout_bus();
	    break;
	case 6: 
	    detail_bus(); 
	    break;
	case 7:
		booking();
	    break;
	case 8: 
	    renew_seats();
	    break;
	case 9: 
	    search_booking();
	    break;
	case 10:
	    update_booking();
	    break;
	case 11:
	    delete_booking();
	    break;
	case 12:
	    exit(0);	 									
	default: 
	    cout<<"\n\n INVALID CHOICE...PLEASE TRY AGAIN...";
    }
    getch();
    goto p;
 }
 void bus::new_bus()
 {
 	p:	
 	system("cls");
 	fstream file;
 	string t_no,tb_name,td_name;
 	int t_seats,found=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	cout<<"\n\n Bus No : ";
 	cin>>b_no;
 	cout<<"\n\n Bus Name : ";
 	cin>>b_name;
 	cout<<"\n\n Total Seats : ";
 	cin>>b_seats;
 	cout<<"\n\n Driver Name : ";
 	cin>>d_name;
 	file.open("bus.txt",ios::in);
 	if(!file)
 	{
 		file.open("bus.txt",ios::app|ios::out);
 		file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
 		file.close();
	}
	else
	{
		file>>t_no>>tb_name>>t_seats>>td_name;
		while(!file.eof())
		{
			if(b_no==t_no)
			{
				found++;
			}
			file>>t_no>>tb_name>>t_seats>>td_name;
		}
		file.close();
		if(found==0)
		{
		  file.open("bus.txt",ios::app|ios::out);
 		  file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
 		  file.close();
		}
		else
		{
			cout<<"\n\n Duplicate Record Found...";
			getch();
			goto p;
		}
	}
	cout<<"\n\n New Bus Inserted Successfully...";
 }
 void bus::view_bus()
 {
 	p:
 	system("cls");
 	int choice;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	cout<<"\n\n 1. Single Bus View";
 	cout<<"\n 2. All Buses View";  
 	cout<<"\n 3. Go Back";
 	cout<<"\n\n Enter Your Choice : ";
 	cin>>choice;
 	switch(choice)
 	{
 		case 1:
 			single_view_bus();
 			break;
 		case 2:
 			all_view_bus();
 			break;
 		case 3:
 			menu();
 		default: 
	        cout<<"\n\n INVALID CHOICE...PLEASE TRY AGAIN...";
	}
	getch();
	goto p;
 }
 void bus::single_view_bus()
 {
 	system("cls");
 	string t_no;
 	fstream file; 
 	int found=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	file.open("bus.txt",ios::in);
 	if(!file)
 	{
 	 cout<<"\n\n File Openning Error...";	
	}
	else
	{
     cout<<"\n\n Bus No. : ";
 	 cin>>t_no;
 	 file>>b_no>>b_name>>b_seats>>d_name;
 	 while(!file.eof())
 	 {
 	  if(t_no == b_no)
	   {
	   	system("cls");
	   	cout<<"\n\n BUS NO.\tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
	   	cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
	   	found++;
	   }
      file>>b_no>>b_name>>b_seats>>d_name;
   	 }
   	 file.close();
		if(found==0)
		{
			cout<<"\n\n Invalid Bus No....";
	    }     
	}
 }
 void bus::all_view_bus()
 {
 	system("cls");
 	fstream file;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	file.open("bus.txt",ios::in);
 	if(!file)
 	{
 	 cout<<"\n\n File Openning Error...";	
	}
	else
	{
	 cout<<"\n\n BUS NO.\tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
 	 file>>b_no>>b_name>>b_seats>>d_name;
 	 while(!file.eof())
 	 {
	  cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
      file>>b_no>>b_name>>b_seats>>d_name;
   	 }
   	file.close(); 
	}
 }
 void bus::update_bus()
 {
 	system("cls");
 	fstream file,file1;
 	string t_no,no,t_name,td_name;
 	int t_seats,found=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	file.open("bus.txt",ios::in);
 	if(!file)
 	{
 	 cout<<"\n\n File Openning Error...";
    }
    else
    {
    	cout<<"\n\n Bus No. : ";
    	cin>>t_no;
    	file1.open("bus1.txt",ios::app|ios::out);
    	file>>b_no>>b_name>>b_seats>>d_name;
    	while(!file.eof())
    	{
    		if(t_no == b_no)
    		{
    			cout<<"\n\n New Bus No. : ";
    			cin>>no;
    			cout<<"\n\n Bus Name : ";
    			cin>>t_name;
    			cout<<"No. of Seats : ";
    			cin>>t_seats;
    			cout<<"\n\n Driver Name : ";
    			cin>>td_name;
    			file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<"\n";
    			cout<<"\n\n\n Update Bus Record Successfully...";
    			found++;
			}
			else
			{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
		file>>b_no>>b_name>>b_seats>>d_name;	
		}
		file.close();
		file1.close();
		remove("bus.txt");
		rename("bus1.txt","bus.txt");
		if(found == 0)
		{
			cout<<"\n\n Bus No. is Invalid...";
		}
	}
 }
 void bus::dlt_bus()
 {
 	system("cls");
 	fstream file,file1;
 	string t_no;
 	int found=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	file.open("bus.txt",ios::in);
 	if(!file)
 	{
 	 cout<<"\n\n File Openning Error...";
    }
    else
    {
    	cout<<"\n\n Bus No. : ";
    	cin>>t_no;
    	file1.open("bus1.txt",ios::app|ios::out);
    	file>>b_no>>b_name>>b_seats>>d_name;
    	while(!file.eof())
    	{
    		if(t_no == b_no)
    		{
    			cout<<"\n\n\n Delete Bus Record Successfully...";
    			found++;
			}
			else
			{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
		file>>b_no>>b_name>>b_seats>>d_name;	
		}
		file.close();
		file1.close();
		remove("bus.txt");
		rename("bus1.txt","bus.txt");
		if(found == 0)
		{
			cout<<"\n\n Bus No. is Invalid...";
		}
	}
 }
 void bus::rout_bus()
 {
 	p:
 	system("cls");
 	int choice;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	cout<<"\n\n 1. 1st ROUT DETAILS";
 	cout<<"\n 2. 2nd ROUT DETAILS";
 	cout<<"\n 3. 3rd ROUT DETAILS";
 	cout<<"\n 4. 4th ROUT DETAILS";
 	cout<<"\n 5. 5th ROUT DETAILS";
 	cout<<"\n\n Enter Your Choice: ";
 	cin>>choice;
 	switch(choice )
 	{
 	  case 1:
 	  	system("cls");
 	  	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	  	cout<<"\n  From Sialkot to Lahore";
 	  	cout<<"\n 9:00 am...................... 11:00 am";
 	  	cout<<"\n  From Lahore to Faisalabad";
 	  	cout<<"\n 12:00 pm...................... 12:30 pm";
 	  	cout<<"\n  From Sahiwaal to Bhawalpur";
 	  	cout<<"\n 4:00 am...................... 9:00 am";
 	  	cout<<"\n  From Lahore to Multan";
 	  	cout<<"\n 7:00 am...................... 2:00 pm";
 	  	cout<<"\n  From Islamabad to Murree";
 	  	cout<<"\n 10:00 am...................... 11:30 pm";
 	  	cout<<"\n  From Daska to Lahore";
 	  	cout<<"\n 8:30 am...................... 10:00 pm";
	   break;
	  case 2:
	  	system("cls");
 	  	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
	  	cout<<"\n  From Sialkot to Gujranwala";
 	  	cout<<"\n 9:00 am...................... 10:00 pm";
 	  	cout<<"\n  From Lahore to Kamoki";
 	  	cout<<"\n 12:00 pm...................... 1:00 pm";
 	  	cout<<"\n  From Islamabad to Rawalpindi";
 	  	cout<<"\n 10:00 pm...................... 11:00 pm";
	   break;
	  case 3:
	  	system("cls");
 	  	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
	  	cout<<"\n  From Kamoki to Wazirabad";
 	  	cout<<"\n 8:30 am...................... 9:30 pm";
 	  	cout<<"\n  From Lahore to Gujranwala";
 	  	cout<<"\n 1:00 pm...................... 2:30 pm";
 	  	cout<<"\n  From Murree to New Murree";
 	  	cout<<"\n 4:00 pm...................... 5:30 pm";
 	  	cout<<"\n  From Naran to Nathiya Gali";
 	  	cout<<"\n 7:00 am...................... 12:00 pm";
 	  	cout<<"\n  From Sialkot to Jehlem";
 	  	cout<<"\n 8:00 am...................... 10:00 am";
	   break;
	  case 4:
	  	system("cls");
 	  	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
	  	cout<<"\n  From Rawalpindi to Attock";
 	  	cout<<"\n 1:00 pm...................... 10:00 pm";
 	  	cout<<"\n  From Sialkot to Lahore";
 	  	cout<<"\n 8:00 pm...................... 10:00 pm";
 	  	cout<<"\n  From Lahore to Faisalabad";
 	  	cout<<"\n 11:00 am...................... 1:30 pm";
 	  	cout<<"\n  From Sialkot to Islamabad";
 	  	cout<<"\n 5:00 pm...................... 10:00 pm";
 	  	cout<<"\n  From Lahore to Multan";
 	  	cout<<"\n 6:00 pm...................... 11:00 pm";
 	  	cout<<"\n  From Multan to Gujranwala";
 	  	cout<<"\n 7:30 am...................... 5:00 pm";
 	  	cout<<"\n  From Gujranwala to Sahiwaal";
 	  	cout<<"\n 9:00 am...................... 5:00 pm";
	   break;
	  case 5:
	    system("cls");
 	  	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
	  	cout<<"\n  From Multan to Lahore";
 	  	cout<<"\n 11:00 am...................... 12:00 pm";
 	  	cout<<"\n  From Daska to Islamabad";
 	  	cout<<"\n 11:00 pm...................... 3:30 am";
 	  	cout<<"\n  From Sialkot to Quetta";
 	  	cout<<"\n 9:00 pm...................... 12:00 am";
 	  	cout<<"\n alm From Sialkot to Islamabad";
 	  	cout<<"\n 7:30 am...................... 5:00 am";
	   break;
	  default:
	   cout<<"\n\n Invalid Choice...Please Try Again...";
	   getch();
	   goto p;     	
	}
 }
 void bus::detail_bus()
 {
 	system("cls");
 	fstream file,file1;
 	string t_no,s_b_no,s_no;
 	int count=0,found=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";

 	file.open("bus.txt",ios::in);
 	file1.open("seat.txt",ios::in);
 	if(!file || !file1)
 	{
 		cout<<"\n\n File Openning Error....";
	}
	else
	{
		cout<<"\n\n Bus No. : ";
		cin>>t_no;
		file1>>s_b_no>>s_no;
		while(!file1.eof())
		{
			if(t_no == s_b_no)
			{
				count++;
			}
			file1>>s_b_no>>s_no;
		}
		file1.close();
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no == b_no)
			{
			system("cls");
 	  	    cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
		   	cout<<"\n\n Total No. of Seats : "<<b_seats;
		   	cout<<"\n\n Reserved No. of Seats : "<<count;
		   	cout<<"\n\n Empty No. of Seats : "<<b_seats-count;
		   	found++;
			}
		 file>>b_no>>b_name>>b_seats>>d_name;	
		}
		file.close();
		if(found == 0)
		{
			cout<<"\n\n Bus No. is Invalid...";
		}
	}
 }
 void bus::renew_seats()
 {
 	system("cls");
 	fstream file,file1;
 	string t_no,s_b_no,s_no;
 	int count=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	cout<<"\n\n Bus No. : ";
 	cin>>t_no;
 	file.open("seat.txt",ios::in);
 	if(!file)
 	{
 		cout<<"\n\n No Booking Records Found...";
	}
	else
	{
		file1.open("seat1.txt",ios::app|ios::out);
		file>>s_b_no>>s_no;
		while(!file.eof())
		{
			if(t_no == s_b_no)
			{
				count++;
			}
			else
			{
				file1<<s_b_no<<" "<<s_no<<"\n";
			}
			file>>s_b_no>>s_no;
		}
		file.close();
		file1.close();
		remove("seat.txt");
		rename("seat1.txt","seat.txt");
		if(count == 0)
		{
			cout<<"\n\n No Reserved Seats Found for this Bus...";
		}
		else
		{
			cout<<"\n\n "<<count<<" Seat(s) Renewed Successfully for Bus "<<t_no<<"...";
		}
	}
 }
 void bus::search_booking()
 {
 	system("cls");
 	fstream file;
 	string t_no,s_b_no,s_no;
 	int found=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	cout<<"\n\n Bus No. : ";
 	cin>>t_no;
 	file.open("seat.txt",ios::in);
 	if(!file)
 	{
 		cout<<"\n\n No Booking Records Found...";
	}
	else
	{
		cout<<"\n\n BUS NO.\tSEAT NO.";
		file>>s_b_no>>s_no;
		while(!file.eof())
		{
			if(t_no == s_b_no)
			{
				cout<<"\n "<<s_b_no<<"\t\t"<<s_no;
				found++;
			}
			file>>s_b_no>>s_no;
		}
		file.close();
		if(found == 0)
		{
			cout<<"\n\n No Booking Records Found for this Bus...";
		}
	}
 }
 void bus::update_booking()
 {
 	system("cls");
 	fstream file,file1;
 	string t_no,s_b_no,s_no,old_seat,new_seat;
 	int found=0,clash=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	cout<<"\n\n Bus No. : ";
 	cin>>t_no;
 	cout<<"\n\n Old Seat No. : ";
 	cin>>old_seat;
 	cout<<"\n\n New Seat No. : ";
 	cin>>new_seat;
 	file.open("seat.txt",ios::in);
 	if(!file)
 	{
 		cout<<"\n\n No Booking Records Found...";
 		return;
	}
	file>>s_b_no>>s_no;
	while(!file.eof())
	{
		if(t_no == s_b_no && new_seat == s_no)
		{
			clash++;
		}
		file>>s_b_no>>s_no;
	}
	file.close();
	if(clash > 0)
	{
		cout<<"\n\n New Seat No. is Already Reserved...";
		return;
	}
	file.open("seat.txt",ios::in);
	file1.open("seat1.txt",ios::app|ios::out);
	file>>s_b_no>>s_no;
	while(!file.eof())
	{
		if(t_no == s_b_no && old_seat == s_no)
		{
			file1<<s_b_no<<" "<<new_seat<<"\n";
			found++;
		}
		else
		{
			file1<<s_b_no<<" "<<s_no<<"\n";
		}
		file>>s_b_no>>s_no;
	}
	file.close();
	file1.close();
	remove("seat.txt");
	rename("seat1.txt","seat.txt");
	if(found == 0)
	{
		cout<<"\n\n Booking Record Not Found...";
	}
	else
	{
		cout<<"\n\n Booking Record Updated Successfully...";
	}
 }
 void bus::delete_booking()
 {
 	system("cls");
 	fstream file,file1;
 	string t_no,s_b_no,s_no,d_seat;
 	int found=0;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	cout<<"\n\n Bus No. : ";
 	cin>>t_no;
 	cout<<"\n\n Seat No. : ";
 	cin>>d_seat;
 	file.open("seat.txt",ios::in);
 	if(!file)
 	{
 		cout<<"\n\n No Booking Records Found...";
	}
	else
	{
		file1.open("seat1.txt",ios::app|ios::out);
		file>>s_b_no>>s_no;
		while(!file.eof())
		{
			if(t_no == s_b_no && d_seat == s_no)
			{
				found++;
			}
			else
			{
				file1<<s_b_no<<" "<<s_no<<"\n";
			}
			file>>s_b_no>>s_no;
		}
		file.close();
		file1.close();
		remove("seat.txt");
		rename("seat1.txt","seat.txt");
		if(found == 0)
		{
			cout<<"\n\n Booking Record Not Found...";
		}
		else
		{
			cout<<"\n\n Booking Record Deleted Successfully...";
		}
	}
 }
 void bus::booking()
 {
 	p:
 	system("cls");
 	fstream file;
 	int found=0,s_no,seats,count=0,s_s_no,ss_no[25],i=0;
 	char x;
 	string t_no,s_b_no;
 	cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
 	file.open("bus.txt",ios::in);
 	if(!file)
 	{
 	  cout<<"\n\n File Openning Error....";	
	}
	else 
	{
		cout<<"\n\n Bus No. : ";
		cin>>t_no;
		file.close();
		file.open("seat.txt",ios::in);
		if(file)
		{
			file>>s_b_no>>s_s_no;
			while(!file.eof())
			{
				if(t_no == s_b_no)
				{
					count++;
				}
				file>>s_b_no>>s_s_no;
			}
			file.close();
	    }
		file.open("bus.txt",ios::in);
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof())
		{
			if(t_no == b_no)
			{
				seats = b_seats;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}file.close();
		if(seats-count == 0)
		{
			cout<<"\n\n All Seats is Already Reserved....";
		}
		else if(found == 1)
		{
			do
			{
				h:
				cout<<"\n\n Seat No. : ";
				cin>>s_no;
				if(s_no > seats)
				{
					cout<<"\n\n Seat No. is Invalid...Please Try Again...";
					goto h;
				}
				file.open("seat.txt",ios::in);
				if(!file)
				{
					file.open("seat.txt",ios::app|ios::out);
					file<<t_no<<" "<<s_no<<"\n";
					file.close();
				}
				else
				{
					file>>s_b_no>>s_s_no;
					while(!file.eof())
					{
						if(t_no == s_b_no && s_no == s_s_no)
						{
							cout<<"\n\n Seat is Already Reserved...Please Try Again...";
							goto h;
						}
						file>>s_b_no>>s_s_no;
					}
					file.close();
					file.open("seat.txt",ios::app|ios::out);
					file<<t_no<<" "<<s_no<<"\n";
					file.close();
				}
				ss_no[i] = s_no;
				i++; 
				cout<<"\n\n Booking Another Seat (Y,N) : ";
				cin>>x;
			}while(x == 'Y'||x == 'y' );
			system("cls");
			cout<<"\n\t\t_BUS MANAGEMENT SYSTEM_";
			
			
			
			
			
			
			
	   }
		else
		{
			cout<<"\n\n Bus No. is Invalid...Please Try Again...";
			getch();
			goto p;
		}
	}
 }
int main()
{
	bus b;
	p:
	system("cls");
	string email,pass;
	char ch;
	cout<<"\n\n\t\t\t**Security Are Required";
    cout<<"\n\n Email :  ";
    cin>>email;
    cout<<"\n\n Password : ";
    while(true)
    {
    	ch = getch();
    	if(ch == 13) break;
    	if(ch == 8)
    	{
    		if(pass.length() > 0)
    		{
    			pass.pop_back();
    			cout<<"\b \b";
			}
    		continue;
		}
    	pass += ch;
    	cout<<"*";
	}
	if(email == "admin@busmanagement.com" && pass == "admin1")
	{
		cout<<"\n\n\n\t\t\tLoading";
		for(int i=1;i<=5;i++)
		{ 
		cout<<".";
		}
		b.menu();
	}
	else
	{
		cout<<"\n\n\t\tYour Email & Password Wrong...";
		getch();
		goto p;
	}
	return 0;
}