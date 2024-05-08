#include <iostream>
using namespace std;
// Власна реалізація методу insert для рядків
void custom_insert(char* str, const char* insert_str, size_t pos) {
    size_t len = 0;
    while (str[len] != '\0') // Знаходження довжини рядка
        len++;

    size_t insert_len = 0;
    while (insert_str[insert_len] != '\0') // Знаходження довжини рядка для вставки
        insert_len++;

    // Зміщення символів у рядку вправо, починаючи з позиції pos
    for (size_t i = len; i >= pos; i--)
        str[i + insert_len] = str[i];

    // Копіювання рядка для вставки у відповідну позицію
    for (size_t i = 0; i < insert_len; i++)
        str[pos + i] = insert_str[i];
}

int main() {
    char main_str[100]; // Оголошення масиву символів
    string str; // Оголошення змінної типу string

    cout << "Введіть рядок: ";
    cin.getline(main_str, 100); // Зчитування рядка з консолі
    cout << "Введіть рядок для вставки: ";
    getline(cin, str); // Зчитування рядка для вставки

    // Виклик власної функції insert
    custom_insert(main_str, str.c_str(), 3);
    cout << "Після вставки: " << main_str << endl;

    // Виклик методу string insert
    string original_str(main_str);
    original_str.insert(3, str);
    cout << "string::insert: " << original_str << endl;

    return 0;
}