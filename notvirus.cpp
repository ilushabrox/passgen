#include <iostream>
#include <cstdlib>
#include <ctime>

// Статическая линковка для Visual Studio
#ifdef _MSC_VER
#pragma comment(linker, "/MT")
#endif

char bucva() {
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f',
                       'g', 'h', 'i', 'j', 'k', 'l', 'm',
                       'n', 'o', 'p', 'q', 'r', 's', 't',
                       'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E',
                       'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int index = rand() % 52;  // 26 строчных + 26 заглавных = 52 буквы
    return alphabet[index];
}

char chislo() {
    return '0' + (rand() % 10);  // Цифры от 0 до 9
}

char symbol() {
    char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*',
                           '(', ')', '-', '_', '+', '=', '{', '}',
                           '[', ']', '|', '\\', ':', ';', '"', '\'',
                           '<', '>', ',', '.', '?', '/'};
    int index = rand() % 30;  // 30 специальных символов
    return specialChars[index];
}

int main() {
    srand(time(0));
    
    int colvo;
    std::cout << "Enter how much symbols you need: ";
    std::cin >> colvo;
    
    // Проверка на корректный ввод
    if (colvo <= 0 || colvo > 10000) {
        std::cout << "Ошибка: введите число от 1 до 10000\n";
        return 1;
    }
    
    for (int i = 0; i < colvo; i++) {
        int final = rand() % 3;  // 0, 1 или 2
        
        switch (final) {
            case 0:
                std::cout << bucva();
                break;
            case 1:
                std::cout << chislo();
                break;
            case 2:
                std::cout << symbol();
                break;
        }
    }
    
    std::cout << std::endl;
    system("pause");  // Чтобы консоль не закрывалась сразу (для Windows)
    
    return 0;
}