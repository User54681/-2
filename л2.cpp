#include <iostream>
#include <vector>

using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "rus");
    int var, size;
    std::vector<std::string> students1{ "Иван", "Анастасия", "Анна", "Екатерина", "Михаил", "Сергей", "Александр", "Татьяна", "Валерий", "Полина" },
                             students2(size),
                             students3(size);
    std::vector<int> marks1{74, 83, 99, 50, 80, 90, 70, 84, 100, 74}, marks2(size), marks3(size);

    cout << "Введите:" << "\n" << "1. Если хотите демонстрационный анализ на дефолтных входных значениях" << "\n"
         << "2. Если хотите анализ на случайных входных значениях" << "\n"
         << "3. Если хотите анализ на входных значениях от самого пользователя" << "\n";
    cin >> var;

    switch (var) {
        
        case 1: 
        {
            cout << "Имя" << "\t" << "Балл" << "\n";
            for (int i = 0; i < 10; ++i) cout << students1[i] << "\t" << marks1[i] << "\n";
        }
        case 2:
        {
            cout << "";
            cin >> size;

        }
        case 3:
        {
            cout << "";
            cin >> size;
        }
    }

}

