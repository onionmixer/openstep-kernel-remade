F00A8960: 9de3bf78                 save    %sp, -0x88, %sp! int
F00A8964: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A8968: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00A896C: d2060000                 ld      [%i0], %o1
F00A8970: 808a6040                 btst    0x40, %o1 ! '@'
F00A8974: 02800005                 be      loc_F00A8988
F00A8978: d027bfd8                 st      %o0, [%fp+var_28]
F00A897C: 113c046f                 sethi   %hi(aSyscall), %o0! "syscall"
F00A8980: 7ffdb1fc                 call    _panic
F00A8984: 90122038                 bset    %lo(aSyscall), %o0! "syscall"
F00A8988: d007bfd8                 ld      [%fp+var_28], %o0
F00A898C: d4022084                 ld      [%o0+0x84], %o2
F00A8990: d2062010                 ld      [%i0+0x10], %o1
F00A8994: 113c04cf                 sethi   %hi(_active_u), %o0
F00A8998: d60221d8                 ld      [%o0+%lo(_active_u)], %o3! int
F00A899C: d227bfe0                 st      %o1, [%fp+var_20]
F00A89A0: d202c000                 ld      [%o3], %o1
F00A89A4: d427bfec                 st      %o2, [%fp+var_14]
F00A89A8: 80a26000                 cmp     %o1, 0
F00A89AC: 02800007                 be      loc_F00A89C8
F00A89B0: d227bfe4                 st      %o1, [%fp+var_1C]
F00A89B4: d002e174                 ld      [%o3+0x174], %o0
F00A89B8: d027bff0                 st      %o0, [%fp+var_10]
F00A89BC: d002e178                 ld      [%o3+0x178], %o0
F00A89C0: d027bff4                 st      %o0, [%fp+var_C]
F00A89C4: 80a26000                 cmp     %o1, 0
F00A89C8: 12800006                 bne     loc_F00A89E0
F00A89CC: 90102005                 mov     5, %o0
F00A89D0: 92102700                 mov     0x700, %o1
F00A89D4: 7ffeecc9                 call    _exception
F00A89D8: 94102000                 mov     0, %o2
F00A89DC: 3080005c                 ba,a    locret_F00A8B4C
F00A89E0: 7fffb1c8                 call    _syncfpu
F00A89E4: 90100018                 mov     %i0, %o0
F00A89E8: d007bfec                 ld      [%fp+var_14], %o0
F00A89EC: 133c042b                 sethi   %hi(_nsysent), %o1
F00A89F0: d20261c8                 ld      [%o1+%lo(_nsysent)], %o1
F00A89F4: d407bfe0                 ld      [%fp+var_20], %o2
F00A89F8: 80a28009                 cmp     %o2, %o1
F00A89FC: 0a800006                 bcs     loc_F00A8A14
F00A8A00: f0220000                 st      %i0, [%o0]
F00A8A04: 113c042a90122200         set     unk_F010AA00, %o0
F00A8A0C: 10800007                 ba      loc_F00A8A28
F00A8A10: d027bfdc                 st      %o0, [%fp+var_24]
F00A8A14: 932aa003                 sll     %o2, 3, %o1
F00A8A18: 113c042a90122008         set     _sysent, %o0
F00A8A20: 92024008                 add     %o1, %o0, %o1
F00A8A24: d227bfdc                 st      %o1, [%fp+var_24]
F00A8A28: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F00A8A2C: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00A8A30: c02a2038                 clrb    [%o0+0x38]
F00A8A34: d407bfdc                 ld      [%fp+var_24], %o2
F00A8A38: d0528000                 ldsh    [%o2], %o0
F00A8A3C: 80a22006                 cmp     %o0, 6
F00A8A40: 04800020                 ble     loc_F00A8AC0
F00A8A44: c027bfe8                 clr     [%fp+var_18]
F00A8A48: d006202c                 ld      [%i0+0x2C], %o0
F00A8A4C: d207bfec                 ld      [%fp+var_14], %o1
F00A8A50: d0226004                 st      %o0, [%o1+4]
F00A8A54: d0062030                 ld      [%i0+0x30], %o0
F00A8A58: d0226008                 st      %o0, [%o1+8]
F00A8A5C: d0062034                 ld      [%i0+0x34], %o0
F00A8A60: d022600c                 st      %o0, [%o1+0xC]
F00A8A64: d0062038                 ld      [%i0+0x38], %o0
F00A8A68: d0226010                 st      %o0, [%o1+0x10]
F00A8A6C: d006203c                 ld      [%i0+0x3C], %o0
F00A8A70: d0226014                 st      %o0, [%o1+0x14]
F00A8A74: d0062040                 ld      [%i0+0x40], %o0
F00A8A78: d0226018                 st      %o0, [%o1+0x18]
F00A8A7C: d0062044                 ld      [%i0+0x44], %o0
F00A8A80: 9202601c                 inc     0x1C, %o1! int
F00A8A84: d4528000                 ldsh    [%o2], %o2
F00A8A88: 9002205c                 inc     0x5C, %o0 ! '\'! int
F00A8A8C: 9402bffa                 inc     -6, %o2! int
F00A8A90: 7fffbd72                 call    _copyin
F00A8A94: 952aa002                 sll     %o2, 2, %o2
F00A8A98: 80a22000                 cmp     %o0, 0
F00A8A9C: 02800006                 be      loc_F00A8AB4
F00A8AA0: d20421dc                 ld      [%l0+0x1DC], %o1
F00A8AA4: 9010200e                 mov     0xE, %o0
F00A8AA8: d02a6038                 stb     %o0, [%o1+0x38]
F00A8AAC: 4000002a                 call    _unix_syscall_return
F00A8AB0: d007bfe8                 ld      [%fp+var_18], %o0
F00A8AB4: d207bfec                 ld      [%fp+var_14], %o1
F00A8AB8: 10800004                 ba      loc_F00A8AC8
F00A8ABC: 90026004                 add     %o1, 4, %o0
F00A8AC0: d207bfec                 ld      [%fp+var_14], %o1
F00A8AC4: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F00A8AC8: d0226024                 st      %o0, [%o1+0x24]
F00A8ACC: d207bfec                 ld      [%fp+var_14], %o1
F00A8AD0: c0226030                 clr     [%o1+0x30]
F00A8AD4: d4062030                 ld      [%i0+0x30], %o2
F00A8AD8: 90026028                 add     %o1, 0x28, %o0 ! '('! jmp_buf
F00A8ADC: 7fffb89e                 call    _setjmp
F00A8AE0: d4226034                 st      %o2, [%o1+0x34]
F00A8AE4: 80a22000                 cmp     %o0, 0
F00A8AE8: 0280000c                 be      loc_F00A8B18
F00A8AEC: d207bfec                 ld      [%fp+var_14], %o1
F00A8AF0: d007bfe8                 ld      [%fp+var_18], %o0
F00A8AF4: 80a22000                 cmp     %o0, 0
F00A8AF8: 12800013                 bne     loc_F00A8B44
F00A8AFC: d007bfec                 ld      [%fp+var_14], %o0
F00A8B00: d04a2039                 ldsb    [%o0+0x39], %o0
F00A8B04: 80a22002                 cmp     %o0, 2
F00A8B08: 0280000f                 be      loc_F00A8B44
F00A8B0C: 90102004                 mov     4, %o0
F00A8B10: 1080000d                 ba      loc_F00A8B44
F00A8B14: d027bfe8                 st      %o0, [%fp+var_18]
F00A8B18: 90102003                 mov     3, %o0
F00A8B1C: d02a6039                 stb     %o0, [%o1+0x39]
F00A8B20: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00A8B24: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F00A8B28: d207bfdc                 ld      [%fp+var_24], %o1
F00A8B2C: d2026004                 ld      [%o1+4], %o1
F00A8B30: 9fc24000                 call    %o1
F00A8B34: d0022024                 ld      [%o0+0x24], %o0
F00A8B38: d007bfec                 ld      [%fp+var_14], %o0
F00A8B3C: d04a2038                 ldsb    [%o0+0x38], %o0
F00A8B40: d027bfe8                 st      %o0, [%fp+var_18]
F00A8B44: 40000004                 call    _unix_syscall_return
F00A8B48: d007bfe8                 ld      [%fp+var_18], %o0
F00A8B4C: 81c7e008                 ret
F00A8B50: 81e80000                 restore
