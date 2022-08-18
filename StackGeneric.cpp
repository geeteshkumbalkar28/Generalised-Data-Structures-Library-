/////////////////////////////////////////////////////////////////////
//Stack genric
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
class Stack
{
    public:
        struct node<T> *Head;
        int Count;

        Stack();
        void Push(T);        // InsertFirst
        void Pop();            // DeleteFirst
        void Display();
        int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Push	
//  Description   :  Used to Insert NODE in first
//  Input         :  T(int,float,char,double)
//  Output        :  void
//  Date 		  :  08/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////
template<class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;
    Count++;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Pop	
//  Description   :  Used to Delete the Data from first NODE
//  Input         :  NONE
//  Output        :  void
//  Date 		  :  08/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::Pop()       // Deletefirst
{
    T no;   // int no;

    if(Count == 0)
    {
        cout<<"Stack is empty"<<endl;
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
void Stack<T>::Display()
{
    cout<<"Elements from Stack are : "<<endl;
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
//  Input         :  NONE
//  Output        :  void
//  Date 		  :  08/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

