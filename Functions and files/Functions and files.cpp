#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct scan_info {
private:
    string model;
    int price;
    double x_size;
    double y_size;
    int optr;
    int grey;
public:
    string get_model() {
        return model;
    }
    int get_price() {
        return price;
    }
    double get_x_size() {
        return x_size;
    }
    double get_y_size() {
        return y_size;
    }
    int get_optr() {
        return optr;
    }
    int get_grey() {
        return grey;
    }
    void set_model(string model) {
        this->model = model;
    }
    void set_price(int price) {
        this->price = price;
    }
    void set_x_size(double x_size) {
        this->x_size = x_size;
    }
    void set_y_size(double y_size) {
        this->y_size = y_size;
    }
    void set_optr(int optr) {
        this->optr = optr;
    }
    void set_grey(int grey) {
        this->grey = grey;
    }
};

//1 - проверка на открытость файла
//3 - функция вводящая данные о сканере с клавиатуры в структуру

void ProofOpen() {
    setlocale(LC_ALL, "rus");
    ifstream file;
    file.open("C:\\Users\\Rush\\Desktop\\Text.txt");
    if (file.is_open()) //Проверка файла
        cout << "Файл открыт!" << endl;
    else
    {
        cout << "Файл не открыт!" << endl;
    }
    file.close();
}

void ReadFile() {
    setlocale(LC_ALL, "rus");
    cout << endl << "ReadFile: " << endl << endl;
    ifstream file;
    string str;
    file.open("C:\\Users\\Rush\\Desktop\\Text.txt");
    while (!file.eof())
    {
        getline(file, str); 
        cout << str << endl; 
    }
    file.close();
}

scan_info MakeStruct (int i) {

    setlocale(LC_ALL, "rus");
    struct scan_info scan;
    cout << "Сканер #" << i;
    cout << endl << "Введите модель: \n";
    string model;
    cin >> model;
    scan.set_model(model);
    cout << endl << "Введите цену: \n";
    int price;
    cin >> price;
    scan.set_price(price);
    cout << endl << "Введите горизонтальный размер: \n";
    double x_size;
    cin >> x_size;
    scan.set_x_size(x_size);
    cout << endl << "Введите вертикальный размер: \n";
    double y_size;
    cin >> y_size;
    scan.set_y_size(y_size);
    cout << endl << "Введите оптическое разрешение: \n";
    int optr;
    cin >> optr;
    scan.set_optr(optr);
    cout << endl << "Введите градацию: \n";
    int grey;
    cin >> grey;
    scan.set_grey(grey);
    //file << " " << scan.grey;
    cout << endl;
    return scan;
}

void WriteInFile(scan_info & ad ) {
    ofstream file("C:\\Users\\Rush\\Desktop\\Text.txt", std::ios::app);
    file << ad.get_model() << " ";
    file << ad.get_price() << " ";
    file << ad.get_x_size() << " ";
    file << ad.get_y_size() << " ";
    file << ad.get_optr() << " ";
    file << ad.get_grey() << "\n";

}

int main()
{
    ofstream file("C:\\Users\\Rush\\Desktop\\Text.txt");
    file.close();
    setlocale(LC_ALL, "rus");
    int n;
    cout << endl << "Сколько записей будет? "; cin >> n; cout << endl;
    scan_info* arr = new scan_info[n];
    for (int i = 0; i < n; i++) {
        scan_info djuma;
        djuma = MakeStruct(i+1);
        arr[i] = djuma;
    }
    for (int i = n - 1; i >= 0; i--) {
        WriteInFile(arr[i]);
    }
    ReadFile();
}
//1 - proof
    //2 - 6 write (записей)
    //3 - write count object
    //4 - замена местами строки (swap)
    //5 - read file
//// Сохранение текущей позиции
        //std::ios::pos_type pos = file.tellp();
        //// Переход к позиции, хранящейся в pos 
        //file.seekp(pos);