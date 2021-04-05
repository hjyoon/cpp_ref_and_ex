#include <iostream>
#include <cstdio>
#include <thread>
#include <chrono>
#include <string>
#include <winsock2.h>

using namespace std;

#define SERVER_PORT 11235  // server port number
#define BUF_SIZE 1024
#define IPAddress "127.0.0.1" // server IP address

void send_msg(SOCKET sock) { 
    while(1) {
        char msg[BUF_SIZE] = {0};
        fflush(stdin);
        fgets(msg, BUF_SIZE, stdin);
        if(strcmp(msg, "exit\n") == 0) {
            shutdown(sock, SD_BOTH);
            break;
        }
        int n = send(sock, msg, BUF_SIZE, 0);
    }
}
 
void recv_msg(SOCKET sock) {
    while(1) {
        char buf[BUF_SIZE] = {0};
        int n = recv(sock, buf, BUF_SIZE, 0);
        if (n <= 0) {
            shutdown(sock, SD_BOTH);
            printf("Got nothing\n"); 
            break; 
        }
        buf[n] = 0; // make a string
        cout << "Received: " << buf;
    }
}

int main(void) {
    WSADATA wsaData;
    SOCKADDR_IN target; //Socket address information
    SOCKET s;
 
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup error %ld", WSAGetLastError());
        WSACleanup();
        return 0;
    }

    string ip_input;

    cout << "Please input ip address : ";
    cin >> ip_input;

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET; // address family Internet
    target.sin_port = htons(SERVER_PORT); //Port to connect on
    //target.sin_addr.s_addr = inet_addr(IPAddress); //Target IP
    target.sin_addr.s_addr = inet_addr(ip_input.c_str()); //Target IP
 
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
    if (s == INVALID_SOCKET) {
        cout << "socket() error : "<< WSAGetLastError() << endl;
        WSACleanup();
        return 0; //Couldn't create the socket
    }
 
    if (connect(s, (SOCKADDR*)&target, sizeof(target)) == SOCKET_ERROR) {
        cout << "connect() error : " << WSAGetLastError() << endl;
        WSACleanup();
        return 0; //Couldn't connect
    }

    thread t1(send_msg, s);
    thread t2(recv_msg, s);

    t1.join();
    t2.join();
 
    closesocket(s);
    WSACleanup();
 
    return 0;
 
}