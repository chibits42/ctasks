#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
	GOAL,
	TASK,
} TaskType;

typedef enum {
	DONE,
	NOTDONE,
	INPROGRESS,
} TaskStatus;

typedef struct {
	char* name;
	TaskType tasktype;
	TaskStatus taskstat;
} Task;

typedef struct {
	Task* arr;
	size_t size;
	size_t used;
} TaskArr;

typedef struct {
	char* name;
	char* desc;
	TaskArr tasks;	
} TaskFolder;

typedef struct {
	TaskFolder* arr;
	size_t size;
	size_t used;
} TaskfArr;

void task_arr_init(TaskArr* ta);
void task_arr_push(TaskArr* ta, Task i);
void task_arr_free(TaskArr* ta);

void taskf_arr_init(TaskfArr* ta);
void taskf_arr_push(TaskfArr* ta, TaskFolder i);
void taskf_arr_free(TaskfArr* ta);

void task_new_folder(TaskFolder* tf, char* name);

