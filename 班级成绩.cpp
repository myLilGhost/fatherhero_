#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	int groups[3][5][4]={ { {95, 86, 89},{74, 93, 97},  {89, 73, 93}, {95, 85, 73}, {92, 73, 74} },
	{  {99, 98, 86}, {92, 95, 89},{85, 91, 95}, {81, 71, 90}, {85, 77, 78} },
	{  {98, 94, 90}, {98, 93, 91}, {89, 89, 86}, {79, 89, 78} ,{70, 74, 76}} };

	char name[3][5][10] =  {{"����","��һ","�Ŷ�","����","����"},
		                    {"����","����","��һ","����","����"},
							{"���","����","����","����","��һ"}};

	for( int m=0; m<3; m++ )  //��groups[][][3]�вɴ����ܷ�
{
	

	for ( int n=0; n<5; n++)
	{   
		
		
			groups[m][n][3] = groups[m][n][0] + groups[m][n][1] + groups[m][n][2];
		
       
	}
}

    int avr[3][4];   //����һ������洢�������ƽ����
	for( int p=0; p<3; p++ )  
{
	
   avr[p][0]= (groups[p][0][0] + groups[p][1][0] + groups[p][2][0] + groups[p][3][0] + groups[p][4][0])/5;
   avr[p][1]= (groups[p][0][1] + groups[p][1][1] + groups[p][2][1] + groups[p][3][1] + groups[p][4][1])/5;	
   avr[p][2]= (groups[p][0][2] + groups[p][1][2] + groups[p][2][2] + groups[p][3][2] + groups[p][4][2])/5;
   avr[p][3]= (groups[p][0][3] + groups[p][1][3] + groups[p][2][3] + groups[p][3][3] + groups[p][4][3])/5;

}




    for( int q=0; q<3; q++ )  //��ӡ�����༶����ƽ����
{
		cout<<"�༶"<<'\t'<<"����ƽ����"<<'\t'<<"��ѧƽ����"<<'\t'<<"Ӣ��ƽ����"<<'\t'<<"��ƽ����"<<endl;;
        cout<<q+1<<'\t';
		for( int p=0; p<4; p++ )  
		{
			cout<<avr[q][p]<<'\t'<<'\t';
		}

		cout<<endl;

}
	
	cout<<endl;

    for(int  i=0; i<3; i++ ) //�����ֽܷ����ӡ����ɼ���
{
	cout<<"�༶:"<<i+1<<endl;
	cout<<"����"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"�ܷ�"<<endl;
    
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

