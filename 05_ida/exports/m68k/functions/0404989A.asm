0404989A: 4856                     pea     (a6)
0404989C: 2c4f                     movea.l sp,a6
0404989E: 206e0008                 movea.l 8(a6),a0
040498A2: 226800a8                 movea.l $A8(a0),a1
040498A6: b3e800a4                 cmpa.l  $A4(a0),a1
040498AA: 6608                     bne.s   loc_40498B4
040498AC: 5291                     addq.l  #1,(a1)
040498AE: 52a90018                 addq.l  #1,$18(a1)
040498B2: 600a                     bra.s   loc_40498BE
040498B4: 2f09                     move.l  a1,-(sp)
040498B6: 61ffffff7946             bsr.l   _ipc_port_copy_send
040498BC: 2240                     movea.l d0,a1
040498BE: 2009                     move.l  a1,d0
040498C0: 4e5e                     unlk    a6
040498C2: 4e75                     rts
