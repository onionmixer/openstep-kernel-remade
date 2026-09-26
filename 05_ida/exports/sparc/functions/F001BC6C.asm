F001BC6C: 9de3bf98                 save    %sp, -0x68, %sp
F001BC70: 113c04bc                 sethi   %hi(unk_F012F204), %o0
F001BC74: d4162038                 lduh    [%i0+0x38], %o2
F001BC78: 90122204                 bset    %lo(unk_F012F204), %o0
F001BC7C: 920aa0ff                 and     %o2, 0xFF, %o1
F001BC80: 932a6004                 sll     %o1, 4, %o1
F001BC84: 92024008                 add     %o1, %o0, %o1
F001BC88: 80a2a000                 cmp     %o2, 0
F001BC8C: 02800014                 be      locret_F001BCDC
F001BC90: d602600c                 ld      [%o1+0xC], %o3
F001BC94: 80a66000                 cmp     %i1, 0
F001BC98: 12800005                 bne     loc_F001BCAC
F001BC9C: d002c000                 ld      [%o3], %o0
F001BCA0: b2102004                 mov     4, %i1
F001BCA4: 10800003                 ba      loc_F001BCB0
F001BCA8: 90122010                 bset    0x10, %o0
F001BCAC: 900a3fef                 and     %o0, -0x11, %o0
F001BCB0: d022c000                 st      %o0, [%o3]
F001BCB4: 900e6001                 and     %i1, 1, %o0
F001BCB8: 932a2001                 sll     %o0, 1, %o1
F001BCBC: d00ae00c                 ldub    [%o3+0xC], %o0
F001BCC0: 808e6002                 btst    2, %i1
F001BCC4: 90120019                 bset    %i1, %o0
F001BCC8: 02800003                 be      loc_F001BCD4
F001BCCC: d02ae00c                 stb     %o0, [%o3+0xC]
F001BCD0: 92126001                 bset    1, %o1
F001BCD4: 7ffffea0                 call    _ptcwakeup
F001BCD8: 90100018                 mov     %i0, %o0
F001BCDC: 81c7e008                 ret
F001BCE0: 81e80000                 restore
