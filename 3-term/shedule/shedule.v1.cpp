#include <iostream>
#include <string.h>

using namespace std;
///—труктура предметов
struct subject{
    string name;
    int num; // кол-во пар в неделю
    string stype; // тип предмета
    int tId; // id преподавател€
};
///—труктура преподавателей
struct tutor{
    int work[4][5];
    string name;
    string post; //должность
};
///—труктура аудитории
struct audit{
    int aId;
    int num; // номер аудитории
    int vol; // объем аудитори
    int type; // тип аудитории компьютерна€ - 1; обычна€ - 0;
};
///структура расписани€
struct shedule{
    string name;
    string tut;
    int aud;
};

void sort_sub(subject &a){//сортировка предметов по убыванию часов
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
    for (int i = 0; i < 10; ++i){//цикл по предметам
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
                l++;//перва€ строка с единицей
            }
            shed[l][k].name = sub[i].name;
            shed[l][k].tut = tut[sub[i].tId].name;
            //в  массиве work пометить у преподавател€ зан€тую пару нулем
            //tmp уменьшить на единицу
        }
    }
    return 0;
}
