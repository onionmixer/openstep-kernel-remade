F005E5C0: 9de3bf88                 save    %sp, -0x78, %sp
F005E5C4: 7fffff4c                 call    _ipc_splay_tree_init
F005E5C8: 9010001a                 mov     %i2, %o0
F005E5CC: d2062004                 ld      [%i0+4], %o1
F005E5D0: 80a26000                 cmp     %o1, 0
F005E5D4: 02800048                 be      locret_F005E6F4
F005E5D8: d227bff4                 st      %o1, [%fp+var_C]
F005E5DC: d0060000                 ld      [%i0], %o0
F005E5E0: 80a20019                 cmp     %o0, %i1
F005E5E4: 02800012                 be      loc_F005E62C
F005E5E8: 90100009                 mov     %o1, %o0
F005E5EC: a0062008                 add     %i0, 8, %l0
F005E5F0: 92100010                 mov     %l0, %o1
F005E5F4: d406200c                 ld      [%i0+0xC], %o2
F005E5F8: a2062010                 add     %i0, 0x10, %l1
F005E5FC: d8062014                 ld      [%i0+0x14], %o4
F005E600: 7fffff32                 call    sub_F005E2C8
F005E604: 96100011                 mov     %l1, %o3
F005E608: 90100019                 mov     %i1, %o0
F005E60C: 9407bff4                 add     %fp, var_C, %o2
F005E610: 96100010                 mov     %l0, %o3
F005E614: 9806200c                 add     %i0, 0xC, %o4
F005E618: d207bff4                 ld      [%fp+var_C], %o1
F005E61C: 9a062014                 add     %i0, 0x14, %o5
F005E620: da23a05c                 st      %o5, [%sp+0x78+var_1C]
F005E624: 7ffffee0                 call    sub_F005E1A4
F005E628: 9a100011                 mov     %l1, %o5
F005E62C: d407bff4                 ld      [%fp+var_C], %o2
F005E630: d002a010                 ld      [%o2+0x10], %o0
F005E634: 80a20019                 cmp     %o0, %i1
F005E638: 1a80001c                 bcc     loc_F005E6A8
F005E63C: d206200c                 ld      [%i0+0xC], %o1
F005E640: d002a018                 ld      [%o2+0x18], %o0
F005E644: d0224000                 st      %o0, [%o1]
F005E648: d0062014                 ld      [%i0+0x14], %o0
F005E64C: c0220000                 clr     [%o0]
F005E650: d007bff4                 ld      [%fp+var_C], %o0
F005E654: d2062008                 ld      [%i0+8], %o1
F005E658: d2222018                 st      %o1, [%o0+0x18]
F005E65C: d026a004                 st      %o0, [%i2+4]
F005E660: d0022010                 ld      [%o0+0x10], %o0
F005E664: d0268000                 st      %o0, [%i2]
F005E668: 9006a008                 add     %i2, 8, %o0
F005E66C: d026a00c                 st      %o0, [%i2+0xC]
F005E670: 9006a010                 add     %i2, 0x10, %o0
F005E674: d026a014                 st      %o0, [%i2+0x14]
F005E678: d0062010                 ld      [%i0+0x10], %o0
F005E67C: d027bff4                 st      %o0, [%fp+var_C]
F005E680: 80a22000                 cmp     %o0, 0
F005E684: 0280001c                 be      locret_F005E6F4
F005E688: d0262004                 st      %o0, [%i0+4]
F005E68C: d0022010                 ld      [%o0+0x10], %o0
F005E690: d0260000                 st      %o0, [%i0]
F005E694: 90062008                 add     %i0, 8, %o0
F005E698: d026200c                 st      %o0, [%i0+0xC]
F005E69C: 90062010                 add     %i0, 0x10, %o0
F005E6A0: 10800015                 ba      locret_F005E6F4
F005E6A4: d0262014                 st      %o0, [%i0+0x14]
F005E6A8: d002a018                 ld      [%o2+0x18], %o0
F005E6AC: d0224000                 st      %o0, [%o1]
F005E6B0: d007bff4                 ld      [%fp+var_C], %o0
F005E6B4: c0222018                 clr     [%o0+0x18]
F005E6B8: d0262004                 st      %o0, [%i0+4]
F005E6BC: f2260000                 st      %i1, [%i0]
F005E6C0: 90062008                 add     %i0, 8, %o0
F005E6C4: d2062008                 ld      [%i0+8], %o1
F005E6C8: d026200c                 st      %o0, [%i0+0xC]
F005E6CC: d227bff4                 st      %o1, [%fp+var_C]
F005E6D0: 80a26000                 cmp     %o1, 0
F005E6D4: 02800008                 be      locret_F005E6F4
F005E6D8: d226a004                 st      %o1, [%i2+4]
F005E6DC: d0026010                 ld      [%o1+0x10], %o0
F005E6E0: d0268000                 st      %o0, [%i2]
F005E6E4: 9006a008                 add     %i2, 8, %o0
F005E6E8: d026a00c                 st      %o0, [%i2+0xC]
F005E6EC: 9006a010                 add     %i2, 0x10, %o0
F005E6F0: d026a014                 st      %o0, [%i2+0x14]
F005E6F4: 81c7e008                 ret
F005E6F8: 81e80000                 restore
