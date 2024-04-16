// программа для иллюстации одинаковой работы процесса--родителя и процессса-ребенка

//подключение библиотек:
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//Главная функция программы 
int main() {
	//Объявление переменных 
	pid_t procid, parentid;//Индификаторы процессов
	pid_t result;//результат системного вызова fork()
	int a=0;//переменная для провверки работы процесса-родителя и процесса-ребенка
	result = fork();
	if (result<0){
		printf("Ошибка при выполнении fork()\n");
		exit(-1);
	}
	else if (result == 0){
	

		a = a+1;
		procid = getpid();//получение инд тек процесса
		parentid = getppid();// получение ид род процесса 
		printf("ид. процесса: %d, ид. родителя: %d, значение переменной a: %d\n,", procid, parentid,a);
	}

	else {
		a = a + 555;
		procid = getpid();//получение инд тек процесса
                parentid = getppid();// получение ид род процесса 
                printf("ид. процесса: %d, ид. родителя: %d, значение переменной a: %d\n,", procid, parentid,a);
	}
	return  0;
}

