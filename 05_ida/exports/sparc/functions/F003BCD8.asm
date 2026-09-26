F003BCD8: 9de3bf98                 save    %sp, -0x68, %sp
F003BCDC: a2102000                 mov     0, %l1
F003BCE0: aa102000                 mov     0, %l5
F003BCE4: a8102000                 mov     0, %l4
F003BCE8: b4102000                 mov     0, %i2
F003BCEC: ac102000                 mov     0, %l6
F003BCF0: 133c04ea                 sethi   %hi(_svstat), %o1
F003BCF4: d00260d0                 ld      [%o1+%lo(_svstat)], %o0! SVCXPRT *
F003BCF8: a6102000                 mov     0, %l3
F003BCFC: 90022001                 inc     %o0
F003BD00: d02260d0                 st      %o0, [%o1+%lo(_svstat)]
F003BD04: e0062008                 ld      [%i0+8], %l0
F003BD08: 80a42011                 cmp     %l0, 0x11
F003BD0C: 08800009                 bleu    loc_F003BD30
F003BD10: a4102000                 mov     0, %l2
F003BD14: 400022e8                 call    _svcerr_noproc
F003BD18: d006201c                 ld      [%i0+0x1C], %o0
F003BD1C: a4102001                 mov     1, %l2
F003BD20: 213c0433                 sethi   %hi(aNfsServerBadPr), %l0! "nfs_server: bad proc number from %s\n"
F003BD24: d006201c                 ld      [%i0+0x1C], %o0
F003BD28: 10800047                 ba      loc_F003BE44
F003BD2C: a0142048                 bset    %lo(aNfsServerBadPr), %l0! "nfs_server: bad proc number from %s\n"
F003BD30: d0062004                 ld      [%i0+4], %o0
F003BD34: 80a22002                 cmp     %o0, 2
F003BD38: 0280000a                 be      loc_F003BD60
F003BD3C: 92102002                 mov     2, %o1! unsigned __int32
F003BD40: d006201c                 ld      [%i0+0x1C], %o0! SVCXPRT *
F003BD44: 40002327                 call    _svcerr_progvers
F003BD48: 94102002                 mov     2, %o2
F003BD4C: a4102001                 mov     1, %l2
F003BD50: 213c0433                 sethi   %hi(aNfsServerBadVe), %l0! "nfs_server: bad version number from %s"...
F003BD54: d006201c                 ld      [%i0+0x1C], %o0
F003BD58: 1080003b                 ba      loc_F003BE44
F003BD5C: a0142070                 bset    %lo(aNfsServerBadVe), %l0! "nfs_server: bad version number from %s"...
F003BD60: 932c2001                 sll     %l0, 1, %o1
F003BD64: 92024010                 add     %o1, %l0, %o1
F003BD68: 932a6003                 sll     %o1, 3, %o1
F003BD6C: 113c043290122294         set     _rfsdisptab, %o0
F003BD74: 173c04cf                 sethi   %hi(dword_F0133DDC), %o3
F003BD78: a8024008                 add     %o1, %o0, %l4
F003BD7C: d402e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o2
F003BD80: ae12e1dc                 or      %o3, %lo(dword_F0133DDC), %l7
F003BD84: 7fffff99                 call    sub_F003BBE8
F003BD88: c02aa038                 clrb    [%o2+0x38]
F003BD8C: a2100008                 mov     %o0, %l1
F003BD90: 113c0432                 sethi   %hi(_rfssize), %o0! void *
F003BD94: d20221f4                 ld      [%o0+%lo(_rfssize)], %o1! size_t
F003BD98: 40016430                 call    _bzero
F003BD9C: 90100011                 mov     %l1, %o0
F003BDA0: d4066008                 ld      [%i1+8], %o2
F003BDA4: d602a008                 ld      [%o2+8], %o3
F003BDA8: 90100019                 mov     %i1, %o0! SVCXPRT *
F003BDAC: d2052004                 ld      [%l4+4], %o1
F003BDB0: 9fc2c000                 call    %o3
F003BDB4: 94100011                 mov     %l1, %o2
F003BDB8: 80a22000                 cmp     %o0, 0
F003BDBC: 12800009                 bne     loc_F003BDE0
F003BDC0: 80a42000                 cmp     %l0, 0
F003BDC4: 400022cf                 call    _svcerr_decode
F003BDC8: 90100019                 mov     %i1, %o0
F003BDCC: d006201c                 ld      [%i0+0x1C], %o0
F003BDD0: a4102001                 mov     1, %l2
F003BDD4: 213c0433                 sethi   %hi(aNfsServerBadGe), %l0! "nfs_server: bad getargs from %s\n"
F003BDD8: 1080001b                 ba      loc_F003BE44
F003BDDC: a0142098                 bset    %lo(aNfsServerBadGe), %l0! "nfs_server: bad getargs from %s\n"
F003BDE0: 02800020                 be      loc_F003BE60
F003BDE4: 01000000                 nop
F003BDE8: 7fff4efd                 call    _crget
F003BDEC: 01000000                 nop
F003BDF0: ac100008                 mov     %o0, %l6
F003BDF4: d405fffc                 ld      [%l7-4], %o2
F003BDF8: 90100011                 mov     %l1, %o0! SVCXPRT *
F003BDFC: f402a01c                 ld      [%o2+0x1C], %i2
F003BE00: 92046014                 add     %l1, 0x14, %o1
F003BE04: 7ffff955                 call    _findexport
F003BE08: ec22a01c                 st      %l6, [%o2+0x1C]
F003BE0C: a6920000                 orcc    %o0, %g0, %l3
F003BE10: 02800014                 be      loc_F003BE60
F003BE14: 92100018                 mov     %i0, %o1
F003BE18: 400000c0                 call    sub_F003C118
F003BE1C: 94100016                 mov     %l6, %o2
F003BE20: 80a22000                 cmp     %o0, 0
F003BE24: 1280000f                 bne     loc_F003BE60
F003BE28: 01000000                 nop
F003BE2C: 400022d5                 call    _svcerr_weakauth
F003BE30: 90100019                 mov     %i1, %o0
F003BE34: d006201c                 ld      [%i0+0x1C], %o0! in_addr
F003BE38: a4102001                 mov     1, %l2
F003BE3C: 213c0433a01420c0         set     aNfsServerWeakA, %l0! "nfs_server: weak authentication, source"...
F003BE44: 7fffcd54                 call    _inet_ntoa
F003BE48: 90022014                 inc     0x14, %o0! char *
F003BE4C: 92100008                 mov     %o0, %o1
F003BE50: 7fff6202                 call    _printf
F003BE54: 90100010                 mov     %l0, %o0
F003BE58: 10800016                 ba      loc_F003BEB0
F003BE5C: 80a52000                 cmp     %l4, 0
F003BE60: 7fffff62                 call    sub_F003BBE8
F003BE64: 01000000                 nop
F003BE68: aa100008                 mov     %o0, %l5
F003BE6C: 113c0432                 sethi   %hi(_rfssize), %o0! void *
F003BE70: d20221f4                 ld      [%o0+%lo(_rfssize)], %o1! size_t
F003BE74: 400163f9                 call    _bzero
F003BE78: 90100015                 mov     %l5, %o0
F003BE7C: 90100011                 mov     %l1, %o0
F003BE80: 92100015                 mov     %l5, %o1
F003BE84: 193c04ea981320d8         set     unk_F013A8D8, %o4
F003BE8C: 9b2c2002                 sll     %l0, 2, %o5
F003BE90: d603400c                 ld      [%o5+%o4], %o3
F003BE94: 94100013                 mov     %l3, %o2
F003BE98: 9602e001                 inc     %o3
F003BE9C: d623400c                 st      %o3, [%o5+%o4]
F003BEA0: d8050000                 ld      [%l4], %o4
F003BEA4: 9fc30000                 call    %o4
F003BEA8: 96100018                 mov     %i0, %o3
F003BEAC: 80a52000                 cmp     %l4, 0
F003BEB0: 02800015                 be      loc_F003BF04
F003BEB4: 80a46000                 cmp     %l1, 0
F003BEB8: d4066008                 ld      [%i1+8], %o2
F003BEBC: d602a010                 ld      [%o2+0x10], %o3
F003BEC0: 90100019                 mov     %i1, %o0
F003BEC4: d2052004                 ld      [%l4+4], %o1
F003BEC8: 9fc2c000                 call    %o3
F003BECC: 94100011                 mov     %l1, %o2! char *
F003BED0: 80a22000                 cmp     %o0, 0
F003BED4: 1280000c                 bne     loc_F003BF04
F003BED8: 80a46000                 cmp     %l1, 0
F003BEDC: d006201c                 ld      [%i0+0x1C], %o0! in_addr
F003BEE0: a404a001                 inc     %l2
F003BEE4: 213c0433a01420f8         set     aNfsServerBadFr, %l0! "nfs_server: bad freeargs from %s\n"
F003BEEC: 7fffcd2a                 call    _inet_ntoa
F003BEF0: 90022014                 inc     0x14, %o0! char *
F003BEF4: 92100008                 mov     %o0, %o1
F003BEF8: 7fff61d8                 call    _printf
F003BEFC: 90100010                 mov     %l0, %o0
F003BF00: 80a46000                 cmp     %l1, 0
F003BF04: 02800005                 be      loc_F003BF18
F003BF08: 80a4a000                 cmp     %l2, 0
F003BF0C: 7fffff6c                 call    sub_F003BCBC
F003BF10: 90100011                 mov     %l1, %o0
F003BF14: 80a4a000                 cmp     %l2, 0
F003BF18: 12800013                 bne     loc_F003BF64
F003BF1C: 80a56000                 cmp     %l5, 0
F003BF20: 90100019                 mov     %i1, %o0! SVCXPRT *
F003BF24: d205200c                 ld      [%l4+0xC], %o1! xdrproc_t
F003BF28: 4000224f                 call    _svc_sendreply
F003BF2C: 94100015                 mov     %l5, %o2
F003BF30: 80a22000                 cmp     %o0, 0
F003BF34: 1280000c                 bne     loc_F003BF64
F003BF38: 80a56000                 cmp     %l5, 0
F003BF3C: d006201c                 ld      [%i0+0x1C], %o0! in_addr
F003BF40: a4102001                 mov     1, %l2
F003BF44: 213c0433a0142120         set     aNfsServerBadSe, %l0! "nfs_server: bad sendreply from %s\n"
F003BF4C: 7fffcd12                 call    _inet_ntoa
F003BF50: 90022014                 inc     0x14, %o0! char *
F003BF54: 92100008                 mov     %o0, %o1
F003BF58: 7fff61c0                 call    _printf
F003BF5C: 90100010                 mov     %l0, %o0
F003BF60: 80a56000                 cmp     %l5, 0
F003BF64: 0280000d                 be      loc_F003BF98
F003BF68: 80a5a000                 cmp     %l6, 0
F003BF6C: d2052014                 ld      [%l4+0x14], %o1
F003BF70: 113c00ee901223dc         set     sub_F003BBDC, %o0
F003BF78: 80a24008                 cmp     %o1, %o0
F003BF7C: 02800004                 be      loc_F003BF8C
F003BF80: 01000000                 nop
F003BF84: 9fc24000                 call    %o1
F003BF88: 90100015                 mov     %l5, %o0
F003BF8C: 7fffff4c                 call    sub_F003BCBC
F003BF90: 90100015                 mov     %l5, %o0
F003BF94: 80a5a000                 cmp     %l6, 0
F003BF98: 02800006                 be      loc_F003BFB0
F003BF9C: 113c04cf                 sethi   %hi(_active_u), %o0
F003BFA0: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F003BFA4: 90100016                 mov     %l6, %o0
F003BFA8: 7fff4e9c                 call    _crfree
F003BFAC: f422601c                 st      %i2, [%o1+0x1C]
F003BFB0: 133c04ea921260d0         set     _svstat, %o1
F003BFB8: d0026004                 ld      [%o1+4], %o0
F003BFBC: 90020012                 add     %o0, %l2, %o0
F003BFC0: d0226004                 st      %o0, [%o1+4]
F003BFC4: 81c7e008                 ret
F003BFC8: 81e80000                 restore
