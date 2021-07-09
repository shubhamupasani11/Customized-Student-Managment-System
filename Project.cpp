/*Project:Customised Student Managment Sytsem...

student Information:
	Student Roll No.
	Student Name:
	Student marks:
	
In this project we are going to develop Linked List(Singly Circular) to find out/update/delete a particular info of student..
To store the data permenantly we have to write data  by using File handling operation..
*/
#include<iostream>
#include<stdio.h>
#include <cstring>
using namespace std;

//Student structure with typedef..members:RollNo,StudentName,next as pointer to store the address of next node..
typedef struct Student
{
	int RollNo;
	char Name[50];
	int Marks;
	struct Student *next;
}NODE,*PNODE;

//////////////////////////////////////////////////////
//class StudentMS
//head and tail pointer are taken as characterastics which is pointing to first node and last node respectively.
//////////////////////////////////////////////////////
class StudentMS
{
	private:                       //Access Specifier
		PNODE head;
		PNODE tail;
		int isize;
	public:                        //Access Specifier
		StudentMS()                //Constructor
		{
			head=NULL;
			tail=NULL;
			isize=0;
		}
	//function members(Behaviours) declaration
	void InsertFirst(int,char[],int);
	void InsertLast(int,char[],int);
	void InsertAtPos(int,char[],int,int);
	void DeleteAtFirst();
	void DeleteAtLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
	void DisplayMarksAbove90();
	void DisplayParticularStudent(int);
	int MaxMarks();
	int MinMarks();
	int AvgMarks();
	int CountMarksAbove90();
	void Result();
	void Update(int,int);
};
//Function Definations
////////////////////////////////////////////////////////////////////////
//Function Name:    InsertFirst
//Function Date:    13/05/2021
//Function Author:  Shubham Upasani
//Paramters:        RollNo,Name,marks
//Description:      It is used to insert at first position
//Returns:    		None
/////////////////////////////////////////////////////////////////////////

void StudentMS::InsertFirst(int rn,char brr[],int score)
{
	
	PNODE newn=NULL;
	newn=new NODE;
	newn->RollNo=rn;
	strcpy(newn->Name,brr);
	newn->Marks=score;
	newn->next=NULL;
	
	if((head==NULL)&&(tail==NULL))
	{
		head=newn;
		tail=newn;
	}
	else
	{
		newn->next=head;
		head=newn;
		tail->next=head;
	}
	isize++;
}

////////////////////////////////////////////////////////////////////////
//Function Name:    InsertLast
//Function Date:    13/05/2021
//Function Author:  Shubham Upasani
//Paramters:        RollNo,Name,marks
//Description:      It is used to insert at last position
//Returns:    		None
/////////////////////////////////////////////////////////////////////////

void StudentMS::InsertLast(int rn,char brr[],int score)
{
	PNODE newn=NULL;
	newn=new NODE;
	newn->RollNo=rn;
	strcpy(newn->Name,brr);
	newn->Marks=score;
	newn->next=NULL;
	if((head==NULL)&&(tail==NULL))
	{
		head=newn;
		tail=newn;
		isize++;
	}
	else
	{
		tail->next=newn;
		tail=newn;
		tail->next=head;
	}
	isize++;
}
////////////////////////////////////////////////////////////////////////
//Function Name:    InsertAtPos
//Function Date:    13/05/2021
//Function Author:  Shubham Upasani
//Paramters:        RollNo,Name,marks,Position
//Description:      It is used to insert at given position 
//Returns:    		None
/////////////////////////////////////////////////////////////////////////

void StudentMS::InsertAtPos(int rn,char arr[],int score,int ipos)
{
	PNODE temp=head;
	PNODE newn=new NODE;
	newn->Marks=score;
	strcpy(newn->Name,arr);
	newn->RollNo=rn;
	newn->next=NULL;
	
	if(ipos==1)
	{
		InsertFirst(rn,arr,score);
	}
	else if(ipos==isize+1)
	{
		InsertLast(rn,arr,score);
	}
	else
	{
		int i=0;
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		isize++;
	}
}
////////////////////////////////////////////////////////////////////////
//Function Name:    DeleteAtFirst
//Function Date:    13/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to delete the first student 
//Returns:    		None
/////////////////////////////////////////////////////////////////////////

void StudentMS::DeleteAtFirst()
{
	if(isize==0)
	{
		return;
	}
	else if(isize==1)
	{
		delete head;
		head=tail=NULL;
		isize--;
	}
	else
	{
		PNODE temp=head;
		head=head->next;
		tail->next=head;
		delete temp;
		isize--;
	}
}
////////////////////////////////////////////////////////////////////////
//Function Name:    DeleteAtLast
//Function Date:    13/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to delete the last student 
//Returns:    		None
/////////////////////////////////////////////////////////////////////////

void StudentMS:: DeleteAtLast()
{
	if(isize==0)
	{
		return;
	}
	else if(isize==1)
	{
		delete head;
		head=tail=NULL;
		isize--;
	}
	else
	{
		PNODE temp=head;
		for(int i=1;i<isize-1;i++)
		{
			temp=temp->next;
		}
		delete temp->next;
		tail=temp;
		tail->next=head;
		isize--;
	}
}
////////////////////////////////////////////////////////////////////////
//Function Name:    DeleteAtPos
//Function Date:    13/05/2021
//Function Author:  Shubham Upasani
//Paramters:        Position
//Description:      It is used to delete the student at given position
//Returns:    		None
/////////////////////////////////////////////////////////////////////////

void StudentMS::DeleteAtPos(int ipos)
{
	if((ipos<1)||(ipos>isize+1))
	{
		return;
	}
	if(ipos==1)
	{
		DeleteAtFirst();
	}
	else if(ipos==isize)
	{
		DeleteAtLast();
	}
	else
	{
		PNODE target=NULL;
		PNODE temp=head;
		for(int i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		delete target;
		isize--;
	}
}
////////////////////////////////////////////////////////////////////////
//Function Name:    Display
//Function Date:    14/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to Display whole students information 
//Returns:    		None
/////////////////////////////////////////////////////////////////////////

void StudentMS::Display()
{
	int i=0;
	PNODE temp=head;
	cout<<"RollNo"<<"\t"<<"StudentName"<<"\t"<<"Marks"<<"\t";
	cout<<"\n";
	for(i=1;i<=isize;i++)
	{
		cout<<temp->RollNo<<"\t"<<temp->Name<<"\t"<<"\t"<<temp->Marks<<"\t";
		temp=temp->next;
		cout<<"\n";
	}
	cout<<"\n";
}

////////////////////////////////////////////////////////////////////////
//Function Name:    Count
//Function Date:    14/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to delete the first student 
//Returns:    		count of total number of students
/////////////////////////////////////////////////////////////////////////

int StudentMS::Count()
{
	return isize;
}

////////////////////////////////////////////////////////////////////////
//Function Name:    DisplayParticularStudent
//Function Date:    14/05/2021
//Function Author:  Shubham Upasani
//Paramters:        RollNo
//Description:      It is used to display particular student of given roll number
//Returns:    		None
////////////////////////////////////////////////////////////////////////

void StudentMS::DisplayParticularStudent(int rn)
{
	//particular student by roll number
	PNODE temp=head;
	for(int i=1;i<=isize;i++)
	{
		if((temp->RollNo)==rn)
		{
			cout<<"RollNo:"<<temp->RollNo<<"\t"<<"StudentName:"<<temp->Name<<"\t"<<"marks:"<<"\t"<<temp->Marks<<"\t";
			break;
		}
		cout<<"\n";
		temp=temp->next;
		cout<<"\n";
	}
	cout<<"\n";
}
////////////////////////////////////////////////////////////////////////
//Function Name:    DisplayMarksAbove90
//Function Date:    15/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to Display students who got Marks Above 90 
//Returns:    		None
////////////////////////////////////////////////////////////////////////

void StudentMS:: DisplayMarksAbove90()
{
	//Display Students marks greater than 90...
	PNODE temp=head;
	for(int i=1;i<=isize;i++)
	{
		if((temp->Marks)>90)
		{
			cout<<"RollNo:"<<temp->RollNo<<"\t"<<"Marks:"<<temp->Marks;
			
		}
		cout<<"\n";
		temp=temp->next;
	}
}
////////////////////////////////////////////////////////////////////////
//Function Name:    CountMarksAbove90
//Function Date:    15/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to calculates students who got Marks Above 90 
//Returns:    		count
////////////////////////////////////////////////////////////////////////

int StudentMS::CountMarksAbove90()
{
	int icnt=0;
	PNODE temp=head;
	for(int i=1;i<=isize;i++)
	{
		if((temp->Marks)>90)
		{
			icnt++;
		}
		temp=temp->next;
	}
	return icnt;
}
////////////////////////////////////////////////////////////////////////
//Function Name:   MaxMarks
//Function Date:    15/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to return max marks among all the students
//Returns:    		max marks
////////////////////////////////////////////////////////////////////////

int StudentMS::MaxMarks()
{
	PNODE temp=head;
	int iret=0;
	iret=temp->Marks;
	for(int i=1;i<=isize;i++)
	{
		if((temp->Marks)>iret)
		{
			iret=temp->Marks;
		}
		temp=temp->next;
	}
	return iret;
}
////////////////////////////////////////////////////////////////////////
//Function Name:   MinMarks
//Function Date:    15/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to return min marks among all the students
//Returns:    		min marks
////////////////////////////////////////////////////////////////////////

int StudentMS::MinMarks()
{
	PNODE temp=head;
	int iret=0;
	iret=temp->Marks;
	for(int i=1;i<=isize;i++)
	{
		if((temp->Marks)<iret)
		{
			iret=temp->Marks;
		}
		temp=temp->next;
	}
	return iret;
}
////////////////////////////////////////////////////////////////////////
//Function Name:   AvgMarks
//Function Date:    15/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to return average marks among all the students
//Returns:    		average marks
////////////////////////////////////////////////////////////////////////

int StudentMS::AvgMarks()
{
	int isum=0;
	PNODE temp=head;
	for(int i=1;i<=isize;i++)
	{
		isum=isum+temp->Marks;
		temp=temp->next;
	}
	return isum/isize;
}
////////////////////////////////////////////////////////////////////////
//Function Name:   Result
//Function Date:    15/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is used to Display the passed students
//Returns:    		None
////////////////////////////////////////////////////////////////////////
void StudentMS::Result()
{
	PNODE temp=head;
	cout<<"Passed students are:\n";
	for(int i=1;i<=isize;i++)
	{
		if((temp->Marks)>=35)
		{
			cout<<temp->Name<<"\t"<<temp->RollNo<<"\t"<<temp->Marks<<"\t";
		}
		temp=temp->next;
		cout<<"\n";
	}
}
////////////////////////////////////////////////////////////////////////
//Function Name:   	Update
//Function Date:    15/05/2021
//Function Author:  Shubham Upasani
//Paramters:        RollNo,new marks
//Description:      It is used to update students marks
//Returns:    		None
////////////////////////////////////////////////////////////////////////

void StudentMS::Update(int Rn,int NMarks)
{
	PNODE temp=head;
	
	for(int i=1;i<isize;i++)
	{
		if((temp->RollNo)==Rn)
		{
			temp->Marks=NMarks;
		}
		temp=temp->next;
	}
	
}
////////////////////////////////////////////////////////////////////////
//Function Name:   	main
//Function Date:    13/05/2021
//Function Author:  Shubham Upasani
//Paramters:        None
//Description:      It is main Function
//Returns:    		0
////////////////////////////////////////////////////////////////////////

int main()
{
	StudentMS obj;
	int choice=1,rollno=0,iret=0,marks=0,ipos=0,irn=0;
	char arr[30];
	while(choice!=0)
	{
		cout<<"********************************************\n";
		cout<<"\nStudent Managment System :>\n";
		cout<<"1:Insert Student At first\n";
		cout<<"2:Insert student at last\n";
		cout<<"3:Insert student at position\n";
		cout<<"4:Delete student at first\n";
		cout<<"5:Delete student at last\n";
		cout<<"6:Delete student at position\n";
		cout<<"7:Display Whole Information of all srudents\n";
		cout<<"8:Total number of student in class\n";
		cout<<"9:Serach Particular student by Roll Number\n";
		cout<<"10:Display students marks >90\n";
		cout<<"11:value max marks\n";
		cout<<"12:value of  min mars\n";
		cout<<"13:Average Marks of class\n";
		cout<<"14:Count of marks>90\n";
		cout<<"15:Result\n";
		cout<<"16:Update a paricular student's Marks\n";
		cout<<"0:Exit the application\n";
		cout<<"********************************************\n";
		cout<<"Enter Your Choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the studet rollno\n";
				cin>>rollno;
				cout<<"Enter the student name\n";
				cin>>arr;
				cout<<"Enter the marks\n";
				cin>>marks;
				obj.InsertFirst(rollno,arr,marks);
				break;
				
			case 2:
				cout<<"Enter the studet rollno\n";
				cin>>rollno;
				cout<<"Enter the student name\n";
				cin>>arr;
				cout<<"Enter the marks\n";
				cin>>marks;
				obj.InsertLast(rollno,arr,marks);
				break;
				
			case 3:
				cout<<"Enter the studet rollno\n";
				cin>>rollno;
				cout<<"Enter the student name\n";
				cin>>arr;
				cout<<"Enter the marks\n";
				cin>>marks;
				cout<<"Enter the position\n";
				cin>>ipos;
				obj.InsertAtPos(rollno,arr,marks,ipos);
				break;
				
			case 4:
				obj.DeleteAtFirst();
				break;
			case 5:
				obj.DeleteAtLast();
				break;
				
			case 6:
				cout<<"Enter the position\n";
				cin>>ipos;
				obj.DeleteAtPos(ipos);
				break;
				
			case 7:
				cout<<"The students in the class are:"<<"\n";
				obj.Display();
				break;
			case 8:
				iret=obj.Count();
				cout<<"Number of students in the class are:"<<iret<<"\n";
				break;
				
			case 9:
				cout<<"Enter the roll number\n";
				cin>>irn;
				obj.DisplayParticularStudent(irn);
				break;
				
			case 10:
				obj.DisplayMarksAbove90();
				break;
				
			case 11:
				iret=obj.MaxMarks();
				cout<<"Maximum Marks from the system is:"<<iret<<"\n";
				break;
				
			case 12:
				iret=obj.MinMarks();
				cout<<"Minimum Marks from the system is:"<<iret<<"\n";
				break;
				
			case 13:
				iret=obj.AvgMarks();
				cout<<"Average Marks of class is:"<<iret<<"\n";
				break;
			case 14:
				iret=obj.CountMarksAbove90();
				cout<<"Number of students having marks greater than 90 are:"<<iret<<"\n";
				break;
			case 15:
				obj.Result();
				break;
			case 16:
				cout<<"Enter the Roll Number of student whose marks going to update\n";
				cin>>irn;
				cout<<"Enter the New Marks\n";
				cin>>marks;
				obj.Update(irn,marks);
				break;
				
			case 0:
				cout<<"Thank you for using the application\n";
				break;
				
			default:
				cout<<"Please Enter the proper input\n";
				break;
		}//End Of switch
		
	}//End of while loop
	return 0;
}//End of main function