
int main() {
    const char* inputFileName = "input.txt"; // Название входного файла
    const char* outputFileName = "output.txt"; // Название файла для записи результата

    replace_to_0(inputFileName, outputFileName); // Вызываем функцию замены символов

    printf("Replace success. Result in '%s'.\n", outputFileName); // Выводим сообщение об успешном завершении

    return 0;
}