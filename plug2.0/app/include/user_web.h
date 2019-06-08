/*
 * user_web.h
 *
 *  Created on: 2018年11月4日
 *      Author: lenovo
 */

#ifndef __USER_WEB_H__
#define __USER_WEB_H__

#define WEB_RECVBUF_SIZE 	(1024)	//接收缓冲区大小
#define WEB_SENDBUF_SIZE 	(1024)	//发送缓冲区大小

#define WEB_MUX 			(1024)	//循环发送时，最大传输单元


#define WEB_MAX_FD 				5	//最大可接受连接数并发（根据空闲栈大小来调整）
#define WEB_CONTINUE_TMOUT		3	//连接超时时间，超过该时间未进行数据交互将主动断开连接


VOID WEB_StartWebServerTheard( VOID );
VOID WEB_StopWebServerTheard( VOID );

UINT8 WEB_GetWebSvcStatus( VOID );

#endif /* __USER_WEB_H__ */
