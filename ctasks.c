#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"

char* getstr(int len) {
	char* buf = calloc(len, sizeof(char));
	fgets(buf, len, stdin);
	buf[strcspn(buf, "\n")] = 0;

	return buf;
}

bool bool_prompt(char* prompt) {
	printf("%s", prompt);
	char* buf = getstr(10);

	if ((strcmp(buf, "y") == 0) || (strcmp(buf, "yes") == 0)) {
		return true;
	} else {
		return false;
	}
} 

// variables and shit for like the software and shit :3
typedef struct {
	TaskfArr folders;
	char* current_dir;
} ctaskenv;

void mainloop() {
	ctaskenv env;
	taskf_arr_init(&env.folders);
	task_arr_init(&env.folders.arr->tasks); // i feel like this is really stupid``

	while (true) {
		printf("%% ");
		char* com = getstr(50);

		if (strcmp(com, "exit") == 0) {
			break;
		} else if (strcmp(com, "add") == 0) {
			printf("Task Name: ");
			char* tname = getstr(50);

			printf("Task Description: ");
			char* tdesc = getstr(1000);

			bool urgent = bool_prompt("Is this task urgent? [y/n] ");

			Task t;
			t.name = tname;
			t.desc = tdesc;
			t.tasktype = URGENT ? urgent : NOTURGENT;
			t.taskstat = NOTDONE;
			task_arr_push(&env.folders.arr->tasks, t);
			
			printf("\nNew task created:\n");
			task_print(t);
		}
	}
}

int main() {
	printf("ctasks v0.1.0\n");	
	mainloop();
	return 0;
}
