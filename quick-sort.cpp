
#include<iostream>
using namespace std;
class quick
{
	float arr[20];
public:
	int getdata();
	void quicksort(int,int);
	void display(int);
	int partition(int,int);
};
void quick::quicksort(int p,int q)
{
	int j;
	if(p<q){
	j=partition(p,q+1);
	quicksort(p,j-1);
	quicksort(j+1,q);
	}
}
int quick::partition(int low,int high)
{
	int i=low+1;
	int j=high-1;
	float pivot=arr[low];
	while(i<j)
	{
		while(arr[i]<pivot)
		{
			i++;
		}
		while(arr[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			float temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	float temp=arr[j];
	arr[j]=arr[low];
	arr[low]=temp;
	return j;
}

int quick::getdata()
{
	int i,n;
	cout<<"\n Enter total number of students: ";
	cin>>n;
	cout<<"\n Enter percentage marks of students...";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	return n;
}

void quick::display(int n)
{
	for(int i=n-1;i>=n-5;i--)
	{
		cout<<"\n"<<arr[i];
	}
}
int main()
{
	quick q;
	int n;
	cout<<"\n Quick Sort .....";
	n=q.getdata();
	q.quicksort(0,n-1);
	q.display(n);
}
