#include<iostream>
using namespace std;
struct node
{
	int data;
	node * next;
	public:node()
	{
		data=0;
		next=NULL;
	}
};

struct linked
{
	node*head ; node*tail;
	public:linked()
	{
		head=NULL;tail=NULL;
	}
	
	void insert(int x)
	{
		node*temp=new node();
		temp->data=x;
		if(head==NULL)
		{
			head=temp;tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
		temp->next=NULL;
	}
	
	void insertAt(int x, int p)
	{
		node*temp=new node();
		int i=0;
		node*slider=head;
		temp->data=x;
		if((p==1)&&(head!=NULL))
		{
			temp->next=head;
			head=temp;
		}
		else if((p>1)&&(slider!=NULL))
		{
			for(i=1;i<p;i++)
			{
				if(i+1==p)
				{
					temp->next = slider->next;
					slider->next = temp;
					if(slider->next==NULL)
					{
						tail=temp;
					}
					break;
				}
				slider=slider->next;
			}
		}
		else
		{
			cout<<"Invalid input of position OR the linked list is not created \n";
		}
	}
	
	void delete_tail()
	{
		node*slider=head;
		if(head==tail)
		{
			head=NULL;tail=NULL;
			delete slider;
		}
		else
		{
			while(slider->next !=NULL)
			{
				slider=slider->next;
			}
			slider->next=NULL;
			tail=slider;
		}
	}
	
	void deleteAt(int p)
	{
		node*pre;node*slider;int i=0;
		pre=head;
		slider=head;
		if(head==tail)
		{
			if(p==1)
			{
				head=tail=NULL;
				delete pre;
				delete slider;
			}
			else
			{
				cout<<"Invalid position input"<<endl;
			}
		}
		else
		{
			if((p>1)&&(head!=NULL))
			{
				for(i=1;i<p;i++)
				{
					if(i+1==p)
					{
						slider=slider->next->next;
						pre->next=slider;
						break;
					}
					slider=slider->next;
					pre=pre->next;
				}
			}
			else
			{
				cout<<"Invalid input OR linked list isn't created"<<endl;
			}
		}
	}
	
	int countnodes()
	{
		node*slider=head;
		int i=1;
		while(slider->next!=NULL)
		{
			++i;
			slider=slider->next;
		}
		cout<<"Number of elements:- ";
		return i;
	}
	
	void display()
	{
		node*slider=head;
		cout<<"The linked list is:-\n";
		while(slider->next!=NULL)
		{
			cout<<slider->data<<"  ";
			slider=slider->next;
		}
		cout<<slider->data<<"  NULL"<<endl;
	}
};

int main()
{
	linked list;
	int a,d,l;
	cout<<"Enter the length of linked list\n";
	cin>>l;
	cout<<"\nEnter the elemnets of the linked list\n";
	for(a=1;a<=l;a++)
	{
		cin>>d;
		list.insert(d);
	}
	cout<<endl;
	list.display();
	list.insertAt(19,4);cout<<endl;list.display();
	list.delete_tail();cout<<endl;list.display();
	list.deleteAt(4);cout<<endl;list.display();
	cout<<list.countnodes()<<endl;
}
