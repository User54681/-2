#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <map>

using std::cout;
using std::cin;
using std::vector;

//2.1 обычный индексовый цикл
int output1(int size, vector<std::string> vec, vector<int> marks) {
    cout << "Имя" << "\t" << "Балл" << "\n";
    for (int i = 0; i < size; ++i) cout << vec[i] << "\t" << marks[i] << "\n";
    return 0;
}
//2.2 Range-based for-loop
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
//2.3 с помощью итератора
int output3(vector<std::string> vec, vector<int> marks) {
    auto it1 = vec.begin();
    auto it2 = marks.begin();
    cout << "Имя" << "\t" << "Балл" << "\n";
    while (it1 != vec.end() and it2 != marks.end()) {
        if (it1 != vec.end()) {
            cout << *it1 << "\t";
            ++it1;
        }
        if (it2 != marks.end()) {
            cout << *it2 << "\n";
            ++it2;
        }
    }
    return 0;
}
//задание 3* - коктейльная сортировка
 vector<int> CocktailSort(vector<int> marks, int size)
{
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        //меняем swapped на false, тк с предыдущей итерации он может быть равен true 
        swapped = false;
        //цикл слева направо такой же, как пузырьковая сортировка
        for (int i = start; i < end; ++i) {
            if (marks[i] > marks[i + 1]) {
                int x = marks[i];
                marks[i] = marks[i + 1];
                marks[i + 1] = x;
                swapped = true;
            }
        }
        //если ничего не поменялось, то массив отсортирован
        if (!swapped)
            break;
        //в противном случае следует сбросить булевую переменную для того,чтобы ее можно было использовать повторно
        swapped = false;
        //перемещаем конец на единицу назад, тк мы уже поставили наибольший элемент в конец вектора
        --end;
        //по сути, повторяем предыдущий цикл, только идем мы справа налево
        for (int i = end - 1; i >= start; --i) {
            if (marks[i] > marks[i + 1]) {
                int x = marks[i];
                marks[i] = marks[i + 1];
                marks[i + 1] = x;
                swapped = true;
            }
        }
        //увеличиваем начальную точку, тк последний этап переместил следующее наименьшее число на его законное место
        ++start;
    }
    return marks;
}
 //задание 3
 double Average(vector<int> marks, int size) {
     double average = 0;
     for (auto i : marks) average += i;
     return (average / size);
 }
 double Mediana(vector<int> marks, int size) {
     double mediana;
     if (size % 2 == 1) mediana = marks[size / 2];
     else mediana = (marks[size / 2] + marks[size / 2 - 1]) / 2;
     return mediana;
 }
 /*int Moda(vector<int> marks, int size) {
     int number = marks[0];
     int moda = number;
     int count = 1;
     int countMode = 1;

     for (int i = 1; i < size; i++){
         if (marks[i] == number) ++count;
         else{
             if (count > countMode){
                 countMode = count;
                 moda = number;
             }
             count = 1;
             number = marks[i];
         }
     }
     if (moda == marks[0] and count == 1) return false;
     else return moda; 
 }*/
 vector<int> Mode(const std::vector<int>& arr) {
     std::map<int, int> countMap;
     vector<int> mode;

     for (int num : arr) {
         countMap[num]++;
     }

     int maxCount = 0;
     for (const auto& pair : countMap) {
         if (pair.second > maxCount) {
             maxCount = pair.second;
         }
     }

     for (const auto& pair : countMap) {
         if (pair.second == maxCount) {
             mode.push_back(pair.first);
         }
     }

     return mode;
 }

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int var, size(10);
    vector<std::string> students1{ "Иван", "Анастасия", "Анна", "Екатерина", "Михаил", "Сергей", "Александр", "Татьяна", "Валерий", "Полина" },
                        students2(size),
                        students3(size);
    vector<int> marks, marks1{ 74, 83, 99, 50, 70, 90, 70, 84, 100, 74 }, marks2(size), marks3(size);

    cout << "Введите:" << "\n" << "1. Если хотите демонстрационный анализ на дефолтных входных значениях" << "\n"
         << "2. Если хотите анализ на случайных входных значениях" << "\n"
         << "3. Если хотите анализ на входных значениях от самого пользователя" << "\n";
    cin >> var;

    switch (var) {
        
        case 1: 
        {
            output1(size, students1, marks1);
            marks = CocktailSort(marks1, size);
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
            output1(size, students2, marks2);
            marks = CocktailSort(marks2, size);
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
            marks = CocktailSort(marks3, size);
            break;
        }
        default:
        {
            cout << "Такого варианта не существует";
            break;
        }
    }

    double average = Average(marks, size);
    double mediana = Mediana(marks, size);
    vector<int> mode = Mode(marks);
    for (auto i : marks) cout << i << " ";
    cout << "\n";
    if (mode.size() == 0) cout << "Мода не найдена";
    else {
        cout << "Мода(ы): ";
        for (int num : mode) {
            cout << num << " ";
        }
    }
    cout << "\nСреднее значение: " << average << "\tМедиана: " << mediana;
}