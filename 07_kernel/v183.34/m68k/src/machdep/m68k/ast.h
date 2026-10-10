/*
 * machdep/m68k/ast.h -- m68k machine AST (plan 432/433, authored, D024).
 * The original bytes set and clear 0x10000000 in a 32-bit word at
 * pcb+0x54 (plan 432); the macro form follows NeXTMach mk-108.1
 * next/pcb.h:58-62.
 */
/* 
 * NeXTMach next/pcb.h:
 * Copyright (c) 1987, 1988 NeXT, Inc.
 */
#ifndef _MACHDEP_M68K_AST_H_
#define _MACHDEP_M68K_AST_H_
#define MACHINE_AST
#define aston(mycpu)	{ current_thread()->pcb->pcb_flags |= 0x10000000; }
#define astoff(mycpu)	{ current_thread()->pcb->pcb_flags &= ~0x10000000; }
#endif
