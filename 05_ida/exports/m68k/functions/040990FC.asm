040990FC: 4856                     pea     (a6)
040990FE: 2c4f                     movea.l sp,a6
04099100: 2f03                     move.l  d3,-(sp)
04099102: 2f02                     move.l  d2,-(sp)
04099104: 242e000c                 move.l  $C(a6),d2
04099108: 08020010                 btst    #$10,d2
0409910C: 6706                     beq.s   loc_4099114
0409910E: 61ffffff81f8             bsr.l   _rtc_power_down
04099114: 40c0                     move    sr,d0
04099116: 46fc2700                 move    #$2700,sr
0409911A: 3600                     move.w  d0,d3
0409911C: 48c3                     ext.l   d3
0409911E: 08020003                 btst    #3,d2
04099122: 671a                     beq.s   loc_409913E
04099124: 4879040ac996             pea     (aHalting).l; "halting...\n\n"
0409912A: 61fffff7222c             bsr.l   _printf
04099130: 4879040ac6e6             pea     (aH).l; "-h"
04099136: 61ffffffa62a             bsr.l   _mon_call
0409913C: 6036                     bra.s   loc_4099174
0409913E: 4879040ac9a3             pea     (aRebootingMach).l; "rebooting Mach...\n\n"
04099144: 61fffff72212             bsr.l   _printf
0409914A: 584f                     addq.w  #4,sp
0409914C: 08020014                 btst    #$14,d2
04099150: 670c                     beq.s   loc_409915E
04099152: 2f2e0010                 move.l  $10(a6),-(sp)
04099156: 61ffffffa60a             bsr.l   _mon_call
0409915C: 6016                     bra.s   loc_4099174
0409915E: 4280                     clr.l   d0
04099160: 08020001                 btst    #1,d2
04099164: 6706                     beq.s   loc_409916C
04099166: 203c040ac9b7             move.l  #$40AC9B7,d0
0409916C: 2f00                     move.l  d0,-(sp)
0409916E: 61ffffffa534             bsr.l   _mon_boot
04099174: 40c0                     move    sr,d0
04099176: 46c3                     move    d3,sr
04099178: 242efff8                 move.l  -8(a6),d2
0409917C: 262efffc                 move.l  -4(a6),d3
04099180: 4e5e                     unlk    a6
04099182: 4e75                     rts
