#include<iostream>
using namespace std;
template<class T>
struct node
{
	T data;
    struct node *next;
};

template<class T>
class SinglyCLL
{
	private:                   
		struct node<T>* Head=NULL;
        struct node <T>*Tail=NULL;
		int Count;
    public:                    
		SinglyCLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int CountNode();
};
template<class T>
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
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
void SinglyCLL<T>::InsertFirst(int no)
{
    struct node <T>* newn = NULL;

    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))    
    {
        Head = newn;
        Tail = newn;
    }
    else        
	{
        newn -> next = Head;
        Head = newn;
    }
    Tail -> next = Head;
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
void SinglyCLL<T>::InsertLast(int no)
{
    struct node <T>* newn = NULL;

    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))    // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else      
	{
        Tail -> next = newn;
        Tail = newn;
    }
    Tail -> next = Head;
	Count++;
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
void SinglyCLL<T>::InsertAtPos(int no, int ipos)
{
    int iSize = CountNode();

    if((ipos < 1) || (ipos > iSize+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
			struct node<T> * newn = NULL;

            newn = new node<T>;

            newn->data = no;
            newn->next = NULL;

            struct node <T>* temp = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp -> next;
            temp->next = newn;
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
void SinglyCLL<T>::DeleteFirst()
{
    if(Head == NULL && Tail ==  NULL)       // If LL is empty
    {
        return;
    }
    else if(Head == Tail)       // If LL contains 1 node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else    
    {
        Head = Head -> next;
        delete Tail->next;

        Tail->next = Head;
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
void SinglyCLL<T>::DeleteLast()
{
    if(Head == NULL && Tail ==  NULL)       // If LL is empty
    {
        return;
    }
    else if(Head == Tail)       // If LL contains 1 node
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else 
		{
        struct node<T> * temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }

        delete Tail;
        Tail = temp;

        Tail->next = Head;
    }
	Count--;
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
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    int iSize = CountNode();

    if((ipos < 1) || (ipos > iSize))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iSize)
    {
        DeleteLast();
    }
    else
    {
    struct node <T>* temp1 = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp1 = temp1->next;
            }

            struct node <T>* temp2 = temp1->next;

            temp1->next = temp2->next;
            delete temp2;
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
void SinglyCLL<T>::Display()
{
    struct node<T> *temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }

    do
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp -> next;
    }while(temp != Head);

    cout<<endl;
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
///////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T>::CountNode()
{
    return Count;
}
