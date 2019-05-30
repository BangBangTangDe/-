#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
//����fx
double fx(double x)
{
	if (x == 0)
		return 1;
	double y = sin(x)*1.0 / x;
	return y;
}
//�Զ��������ĸ������ι�ʽ
double complex_t()
{
	double *store;
	store= new double[30];
	memset(store, 0, sizeof(int) * 30);
	double a, b, e, h, T1, T2;
	double s = 0;
	int count = 0;
	int ans = 0;
	cout << "�Զ��������ĸ��������ʽ" << endl;
	cout << "���� ���� ���� ���� ���ֵ" << endl;
	cin >> a >> b >> e;
	
	h = b - a;
	T1 = h / 2 * (fx(a) + fx(b));
	store[ans++] = T1;
	while (true)
	{
		s = 0;
		double x = a + h / 2;
		while (x < b)
		{
			s += fx(x);
			x += h;
		}
		T2=T1 / 2 + h / 2 * s;
		store[ans++] = T2;
		if (abs(T2 - T1) < e)
			break;
		else
		{
			T1 = T2;
			h = h / 2;
			count++;
		}
	}
	cout << "�����Ĵ�����" << count << endl;
	cout << "=====���α�=====" << endl;
	for (int i = 0; i < ans; i++)
	{
		cout << "T" << i << ": " << store[i]   << endl;
	}
	cout << endl;
	return T2;
}
//romberg�㷨
void romberg()
{
	double ans[10][4] = { 0 };//�洢�������
	double a, b, e, h, T2, T1, S2, S1, C2, C1=0, R2, R1=0;//���� ���� ��� ��Χ ����ֵT1 T2 ����ɭֵ S1 S2 
	                                                     //����˹ֵ C1 C2 ������ֵ R1 R2
	int k; //����ת��
	double x,s;//x��ֵ s �����ֵ
	int count = 0;//������
	
	int Tcount = 0, Scount = 1, Ccount = 2, Rcount = 3; //���������� �������洢�������Ӧλ��

	cout << "========�������㷨==========" << endl;
	cout << "���� ���� ���� ���" << endl;
	cin >> a >> b >> e;
	h = b - a;
	T1 = h / 2 * (fx(a) + fx(b));
	ans[Tcount++][0] = T1;
	k = 1;
	while(true)
	{
		s = 0;
		double x = a + h / 2;
		while (x < b)
		{
			s += fx(x);
			x += h;
		}
		T2 = T1 / 2 + h / 2 * s;
		ans[Tcount++][0] = T2;
		S2 = (4*T2 - T1) / 3;
		ans[Scount++][1] = S2;
		if (k == 1)
		{
			k++; T1 = T2; S1 = S2; h = h / 2;
			count++;
			continue;
		}
		else
		{
			C2 = S2 + (S2 - S1) / 15; ans[Ccount++][2] = C2;
		}
		if (k == 2)
		{
			C1 = C2; k++; T1 = T2; S1 = S2; h = h / 2;
			count++;
			continue;
		}
		else
		{
			R2 = C2 + (C2 - C1) / 63; ans[Rcount++][3] = R2;
		}
		if (k == 3)
		{
			R1 = R2;
			C1 = C2; k++; T1 = T2; S1 = S2; h = h / 2;
			count++;
			continue;
		}
		
		if (abs(R2 - R1) < e)
			break;
		else
		{
			R1 = R2;
			C1 = C2; k++; T1 = T2; S1 = S2; h = h / 2;
			count++;
			continue;
		}

	}
	cout << "�����Ĵ���" << count << endl;
	cout << "�����������ֵ��";
	printf("%.10f", R2);
	
	cout << "�Ƿ�ѡ���ӡ����������㷨������α�Y/N" << endl;
	char choose;
	cin >> choose;
	if (choose == 'Y')
	{
		cout << "=======================���������α�======================" << endl;
		cout << "  T\t\t  S\t\t  C\t\t  R" << endl;
		for (int i = 0; i <= count; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (ans[i][j] == 0)
					cout << "\t\t";
				else
				{
					//cout << ans[i][j]<<"\t";
					printf("%.10f\t", ans[i][j]);
				}
				
			}
			cout << endl;
		}
	}
	else
		cout << "����" << endl;
	cout << endl;
}
int main()
{
	int a;
	cout << "��ֵ����\n 1.�������ι�ʽ \n 2.Romberg�㷨" << endl;
	while (1)
	{
		cin >> a;
		switch (a)
		{
		case 1:cout << "�ھ��ȷ�Χ�ڵĽ����";
			printf("%.10f",complex_t());
			break;
		case 2:romberg(); break;
		case 0:break;
		}
		if (a == 0)
			break;
	}

	return 0;
}