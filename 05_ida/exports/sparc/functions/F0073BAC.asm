F0073BAC: 9de3bf88                 save    %sp, -0x78, %sp
F0073BB0: 80a62000                 cmp     %i0, 0
F0073BB4: 02800086                 be      loc_F0073DCC
F0073BB8: 80a66001                 cmp     %i1, 1
F0073BBC: 02800006                 be      loc_F0073BD4
F0073BC0: 80a66003                 cmp     %i1, 3
F0073BC4: 22800030                 be,a    loc_F0073C84
F0073BC8: d006c000                 ld      [%i3], %o0
F0073BCC: 10800083                 ba      locret_F0073DD8
F0073BD0: b0102004                 mov     4, %i0
F0073BD4: d006c000                 ld      [%i3], %o0
F0073BD8: 80a22007                 cmp     %o0, 7
F0073BDC: 0880007c                 bleu    loc_F0073DCC
F0073BE0: 113c0442                 sethi   %hi(_kernel_task), %o0
F0073BE4: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0
F0073BE8: 80a60008                 cmp     %i0, %o0
F0073BEC: 02800004                 be      loc_F0073BFC
F0073BF0: 113c04d1                 sethi   -0xFECBC00, %o0
F0073BF4: 10800003                 ba      loc_F0073C00
F0073BF8: d206200c                 ld      [%i0+0xC], %o1
F0073BFC: d2022340                 ld      [%o0+0x340], %o1
F0073C00: d0026028                 ld      [%o1+0x28], %o0
F0073C04: d026a008                 st      %o0, [%i2+8]
F0073C08: d0026024                 ld      [%o1+0x24], %o0
F0073C0C: d0022020                 ld      [%o0+0x20], %o0
F0073C10: 133c0447                 sethi   %hi(_page_size), %o1
F0073C14: 7ffe4a3b                 call    _umul
F0073C18: d202613c                 ld      [%o1+%lo(_page_size)], %o1
F0073C1C: d026a00c                 st      %o0, [%i2+0xC]
F0073C20: d0060000                 ld      [%i0], %o0
F0073C24: 80a22000                 cmp     %o0, 0
F0073C28: 12bffffe                 bne     loc_F0073C20
F0073C2C: 01000000                 nop
F0073C30: 40008c9e                 call    _simple_lock_try
F0073C34: 90100018                 mov     %i0, %o0
F0073C38: 80a22000                 cmp     %o0, 0
F0073C3C: 02bffff9                 be      loc_F0073C20
F0073C40: 01000000                 nop
F0073C44: d0062048                 ld      [%i0+0x48], %o0
F0073C48: d026a004                 st      %o0, [%i2+4]
F0073C4C: d0062044                 ld      [%i0+0x44], %o0
F0073C50: d0268000                 st      %o0, [%i2]
F0073C54: d0062054                 ld      [%i0+0x54], %o0
F0073C58: d026a010                 st      %o0, [%i2+0x10]
F0073C5C: d0062058                 ld      [%i0+0x58], %o0
F0073C60: d026a014                 st      %o0, [%i2+0x14]
F0073C64: d006205c                 ld      [%i0+0x5C], %o0
F0073C68: d026a018                 st      %o0, [%i2+0x18]
F0073C6C: d0062060                 ld      [%i0+0x60], %o0
F0073C70: d026a01c                 st      %o0, [%i2+0x1C]
F0073C74: c0260000                 clr     [%i0]
F0073C78: 90102008                 mov     8, %o0
F0073C7C: 10800056                 ba      loc_F0073DD4
F0073C80: d026c000                 st      %o0, [%i3]
F0073C84: 80a22003                 cmp     %o0, 3
F0073C88: 28800054                 bleu,a  locret_F0073DD8
F0073C8C: b0102004                 mov     4, %i0
F0073C90: c0268000                 clr     [%i2]
F0073C94: c026a004                 clr     [%i2+4]
F0073C98: c026a008                 clr     [%i2+8]
F0073C9C: c026a00c                 clr     [%i2+0xC]
F0073CA0: d0060000                 ld      [%i0], %o0
F0073CA4: 80a22000                 cmp     %o0, 0
F0073CA8: 12bffffe                 bne     loc_F0073CA0
F0073CAC: 01000000                 nop
F0073CB0: 40008c7e                 call    _simple_lock_try
F0073CB4: 90100018                 mov     %i0, %o0
F0073CB8: 80a22000                 cmp     %o0, 0
F0073CBC: 02bffff9                 be      loc_F0073CA0
F0073CC0: 9006201c                 add     %i0, 0x1C, %o0
F0073CC4: e006201c                 ld      [%i0+0x1C], %l0
F0073CC8: 80a20010                 cmp     %o0, %l0
F0073CCC: 0280003c                 be      loc_F0073DBC
F0073CD0: 110003d0                 sethi   0xF4000, %o0
F0073CD4: a612223f                 or      %o0, 0x23F, %l3
F0073CD8: 113ffc2fa41221c0         set     -0xF4240, %l2
F0073CE0: 40008baa                 call    _splusclock
F0073CE4: b2042020                 add     %l0, 0x20, %i1 ! ' '
F0073CE8: a2100008                 mov     %o0, %l1
F0073CEC: d0064000                 ld      [%i1], %o0
F0073CF0: 80a22000                 cmp     %o0, 0
F0073CF4: 12bffffe                 bne     loc_F0073CEC
F0073CF8: 01000000                 nop
F0073CFC: 40008c6b                 call    _simple_lock_try
F0073D00: 90100019                 mov     %i1, %o0
F0073D04: 80a22000                 cmp     %o0, 0
F0073D08: 02bffff9                 be      loc_F0073CEC
F0073D0C: 90100010                 mov     %l0, %o0
F0073D10: 9207bff0                 add     %fp, var_10, %o1
F0073D14: 40000f38                 call    _thread_read_times
F0073D18: 9407bfe8                 add     %fp, var_18, %o2
F0073D1C: c0242020                 clr     [%l0+0x20]
F0073D20: 40008c01                 call    _splx
F0073D24: 90100011                 mov     %l1, %o0
F0073D28: d206a004                 ld      [%i2+4], %o1
F0073D2C: d007bff4                 ld      [%fp+var_C], %o0
F0073D30: d4068000                 ld      [%i2], %o2
F0073D34: 92024008                 add     %o1, %o0, %o1
F0073D38: d226a004                 st      %o1, [%i2+4]
F0073D3C: d007bff0                 ld      [%fp+var_10], %o0
F0073D40: d206a004                 ld      [%i2+4], %o1
F0073D44: 94028008                 add     %o2, %o0, %o2
F0073D48: 80a24013                 cmp     %o1, %l3
F0073D4C: 04800007                 ble     loc_F0073D68
F0073D50: d4268000                 st      %o2, [%i2]
F0073D54: 92024012                 add     %o1, %l2, %o1
F0073D58: d0068000                 ld      [%i2], %o0
F0073D5C: d226a004                 st      %o1, [%i2+4]
F0073D60: 90022001                 inc     %o0
F0073D64: d0268000                 st      %o0, [%i2]
F0073D68: d206a00c                 ld      [%i2+0xC], %o1
F0073D6C: d007bfec                 ld      [%fp+var_14], %o0
F0073D70: d406a008                 ld      [%i2+8], %o2
F0073D74: 92024008                 add     %o1, %o0, %o1
F0073D78: d226a00c                 st      %o1, [%i2+0xC]
F0073D7C: d007bfe8                 ld      [%fp+var_18], %o0
F0073D80: d206a00c                 ld      [%i2+0xC], %o1
F0073D84: 94028008                 add     %o2, %o0, %o2
F0073D88: 80a24013                 cmp     %o1, %l3
F0073D8C: 04800007                 ble     loc_F0073DA8
F0073D90: d426a008                 st      %o2, [%i2+8]
F0073D94: 92024012                 add     %o1, %l2, %o1
F0073D98: d006a008                 ld      [%i2+8], %o0
F0073D9C: d226a00c                 st      %o1, [%i2+0xC]
F0073DA0: 90022001                 inc     %o0
F0073DA4: d026a008                 st      %o0, [%i2+8]
F0073DA8: e0042010                 ld      [%l0+0x10], %l0
F0073DAC: 9006201c                 add     %i0, 0x1C, %o0
F0073DB0: 80a20010                 cmp     %o0, %l0
F0073DB4: 12bfffcb                 bne     loc_F0073CE0
F0073DB8: 01000000                 nop
F0073DBC: c0260000                 clr     [%i0]
F0073DC0: 90102004                 mov     4, %o0
F0073DC4: 10800004                 ba      loc_F0073DD4
F0073DC8: d026c000                 st      %o0, [%i3]
F0073DCC: 10800003                 ba      locret_F0073DD8
F0073DD0: b0102004                 mov     4, %i0
F0073DD4: b0102000                 mov     0, %i0
F0073DD8: 81c7e008                 ret
F0073DDC: 81e80000                 restore
