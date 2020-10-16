#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
class subject {///класс предметов
	string name;
	int num; // кол-во пар в неделю
	string stype; // тип предмета
	int tId; // id преподавателя
public:
	subject(){};
	void print() {
		cout << "\n* * " << name << ":\n";
		cout << num << " pair in week\n";
		cout << stype << endl;
		cout << "tutor ID: " << tId << "\n";
	}
	void input(int i){
		cout << "\nsubject " << i + 1 << ":\nenter name:";
		cin >> name;
		num = rand() % 4 + 1;
		cout << "number pair in week: " << num;
		cout << "\nsubject type (practic, lection): ";
		int c = rand() % 2;
		if (c == 0)
			stype = "lection";
		else if (c == 1)
			stype = "practic";
		cout << stype;
		tId = i;
		cout << "\ntId: " << tId;
		cout << '\n';
	}
	friend void sort_sub(subject a[]);
	int getnum(){
		return num;
	}
};
class tutor {///преподаватели
	int work[4][5];
	string name;
	string post; //должность (степени) - senior lecturer
				//docent, academician, professor
public:
	tutor(){};
	void print(){
        cout << "tutor " << name << ", " << post;
        cout << "\nwork:\n";
        for (int j = 0; j < 4; j++) {
            for (int h = 0; h < 5; h++)
                cout << work[j][h] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    void input(int i){
    	cout << "\ntutor " << i + 1 << ":\nenter name:";
		cin >> name;
		cout << "position: ";//enter
		int c = rand() % 4;
		if (c == 0)
			post = "senior lecturer";
		else if (c == 1)
			post = "docent";
		else if (c == 2)
			post = "academician";
		else if (c == 3)
			post = "professor";
		//cin >> a[i].post;
		cout << post << '\n';
		cout << "work:\n";
		for (int j = 0; j < 4; j++) {
			for (int h = 0; h < 5; h++) {
				//cout << j + 1 << ", " << h + 1 << ": ";
				//cin >> a[i].work[j][h];
				work[j][h] = rand() % 2;
				cout << work[j][h] << ' ';
			}
			cout << '\n';
		}
    }
};
class audit {//аудитории
	int aId;
	int num; // номер аудитории
	int vol; // объем аудитории
	int type; // тип аудитории компьютерная - 1, обычная - 0
public:
	audit(){};
};
class shedule {//само расписание
	string name;
	string tut;
	int aud;
public:
	shedule(){};
};
void sort_sub(subject a[]){//сортировка предметов по убыванию часов
	cout << "sorting . .\n";
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10 - i - 1; j++){
			if (a[j].num < a[j+1].num)
				swap(a[j], a[j+1]);
			cout << i << '.' << j << "  ";
		}
		cout << '\n';
	}
}
void print_sub(subject a[]) {
	cout << "\ntable subjects:\n";
	for (int i = 0; i < 10; i++) {
		a[i].print();
	}
	cout << endl;
}
void print_tut(tutor a[]){
	cout << "table tutors:\n";
	for (int i = 0; i < 10; i++) {
		a[i].print();
	}
	cout << '\n';
}
void input_sub(subject a[]) {
	srand(time(0));
	cout << "input subjects:\n";
	for (int i = 0; i < 10; i++) {
		a[i].input(i);
	}
}
void input_tut(tutor a[]) {
	srand(time(0));
	cout << "\nenter tutors:\n";
	for (int i = 0; i < 10; i++){
		a[i].input(i);
	}
	//return a;
}
void calculate_shedule(subject &sub, tutor &tut, shedule &shed, audit &aud)
{
	/*for (int i = 0; i < 10; ++i){//цикл по предметам
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
	int temp[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < 10; ++i){ int nm = sub[i].num;         //цикл по предметам
		while(nm > 2){
			int maks = 0, indmaks;
			for(int j = 0; j < 5; j++){
				temp[j] = 0;
				for (int k = 0; k < 4; ++k)
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
				temp[j] = 0;
				for (int k = 0; k < 4; ++k)
				temp[j] += tut[sub[i].tId].work[j][k];
				if (temp[j] < mins && temp[j] > 0) {
					mins = temp[j];
					indmin = j;
				}
			}
			int k = 0;
			while(tut[sub[i].tId].work[k][indmin] == 0)
				k++; // пропускаем нули в столбце ворк, ищем 1цу
			shed[k][indmin].name = sub[i].name;
			tut[sub[i].tId].work[k][indmin] = 0;
			nm--;
		}
	}*/
}
int main()
{
	subject sub[10];
	subject &s = *sub;
	tutor tut[10], &t = tut[0];
	shedule shed[4][5], &sh = shed[0][0];
	audit aud[10], &a = aud[0];

	input_sub(sub);
	//input_tut(tut);

	print_sub(sub);


	//print_tut(tut);

	sort_sub(sub);
	cout << "after sort:\n";
	print_sub(sub);
	calculate_shedule(s, t, sh ,a);
	/*
	system("pause");
	system("exit");*/
	return 0;
}
