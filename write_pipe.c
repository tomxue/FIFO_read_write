#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define FIFO_SERVER "/home/tomxue/fifoserver"
#define NUM         12

int main(int argc, char **argv)
//参数为即将写入的字节数
{
    int fd;
    char w_buf[NUM];
    int real_wnum;

    memset(w_buf, '2', NUM);

    if ((mkfifo(FIFO_SERVER, 0666) < 0) && (errno != EEXIST))
        printf("cannot create fifoserver\n");
    if (fd == -1)
        if (errno == ENXIO)
            printf("open error; no reading process\n");

    // fd = open(FIFO_SERVER, O_WRONLY | O_NONBLOCK, 0);
    //设置非阻塞标志

    fd=open(FIFO_SERVER, O_WRONLY, 0);
    //设置阻塞标志
    real_wnum = write(fd, w_buf, NUM / 4);
    if (real_wnum == -1) {
        printf("write failed!\n");
        if (errno == EAGAIN)
            printf("write to fifo error; try later\n");
    } else
        printf("real write num is %d, data: %.*s\n", real_wnum, real_wnum, w_buf);

    //5000用于测试写入字节大于4096时的非原子性
    //real_wnum=write(fd,w_buf,4096);
    //4096用于测试写入字节不大于4096时的原子性

    if (real_wnum == -1)
        if (errno == EAGAIN)
            printf("try later\n");
}
