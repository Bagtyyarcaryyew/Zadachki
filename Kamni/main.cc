/*
 * main.cc
 *
 *  Created on: 2 ���. 2022 �.
 *      Author: HP
 */
#include<iostream>
#include<limits>
#include<random>

int main()
{
	setlocale(0, "rus");
	std::cout << "���� \"�����\". "
			"�������: 2 ������ - ������ ���� �� �������. \n"
			"���� ����, � ��� N ������ (N = 10..20 - ���������� ��������� �������)\n"
			"�� ��� ����� ������ ����� 1, 2 ��� 5 �����.\n"
			"��� ������ ��������� ������ - ��������." << std::endl;
	std::default_random_engine rnd;
		std::random_device rdev;
		rnd.seed(rdev());
		std::uniform_int_distribution<> stones {10,20};
		std::uniform_int_distribution<> stnes {1,3};
 retry:
		int N=stones(rnd);
		 while (N > 0)
		    {
		        int x;
		        int m=5;

		        std::cout <<"� ���� "<< N << " ������" << std::endl;
		        do {
		        	menu_retry:
		            std::cout << "��� ���: " << std::endl;
		            if (not(std::cin>>x)){std::cout<<"������ �����"<<std::endl;
		            	std::cin.clear();
		            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		            	goto menu_retry;}
		            } while (x <=0 || x>m || x>N);
		        N -= x;
		        std::cout << N << " ������ � ����" << std::endl;
		        if (N == 0) {
		            std::cout << "�� ���������" << std::endl;
		        continue;
		        }
		        x = stnes(rnd) % m + 1;
		        if (x > N) x = N;
		        N -= x;
		        std::cout << "��� ���: -" << x << std::endl;
		        std::cout << N << " ������ � ����" << std::endl;
		        if (N == 0) {
		        	std::cout << "��������� ��������" << std::endl;
		        	 continue;
		        }}

     	std::cout << "������ �����?\n1 - ��, 0 - ���" << std::endl;
     	int c;
     	std::cin>>c;
		if (c==1) goto retry;
     	if (c==0) std::cout << "�� ��������!" << std::endl;


	return 0;
}





