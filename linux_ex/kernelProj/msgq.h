#ifndef MSGQ_H
#define MSGQ_H


#define SEND_MESSAGE	16
#define RECIEVE_MESSAGE	17
#define FIFO_DEBUG 18
#define MAX_MESSAGE	4096

#pragma pack(push,1)
typedef struct my_msg_t {
	int m_size;
	char* m_data;
}my_msg_t;
#pragma pack(pop)

#endif








