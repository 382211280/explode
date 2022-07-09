/*
 * @LastEditors: zhaodejin
 * @Description: Copyright by zhaodejin
 * @Author: zhaodejin 382211280@qq.com
 * @Date: 2022-07-09 00:35:12
 * @LastEditTime: 2022-07-09 22:45:18
 * @FilePath: /explode/ex_event.c
 */
#include "ex_event.h"
#include "log.h"
#include "pub.h"

// TODO
void read_cb(struct bufferevent *pbuffer, void *data)
{
    int recvlen = 0;
    char buff[1024] = {0};
    recvlen = bufferevent_read(pbuffer, buff, sizeof(buff));
    printf("recv:%s\n", buff);
    if (strstr(buff, "quit"))
    {
        printf("will close connect\n");
        sleep(2);
        bufferevent_free(pbuffer);
    }
labal_ret:
    return;
}

// TODO
void write_cb(struct bufferevent *p_buff, void *data)
{
    if (NULL == p_buff)
    {
        return;
    }
}

// TODO
void listen_cb(struct evconnlistener *p_listener, evutil_socket_t fd, struct sockaddr *p_sock_addr, int socklen, void *data)
{
    s64 ret = 0;
    s64 session_index = -1;
    struct bufferevent *p_evbuffer = NULL;
    struct sockaddr_in client_addr = {0};
    u64 len = sizeof(client_addr);
    u64 fd_on = 1;
    u64 fd_keep_idle = 60;
    u64 fd_keep_interval = 20;
    u64 fd_keep_count = 3;
    event_base *tmp_base = (event_base *)data;
    // TODO
    if (fd < 0)
    {
        ret = -1;
        goto lab_ret;
    }
    setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (void *)&fd_on, sizeof(fd_on));
    setsockopt(fd, SOL_SOCKET, TCP_KEEPIDLE, (void *)&fd_keep_idle, sizeof(fd_keep_idle));
    setsockopt(fd, SOL_SOCKET, TCP_KEEPINTVL, (void *)&fd_keep_interval, sizeof(fd_keep_interval));
    setsockopt(fd, SOL_SOCKET, TCP_KEEPCNT, (void *)&fd_keep_count, sizeof(fd_keep_count));

    // TODO
    p_evbuffer = bufferevent_socket_new(g_base, fd, BEV_OPT_CLOSE_ON_FREE);
    if (p_evbuffer == NULL)
    {
        ret = -1;
        goto lab_ret;
    }
    // TODO
    bufferevent_setcb(p_evbuffer, read_cb, write_cb, NULL, NULL);
    ret = bufferevent_enable(p_evbuffer, EV_READ | EV_WRITE | EV_PERSIST);
    if (ret != ERR_SUCCESS)
    {
        ret = -1;
        goto lab_ret;
    }
    printf("event accept ok.\n");
lab_ret:
    if (ret != ERR_SUCCESS)
    {
        if (p_evbuffer != NULL)
        {
            bufferevent_free(p_evbuffer);
            p_evbuffer = NULL;
            fd = -1;
        }
        if (fd > 0)
        {
            evutil_closesocket(fd);
            fd = -1;
        }
    }
    return;
}
// TODO
int event_main()
{
    s64 ret = 0;
    // TODO
    struct evconnlistener *e_listener = NULL;
    struct sockaddr_in severaddr = {0};
    g_base = event_base_new();
    // TODO
    if (g_base == NULL)
    {
        DEBUG("event_base_new failded!");
        ret = -1;
        goto lab_ret;
    }
    // TODO
    severaddr.sin_family = AF_INET;
    severaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    severaddr.sin_port = htons(SERVER_PORT);

    // TODO
    g_event_listener = evconnlistener_new_bind(g_base, listen_cb, NULL,
                                               LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE | LEV_OPT_THREADSAFE, 10, (struct sockaddr *)&severaddr,
                                               sizeof(struct sockaddr_in));
    if (g_event_listener == NULL)
    {
        ret = -1;
        goto lab_ret;
    }
    printf("listener init ok, port = %d\n", SERVER_PORT);
    ret = event_base_dispatch(g_base);
    if (ret != ERR_SUCCESS)
    {
        ret = -1;
        goto lab_ret;
    }
lab_ret:

    return ret;
}
