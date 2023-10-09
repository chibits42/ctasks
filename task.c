#include "task.h"

// array shit and shit
void task_arr_init(TaskArr* ta) {
	ta->size = 5;
	ta->used = 0;
	ta->arr = malloc(5 * sizeof(Task));
}

void task_arr_push(TaskArr* ta, Task i) {
	if (ta->used == ta->size) {
		ta->size *= 2;
		ta->arr = realloc(ta->arr, ta->size * sizeof(Task));
	}
	ta->arr[ta->used++] = i;
}

void task_arr_free(TaskArr* ta) {
	free(ta->arr);
	ta->arr = NULL;
	ta->used = ta->size = 0;
}

void taskf_arr_init(TaskfArr* ta) {
	ta->size = 5;
	ta->used = 0;
	ta->arr = malloc(5 * sizeof(Task));
}

void taskf_arr_push(TaskfArr* ta, TaskFolder i) {
	if (ta->used == ta->size) {
		ta->size *= 2;
		ta->arr = realloc(ta->arr, ta->size * sizeof(Task));
	}
	ta->arr[ta->used++] = i;
}

void taskf_arr_free(TaskfArr* ta) {
	free(ta->arr);
	ta->arr = NULL;
	ta->used = ta->size = 0;
}

void task_print(Task a) {
	printf("[%s]\n\t%s\n", a.name, a.desc);
}

void task_new_folder(TaskFolder* tf, char* name, char* desc) {
	task_arr_init(&tf->tasks);
	tf->name = name;
	tf->desc = desc;
}

