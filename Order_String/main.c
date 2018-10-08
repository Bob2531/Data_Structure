#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE+1]; /*  0号单元存放串的长度 */

/* 生成一个其值等于chars的串T */

Status StrAssign(String T,char *chars)
{
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);     //第0个位置存放字符串的长度
		for(i=1;i<=T[0];i++)    //剩下的空间存放字符
			T[i]=*(chars+i-1);
		return OK;
	}
}

/* 由串S复制得串T */
Status StrCopy(String T,String S)
{
    int i;
    for(i=0; i<=S[0]; i++)
        T[i] = S[i];
    return OK;
}

/* 若S为空串,则返回TRUE,否则返回FALSE */
Status StrEmpty(String S)
{
    if(S[0] == 0)
        return TRUE;
    else
        return FALSE;
}

/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
int StrCompare(String S,String T)
{
    int i;
    for(i=1; i<=S[0] && i<=T[0]; i++)
        if(S[i] != T[i])    //串不相等
            //printf("%c-%c = %d \n", S[i], T[i], S[i]-T[i]);
            return S[i]-T[i];
    printf("%d\n", S[0] - T[0]);
    return S[0] - T[0];
}

/* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
Status Concat(String T,String S1,String S2)
{
    int i;
    if(S1[0]+S2[0] <= MAXSIZE)    //未截断
    {
        for(i=1; i<=S1[0]; i++)
            T[i] = S1[i];
        for(i=1; i<=S2[0]; i++)
            T[S1[0]+i] = S2[i];
        T[0] = S1[0]+S2[0];     //新串的长度为原始串 S1, S2 串长度和
        return TRUE;
    }
    else    //发生截断 只能截断S2
    {
        for(i=1; i<=S1[0]; i++)
            T[i] = S1[i];
        for(i=1; i<=MAXSIZE-S1[0]; i++)
            T[S1[0]+i] = S2[i];
        T[0] = MAXSIZE;
        return FALSE;
    }
}

/*  初始条件: 串S和T存在,1≤pos≤StrLength(S)+1 */
/*  操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE */
Status StrInsert(String S,int pos,String T)
{
    int i;
    if(pos<0 || pos>S[0]+1)
    {
        printf("pos Illegle\n");
        return ERROR;
    }
    if(S[0]+T[0] <= MAXSIZE)    //没有发生溢出 则完全插入
    {
        //先进行后移操作
        for(i=S[0]; i>=pos; i--)
            S[i+T[0]] = S[i];
        //进行依次赋值操作 (插入操作)
        for(i=pos; i<=pos+T[0]; i++)
            S[i] = T[i-pos+1];
        S[0] = S[0]+T[0];       //长度重新赋值
        return TRUE;
    }
    else                        //发生溢出 部分插入
    {
        for(i=MAXSIZE; i<=pos; i--)
            S[i] = S[i-T[0]];   //依次后移
        for(i=pos; i<pos+T[0]; i++)
            S[i]=T[i-pos+1];
        S[0] = MAXSIZE;
        return FALSE;
    }
}

/* 返回串的元素个数 */
void StrLength(char name[10], String S)
{
    printf("Str %-8.10s length is %d \n", name, S[0]);
    //return S[0];
}

/* 初始条件:串S存在。操作结果:将S清为空串 */
Status ClearString(String S)
{
    S[0] = 0;   //串长度赋0
    return OK;
}

/* 用Sub返回串S的第pos个字符起长度为len的子串。 */
Status SubString(String Sub,String S,int pos,int len)
{
    int i;
    //判断是否合法 .. 1<=pos<=S[0] 0<len<S[0]-pos+1
    if(pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
        {printf("pos illegial\n");return ERROR;}
    for(i=1; i<len;i++)
    {
        Sub[i] = S[pos+i-1];
    }Sub[0] = len;
    return OK;
}

/* 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0。 */
/* 其中,T非空,1≤pos≤StrLength(S)。 */
int Index(String S, String T, int pos)
{
    int j=1;             //j为子串T的下标
    while(pos<=S[0] && j<=T[0])
    {
        if(S[pos] == T[j])    //字符匹配
        {
            pos++;
            j++;
        }
        else                //字符不匹配
        {
            pos = pos-j+2;  //pos指向先前匹配的下一个字符 既 pos - j +1 +1
            j = 1;          //j回退到T[0]首位
        }
    }
	if (j > T[0])
		return pos-T[0];
	else
		return 0;
}

void StrPrint(char name[10], String T)
{
    printf("Str %-8.10s is : ", name);
    int i, len;
    len = strlen(T);
    for(i=1; i<=T[0]; i++)
        printf("%c", T[i]);
    printf("\n");
}

int main()
{
    String T, Input, Str, TestStr, ConStr, Input_Str, SubStr, Index_Str, Insert_Str;
    printf("Input the string: ");
    gets(Input);        //输入字符串
    StrAssign(&T, "google is the best");
    StrAssign(&Input_Str, Input);
    StrCopy(&TestStr, T);
    StrPrint("TestStr", TestStr);
    printf("%d\n", StrCompare(Str ,T));
    StrLength("TestStr", TestStr);
    StrPrint("T", T);

    Concat(ConStr, TestStr, Str);
    StrPrint("ConStr", ConStr);

    SubString(SubStr, T, 1, 4);
    StrPrint("SubStr", SubStr);


    printf("%d\n", Index(T, Input_Str, 1));
    //StrPrint("Index_Str", )

    StrInsert(T, 6, Input_Str);
    StrPrint("T", T);

    return 0;
}
