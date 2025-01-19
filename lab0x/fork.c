#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t child_pid = fork();
        if (child_pid == 0) { // Child process
            printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else if (child_pid > 0) { // Parent process
            printf("Parent: PID = %d, Created Child PID = %d\n", getpid(), child_pid);
        } else {
            perror("Fork failed");
        }
    }
    return 0;
}
