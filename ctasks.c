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

// variables and shit for like the software and shit :3
typedef struct {
	TaskfArr folders;

} ctaskenv;

void mainloop() {
	while (true) {
		printf("%% ");
		char* com = getstr(50);

		if (strcmp(com, "exit") == 0) {
			printf("lfhkdsjhks ADD TASK???\n");
			break;
		}
	}
}

int main() {
	printf("Hello, World!\n");
	
	// TaskArr t;
	// task_arr_init(&t);
	//
	// Task simpletask = {
	// 	"guh", TASK, NOTDONE
	// };
	// 
	// for (int i = 0; i < 20; i++) {
	// 	task_arr_push(&t, simpletask); 
	// 	printf("size: %d\nused: %d\n", t.size, t.used);
	// }
	//
	
	mainloop();
	return 0;
}
