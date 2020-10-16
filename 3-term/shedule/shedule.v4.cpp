//объедининие алгоритма из v3 и ввода из v2
//изменение типа функций для ввода на void
//добавление в ввод rand для отладки
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
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
	string post; //должность (степени) - senior lecturer, docent, academician, professor
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
	cout << "sorting . .\n";
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10 - i; j++){
			if (a[j].num < a[j+1].num)
				swap(a[j], a[j+1]);
			cout << i << '.' << j << "  ";
		}
		cout << '\n';
	}
}
void print_sub(subject a) {
	cout << "\n* * " << a.name << ":\n";
	cout << a.num << " pair in week\n";
	cout << a.stype << endl;
	cout << "tutor ID: " << a.tId << "\n";
}
void print_sub(subject a[]) {
	cout << "\ntable subjects:\n";
	for (int i = 0; i < 10; i++) {
		print_sub(a[i]);
	}
	cout << endl;
}
void print_tut(tutor a){
	cout << "tutor " << a.name << ", " << a.post;
	cout << "\nwork:\n";
	for (int j = 0; j < 4; j++) {
		for (int h = 0; h < 5; h++)
			cout << a.work[j][h] << ' ';
		cout << '\n';
	}
	cout << '\n';
}
void print_tut(tutor a[]){
	cout << "table tutors:\n";
	for (int i = 0; i < 10; i++) {
		print_tut(a[i]);
	}
	cout << '\n';
}
void input_sub(subject a[]) {
	srand(time(0));
	cout << "input subjects:\n";
	for (int i = 0; i < 10; i++) {
		cout << "\nsubject " << i + 1 << ":\nenter name:";
		cin >> a[i].name;
		//cout << "number pair in week: ";
		//cin >> a[i].num; //change to rand
		a[i].num = rand() % 4 + 1;
		cout << "number pair in week: " << a[i].num;
		cout << "\nsubject type (practic, lection): ";
		/*cin.get();
		char c;
		cin.get(c);
		if (c == 'l')
			a[i].stype = "lection";
		else if (c == 'p')
			a[i].stype = "practic";
		else a[i].stype = "lection";*/
		int c = rand() % 2;
		if (c == 0)
			a[i].stype = "lection";
		else if (c == 1)
			a[i].stype = "practic";
		cout << a[i].stype;
		//cout << "tutor ID: ";//change to rand
		//cin >> a[i].tId;
		a[i].tId = i;
		cout << "\ntId: " << a[i].tId;
		cout << '\n';
	}
	//return a;
}
void input_tut(tutor a[]) {
	srand(time(0));
	cout << "\nenter tutors:\n";
	for (int i = 0; i < 10; i++){
		cout << "\ntutor " << i + 1 << ":\nenter name:";
		cin >> a[i].name;
		cout << "position: ";//enter 
		int c = rand() % 4;
		if (c == 0)
			a[i].post = "senior lecturer";
		else if (c == 1)
			a[i].post = "docent";
		else if (c == 2)
			a[i].post = "academician";
		else if (c == 3)
			a[i].post = "professor";
		//cin >> a[i].post;
		cout << a[i].post << '\n';
		cout << "work:\n";
		for (int j = 0; j < 4; j++) {
			for (int h = 0; h < 5; h++) {
				//cout << j + 1 << ", " << h + 1 << ": ";
				//cin >> a[i].work[j][h];
				a[i].work[j][h] = rand() % 2;
				cout << a[i].work[j][h] << ' ';
			}
			cout << '\n';
		}
	}
	//return a;
}
int main()
{
	subject sub[10];
	tutor tut[10];
	shedule shed[4][5];
	audit aud[10];

	input_sub(sub);
	input_tut(tut);

	print_sub(sub);
	print_tut(tut);

	sort_sub(sub);
	cout << "after sort:\n";
	print_sub(sub);
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
	}
	system("pause");
	system("exit");
	return 0;
}
