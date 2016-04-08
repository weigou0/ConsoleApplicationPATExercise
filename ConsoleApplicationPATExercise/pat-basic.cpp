#include "stdafx.h"
#include "DataStructure.h"
#include <math.h>


void test(void) {
	printf("hello"); 
	//return 0;
}

//1004
/*
1004. �ɼ�����(20)

����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�
\�����ʽ:ÿ�������������1����������,��ʽΪ
��1��:������n
��2��:��1��ѧ�������� ѧ�� �ɼ�
��3��:��2��ѧ�������� ѧ�� �ɼ�
... ... ...
��n + 1��:��n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ:��ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

��������:
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
�������:
Mike CS991301
Joe Math990112
*/
int pat_basic_1004(void) 
{
	int n = 0;

	//read
	if(scanf("%d",&n) == 1)
	{
		stu_info_1004_pt start = (stu_info_1004_pt)malloc(sizeof(stu_info_1004));
		stu_info_1004_pt p = start;
		//1 <--> (n-1)
		for (int i = 0; i < n-1; i++)
		{
			//if(scanf("%s", p->stu_name_c)||scanf("%s", p->stu_number_c)||scanf("%d",p->stu_score_i));
			if (scanf("%s %s %d", &(p->stu_name_c), &(p->stu_number_c), &(p->stu_score_i)) == 3);
			else
			{
				printf("READ ERROR!");
				return -1;
			}
			stu_info_1004_pt temp_pt = (stu_info_1004_pt)malloc(sizeof(stu_info_1004));
			p->next_stu_info_pt = temp_pt;
			p = temp_pt;
		}
		//n
		if (scanf("%s %s %d", &(p->stu_name_c), &(p->stu_number_c), &(p->stu_score_i)))
			p->next_stu_info_pt = nullptr;
		else
		{
			printf("READ ERROR!");
			return - 1;
		}
		//sort
		stu_info_1004_pt max = nullptr, min = nullptr;
		stu_info_1004_pt temp_pt = start;
		int score_max_i = 0;
		//find max score
		for (int i = 0; i < n; i++)
		{
			if(temp_pt->stu_score_i >= score_max_i)
			{
				score_max_i = temp_pt->stu_score_i;
				max = temp_pt;
				temp_pt = temp_pt->next_stu_info_pt;
			}
			else
			{
				temp_pt = temp_pt->next_stu_info_pt;
			}
		}
		//find min score
		temp_pt = start;
		int score_min_i = 100;
		for (int i = 0; i < n; i++)
		{
			if (temp_pt->stu_score_i <= score_min_i)
			{
				score_min_i = temp_pt->stu_score_i;
				min = temp_pt;
				temp_pt = temp_pt->next_stu_info_pt;
			}
			else
			{
				temp_pt = temp_pt->next_stu_info_pt;
			}
		}


		//output

		//max
		printf("%s %s\n", max->stu_name_c, max->stu_number_c);
		//min
		printf("%s %s", min->stu_name_c, min->stu_number_c);
		//free node
		temp_pt = start;
		for (int i = 0; i < n; i++)
		{
			if(temp_pt->next_stu_info_pt != nullptr)
			{
				stu_info_1004_pt next_pt = temp_pt->next_stu_info_pt;
				free(temp_pt);
				temp_pt = next_pt;
			}
			else if(temp_pt->next_stu_info_pt == nullptr)
			{
				free(temp_pt);
			}
			else return -1;
		}

		return 0;
	}
	else return -1;


}

//1005
/*
1005. ����(3n+1)���� (25)

������(Callatz)����
���κ�һ����Ȼ��n,�������ż��,��ô��������һ��,�����������,��ô��(3n+1)����һ�롣����һֱ��������ȥ,���һ����ĳһ���õ�n=1��

��������֤�����Ȳ����ʱ��,Ϊ�˱����ظ�����,���Լ�¼�µ��ƹ�����������ÿһ�����������n=3������֤��ʱ��������Ҫ����3��5��8��4��2��1,�����Ƕ�n=5��8��4��2������֤��ʱ��Ϳ���ֱ���ж������Ȳ������α,������Ҫ�ظ�����.��Ϊ��4�����Ѿ�����֤3��ʱ����������.���ǳ�5��8��4��2�Ǳ�3�����ǡ����������ǳ�һ�������е�ĳ����nΪ���ؼ�����.���n���ܱ������е��������������ǡ�

���ڸ���һϵ�д���֤������,����ֻ��Ҫ��֤���еļ����ؼ���,�Ϳ��Բ������ظ���֤���µ����֡������������ҳ���Щ�ؼ�����,�����Ӵ�С��˳��������ǡ�

�����ʽ:ÿ�������������1��������������1�и���һ��������K(<100),��2�и���K��������ͬ�Ĵ���֤��������n(1<n<=100)��ֵ�����ּ��ÿո������

�����ʽ:ÿ���������������ռһ�У����Ӵ�С��˳������ؼ����֡����ּ���1���ո��������һ�������һ�����ֺ�û�пո�

��������:
6
3 5 6 7 8 11
�������:
7 6
*/
//PAT����Ŀ��ô���Ǻ������Ĳ�һ��...Son of biscuit
int pat_basic_1005(void)
{
    int n = 0;
    int array_i[101];
    for (int i = 0; i < 101; i++)
        array_i[i] = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp_i = 0;
        scanf("%d", &temp_i);
        array_i[temp_i] = 1;
    }


    return 0;
}


//1006
/*
1006. ������ʽ������� (15)

����������ĸB����ʾ���١�����ĸS��ʾ��ʮ��,�á�12...n������ʾ��λ����n(<10).������ʽ�������һ��������3λ��������������234Ӧ�ñ����ΪBBSSS1234,��Ϊ����2�����١���3����ʮ�����Լ���λ��4��

�����ʽ��ÿ�������������1����������,����������n(<1000)��

�����ʽ��ÿ���������������ռһ�У��ù涨�ĸ�ʽ���n��

��������1��
234
�������1��
BBSSS1234
��������2��
23
�������2��
SS123
*/
int pat_basic_1006(void)
{
    int n;
    scanf("%d", &n);
    int hundred, ten, one;
    hundred = (int)n / 100;
    ten = (int)((n - hundred * 100) / 10);
    one = (int)(n - hundred * 100 - ten * 10);


    for (int i = 1; i <= hundred;i++)
    {
        printf("B");
    }
    for (int i = 1; i <= ten; i++)
    {
        printf("S");
    }
    for (int i = 1; i <= one; i++)
    {
        printf("%d", i);
    }
    return 0;
}
int pat_basic_1007(void)
{
    long n;
    scanf("%d", &n);
    long Prime[10000];
    int primeNum = 0;
    int primePair = 0;
    for (long possiblePrime = 2; possiblePrime <= n; possiblePrime++)
    {
        bool isPrime = true;
        for (long possibleFactor = 2; possibleFactor <= (long)sqrt(possiblePrime); possibleFactor++)
        {
            if ((possiblePrime%possibleFactor) == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            Prime[primeNum] = possiblePrime;
            primeNum++;
        }
    }
    for (int i = 1; i < primeNum; i++)
    {
        if ((Prime[i] - Prime[i - 1]) == 2)
            primePair++;
    }
    printf("%d", primePair);
    return 0;
}
int pat_basic_1008(void)
{
    return 0;
}