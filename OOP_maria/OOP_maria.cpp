#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

double string_to_double(string);

class FILE_ {
private:
    ifstream    file_read;
    ofstream    file_record;
public:
    //Конструктор 
    FILE_(string str) {
        if (str == "read") {
            file_read.open("file.txt");
            if (!file_read.is_open()) {
                cout << "Файл не может быть открыт!\n";
                
            }
            return;
        }
        if (str == "record") {
            file_record.open("file.txt");
            if (!file_record.is_open()) {
                cout << "Файл не может быть открыт!\n";
               
            }
            return;
        }
        cout << "Неверное заданное значение!\n";
       
    }
    //Открытие Файла для записи или чтения
    void open(string str) {
        if (str == "read") {
            file_read.open("file.txt");
            if (!file_read.is_open()) {
                cout << "Файл не может быть открыт!\n";

            }
            return;
        }
        if (str == "record") {
            file_record.open("file.txt");
            if (!file_record.is_open()) {
                cout << "Файл не может быть открыт!\n";

            }
            return;
        }
        cout << "Неверное заданное значение!\n";
    }
    //Закрытие файла 
    void close() {
        file_read.close();
        file_record.close();
        cout << "Файл закрыт!\n\n\n" << "//////////////////////////////////////////////////" << endl;

    }
    //Запись для типа int
    void operator <<(int n) {
        file_record << n;
    }
    //Запись для типа double
    void operator <<(double n) {
        file_record << n;
    }
    //Чтение из файла для int
    void operator >> (int* n) {
        string str;
        file_read >> str;
        *n = string_to_double(str);
    }
    //Чтение из файла для double
    void operator >> (double* n) {
        string str;
        file_read >> str;
        *n = string_to_double(str);
    }
    //Запись
    void record(string str) {
        file_record << str;
    }
    //Чтение из файла
    void read(string* str) {
        file_read >> *str;
    }
    //Деструктор
    ~FILE_() {
        file_read.close();
        file_record.close();
    }
};
//Функция перевода string в double
double string_to_double( string s)
{
    istringstream i(s);
    double x;
    if (!(i >> x))
        return 0;
    return x;
}


int main()
{
    setlocale(LC_ALL, "rus");
    FILE_ file("read");
    int number;
    double buff_n;
    string buff;
    while (true) {
        cout << "Введите 1 для чтения,2 для записи или 3 для выхода" << endl;
        cin >> number;
        cout << endl;
        switch (number) {
        case 2:
            file.open("record");
            cout << "Введите что вы хотите записать в файл: число(1) или строку(2)" << endl;
            cin >> number;
            if (number == 1) {
                cout << "Введите число: ";
                cin >> buff_n;
                if (int(buff_n) == buff_n) {
                    file << int(buff_n);
                    file.close();
                }
                else {
                    file << buff_n;
                    file.close();
                }
                break;
            }
            if (number == 2) {
                cout << "Введите строку: ";
                cin >> buff;
                file.record(buff);
                file.close();
                break;
            }
            cout << "Неверное значение!\n";
            file.close();
            break;
        case 1:
            file.open("read");
            cout << "Введите, какой тип данных для считывания: число(1) или строка(2)" << endl;
            cin >> number;
            if (number == 1) {
                file >> &buff_n;
                if (int(buff_n) == buff_n) {
                    cout << "Ваше число: " << buff_n << endl;
                    file.close();
                }
                else {
                    cout << "Ваше число: " << buff_n << endl;
                    file.close();
                }
                break;
            }
            if (number == 2) {
                file.read(&buff);
                cout << "Ваша строчка: " << buff<<endl;
                break;
            }
            cout << "Неверное значение!\n";
            file.close();
            break;
            
        default:
            cout << "Неверное значение!\n";
            break;
        case 3:
            return 0;
        }
    }
    
   
        
}

