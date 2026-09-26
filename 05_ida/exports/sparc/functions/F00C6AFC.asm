F00C6AFC: 9de3bf80                 save    %sp, -0x80, %sp
F00C6B00: 113c0506                 sethi   %hi(paIswriteprotect), %o0! id
F00C6B04: d20221bc                 ld      [%o0+%lo(paIswriteprotect)], %o1! SEL
F00C6B08: e007a05c                 ld      [%fp+arg_5C], %l0
F00C6B0C: 4000ab59                 call    _objc_msgSend
F00C6B10: 90100018                 mov     %i0, %o0
F00C6B14: 912a2018                 sll     %o0, 24, %o0
F00C6B18: 80a22000                 cmp     %o0, 0
F00C6B1C: 02800004                 be      loc_F00C6B2C
F00C6B20: 90100018                 mov     %i0, %o0! id
F00C6B24: 10800016                 ba      locret_F00C6B7C
F00C6B28: b0103d31                 mov     -0x2CF, %i0
F00C6B2C: 133c0506                 sethi   %hi(paDiskparamcommo), %o1
F00C6B30: d20261c4                 ld      [%o1+%lo(paDiskparamcommo)], %o1! SEL
F00C6B34: 9410001a                 mov     %i2, %o2
F00C6B38: 9610001b                 mov     %i3, %o3
F00C6B3C: 9807bfec                 add     %fp, var_14, %o4
F00C6B40: 4000ab4c                 call    _objc_msgSend
F00C6B44: 9a07bfe8                 add     %fp, var_18, %o5
F00C6B48: 80a22000                 cmp     %o0, 0
F00C6B4C: 3280000c                 bne,a   locret_F00C6B7C
F00C6B50: b0100008                 mov     %o0, %i0
F00C6B54: d0062184                 ld      [%i0+0x184], %o0! id
F00C6B58: 9810001c                 mov     %i4, %o4
F00C6B5C: d407bfec                 ld      [%fp+var_14], %o2
F00C6B60: 9a10001d                 mov     %i5, %o5
F00C6B64: d607bfe8                 ld      [%fp+var_18], %o3
F00C6B68: 133c0506                 sethi   %hi(paWriteatLengthB), %o1
F00C6B6C: d20261b8                 ld      [%o1+%lo(paWriteatLengthB)], %o1! SEL
F00C6B70: 4000ab40                 call    _objc_msgSend
F00C6B74: e023a05c                 st      %l0, [%sp+0x80+var_24]
F00C6B78: b0100008                 mov     %o0, %i0
F00C6B7C: 81c7e008                 ret
F00C6B80: 81e80000                 restore
