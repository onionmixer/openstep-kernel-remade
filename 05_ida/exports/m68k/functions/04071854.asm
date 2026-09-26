04071854: 4856                     pea     (a6)
04071856: 2c4f                     movea.l sp,a6
04071858: 2f02                     move.l  d2,-(sp)
0407185A: 41f9040b6904             lea     (unk_40B6904).l,a0
04071860: 3010                     move.w  (a0),d0
04071862: 08000003                 btst    #3,d0
04071866: 6764                     beq.s   loc_40718CC
04071868: 4879040aa60f             pea     (aReallyPowerOff).l; "\nReally power off?  Type y to power of"...
0407186E: 61fffff99ae8             bsr.l   _printf
04071874: 584f                     addq.w  #4,sp
04071876: 61ffffffed04             bsr.l   _kmtrygetc
0407187C: 72ff                     moveq   #$FFFFFFFF,d1
0407187E: b280                     cmp.l   d0,d1
04071880: 67f4                     beq.s   loc_4071876
04071882: 7279                     moveq   #$79,d1 ; 'y'
04071884: b280                     cmp.l   d0,d1
04071886: 6736                     beq.s   loc_40718BE
04071888: 7404                     moveq   #4,d2
0407188A: 2079040b56d4             movea.l (_intrstat).l,a0
04071890: 2010                     move.l  (a0),d0
04071892: 08000002                 btst    #2,d0
04071896: 6712                     beq.s   loc_40718AA
04071898: 61ff0001f8a8             bsr.l   _rtc_intr
0407189E: 2079040b56d4             movea.l (_intrstat).l,a0
040718A4: 2010                     move.l  (a0),d0
040718A6: c082                     and.l   d2,d0
040718A8: 66ee                     bne.s   loc_4071898
040718AA: 2079040c32ec             movea.l (_intrmask).l,a0
040718B0: 2010                     move.l  (a0),d0
040718B2: 8082                     or.l    d2,d0
040718B4: 2080                     move.l  d0,(a0)
040718B6: 85b9040b56d0             or.l    d2,(_intr_mask).l
040718BC: 602e                     bra.s   loc_40718EC
040718BE: 4879040aa64b             pea     (aShutDownInProg).l; "Shut down in progress.\n"
040718C4: 61fffff99a92             bsr.l   _printf
040718CA: 584f                     addq.w  #4,sp
040718CC: 7201                     moveq   #1,d1
040718CE: 23c1040b124a             move.l  d1,(_force_power_down).l
040718D4: 61ff000182b2             bsr.l   _vidStopAnimation
040718DA: 61ff000182da             bsr.l   _vidSuspendAnimation
040718E0: 2f3c00090000             move.l  #$90000,-(sp)
040718E6: 61ff00021efe             bsr.l   _reboot_mach
040718EC: 242efffc                 move.l  -4(a6),d2
040718F0: 4e5e                     unlk    a6
040718F2: 4e75                     rts
