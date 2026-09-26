0400BC66: 4856                     pea     (a6)
0400BC68: 2c4f                     movea.l sp,a6
0400BC6A: 48e72030                 movem.l d2/a2-a3,-(sp)
0400BC6E: 246e0008                 movea.l 8(a6),a2
0400BC72: 4282                     clr.l   d2
0400BC74: 2679040b69bc             movea.l (_mon_global).l,a3
0400BC7A: 4ab9040b69c8             tst.l   (_panicstr).l
0400BC80: 6714                     beq.s   loc_400BC96
0400BC82: 4ab9040b69c4             tst.l   (_paniccpu).l
0400BC88: 6604                     bne.s   loc_400BC8E
0400BC8A: 7404                     moveq   #4,d2
0400BC8C: 6014                     bra.s   loc_400BCA2
0400BC8E: 61ff00088cee             bsr.l   _halt_cpu
0400BC94: 600c                     bra.s   loc_400BCA2
0400BC96: 23ca040b69c8             move.l  a2,(_panicstr).l
0400BC9C: 42b9040b69c4             clr.l   (_paniccpu).l
0400BCA2: 2f0a                     move.l  a2,-(sp)
0400BCA4: 2f39040b69c4             move.l  (_paniccpu).l,-(sp)
0400BCAA: 4879040a6299             pea     (aPanicCpuDS).l; "panic: (Cpu %d) %s\n"
0400BCB0: 45f90400b358             lea     (_printf).l,a2
0400BCB6: 4e92                     jsr     (a2)
0400BCB8: 306b030c                 movea.w $30C(a3),a0
0400BCBC: 2f08                     move.l  a0,-(sp)
0400BCBE: 306b030a                 movea.w $30A(a3),a0
0400BCC2: 2f08                     move.l  a0,-(sp)
0400BCC4: 366b0312                 movea.w $312(a3),a3
0400BCC8: 2f0b                     move.l  a3,-(sp)
0400BCCA: 4879040a62ad             pea     (aNextRomMonitor).l; "NeXT ROM Monitor %d.%d v%d\n"
0400BCD0: 4e92                     jsr     (a2)
0400BCD2: 4879040b3119             pea     (_version).l; "NeXT Mach 4.2: Sun Apr 27 13:42:14 PDT "...
0400BCD8: 4879040a62c9             pea     (aPanicS).l; "panic: %s\n"
0400BCDE: 4e92                     jsr     (a2)
0400BCE0: defc0020                 adda.w  #$20,sp ; ' '
0400BCE4: 2eb9040b606c             move.l  (_boothowto).l,(sp)
0400BCEA: 4879040a62d4             pea     (aSystemPanic).l; "System Panic"
0400BCF0: 4879040a62e1             pea     (aPanic).l; "panic"
0400BCF6: 61ff00087c7e             bsr.l   _mini_mon
0400BCFC: 4879040a62e7             pea     (unk_40A62E7).l
0400BD02: 2f02                     move.l  d2,-(sp)
0400BD04: 42a7                     clr.l   -(sp)
0400BD06: 61ffffffc736             bsr.l   _boot
0400BD0C: 4cee0c04fff4             movem.l -$C(a6),d2/a2-a3
0400BD12: 4e5e                     unlk    a6
0400BD14: 4e75                     rts
