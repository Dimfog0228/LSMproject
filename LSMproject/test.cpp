#include <iostream>
#include <chrono>
#include <thread>
#include <future>

void asynchronousBlockingTask() {
    std::cout << "Start Asynchronous Task" << std::endl;
    // �񵿱� �۾� ����
    std::future<void> result = std::async(std::launch::async, [] {
        // �۾��� �Ϸ�� ������ ���
        std::this_thread::sleep_for(std::chrono::seconds(2));
        });
    // �ٸ� �񵿱� �۾��̳� ���ÿ� ������ �� �ִ� �۾�
    std::cout << "Do something else while waiting..." << std::endl;
    // �񵿱� �۾� �Ϸ� ���
    result.get();
    std::cout << "End Asynchronous Task" << std::endl;
}

int main() {
    std::cout << "Main Start" << std::endl;
    asynchronousBlockingTask(); // ��� �񵿱� �۾� ȣ��
    std::cout << "Main End" << std::endl;
    return 0;
}