#include<iostream>
#include <string>
#include <conio.h>
#include <time.h>

using namespace std;




class list{
public:
struct Node{
	
	string fon,name,address,email;
	Node *next;


};


struct bst
{
	string fon,name,address,email;
	
	bst *left;
	bst*right;
	
	
	
};
	bst *root;
	Node *head;
	
	list ()
	{head=NULL;
	root=NULL;
	
	}
	
	void searchbst()
	{
		string gg;
		int flag=0;
		cout<<"\nEnter Number to Search: ";
		
		cin>>gg;
		clock_t c_start=clock();
		
		bst *ptr=root;
		
		while(ptr!=NULL && flag!=1)
		{
			if(ptr->fon==gg)
				flag=1;
				
		else if(gg<ptr->fon)
		ptr=ptr->left;	
			
			else
			ptr=ptr->right;
		}
		
		if (flag==1)
		{
			cout<<"\nRecord Found\n";
				cout<<"Phone Number: "<<ptr->fon<<endl<<"\nName: "<<ptr->name<<endl<<"\nEmail: "<<ptr->email<<endl<<"\nAddress: "<<ptr->address<<endl<<endl;
		}
		else
		cout<<"\nRecord Cannot be Found.\n";
		
		
				clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
	}
	
	
	
	void remove(bst *&ptr)
	{
		bst *temp;
		
		if(ptr==NULL)
		cout<<"\nCannot Delete Empty Node.\n";
		else if(ptr->right==NULL)
		{
			temp=ptr;
			ptr=ptr->left;
			delete temp;
		}
		
		else if(ptr->left==NULL)
		{
			temp=ptr;
			ptr=ptr->right;
			delete temp;
		}
		else
		{
			
			temp=ptr->right;
			while(temp->left !=NULL)
			temp=temp->left;
			
			temp->left=ptr->left;
			temp=ptr;
			ptr=ptr->right;
			delete temp;	
				
			
			
			
			
			
		}
		
		
	}
	void del(string num,bst *&ptr)
	{
		if(num<ptr->fon)
		del(num,ptr->left);
		
		else if(num>ptr->fon)
		del(num,ptr->right);
	
	else
	remove(ptr);
		
		
	}
	void deletebst()
	{
		string num;
		cout<<"\nEnter Number to Delete: ";
		
		cin>>num;
		clock_t c_start=clock();
		 del(num,root);
		 		clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
	}
	
	void addnodebst()
	{
		bst *newnode= new bst;
		newnode->left=NULL;
		newnode->right=NULL;
		
		
		string a,b,c,d;
		cout<<"Enter mobile number of customer:";
	cin>>a;
	cout<<"Enter name of customer:";
	cin>>b;
	cout<<"Enter address of customer:";
	cin>>c;
	cout<<"Enter email of customer:";
	cin>>d;
	cout<<endl<<endl;
		
		clock_t c_start=clock();
		newnode->fon=a;
		newnode->name=b;
		newnode->address=c;
		newnode->email=d;
		
		if(root==NULL)
		root =newnode;
	
	
	else
	{
		bst *currptr=root;
		while(currptr!=NULL)
		{
			
		if(newnode->fon<currptr->fon)
		{
			if(currptr->left!=NULL)
			currptr=currptr->left;
		
		else
		{
			currptr->left=newnode;
		
			break;
		}
		
	}
	
	else if(newnode->fon>currptr->fon)
	{
		if(currptr->right!=NULL)
		currptr=currptr->right;
		
		else
		{
			currptr->right=newnode;
			
			break;
		}
	}
		else
		{
			cout<<"\nCant Add Duplicate.";
		
			break;
		}
	
		}
	}
				clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
}

void inorder(bst *ptr)
{
	
	
	if(ptr)
	{
		inorder(ptr->left);
		cout<<ptr->fon<<endl<<ptr->name<<endl<<ptr->email<<endl<<ptr->address<<endl<<endl;
		inorder(ptr->right);
	}
}
void preorder(bst *ptr)
{
	if(ptr){
		cout<<ptr->fon<<endl<<ptr->name<<endl<<ptr->email<<endl<<ptr->address<<endl<<endl;
		preorder(ptr->left);
		preorder(ptr->right);
		
	}
	
	
}

void postorder(bst *ptr)
{
	if(ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->fon<<endl<<ptr->name<<endl<<ptr->email<<endl<<ptr->address<<endl<<endl;
	}
	
}
void displaybst()
{
	clock_t c_start=clock();
	cout<<"\nIn Order List:\n";
inorder(root);
cout<<"\nPre Order List: \n";
preorder(root);

cout<<"\nPost Order List: \n";
postorder(root);

		clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
	
}
	//below are lik list functions

void addnodeattail()
{
	
	
	string a,b,c,d;
	Node *temp8;
	Node *ptrnew=new Node;
	cout<<"Enter mobile number of customer:";
	cin>>a;
	cout<<"Enter name of customer:";
	cin>>b;
	cout<<"Enter address of customer:";
	cin>>c;
	cout<<"Enter email of customer:";
	cin>>d;
	cout<<endl<<endl;
	clock_t c_start =clock();
	ptrnew->fon=a;
	ptrnew->name=b;
	ptrnew->address=c;
	ptrnew->email=d;
	
	ptrnew->next=NULL;
	
	if(head==NULL)
	{
		head=ptrnew;
			clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
		return;
	} 
	
	temp8=head;
	while(temp8->next!=NULL)
	{
		temp8=temp8->next;
	}
	temp8->next=ptrnew;	
		
	
		clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
}
void Delete()
{
	string x;
	cout<<"Enter the Number of customer.";
	cin>>x;
	
	clock_t c_start=clock();
	
	Node *ptrcur=head;
	Node *ptrprev;
	while(ptrcur!=NULL && ptrcur->fon!=x ){
		ptrprev=ptrcur;
		ptrcur=ptrcur->next;
	}
	if(ptrcur==NULL)
	{
		cout<<"Customer Does Not Found";
			
		clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
		return;
	}
	
	if(ptrcur==head)
	head=head->next;
	else
	ptrprev->next=ptrcur->next;
	
		

	
	delete ptrcur;
	
			clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
}

void display()
{
	clock_t c_start=clock();
	
	Node *temp1=new Node;
	temp1=head;
	while(temp1!=NULL)
	{
		cout<<"Name:"<<temp1->name<<endl<<"Mobile:"<<temp1->fon<<endl<<"Email:"<<temp1->email<<endl<<"Address:"<<temp1->address<<endl;
		temp1=temp1->next;
		


	}
	
	
			clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
	
}

void search()
{
	string a;
	cout<<"Enter number you want to search:";
	cin>>a;
	
	clock_t c_start=clock();
	Node *temp;
	temp=head;
	while(temp!=NULL&&temp->fon!=a)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"Customer not found"<<endl;
				clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
		return;
	}
	else if (temp->fon==a){
		cout<<"Name:"<<temp->name<<endl;
		cout<<"Mobile:"<<temp->fon<<endl;
		cout<<"Email:"<<temp->email<<endl;
		cout<<"Address"<<temp->address<<endl;
				clock_t c_end=clock();
	
	long double time_elapsed_ms= (long double)(c_end-c_start)/ (long double)CLOCKS_PER_SEC;
	cout<<"CPU TIME USED: "<<time_elapsed_ms<<" s\n";
		
	}
}

 
};


int main()
{
	list b;
	list l;
	char gg='y';
	int x,y;
	
	while(1)
	{
		
	
	cout<<"\nSelect: \n1-Link List\n2-BST\n3-Exit";
	cin>>y;
	
	if(y==1)
	{
	int flag1=0;
	while(gg=='y')
	{
		
	system("cls");
	
		cout<<"\t\t\tLINK LIST\n*************Mobile Phone Directory**************\n";
		cout<<"Choose\n1:Add Number\n2:Delete Number\n3:Display Number\n4:Search\n5-Main Menu";

		
		cin>>x;
		
		switch(x)
		{
 		case 1:
 		l.addnodeattail();
 		break;
 		case 2:
 		l.Delete();
 		break;
 		case 3:
 		l.display();
 		break;
		case 4:
		l.search();
		break;
		default:
		flag1=1;
	
		}

if(flag1==1)
break;

cout<<"\nGo to Previous Menu ? :(y/n): ";
cin>>gg;
}

}
else if(y==2)
{
	int flag2=0;
	char gg='y';
	while(gg=='y')
	{
		
	system("cls");
		cout<<"\t\t\tBST\n*************Mobile Phone Directory**************\n";
		cout<<"Choose\n1:Add Number\n2:Delete Number\n3:Display Number\n4:Search\n5-Main Menu";

cin>>x;

switch(x)
{
	case 1:
		b.addnodebst();
		break;
		case 2:
		b.deletebst();
			break;
			
		case 3:
			b.displaybst();
			break;
			case 4:
				b.searchbst();
				break;
				case 5:
					flag2=1;
					break;
			
	
	
}
if(flag2==1)
break;
cout<<"\n Go to Previous Menu? (y/n): ";
cin>>gg;

}
}
else
break;
}
	return 0;
}
