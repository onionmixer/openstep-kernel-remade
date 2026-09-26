F007BBF4: 9de3be70                 save    %sp, -0x190, %sp
F007BBF8: a0102124                 mov     0x124, %l0
F007BBFC: 9007bef4                 add     %fp, var_10C, %o0! __dst
F007BC00: 92100019                 mov     %i1, %o1! __src
F007BC04: 94102100                 mov     0x100, %o2! __n
F007BC08: 173c03d3                 sethi   %hi(dword_F00F4E1C), %o3
F007BC0C: d802e21c                 ld      [%o3+%lo(dword_F00F4E1C)], %o4
F007BC10: b207bed0                 add     %fp, var_130, %i1
F007BC14: 9612e21c                 bset    %lo(dword_F00F4E1C), %o3
F007BC18: da02e004                 ld      [%o3+4], %o5
F007BC1C: d827bee8                 st      %o4, [%fp+var_118]
F007BC20: d602e008                 ld      [%o3+8], %o3
F007BC24: da27beec                 st      %o5, [%fp+var_114]
F007BC28: 7ffe2f3d                 call    _strncpy
F007BC2C: d627bef0                 st      %o3, [%fp+var_110]
F007BC30: c02fbff3                 clrb    [%fp+var_D]
F007BC34: 90102001                 mov     1, %o0
F007BC38: d02fbed3                 stb     %o0, [%fp+var_12D]
F007BC3C: e027bed4                 st      %l0, [%fp+var_12C]
F007BC40: 90102100                 mov     0x100, %o0
F007BC44: d027bed8                 st      %o0, [%fp+var_128]
F007BC48: 7fffaa4c                 call    _mig_get_reply_port
F007BC4C: f027bee0                 st      %i0, [%fp+var_120]
F007BC50: d027bedc                 st      %o0, [%fp+var_124]
F007BC54: 901020c8                 mov     0xC8, %o0
F007BC58: d027bee4                 st      %o0, [%fp+var_11C]
F007BC5C: 90100019                 mov     %i1, %o0! reply_port
F007BC60: 92102000                 mov     0, %o1
F007BC64: 94102020                 mov     0x20, %o2 ! ' '
F007BC68: 96102000                 mov     0, %o3
F007BC6C: 7fffa8dc                 call    _msg_rpc
F007BC70: 98102000                 mov     0, %o4
F007BC74: b0920000                 orcc    %o0, %g0, %i0
F007BC78: 02800006                 be      loc_F007BC90
F007BC7C: 80a63f36                 cmp     %i0, -0xCA
F007BC80: 12800023                 bne     locret_F007BD0C
F007BC84: 01000000                 nop
F007BC88: 7fffaa49                 call    _mig_dealloc_reply_port
F007BC8C: 9e03e07c                 inc     0x7C, %o7 ! '|'
F007BC90: e007bed4                 ld      [%fp+var_12C], %l0
F007BC94: d007bee4                 ld      [%fp+var_11C], %o0
F007BC98: 80a2212c                 cmp     %o0, 0x12C
F007BC9C: 02800004                 be      loc_F007BCAC
F007BCA0: d20fbed3                 ldub    [%fp+var_12D], %o1
F007BCA4: 1080001a                 ba      locret_F007BD0C
F007BCA8: b0103ed3                 mov     -0x12D, %i0
F007BCAC: 80a42020                 cmp     %l0, 0x20 ! ' '
F007BCB0: 12800017                 bne     locret_F007BD0C
F007BCB4: b0103ed4                 mov     -0x12C, %i0
F007BCB8: 80a26001                 cmp     %o1, 1
F007BCBC: 0280000a                 be      loc_F007BCE4
F007BCC0: 80a42020                 cmp     %l0, 0x20 ! ' '
F007BCC4: 12800012                 bne     locret_F007BD0C
F007BCC8: 01000000                 nop
F007BCCC: 80a26001                 cmp     %o1, 1
F007BCD0: 1280000f                 bne     locret_F007BD0C
F007BCD4: d007beec                 ld      [%fp+var_114], %o0
F007BCD8: 80a22000                 cmp     %o0, 0
F007BCDC: 0280000c                 be      locret_F007BD0C
F007BCE0: 01000000                 nop
F007BCE4: d0066018                 ld      [%i1+0x18], %o0
F007BCE8: 133c03d3                 sethi   %hi(dword_F00F4E28), %o1
F007BCEC: d2026228                 ld      [%o1+%lo(dword_F00F4E28)], %o1
F007BCF0: 80a20009                 cmp     %o0, %o1
F007BCF4: 12800006                 bne     locret_F007BD0C
F007BCF8: b0103ed4                 mov     -0x12C, %i0
F007BCFC: f006601c                 ld      [%i1+0x1C], %i0
F007BD00: 80a62000                 cmp     %i0, 0
F007BD04: 22800002                 be,a    locret_F007BD0C
F007BD08: b0102000                 mov     0, %i0
F007BD0C: 81c7e008                 ret
F007BD10: 81e80000                 restore
