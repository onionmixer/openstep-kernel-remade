F0024A68: 9de3bf98                 save    %sp, -0x68, %sp
F0024A6C: a4960000                 orcc    %i0, %g0, %l2
F0024A70: 1280000c                 bne     loc_F0024AA0
F0024A74: 80a66000                 cmp     %i1, 0
F0024A78: 113c042f90122310         set     aVp0xXBlkno0xXS, %o0! "vp=0x%x, blkno=0x%x, size=0x%x\n"
F0024A80: 92102000                 mov     0, %o1
F0024A84: 94100019                 mov     %i1, %o2
F0024A88: 7fffbef4                 call    _printf
F0024A8C: 9610001a                 mov     %i2, %o3
F0024A90: 113c042f                 sethi   %hi(aGetblkIllegalV), %o0! "getblk: Illegal vnode pointer"
F0024A94: 7fffc1b7                 call    _panic
F0024A98: 90122330                 bset    %lo(aGetblkIllegalV), %o0! "getblk: Illegal vnode pointer"
F0024A9C: 80a66000                 cmp     %i1, 0
F0024AA0: 16800003                 bge     loc_F0024AAC
F0024AA4: 90100019                 mov     %i1, %o0
F0024AA8: 90066007                 add     %i1, 7, %o0
F0024AAC: 913a2003                 sra     %o0, 3, %o0
F0024AB0: 90048008                 add     %l2, %o0, %o0
F0024AB4: 900a200f                 and     %o0, 0xF, %o0
F0024AB8: 932a2001                 sll     %o0, 1, %o1
F0024ABC: 92024008                 add     %o1, %o0, %o1
F0024AC0: 932a6002                 sll     %o1, 2, %o1
F0024AC4: 113c04cf90122300         set     _bufhash, %o0
F0024ACC: a2024008                 add     %o1, %o0, %l1
F0024AD0: f0046004                 ld      [%l1+4], %i0
F0024AD4: 80a60011                 cmp     %i0, %l1
F0024AD8: 0280003c                 be      loc_F0024BC8
F0024ADC: 13000040                 sethi   0x10000, %o1
F0024AE0: d0062024                 ld      [%i0+0x24], %o0
F0024AE4: 80a20019                 cmp     %o0, %i1
F0024AE8: 32800035                 bne,a   loc_F0024BBC
F0024AEC: f0062004                 ld      [%i0+4], %i0
F0024AF0: d0062040                 ld      [%i0+0x40], %o0
F0024AF4: 80a20012                 cmp     %o0, %l2
F0024AF8: 32800031                 bne,a   loc_F0024BBC
F0024AFC: f0062004                 ld      [%i0+4], %i0
F0024B00: d0060000                 ld      [%i0], %o0
F0024B04: 808a0009                 btst    %o1, %o0
F0024B08: 3280002d                 bne,a   loc_F0024BBC
F0024B0C: f0062004                 ld      [%i0+4], %i0
F0024B10: 4001c81e                 call    _splusclock
F0024B14: 01000000                 nop
F0024B18: d2060000                 ld      [%i0], %o1
F0024B1C: 808a6008                 btst    8, %o1
F0024B20: 0280000b                 be      loc_F0024B4C
F0024B24: a0100008                 mov     %o0, %l0
F0024B28: 90126040                 or      %o1, 0x40, %o0
F0024B2C: d0260000                 st      %o0, [%i0]
F0024B30: 90100018                 mov     %i0, %o0! unsigned int
F0024B34: 7fffb6d1                 call    _sleep
F0024B38: 92102015                 mov     0x15, %o1
F0024B3C: 4001c87a                 call    _splx
F0024B40: 90100010                 mov     %l0, %o0
F0024B44: 10bfffe4                 ba      loc_F0024AD4
F0024B48: f0046004                 ld      [%l1+4], %i0
F0024B4C: 4001c876                 call    _splx
F0024B50: 90100010                 mov     %l0, %o0
F0024B54: 4001c819                 call    _spltty
F0024B58: 01000000                 nop
F0024B5C: d4062010                 ld      [%i0+0x10], %o2
F0024B60: d206200c                 ld      [%i0+0xC], %o1
F0024B64: d222a00c                 st      %o1, [%o2+0xC]
F0024B68: d406200c                 ld      [%i0+0xC], %o2
F0024B6C: d2062010                 ld      [%i0+0x10], %o1
F0024B70: d222a010                 st      %o1, [%o2+0x10]
F0024B74: d2060000                 ld      [%i0], %o1
F0024B78: 92126008                 bset    8, %o1
F0024B7C: 4001c86a                 call    _splx
F0024B80: d2260000                 st      %o1, [%i0]
F0024B84: d0062014                 ld      [%i0+0x14], %o0
F0024B88: 80a2001a                 cmp     %o0, %i2
F0024B8C: 02800007                 be      loc_F0024BA8
F0024B90: 90100018                 mov     %i0, %o0
F0024B94: 40000056                 call    _brealloc
F0024B98: 9210001a                 mov     %i2, %o1
F0024B9C: 80a22000                 cmp     %o0, 0
F0024BA0: 22bfffcd                 be,a    loc_F0024AD4
F0024BA4: f0046004                 ld      [%l1+4], %i0
F0024BA8: d0060000                 ld      [%i0], %o0
F0024BAC: 13000020                 sethi   0x8000, %o1
F0024BB0: 90120009                 bset    %o1, %o0
F0024BB4: 10800023                 ba      locret_F0024C40
F0024BB8: d0260000                 st      %o0, [%i0]
F0024BBC: 80a60011                 cmp     %i0, %l1
F0024BC0: 32bfffc9                 bne,a   loc_F0024AE4
F0024BC4: d0062024                 ld      [%i0+0x24], %o0
F0024BC8: 400000d5                 call    _getnewbuf
F0024BCC: 01000000                 nop
F0024BD0: 40021629                 call    _bfree
F0024BD4: b0100008                 mov     %o0, %i0
F0024BD8: d2062008                 ld      [%i0+8], %o1
F0024BDC: d0062004                 ld      [%i0+4], %o0
F0024BE0: d0226004                 st      %o0, [%o1+4]
F0024BE4: d6062004                 ld      [%i0+4], %o3
F0024BE8: 90100018                 mov     %i0, %o0
F0024BEC: d4062008                 ld      [%i0+8], %o2
F0024BF0: 92100012                 mov     %l2, %o1
F0024BF4: 4000029a                 call    sub_F002565C
F0024BF8: d422e008                 st      %o2, [%o3+8]
F0024BFC: d014a02c                 lduh    [%l2+0x2C], %o0
F0024C00: d036201e                 sth     %o0, [%i0+0x1E]
F0024C04: f2262024                 st      %i1, [%i0+0x24]
F0024C08: c036201c                 clrh    [%i0+0x1C]
F0024C0C: c0262028                 clr     [%i0+0x28]
F0024C10: d2046004                 ld      [%l1+4], %o1
F0024C14: 90100018                 mov     %i0, %o0
F0024C18: d2262004                 st      %o1, [%i0+4]
F0024C1C: e2262008                 st      %l1, [%i0+8]
F0024C20: d4046004                 ld      [%l1+4], %o2
F0024C24: 9210001a                 mov     %i2, %o1
F0024C28: f022a008                 st      %i0, [%o2+8]
F0024C2C: 40000030                 call    _brealloc
F0024C30: f0246004                 st      %i0, [%l1+4]
F0024C34: 80a22000                 cmp     %o0, 0
F0024C38: 22bfffa7                 be,a    loc_F0024AD4
F0024C3C: f0046004                 ld      [%l1+4], %i0
F0024C40: 81c7e008                 ret
F0024C44: 81e80000                 restore
