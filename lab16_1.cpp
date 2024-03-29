#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void  showData(double *data, int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0;i < N * M;i++)
    {
        cout << *(data + i);
        if((i + 1) % M == 0) cout << endl;
        else cout << " ";
    }
}
void randData(double *data, int N, int M){
    for(int i = 0;i < N * M;i++)
    {
       *(data + i) = rand()%101 / 100.00;
    }
}
void findRowSum(const double *data ,double *data2 ,int N,int M) 
{
    int i = 0  ;
    double sum = 0 ;
    for(int j = 0 ;j < N * M  ;j++ )
    {
         sum += *(data + j ) ;
         if (j % M == M-1 ) 
            {
            data2[i] = sum ;
            sum = 0 ;
            i++ ;
            }
    }
}
void findColSum(const double *data,double *data2,int N,int M){
    double x = 0;
    for(int i = 0;i < M ;i++)
    {
        for(int j = 0;j < N ;j++)
        {
            x = x + *(data + i + j * M);
        }
        *(data2+i)=x; 
        x=0;
    }
}
