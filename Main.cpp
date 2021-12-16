#include "Tree.h"

//--------------------------------������������� ������-������� ������----------------------------------------------------------------
/*
1) ����������� ����� �������-������ ������

2) ����������� ����������� ��� ������ �������:
    a)������������ +
    b)�����������  +
    c)������ ������:    ����������, +
                        ��������,   +
                        �����,      +
                        ����� ��������, +
                        ���������   +

3) �������� ��������� ��� ������������ ��������� ������ +

4) �������������� ����������� ���: (������� �������� ������� � ��������� ������) :D
    1) �� ������������������
    2) �� ����������� ������


----------------------testing-------------------------------
������������������ ������ �������� ���������� ������ ��������, +
                                   ������ ��������,  +
                                   ����������� �������� � ��������� +

����������������� ������ ������� �� ������ � ������������������  */

int main()
{
    std::cout << "Start\n";
    std::vector<int> nums{ 10,40,30,60,90,70,20,50,80,100 };
    std::vector<int> nums2{ 10,20,30,40,50,60,70,80,90,100 };
    RBTree tree1(nums2), tree2(nums);
    std::cout << "\nPrint\n";
    //for (auto it = tree1.begin(); it != tree1.end(); ++it)
    //{
      //  std::cout << *it << ' ';
    //}
    if (tree1.Search(35))
        std::cout << std::endl << tree1.Search(35)->_value << std::endl;
    else
        std::cout << "\nElement is not found\n";
    tree1.Remove(30);
    tree1.print();
    tree2.print();
    std::cout << "Min = " << tree1.Min()->_value << "\tMax = " << tree1.Max()->_value << std::endl;
    return 0;
}