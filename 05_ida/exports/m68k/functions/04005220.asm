04005220: 4e56fff0                 link    a6,#-$10
04005224: 48e73030                 movem.l d2-d3/a2-a3,-(sp)
04005228: 4283                     clr.l   d3
0400522A: 45f90400165e             lea     (_copyoutmsg).l,a2
04005230: 47f9040b6070             lea     (_init_exec_args).l,a3
04005236: 08390004040b606f         btst    #4,(byte_40B606F).l
0400523E: 6722                     beq.s   loc_4005262
04005240: 4879040a5e6f             pea     (aInitProgram).l; "init program? "
04005246: 61ff00006110             bsr.l   _printf
0400524C: 4879040ae124             pea     (_init_program_name).l; "/etc/mach_init"
04005252: 4879040ae124             pea     (_init_program_name).l; "/etc/mach_init"
04005258: 61ff0009421c             bsr.l   _gets
0400525E: 504f                     addq.w  #8,sp
04005260: 584f                     addq.w  #4,sp
04005262: 4a83                     tst.l   d3
04005264: 674a                     beq.s   loc_40052B0
04005266: 08390004040b606f         btst    #4,(byte_40B606F).l
0400526E: 6640                     bne.s   loc_40052B0
04005270: 7201                     moveq   #1,d1
04005272: b2b9040ae224             cmp.l   (_init_attempts).l,d1
04005278: 6636                     bne.s   loc_40052B0
0400527A: 4879040ae228             pea     (aEtcInit).l; "/etc/init"
04005280: 2f03                     move.l  d3,-(sp)
04005282: 4879040ae124             pea     (_init_program_name).l; "/etc/mach_init"
04005288: 4879040a5e7e             pea     (aLoadOfSErrnoDT).l; "Load of %s, errno %d, trying %s\n"
0400528E: 61ff000060c8             bsr.l   _printf
04005294: 4283                     clr.l   d3
04005296: 4878000a                 pea     ($A).w
0400529A: 4879040ae124             pea     (_init_program_name).l; "/etc/mach_init"
040052A0: 4879040ae228             pea     (aEtcInit).l; "/etc/init"
040052A6: 61ff0008da84             bsr.l   _bcopy
040052AC: defc001c                 adda.w  #$1C,sp
040052B0: 52b9040ae224             addq.l  #1,(_init_attempts).l
040052B6: 4a83                     tst.l   d3
040052B8: 6726                     beq.s   loc_40052E0
040052BA: 2f03                     move.l  d3,-(sp)
040052BC: 4879040ae124             pea     (_init_program_name).l; "/etc/mach_init"
040052C2: 4879040a5e9f             pea     (aLoadOfSFailedE).l; "Load of %s failed, errno %d\n"
040052C8: 61ff0000608e             bsr.l   _printf
040052CE: 4283                     clr.l   d3
040052D0: 7210                     moveq   #$10,d1
040052D2: 83b9040b606c             or.l    d1,(_boothowto).l
040052D8: 504f                     addq.w  #8,sp
040052DA: 584f                     addq.w  #4,sp
040052DC: 600000cc                 bra.w   loc_40053AA
040052E0: 42aefff0                 clr.l   var_10(a6)
040052E4: 48780001                 pea     (1).w
040052E8: 2f39040b06d0             move.l  (_page_size).l,-(sp)
040052EE: 486efff0                 pea     var_10(a6)
040052F2: 2079040b5648             movea.l (_active_threads).l,a0
040052F8: 2068000c                 movea.l $C(a0),a0
040052FC: 2f280008                 move.l  8(a0),-(sp)
04005300: 61ff0005d11a             bsr.l   _vm_allocate
04005306: 504f                     addq.w  #8,sp
04005308: 504f                     addq.w  #8,sp
0400530A: 4aaefff0                 tst.l   var_10(a6)
0400530E: 6606                     bne.s   loc_4005316
04005310: 7201                     moveq   #1,d1
04005312: 2d41fff0                 move.l  d1,var_10(a6)
04005316: 48780081                 pea     ($81).w
0400531A: 2f2efff0                 move.l  var_10(a6),-(sp)
0400531E: 4879040ae124             pea     (_init_program_name).l; "/etc/mach_init"
04005324: 4e92                     jsr     (a2)
04005326: 2d6efff0fff4             move.l  var_10(a6),var_C(a6)
0400532C: 202efff0                 move.l  var_10(a6),d0
04005330: 06800000008f             addi.l  #$8F,d0
04005336: 72f0                     moveq   #$FFFFFFF0,d1
04005338: c081                     and.l   d1,d0
0400533A: 2d40fff0                 move.l  d0,var_10(a6)
0400533E: 48780080                 pea     ($80).w
04005342: 2f00                     move.l  d0,-(sp)
04005344: 4879040ae1a4             pea     (_init_args).l; "-xx"
0400534A: 4e92                     jsr     (a2)
0400534C: 2d6efff0fff8             move.l  var_10(a6),var_8(a6)
04005352: 202efff0                 move.l  var_10(a6),d0
04005356: 06800000008f             addi.l  #$8F,d0
0400535C: 72f0                     moveq   #$FFFFFFF0,d1
0400535E: c081                     and.l   d1,d0
04005360: 2d40fff0                 move.l  d0,var_10(a6)
04005364: 42aefffc                 clr.l   var_4(a6)
04005368: 4878000c                 pea     ($C).w
0400536C: 2f00                     move.l  d0,-(sp)
0400536E: 486efff4                 pea     var_C(a6)
04005372: 4e92                     jsr     (a2)
04005374: 26aefff4                 move.l  var_C(a6),(a3)
04005378: 23eefff0040b6074         move.l  var_10(a6),(dword_40B6074).l
04005380: 42b9040b6078             clr.l   (dword_40B6078).l
04005386: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400538C: 24280024                 move.l  $24(a0),d2
04005390: 214b0024                 move.l  a3,$24(a0)
04005394: defc0024                 adda.w  #$24,sp ; '$'
04005398: 61fffffff562             bsr.l   _execve
0400539E: 2600                     move.l  d0,d3
040053A0: 2079040b57d4             movea.l (dword_40B57D4).l,a0
040053A6: 21420024                 move.l  d2,$24(a0)
040053AA: 4a83                     tst.l   d3
040053AC: 6600fe88                 bne.w   loc_4005236
040053B0: 4cee0c0cffe0             movem.l var_20(a6),d2-d3/a2-a3
040053B6: 4e5e                     unlk    a6
040053B8: 4e75                     rts
