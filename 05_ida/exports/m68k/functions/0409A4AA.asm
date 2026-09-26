0409A4AA: 4856                     pea     (a6)
0409A4AC: 2c4f                     movea.l sp,a6
0409A4AE: 48e7003c                 movem.l a2-a5,-(sp)
0409A4B2: 246e0008                 movea.l 8(a6),a2
0409A4B6: 2039040c9900             move.l  (_traceback_recursive).l,d0
0409A4BC: 6724                     beq.s   loc_409A4E2
0409A4BE: 4879040acda5             pea     (aTracebackRecur).l; "traceback: recursive call!\n"
0409A4C4: 61fffff70e92             bsr.l   _printf
0409A4CA: 4879040c9898             pea     (_traceback_jb).l
0409A4D0: 61fffff6738c             bsr.l   _longjmp
0409A4D6: 4879040ace11             pea     (aLoopingFp).l; "LOOPING fp\n"
0409A4DC: 4e94                     jsr     (a4)
0409A4DE: 584f                     addq.w  #4,sp
0409A4E0: 6074                     bra.s   loc_409A556
0409A4E2: 7201                     moveq   #1,d1
0409A4E4: 23c1040c9900             move.l  d1,(_traceback_recursive).l
0409A4EA: 2f0a                     move.l  a2,-(sp)
0409A4EC: 4879040acdc1             pea     (aTracebackFp0xX).l; "traceback: fp 0x%x\n"
0409A4F2: 49f90400b358             lea     (_printf).l,a4
0409A4F8: 4e94                     jsr     (a4)
0409A4FA: 2679040c96d0             movea.l (_interrupt_stack).l,a3
0409A500: 4beb1000                 lea     $1000(a3),a5
0409A504: 504f                     addq.w  #8,sp
0409A506: 220a                     move.l  a2,d1
0409A508: 08010000                 btst    #0,d1
0409A50C: 6648                     bne.s   loc_409A556
0409A50E: b7ca                     cmpa.l  a2,a3
0409A510: 6204                     bhi.s   loc_409A516
0409A512: bbca                     cmpa.l  a2,a5
0409A514: 6410                     bcc.s   loc_409A526
0409A516: b5fc0fffffff             cmpa.l  #$FFFFFFF,a2
0409A51C: 6338                     bls.s   loc_409A556
0409A51E: b5fc14000000             cmpa.l  #$14000000,a2
0409A524: 6230                     bhi.s   loc_409A556
0409A526: 2f2a0014                 move.l  $14(a2),-(sp)
0409A52A: 2f2a0010                 move.l  $10(a2),-(sp)
0409A52E: 2f2a000c                 move.l  $C(a2),-(sp)
0409A532: 2f2a0008                 move.l  8(a2),-(sp)
0409A536: 2f12                     move.l  (a2),-(sp)
0409A538: 2f2a0004                 move.l  4(a2),-(sp)
0409A53C: 4879040acdd5             pea     (aCalledFromPc0x).l; "called from pc 0x%08x fp 0x%08x 4-args "...
0409A542: 4e94                     jsr     (a4)
0409A544: 2012                     move.l  (a2),d0
0409A546: defc001c                 adda.w  #$1C,sp
0409A54A: b08a                     cmp.l   a2,d0
0409A54C: 6788                     beq.s   loc_409A4D6
0409A54E: 2440                     movea.l d0,a2
0409A550: 08000000                 btst    #0,d0
0409A554: 67b8                     beq.s   loc_409A50E
0409A556: 2f0a                     move.l  a2,-(sp)
0409A558: 4879040ace1d             pea     (aLastFp0xX).l; "last fp 0x%x\n"
0409A55E: 61fffff70df8             bsr.l   _printf
0409A564: 42b9040c9900             clr.l   (_traceback_recursive).l
0409A56A: 4cee3c00fff0             movem.l -$10(a6),a2-a5
0409A570: 4e5e                     unlk    a6
0409A572: 4e75                     rts
