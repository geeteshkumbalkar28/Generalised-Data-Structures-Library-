
#include<iostream>
using namespace std;

template<class T>
struct node
{
	T Data;
	struct node * next;
};

template<class T>
class SingllyLLG
{
	public :
	struct node <T>*Head;
	int Accept;
	
	SingllyLLG();
	void InsertFirst(T);
	int SearchFirstOcc(T);
	int SearchLastOcc(T);
	T Addition();
	T Maximum();
	T Minimum();
	T SecMax();
	void Display();
};
template<class T>

SingllyLLG<T>::SingllyLLG()
{
	Head = NULL;
}

template<class T>
void SingllyLLG<T>::InsertFirst(T no)
{
	struct node<T> *newn=NULL;
	newn=new node<T>;
	
	newn->next=NULL;
	newn->Data=no;
	
	if(Head==NULL)
	{
		Head=newn;
		
	}
	else
	{
		newn->next=Head;
		Head=newn;
	}
}

template<class T>
void SingllyLLG<T>::Display()
{
	struct node<T> *temp=Head;
	printf("your linked list element");
	
	while(temp!=NULL)
	{
		cout<<" "<<temp->Data<<" ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

/////////////////////////////////////////////////////////////////////
//
//  Function Name :  SearchFirstOcc
//  Description   :  Used to search first occurrence of perticular element
//  Input         :  T(int,float,char,double)
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
int SingllyLLG<T>::SearchFirstOcc(T no)
{
	int iPos=1,ipos=0;
	struct node<T> *temp=Head;
	
	while(temp!=NULL)
	{
		if(temp->Data == no)
		{
			ipos=iPos;
			break;
		}

		iPos++;
		temp=temp->next;
	}
	return ipos;


}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  SearchFirstOcc
//  Description   :  Used to search last occurrence of perticular element
//  Input         :  T(int,float,char,double)
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
int SingllyLLG<T>::SearchLastOcc(T no)
{
	int iPos=1,ipos=0;
	struct node<T> *temp=Head;
	
	while(temp!=NULL)
	{
		if(temp->Data == no)
		{
			ipos=iPos;
			
		}

		iPos++;
		temp=temp->next;
	}
	return ipos;


}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Addition
//  Description   :  Addition of all element 
//  Input         :  T(int, float ,double)
//  Output        :  void
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
T SingllyLLG<T>::Addition()
{
	T Sum;
	struct node<T>* temp=Head;
	while(temp!=NULL)
	{
		Sum=Sum+(temp->Data);
		temp=temp->next;
	}
	

	return Sum;

}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Maximum
//  Description   :  Used to largest element for linked list
//  Input         :  T(int, float ,double)
//  Output        :  T(int, float ,double)
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
T SingllyLLG<T>::Maximum()
{
	T Max=Head->Data;
	struct node<T>* temp=Head;
	while(temp!=NULL)
	{
		if((temp->Data)>Max)
		{
			Max=temp->Data;
		}
		temp=temp->next;
	}
	

	return Max;

}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  Minimum
//  Description   :  Used to smallest element for linked list
//  Input         :  T(int, float ,double)
//  Output        :  T(int, float ,double)
//  Date 		  :  09/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
T SingllyLLG<T>::Minimum()
{
	T Min=Head->Data;
	struct node<T>* temp=Head;
	while(temp!=NULL)
	{
		if((temp->Data)<Min)
		{
			Min=temp->Data;
		}
		temp=temp->next;
	}
	

	return Min;

}
/////////////////////////////////////////////////////////////////////
//
//  Function Name :  SecMax
//  Description   :  Used to second largest element for linked list
//  Input         :  T(int, float ,double)
//  Output        :  T(int, float ,double)
//  Date 		  :  10/08/2022
//  Author 		  :  Geetesh Gajanan Kumbalkar
//
/////////////////////////////////////////////////////////////////////

template<class T>
T SingllyLLG<T>::SecMax()
{
	T SMax=Minimum();
	T max=Maximum();
		struct node<T>* temp=Head;
	while(temp!=NULL)
	{
		if(max!=(temp->Data))
		{
			if(SMax<(temp->Data))
			{
				SMax=temp->Data;
			}
		}
	
		
		temp=temp->next;
	}
	return SMax;
}


