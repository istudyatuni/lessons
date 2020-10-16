#include <iostream>
#include <string.h>
using namespace std;
struct subject{///Структура предметов
    string name;
    int num; // кол-во пар в неделю
    string stype; // тип предмета
    int tId; // id преподавателя
};
struct tutor{///Структура преподавателей
    int work[4][5];
    string name;
    string post; //должность
};
struct audit{///Структура аудитории
    int aId;
    int num; // номер аудитории
    int vol; // объем аудитории
    int type; // тип аудитории компьютерная - 1, обычная - 0
};
struct shedule{///структура расписания
    string name;
    string tut;
    int aud;
};
void sort_sub(subject a[]){//сортировка предметов по убыванию часов
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
                l++;//первая строка с единицей
            }
            shed[l][k].name = sub[i].name;
            shed[l][k].tut = tut[sub[i].tId].name;
            //в  массиве work пометить у преподавателя занятую пару нулем
            //tmp уменьшить на единицу
        }
    }
    int *temp = new int[5];
    for (int i = 0; i < 10; ++i){ int nm = sub[i].num;         //цикл по предметам
        while(nm > 2){
            int maks = 0, indmaks;
            for(int j = 0; j < 5; j++){
                for (int k = 0, temp[j] = 0; k < 4; ++k)
                    temp[j] += tut[sub[i].tId].work[j][k];
                if (temp[j] > maks) {
                    maks = temp[j];
                    indmaks = j;
                }
            }
            int k = 0;
            while(tut[sub[i].tId].work[k][indmaks] == 0)
                k++; // пропускаем нули в столбце ворк, ищем 1цу
            shed[k][indmaks].name = sub[i].name;
            tut[sub[i].tId].work[k][indmaks] = 0;
            while(tut[sub[i].tId].work[k][indmaks] == 0)
                k++;
            shed[k][indmaks].name = sub[i].name;
            tut[sub[i].tId].work[k][indmaks] = 0;
            nm -= 2;
        }
        while(nm > 0){
            int mins = 0, indmin;
            for(int j = 0; j < 5; j++){
                for (int k = 0, temp[j] = 0; k < 4; ++k)
                temp[j] += tut[sub[i].tId].work[j][k];
                if (temp[j] < mins && temp[j] > 0) {
                    mins = temp[j];
                    indmins = j;
                }
            }
            int k = 0;
            while(tut[sub[i].tId].work[k][indmins] == 0)
                k++; // пропускаем нули в столбце ворк, ищем 1цу
            shed[k][indmins].name = sub[i].name;
            tut[sub[i].tId].work[k][indmins] = 0;
            nm--;
        }
    }
    return 0;
}
