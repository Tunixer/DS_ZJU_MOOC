#include <iostream>
#include <cstring>
#include <cstdlib> 
using namespace std;
typedef struct PolyNode* Polynomial;
typedef struct PolyNode Node;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
}; 

Polynomial ReadPoly();
void Attach(int c,int e,Polynomial *pRear);
Polynomial Add(Polynomial P1,Polynomial P2);
void PrintPoly(Polynomial P);
Polynomial  Mult(Polynomial P1,Polynomial P2);

int main(){
	Polynomial P1,P2,PP,PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1,P2);
	PS = Add(P1,P2);
	PrintPoly(PP);
	PrintPoly(PS);
	return 0;
}

Polynomial ReadPoly(){
	Polynomial P,Rear,t;
	int N,c,r;
	cin>>N;
	P = (Polynomial)malloc(sizeof(Node));
	P->link = NULL;
	Rear = P;
	while(N--){
		cin>>c>>r;
		Attach(c,r,&Rear); 
	} 
	t = P; P = P->link;free(t);
	return P; 
}

Polynomial  Mult(Polynomial P1,Polynomial P2){
	Polynomial P,t1,t2,temp,Rear,t;
	t1 = P1;t2 = P2;
	P = (Polynomial)malloc(sizeof(Node));
	P->link = NULL;
	Rear = P;
	while(t2){
		Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
		t2 = t2->link;
	}
	t = P;P = P->link;free(t); 
	t1 = t1->link;
	while(t1){
		t2 = P2;
		temp = (Polynomial)malloc(sizeof(Node));
		temp->link = NULL;
		Rear = temp;
		while(t2){
			Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
			t2 = t2->link;
		}
		t = temp;temp = temp->link;free(t);
		P = Add(P,temp);
		t1 = t1->link;
	}
	return P;
}

void Attach(int c,int e,Polynomial *pRear){
	Polynomial P;
	P = (Polynomial)malloc(sizeof(Node));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

Polynomial Add(Polynomial P1,Polynomial P2){
	Polynomial t1,t2,Rear,t,P;
	P = (Polynomial)malloc(sizeof(Node));
	t1 = P1;t2 = P2; 
	P->link = NULL;
	Rear = P;
	while(t1&&t2){
		if(t1->expon == t2->expon){
			Attach(t1->coef+t2->coef,t1->expon,&Rear);
			t1 = t1->link;
			t2 = t2->link;
		}
		else if(t1->expon > t2->expon){
			Attach(t1->coef,t1->expon,&Rear);
			t1 = t1->link;		
		}
		else{
			Attach(t2->coef,t2->expon,&Rear);
			t2 = t2->link;				
		}
	}
	while(t1){
		Attach(t1->coef,t1->expon,&Rear);
		t1 = t1->link;	
	}
	while(t2){
		Attach(t2->coef,t2->expon,&Rear);
		t2 = t2->link;	
	}
	t = P; P = P->link;free(t);
	return P;
}

void PrintPoly(Polynomial P){
	int flag = 0;
	if(!P){
		cout<<"0 0"<<endl;
		return;
	}
	while(P){
		if(!flag)
		    flag = 1;
		else
		    cout<<' ';
		cout<<P->coef<<' '<<P->expon;
		P = P->link;
	}
	cout<<endl;
}
