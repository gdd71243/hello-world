/*婊¤冻涓嬪垪鏉′欢鐨勮嚜鐒舵暟绉颁负瓒呯骇绱犳暟:璇ユ暟鏈韩,鎵€鏈夋暟瀛椾箣鍜?鎵€鏈夋暟瀛椾箣绉互鍙婃墍鏈夋暟瀛楃殑骞虫柟鍜岄兘鏄礌鏁?渚嬪113灏辨槸涓€涓秴绾х礌鏁?姹俒100,9999]涔嬪唴:(1)瓒呯骇绱犳暟鐨勪釜鏁?(2)鎵€鏈夎秴绾х礌鏁颁箣鍜?(3)鏈€澶х殑瓒呯骇绱犳暟.*/
#include<stdio.h>

int flag[10010];
int b[4];

void devide(int num)
{
	int i;
	for ( i=0; i<4; i++)
		b[i] = 0;
	i = 0;
	while ( num > 0)
	{
		b[i++] = num % 10;
		num = num / 10;
	}
}

int sum_bit(int num) {
	devide(num);
	return b[0]+b[1]+b[2]+b[3];
  	
}

int multi_bit(int num) {
	if( b[3]!=0)
		return b[0]*b[1]*b[2]*b[3];
	  	
	else
		return b[0]*b[1]*b[2];
	
}

int square_sum_bit(int num) {
	return b[0]*b[0]+b[1]*b[1]+b[2]*b[2]+b[3]*b[3];
}

int isprime(int num) {
	if ( flag[num])
		return 0;
	else
 	 	return 1;
}

int main() {
	int i,j;

	for (  i=2; i<=100; i++)
		if ( !flag[i] )
		{
			for (  j=2; j<=10010/i; j++)
				flag[i*j] = 1;
		
		}
	flag[0] = 1;
	flag[1] = 1;
	flag[2] = 1;
	int num=0,a[200],sum=0;
	for (  i=100; i<10000; i++)
		if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i)))
		{	
			sum += i;
			a[num++] = i;
		}
	printf("此区间超级素数一共有：%d个\n", num);
	printf("此区间超级素数的和为：%d\n", sum);
	printf("此区间最大的超级素数为：%d\n", a[num-1]);
    //to do sth
}
