#ifndef _INTERRUPT_H_INCLUDED_
#define _INTERRUPT_H_INCLUDED_

/* 以下はリンカスクリプトで定義してあるシンボル */
extern char softvec;
#define SOFTVEC_ADDR (&softvec)

/* ソフトウェア・割り込みベクタの種別を表す型定義 */
typedef short softvec_type_t;

/* 割り込みハンドラの型定義 */
typedef void (*softvec_handler_t)(softvec_type_t type, unsigned long sp);

/* ソフトウェア割り込みベクタの位置 */
#define SOFTVECS  ((softvec_handler_t *)SOFTVEC_ADDR)

/* 割り込みの有効/無効 */
#define INTR_ENABLE   asm volatile ("andc.b #0x3f,ccr")
#define INTR_DISABLE  asm volatile ("orc.b #0xc0,ccr")

/* ソフトウェア・割り込みベクタの初期化 */
int softvec_init(void);

/* ソフトウェア・割り込みベクタの設定 */
int softvec_setintr(softvec_type_t type, softvec_handler_t handler);

/* 共通割込みハンドラ */
void interrupt(softvec_type_t type, unsigned long sp);

#endif
