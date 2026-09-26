0406DB14: 4856                     pea     (a6)
0406DB16: 2c4f                     movea.l sp,a6
0406DB18: 206e0008                 movea.l 8(a6),a0
0406DB1C: 4ab9040b1298             tst.l   (_fd_polling_mode).l
0406DB22: 6638                     bne.s   loc_406DB5C
0406DB24: 2f2e000c                 move.l  $C(a6),-(sp)
0406DB28: 4879040b13f6             pea     (_fd_return_values).l
0406DB2E: 2f28009e                 move.l  $9E(a0),-(sp)
0406DB32: 203c040aa47e             move.l  #$40AA47E,d0
0406DB38: 08280000015f             btst    #0,$15F(a0)
0406DB3E: 6706                     beq.s   loc_406DB46
0406DB40: 203c040aa479             move.l  #$40AA479,d0
0406DB46: 2f00                     move.l  d0,-(sp)
0406DB48: 2f28013c                 move.l  $13C(a0),-(sp)
0406DB4C: 2f280010                 move.l  $10(a0),-(sp)
0406DB50: 4879040aa484             pea     (aFdDSectorDDCmd).l; "fd%d: Sector %d(d) cmd = %s; %n: %s\n"
0406DB56: 61fffff9d800             bsr.l   _printf
0406DB5C: 4e5e                     unlk    a6
0406DB5E: 4e75                     rts
