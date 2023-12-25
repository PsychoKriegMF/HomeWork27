#include <iostream>
#include <string>


struct Movie {
	std::string title{"empty"};    // название фильма
	int year{ 0 };                 // год выхода
	std::string genre{"empty"};    // жанр
	unsigned int duration{ 0 };    //продолжительность в минутах
	unsigned int budget{ 0 };      // бюджет фильма 
	int fees{ 0 };                 // сборы 
};
void print_movie_name(Movie arr[], const int length) { 
	std::cout << "Доступные фильмы:\n";                      //Вывод названий фильмов
	for (int i = 0; i < length; i++) {
		std::cout << i+1 << '.' << arr[i].title << std::endl;
	}
}
void print_movie(const Movie& M) {                    // Вывод информации о фильме
	std::cout << "\nИнформация о фильме : \n\n";
	std::cout << "1.Название фильма: " << '\t' << M.title << std::endl;
	std::cout << "2.Дата выхода: " << "\t\t" << M.year << std::endl;
	std::cout << "3.Жанр: " << "\t\t" << M.genre << std::endl;
	std::cout << "4.Время: " << "\t\t" << M.duration << std::endl;
	std::cout << "5.Бюджет: " << "\t\t" << M.budget << " $" << std::endl;
	std::cout << "6.Сборы: " << "\t\t" << M.fees << " $" << std::endl;
	std::cout << std::endl;
}
void update_info(Movie& M) {
	int position_update;
	std::cout << "Какой пункт изменить? -> ";
	std::cin >> position_update;
	std::cin.ignore();
	switch (position_update) {
	case 1: std::cout << "Измените имя -> ";
		std::getline(std::cin, M.title); break;	
	case 2: std::cout << "Измените дату выхода -> ";
		std::cin >> M.year; break;
	case 3: std::cout << "Измените жанр -> ";
		std::getline(std::cin, M.genre); break;
	case 4: std::cout << "Измените время -> ";
		std::cin >> M.duration; break;
	case 5: std::cout << "Измените бюджет -> ";
		std::cin >> M.budget; break;
	case 6: std::cout << "Измените сборы -> ";
		std::cin >> M.fees; break;
	}
	std::cout << "Изменения сохранены!\n";
	system("pause");
	system("cls");
}


Movie expensive( Movie arr[], const int length) {
	int number = 0; // для фиксации номера объекта структцры в массиве
	int max = arr[0].fees;
	for (int i = 0; i < length; i++)
		if (arr[i].fees > max) {
			max = arr[i].fees;			
			number = i;
		}	
	return arr[number];

}


int main() {
	setlocale(LC_ALL, "ru");
	

	Movie MIB;
	MIB.title = "Люди в черном";
	MIB.year = 1997;
	MIB.genre = "фантастика, боевик, комедия, приключения";
	MIB.duration = 98;
	MIB.budget = 90000000;
	MIB.fees = 589390539;

	Movie MIB2;
	MIB2.title = "Люди в черном 2";
	MIB2.year = 2002;
	MIB2.genre = "фантастика, боевик, комедия, приключения";
	MIB2.duration = 88;
	MIB2.budget = 190000000;
	MIB2.fees = 441818803;

	Movie MIB3;
	MIB3.title = "Люди в черном 3";
	MIB3.year = 2012;
	MIB3.genre = "фантастика, боевик, комедия, приключения";
	MIB3.duration = 106;
	MIB3.budget = 215000000;
	MIB3.fees = 624026776;

	Movie MIBinternational;
	MIBinternational.title = "Люди в черном: интернэшнл";
	MIBinternational.year = 2019;
	MIBinternational.genre = "фантастика, боевик, комедия, приключения";
	MIBinternational.duration = 114;
	MIBinternational.budget = 110000000;
	MIBinternational.fees = 253890701;

	
	const int size = 4;
	Movie object[size]{ MIB,MIB2,MIB3,MIBinternational };
	bool go = true;
	while (go) {                  //Делаем цикл чтобы пользоваться в рамках одной сессии
		
		print_movie_name(object, size);
		std::cout << std::endl;
		std::cout << "Введите номер фильма о котором нужна информация или введите 0 для продолжения -> ";
		int number_film;
		int update;
		std::cin >> number_film;
		if (number_film == 0)
			go = false;
		else {
			switch (number_film) {
			case 1: print_movie(MIB); std::cout << "Хотите обновить информацию ?\n1.Да\n2.Нет\n";
				std::cin >> update;
				switch (update) {
				case 1:update_info(MIB); break;
				case 2: system("cls");
				}break;
			case 2: print_movie(MIB2); std::cout << "Хотите обновить информацию ?\n1.Да\n2.Нет\n";
				std::cin >> update;
				switch (update) {
				case 1:update_info(MIB2); break;
				case 2:system("cls");
				}; break;
			case 3: print_movie(MIB3); std::cout << "Хотите обновить информацию ?\n1.Да\n2.Нет\n";
				std::cin >> update;
				switch (update) {
				case 1:update_info(MIB3); break;
				case 2:system("cls");
				}; break;
			case 4: print_movie(MIBinternational); std::cout << "Хотите обновить информацию ?\n1.Да\n2.Нет\n";
				std::cin >> update;
				switch (update) {
				case 1:update_info(MIBinternational); break;
				case 2:system("cls");
				};
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Фильм с самыми высокими сборами:\n";
	print_movie(expensive(object, size));


	




	return 0;
}