F00EFBE4: 9de3bf98                 save    %sp, -0x68, %sp
F00EFBE8: 80a66000                 cmp     %i1, 0
F00EFBEC: 1280000f                 bne     loc_F00EFC28
F00EFBF0: 98100018                 mov     %i0, %o4
F00EFBF4: 10800043                 ba      locret_F00EFD00
F00EFBF8: b0102000                 mov     0, %i0
F00EFBFC: 113c03c6901222b0         set     __objc_msgForward, %o0
F00EFC04: f002a008                 ld      [%o2+8], %i0
F00EFC08: b01e0008                 btog    %o0, %i0
F00EFC0C: 80a00018                 cmp     %g0, %i0
F00EFC10: 1080003c                 ba      locret_F00EFD00
F00EFC14: b0402000                 addc    %g0, 0, %i0
F00EFC18: 40000133                 call    sub_F00F00E4
F00EFC1C: 90100018                 mov     %i0, %o0
F00EFC20: 10800038                 ba      locret_F00EFD00
F00EFC24: b0102001                 mov     1, %i0
F00EFC28: d0032020                 ld      [%o4+0x20], %o0
F00EFC2C: d6020000                 ld      [%o0], %o3
F00EFC30: 9a022008                 add     %o0, 8, %o5
F00EFC34: 920e400b                 and     %i1, %o3, %o1
F00EFC38: 912a6002                 sll     %o1, 2, %o0
F00EFC3C: d4034008                 ld      [%o5+%o0], %o2
F00EFC40: 80a2a000                 cmp     %o2, 0
F00EFC44: 22800008                 be,a    loc_F00EFC64
F00EFC48: d603201c                 ld      [%o4+0x1C], %o3
F00EFC4C: d0028000                 ld      [%o2], %o0
F00EFC50: 80a20019                 cmp     %o0, %i1
F00EFC54: 02bfffea                 be      loc_F00EFBFC
F00EFC58: 92026001                 inc     %o1
F00EFC5C: 10bffff7                 ba      loc_F00EFC38
F00EFC60: 920a400b                 and     %o1, %o3, %o1
F00EFC64: 80a2e000                 cmp     %o3, 0
F00EFC68: 22800011                 be,a    loc_F00EFCAC
F00EFC6C: d8032004                 ld      [%o4+4], %o4
F00EFC70: d402e004                 ld      [%o3+4], %o2
F00EFC74: 9482bfff                 inccc   -1, %o2
F00EFC78: 0c800008                 bneg    loc_F00EFC98
F00EFC7C: 9202e008                 add     %o3, 8, %o1
F00EFC80: d0024000                 ld      [%o1], %o0
F00EFC84: 80a64008                 cmp     %i1, %o0
F00EFC88: 02bfffe4                 be      loc_F00EFC18
F00EFC8C: 9482bfff                 inccc   -1, %o2
F00EFC90: 1cbffffc                 bpos    loc_F00EFC80
F00EFC94: 9202600c                 inc     0xC, %o1
F00EFC98: d602c000                 ld      [%o3], %o3
F00EFC9C: 80a2e000                 cmp     %o3, 0
F00EFCA0: 32bffff5                 bne,a   loc_F00EFC74
F00EFCA4: d402e004                 ld      [%o3+4], %o2
F00EFCA8: d8032004                 ld      [%o4+4], %o4
F00EFCAC: 80a32000                 cmp     %o4, 0
F00EFCB0: 32bfffed                 bne,a   loc_F00EFC64
F00EFCB4: d603201c                 ld      [%o4+0x1C], %o3
F00EFCB8: 400003a5                 call    _NXDefaultMallocZone
F00EFCBC: 01000000                 nop
F00EFCC0: 400003a3                 call    _NXDefaultMallocZone
F00EFCC4: a0100008                 mov     %o0, %l0
F00EFCC8: d4042004                 ld      [%l0+4], %o2
F00EFCCC: 9fc28000                 call    %o2
F00EFCD0: 9210200c                 mov     0xC, %o1
F00EFCD4: 92100008                 mov     %o0, %o1
F00EFCD8: f2224000                 st      %i1, [%o1]
F00EFCDC: 113c03e990122128         set     asc_F00FA528, %o0! ""
F00EFCE4: d0226004                 st      %o0, [%o1+4]
F00EFCE8: 113c03c6901222b0         set     __objc_msgForward, %o0
F00EFCF0: d0226008                 st      %o0, [%o1+8]
F00EFCF4: 400000fc                 call    sub_F00F00E4
F00EFCF8: 90100018                 mov     %i0, %o0
F00EFCFC: b0102000                 mov     0, %i0
F00EFD00: 81c7e008                 ret
F00EFD04: 81e80000                 restore
