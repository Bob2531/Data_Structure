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

#define MAXSIZE 40 /* �洢�ռ��ʼ������ */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */

typedef char String[MAXSIZE+1]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */

/* ����һ����ֵ����chars�Ĵ�T */

Status StrAssign(String T,char *chars)
{
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);     //��0��λ�ô���ַ����ĳ���
		for(i=1;i<=T[0];i++)    //ʣ�µĿռ����ַ�
			T[i]=*(chars+i-1);
		return OK;
	}
}

/* �ɴ�S���Ƶô�T */
Status StrCopy(String T,String S)
{
    int i;
    for(i=0; i<=S[0]; i++)
        T[i] = S[i];
    return OK;
}

/* ��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE */
Status StrEmpty(String S)
{
    if(S[0] == 0)
        return TRUE;
    else
        return FALSE;
}

/*  ��ʼ����: ��S��T���� */
/*  �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
int StrCompare(String S,String T)
{
    int i;
    for(i=1; i<=S[0] && i<=T[0]; i++)
        if(S[i] != T[i])    //�������
            //printf("%c-%c = %d \n", S[i], T[i], S[i]-T[i]);
            return S[i]-T[i];
    printf("%d\n", S[0] - T[0]);
    return S[0] - T[0];
}

/* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */
Status Concat(String T,String S1,String S2)
{
    int i;
    if(S1[0]+S2[0] <= MAXSIZE)    //δ�ض�
    {
        for(i=1; i<=S1[0]; i++)
            T[i] = S1[i];
        for(i=1; i<=S2[0]; i++)
            T[S1[0]+i] = S2[i];
        T[0] = S1[0]+S2[0];     //�´��ĳ���Ϊԭʼ�� S1, S2 �����Ⱥ�
        return TRUE;
    }
    else    //�����ض� ֻ�ܽض�S2
    {
        for(i=1; i<=S1[0]; i++)
            T[i] = S1[i];
        for(i=1; i<=MAXSIZE-S1[0]; i++)
            T[S1[0]+i] = S2[i];
        T[0] = MAXSIZE;
        return FALSE;
    }
}

/*  ��ʼ����: ��S��T����,1��pos��StrLength(S)+1 */
/*  �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE */
Status StrInsert(String S,int pos,String T)
{
    int i;
    if(pos<0 || pos>S[0]+1)
    {
        printf("pos Illegle\n");
        return ERROR;
    }
    if(S[0]+T[0] <= MAXSIZE)    //û�з������ ����ȫ����
    {
        //�Ƚ��к��Ʋ���
        for(i=S[0]; i>=pos; i--)
            S[i+T[0]] = S[i];
        //�������θ�ֵ���� (�������)
        for(i=pos; i<=pos+T[0]; i++)
            S[i] = T[i-pos+1];
        S[0] = S[0]+T[0];       //�������¸�ֵ
        return TRUE;
    }
    else                        //������� ���ֲ���
    {
        for(i=MAXSIZE; i<=pos; i--)
            S[i] = S[i-T[0]];   //���κ���
        for(i=pos; i<pos+T[0]; i++)
            S[i]=T[i-pos+1];
        S[0] = MAXSIZE;
        return FALSE;
    }
}

/* ���ش���Ԫ�ظ��� */
void StrLength(char name[10], String S)
{
    printf("Str %-8.10s length is %d \n", name, S[0]);
    //return S[0];
}

/* ��ʼ����:��S���ڡ��������:��S��Ϊ�մ� */
Status ClearString(String S)
{
    S[0] = 0;   //�����ȸ�0
    return OK;
}

/* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ��� */
Status SubString(String Sub,String S,int pos,int len)
{
    int i;
    //�ж��Ƿ�Ϸ� .. 1<=pos<=S[0] 0<len<S[0]-pos+1
    if(pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
        {printf("pos illegial\n");return ERROR;}
    for(i=1; i<len;i++)
    {
        Sub[i] = S[pos+i-1];
    }Sub[0] = len;
    return OK;
}

/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0�� */
/* ����,T�ǿ�,1��pos��StrLength(S)�� */
int Index(String S, String T, int pos)
{
    int j=1;             //jΪ�Ӵ�T���±�
    while(pos<=S[0] && j<=T[0])
    {
        if(S[pos] == T[j])    //�ַ�ƥ��
        {
            pos++;
            j++;
        }
        else                //�ַ���ƥ��
        {
            pos = pos-j+2;  //posָ����ǰƥ�����һ���ַ� �� pos - j +1 +1
            j = 1;          //j���˵�T[0]��λ
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
    gets(Input);        //�����ַ���
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
