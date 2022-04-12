#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

#define SYS_delay_a_process 448
#define SYS_show_disp_time 449

int main(){
    pid_t ip_pid1, ip_pid2;
    printf("Enter the first pid:\n");
    scanf("%d", &ip_pid1);
    printf("Enter the second pid:\n");
    scanf("%d", &ip_pid2);
    int time;
    printf("Enter the time (unit is in milliseconds):\n");
    scanf("%d", &time);
    printf("Delaying the process with PID: %d, by %d milliseconds \n", ip_pid1, time);
    int x = syscall(SYS_delay_a_process, ip_pid1, time);
    if(x<0){
        printf("Unable to delay the process\n");
    }
    int y = syscall(SYS_show_disp_time, ip_pid1);
    if(y<0){
        printf("Unable to display the process 1 dispatch time\n");
    }
    
    int z = syscall(SYS_show_disp_time, ip_pid2);
    if(z<0){
        printf("Unable to display the process 2 dispatch time\n");
    }
    printf("Done\n");
}