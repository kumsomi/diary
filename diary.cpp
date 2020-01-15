#include<iostream>
#include<fstream>
//#include<process>
#include<stdio.h>
#include<string.h>
#include<conio.h>
using namespace std;
class diary
{
	int ddate,mdate,cdate,fdate,dm,mm,cm,fm;
	int dy,my,cy,fy,ndate,nm,ny;
	char mname[20],flike[20],fdlike[20];
	char like[20],dlike[20],mniname[20],niname[20];
	char diary[100],note[50];
	char fname[20];

public:
	void mpro()
	{
		cout<<"\n\nEnter your name: ";
		cin>>mname;
		cout<<"\nDate of Birth: ";
		cin>>mdate>>mm>>my;
		cout<<"\nEnter your likes:";
		cin>>like;
		cout<<"\nDislikes:";
		cin>>dlike;
		cout<<"\nEnter your nick name: ";
		cin>>mniname;
	}

	void mdisplay()
	{
		cout<<"\n\nYour Profile\n\n";
		cout<<"\nName: "<<mname;
		cout<<"\nDOB: "<<mdate<<"\t"<<mm<<" "<<my;
		cout<<"\nLikes: "<<like;
		cout<<"\nDislikes: "<<dlike;
		cout<<"\nNike Name: "<<mniname;
		cout<<"\n\n";
	}

	void fpro()
	{
		cout<<"\n\nEnter name: ";
		cin>>fname;
		cout<<"\nDOB: ";
		cin>>fdate>>fm>>fy;
		cout<<"\nNick name: ";
		cin>>niname;
		cout<<"\nLikes: ";
		cin>>flike;
		cout<<"\nDislikes :";
		cin>>fdlike;
	}

	void fdisplay()
	{
		cout<<"\n\nFriends Profile\n\n";
		cout<<"\nName: "<<fname;
		cout<<"\nDOB: "<<fdate<<"\t"<<fm<<"\t"<<fy;
		cout<<"\nLikes :"<<flike<<"\nDislikes :"<<fdlike;
	}

	void wdiary()
	{
		cout<<"\n\nEnter the date";
		cin>>ddate>>dm>>dy;
		cout<<"\nWrite your diary";
		cin>>diary;
	}

	void rdiary()
	{
		cout<<"\n\nYour diary\n";
		cout<<diary;
	}

	int getd()
	{
		return(ddate);
	}

	void wnote()
	{
		cout<<"\n\nEnter the event date\n";
		cin>>ndate>>nm>>ny;
		cout<<"\nEnter the event";
		gets(note);
	}

	void dnote()
	{
		cout<<"\n\nThe event is\n";
		puts(note);
	}

	int getnd()
	{
		return(ndate);
	}

	char* getnm()
	{
		return(fname);
	}
};

int main()
{

	diary d;
	int pass,ch,dd,nd;
	int found=0;
	cout<<"\n\n			WELCOME	       \n";
	cout<<"			   to	       \n";
	cout<<"		    Your Daily Diary   \n";
	cout<<"\n*****************************************************************";
	cout<<"\n		    Daily Diary CS Project By:-";
	cout<<"\n		     	*  Aayesha Bano		XII-C";
	cout<<"\n			*  Amisha Kumari	XII-C";
	cout<<"\n			*  Kum Somi		XII-C";
	cout<<"\n\nEnter the password: ";
	cin>>pass;
	ifstream fin;
	ofstream fout;
	if(pass==1301)
	{    for(;;)
	     {	cout<<"\nEnter your choice: ";
		cout<<"\n1.Write Your profile \n2.Read Your profile";
		cout<<"\n3.Write Friends Profile \n4.Read Friends profile";
		cout<<"\n5.Write Diary \n6.Read Diary \n7.Write Event";
		cout<<"\n8.Read Event \n9.Delete friends profile \n10.Delete Event \n11.Exit \nChoice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:		d.mpro();
					fout.open("mpro.txt",ios::binary);
					fout.write((char*)&d,sizeof(d));
					cout<<"\nRecord Written";
					fout.close();
					break;

			case 2:         fin.open("mpro.txt",ios::in|ios::binary);
					while(fin.read((char*)&d,sizeof(d)))
					{
						d.mdisplay();
					}
					fin.close();
					break;

			case 3:		d.fpro();
					fout.open("fpro.txt",ios::app|ios::binary);
					fout.write((char*)&d,sizeof(d));
					cout<<"\nRecord written";
					fout.close();
					break;

			case 4:		fin.open("fpro.txt",ios::in|ios::binary);
					while(fin.read((char*)&d,sizeof(d)))
					{
						d.fdisplay();
					}
					fin.close();
					break;

			case 5:         cout<<"Enter todays date";
					d.wdiary();
					fout.open("diary.txt",ios::app|ios::binary);
					fout.write((char*)&d,sizeof(d));
					cout<<"\nDiary written";
					fout.close();
					break;

			case 6:         cout<<"\nEnter the date";
					cin>>dd;
					fin.open("diary.txt",ios::in|ios::binary);
					while(fin.read((char*)&d,sizeof(d)))
					{
						if(d.getd()==dd)
						{
							cout<<"\nFound Record\n";
							d.rdiary();
						}
						else
							cout<<"\nNot found";
					}
					fin.close();
					break;

			case 7:         d.wnote();
					fout.open("event.txt",ios::app|ios::binary);
					fout.write((char*)&d,sizeof(d));
					cout<<"\nEvent written";
					fout.close();
					break;

			case 8:         cout<<"\nEnter the date: ";
					cin>>nd;
					fin.open("note.txt",ios::in|ios::binary);
					while(fin.read((char*)&d,sizeof(d)))
					{
						if(d.getnd()==nd)
						{
							cout<<"\nFound event";
							d.dnote();
						}
						else
							cout<<"\nNo event found on this date";
					}
					fin.close();
					break;

			case 9:         fin.open("fpro.txt",ios::in|ios::binary);
					fout.open("fprof.txt",ios::out|ios::binary);
					char* dname; 
					//int found=0;
					cout<<"\n Enter the name of the profile to be deleted :";
					cin>>dname;
					while(fin.read((char*)&d,sizeof(d)))
					{
						if(strcmp(d.getnm(),dname)!=0)
						{
							fout.write((char*)&d,sizeof(d));
						}
						else
							found=1;
					}
					fin.close();
					fout.close();
					remove("fpro.txt");
					cout<<"\nContent Deleted";
					rename("fprof.txt","fpro.txt");
					remove("fprof.txt");
					if(found==1)
						cout<<"Database not found";
					break;
			default:	
				exit(0);
		}
	     }
	}
	else
		exit(0);
	return 0;
}
