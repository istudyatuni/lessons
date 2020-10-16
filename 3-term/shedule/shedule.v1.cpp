#include <iostream>
#include <string.h>

using namespace std;
///��������� ���������
struct subject{
    string name;
    int num; // ���-�� ��� � ������
    string stype; // ��� ��������
    int tId; // id �������������
};
///��������� ��������������
struct tutor{
    int work[4][5];
    string name;
    string post; //���������
};
///��������� ���������
struct audit{
    int aId;
    int num; // ����� ���������
    int vol; // ����� ��������
    int type; // ��� ��������� ������������ - 1; ������� - 0;
};
///��������� ����������
struct shedule{
    string name;
    string tut;
    int aud;
};

void sort_sub(subject &a){//���������� ��������� �� �������� �����
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10 - i; j++){
            if (a[j].num < a[j+1].num)
                swap(a[j], a[j+1]);
        }
    }
}
void print_sub(subject a){
    cout << "subject: " << a.name << endl;
    cout << a.num << "in week\n";
    cout << a.stype << endl;
}
int main()
{
    subject sub[10];
    tutor tut[10];
    shedule shed[4][5];
    audit aud[10];
    sort_sub(sub);
    for (int i = 0; i < 10; ++i){//���� �� ���������
        int tmp = sub[i].num;
        while (tmp > 2){ /// tut[sub[i].tId].work
            int mx = 0;
            int k = 0;
            for (int j = 0; j < 5; ++j){
                int sum = 0;
                for (int h = 0; h < 4; ++h){
                    sum += tut[sub[i].tId].work[h][j];
                }
                if (sum > mx){
                    mx = sum;
                    k = j;
                }
            }
            int l = 0;
            while (tut[sub[i].tId].work[l][k] == 0){
                l++;//������ ������ � ��������
            }
            shed[l][k].name = sub[i].name;
            shed[l][k].tut = tut[sub[i].tId].name;
            //�  ������� work �������� � ������������� ������� ���� �����
            //tmp ��������� �� �������
        }
    }
    return 0;
}
