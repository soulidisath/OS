#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[50];

    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();
    if (pid == 0) { // Child process
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    } else if (pid > 0) { // Parent process
        write(pipe_fd[1], message, strlen(message) + 1);
    } else {
        perror("Fork failed");
    }
    return 0;
}
