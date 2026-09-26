04005AC6: 4e56fffc                 link    a6,#-4
04005ACA: 487904005ac6             pea     (_wait).l
04005AD0: 42a7                     clr.l   -(sp)
04005AD2: 486efffc                 pea     var_4(a6)
04005AD6: 42a7                     clr.l   -(sp)
04005AD8: 42a7                     clr.l   -(sp)
04005ADA: 61ff00000090             bsr.l   _wait1
04005AE0: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04005AE6: 216efffc0060             move.l  var_4(a6),$60(a0)
04005AEC: 2f00                     move.l  d0,-(sp)
04005AEE: 61ff00094726             bsr.l   _unix_syscall_return
04005AF4: 4e5e                     unlk    a6
04005AF6: 4e75                     rts
