#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void handle_signal(int sig) {
    printf("Child received signal %d from parent\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { // Child process
        signal(SIGUSR1, handle_signal);
        pause(); // Wait for signal
    } else if (pid > 0) { // Parent process
        sleep(1); // Wait for child to be ready
        kill(pid, SIGUSR1);
    } else {
        perror("Fork failed");
    }
    return 0;
}
