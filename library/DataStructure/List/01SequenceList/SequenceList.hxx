/***************************************
 *                                     *
 * �ļ���: ��02 ���Ա�\01 SequenceList *
 *                                     *
 * �ļ���: SequenceList.h              *
 *                                     *
 * ��  ��: ˳�����ز����б�          *
 *                                     *
 ***************************************/

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
#include "Status.hxx"		//**��01 ����**//

/* �궨�� */
#define LIST_INIT_SIZE 100				//˳����洢�ռ�ĳ�ʼ������ 
#define LISTINCREMENT  10				//˳����洢�ռ�ķ�������

/* ˳������Ͷ��� */
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct
{
	LElemType_Sq *elem;					//�洢�ռ��ַ��ָ���һ������ָ�룩 
	int length;							//��ǰ˳������ȣ� 
	int listsize;						//��ǰ����Ĵ洢���� 
}SqList;								//˳���0�ŵ�Ԫ����ʹ�� 

/* ˳��������б� */
Status InitList_Sq(SqList *L);
/*��������������������������������
��(01)�㷨2.3����ʼ����˳���L����
��������������������������������*/

void ClearList_Sq(SqList *L);
/*��������������������
��(02)���˳���L�� ��
��������������������*/

void DestroyList_Sq(SqList *L);
/*��������������������
��(03)����˳���L�� ��
��������������������*/
	  
Status ListEmpty_Sq(SqList L);
/*����������������������������
��(04)�ж�˳���L�Ƿ�Ϊ�ա� ��
����������������������������*/

int ListLength_Sq(SqList L);
/*������������������������������
��(05)����˳���L��Ԫ�ظ����� ��
������������������������������*/
	
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);
/*����������������������������������
��(06)��e����˳���L�е�i��Ԫ�ء� ��
����������������������������������*/

int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));
/*��������������������������������������������������������������
��(07)�㷨2.6������˳���L���׸���e����Compare��ϵ��Ԫ��λ�򡣩�
��������������������������������������������������������������*/

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);
/*������������������������������������
��(08)��pre_e����cur_e��ǰ����      ��
������������������������������������*/

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);
/*������������������������������������
��(09)��next_e����cur_e�ĺ�̡�     ��
������������������������������������*/

Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);
/*��������������������������������������������
��(10)�㷨2.4����˳���L�ĵ�i��λ���ϲ���e����
��������������������������������������������*/

Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);
/*��������������������������������������������������������
��(11)�㷨2.5��ɾ��˳���L�ϵ�i��λ�õ�Ԫ�أ�����e���ء���
��������������������������������������������������������*/

Status ListTraverse_Sq(SqList L, void (Visit)(LElemType_Sq)); 
/*������������������������������
��(12)��visit��������˳���L����
������������������������������*/

#endif
