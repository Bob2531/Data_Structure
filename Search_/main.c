#include <stdio.h>
#include <stdlib.h>

void show(int arr[], int length)
{
    int i=0;
    while(i<=length)
        printf("%d\t", arr[i++]);
    printf("\n");
}
int CreatRandomArray(int *arr)
{
    int i;
    for (i=0; i<20; i++)
    {
        arr[i] = rand()%11;
        printf("%d ", arr[i]);
    }printf("%\n");
    return *arr;
}

int Sequential_Search(int *arr,int length, int key)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(arr[i]==key)
            return i;
    }
    return 0;
}

int Sequential_Search_Sentinel(int *arr, int length, int key)
{
    int i = length-1; //从末尾开始搜索
    arr[0] = key;   //设置哨兵 将主键赋值给数组第一个元素
    while(arr[i] != -1)//当没有找到 key 时继续查找 直到遇到哨兵为止
    {
        i--;
    }
    return i;
}

int Binary_Search(int *arr, int length, int key)
{
    show(arr, length);
    int low, high, mid, count=1;
    low = 0;
    high = length;
    mid = (low+high)/2;
    while(low <= high)
    {
        printf("low :%d\thigh :%d\t mid :%d\n", low, high, mid);
        mid = (low+high)/2; //更新mid值
        if(key>arr[mid])
        {
            low = mid+1;    //更新low值进行下一次折半查找
        }
        else if(key<arr[mid])
        {
            high = mid-1;
        }
//        else if(key == arr[mid])
//            return mid;
        else
            return mid;
        count++;

    }
    printf("count is %d\n", count);
    return mid;
}

//斐波那契查找
int Fibonacci_Search(int *arr, int length, int key)
{
    int low, high, mid, i, k;
    low = 1;
    high = length;
    k = 0;
    while(n>F[k]-1)
        k++;
    for(i=length; i<F{k}-1; i++)
        a[i] = a[length];
    while(low<=high)
    {
        mid = low + F[k-1]-1;   //计算当前分隔符的下标
        if(key<arr[mid])
        {
            high = mid-1;
            k = k-1;
        }
        else if(key>arr[mid])
        {
            low = mid+1;
            k = k+2;
        }
        else
        {
            if(mid<=n)
                return mid;
            else
                return length;
        }
    }
    return 0;
}

int main()
{
    srand(100);
    int length = 20, key, i;
    int a[length];
    int Order_arr[11] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    show(Order_arr, 11);
    CreatRandomArray(&a);
    printf("Input the key u want to Search:");
    scanf("%d", &key);
    //key = 35;
    printf("\nSequential_Search:\nfind %d is %d. If index is 0 then not find\n",
           key, Sequential_Search(&a, length, key));

    printf("\nSequential_Search_Sentinel:\nfind %d is %d. If index is 0 then not find\n",
           key, Sequential_Search_Sentinel(&a, length, key));
//    for(i=0; i<10; i++)
//        printf("\nBinary_Search:\nfind %d is %d. If index is 0 then not find\n",
//           Order_arr[i], Binary_Search(&Order_arr, 10, Order_arr[i]));
    printf("\nBinary_Search:\nfind %d is %d. If index is 0 then not find\n",
           key, Binary_Search(&Order_arr, 10, key));
    return 0;
}
