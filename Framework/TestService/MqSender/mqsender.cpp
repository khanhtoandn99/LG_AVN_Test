// C Program for Message Queue (Writer Process)
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#define MAX 10

enum E_MQ_MSG_TYPE : long
{
    E_MQ_MSG_TYPE_REQUESTGETSCOREDATA = 1
};

// structure for message queue
struct MQ_MSG_DATA_T {
    E_MQ_MSG_TYPE mesg_type;
    char mesg_text[100];
};
  
int main()
{
    key_t key;
    int msgid;
    MQ_MSG_DATA_T message;
  
    // ftok to generate unique key
    key = ftok("/home/avn/Desktop/progfile", 65);
  
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    printf("New msgid = %d\n", msgid);

    message.mesg_type = E_MQ_MSG_TYPE_REQUESTGETSCOREDATA;
  
    printf("Write Data : ");
    // fgets(message.mesg_text,MAX,stdin);
    memcpy(message.mesg_text, "Application/AVNAppC 1 luan_pham", sizeof("Application/AVNAppC 1 luan_pham"));
  
    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);
  
    // display the message
    printf("Data send is : %s \n", message.mesg_text);
  
    return 0;
}