/////////////////////////////////////////////////////////////////////
//Queue genric
/////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class Queue
{
    public:
        struct node<T> *Head;
        int Count;

        Queue();
        void Enqueue(T);        
        void Dequeue();           
        void Display();
        int CountNode();
};

template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Enqueue	
//  Description   :  Used to Insert NODE in Last
//  Input         :  T
//  Output        :  void
//  Date 		  :  08/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::Enqueue(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
            struct node<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }

            temp->next = newn;
    }
    Count++;
}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Dequeue	
//  Description   :  Used to Delete the Data from first NODE
//  Input         :  NONE
//  Output        :  void
//  Date 		  :  08/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////


template <class T>
void Queue<T>::Dequeue()       // Deletefirst
{
    T no;   // int no;

    if(Count == 0)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    no = Head -> data;
    struct node<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Display	
//  Description   :  Used to display the NODE
//  Input         :  NONE
//  Output        :  void
//  Date 		  :  08/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>::Display()
{
    cout<<"Elements from Queue are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Dequeue	
//  Description   :  Used to return Count of NODE
//  Input         :  T
//  Output        :  void
//  Date 		  :  08/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T>::CountNode()
{
    return Count;
}

