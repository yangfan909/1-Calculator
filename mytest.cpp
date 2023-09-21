#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // 创建管道，用于向计算器程序发送数据
    int pipe_send[2];
    if (pipe(pipe_send) == -1) {
        std::cerr << "Error: Failed to create send pipe." << std::endl;
        return 1;
    }

    // 创建子进程，用于向计算器程序发送数据
    pid_t pid_send = fork();
    if (pid_send == -1) {
        std::cerr << "Error: Failed to fork send process." << std::endl;
        return 1;
    }

    if (pid_send == 0) { // 子进程
        close(pipe_send[1]); // 关闭发送管道的写入端

        dup2(pipe_send[0], STDIN_FILENO); // 将发送管道的读取端连接到标准输入

        // 启动计算器程序
        execl("./test", "./test", nullptr); // 请替换为你的计算器程序的路径

        // 如果execl失败，打印错误信息
        std::cerr << "Error: Failed to execute calculator program." << std::endl;
        return 1;
    }

    // 主进程
    close(pipe_send[0]); // 关闭发送管道的读取端

    while (true) {
        // 提示用户输入表达式
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);

        // 输入空行表示退出
        if (input.empty()) {
            break;
        }

        // 向计算器程序发送数据
        write(pipe_send[1], input.c_str(), input.length());
        write(pipe_send[1], "\n", 1);
        fflush(stdin); // 刷新管道以确保数据被发送

        // 等待子进程完成
        int status;
        waitpid(pid_send, &status, 0);

        // 重新创建子进程，用于向计算器程序发送数据
        pid_send = fork();
        if (pid_send == -1) {
            std::cerr << "Error: Failed to fork send process." << std::endl;
            return 1;
        }

        if (pid_send == 0) { // 子进程
            close(pipe_send[1]); // 关闭发送管道的写入端

            dup2(pipe_send[0], STDIN_FILENO); // 将发送管道的读取端连接到标准输入

            // 启动计算器程序
            execl("./test", "./test", nullptr); // 请替换为你的计算器程序的路径

            // 如果execl失败，打印错误信息
            std::cerr << "Error: Failed to execute calculator program." << std::endl;
            return 1;
        }
    }

    return 0;
}
