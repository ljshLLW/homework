#include <iostream>
#include<cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <string>
#include <stdio.h>
using namespace std;
int  N;
int *a;
time_t start ,finish;
char name1[100];
char name2[100];
HANDLE handle1;

//直接插入排序
void DirectInsertSort(int a[],int len)
{
     int tmp,j;
     for(int i=1; i<len; i++)
     {
             tmp = a[i];
             for( j=i-1; j>=0 && a[j]>tmp; j--)
                a[j+1] = a[j];
             a[j+1] = tmp;
     }
}
//希尔排序
void ShellSort(int a[], int n)
{
        int i,j,gap;
        for(gap=n/2;gap>0;gap/=2)
            for(i=0;i<gap;i++)
                for(j=i+gap;j<n;j+=gap)
                {
                   if(a[j]<a[j-gap])
                   {
                           int tmp=a[j];
                           int k=j-gap;
                           while(k>=0 && a[k]>tmp)
                           {
                                   a[k+gap]=a[k];
                                   k-=gap;
                           }
                           a[k+gap]=tmp;
                   }
                }
}
//起泡排序
void BubbleSort(int a[], int len)
{
        for(int i=0;i<len;i++)
            for(int l=0;l<len-i-1;l++)
            {
                if(a[l]>a[l+1])
                {
                        int tmp=a[l];
                        a[l]=a[l+1];
                        a[l+1]=tmp;
                }
            }
}
//选择排序
void SelectionSort(int a[], int len)
{

        for(int i=0;i<len;i++)
        {
                int index=i;
                for(int l=i+1;l<len;l++)
                {
                       if(a[l]<a[index])
                           index=l;

                }
                if(index!=i)
                {
                        int tmp=a[i];
                        a[i]=a[index];
                        a[index]=tmp;
                }

        }
}
//快速排序
int QuickSort(int a[],int left,int right)
{
        if(left<right)
        {
                int key=a[left];
                int low=left,high=right;
                while(low<high)
                {
                        while(low<high && a[high]>key)
                        {
                                high--;
                        }
                        if(low<high)
                        {
                                a[low++]=a[high];
                        }
                        while(low<high && a[low]<key)
                        {
                                low++;
                        }
                        if(low<high)
                        {
                                a[high--]=a[low];
                        }

                }
                 a[low]=key;
                        QuickSort(a,left,low-1);
                        QuickSort(a,low+1,right);
        }
}

//堆排序
void HeapAdjust(int a[], int i, int size)//调整堆
{
        int Lchild = 2*i+1;
        int Rchild = 2*i+2;
        int max = i;
        if(i<=size/2)
        {
                if(Lchild<=size && a[Lchild]>a[max])
                        max=Lchild;
                if(Rchild<=size && a[Rchild]>a[max])
                        max=Rchild;
                if(max!=i)
                {
                    swap(a[i],a[max]);// algroithm里面的函数 作用是交换
                    HeapAdjust(a,max,size);
                }
        }
}
void BuildHeap(int a[], int size)// 构建堆
{
        for(int i=size/2-1;i>=0;i--)
            HeapAdjust(a,i,size);
}
void HeapSort(int a[], int size)//  堆排序
{
        BuildHeap(a,size);
        for(int i=size-1;i>0;i--)
        {
                swap(a[0],a[i]);
                HeapAdjust(a,0,i-1);
        }
}

//归并排序
void MergeArray(int a[], int first, int mid, int last, int temp[])
{
        int i=first, j=mid+1, m=mid, n=last, k=0;
        while(i<=m && j<=n)
        {
                if(a[i]<=a[j])
                   temp[k++]=a[i++];
                else
                   temp[k++]=a[j++];
        }
        while(i<=m)
             temp[k++]=a[i++];
        while(j<=n)
             temp[k++]=a[j++];
        for(i=0;i<k;i++)
            a[first+i]=temp[i];
}
void mergeSort(int a[],int first, int last, int temp[])
{
        if(first<last)
        {
                int mid = (first+last)/2;
                mergeSort(a,first,mid,temp);
                mergeSort(a,mid+1,last,temp);
                MergeArray(a,first,mid,last,temp);
        }
}
void MergeSort(int a[], int len)
{
        int *p = new int[len];
        mergeSort(a,0,len-1,p);
}
//创建随机数
void CreateRandomNum()
{
        srand(time(NULL));
        for(int i=0;i<N;i++)
                a[i]=rand()%1000;
}
//保存
void Save(char *name)
{
   ofstream ofile;
   ofile.open(name,ios::out);
   for(int i=0;i<N;i++)
   {
           ofile<<a[i]<<" ";
   }
   ofile.close();
}
//读取文件
void Read()
{
        int temp,i=0;
        ifstream ifile;
        ifile.open(name1,ios::in);
        while(ifile>>temp)
                a[i++]=temp;
        ifile.close();
}
void SetN()
{
        cout<<">_请输入您要设置的随机数大小"<<endl<<">_";
        int x;
        cin>>x;
        N=x;
        a = new int [N];
}

void RunTime()
{
   double runtime[7];
  SetConsoleTextAttribute(handle1, FOREGROUND_INTENSITY |FOREGROUND_BLUE );
   Read();
   start = clock();
   DirectInsertSort(a,N);
   finish = clock();
    runtime[0] = (double)(finish-start)/CLOCKS_PER_SEC;
     cout<<"插入排序 : "<<runtime[0]<<"s"<<endl; 

    Read();
    start = clock();
     ShellSort(a,N);
   finish = clock();
    runtime[1] = (double)(finish-start)/CLOCKS_PER_SEC;
     cout<<"希尔排序 : "<<runtime[1]<<"s"<<endl;

    Read();
    start = clock();
      BubbleSort(a,N);
   finish = clock();
    runtime[2] = (double)(finish-start)/CLOCKS_PER_SEC;
      cout<<"起泡排序 : "<<runtime[2]<<"s"<<endl; 

    Read();
    start = clock();
    SelectionSort(a,N);
    finish = clock();
    runtime[3] = (double)(finish-start)/CLOCKS_PER_SEC;
     cout<<"选择排序 : "<<runtime[3]<<"s"<<endl; 


    Read();
   start = clock();
    QuickSort(a,0,N);
   finish = clock();
   runtime[4] = (double)(finish-start)/CLOCKS_PER_SEC;
     cout<<"快速排序 : "<<runtime[4]<<"s"<<endl;

    Read();
    start = clock();
     HeapSort(a,N);
   finish = clock();
    runtime[5] = (double)(finish-start)/CLOCKS_PER_SEC;
       cout<<"堆排序 : "<<runtime[5]<<"s"<<endl;

    Read();
    start = clock();
     MergeSort(a,N);
   finish = clock();
    runtime[6] = (double)(finish-start)/CLOCKS_PER_SEC;
      cout<<"归并排序 : "<<runtime[6]<<"s"<<endl;
 SetConsoleTextAttribute(handle1, FOREGROUND_INTENSITY);

}
void Menu()
{
        cout<<"———————————————欢迎使用排序综合程序————————————————"<<endl;
        cout<<">_正在初始化程序..";
        Sleep(1000);
        cout<<".."<<endl;
         Sleep(1000);

         SetN();
        CreateRandomNum();
        cout<<">_随机数已经生成"<<endl;
        cout<<">_程序想要保存生成的数据请输入保存数据的文件名，请添加后缀名 .txt"<<endl;
        while(1)
        {
                cout<<">_";
                cin>>name1;
                char  namex[4];
                int  xx=0,slen=strlen(name1);
                for(int i=slen-4;i<=slen;i++)
                      namex[xx++]=name1[i];
                      namex[xx]='\0';
                if(strcmp(namex,".txt")==0)
                        break;
                else
                        cout<<">_您输入的格式不正确，请确保后缀为.txt"<<endl;

        }

        Save(name1);
        cout<<">_数据已经成功保存"<<endl;
         cout <<">_本程序包括七种算法，自动处理生成的数据，并计算排序花费的时间"<<endl
            <<">_                       0 采用七种方法排序并记录运行时间                              "<<endl
            <<">_                       1 直接插入排序                              "<<endl
            <<">_                       2 希尔排序                                  "<<endl
            <<">_                       3 起泡排序                                  "<<endl
            <<">_                       4 选择排序                                  "<<endl
            <<">_                       5 快速排序                                  "<<endl
            <<">_                       6 堆排序                                    "<<endl
            <<">_                       7 归并排序                                  "<<endl
            <<">_                       8 退出程序                                  "<<endl
            <<"       —————————作者：林静生寒  163401010414—————————                  "<<endl;
        while(1)
        {
                Read();
            cout<<">_随机数据已经准备完毕"<<endl;
        int num;
        cout<<">_请输入您选择的方法的序号 example：选择直接插入排序 输入 1 退出请输入 8"<<endl<<">_";
        while(1)
        {
                cin>>num;
                 if(num>8 || num<0)
                        cout<<">_请输入正确的序号"<<endl<<">_";
                 else
                        break;

        }
        start = clock();
        switch(num)
        {
        case 0:RunTime();break;
        case 1:DirectInsertSort(a,N);break;
        case 2:ShellSort(a,N);break;
        case 3:BubbleSort(a,N);break;
        case 4:SelectionSort(a,N);break;
        case 5:QuickSort(a,0,N);break;
        case 6:HeapSort(a,N);break;
        case 7:MergeSort(a,N);break;
        case 8: exit(0);
        }
        finish = clock();
        if(num!=0)
        {
          cout<<">_排序结束"<<">_此次所用时间为"<<endl;
        SetConsoleTextAttribute(handle1, FOREGROUND_INTENSITY | FOREGROUND_RED);
        printf("%.5f",(double)(finish-start)/CLOCKS_PER_SEC);
        cout<<"s"<<endl;
        SetConsoleTextAttribute(handle1, FOREGROUND_INTENSITY);
        cout<<">_程序将会保存此次排序结果,请输入保存文件的名称，请不要与已有文件冲突，此程序不做检查"<<endl;
         while(1)
        {
                cout<<">_";
                cin>>name2;
                char  namex[4];
                int  xx=0,slen=strlen(name2);
                for(int i=slen-4;i<=slen;i++)
                      namex[xx++]=name2[i];
                      namex[xx]='\0';
                if(strcmp(name1,name2)==0)
                        cout<<"您输入的文件名与保存随机数的文件名一致，请重新输入"<<endl;
                else if(strcmp(namex,".txt")==0)
                        break;
                else
                        cout<<">_您输入的格式不正确，请确保后缀为.txt"<<endl;

        }
        Save(name2);

        }

        }

}

int main()
{
        handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle1, FOREGROUND_INTENSITY);
        Menu();
}
