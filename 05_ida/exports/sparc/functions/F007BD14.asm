F007BD14: 9de3bf58                 save    %sp, -0xA8, %sp
F007BD18: a0102040                 mov     0x40, %l0 ! '@'
F007BD1C: 9007bfd4                 add     %fp, var_2C, %o0! __dst
F007BD20: 92100019                 mov     %i1, %o1! __src
F007BD24: 153c03d3                 sethi   %hi(dword_F00F4E2C), %o2
F007BD28: d602a22c                 ld      [%o2+%lo(dword_F00F4E2C)], %o3
F007BD2C: b207bfb8                 add     %fp, var_48, %i1
F007BD30: 94102010                 mov     0x10, %o2! __n
F007BD34: 7ffe2efa                 call    _strncpy
F007BD38: d627bfd0                 st      %o3, [%fp+var_30]
F007BD3C: c02fbfe3                 clrb    [%fp+var_1D]
F007BD40: 9007bfe8                 add     %fp, var_18, %o0! __dst
F007BD44: 153c03d3                 sethi   %hi(dword_F00F4E30), %o2
F007BD48: d602a230                 ld      [%o2+%lo(dword_F00F4E30)], %o3
F007BD4C: 9210001a                 mov     %i2, %o1! __src
F007BD50: 94102010                 mov     0x10, %o2! __n
F007BD54: 7ffe2ef2                 call    _strncpy
F007BD58: d627bfe4                 st      %o3, [%fp+var_1C]
F007BD5C: c02fbff7                 clrb    [%fp+var_9]
F007BD60: 90102001                 mov     1, %o0
F007BD64: d02fbfbb                 stb     %o0, [%fp+var_45]
F007BD68: e027bfbc                 st      %l0, [%fp+var_44]
F007BD6C: 90102100                 mov     0x100, %o0
F007BD70: d027bfc0                 st      %o0, [%fp+var_40]
F007BD74: 7fffaa01                 call    _mig_get_reply_port
F007BD78: f027bfc8                 st      %i0, [%fp+var_38]
F007BD7C: d027bfc4                 st      %o0, [%fp+var_3C]
F007BD80: 901020c9                 mov     0xC9, %o0
F007BD84: d027bfcc                 st      %o0, [%fp+var_34]
F007BD88: 90100019                 mov     %i1, %o0! reply_port
F007BD8C: 92102000                 mov     0, %o1
F007BD90: 94102030                 mov     0x30, %o2 ! '0'
F007BD94: 96102000                 mov     0, %o3
F007BD98: 7fffa891                 call    _msg_rpc
F007BD9C: 98102000                 mov     0, %o4
F007BDA0: b0920000                 orcc    %o0, %g0, %i0
F007BDA4: 02800006                 be      loc_F007BDBC
F007BDA8: 80a63f36                 cmp     %i0, -0xCA
F007BDAC: 12800033                 bne     locret_F007BE78
F007BDB0: 01000000                 nop
F007BDB4: 7fffa9fe                 call    _mig_dealloc_reply_port
F007BDB8: 9e03e0bc                 inc     0xBC, %o7
F007BDBC: e007bfbc                 ld      [%fp+var_44], %l0
F007BDC0: d007bfcc                 ld      [%fp+var_34], %o0
F007BDC4: 80a2212d                 cmp     %o0, 0x12D
F007BDC8: 02800004                 be      loc_F007BDD8
F007BDCC: d20fbfbb                 ldub    [%fp+var_45], %o1
F007BDD0: 1080002a                 ba      locret_F007BE78
F007BDD4: b0103ed3                 mov     -0x12D, %i0
F007BDD8: 80a42030                 cmp     %l0, 0x30 ! '0'
F007BDDC: 12800005                 bne     loc_F007BDF0
F007BDE0: 80a42020                 cmp     %l0, 0x20 ! ' '
F007BDE4: 80a26001                 cmp     %o1, 1
F007BDE8: 0280000a                 be      loc_F007BE10
F007BDEC: 80a42020                 cmp     %l0, 0x20 ! ' '
F007BDF0: 12800022                 bne     locret_F007BE78
F007BDF4: b0103ed4                 mov     -0x12C, %i0
F007BDF8: 80a26001                 cmp     %o1, 1
F007BDFC: 1280001f                 bne     locret_F007BE78
F007BE00: d007bfd4                 ld      [%fp+var_2C], %o0
F007BE04: 80a22000                 cmp     %o0, 0
F007BE08: 0280001c                 be      locret_F007BE78
F007BE0C: 01000000                 nop
F007BE10: d0066018                 ld      [%i1+0x18], %o0
F007BE14: 133c03d3                 sethi   %hi(dword_F00F4E34), %o1
F007BE18: d2026234                 ld      [%o1+%lo(dword_F00F4E34)], %o1
F007BE1C: 80a20009                 cmp     %o0, %o1
F007BE20: 12800016                 bne     locret_F007BE78
F007BE24: b0103ed4                 mov     -0x12C, %i0
F007BE28: f006601c                 ld      [%i1+0x1C], %i0
F007BE2C: 80a62000                 cmp     %i0, 0
F007BE30: 12800012                 bne     locret_F007BE78
F007BE34: 133c03d3                 sethi   %hi(dword_F00F4E38), %o1
F007BE38: d0066020                 ld      [%i1+0x20], %o0
F007BE3C: d2026238                 ld      [%o1+%lo(dword_F00F4E38)], %o1
F007BE40: 80a20009                 cmp     %o0, %o1
F007BE44: 1280000d                 bne     locret_F007BE78
F007BE48: b0103ed4                 mov     -0x12C, %i0
F007BE4C: d0066024                 ld      [%i1+0x24], %o0
F007BE50: d026c000                 st      %o0, [%i3]
F007BE54: d2066028                 ld      [%i1+0x28], %o1
F007BE58: 113c03d3                 sethi   %hi(dword_F00F4E3C), %o0
F007BE5C: d002223c                 ld      [%o0+%lo(dword_F00F4E3C)], %o0
F007BE60: 80a24008                 cmp     %o1, %o0
F007BE64: 12800005                 bne     locret_F007BE78
F007BE68: 01000000                 nop
F007BE6C: d006602c                 ld      [%i1+0x2C], %o0
F007BE70: d0270000                 st      %o0, [%i4]
F007BE74: f006601c                 ld      [%i1+0x1C], %i0
F007BE78: 81c7e008                 ret
F007BE7C: 81e80000                 restore
