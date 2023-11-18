#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;

//обычный индексовый цикл
int output1(int size, vector<std::string> vec, vector<int> marks) {
    cout << "Имя" << "\t" << "Балл" << "\n";
    for (int i = 0; i < size; ++i) cout << vec[i] << "\t" << marks[i] << "\n";
    return 0;
}
//Range-based for-loop
int output2(vector<std::string> vec, vector<int> marks) {
    cout << "Имя" << "\t" << "Балл" << "\n";
    vector<std::pair<std::string, int>> result;

    std::transform(vec.begin(), vec.end(), marks.begin(), std::back_inserter(result),
        [](const std::string& a, int b) { return std::make_pair(a, b); });

    for (const auto& pair : result) {
        std::cout << pair.first << "\t" << pair.second << "\n";
    }
    return 0;
}
//с помощью итератора
//int output3() {
//
//}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int var, size(10);
    vector<std::string> students1{ "Иван", "Анастасия", "Анна", "Екатерина", "Михаил", "Сергей", "Александр", "Татьяна", "Валерий", "Полина" },
                             students2(size),
                             students3(size);
    vector<int> marks1{ 74, 83, 99, 50, 80, 90, 70, 84, 100, 74 }, marks2(size), marks3(size);

    cout << "Введите:" << "\n" << "1. Если хотите демонстрационный анализ на дефолтных входных значениях" << "\n"
         << "2. Если хотите анализ на случайных входных значениях" << "\n"
         << "3. Если хотите анализ на входных значениях от самого пользователя" << "\n";
    cin >> var;

    switch (var) {
        
        case 1: 
        {
            output1(size, students1, marks1);
            break;
        }
        case 2:
        {
            int index;
            cout << "Введите размер массива: ";
            cin >> size;
            students2.resize(size);
            marks2.resize(size);
            for(int i = 0; i < size; ++i){
                index = rand() % size;
                students2[i] = students1[index];  
                marks2[i] = rand() % 100;
            }
            //output1(size, students2, marks2);
            output2(students2, marks2);
            break;
        }
        case 3:
        {
            cout << "Введите размер массива: ";
            cin >> size;
            students3.resize(size);
            marks3.resize(size);
            for (int i = 0; i < size; ++i) cin >> students3[i] >> marks3[i];
            output1(size, students3, marks3);
            break;
        }
    }

}

