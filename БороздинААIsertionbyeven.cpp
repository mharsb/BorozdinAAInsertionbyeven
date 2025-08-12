#include <iostream>
#include <vector>

using namespace std;
//требований к асимптотике не было, поэтому надеюсь такое решение будет оптимальным
vector<int> insertionSortEvenNumbers(vector<int> arr) { //ну название само за себя говорит - сортировка вставками по четным элементам.
    // сделаем отдельный массив, где будут индексы четных элементов исходного массива
    vector<int> evenIndices;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 == 0) {
            evenIndices.push_back(i);
        }
    }

    // Теперь, обращаясь к проиндексированному массиву выше, будем собирать все четные элементы
    vector<int> evenNumbers;
    for (int idx : evenIndices) {
        evenNumbers.push_back(arr[idx]);
    }

    // Реализация самой сортировки вставками для массива с четными элементами исходного массива
    for (int i = 1; i < evenNumbers.size(); ++i) {
        int key = evenNumbers[i]; //стоим на какой-то позиции массива
        int j = i - 1;
        while (j >= 0 && evenNumbers[j] > key) { //проверяем, что все предыдущие элементы меньше того, на котором стоим
            evenNumbers[j + 1] = evenNumbers[j]; // иначе если встретим кого-то, кто был больше исходного - кладем его после того, на котором стоим
            j--; //просто декриментируем справа счётчик, чтобы двигаться дальше
        }
        evenNumbers[j + 1] = key; //следующий элемент
    }

    // Теперь просто вставляем вместо исходных четных элементов - их же, но уже отсортированными 
    for (int i = 0; i < evenIndices.size(); ++i) {
        arr[evenIndices[i]] = evenNumbers[i];
    }

    return arr;
}

//я подумал, что проще не париться над созданием отдельного файла с модульными тестами и сделать их сразу в отдельной функции. 
void testInsertionSortEvenNumbers() {
    // Тест 1: Все элементы чётные
    vector<int> test1 = { 4, 2, 8, 6 };
    vector<int> expected1 = { 2, 4, 6, 8 };
    vector<int> result1 = insertionSortEvenNumbers(test1);
    cout << "test 1: " << (result1 == expected1 ? "Approved" : "not approved") << endl; //через тернарный оператор везде проверим, совпадение того, что нужно с тем, что получится после сортировки. 

    // Тест 2: Все элементы нечётные
    vector<int> test2 = { 1, 3, 5, 7 };
    vector<int> expected2 = { 1, 3, 5, 7 };
    vector<int> result2 = insertionSortEvenNumbers(test2);
    cout << "test 2: " << (result2 == expected2 ? "Approved" : "not approved") << endl;

    // Тест 3: Смешанные чётные и нечётные элементы
    vector<int> test3 = { 5, 2, 8, 1, 6 };
    vector<int> expected3 = { 5, 2, 6, 1, 8 };
    vector<int> result3 = insertionSortEvenNumbers(test3);
    cout << "test 3: " << (result3 == expected3 ? "Approved" : "not approved") << endl;

    // Тест 4: Пустой массив
    vector<int> test4 = {};
    vector<int> expected4 = {};
    vector<int> result4 = insertionSortEvenNumbers(test4);
    cout << "test 4: " << (result4 == expected4 ? "Approved" : "not approved") << endl;

    // Тест 5: Один чётный элемент
    vector<int> test5 = { 3, 4, 1 };
    vector<int> expected5 = { 3, 4, 1 };
    vector<int> result5 = insertionSortEvenNumbers(test5);
    cout << "test 5: " << (result5 == expected5 ? "Approved" : "not approved") << endl;
}

int main() { //int main тоже функция :)

    testInsertionSortEvenNumbers(); //запускаем тест программу, если какой-то тест не подойдет можно написать какой-нибудь массив  в теле main. 
}




