#include <iostream>

struct stack {
    int array_data[15];
    int top;
};

stack tumpuk;

void push(int input) {
    tumpuk.top++;
    tumpuk.array_data[tumpuk.top] = input;
}

int pop() {
    int item = tumpuk.array_data[tumpuk.top];
    tumpuk.top--;
    return item;
}

void begin() {
    tumpuk.top = -1;
}

bool isEmpty() {
    return tumpuk.top == -1;
}

bool isFull() {
    return tumpuk.top == 14;
}

void print() {
    std::cout << "Data : " << std::endl;
    for (int i = 0; i <= tumpuk.top; i++) {
        std::cout << tumpuk.array_data[i] << " ";
    }
    std::cout << "\n\n";
}

int main() {
    int pilihan, input;
    begin();

    do {
        std::cout << "1. push data" << std::endl;
        std::cout << "2. pop data" << std::endl;
        std::cout << "3. print data" << std::endl;
        std::cout << "4. clear data" << std::endl;
        std::cout << "5. exit " << std::endl;
        std::cout << "Pilih : ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (isFull()) {
                    std::cout << "Tumpukan Penuh";
                } else {
                    std::cout << "Data yang di push: ";
                    std::cin >> input;
                    push(input);
                }
                break;
            }
            case 2: {
                if (isEmpty()) {
                    std::cout << "Tumpukan Kosong";
                } else {
                    std::cout << "Data yang di pop: " << pop() << std::endl;
                }
                break;
            }
            case 3: {
                if (isEmpty()) {
                    std::cout << "Tumpukan Kosong" << "\n";
                } else {
                    print();
                }
                break;
            }
            case 4: {
                begin();
                break;
            }
            case 5: {
                std::cout << "Keluar dari program.\n";
                break;
            }
            default: {
                std::cout << "Pilihan tidak valid.\n";
                break;
            }
        }
    } while (pilihan != 5);

    return 0;
}
