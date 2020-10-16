
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
///Структура предметов
struct subject {
	string name;
	int num; // кол-во пар в неделю
	string stype; // тип предмета
	int tId; // id преподавателя
};
///Структура преподавателей
struct tutor {
	int work[2][2];
	string name;
	string post; //должность
};
///Структура аудитории
struct audit {
	int aId;
	int num; // номер аудитории
	int vol; // объем аудитори
	int type; // тип аудитории компьютерная - 1; обычная - 0;
};
///структура расписания
struct shedule {
	string name;
	string tut;
	int aud;
};

void sort_sub(subject a[]) {//сортировка предметов по убыванию часов
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i; j++) {
			if (a[j].num < a[j + 1].num)
				swap(a[j], a[j + 1]);
		}
	}
}
void print_sub(subject a) {
	cout << '\t' << a.name << ":\n";
	cout << a.num << " pair in week\n";
	cout << a.stype << endl;
	cout << "tutor ID: " << a.tId << "\n";
}
subject* input_sub(subject a[]) {
	cout << "input subjects:\n";
	for (int i = 0; i < 3; i++) {
		cout << "subject " << i + 1 << ":\nenter name:";
		cin >> a[i].name;
		cout << "number pair in week: ";
		cin >> a[i].num;
		cout << "subject type (practic, lection): ";
		cin >> a[i].stype;
		cout << "tutor ID: ";
		cin >> a[i].tId;
		cout << endl;
	}
	return a;
}
void print_sub(subject a[]) {
	cout << "print subjects:\n";
	for (int i = 0; i < 3; i++) {
		print_sub(a[i]);
	}
	cout << endl;
}
tutor* input_tut(tutor a[]) {
	cout << "enter tutors:\n";
	for (int i = 0; i < 3; i++){
		cout << "enter name: ";
		cin >> a[i].name;
		cout << "enter position: ";
		cin >> a[i].post;
		for (int j = 0; j < 2; j++) {
			for (int h = 0; h < 2; h++) {
				cout << j + 1 << ", " << h + 1 << ": ";
				cin >> a[i].work[j][h];
			}
		}
	}
	return a;
}

int main()
{
	subject sub[3];
	tutor tut[3];
	shedule shed[4][5];
	audit aud[3];
	input_sub(sub);
	print_sub(sub);
	input_tut(tut);
	sort_sub(sub);
	cout << "after sort:\n";
	print_sub(sub);
	for (int i = 0; i < 3; ++i) {//цикл по предметам
		int tmp = sub[i].num;
		while (tmp > 2) { /// tut[sub[i].tId].work
			int mx = 0;
			int k = 0;
			for (int j = 0; j < 2; ++j) {
				int sum = 0;
				for (int h = 0; h < 2; ++h) {
					sum += tut[sub[i].tId].work[h][j];
				}
				if (sum > mx) {
					mx = sum;
					k = j;
				}
			}
			int l = 0;
			while (tut[sub[i].tId].work[l][k] == 0) {
				l++;//первая строка с единицей
			}
			shed[l][k].name = sub[i].name;
			shed[l][k].tut = tut[sub[i].tId].name;
			//в  массиве work пометить у преподавателя занятую пару нулем
			//tmp уменьшить на единицу
		}
	}
	cout << "after for:\n";
	print_sub(sub);
	system("pause");
	return 0;
}
