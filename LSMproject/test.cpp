#include <iostream>
#include <chrono>
#include <thread>
#include <future>

void asynchronousBlockingTask() {
    std::cout << "Start Asynchronous Task" << std::endl;
    // 비동기 작업 시작
    std::future<void> result = std::async(std::launch::async, [] {
        // 작업이 완료될 때까지 대기
        std::this_thread::sleep_for(std::chrono::seconds(2));
        });
    // 다른 비동기 작업이나 동시에 수행할 수 있는 작업
    std::cout << "Do something else while waiting..." << std::endl;
    // 비동기 작업 완료 대기
    result.get();
    std::cout << "End Asynchronous Task" << std::endl;
}

int main() {
    std::cout << "Main Start" << std::endl;
    asynchronousBlockingTask(); // 블록 비동기 작업 호출
    std::cout << "Main End" << std::endl;
    return 0;
}