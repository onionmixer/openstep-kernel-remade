0400A42A: 4e56fff8                 link    a6,#-8
0400A42E: 2f0a                     move.l  a2,-(sp)
0400A430: 2f02                     move.l  d2,-(sp)
0400A432: 242e0008                 move.l  arg_0(a6),d2
0400A436: 0c821ff46b7f             cmpi.l  #$1FF46B7F,d2
0400A43C: 6304                     bls.s   loc_400A442
0400A43E: 4a82                     tst.l   d2
0400A440: 6c12                     bge.s   loc_400A454
0400A442: 4879040a6121             pea     (aWarningPrepost).l; "WARNING: preposterous time in file syst"...
0400A448: 61ff00000f0e             bsr.l   _printf
0400A44E: 584f                     addq.w  #4,sp
0400A450: 600000c2                 bra.w   loc_400A514
0400A454: 45eefff8                 lea     var_8(a6),a2
0400A458: 2f0a                     move.l  a2,-(sp)
0400A45A: 61ff00044530             bsr.l   _microtime
0400A460: 41f9040b67d0             lea     (_boottime).l,a0
0400A466: 20aefff8                 move.l  var_8(a6),(a0)
0400A46A: 42b9040b67d4             clr.l   (dword_40B67D4).l
0400A470: 2210                     move.l  (a0),d1
0400A472: 2001                     move.l  d1,d0
0400A474: 9082                     sub.l   d2,d0
0400A476: 584f                     addq.w  #4,sp
0400A478: 6a02                     bpl.s   loc_400A47C
0400A47A: 4480                     neg.l   d0
0400A47C: 0c800002a2ff             cmpi.l  #$2A2FF,d0
0400A482: 6206                     bhi.s   loc_400A48A
0400A484: b481                     cmp.l   d1,d2
0400A486: 6d000098                 blt.w   loc_400A520
0400A48A: 0c8101e1337f             cmpi.l  #$1E1337F,d1
0400A490: 622e                     bhi.s   loc_400A4C0
0400A492: 4879040a614b             pea     (aWarningClockNo).l; "WARNING: clock not set properly"
0400A498: 61ff00000ebe             bsr.l   _printf
0400A49E: 2d42fff8                 move.l  d2,var_8(a6)
0400A4A2: 42aefffc                 clr.l   var_4(a6)
0400A4A6: 2f0a                     move.l  a2,-(sp)
0400A4A8: 61fffffffe64             bsr.l   _setthetime
0400A4AE: 23eefff8040b67d0         move.l  var_8(a6),(_boottime).l
0400A4B6: 23eefffc040b67d4         move.l  var_4(a6),(dword_40B67D4).l
0400A4BE: 6052                     bra.s   loc_400A512
0400A4C0: 0c800076a700             cmpi.l  #$76A700,d0
0400A4C6: 632e                     bls.s   loc_400A4F6
0400A4C8: 4879040a616b             pea     (aWarningPrepost_0).l; "WARNING: preposterous time in Real Time"...
0400A4CE: 61ff00000e88             bsr.l   _printf
0400A4D4: 2d42fff8                 move.l  d2,var_8(a6)
0400A4D8: 42aefffc                 clr.l   var_4(a6)
0400A4DC: 2f0a                     move.l  a2,-(sp)
0400A4DE: 61fffffffe2e             bsr.l   _setthetime
0400A4E4: 23eefff8040b67d0         move.l  var_8(a6),(_boottime).l
0400A4EC: 23eefffc040b67d4         move.l  var_4(a6),(dword_40B67D4).l
0400A4F4: 601c                     bra.s   loc_400A512
0400A4F6: 2200                     move.l  d0,d1
0400A4F8: 4c3c1400c22e4507         mulu.l  #$C22E4507,d0:d1
0400A500: 4240                     clr.w   d0
0400A502: 4840                     swap    d0
0400A504: 2f00                     move.l  d0,-(sp)
0400A506: 4879040a6199             pea     (aWarningClockLo).l; "WARNING: clock lost %d days"
0400A50C: 61ff00000e4a             bsr.l   _printf
0400A512: 504f                     addq.w  #8,sp
0400A514: 4879040a61b5             pea     (aCheckAndResetT).l; " -- CHECK AND RESET THE DATE!\n"
0400A51A: 61ff00000e3c             bsr.l   _printf
0400A520: 242efff0                 move.l  var_10(a6),d2
0400A524: 246efff4                 movea.l var_C(a6),a2
0400A528: 4e5e                     unlk    a6
0400A52A: 4e75                     rts
