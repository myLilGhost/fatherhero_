#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	int groups[3][5][4]={ { {95, 86, 89},{74, 93, 97},  {89, 73, 93}, {95, 85, 73}, {92, 73, 74} },
	{  {99, 98, 86}, {92, 95, 89},{85, 91, 95}, {81, 71, 90}, {85, 77, 78} },
	{  {98, 94, 90}, {98, 93, 91}, {89, 89, 86}, {79, 89, 78} ,{70, 74, 76}} };

	char name[3][5][10] =  {{"张五","张一","张二","张三","张四"},
		                    {"王四","王三","王一","王五","王二"},
							{"李二","李四","李三","李五","李一"}};

	for( int m=0; m<3; m++ )  //在groups[][][3]中采存入总分
{
	

	for ( int n=0; n<5; n++)
	{   
		
		
			groups[m][n][3] = groups[m][n][0] + groups[m][n][1] + groups[m][n][2];
		
       
	}
}

    int avr[3][4];   //定义一个数组存储各班各科平均分
	for( int p=0; p<3; p++ )  
{
	
   avr[p][0]= (groups[p][0][0] + groups[p][1][0] + groups[p][2][0] + groups[p][3][0] + groups[p][4][0])/5;
   avr[p][1]= (groups[p][0][1] + groups[p][1][1] + groups[p][2][1] + groups[p][3][1] + groups[p][4][1])/5;	
   avr[p][2]= (groups[p][0][2] + groups[p][1][2] + groups[p][2][2] + groups[p][3][2] + groups[p][4][2])/5;
   avr[p][3]= (groups[p][0][3] + groups[p][1][3] + groups[p][2][3] + groups[p][3][3] + groups[p][4][3])/5;

}




    for( int q=0; q<3; q++ )  //打印各个班级各科平均分
{
		cout<<"班级"<<'\t'<<"语文平均分"<<'\t'<<"数学平均分"<<'\t'<<"英语平均分"<<'\t'<<"总平均分"<<endl;;
        cout<<q+1<<'\t';
		for( int p=0; p<4; p++ )  
		{
			cout<<avr[q][p]<<'\t'<<'\t';
		}

		cout<<endl;

}
	
	cout<<endl;

    for(int  i=0; i<3; i++ ) //按照总分降序打印各班成绩单
{
	cout<<"班级:"<<i+1<<endl;
	cout<<"姓名"<<'\t'<<"语文"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
    
	for ( int j=0; j<5; j++)
	{   
		cout<<name[i][j]<<'\t';

		for ( int k=0; k<4; k++ )
		{
			cout<<groups[i][j][k]<<'\t';
		}
       cout<<endl;
	}
   cout<<endl;
}
 return 0;

}

