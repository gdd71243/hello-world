//单位转换程序，输入值和原单位，新单位，返回新单位下的值。

//重量单位：Kg, g, lb, gr,......

//压力单位：Pa, MPa, psi,......

//长度单位：m, km, ft, in,......

//其它单位：md, cp,......

//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream> 
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

class type
{
	public:
		type()
		{
			n = 0;
		}
		void give( string t, int n_t)//赋值name 
		{
			name[n_t] = t;
			n++;
		}
		void give( double a, int b, int c)//赋值num和ten 
		{
			num[0][c] = a;
			ten[0][c] = b;
		}
		void show() 
		{
			for ( int i=0; i<n; i++)
				printf("%d.%s  ",i, name[i].c_str() );
			printf("\n");
		}
		void change() 
		{
			for ( int i=0; i<n; i++)
			{
				num[i][i] = 1;
				ten[i][i] = 0;
				for ( int j = i+1; j<n; j++)
				{
					num[i][j] = num[0][j] / num[0][i];
					num[j][i] = 1 / num[i][j];
					ten[i][j] = ten[0][j] - ten[0][i];
					ten[j][i] = - ten[i][j];
				}
			}
		}
		
	private:
		int n;
		double num[30][30];
		int ten[30][30];
		string name[30];
		
};

class show
{
	public:
		void beginshow()
		{
			printf("请输入需要转化的单位类型编号并回车：\n1.长度 2.面积 3.体积\n"); 
		}
		
		void midshow()
		{
			printf("请输入需要转化的单位编号，并输入n，m，表示n*10^m\n");
		}
		
		void endshow()
		{
			printf("回车继续，Ctrl+Z回车退出\n");
		}
	
};


int main()
{
	show show_t;
	type length;
	// 初始化 
	int nn = 0;
	length.give("千米",nn++);
	length.give("米",nn++);
	length.give("分米",nn++);
	length.give("厘米",nn++);
	length.give("毫米",nn++);
	length.give("微米",nn++);
	length.give("英尺",nn++);
	length.give("英寸",nn++);
	length.give("码",nn++);
	length.give("英里",nn++);
	length.give("海里",nn++);
	length.give("英寻",nn++);
	length.give("弗隆",nn++);
	length.give("里",nn++);
	length.give("丈",nn++);
	length.give("尺",nn++);
	length.give("寸",nn++);
	length.give("分",nn++);
	length.give("厘",nn++);
	length.give("毫",nn++);
	nn = 1;
	length.give(1,3,nn++);
	length.give(1,4,nn++);
	length.give(1,5,nn++);
	length.give(1,6,nn++);
	length.give(1,9,nn++);
	length.give(3280.839895,0,nn++);
	length.give(39370.0787402,0,nn++);
	length.give(1093.6132983,0,nn++);
	length.give(0.6213712,0,nn++);
	length.give(0.5399568,0,nn++);
	length.give(546.8066492,0,nn++);
	length.give(4.9709695,0,nn++);
	length.give(2,0,nn++);
	length.give(3,2,nn++);
	length.give(3,3,nn++);
	length.give(3,4,nn++);
	length.give(3,5,nn++);
	length.give(3,6,nn++);
	length.give(3,7,nn++);// 长度 
	
	int a,b,c,d;
	double q;
	show_t.beginshow();
	cin >> a;
	length.show() ;
	show_t.midshow();
	
	
	show_t.endshow();

	while((getchar())!=EOF)
	{
		show_t.beginshow();
		show_t.midshow();
		show_t.endshow();
	}
	

	return 0;
}
