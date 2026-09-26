04007128: 4e56ffb0                 link    a6,#-$50
0400712C: 2f0a                     move.l  a2,-(sp)
0400712E: 222e0008                 move.l  arg_0(a6),d1
04007132: 703f                     moveq   #$3F,d0 ; '?'
04007134: c081                     and.l   d1,d0
04007136: 41f9040b5f04             lea     (_posix_proc_hash).l,a0
0400713C: 20700c00                 movea.l (a0,d0.l*4),a0
04007140: 4a88                     tst.l   a0
04007142: 6710                     beq.s   loc_4007154
04007144: b290                     cmp.l   (a0),d1
04007146: 6604                     bne.s   loc_400714C
04007148: 2008                     move.l  a0,d0
0400714A: 6024                     bra.s   loc_4007170
0400714C: 2068001a                 movea.l $1A(a0),a0
04007150: 4a88                     tst.l   a0
04007152: 66f0                     bne.s   loc_4007144
04007154: 2f01                     move.l  d1,-(sp)
04007156: 4879040a5f8f             pea     (aGetPosixProcNo).l; "get_posix_proc(): no posix proc struct "...
0400715C: 45eeffb0                 lea     var_50(a6),a2
04007160: 2f0a                     move.l  a2,-(sp)
04007162: 61ff000042b8             bsr.l   _sprintf
04007168: 2f0a                     move.l  a2,-(sp)
0400716A: 61ff00004afa             bsr.l   _panic
04007170: 246effac                 movea.l var_54(a6),a2
04007174: 4e5e                     unlk    a6
04007176: 4e75                     rts
