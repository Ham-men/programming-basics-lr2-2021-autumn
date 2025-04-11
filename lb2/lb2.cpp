#include <stdio.h>
#define MAXLINE 1024

#pragma warning(disable : 4996)
//скопировать содержимое текстового файла, удалив строку с наибольшим количеством слов
int main(void) {
	// указатели на структуру типа FILE для
	// входной и выходного файлов
	FILE* fpin;
	FILE* fpout;
	char line[MAXLINE]; // текущая строка
	char* ptr;
	int stroki = 0;
	int colword[10];
	int i = 0, i2 = 0;
	int maxwordline = 0;
	// открыть файл для чтения
	fpin = fopen("test.txt", "rt");
	if (fpin == NULL)
		return 0; // ошибка при открытии файла
	// открыть файл для записи
	fpout = fopen("result.txt", "wt");
	if (fpout == NULL)
		return 0; // ошибка при открытии файла
	while (!feof(fpin)) { // цикл до конца файла
		// чтение строки
		ptr = fgets(line, MAXLINE, fpin);
		if (ptr == NULL)
			break; // файл исчерпан
		while (*ptr != '\0') { // цикл до конца строки
			if (*ptr == ' ' || *ptr == '.' || *ptr == ',' || *ptr == '!' || *ptr ==
				'?') {
				i2++;
			}
			ptr++; // продвигаем указатель по строке
		}
		colword[i] = i2;
		if (stroki < colword[i]) { // находим длинную строку
			stroki = colword[i];
			maxwordline = i;
		}
		i2 = 0;
		i++;
		//fputs( line, fpout ); // запись строки
	}
	fclose(fpin);
	fpin = fopen("test.txt", "rt");
	if (fpin == NULL)
		return 0;
	i2 = 0;
	while (!feof(fpin)) { // цикл до конца файла
		// чтение строки
		ptr = fgets(line, MAXLINE, fpin);
		if (ptr == NULL)
			break; // файл исчерпан
		while (*ptr != '\0') { // цикл до конца строки
			if (i2 == maxwordline) {
				*ptr = '\n'; // ставим символ "конец
				//строки"
				*ptr = '\0';
				break;
			}
			ptr++; // продвигаем указатель по строке
		}
		i2++;
		fputs(line, fpout); // запись строки
	}
	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл
	return 0;
}