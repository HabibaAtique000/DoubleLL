#include<iostream>
using namespace std;
class node 
{
	public:
		int data;
		node *link;
		node *prev;
};
class LL
{
	public:
		
		node *head;
		LL()
		{
			head=NULL;
		}
		void insert_head(int v)
		{
			node *nptr=new node();
			nptr->data=v;
			nptr->link=NULL;
			nptr->prev=NULL;
			
			if(head==NULL)
			{
				head=nptr;
			}
			else
			{
				node *tptr=head;
				head=nptr;
				tptr->prev=nptr;
				nptr->link=tptr;
			}
		}
		void insert_tail(int v)
		{
			node *nptr=new node();
			nptr->data=v;
			nptr->link=NULL;
			nptr->prev=NULL;
			
			if(head==NULL)
			{
				head=nptr;
			}
			else
			{
				node *tptr=head;
				while(tptr->link!=NULL)
				{
					tptr=tptr->link;
				}
					tptr->link=nptr;
					nptr->prev=tptr;
			}
		}
		void print()
		{
			if(head==NULL)
			{
				cout<<"empty"<<endl;
			}
			else
			{
				node *tptr=head;
				while(tptr!=NULL)
				{
					cout<<tptr->data<<endl;
					tptr=tptr->link;					
				}
			}
		}
		bool search(int x)
		{
			int a=0;
			if(head==NULL)
			{
				cout<<"empty"<<endl;
				return false;
			}
			
			else
			{
				node *tptr=head;
				while(tptr!=NULL)
				{
					
					if(tptr->data==x)
					{
						a++;
					}
					tptr=tptr->link;					
				}
				cout<<"__NUMBER "<<x<<" EXISTS "<<a<<" TIMES__"<<endl;
				return true;
			}
		}
		int ret_search(int x)
		{
			node *tptr=head;
			
			for( int i=0;i<x;i++ )
			{
				tptr=tptr->link;
			}
			return tptr->data;
		}
		void del(int v)
		{
			node *tptr=head;
				while(tptr!=NULL && tptr->data!=v)
				{
					tptr=tptr->link;
				}
				if (tptr->link==NULL)
				{
					tptr->prev->link=tptr->link;	
				}
				else if(tptr->prev==NULL)
				{
					head=head->link;
					if(tptr->link==NULL)
					{
						head->prev==NULL;
					}
				}
				else
				{
				tptr->prev->link=tptr->link;
				tptr->link->prev=tptr->prev;
				}
		}
};
int main()
{
	LL list1;
	list1.insert_head(5);
	list1.insert_head(6);
	list1.insert_tail(7);
	list1.insert_tail(15);

	cout<<"returning"<<list1.ret_search(3);
	return 0;
}
