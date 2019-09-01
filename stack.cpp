#include<iostream>
using namespace std;
#define max 10
struct stack
{
    int stk[max];
    int top;
}s;

class Stack
{
private:
    /* data */
public:
    Stack(/* args */);
    bool isFull();
    bool isEmmpty();
    void insert();
    void remove();
    void display();
};

Stack ::Stack(){
    for (int i = 0; i < max; i++)
    {
        s.stk[i]=0;
    }
    s.top=-1;
}

void Stack ::display(){
    cout<<"\n";
    bool flag=false;
    for (int i = 0; i < s.top; i++)
    {
        cout<<"|\t"<<s.stk[i]<<"\t|";
        if(!flag){
            cout<<"<== top";
            flag= true;
        }
        cout<<"\n";
    }
    cout<<"|______________|";
    cout<<"\n";
    
}
bool Stack::isFull(){
    if (s.top==max )
    {
        return 1;
    }
    return 0;
}
bool Stack::isEmmpty(){
    if(s.top==-1){
        return 1;
    }
    return 0;
}
void Stack ::insert(){
    int n;
    if (isFull())
    {
        cout<<"stack is Overflow\n";
    }
    cout<<"enter the element your wanna insert\n";
    cin>>n;
    s.top++;
    s.stk[s.top]=n;
    cout<<"element inserted to stack \t"<<n<<"\n";
}
void Stack::remove(){
    if (isEmmpty())
    {
        cout<<"stack is underflow\n";
    }
    cout<<"item removed \t"<<s.stk[s.top]<<"\n";
    s.top--;
}
int main(){
    int ch;
    Stack obj;
    cout<<"------------------ stack ------------------\n";
    while (true)
    {
        cout<<"enter your choice\n0.exit\n1.insert\n2.remove\n3.display\n";
        cin>>ch;
        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
                obj.insert();
                break;
        case 2:
                obj.remove();
                break;
        case 3:
                obj.display(); 
                break;
        default:
            cout<<"Invalid Option \n";
            break;
        }
    }   
}