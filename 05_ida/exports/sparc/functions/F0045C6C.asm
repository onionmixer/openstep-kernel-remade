F0045C6C: 9de3bf98                 save    %sp, -0x68, %sp
F0045C70: a0100018                 mov     %i0, %l0
F0045C74: d0042014                 ld      [%l0+0x14], %o0
F0045C78: 90023ffc                 inc     -4, %o0
F0045C7C: 80a22000                 cmp     %o0, 0
F0045C80: 16800015                 bge     loc_F0045CD4
F0045C84: d0242014                 st      %o0, [%l0+0x14]
F0045C88: 80a23ffc                 cmp     %o0, -4
F0045C8C: 02800004                 be      loc_F0045C9C
F0045C90: 113c0438                 sethi   %hi(aXdrMbufLongCro), %o0! "xdr_mbuf: long crosses mbufs!\n"
F0045C94: 7fff3a71                 call    _printf
F0045C98: 901220d0                 bset    %lo(aXdrMbufLongCro), %o0! "xdr_mbuf: long crosses mbufs!\n"
F0045C9C: d0042010                 ld      [%l0+0x10], %o0
F0045CA0: 80a22000                 cmp     %o0, 0
F0045CA4: 0280001c                 be      locret_F0045D14
F0045CA8: b0102000                 mov     0, %i0
F0045CAC: d2020000                 ld      [%o0], %o1
F0045CB0: 80a26000                 cmp     %o1, 0
F0045CB4: 02800018                 be      locret_F0045D14
F0045CB8: d2242010                 st      %o1, [%l0+0x10]
F0045CBC: d0026004                 ld      [%o1+4], %o0
F0045CC0: 90024008                 add     %o1, %o0, %o0
F0045CC4: d024200c                 st      %o0, [%l0+0xC]
F0045CC8: d0526008                 ldsh    [%o1+8], %o0
F0045CCC: 90023ffc                 inc     -4, %o0
F0045CD0: d0242014                 st      %o0, [%l0+0x14]
F0045CD4: d004200c                 ld      [%l0+0xC], %o0
F0045CD8: 808a2003                 btst    3, %o0
F0045CDC: 12800005                 bne     loc_F0045CF0
F0045CE0: 92100019                 mov     %i1, %o1! void *
F0045CE4: 808e6003                 btst    3, %i1
F0045CE8: 22800006                 be,a    loc_F0045D00
F0045CEC: d0020000                 ld      [%o0], %o0! void *
F0045CF0: 40013b88                 call    _bcopy
F0045CF4: 94102004                 mov     4, %o2
F0045CF8: 10800004                 ba      loc_F0045D08
F0045CFC: d004200c                 ld      [%l0+0xC], %o0
F0045D00: d0264000                 st      %o0, [%i1]
F0045D04: d004200c                 ld      [%l0+0xC], %o0
F0045D08: b0102001                 mov     1, %i0
F0045D0C: 90022004                 inc     4, %o0
F0045D10: d024200c                 st      %o0, [%l0+0xC]
F0045D14: 81c7e008                 ret
F0045D18: 81e80000                 restore
