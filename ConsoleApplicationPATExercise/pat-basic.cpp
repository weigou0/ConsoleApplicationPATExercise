#include "stdafx.h"
#include "DataStructure.h"
#include <math.h>


void test(void) {
	printf("hello"); 
	//return 0;
}

//1004
/*
1004. 成绩排名(20)

读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
\输入格式:每个测试输入包含1个测试用例,格式为
第1行:正整数n
第2行:第1个学生的姓名 学号 成绩
第3行:第2个学生的姓名 学号 成绩
... ... ...
第n + 1行:第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式:对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例:
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例:
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
1005. 继续(3n+1)猜想 (25)

卡拉兹(Callatz)猜想
对任何一个自然数n,如果它是偶数,那么把它砍掉一半,如果它是奇数,那么把(3n+1)砍掉一半。这样一直反复砍下去,最后一定在某一步得到n=1。

当我们验证卡拉兹猜想的时候,为了避免重复计算,可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1,则当我们对n=5、8、4、2进行验证的时候就可以直接判定卡拉兹猜想的真伪,而不需要重复计算.因为这4个数已经在验证3的时候遇到过了.我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”.如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字,我们只需要验证其中的几个关键数,就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字,并按从大到小的顺序输出它们。

输入格式:每个测试输入包含1个测试用例，第1行给出一个正整数K(<100),第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。

输出格式:每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

输入样例:
6
3 5 6 7 8 11
输出样例:
7 6
*/
//PAT的题目怎么老是和人理解的不一样...Son of biscuit
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
1006. 换个格式输出整数 (15)

让我们用字母B来表示“百”、字母S表示“十”,用“12...n”来表示个位数字n(<10).换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234,因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例,给出正整数n(<1000)。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
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