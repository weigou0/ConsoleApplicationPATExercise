#include "stdafx.h"
#include "DataStructure.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

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
    int numCount = 0;
    int shiftCount = 0;
    scanf("%d %d", &numCount, &shiftCount);
    getchar();
    int numArray[100];
    for (int i = 0; i < numCount; i++)
    {
        scanf("%d", &numArray[i]);
    }

    for (int shift = 0; shift < shiftCount; shift++)
    {
        int temp = numArray[0];
        int temp2 = 0;
        numArray[0] = numArray[numCount - 1];
        for (int i = 0; i < (numCount - 1); i++)
        {
            temp2 = numArray[i + 1];
            numArray[i + 1] = temp;
            temp = temp2;
        }
    }
    
    for (int i = 0; i < numCount-1; i++)
    {
        printf("%d ", numArray[i]);
    }
    printf("%d", numArray[numCount - 1]);
    return 0;
}
int pat_basic_1009(void)
{
   // C++ Version!!!

   /* vector<string> vecString;
    string temp;
    char c;
    while (cin.get() != '\n')
    {
        cin.unget();
        cin >> temp;
        vecString.push_back(temp);
    }


    for (vector<string>::size_type i = vecString.size() - 1; i != 0; i--)
        cout << vecString[i] << " ";
    cout << vecString[0];*/
    return 0;
}
int pat_basic_1010(void)
{
    //vector<int> coefficient_index;
    //int temp;
    //while(cin.get() != '\n')
    //{
    //    cin.unget();
    //    cin >> temp;
    //    coefficient_index.push_back(temp);
    //}
    //for (vector<int>::iterator i = coefficient_index.begin(); i < coefficient_index.end(); )
    //{
        //    if((coefficient_index.end()-2) != i)
        //    {
        //        if (((*(i + 1)) != 0) && ((*(i + 1)) != 1))
        //        //if(((*(i + 1)) > 1)|| ((*(i + 1)) < 0))
        //        {
        //            cout << (*i) * (*(i + 1));
        //            cout << ' ';
        //            cout << (*(i + 1)) - 1;
        //            cout << ' ';
        //            i += 2;
        //        }
        //        else if ((*(i + 1)) == 1)
        //        {
        //            if ((*(i + 3)) == 0)
        //            {
        //                if((coefficient_index.end() - 4) <= i)
        //                {
        //                    cout << (*i) * (*(i + 1));
        //                    cout << ' ';
        //                    cout << (*(i + 1)) - 1;
        //                    i += 4;
        //                }
        //                else
        //                {
        //                    cout << (*i) * (*(i + 1));
        //                    cout << ' ';
        //                    cout << (*(i + 1)) - 1;
        //                    cout << ' ';
        //                    i += 4;
        //                }
        //                
        //            }
        //        }
        //        else if ((*(i + 1)) == 0)
        //        {
        //            cout << "0 0 ";
        //            i += 2;
        //        }
        //    }
        //    else
        //    {
        //            if ((*(i + 1)) != 0)
        //            {
        //                cout << (*i) * (*(i + 1));
        //                cout << ' ';
        //                cout << (*(i + 1)) - 1;
        //                i += 2;
        //            }
        //            else if ((*(i + 1)) == 0)
        //            {
        //                i += 2;
        //                cout << "0 0";
        //            }
        //               
        //    }
        //}
        
    int coefficient, index;
    int count = 0;
    int zeroFlag = 0;
    while (cin >> coefficient >> index)
    {
        if(index != 0)
        {
            if (zeroFlag == 1)
                cout << ' ';
            cout << coefficient*index << ' ' << index - 1;
            count++;
            zeroFlag = 1;
        }
    }
    if(count == 0)
    {
        cout << "0 0";
    }

    return EXIT_SUCCESS;
}
int pat_basic_1011(void)
{
    //should have a better method
    int count = 0;
    cin >> count;
    long a, b, c;
    long long sum;
    for (int i = 0; i < count; i++)
    {
        cin >> a >> b >> c;
        sum = a + b;
        if (sum > c)
        {
            cout << "Case #" << i + 1 << ": true" << endl;
        }
        else
        {
            cout << "Case #" << i + 1 << ": false" << endl;
        }
    }
    return EXIT_SUCCESS;
}
int pat_basic_1012(void)
{
    unsigned count;
    cin >> count;
    
    unsigned processedNumber;
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    bool A1Status = false, A2Status = false, A3Status = false, A4Status = false, A5Status = false;
    float A4 = 0;
    unsigned A4Count = 0;
    bool A2Flag = true;
    while(count != 0)
    {
        cin >> processedNumber;
        //A1
        if ((processedNumber % 5 == 0) && (processedNumber % 2 == 0))
        {
            A1 += processedNumber;
            A1Status = true;
        }
            
        //A2
        if(processedNumber % 5 == 1)
        {
            if(A2Flag)
            {
                A2 += processedNumber;
                A2Flag = false;
                A2Status = true;
            }
            else
            {
                A2 -= processedNumber;
                A2Flag = true;
                A2Status = true;
            }
        }
        //A3
        if (processedNumber % 5 == 2)
        {
            A3++;
            A3Status = true;
        }
           
        //A4 --> Sum
if (processedNumber % 5 == 3)
{
    A4 += processedNumber;
    A4Status = true;
    A4Count++;
}
//A5
if (processedNumber % 5 == 4)
{
    if (processedNumber > A5)
    {
        A5 = processedNumber;
        A5Status = true;
    }
}
count--;
    }
    //output
    if (A1Status)
        cout << A1 << ' ';
    else
        cout << "N ";


    if (A2Status)
        cout << A2 << ' ';
    else
        cout << "N ";

    if (A3Status)
        cout << A3 << ' ';
    else
        cout << "N ";

    if (A4Status)
    {
        cout << fixed << setprecision(1) << A4 / A4Count << ' ';
        //cout << A4;
    }
    else
        cout << "N ";


    if (A5Status)
        cout << A5;
    else
        cout << "N";
    return EXIT_SUCCESS;
}
int pat_basic_1013(void)
{
    //one test point overtime
    int pm, pn;
    cin >> pm >> pn;
    unsigned primeCount = 0;
    int primeCandidate = 2;
    int lineCount = 0;

    while (primeCount < pn)
    {
        bool primeStatus = true;
        for (int i = 1; i <= sqrt(primeCandidate) + 1; i++)
        {
            if (i != 1 && primeCandidate != i)
            {
                if ((primeCandidate % i == 0))
                {
                    primeStatus = false;
                }
            }

        }
        if (primeStatus)
        {
            primeCount++;
            if (primeCount >= pm && primeCount < pn && lineCount < 9)
            {
                cout << primeCandidate << ' ';
                lineCount++;
            }

            else if (primeCount >= pm)
            {
                cout << primeCandidate << endl;
                lineCount = 0;
            }

        }
        primeCandidate++;

    }
    return EXIT_SUCCESS;
}
int pat_basic_1014(void)
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    bool flagDay = false;
    bool flagHour = false;
    bool flagMinute = false;
    //int abCount = 0;
    int hourPosition = 0;
    for (string::size_type i = 0; i < a.length() && i < b.length(); i++)
    {
        if (a[i] == b[i] && isalnum(a[i]))
        {
            //abCount++;
            if (isupper(a[i]) && a[i] <= 'G') //a[i] <= 'G' is very important, there is only seven days in a week.
            {
                //day
                if (!flagDay)
                {
                    switch (a[i])
                    {
                    case 'A':
                        cout << "MON ";
                        break;
                    case 'B':
                        cout << "TUE ";
                        break;
                    case 'C':
                        cout << "WED ";
                        break;
                    case 'D':
                        cout << "THU ";
                        break;
                    case 'E':
                        cout << "FRI ";
                        break;
                    case 'F':
                        cout << "SAT ";
                        break;
                    case 'G':
                        cout << "SUN ";
                        break;
                    }
                    flagDay = true;
                    continue;
                }
            }


            //find hour
            if (flagDay && (!flagHour))
            {
                if ((isupper(a[i]) || isdigit(a[i])) && a[i] <= 'N') //same to days
                {
                    hourPosition = static_cast<int>(i);
                    flagHour = true;
                }
            }
        }
    }

    //print hour
    if (isdigit(a[hourPosition]))
    {
            cout << '0' << a[hourPosition] << ':';
    }
    if (isalpha(a[hourPosition]))
    {
        if(isupper(a[hourPosition]))
        {
            cout << static_cast<int>(a[hourPosition]) - static_cast<int>('A') + 10 << ':';
        }
        else if(islower(a[hourPosition]))
        {
            cout << static_cast<int>(a[hourPosition]) - static_cast<int>('a') + 10 << ':';
        }
        flagHour = true;
    }
    //minute
    for (string::size_type i = 0; i < c.length() && i < d.length(); i++)
    {
        if (isalpha(c[i]) && c[i] == d[i] && (!flagMinute))
        {
            if (i < 10)
                cout << '0' << i;
            else
                cout << i;
            flagMinute = true;
        }
    }
    return  EXIT_SUCCESS;
}
int pat_basic_1015(void)
{
    int totalStudent, minLine, priorityLine;
    cin >> totalStudent >> minLine >> priorityLine;

    
}