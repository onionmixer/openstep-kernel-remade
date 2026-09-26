04080404: 4856                     pea     (a6)
04080406: 2c4f                     movea.l sp,a6
04080408: 2f0b                     move.l  a3,-(sp)
0408040A: 2f0a                     move.l  a2,-(sp)
0408040C: 4879040abb3a             pea     (aSounddspSndDev).l; "SoundDSP: snd_dev_intr called!\n"
04080412: 61fffff8af44             bsr.l   _printf
04080418: 4878ff7f                 pea     ($FFFFFF7F).w
0408041C: 47f90407254a             lea     (_mon_csr_and).l,a3
04080422: 4e93                     jsr     (a3)
04080424: 48780020                 pea     ($20).w
04080428: 45f904072596             lea     (_mon_csr_or).l,a2
0408042E: 4e92                     jsr     (a2)
04080430: 4878fff7                 pea     ($FFFFFFF7).w
04080434: 4e93                     jsr     (a3)
04080436: 48780002                 pea     (2).w
0408043A: 4e92                     jsr     (a2)
0408043C: 42a7                     clr.l   -(sp)
0408043E: 48780003                 pea     (3).w
04080442: 45f9040724a4             lea     (_mon_send).l,a2
04080448: 4e92                     jsr     (a2)
0408044A: 42a7                     clr.l   -(sp)
0408044C: 48780007                 pea     (7).w
04080450: 4e92                     jsr     (a2)
04080452: defc0020                 adda.w  #$20,sp ; ' '
04080456: 2ebc000000ff             move.l  #$FF,(sp)
0408045C: 487800c4                 pea     ($C4).w
04080460: 4e92                     jsr     (a2)
04080462: 246efff8                 movea.l -8(a6),a2
04080466: 266efffc                 movea.l -4(a6),a3
0408046A: 4e5e                     unlk    a6
0408046C: 4e75                     rts
