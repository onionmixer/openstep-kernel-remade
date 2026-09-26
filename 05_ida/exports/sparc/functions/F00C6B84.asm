F00C6B84: 9de3bf80                 save    %sp, -0x80, %sp
F00C6B88: 113c0506                 sethi   %hi(paIswriteprotect), %o0! id
F00C6B8C: d20221bc                 ld      [%o0+%lo(paIswriteprotect)], %o1! SEL
F00C6B90: e007a05c                 ld      [%fp+arg_5C], %l0
F00C6B94: 4000ab37                 call    _objc_msgSend
F00C6B98: 90100018                 mov     %i0, %o0
F00C6B9C: 912a2018                 sll     %o0, 24, %o0
F00C6BA0: 80a22000                 cmp     %o0, 0
F00C6BA4: 02800004                 be      loc_F00C6BB4
F00C6BA8: 90100018                 mov     %i0, %o0! id
F00C6BAC: 10800016                 ba      locret_F00C6C04
F00C6BB0: b0103d31                 mov     -0x2CF, %i0
F00C6BB4: 133c0506                 sethi   %hi(paDiskparamcommo), %o1
F00C6BB8: d20261c4                 ld      [%o1+%lo(paDiskparamcommo)], %o1! SEL
F00C6BBC: 9410001a                 mov     %i2, %o2
F00C6BC0: 9610001b                 mov     %i3, %o3
F00C6BC4: 9807bfec                 add     %fp, var_14, %o4
F00C6BC8: 4000ab2a                 call    _objc_msgSend
F00C6BCC: 9a07bfe8                 add     %fp, var_18, %o5
F00C6BD0: 80a22000                 cmp     %o0, 0
F00C6BD4: 3280000c                 bne,a   locret_F00C6C04
F00C6BD8: b0100008                 mov     %o0, %i0
F00C6BDC: d0062184                 ld      [%i0+0x184], %o0! id
F00C6BE0: 9810001c                 mov     %i4, %o4
F00C6BE4: d407bfec                 ld      [%fp+var_14], %o2
F00C6BE8: 9a10001d                 mov     %i5, %o5
F00C6BEC: d607bfe8                 ld      [%fp+var_18], %o3
F00C6BF0: 133c0504                 sethi   %hi(paWriteasyncatLe), %o1
F00C6BF4: d2026190                 ld      [%o1+%lo(paWriteasyncatLe)], %o1! SEL
F00C6BF8: 4000ab1e                 call    _objc_msgSend
F00C6BFC: e023a05c                 st      %l0, [%sp+0x80+var_24]
F00C6C00: b0100008                 mov     %o0, %i0
F00C6C04: 81c7e008                 ret
F00C6C08: 81e80000                 restore
