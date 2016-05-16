#include <iostream>
#include <cstring>
#define MAXDEG 2000
using namespace std;

class Polynomial{
	public:
		int CoEff[MAXDEG+10];
		int HighPow;
		void ZeroNom(){
			int i;
			for(i = 0;i <= MAXDEG;i++)
			    this->CoEff[i] = 0;
			this->HighPow = 0;
		}
		
		Polynomial operator+(const Polynomial &secPoly){
			Polynomial temp;
			temp.ZeroNom();
			temp.HighPow = max(this->HighPow,secPoly.HighPow);
			for(int i = temp.HighPow;i>= 0;i--)
			    temp.CoEff[i] = this->CoEff[i] + secPoly.CoEff[i];
			return temp;
		}
		
		Polynomial operator*(const Polynomial &secPoly){
			int i,j;
			Polynomial temp;
			temp.ZeroNom();
			temp.HighPow = this->HighPow + secPoly.HighPow;

			for(i = 0;i <= this->HighPow;i++){
				for(j = 0;j <= secPoly.HighPow;j++){
					temp.CoEff[i+j] += this->CoEff[i] * secPoly.CoEff[j]; 
				}
			}
			return temp;
		}
		Polynomial& operator=(const Polynomial &secPoly){
			memcpy(this,&secPoly,sizeof(secPoly));
			return *this;
		}
};

void input(Polynomial& PolyN){
	PolyN.ZeroNom();
	int c,t1,t2;
	cin>>c;
	cin>>t1>>t2;
	PolyN.HighPow = t2;
	PolyN.CoEff[t2] = t1;
	for(int i = 1;i <= c-1;i++){
		cin>>t1>>t2;
		PolyN.CoEff[t2] = t1;
	}
}

int main(){
	Polynomial Poly1,Poly2,temp;
	input(Poly1);
	input(Poly2);
	
	temp = Poly1 * Poly2;
	for(int i = temp.HighPow;i>=1;i--){
		if(temp.CoEff[i]!=0) cout<<temp.CoEff[i]<<' '<<i<<' ';
	}
	if(temp.CoEff[0]!=0) cout<<temp.CoEff[0]<<' '<<0;
	cout<<endl;
	temp = Poly1 + Poly2;
	for(int i = temp.HighPow;i>=1;i--){
		if(temp.CoEff[i]!=0) cout<<temp.CoEff[i]<<' '<<i<<' ';
	}
	if(temp.CoEff[0]!=0) cout<<temp.CoEff[0]<<' '<<0;
	cout<<endl;
	return 0;
}
