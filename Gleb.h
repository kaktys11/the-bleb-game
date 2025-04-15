#include <iostream>
#include <vector>

using namespace std;

template <typename std;

Class MyVector {

  private:
    T* data;
    size_t capacity;
    size_t lenght;
    void resize(size_t new_capacity);
    public:
        MyVector();
        ~MyVector();
        void push_back(const T& value);
        size_t size() const;
        T& operator[](size_t index);
        const T& operator[](size_t index) const

};

template <typename T>
MyVector<T>::MyVector() : data(nullptr), capacity(0), length(0) {}
template <typename T>
MyVector<T>::~MyVector() {
delete[] data;
}

template <typename T>
MyVector<T>::MyVector() : data(nullptr), capacity(0), length(0) {}
template <typename T>
MyVector<T>::~MyVector() {
delete[] data;
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
 if (length == capacity) {
 size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
 resize(new_capacity);
 }
 data[length++] = value; // Добавляем элемент и увеличиваем длину
}

template <typename T>
T& MyVector<T>::operator[](size_t index) {
 return data[index];
}
template <typename T>
const T& MyVector<T>::operator[](size_t index) const {
 return data[index];
}

template <typename T>
size_t MyVector<T>:: const {
    return lenght;
}

// int main()
// {
//     vector<int> numbers;

//     vector<int> v1;              // пустой вектор
//     vector<int> v2(v1);          // вектор v2 - копия вектора v1
//     vector<int> v3 = v1;         // вектор v3 - копия вектора v1
//     vector<int> v4(5);           // вектор v4 состоит из 5 чисел, каждое число равно 0
//     vector<int> v5(5, 2);        // вектор v5 состоит из 5 чисел, каждое число равно 2
//     vector<int> v6{ 1, 2, 4, 5 };  // вектор v6 состоит из чисел 1, 2, 4, 5
//     vector<int> v7 = { 1, 2, 3, 5 }; // вектор v7 состоит из чисел 1,2,3,5

//     cout << v6[0] << endl
//     cout << v6.front() << endl; // Первый элемент в массиве
//     cout << v.back << endl; // Последний эелемент в массиве

//     v6.push_back(10); // Добавление элемента в массив
//     v6.emplace_back(11); // Аналогичная строчка

//     v6.clear(); // Полностью удаляет элемент в векторе
//     v6.pop_back(); // Удаляет последний элемент вектора

//     v6.size(); // Размер вектора
//     v6.empty(); // Пуст лм вектор (true/false)

//     v6.resize(4); // Оставляет в векторе n первых элементов
//     v6.resize(4,10); // Оставляет в векторе n первых элементов
//     // Если размер вектора меньше nб то добавляются недостоющие элементы

//     vector<string> langs = { "java", "JavaScript", "C" };
//     langs.assign(4, "C++"); //langs = {"C++, "C++", "C++"}
//     langs.assign({"C++", "C#", "C"}); // langs = {"C++", "C#", "C"}

//     vector<string> clangs{ "C++", "C#", "Java" };
//     vector<string> ilangs{ "JavaScript", "Python", "PHP" };
//     clangs.swap(ilangs);    // clangs = ( "JavaScript", "Python", "PHP");
//}