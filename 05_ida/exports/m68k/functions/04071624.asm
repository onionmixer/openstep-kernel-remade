04071624: 4e56ff00                 link    a6,#-$100
04071628: 2f0a                     move.l  a2,-(sp)
0407162A: 45f9040b6904             lea     (unk_40B6904).l,a2
04071630: 3012                     move.w  (a2),d0
04071632: 08000005                 btst    #5,d0
04071636: 6706                     beq.s   loc_407163E
04071638: 61ff000000ca             bsr.l   _alert_done
0407163E: 0cb9040b67fc040b6a68     cmpi.l  #$40B67FC,(_cons_tp).l
04071648: 6608                     bne.s   loc_4071652
0407164A: 3012                     move.w  (a2),d0
0407164C: 08000003                 btst    #3,d0
04071650: 6630                     bne.s   loc_4071682
04071652: 48780001                 pea     (1).w
04071656: 61ff000000fc             bsr.l   _alert_lock_screen
0407165C: 48780001                 pea     (1).w
04071660: 2f2e000c                 move.l  arg_4(a6),-(sp)
04071664: 2f2e0008                 move.l  arg_0(a6),-(sp)
04071668: 48780001                 pea     (1).w
0407166C: 2f2e0010                 move.l  arg_8(a6),-(sp)
04071670: 61ffffffe044             bsr.l   _kmpopup
04071676: 5279040b6938             addq.w  #1,(word_40B6938).l
0407167C: defc0018                 adda.w  #$18,sp
04071680: 600e                     bra.s   loc_4071690
04071682: 41f9040b6938             lea     (word_40B6938).l,a0
04071688: 3010                     move.w  (a0),d0
0407168A: 6704                     beq.s   loc_4071690
0407168C: 5240                     addq.w  #1,d0
0407168E: 3080                     move.w  d0,(a0)
04071690: 41f9040b6904             lea     (unk_40B6904).l,a0
04071696: 3010                     move.w  (a0),d0
04071698: 00400020                 ori.w   #$20,d0 ; ' '
0407169C: 3080                     move.w  d0,(a0)
0407169E: 42b9040b67f4             clr.l   (_alert_key).l
040716A4: 3010                     move.w  (a0),d0
040716A6: 00400100                 ori.w   #$100,d0
040716AA: 3080                     move.w  d0,(a0)
040716AC: 1d79040aa60cff00         move.b  (aL).l,var_100(a6); "%L"
040716B4: 1d79040aa60dff01         move.b  (aL+1).l,var_FF(a6); "L"
040716BC: 1d79040aa60eff02         move.b  (aL+2).l,var_FE(a6); ""
040716C4: 2f2e0014                 move.l  arg_C(a6),-(sp)
040716C8: 45eeff00                 lea     var_100(a6),a2
040716CC: 2f0a                     move.l  a2,-(sp)
040716CE: 61ff0002198c             bsr.l   _strcat
040716D4: 2f2e0034                 move.l  arg_2C(a6),-(sp)
040716D8: 2f2e0030                 move.l  arg_28(a6),-(sp)
040716DC: 2f2e002c                 move.l  arg_24(a6),-(sp)
040716E0: 2f2e0028                 move.l  arg_20(a6),-(sp)
040716E4: 2f2e0024                 move.l  arg_1C(a6),-(sp)
040716E8: 2f2e0020                 move.l  arg_18(a6),-(sp)
040716EC: 2f2e001c                 move.l  arg_14(a6),-(sp)
040716F0: 2f2e0018                 move.l  arg_10(a6),-(sp)
040716F4: 2f0a                     move.l  a2,-(sp)
040716F6: 61fffff99c60             bsr.l   _printf
040716FC: 246efefc                 movea.l var_104(a6),a2
04071700: 4e5e                     unlk    a6
04071702: 4e75                     rts
