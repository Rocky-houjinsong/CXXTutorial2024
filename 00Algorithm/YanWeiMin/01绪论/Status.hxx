// Status.hxx  文件 

/**********************************
 *                                *
 * 文件夹: ▲01 绪论                 *
 *                                *
 * 文件名: Status.hxx              *
 *                                *
 * 内  容: 相关状态码及宏函数列表      *
 *                                *
 **********************************/ 

#pragma once

#ifndef STATUS_HXX
#define STATUS_HXX

/** 状态码 */



#define TRUE 1 
#define FALSE 0

#define YES 1
#define NO 0

#define SUCCESS 1
#define UNSUCCESS 0

#define OK 1
#define ERROR 0

#define INFEASIBLE -1 

#ifndef _MATH_H_  
#define OVERFLOW -2
#define UNDERFLOW -3
#endif

#ifndef NULL
#define NULL ((void*) 0 )
#endif


/** 状态码 识别类型 */
typedef int Status;




/*宏函数*/
//函数暂停一段时间
#define Wait(x)\
 {\
	double _Loop_Num_;\
	for(_Loop_Num_=0.01; _Loop_Num_<=100000.0*x; _Loop_Num_+=0.01)\
		;\
 }//设立一个空循环 
 
//摁Enter键继续 
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }

#endif

