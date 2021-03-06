
#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	char name[20];
	struct node *next;
};
class Set
{

public:
	struct node *head,*head1,*head2;
	Set()
	{
		head=NULL;
		head1=NULL;
		head2=NULL;
	}
	struct node* create(struct node *head);
	void display(struct node *p);
	struct node *Union(struct node *head1,struct node *head2);
	void Intersection(struct node *head1, struct node *head2);
	struct node *difference(struct node *head1, struct node *head2);
	int count(struct node *p);
};

int Set::count(struct node *p)
{
	int cnt=0;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}
struct node * Set::difference(struct node *head1, struct node *head2)
{
	struct node *head3,*p,*q,*r;
		struct node* New;
		p=head1;
		head3=NULL;
		while(p!=NULL)
		{
			int flag=0;
			q=head2;
			while(q!=NULL)
			{
				if(strcmp(p->name,q->name)==0)
				{
					flag=1;
					break;
				}
				else
				{
					q=q->next;
				}
			}
			if(flag!=1)
			{
				if(head3==NULL)
					{
						New=new node;
						strcpy(New->name,p->name);
						r=New;
						r->next=NULL;
						head3=r;
					}
					else
					{
						New=new node;
						r->next=New;
						strcpy(New->name,p->name);
						r=r->next;
						r->next=NULL;
					}
			}
			p=p->next;
		}
		return head3;
}
void Set::Intersection(struct node *head1, struct node *head2)
{
	struct node *head3,*p,*q,*r;
	struct node* New;
	p=head1;
	head3=NULL;
	while(p!=NULL)
	{
		q=head2;
		while(q!=NULL)
		{
			if(strcmp(p->name,q->name)==0)
			{
				if(head3==NULL)
				{
					//head3=r=p;
					New=new node;
					strcpy(New->name,p->name);
					r=New;
					r->next=NULL;
					head3=r;
				}
				else
				{
					New=new node;
					r->next=New;
					strcpy(New->name,p->name);
					r=r->next;
					r->next=NULL;
				}
				break;
			}
			q=q->next;

		}
		p=p->next;
	}
	display(head3);
}

struct node *Set::Union(struct node *head1,struct node *head2)
{
	struct node *head3,*p,*q,*r;
	//p=head1;
	q=head2;
	head3=head1;
	r=head3;

	while(r->next!=NULL)
	{
		r=r->next;
	}
	while(q!=NULL)
	{
		p=head1;
		int flag=0;
		while(p!=NULL)
		{
			if(strcmp(p->name,q->name)==0)
			{
				flag=1;
				break;
			}
			else
				p=p->next;
		}
		if(flag==0)
		{
			struct node* New=new node;
			r->next=New;
			strcpy(New->name,q->name);
			r=r->next;
			r->next=NULL;
		}
		q=q->next;
	}
	return head3;
}

void Set::display(struct node *p)
{
	if(p==NULL)
	{
		cout<<"\n This set is empty...";
	}
	while(p!=NULL)
	{
		cout<<" "<<p->name;
		p=p->next;
	}
}
struct node* Set::create(struct node *head)
{
	struct node *New,*p;
	int ans;
	do{
	New = new node;
	New->next=NULL;
	cout<<"\n Enter name: ";
	cin>>New->name;
	if(head==NULL)
	{
		head=p=New;
	}
	else
	{
		p->next=New;
		p=p->next;
	}
	cout<<"\n Want to add more names: ";
	cin>>ans;
	}while(ans==1);
	return head;
}
int main()
{
	Set s;
	struct node *U,*d;
	int ch,ans;
	cout<<"\n Enter the main list of students: ";
	s.head=s.create(s.head);
	cout<<"\n Enter list of students who like vanilla";
	s.head1=s.create(s.head1);
	cout<<"\n Enter list of students who like butterscotch";
	s.head2=s.create(s.head2);
	cout<<"\n List of all students.\n";
	s.display(s.head);
	cout<<"\n List of students who like vanilla.\n";
	s.display(s.head1);
	cout<<"\n List of students who like butterscotch.\n";
	s.display(s.head2);
	do
	{
		cout<<"\n Options..";
		cout<<"\n 1. Set of students who like either vanilla or butterscotch or both";
		cout<<"\n 2. Set of students who like both vanilla and butterscotch";
		cout<<"\n 3. Set of students who like only vanilla not butterscotch";
		cout<<"\n 4. Set of students who like only butterscotch not vanilla";
		cout<<"\n 5. Number of students who neither like vanilla nor butterscotch";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n Set of students who like either vanilla or butterscotch or both ";
			U=s.Union(s.head1,s.head2);
			s.display(U);
			break;
		case 2:
			cout<<"\n Set of students who like both vanilla and butterscotch";
			s.Intersection(s.head1,s.head2);
			break;
		case 3:
			cout<<"\n Set of students who like only vanilla not butterscotch";
			d=s.difference(s.head1,s.head2);
			s.display(d);
			break;
		case 4:
			cout<<"\n Set of students who like only butterscotch not vanilla";
			d=s.difference(s.head2,s.head1);
			s.display(d);
			break;
		case 5:
			cout<<"\n Number of students who neither like vanilla nor butterscotch: ";
			d=s.difference(s.head,U);
			cout<<s.count(d);
		}
		cout<<"\n Do you want to continue: ";
		cin>>ans;
	}while(ans==1);
}
