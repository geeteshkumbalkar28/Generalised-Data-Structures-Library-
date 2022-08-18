#include<iostream>
using namespace std;
template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};
template<class T>
class DoublyCLL
{
	private: 
	struct node<T> *Head;
	struct node<T> *Tail;
	int Countnode;
	
	public :
	DoublyCLL();
	
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	
	int Count();
	void Display();
};
template<class T>
DoublyCLL<T>::DoublyCLL()
{
	Head=NULL;
	Tail=NULL;
	Countnode=0;
	
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
void DoublyCLL<T>::InsertFirst(T iNo)
{
  struct node<T>*newn;
  newn=new node<T>;
   
   newn->next=NULL;
   newn->prev=NULL;
   newn->data=iNo;
   if(Countnode==0)
   {
	   Head=newn;
	   Tail=newn;
   }
   else
   {
	   newn->next=Head;
	   Head->prev=newn;
	   Head=newn;
	   
   }
   Head->prev=Tail;
   Tail->next=Head;
   Countnode++;
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
void DoublyCLL<T>::Display()
{
	int i=0;
	struct node<T> *temp=Head;
	
	for(i=1;i<=Countnode;i++)
	{
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
	}
	cout<<" "<<endl;
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
void DoublyCLL<T>::InsertLast(T iNo)
{
	
	  struct node<T> *newn;
	  newn=new node<T>;
	   
	   newn->next=NULL;
	   newn->prev=NULL;
	   newn->data=iNo;
   if(Countnode==0)
	{
	   Head=newn;
	   Tail=newn;
   }
   else
   {
	
	Tail->next=newn;
	newn->prev=Tail;
	Tail=newn;   
   }
	Tail->next=Head;
	Head->prev=Tail;
	Countnode++;
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
void DoublyCLL<T>::InsertAtPos(T iNo,int iPos)
{
		if((iPos<1)||(iPos>Countnode+1))
		{
			cout<<"Invalid position"<<endl;
			return;
		}
		if(iPos == 1)
		{
			InsertFirst(iNo);
		}
		else if(iPos == Countnode+1)
		{
			InsertLast(iNo);
		}
		else 
		{
			int i=0;
			struct node <T>*newn=new node<T>;
			
			newn->next=NULL;
			newn->data=iNo;
			newn->prev=NULL;
			
			struct node <T>*temp=Head;
			
			for(i=1;i<iPos-1;i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next->prev=newn;
			temp->next=newn;
			newn->prev=temp;
			
			Countnode++;
		}
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
void DoublyCLL<T>::DeleteFirst()
{
	if(Countnode == 0)
	{
		return;
	}
	else if(Countnode ==1)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Head=Head->next;
		delete Tail->next;
		
	}
	Tail->next=Head;
	Head->prev=Tail;
	Countnode--;
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
void DoublyCLL<T>::DeleteLast()
{
	if(Countnode == 0)
	{
		return;
	}
	else if(Countnode==1)
	{
		delete Tail;
		Tail =NULL;
		Head =NULL;
		
	}
	else
	{
		Tail=Tail->prev;
		delete Tail->next;
	}
	Head->prev=Tail;
	Tail->next=Head;
	Countnode--;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteAtPos
//  Description   :  Used to delete Node from position
//  Input         :  int
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
	if((iPos<0)||(iPos>Countnode))
	{
		cout<<"Invalid Position"<<endl;
		return;
	}
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos == Countnode)
	{
		DeleteLast();
	}
	else
	{
		int i=0;
		struct node <T>*temp=Head;
		
		for(i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
		
		Countnode--;
	}
		
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Count
//  Description   :  Used to Count node
//  Input         :  NONE
//  Output        :  int
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
///////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCLL<T>::Count()
{
	return Countnode;
}
