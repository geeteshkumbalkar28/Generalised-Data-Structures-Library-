#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node * next;
};
template<class T>
class Singlly
{
	public:
	struct node<T> *Head;
	int Count;
	
	Singlly();
	void Insertfirst(T);
	void Insertlast(T);
	void Display();
	int CountNode();
	void Deletefirst();
	void DeleteLast();
	void InsertAtPos(T,int);
	void DeleteAtPos(int);
};
template<class T>

Singlly<T>::Singlly()
{
	Head=NULL;
	Count=0;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Insertfirst
//  Description   :  Used to insert Node in first 
//  Input         :  T(int,float,char,double)
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void Singlly<T>::Insertfirst(T no)
{
	struct node <T>*newn=NULL;
	newn =new node<T>;
	
	newn->next=NULL;
	newn->data=no;
	
	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		newn->next=Head;
		Head=newn;
	}
	Count++;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Insertlast
//  Description   :  Used to insert Node in last
//  Input         :  T(int,float,char,double)
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void Singlly<T>::Insertlast(T no)
{
	struct node <T>*newn=NULL;
	newn =new node<T>;
	
	newn->next=NULL;
	newn->data=no;
	
	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		struct node <T>*temp=Head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	Count++;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Display
//  Description   :  Used to Display node
//  Input         :  NONE
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void Singlly<T>:: Display()
{
	cout<<"Elements from linked list are :"<<endl;
	struct node <T>*temp=Head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
	cout<<"NULL"<<endl;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  CountNode
//  Description   :  Used to Count node
//  Input         :  NONE
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////


template<class T>
int Singlly<T>::CountNode()
{
	return Count;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Deletefirst
//  Description   :  Used to delete node from first
//  Input         :  NONE
//  Output        :  int
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void Singlly<T>::Deletefirst()
{
	
	if(Head==NULL)
	{
		return ;
	}
	else
	{
		struct node<T>*temp=Head;
		Head=temp->next;
		delete[]temp;
	}
	Count--;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Description   :  Used to delete node from last
//  Input         :  NONE
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void Singlly<T>::DeleteLast()
{

	if(Head==NULL)
	{
		return ;
	}
	else if(Head->next==NULL)
	{
		delete []Head;
		Head=NULL;
	}
	else
	{
			struct node<T>*temp=Head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			delete []temp->next;
			temp->next=NULL;
				
	}
	Count--;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertAtPos
//  Description   :  Used to Insert Node in position
//  Input         :  T(int,float,char,double),int
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void Singlly<T>::InsertAtPos(T no,int pos)
{
	
	int Size =CountNode();
	if((pos<1)|(pos>(Size+1)))
	{
		cout<<"position invalide :";
			return ;
	}
	if(pos==1)
	{
		Insertfirst(no);
	}
	else if(pos ==(Size+1))
	{
		Insertlast(no);
	}
	else
	{
		struct node <T>*newn=NULL;
		newn=new node<T>;
		
		newn->next=NULL;
		newn->data=no;
		struct node<T>*temp=NULL;
		temp=Head;
		
		for(int iCnt=1;iCnt<pos-1;iCnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
	Count++;
	
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertAtPos
//  Description   :  Used to delete Node from position
//  Input         :  int
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////


template<class T>
void Singlly<T>::DeleteAtPos(int pos)
{

	int Size =CountNode();
	if((pos<1)|(pos>(Size)))
	{
		cout<<"position invalide :";
			return ;
	}
	if(pos==1)
	{
		Deletefirst();
	}
	else if(pos ==(Size+1))
	{
		DeleteLast();
	}
	else
	{
		struct node<T>* tempDelete=NULL;
		
		struct node<T>*temp=NULL;
		temp=Head;
		
		for(int iCnt=1;iCnt<pos-1;iCnt++)
		{
			temp=temp->next;
		}
		tempDelete=temp->next;
		temp->next=temp->next->next;
		delete[]tempDelete;
		
	}
	Count--;
	
}
