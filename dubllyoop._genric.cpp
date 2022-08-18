#include<iostream>
using namespace std;
template<class T>
struct node
{
	T data;
	struct node* next;
	struct node* prev;
};
template<class T>
class dublly
{
	public:
	struct node<T> *Head;
	int Count;
	
	dublly();
	void InsertFirst(T);
	void InsertLast(T);
	void DeleteFirst();
	void DeleteLast();
	void Display();
	int CountNode();
	void InsertAtPos(T,int);
	void DeleteAtPos(int);
};
template<class T>
dublly<T>::dublly()
{
	Head=NULL;
	Count=0;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertFirst
//  Description   :  Used to insert Node in first 
//  Input         :  T(int,float,char,double)
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void dublly<T>::InsertFirst(T No)
{
	
	struct node<T> *newn=NULL;
	newn =new node<T>;
	
	newn->data=No;
	newn->next=NULL;
	newn->prev=NULL;
	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		newn->next=Head;
		Head->prev=newn;
		Head=newn;
	}
	Count++;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertLast
//  Description   :  Used to insert Node in last
//  Input         :  T(int,float,char,double)
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void dublly<T>::InsertLast(T No )
{
	
	struct node<T> *newn=NULL;
	newn =new node<T>;
	
	newn->data=No;
	newn->next=NULL;
	newn->prev=NULL;
	if(Head==NULL)
	{
		Head=newn;
		
	}
	else
	{
		struct node<T> *temp=Head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		temp->prev=temp;
		
	}
	Count++;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteFirst
//  Description   :  Used to delete node from first
//  Input         :  NONE
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////
template<class T>
void dublly<T>::DeleteFirst()
{
	if(Head==NULL)
	{
		return ;
	}
	if(Head->next==NULL)
	{
		delete []Head;
		Head=NULL;
	}
	else
	{
		Head=Head->next;
		delete[](Head->prev);
		Head->prev=NULL;
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
void dublly<T>::DeleteLast()
{
	if(Head==NULL)
	{
		return ;
	}
	if(Head->next==NULL)
	{
		delete []Head;
		Head=NULL;
	}
	else
	{
		struct node <T>*temp=Head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		delete[](temp->next);
		temp->next=NULL;
	}
	Count--;
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
void dublly<T>::Display()
{
	cout<<"Data from Linked list is : \n";
	struct node<T>*temp=Head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;;
	}
	cout<<"NULL"<<endl;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  CountNode
//  Description   :  Used to Count node
//  Input         :  NONE
//  Output        :  int
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
//////////////////////////
template<class T>

int dublly<T>::CountNode()
{
	return Count;
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
void dublly<T>::InsertAtPos(T no,int pos)
{
	if((pos<1)||(pos>(Count+1)))
	{
		cout<<"Invalid Position"<<endl;
		return ;
	}
	if(pos==1)
	{
		InsertFirst(no);
	}
	else if(pos==(Count+1))
	{
		InsertLast(no);
		
	}
	else
	{
		struct node<T> *temp=Head;
		struct node<T> *newn=NULL;
		newn =new node<T>;
		
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		for(int iCnt=1;iCnt<(pos-1);iCnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
	}
	Count++;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteAtPosnsertAtPos
//  Description   :  Used to delete Node from position
//  Input         :  int
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void dublly<T>::DeleteAtPos(int pos)
{
		if((pos<1)||(pos>Count))
	{
		cout<<"Invalid Position"<<endl;
		return ;
	}
	if(pos==1)
	{
		DeleteFirst();
	}
	else if(pos==(Count+1))
	{
		DeleteLast();
		
	}
	else
	{
		struct node<T> *temp=Head;
		struct node<T> *tempDelete=NULL;
		for(int iCnt=1;iCnt<(pos-1);iCnt++)
		{
			temp=temp->next;
		}
		tempDelete=temp->next;
		temp->next=temp->next->next;
		delete[]tempDelete;
		}
	Count--;

}

