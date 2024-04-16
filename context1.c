//Подключение библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//Главная функция программы 
int main(int argc, char *argv[], char *envp[]) {
	//Объявление переменных
	int result1; 
	pid_t procid, parentid;//Индификаторы процессов
	pid_t result;//результат системного вызова fork()
	int a=0;//переменная для провверки работы процесса-родителя и процесса-ребенка
	result = fork();
	if (result<0) {
		printf("Ошибка при выполнении fork()\n");
		exit(-1);
	}
	else if (result == 0) {
		a = a+1;
		procid = getpid();//получение инд тек процесса
		parentid = getppid();// получение ид род процесса 
		printf("ид. процесса: %d, ид. родителя: %d, значение переменной a: %d\n,", procid, parentid,a);
		//Запуск программы cat с аргументом otchet_16_04_2024.txt
		result1 = execle("/bin/cat", "/bin/cat", "otchet_16_04_2024.txt", 0, envp);
		printf("Ошибка при выполнении системного вызова execle()\n");
		exit(-1);
	}

	else {
		a = a + 555;
		procid = getpid();//получение инд тек процесса
                parentid = getppid();// получение ид род процесса 
                printf("ид. процесса: %d, ид. родителя: %d, значение переменной a: %d\n,", procid, parentid,a);
	}
	return 0; //Никогда не выполняется
}
