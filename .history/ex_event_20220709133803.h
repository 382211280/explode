/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-07-09 00:35:12
 * @LastEditors: zhaodejin 382211280@qq.com
 * @LastEditTime: 2022-07-09 13:38:04
 * @FilePath: /explode/ex_event.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef EX_EXVENT_H
#define EX_EXVENT_H
//系统头文件
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/msg.h>
#include <linux/bpfilter.h>
//*event库头文件
#include <arpa/inet.h>
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer_compat.h>
#include <event2/buffer.h>
//!自定义端口
#define SERVER_PORT 9090
//!定义全局eventbase
static struct event_base *g_base = NULL;
//监听器
static struct evconlistener *g_event_listener =NULL;

//#服务端实现
int event_main();
#endif//EX_EXVENT_H