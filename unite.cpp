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
			doit();
		}
		void doit()
		{
			int a,b,c;
			double k;
			cin >> a >> b >> k >> c;
		
			printf("%lf * 10^%d %s",k,c);
			cout << name[a];
			printf(" = %lf * 10^%d ",k*num[a][b], c+ten[a][b]);
			cout << name[b] <<  endl;
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
			printf("请输入需要转化的单位类型编号并回车：\n1.长度 2.面积 3.体积 4.质量 5.力 6.时间 7.角度 8.数据储存 0.退出\n"); 
		}
		
		void midshow()
		{
			printf("请输入需要转化的单位编号，并输入n，m，表示n*10^m\n");
		}
		
	/*	void endshow()
		{
			printf("回车继续，Ctrl+Z回车退出\n");
		}*/
	
};


int main()
{
	show show_t;
	type length, acreage , volume,mass,power, time,angle, data;
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
	nn = 0;
	acreage.give("平方千米",nn++);
	acreage.give("公顷",nn++);
	acreage.give("公亩",nn++);
	acreage.give("平方米",nn++);
	acreage.give("平方分米",nn++);
	acreage.give("平方厘米",nn++);
	acreage.give("平方毫米",nn++);
	acreage.give("英亩",nn++);
	acreage.give("平方英里",nn++);
	acreage.give("平方英尺",nn++);
	acreage.give("平方竿",nn++);
	acreage.give("顷",nn++);
	acreage.give("亩",nn++);
	acreage.give("分",nn++);
	acreage.give("平方尺",nn++);
	acreage.give("平方寸",nn++);
	nn=1;
	acreage.give(1,2,nn++);
	acreage.give(1,4,nn++);
	acreage.give(1,6,nn++);
	acreage.give(1,8,nn++);
	acreage.give(1,10,nn++);
	acreage.give(1,12,nn++);
	acreage.give(247.1053815,0,nn++);
	acreage.give(0.3861022,0,nn++);
	acreage.give(1.0764,7,nn++);
	acreage.give(3.9537,4,nn++);
	acreage.give(1.5,1,nn++);
	acreage.give(1.5,3,nn++);
	acreage.give(1.5,4,nn++);
	acreage.give(9,6,nn++);
	acreage.give(9,8,nn++);
	//面积 
	
	nn = 0;
	volume.give("立方米",nn++);
	volume.give("立方分米",nn++);
	volume.give("立方厘米",nn++);
	volume.give("立方毫米",nn++);
	volume.give("升",nn++);
	volume.give("分升",nn++);
	volume.give("毫升",nn++);
	volume.give("厘升",nn++);
	volume.give("公石",nn++);
	volume.give("微升",nn++);
	volume.give("立方英尺",nn++);
	volume.give("立方英寸",nn++);
	volume.give("立方码",nn++);
	volume.give("亩英尺",nn++);
	volume.give("英制加仑",nn++);
	volume.give("美制加仑",nn++);
	volume.give("英制液体盎司",nn++);
	volume.give("美制液体盎司",nn++);
	nn=1;
	volume.give(1,3,nn++);
	volume.give(1,6,nn++);
	volume.give(1,9,nn++);
	volume.give(1,3,nn++);
	volume.give(1,4,nn++);
	volume.give(1,6,nn++);
	volume.give(1,5,nn++);
	volume.give(1,1,nn++);
	volume.give(1,9,nn++);
	volume.give(3.5315,1,nn++);
	volume.give(6.1024,4,nn++);
	volume.give(1.307953,0,nn++);
	volume.give(8.107,-4,nn++);
	volume.give(2.199692,2,nn++);
	volume.give(2.641721,2,nn++);
	volume.give(3.519887,4,nn++);
	volume.give(3.416467,4,nn++);	
	nn=0;
	mass.give("千克",nn++);
	mass.give("克",nn++);
	mass.give("毫克",nn++);
	mass.give("微克",nn++);
	mass.give("吨",nn++);
	mass.give("公担",nn++);
	mass.give("克拉",nn++);
	mass.give("分",nn++);
	mass.give("磅",nn++);
	mass.give("盎司",nn++);
	mass.give("英制克拉",nn++);
	mass.give("格令",nn++);
	mass.give("长吨",nn++);
	mass.give("短吨",nn++);
	mass.give("英担",nn++);
	mass.give("美担",nn++);
	mass.give("英石",nn++);
	mass.give("打兰",nn++);
	mass.give("担",nn++);
	mass.give("斤",nn++);
	mass.give("两",nn++);
	mass.give("钱",nn++);
	nn=1;
	mass.give(1,3,nn++);
	mass.give(1,6,nn++);
	mass.give(1,9,nn++);
	mass.give(1,-3,nn++);
	mass.give(1,-2,nn++);
	mass.give(5,3,nn++);
	mass.give(5,5,nn++);
	mass.give(2.204623,0,nn++);
	mass.give(3.527396,1,nn++);
	mass.give(5,3,nn++);
	mass.give(1.543236,4,nn++);
	mass.give(9.842,-4,nn++);
	mass.give(1.1023,-3,nn++);
	mass.give(1.96841,-2,nn++);
	mass.give(2.20462,-2,nn++);
	mass.give(1.57473,-1,nn++);
	mass.give(5.643834,2,nn++);
	mass.give(2,-2,nn++);
	mass.give(2,0,nn++);
	mass.give(2,1,nn++);
	mass.give(2,2,nn++);//质量 
	
	nn=0;
	power.give("牛",nn++);
	power.give("千克力",nn++);
	power.give("克力",nn++);
	power.give("磅力",nn++);
	power.give("达因",nn++);
	
	nn=1;
	power.give(1.019716,-1,nn++);
	power.give(1.019716,2,nn++);
	power.give(2.248089,-1,nn++);
	power.give(1,5,nn++);//力 
	
	nn=0;
	time.give("年",nn++);
	time.give("周",nn++);
	time.give("天",nn++);
	time.give("时",nn++);
	time.give("分",nn++);
	time.give("秒",nn++);
	time.give("毫秒",nn++);
	time.give("微秒",nn++);
	time.give("纳秒",nn++);
	
	nn=1;
	time.give(5.214285,1,nn++);
	time.give(3.649999,2,nn++);
	time.give(8.760,3,nn++);
	time.give(5.256,5,nn++);
	time.give(3.1536,7,nn++);
	time.give(3.1536,10,nn++);
	time.give(3.1536,13,nn++);
	time.give(3.1536,16,nn++);//时间 
	
	nn=0;
	angle.give("圆周",nn++);
	angle.give("度",nn++);
	angle.give("分",nn++);
	angle.give("秒",nn++);
	angle.give("弧度",nn++);
	
	nn=1;
	angle.give(3.6,2,nn++);
	angle.give(2.16,4,nn++);
	angle.give(1.296,6,nn++);
	angle.give(6.283185,0,nn++);//角度 
	
	nn=0;
	data.give("比特",nn++);
	data.give("字节",nn++);
	data.give("千字节",nn++);
	data.give("兆字节",nn++);
	data.give("千兆字节",nn++);
	data.give("太字节",nn++);
	data.give("拍字节",nn++);
	data.give("艾字节",nn++);
	
	nn=1;
	data.give(1.25,-1,nn++);
	data.give(1.221,-4,nn++);
	data.give(1.1921,-7,nn++);
	data.give(1.1642,-10,nn++);
	data.give(1.1369,-13,nn++);
	data.give(1.1102,-16,nn++);
	data.give(1.0842,-19,nn++);//数据 
	length.change() ;
	acreage.change();
	volume.change();
	mass.change();
	power.change() ;
	time.change();
	angle.change();
	data.change();
	int a,b,c,d;
	double q;
	bool flag = false;
	show_t.beginshow();
	while (  !flag && (scanf("%d", &a)) != EOF )
	{//length, acreage , volume,mass,power, time,angle, data
		show_t.midshow();
		switch(a)
		{
			case 1: length.show() ; break;
			case 2:	acreage.show() ; break;
			case 3:	volume.show() ; break;
			case 4:	mass.show() ; break;
			case 5:	power.show() ; break;
			case 6:	time.show() ; break;
			case 7:	angle.show() ; break;
			case 8:	data.show() ; break;						
			case 0:	flag = true;	break;
		}
	//	show_t.endshow();
		if ( !flag)
			show_t.beginshow();
	}	
		
		
	

	return 0;
}
