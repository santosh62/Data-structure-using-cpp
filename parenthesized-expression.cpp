
#include<iostream>
#include<string.h>
using namespace std;
#define max 50
struct node
{
	char stack[max];
	int top;
}st;

class Stack
{
public:
	void push(char);
	char pop();
	int check(char exp[]);
	friend int match(char s,char b);
};

int Stack::check(char exp[])
{
	int i;
	char temp;
	int n=strlen(exp);
	for(i=0;i<n;i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			push(exp[i]);
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
			if(st.top==-1)
				return 0;
			else
			{
				temp=pop();
				if(!match(temp,exp[i]))
					return 0;
			}
	}
	if(st.top==-1)
		return 1;
	else
		return 0;
}

int match(char a,char b)
{
	if(a=='[' && b==']')
		return 1;
	if(a=='{' && b=='}')
		return 1;
	if(a=='(' && b==')')
		return 1;
	return 0;
}

void Stack::push(char item)
{
	if(st.top==(max-1))
	{
		cout<<"\n Stack Overflow";
		return;
	}
	st.top++;
	st.stack[st.top]=item;
}

char Stack::pop()
{
	if(st.top==-1)
	{
		cout<<"\n Stack underflow.";
		exit(1);
	}
	return (st.stack[st.top--]);
}

int main()
{
	char exp[max];
	int status;
	Stack obj;
	st.top=-1;
	cout<<"\n Enter a parenthesized expression";
	cin>>exp;
	status=obj.check(exp);
	if(status==1)
	{
		cout<<"\n The expression is well parenthesized";
	}
	else
	{
		cout<<"\n The expression is not well parenthesized";
	}
	return 0;
}
