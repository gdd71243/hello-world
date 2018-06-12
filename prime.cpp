#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
class Prime{
	public:
		Prime(int num):mNum(num){}
		void devide(void){
			memset(b,0,sizeof(b));
			memset(flag,0,sizeof(flag));
			int num=mNum;
			for (int i=0; i<4; i++)
				b[i] = 0;
			int i = 0;
			while ( num > 0){
				b[i++] = num % 10;
				num = num / 10;
			}
		};
		bool isPrime(){
			for(int i=2;i<=sqrt(mNum);i++){
				if(mNum%i==0)
					return false;		
			}
			return true;
		};
		Prime sumBit(){
			this->devide();
			int buffer=b[0]+b[1]+b[2]+b[3];
			Prime res(buffer);
			return res;
		};
		Prime multiBit(){
			int buffer;
			this->devide();
			if(b[3]!=0)
				buffer=b[0]*b[1]*b[2]*b[3];
			else
				buffer=b[0]*b[1]*b[2];
			Prime res(buffer);
			return res;	
		};
		Prime sqaureSumBit(){
			this->devide();
			int buffer=b[0]*b[0]+b[1]*b[1]+b[2]*b[2]+b[3]*b[3];
			Prime res(buffer);
			return res; 
		};
		void print(){
			cout<<mNum<<endl;
		};
	private:
		const int mNum;	
		int flag[10010];
		int b[4];
};
int main(){
	for ( int i=100; i<=999; i++)
	{
		Prime pm(i);
		Prime sb=pm.sumBit();
		Prime mb=pm.multiBit();
		Prime ssb=pm.sqaureSumBit();
		if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
			pm.print();
		}
	}
	
}
