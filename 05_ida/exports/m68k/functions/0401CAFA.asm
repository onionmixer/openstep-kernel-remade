0401CAFA: 4e56fff8                 link    a6,#-8
0401CAFE: 2f0a                     move.l  a2,-(sp)
0401CB00: 222e0008                 move.l  arg_0(a6),d1
0401CB04: 202e000c                 move.l  arg_4(a6),d0
0401CB08: 226e0010                 movea.l arg_8(a6),a1
0401CB0C: 2041                     movea.l d1,a0
0401CB0E: 24680036                 movea.l $36(a0),a2
0401CB12: 4a8a                     tst.l   a2
0401CB14: 6606                     bne.s   loc_401CB1C
0401CB16: 7006                     moveq   #6,d0
0401CB18: 600000a2                 bra.w   loc_401CBBC
0401CB1C: 0c8080206931             cmpi.l  #$80206931,d0
0401CB22: 675e                     beq.s   loc_401CB82
0401CB24: 6212                     bhi.s   loc_401CB38
0401CB26: 0c808020690c             cmpi.l  #$8020690C,d0
0401CB2C: 6732                     beq.s   loc_401CB60
0401CB2E: 0c8080206910             cmpi.l  #$80206910,d0
0401CB34: 6740                     beq.s   loc_401CB76
0401CB36: 606a                     bra.s   loc_401CBA2
0401CB38: 0c80c020690d             cmpi.l  #$C020690D,d0
0401CB3E: 672a                     beq.s   loc_401CB6A
0401CB40: 620a                     bhi.s   loc_401CB4C
0401CB42: 0c8080206932             cmpi.l  #$80206932,d0
0401CB48: 674a                     beq.s   loc_401CB94
0401CB4A: 6056                     bra.s   loc_401CBA2
0401CB4C: 0c80c0206921             cmpi.l  #$C0206921,d0
0401CB52: 664e                     bne.s   loc_401CBA2
0401CB54: 48690010                 pea     $10(a1)
0401CB58: 4879040acf87             pea     (_IFCONTROL_AUTOADDR).l; "autoaddr"
0401CB5E: 603c                     bra.s   loc_401CB9C
0401CB60: 2f09                     move.l  a1,-(sp)
0401CB62: 4879040acf77             pea     (_IFCONTROL_SETADDR).l; "setaddr"
0401CB68: 6032                     bra.s   loc_401CB9C
0401CB6A: 48690010                 pea     $10(a1)
0401CB6E: 4879040acf7f             pea     (_IFCONTROL_GETADDR).l; "getaddr"
0401CB74: 6026                     bra.s   loc_401CB9C
0401CB76: 48690010                 pea     $10(a1)
0401CB7A: 4879040acf6e             pea     (_IFCONTROL_SETFLAGS).l; "setflags"
0401CB80: 601a                     bra.s   loc_401CB9C
0401CB82: 2f09                     move.l  a1,-(sp)
0401CB84: 4879040acfba             pea     (_IFCONTROL_ADDMULTICAST).l; "add-multicast"
0401CB8A: 2f08                     move.l  a0,-(sp)
0401CB8C: 61ffffffff48             bsr.l   _if_control
0401CB92: 6028                     bra.s   loc_401CBBC
0401CB94: 2f09                     move.l  a1,-(sp)
0401CB96: 4879040acfc8             pea     (_IFCONTROL_RMVMULTICAST).l; "rmv-multicast"
0401CB9C: 2f08                     move.l  a0,-(sp)
0401CB9E: 4e92                     jsr     (a2)
0401CBA0: 601a                     bra.s   loc_401CBBC
0401CBA2: 2d40fff8                 move.l  d0,var_8(a6)
0401CBA6: 2d49fffc                 move.l  a1,var_4(a6)
0401CBAA: 486efff8                 pea     var_8(a6)
0401CBAE: 4879040acf90             pea     (_IFCONTROL_UNIXIOCTL).l; "unix-ioctl"
0401CBB4: 2f01                     move.l  d1,-(sp)
0401CBB6: 20680036                 movea.l $36(a0),a0
0401CBBA: 4e90                     jsr     (a0)
0401CBBC: 246efff4                 movea.l var_C(a6),a2
0401CBC0: 4e5e                     unlk    a6
0401CBC2: 4e75                     rts
