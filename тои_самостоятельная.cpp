#include <iostream>
//#include <fstream>
//#include <filesystem>
#include <windows.h>
#include <vector>
//#include <algorithm>
using namespace std;

/// <summary>
///  Описание структуры элемента списка 
/// </summary>
struct Sport
{
    string name;
    int age;
    int number;
    string team;
    int result;
};

/// <summary>
/// Структура для сортировки массива по имени
/// </summary>
struct SortByName
{
    string name; // ключ
    int index;  // индекс в массиве
};

/// <summary>
/// Структура для сортировки массива по номеру
/// </summary>
struct SortByNumber
{
    int number;; // ключ
    int index;  // индекс в массиве
};

/// <summary>
/// Структура для удаление элемента массива
/// </summary>
struct DeleteElement
{
    string name; // ключ
    int index;  // индекс в массиве
};

/// <summary>
/// Структура для редактирования элемента массива по имени
/// </summary>
struct EditByName
{
    string name; // ключ
    int index;  // индекс в массиве
    int number;
};

/// <summary>
/// Структура для редактирования элемента массива по номеру
/// </summary>
struct EditByNumber
{
    int number;; // ключ
    int index;  // индекс в массиве
    string name;
};

/// <summary>
/// Стуктура для бинарного дерева
/// </summary>
struct TreeNode
{
    int key; // ключевой атрибут для индексации: номер
    int index; // номер элемента в массиве
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k, int i) // конструктор для структуры
    {
        key = k;
        index = i;
        left = right = nullptr;
    }
};

/// <summary>
/// Стуктура для списка
/// </summary>
struct SportsmenList
{
    Sport sportsmen;
    SportsmenList* next;
};

/// <summary>
/// Функция для сортировки массива по имени (сортировка вставками)
/// </summary>
/// <param name="arr"></param>
/// <param name="n"></param>
void SortByNameArray(SortByName arr[], int arraySize)
{
    int i, j;
    SortByName key;
    for (i = 1; i < arraySize; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].name > key.name)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/// <summary>
/// Рекурсивная функция бинарного поиска по имени
/// </summary>
/// <param name="arr"></param>
/// <param name="left"></param>
/// <param name="right"></param>
/// <param name="key"></param>
/// <returns></returns>
int binarySearchByName(SortByName arr[], int left, int right, string key)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid].name == key)
            return mid;

        if (arr[mid].name > key)
            return binarySearchByName(arr, left, mid - 1, key);

        return binarySearchByName(arr, mid + 1, right, key);
    }
    // Если элемент не найден
    return -1;
}

/// <summary>
/// Функция для сортировки массива по номеру (сортировка вставками)
/// </summary>
/// <param name="arr"></param>
/// <param name="n"></param>
void SortByNumberArray(SortByNumber arr[], int arraySize)
{
    int i, j;
    SortByNumber key;
    for (i = 1; i < arraySize; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].number < key.number)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/// <summary>
/// Итеративная функция бинарного поиска по номеру
/// </summary>
/// <param name="arr"></param>
/// <param name="n"></param>
/// <param name="key"></param>
/// <returns></returns>
int binarySearchByNumber(SortByNumber arr[], int arraySize, int key)
{
    int left = 0, right = arraySize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid].number == key)
            return mid;

        else if (arr[mid].number < key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

/// <summary>
/// Редактирование элементов массива: ищем имя, по нему меняем номер элемента
/// </summary>
/// <param name="sportsmen"></param>
/// <param name="arraySize"></param>
/// <param name="nameToSearch"></param>
/// <param name="newNumber"></param>
void editNumber(EditByName editedByName[], int arraySize, string nameToSearch, int newNumber)
{
    // Ищем индекс записи в массиве по имени
    int indexByName = -1;
    for (int i = 0; i < arraySize; i++)
    {
        if (editedByName[i].name == nameToSearch)
        {
            indexByName = i;
        }
    }
    // Если запись по имени найдена, редактируем поле номера
    if (indexByName != -1)
    {
        //sportsmen[editedByName[indexByName].index].number = newNumber;
        editedByName[indexByName].number = newNumber;
        std::cout << "Запись с именем' '" << nameToSearch << "'  изменена. Новый номер : " << newNumber << std::endl;
    }
    else
    {
        std::cout << "Запись с именем'" << nameToSearch << "' не найдена." << std::endl;
    }
}

/// <summary>
/// Редактирование элементов массива: ищем номер, по нему меняем имя элемента
/// </summary>
/// <param name="sportsmen"></param>
/// <param name="arraySize"></param>
/// <param name="newName"></param>
/// <param name="numberToSearch"></param>
void editName(EditByNumber editedByNumber[], int arraySize, string newName, int numberToSearch)
{
    // Ищем индекс записи в массиве по имени
    int indexByNumber = -1;
    for (int i = 0; i < arraySize; i++)
    {
        if (editedByNumber[i].number == numberToSearch)
        {
            indexByNumber = i;
        }
    }
    // Если запись по имени найдена, редактируем поле имени
    if (indexByNumber != -1)
    {
        //sportsmen[editedByNumber[indexByNumber].index].name = newName;
        editedByNumber[indexByNumber].name = newName;

        std::cout << "Запись с номером' '" << numberToSearch << "'  изменена. Новое имя : " << newName << std::endl;
    }
    else
    {
        std::cout << "Запись с номером'" << numberToSearch << "' не найдена." << std::endl;
    }
}

/// <summary>
/// Удаление элемента
/// </summary>
/// <param name="sportsmen"></param>
/// <param name="arraySize"></param>
/// <param name="nameToDelete"></param>
void deleteRec(DeleteElement deletedArray[], int arraySize, string nameToDelete)
{
    int deleteIndex = -1;

    // Найдем индекс записи в массиве по имени для удаления
    for (int i = 0; i < arraySize; i++)
    {
        if (deletedArray[i].name == nameToDelete)
        {
            deleteIndex = i;
        }
    }

    if (deleteIndex != -1)
    {
        // Сохраняем индекс удаляемой записи
        int indexToDelete = deletedArray[deleteIndex].index;

        // Сдвигаем элементы в массиве на одну позицию влево
        for (int i = deleteIndex; i < arraySize - 1; i++)
        {
            deletedArray[i] = deletedArray[i + 1];

            // Обновляем индексы
            if (deletedArray[i].index > indexToDelete)
            {
                deletedArray[i].index = deletedArray[i+1].index;
            }
        }
        arraySize--;
        std::cout << "Запись с именем '" << nameToDelete << "' удалена" << endl << endl;
    }
    else
    {
        std::cout << " Запись с именем  '" << nameToDelete << "' не найдена  " << std::endl;
    }
}

/// <summary>
/// Создание бинарного дерева
/// </summary>
/// <param name="root"></param>
/// <param name="key"></param>
/// <param name="index"></param>
void MakeTree(TreeNode*& root, int number, int index)
{
    if (root == nullptr)
    {
        root = new TreeNode(number, index);
    }
    else if (number < root->key)
    {
        MakeTree(root->left, number, index);
    }
    else
    {
        MakeTree(root->right, number, index);
    }
}

/// <summary>
/// Вывод данных в порядке возрастания
/// </summary>
/// <param name="root"></param>
/// <param name="sportsmen"></param>
void GetAscendingTree(TreeNode* root, Sport sportsmen[])
{
    if (root == nullptr)
    {
        return;
    }

    GetAscendingTree(root->left, sportsmen);
    cout << "Name: " << sportsmen[root->index].name << ", Age: " << sportsmen[root->index].age << ", Number: " << sportsmen[root->index].number << 
        ", Team: " << sportsmen[root->index].team << ", Result: " << sportsmen[root->index].result << endl << endl;
    GetAscendingTree(root->right, sportsmen);
}

/// <summary>
/// Вывод данных в порядке убывания
/// </summary>
/// <param name="root"></param>
/// <param name="sportsmen"></param>
void GetDescendingTree(TreeNode* root, Sport sportsmen[])
{
    if (root == nullptr) // проверка на пустоту корня
    {
        return;
    }
    GetDescendingTree(root->right, sportsmen);
    cout << "Name: " << sportsmen[root->index].name << ", Age: " << sportsmen[root->index].age << ", Number: " << sportsmen[root->index].number << 
        ", Team: " << sportsmen[root->index].team << ", Result: " << sportsmen[root->index].result << endl << endl;
    GetDescendingTree(root->left, sportsmen);
}

/// <summary>
/// Поиск записи по имени
/// </summary>
/// <param name="root"></param>
/// <param name="sportsmen"></param>
/// <param name="key"></param>
void searchElement(TreeNode* root, Sport sportsmen[], int numberToSearch)
{
    if (root == nullptr)
    {
        cout << "Элемент не найден" << endl;
    }
    else
    {
        if (numberToSearch == sportsmen[root->index].number)
        {
            cout << "Name: " << sportsmen[root->index].name << ", Age: " << sportsmen[root->index].age << ", Number: " << sportsmen[root->index].number <<
                ", Team: " << sportsmen[root->index].team << ", Result: " << sportsmen[root->index].result << endl << endl;
            return;
        }

        if (numberToSearch < sportsmen[root->index].number)
        {
            searchElement(root->left, sportsmen, numberToSearch);
        }
        else
        {
            searchElement(root->right, sportsmen, numberToSearch);
        }
    }
}

/// <summary>
/// Удаление записи по искомому номеру
/// </summary>
/// <param name="root"></param>
/// <param name="key"></param>
/// <param name="sportsmen"></param>
/// <param name="size"></param>
void deleteNode(TreeNode*& root, int numberToDelete, Sport sportsmen[])
{
    if (root == nullptr)
    {
        cout << "Элемент с номером " << numberToDelete << " не найден" << endl << endl;
    }
    else
    {
        if (sportsmen[root->index].number > numberToDelete)
        {
            deleteNode(root->left, numberToDelete, sportsmen);
        }
        else if (sportsmen[root->index].number < numberToDelete)
        {
            deleteNode(root->right, numberToDelete, sportsmen);
        }
        else
        {
            if (root->left == nullptr)
            {
                TreeNode* temp = root->right;
                delete root;
                root = temp;
            }
            else if (root->right == nullptr)
            {
                TreeNode* temp = root->left;
                delete root;
                root = temp;
            }
            else
            {
                TreeNode* temp = root->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                root->index = temp->index;
                deleteNode(root->right, sportsmen[temp->index].number, sportsmen);
            }
        }
    }
}

/// <summary>
/// Редактирование записи по номеру
/// </summary>
/// <param name="root"></param>
/// <param name="sportsmen"></param>
/// <param name="key"></param>
/// <param name="newName"></param>
/// <param name="newAge"></param>
/// <param name="newNumber"></param>
/// <param name="newTeam"></param>
/// <param name="newResult"></param>
void editRecord(TreeNode* root, Sport sportsmen[], int numberToEdit, string newName, int newAge, int newNumber, string newTeam, int newResult)
{
    if (root == nullptr)
    {
        cout << "Элемент с номером " << numberToEdit << " не найден" << endl << endl;
    }
    else
    {
        if (numberToEdit == sportsmen[root->index].number)
        {
            sportsmen[root->index].name = newName;
            sportsmen[root->index].age = newAge;
            sportsmen[root->index].number = newNumber;
            sportsmen[root->index].team = newTeam;
            sportsmen[root->index].result = newResult;

            cout << "Запись с номером " << numberToEdit << " отредактирована" << endl;
        }
        else
        {
            if (numberToEdit < sportsmen[root->index].number)
            {
                editRecord(root->left, sportsmen, numberToEdit, newName, newAge, newNumber, newTeam, newResult);
            }
            else
            {
                editRecord(root->right, sportsmen, numberToEdit, newName, newAge, newNumber, newTeam, newResult);
            }
        }
    }
}

/// <summary>
/// Функция печати элементов списака от начало к концу (от головы к хвосту) 
/// </summary>
/// <param name="head"></param>
void ListFromFirst(SportsmenList* head)
{
    while (head != nullptr)
    {
        //Вывод информационного поля текущего элемента, на который указывает ссылка:	
        cout << "Name: " << head->sportsmen.name << " Age: " << head->sportsmen.age << " Number: " << head->sportsmen.number <<
            " Team: " << head->sportsmen.team << " Reasult: " << head->sportsmen.result << endl << endl;
        head = head->next;  //Переход к следующему элементу по ссылке next в текущем элементе
    }
}

/// <summary>
/// Функция печати элементов списка от хвоста к голове (рекурсивно)
/// </summary>
/// <param name="head"></param>
void ListFromEnd(SportsmenList* head)
{
    if (head != nullptr)
    {
        ListFromEnd(head->next);
        cout << "Name: " << head->sportsmen.name << " Age: " << head->sportsmen.age << " Number: " << head->sportsmen.number << 
            " Team: " << head->sportsmen.team << " Reasult: " << head->sportsmen.result << endl << endl;
    }
}

/// <summary>
/// Функция сортировки списка  по возрастанию поля возраст
/// </summary>
/// <param name="head"></param>
void sortListByAge(SportsmenList*& head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    SportsmenList* i, * j;
    Sport temp;

    for (i = head; i != nullptr; i = i->next)
    {
        for (j = i->next; j != nullptr; j = j->next)
        {
            if (i->sportsmen.age > j->sportsmen.age)
            {
                temp = i->sportsmen;
                i->sportsmen = j->sportsmen;
                j->sportsmen = temp;
            }
        }
    }
}

/// <summary>
/// Функция для сортировки списка по убыванию поля "team"
/// </summary>
/// <param name="head"></param>
void sortListByTeam(SportsmenList*& head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    SportsmenList* i, * j;
    Sport temp;

    for (i = head; i != nullptr; i = i->next)
    {
        for (j = i->next; j != nullptr; j = j->next)
        {
            if (i->sportsmen.team < j->sportsmen.team)
            {
                temp = i->sportsmen;
                i->sportsmen = j->sportsmen;
                j->sportsmen = temp;
            }
        }
    }
}

/// <summary>
/// Функция для добавления новой записи в список и его сортировка по возрастанию поля "age"
/// </summary>
/// <param name="head"></param>
/// <param name="newSportsmen"></param>
void AddAndSortByAge(SportsmenList*& head, Sport newSportsmen)
{
    SportsmenList* newNode = new SportsmenList;
    newNode->sportsmen = newSportsmen;
    newNode->next = head;
    head = newNode;

    sortListByAge(newNode);
}

/// <summary>
/// Функция для добавления новой записи в список с сортировкой по убыванию поля "team"
/// </summary>
/// <param name="head"></param>
/// <param name="newSportsmen"></param>
void AddAndSortByTeam(SportsmenList*& head, Sport newSportsmen)
{
    SportsmenList* newNode = new SportsmenList;
    newNode->sportsmen = newSportsmen;
    newNode->next = head;
    head = newNode;
    sortListByTeam(newNode);
}

/// <summary>
/// Функция для поиска и вывода записи/записей с заданным значением атрибута "age"
/// </summary>
/// <param name="head"></param>
/// <param name="targetAge"></param>
void searchByAge(SportsmenList* head, int ageToSearch)
{
    bool found = false;

    SportsmenList* current = head;
    while (current != nullptr)
    {
        if (current->sportsmen.age == ageToSearch)
        {
            found = true;
            cout << "Name: " << current->sportsmen.name << " Age: " << current->sportsmen.age << " Number: " << current->sportsmen.number <<
                " Team: " << current->sportsmen.team << " Reasult: " << current->sportsmen.result << endl << endl;
        }
        current = current->next;
    }

    if (!found)
    {
        std::cout << "Запись с возрастом " << ageToSearch << " не найдена." << std::endl;
    }
}

/// <summary>
/// Функция для поиска и вывода записи/записей с заданным значением атрибута "team"
/// </summary>
/// <param name="head"></param>
/// <param name="targetTeam"></param>
void searchByTeam(SportsmenList* head, string teamToSearch)
{
    bool found = false;

    SportsmenList* current = head;
    while (current != nullptr)
    {
        if (current->sportsmen.team == teamToSearch)
        {
            found = true;
            cout << "Name: " << current->sportsmen.name << " Age: " << current->sportsmen.age << " Number: "
                << current->sportsmen.number << " Team: " << current->sportsmen.team << " Reasult: "
                << current->sportsmen.result << endl << endl;
        }
        current = current->next;
    }

    if (!found)
    {
        std::cout << "Запись с командой " << teamToSearch << " не найдена." << std::endl;
    }
}

/// <summary>
/// Функция для удаления записи с заданным значением атрибута "age"
/// </summary>
/// <param name="head"></param>
/// <param name="targetAge"></param>
void deleteByAge(SportsmenList*& head, int ageToDelete)
{
    SportsmenList* current = head;
    SportsmenList* previous = nullptr;

    while ((current != nullptr) && (current->sportsmen.age != ageToDelete))
    {
        previous = current;
        current = current->next;
    }

    if (current != nullptr)
    {
        if (current == head)
        {
            head = current->next;
        }
        else
        {
            if (current->next == nullptr)
            {
                previous->next = nullptr;
            }
            else
            {
                previous->next = current->next;
            }
        }

        delete current;
        std::cout << "Запись с возрастом " << ageToDelete << " удалена." << std::endl;
    }
    else
    {
        std::cout << "Запись с возрастом " << ageToDelete << " не найдена." << std::endl;
    }
}

/// <summary>
/// Функция для удаления записи с заданным значением атрибута "team"
/// </summary>
/// <param name="head"></param>
/// <param name="targetTeam"></param>
void deleteByTeam(SportsmenList*& head, string teamToDelete)
{
    SportsmenList* current = head;
    SportsmenList* previous = nullptr;

    while ((current != nullptr) && (current->sportsmen.team != teamToDelete))
    {
        previous = current;
        current = current->next;
    }

    if (current != nullptr)
    {
        if (current == head)
        {
            head = current->next;
        }
        else
        {
            if (current->next == nullptr)
            {
                previous->next = nullptr;
            }
            else
            {
                previous->next = current->next;
            }
        }

        delete current;
        std::cout << "Запись с командой " << teamToDelete << " удалена." << std::endl;
    }
    else
    {
        std::cout << "Запись с командой " << teamToDelete << " не найдена." << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Установка кириллицы
    const int arraySize = 5;
    // Выделение памяти для массивов и их инициализация
    struct Sport sportsmen[arraySize];
    struct SortByName sortedByNameSportsmen[arraySize];  // массив для сортировки элементов по имени
    struct SortByNumber sortedByNumberSportsmen[arraySize]; // массив для сортировки элементов по номеру
    struct DeleteElement deletedArray[arraySize];  // массив для удаления элементов по номеру
    struct EditByName editedByName[arraySize]; // массив для редактирования элементов по имени
    struct EditByNumber editedByNumber[arraySize]; // массив для редактирования элементов по номеру
    
    //-----Основой для тестирования массив-------
    sportsmen[0] = { "Jonh", 23, 14, "Kron", 2 };
    sportsmen[1] = { "Tom", 18, 8, "Wolf", 5 };
    sportsmen[2] = { "Kate", 19, 4, "Sky", 3 };
    sportsmen[3] = { "Bob", 17, 7, "Loft", 4 };
    sportsmen[4] = { "Kol", 20, 20, "Zolli", 1 };

    //Массив с одинаковыми элементами
    /*sportsmen[0] = { "Jonh", 23, 14, "Kron", 2 };
    sportsmen[1] = { "Jonh", 23, 14, "Kron", 2 };
    sportsmen[2] = { "Jonh", 23, 14, "Kron", 2 };
    sportsmen[3] = { "Jonh", 23, 14, "Kron", 2 };
    sportsmen[4] = { "Jonh", 23, 14, "Kron", 2 };*/

    // Пустой массив
    /*sportsmen[0] = {  };
    sportsmen[1] = {  };
    sportsmen[2] = {  };
    sportsmen[3] = {  };
    sportsmen[4] = {  };*/

    sortedByNameSportsmen[0] = { sportsmen[0].name, 0 };
    sortedByNumberSportsmen[0] = { sportsmen[0].number , 0 };
    deletedArray[0] = { sportsmen[0].name, 0 };
    editedByName[0] = { sportsmen[0].name , 0, sportsmen[0].number };
    editedByNumber[0] = { sportsmen[0].number , 0, sportsmen[0].name };

    sortedByNameSportsmen[1] = { sportsmen[1].name, 1 };
    sortedByNumberSportsmen[1] = { sportsmen[1].number , 1 };
    deletedArray[1] = { sportsmen[1].name, 1 };
    editedByName[1] = { sportsmen[1].name , 1, sportsmen[1].number };
    editedByNumber[1] = { sportsmen[1].number , 1, sportsmen[1].name };

    sortedByNameSportsmen[2] = { sportsmen[2].name, 2 };
    sortedByNumberSportsmen[2] = { sportsmen[2].number , 2 };
    deletedArray[2] = { sportsmen[2].name, 2 };
    editedByName[2] = { sportsmen[2].name , 2, sportsmen[2].number };
    editedByNumber[2] = { sportsmen[2].number , 2, sportsmen[2].name };

    sortedByNameSportsmen[3] = { sportsmen[3].name, 3 };
    sortedByNumberSportsmen[3] = { sportsmen[3].number , 3 };
    deletedArray[3] = { sportsmen[3].name, 3 };
    editedByName[3] = { sportsmen[3].name , 3,sportsmen[3].number };
    editedByNumber[3] = { sportsmen[3].number , 3, sportsmen[3].name };

    sortedByNameSportsmen[4] = { sportsmen[4].name, 4 };
    sortedByNumberSportsmen[4] = { sportsmen[4].number , 4 };
    deletedArray[4] = { sportsmen[4].name, 4 };
    editedByName[4] = { sportsmen[4].name , 4, sportsmen[4].number };
    editedByNumber[4] = { sportsmen[4].number , 4 , sportsmen[4].name };

    int variant;

    do
    {
        std::cout << " === Меню === " << std::endl;
        std::cout << "1. Задание 1" << std::endl;
        std::cout << "2. Задание 2" << std::endl;
        std::cout << "3. Задание 3" << std::endl;
        std::cout << "0. Выход" << std::endl;

        cin >> variant;

        switch (variant)
        {
            case 1:
            {
                // Печать исходного массива
                std::cout << "  Исходный массив  " << "\n";
                for (int i = 0; i < 5; i++)
                {
                    cout << "Name: " << sportsmen[i].name << ", Age: " << sportsmen[i].age << ", Number: " << sportsmen[i].number << ", Team: " << sportsmen[i].team << ", Result: " << sportsmen[i].result << endl << endl;
                }

                int variant1;
                do
                {
                    cout << "---- Task 1: Array ----" << "\n";
                    std::cout << "1. Сортировка по имени в порядке возрастания" << std::endl;
                    std::cout << "2. Сортировка по номеру в порядке убывания" << std::endl;
                    std::cout << "3. Бинарный поиск по имени" << std::endl;
                    std::cout << "4. Бинарный поиск по номеру" << std::endl;
                    std::cout << "5. Редактирование номера" << std::endl;
                    std::cout << "6. Редактирование имени " << std::endl;
                    std::cout << "7. Удаление записи по имени" << std::endl;
                    std::cout << "0. Выход" << std::endl;

                    cin >> variant1;

                    switch (variant1)
                    {
                    case 1:
                    {
                        std::cout << "    Сортировка по имени   " << "\n";

                        SortByNameArray(sortedByNameSportsmen, arraySize);
                        for (int i = 0; i < arraySize; i++)
                        {
                            int ind = sortedByNameSportsmen[i].index;
                            cout << "Name: " << sportsmen[ind].name << ", Age: " << sportsmen[ind].age << ", Number: " << sportsmen[ind].number
                                << ", Team: " << sportsmen[ind].team << ", Result: " << sportsmen[ind].result << endl << endl;
                        }
                        break;
                    }

                    case 2:
                    {
                        std::cout << "   Сортировка по номеру   " << "\n";

                        SortByNumberArray(sortedByNumberSportsmen, arraySize);
                        for (int i = 0; i < arraySize; i++)
                        {
                            int ind = sortedByNumberSportsmen[i].index;
                            std::cout << "Name: " << sportsmen[ind].name << ", Age: " << sportsmen[ind].age << ", Number: " << sportsmen[ind].number 
                                << ", Team: " << sportsmen[ind].team << ", Result: " << sportsmen[ind].result << endl << endl;
                        }
                        break;
                    }

                    case 3:
                    {
                        std::cout << "   Бинарный поиск по имени   " << std::endl;
                        string nameToSearch = "Tom"; // поиск имени, которое есть в массиве
                        //string nameToSearch = "Tim"; // поиск имени, которого нет в массиве

                        int resultIndexByName = binarySearchByName(sortedByNameSportsmen, 0, 4, nameToSearch);
                        if (resultIndexByName != -1)
                        {
                            int indByName = sortedByNameSportsmen[resultIndexByName].index;
                            std::cout << "Name: " << sortedByNameSportsmen[resultIndexByName].name << ", Age: " << sportsmen[indByName].age << ", Number: " << sportsmen[indByName].number 
                                << ", Team: " << sportsmen[indByName].team << ", Result: " << sportsmen[indByName].result << endl << endl;
                        }
                        else
                        {
                            std::cout << "Элемент не найден" << std::endl;
                        }
                        break;
                    }

                    case 4:
                    {
                        std::cout << "   Бинарный поиск по номеру   " << std::endl;
                        int numberToSearch = 7; // поиск по существующему в массиве номеру
                        //int numberToSearch = 128; //поиск по не существующему в массиве номеру

                        int resultIndexByNumber = binarySearchByNumber(sortedByNumberSportsmen, arraySize, numberToSearch);
                        if (resultIndexByNumber != -1)
                        {
                            int indByNumber = sortedByNumberSportsmen[resultIndexByNumber].index;
                            std::cout << "Name: " << sportsmen[indByNumber].name << ", Age: " << sportsmen[indByNumber].age << ", Number: " << sportsmen[indByNumber].number 
                                << ", Team: " << sportsmen[indByNumber].team << ", Result: " << sportsmen[indByNumber].result << endl << endl;
                        }
                        else
                        {
                            std::cout << "Элемент не найден" << std::endl;
                        }
                        break;
                    }

                    case 5:
                    {
                        std::cout << "  Редактирование номера (поиск по имени)  " << std::endl;

                        // поиск по сущестующим данным
                        string nameToEdit = "Kate"; 
                        int newNumber = 55;

                        //// поиск по несущестующим данным
                        //string nameToEdit = "Rocki";
                        //int newNumber = 47;

                        editNumber(editedByName, arraySize, nameToEdit, newNumber);
                        for (int i = 0; i < arraySize; i++)
                        {
                            cout << "Name: " << sportsmen[i].name << ", Age: " << sportsmen[i].age << ", Number: " << editedByName[i].number
                                << ", Team: " << sportsmen[i].team << ", Result: " << sportsmen[i].result << endl << endl;
                        }
                        break;
                    }

                    case 6:
                    {
                        cout << "   Редактирование имени (поиск по номеру)  " << endl;

                        // поиск по сущестующим данным
                        int numberToEdit = 20;
                        string newName = "Bill";

                        //// поиск по несущестующим данным
                        //int numberToEdit = 458;
                        //string newName = "Bill";

                        editName(editedByNumber, arraySize, newName, numberToEdit);
                        for (int i = 0; i < arraySize; i++)
                        {
                            cout << "Name: " << editedByNumber[i].name << ", Age: " << sportsmen[i].age << ", Number: "
                                << sportsmen[i].number << ", Team: " << sportsmen[i].team << ", Result: " << sportsmen[i].result << endl << endl;
                        }
                        break;
                    }

                    case 7:
                    {
                        std::cout << "   Удаление записи по имени   " << std::endl;

                        // Удаление по сущестующим данным
                        string nameToDelete = "Kate";

                        //// Удаление по несущестующим данным
                        //string nameToDelete = "Sasha";

                        deleteRec(deletedArray, arraySize, nameToDelete);
                        for (int i = 0; i < arraySize - 1; i++)
                        {
                            int ind = deletedArray[i].index;
                            std::cout << "Name: " << sportsmen[ind].name << ", Age: " << sportsmen[ind].age << ", Number: " << sportsmen[ind].number << ", Team: " << sportsmen[ind].team << ", Result: " << sportsmen[ind].result << endl << endl;
                        }
                        break;
                    }
                    }
                } while (variant1 != 0);
                break;
            }

            case 2:
            {
                if ((sportsmen[0].number == sportsmen[1].number) || (sportsmen[0].number == sportsmen[2].number) || (sportsmen[0].number == sportsmen[3].number) || (sportsmen[0].number == sportsmen[4].number) || (sportsmen[1].number == sportsmen[2].number) || (sportsmen[1].number == sportsmen[3].number) || (sportsmen[1].number == sportsmen[4].number) || (sportsmen[2].number == sportsmen[3].number) || (sportsmen[2].number == sportsmen[4].number) || (sportsmen[3].number == sportsmen[4].number))
                {
                    std::cout << " В дереве есть одинаковые значения ключей или массив пуст. " << endl << endl;
                    break;
                }

                // Печать исходного массива
                std::cout << "  Исходный массив  " << "\n";
                for (int i = 0; i < arraySize; i++)
                {
                    cout << "Name: " << sportsmen[i].name << ", Age: " << sportsmen[i].age << ", Number: " << sportsmen[i].number << ", Team: " << sportsmen[i].team << ", Result: " << sportsmen[i].result << endl << endl;
                }

                TreeNode* root = nullptr;
                for (int i = 0; i < arraySize; i++)
                {
                    MakeTree(root, sportsmen[i].number, i);
                }

                int variant2;

                do
                {
                    cout << "---- Task 2: Binary Tree ----" << "\n";
                    std::cout << "1. Вывод бинарного дерева, отсортированного по возрастанию атрибута 'номер' спортсмена" << std::endl;
                    std::cout << "2. Вывод бинарного дерева, отсортированного по убыванмю атрибута 'номер' спортсмена" << std::endl;
                    std::cout << "3. Поиск элемента по номеру спортсмена и вывод данных" << std::endl;
                    std::cout << "4. Удаление элемента по заданному номеру спортсмена и вывод данных" << std::endl;
                    std::cout << "5. Редактирование дерева по заданному номеру спортсмена и вывод дерева с изменениями" << std::endl;
                    std::cout << "0. Выход" << std::endl;

                    cin >> variant2;

                    switch (variant2)
                    {
                    case 1:
                    {
                        cout << "  Отсортированное по возрастанию атрибута 'номер' дерево:  " << endl;
                        GetAscendingTree(root, sportsmen);
                        break;
                    }
                    case 2:
                    {
                        cout << "  Отсортированное по убыванию атрибута 'номер' дерево:  " << endl;
                        GetDescendingTree(root, sportsmen);
                        break;
                    }
                    case 3:
                    {
                        std::cout << "  Поиск элемента по номеру спортсмена и вывод данных   " << std::endl;

                        // Пользовательский ввод номера для поиска
                        //int numberToSearch;
                        //cout << " Введите номер для поиска: " << endl;
                        //cin >> numberToSearch;

                        int numberToSearch = 4;// Поиск по существующим данным

                        //int numberToSearch = 36; // Поиск по несуществующим данным

                        searchElement(root, sportsmen, numberToSearch);
                        break;
                    }
                    case 4:
                    {
                        std::cout << "   Удаление элемента по заданному номеру спортсмена и вывод данных  " << std::endl;
                        // Пользовательский ввод номера для удаления
                        int numberToDelete;
                        cout << " Введите номер для удаления: " << endl;
                        cin >> numberToDelete;

                        //int numberToDelete = 20; // Удаление по существующим данным

                       //int numberToDelete = 98; // Удаление по несуществующим данным

                        deleteNode(root, numberToDelete, sportsmen);
                        
                        GetAscendingTree(root, sportsmen);
                        break;
                    }
                    case 5:
                    {
                        cout << "  Редактирование дерева по заданному номеру спортсмена и вывод дерева с изменениями   " << endl;

                        // Пользовательский ввод номера для удаления
                        int numberToEdit;
                        std::cout << " Введите номер для редактирования: " << endl;
                        cin >> numberToEdit;
                        //std::cin.ignore(std::numeric_limits<std::streamsize> :: max(), '\n');


                        // Поиск по существующим данным
                        //int numberToEdit = 4; // Значение ключа элемента, который нужно обновить

                        //// Поиск по несуществующим данным
                        //int numberToEdit = 89; // Значение ключа элемента, который нужно обновить

                        // Новые значения атрибутов
                        string newName = "Kassie"; 
                        int newAge = 30; 
                        int newNumber = 44; 
                        string newTeam = "New Team"; 
                        int newResult = 7; 
                        
                        editRecord(root, sportsmen, numberToEdit, newName, newAge, newNumber, newTeam, newResult);
                        GetAscendingTree(root, sportsmen);
                        break;
                    }
                    }
                } while (variant2 != 0);
                break;
            }

            case 3:
            {
                SportsmenList* NewNode = nullptr;// Ссылка на новую вершину, которая будет вставляться в список (в голову)
                SportsmenList* HeadNow = nullptr;// Список пуст - указатель на "голову" - первый элемент - обнуляется

                for (int i = 0; i < arraySize; i++)
                {
                    NewNode = new SportsmenList;
                    NewNode->sportsmen.name = sportsmen[i].name;
                    NewNode->sportsmen.age = sportsmen[i].age;
                    NewNode->sportsmen.number = sportsmen[i].number;
                    NewNode->sportsmen.team = sportsmen[i].team;
                    NewNode->sportsmen.result = sportsmen[i].result;
                    NewNode->next = HeadNow;
                    HeadNow = NewNode;
                }

                int variant3;
                do
                {
                    cout << "---- Task 3: List ----" << "\n";
                    std::cout << "1. Вывод с начала" << std::endl;
                    std::cout << "2. Вывод с конца" << std::endl;
                    std::cout << "3. Вывод отсортиртированного по возрастанию поля age списка" << std::endl;
                    std::cout << "4. Вывод отсортиртированного по убыванию поля team списка" << std::endl;
                    std::cout << "5. Добавление новой записи и сортировка по возрастанию поля age" << std::endl;
                    std::cout << "6. Добавление новой записи и сортировка по убыванию поля team " << std::endl;
                    std::cout << "7. Поиск по возрасту и печатать найденной записи" << std::endl;
                    std::cout << "8. Поиск по команде и печатать найденной записи" << std::endl;
                    std::cout << "9. Удаление записи по введенному возрасту и печать списка" << std::endl;
                    std::cout << "10. Удаление записи по введенной команде и печать списка" << std::endl;
                    std::cout << "0. Выход" << std::endl;

                    cin >> variant3;

                    switch (variant3)
                    {
                    case 1:
                    {
                        cout << " Печать списка с начала  " << endl;
                        ListFromFirst(HeadNow);
                        break;
                    }
                    case 2:
                    {
                        cout << "  Печать списка с конца  " << endl;
                        ListFromEnd(HeadNow);
                        break;
                    }
                    case 3:
                    {
                        sortListByAge(HeadNow);
                        std::cout << "  Отсортированный по возрастанию атрибута 'age' список:  " << std::endl;
                        ListFromFirst(HeadNow);
                        break;
                    }
                    case 4:
                    {
                        sortListByTeam(HeadNow);
                        std::cout << "   Отсортированный по убыванию атрибута 'team' список:  " << std::endl;
                        ListFromFirst(HeadNow);
                        break;
                    }
                    case 5:
                    {
                        Sport newSportsmen1 = { "Alice", 19, 10, "Alfa", 13 };
                        std::cout << "  Отсортированный по возрастанию атрибута 'age' список с новым объектом  :" << std::endl;
                        AddAndSortByAge(HeadNow, newSportsmen1);
                        ListFromFirst(HeadNow);
                        break;
                    }
                    case 6:
                    {
                        std::cout << "  Отсортированный по убыванию атрибута 'team' список с новыми объектами  :" << std::endl;
                        Sport newSportsmen2 = { "Charlie", 20, 20, "Noon", 25 };
                        AddAndSortByTeam(HeadNow, newSportsmen2);
                        ListFromFirst(HeadNow);
                        break;
                    }
                    case 7:
                    {
                        std::cout << "  Поиск по возрасту и вывод записей:   " << std::endl;
                        // Пользовательский ввод номера для удаления
                        int ageToSearch;
                        cout << " Введите возраст для поиска: " << endl;
                        cin >> ageToSearch;

                        //int ageToSearch = 19; // Поиск по существующим данным
                        // int ageToSearch = 78; // Поиск по несуществующим данным
                        searchByAge(HeadNow, ageToSearch);
                        break;
                    }
                    case 8:
                    {
                        std::cout << "  Поиск по команде и вывод записей   :" << std::endl;
                        // Пользовательский ввод номера для удаления
                        string teamToSearch;
                        cout << "  Введите команду для поиска: " << endl;
                        cin >> teamToSearch;

                        //string teamToSearch = "Wolf"; // Поиск по существующим данным
                        // string teamToSearch = "Ulta"; // Поиск по несуществующим данным
                        searchByTeam(HeadNow, teamToSearch);
                        break;
                    }
                    case 9:
                    {
                        std::cout << "   Удаление по возрасту и вывод оставшихся записей:   " << std::endl;
                       // Пользовательский ввод возраста для удаления
                        int ageToDelete;
                        cout << " Введите возраст спортсмена для удаления" << endl;
                        cin >> ageToDelete;
                        
                        //int ageToDelete = 19; // Удаление по существующим  данным
                        // int ageToDelete = 19; // Удаление по несуществующим данным
                        deleteByAge(HeadNow, ageToDelete);
                        ListFromFirst(HeadNow);
                        break;
                    }
                    case 10:
                    {
                        std::cout << "   Удаление по команде и вывод оставшихся записей:   " << std::endl;
                        // Пользовательский ввод команды для удаления
                        string teamToDelete;
                        cout << " Введите команду спортсмена для удаления" << endl;
                        cin >> teamToDelete;
                        
                        //string teamToDelete = "Loft"; // Удаление по сущестующим данным
                        //string teamToDelete = "Korpus"; // Удаление по несущестующим данным
                        deleteByTeam(HeadNow, teamToDelete);
                        ListFromFirst(HeadNow);
                        break;
                    }
                    }
                } while (variant3 != 0);

                break;
            }
                
        }
    } while (variant != 0);
}
