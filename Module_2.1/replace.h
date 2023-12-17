#pragma once

/* @brief
Открываем файлы для чтения и записи. 
Находим первое "-+". 
Заменяем символы "-+" на "0".
Находим следующее "-+".
Закрываем файл для чтения и обработанный файл для записи.
*/
void replace_to_0(const char* inputFileName, const char* outputFileName);
