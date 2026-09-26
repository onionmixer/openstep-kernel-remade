F00A7900: 9de3bf88                 save    %sp, -0x78, %sp! int
F00A7904: f427a04c                 st      %i2, [%fp+arg_4C]
F00A7908: a2102000                 mov     0, %l1
F00A790C: 213c04cf                 sethi   %hi(_active_u), %l0
F00A7910: c027bfec                 clr     [%fp+var_14]
F00A7914: d20421d8                 ld      [%l0+%lo(_active_u)], %o1
F00A7918: a8102000                 mov     0, %l4
F00A791C: e6024000                 ld      [%o1], %l3
F00A7920: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A7924: 80a4e000                 cmp     %l3, 0
F00A7928: 02800006                 be      loc_F00A7940
F00A792C: ea022260                 ld      [%o0+%lo(_active_threads)], %l5
F00A7930: d0026174                 ld      [%o1+0x174], %o0
F00A7934: d027bff0                 st      %o0, [%fp+var_10]
F00A7938: d0026178                 ld      [%o1+0x178], %o0
F00A793C: d027bff4                 st      %o0, [%fp+var_C]
F00A7940: 7fffb5f0                 call    _syncfpu
F00A7944: 90100019                 mov     %i1, %o0
F00A7948: 110000409012200a         set     0x1000A, %o0
F00A7950: 80a60008                 cmp     %i0, %o0
F00A7954: 228001b2                 be,a    loc_F00A801C
F00A7958: 113c046e                 sethi   -0xFEE4800, %o0
F00A795C: 18800024                 bgu     loc_F00A79EC
F00A7960: 11000040                 sethi   0x10000, %o0
F00A7964: 90122005                 bset    5, %o0
F00A7968: 80a60008                 cmp     %i0, %o0
F00A796C: 028001c0                 be      loc_F00A806C
F00A7970: 01000000                 nop
F00A7974: 18800011                 bgu     loc_F00A79B8
F00A7978: 11000040                 sethi   0x10000, %o0
F00A797C: 90122002                 bset    2, %o0
F00A7980: 80a60008                 cmp     %i0, %o0
F00A7984: 22800136                 be,a    loc_F00A7E5C
F00A7988: 113c046e                 sethi   -0xFEE4800, %o0
F00A798C: 18800004                 bgu     loc_F00A799C
F00A7990: 11000040                 sethi   0x10000, %o0
F00A7994: 10800024                 ba      loc_F00A7A24
F00A7998: 90122001                 bset    1, %o0
F00A799C: 1100004090122003         set     0x10003, %o0
F00A79A4: 80a60008                 cmp     %i0, %o0
F00A79A8: 0280011f                 be      loc_F00A7E24
F00A79AC: 113c046e                 sethi   %hi(_tudebug), %o0
F00A79B0: 10800038                 ba      loc_F00A7A90
F00A79B4: d0022008                 ld      [%o0+%lo(_tudebug)], %o0
F00A79B8: 1100004090122008         set     0x10008, %o0
F00A79C0: 80a60008                 cmp     %i0, %o0
F00A79C4: 22800174                 be,a    loc_F00A7F94
F00A79C8: 113c046e                 sethi   -0xFEE4800, %o0
F00A79CC: 1880005d                 bgu     loc_F00A7B40
F00A79D0: 11000040                 sethi   0x10000, %o0
F00A79D4: 90122007                 bset    7, %o0
F00A79D8: 80a60008                 cmp     %i0, %o0
F00A79DC: 028000d3                 be      loc_F00A7D28
F00A79E0: 113c046e                 sethi   %hi(_tudebug), %o0
F00A79E4: 1080002b                 ba      loc_F00A7A90
F00A79E8: d0022008                 ld      [%o0+%lo(_tudebug)], %o0
F00A79EC: 110000409012202b         set     0x1002B, %o0
F00A79F4: 80a60008                 cmp     %i0, %o0
F00A79F8: 22800043                 be,a    loc_F00A7B04
F00A79FC: 113c0464                 sethi   -0xFEE7000, %o0
F00A7A00: 1880000e                 bgu     loc_F00A7A38
F00A7A04: 11000040                 sethi   0x10000, %o0
F00A7A08: 90122029                 bset    0x29, %o0 ! ')'
F00A7A0C: 80a60008                 cmp     %i0, %o0
F00A7A10: 2280004d                 be,a    loc_F00A7B44
F00A7A14: 9007a04c                 add     %fp, arg_4C, %o0
F00A7A18: 18800135                 bgu     loc_F00A7EEC
F00A7A1C: 11000040                 sethi   0x10000, %o0
F00A7A20: 90122021                 bset    0x21, %o0 ! '!'
F00A7A24: 80a60008                 cmp     %i0, %o0
F00A7A28: 0280004c                 be      loc_F00A7B58
F00A7A2C: 113c04f8                 sethi   -0xFEC2000, %o0
F00A7A30: 10800017                 ba      loc_F00A7A8C
F00A7A34: 113c046e                 sethi   -0xFEE4800, %o0
F00A7A38: 1100004090122082         set     0x10082, %o0
F00A7A40: 80a60008                 cmp     %i0, %o0
F00A7A44: 2280012b                 be,a    loc_F00A7EF0
F00A7A48: 113c046e                 sethi   -0xFEE4800, %o0
F00A7A4C: 18800008                 bgu     loc_F00A7A6C
F00A7A50: 11000040                 sethi   0x10000, %o0
F00A7A54: 90122081                 bset    0x81, %o0
F00A7A58: 80a60008                 cmp     %i0, %o0
F00A7A5C: 02800160                 be      loc_F00A7FDC
F00A7A60: 113c046e                 sethi   %hi(_tudebug), %o0
F00A7A64: 1080000b                 ba      loc_F00A7A90
F00A7A68: d0022008                 ld      [%o0+%lo(_tudebug)], %o0
F00A7A6C: 1100004090122087         set     0x10087, %o0
F00A7A74: 80a60008                 cmp     %i0, %o0
F00A7A78: 0280012f                 be      loc_F00A7F34
F00A7A7C: 11000041                 sethi   0x10400, %o0
F00A7A80: 80a60008                 cmp     %i0, %o0
F00A7A84: 028001a3                 be      loc_F00A8110
F00A7A88: 113c046e                 sethi   -0xFEE4800, %o0
F00A7A8C: d0022008                 ld      [%o0+8], %o0
F00A7A90: 80a22000                 cmp     %o0, 0
F00A7A94: 02800007                 be      loc_F00A7AB0
F00A7A98: 90100018                 mov     %i0, %o0
F00A7A9C: 92100019                 mov     %i1, %o1
F00A7AA0: 94102000                 mov     0, %o2
F00A7AA4: 96102000                 mov     0, %o3
F00A7AA8: 40000654                 call    _showregs
F00A7AAC: 98102000                 mov     0, %o4
F00A7AB0: 11000040                 sethi   0x10000, %o0
F00A7AB4: 922e0008                 andn    %i0, %o0, %o1
F00A7AB8: 80a2607f                 cmp     %o1, 0x7F
F00A7ABC: 18800004                 bgu     loc_F00A7ACC
F00A7AC0: 808e2020                 btst    0x20, %i0 ! ' '
F00A7AC4: 0280000a                 be      loc_F00A7AEC
F00A7AC8: 90100018                 mov     %i0, %o0
F00A7ACC: a2100009                 mov     %o1, %l1
F00A7AD0: 80a4607f                 cmp     %l1, 0x7F
F00A7AD4: 04800003                 ble     loc_F00A7AE0
F00A7AD8: a4102002                 mov     2, %l2
F00A7ADC: a4102005                 mov     5, %l2
F00A7AE0: d0066004                 ld      [%i1+4], %o0
F00A7AE4: 1080020d                 ba      loc_F00A8318
F00A7AE8: d027bfec                 st      %o0, [%fp+var_14]
F00A7AEC: 92100019                 mov     %i1, %o1
F00A7AF0: d407a04c                 ld      [%fp+arg_4C], %o2
F00A7AF4: 9610001b                 mov     %i3, %o3
F00A7AF8: 7ffffeca                 call    _badtrap
F00A7AFC: 9810001c                 mov     %i4, %o4
F00A7B00: 113c0464                 sethi   -0xFEE7000, %o0
F00A7B04: d00222b0                 ld      [%o0+0x2B0], %o0
F00A7B08: 80a22000                 cmp     %o0, 0
F00A7B0C: 12800008                 bne     loc_F00A7B2C
F00A7B10: 90100018                 mov     %i0, %o0
F00A7B14: 92100019                 mov     %i1, %o1
F00A7B18: d407a04c                 ld      [%fp+arg_4C], %o2
F00A7B1C: 9610001b                 mov     %i3, %o3
F00A7B20: 7fffff30                 call    _check_fsr
F00A7B24: 9810001c                 mov     %i4, %o4
F00A7B28: 90100018                 mov     %i0, %o0
F00A7B2C: 92100019                 mov     %i1, %o1
F00A7B30: d407a04c                 ld      [%fp+arg_4C], %o2
F00A7B34: 9610001b                 mov     %i3, %o3
F00A7B38: 7ffffeba                 call    _badtrap
F00A7B3C: 9810001c                 mov     %i4, %o4
F00A7B40: 9007a04c                 add     %fp, arg_4C, %o0
F00A7B44: 92100019                 mov     %i1, %o1
F00A7B48: 9410001c                 mov     %i4, %o2
F00A7B4C: 7fffb717                 call    _module_wkaround
F00A7B50: 9610001b                 mov     %i3, %o3
F00A7B54: 113c04f8                 sethi   -0xFEC2000, %o0
F00A7B58: d0022120                 ld      [%o0+0x120], %o0
F00A7B5C: 80a22080                 cmp     %o0, 0x80
F00A7B60: 1280000f                 bne     loc_F00A7B9C
F00A7B64: 808ee001                 btst    1, %i3
F00A7B68: 9136e00a                 srl     %i3, 10, %o0
F00A7B6C: 808a20ff                 btst    0xFF, %o0
F00A7B70: 0280000a                 be      loc_F00A7B98
F00A7B74: 90102000                 mov     0, %o0
F00A7B78: 9210001b                 mov     %i3, %o1
F00A7B7C: d407a04c                 ld      [%fp+arg_4C], %o2
F00A7B80: 96100018                 mov     %i0, %o3
F00A7B84: 7fffbd6c                 call    _ebe_handler
F00A7B88: 98100019                 mov     %i1, %o4
F00A7B8C: 80a23fff                 cmp     %o0, -1
F00A7B90: 1280026f                 bne     locret_F00A854C
F00A7B94: 01000000                 nop
F00A7B98: 808ee001                 btst    1, %i3
F00A7B9C: 02800022                 be      loc_F00A7C24
F00A7BA0: 808eec00                 btst    0xC00, %i3
F00A7BA4: 9136e002                 srl     %i3, 2, %o0
F00A7BA8: 900a2007                 and     %o0, 7, %o0
F00A7BAC: 80a22004                 cmp     %o0, 4
F00A7BB0: 1280001d                 bne     loc_F00A7C24
F00A7BB4: 808eec00                 btst    0xC00, %i3
F00A7BB8: 213c0464                 sethi   %hi(_cpuid), %l0
F00A7BBC: 113c046e                 sethi   %hi(aCpuDMultipleFa), %o0! "cpu %d: Multiple faults occurred\n"
F00A7BC0: d2042340                 ld      [%l0+%lo(_cpuid)], %o1
F00A7BC4: 7ffdb2a5                 call    _printf
F00A7BC8: 90122218                 bset    %lo(aCpuDMultipleFa), %o0! "cpu %d: Multiple faults occurred\n"
F00A7BCC: 1100004090122009         set     0x10009, %o0
F00A7BD4: 80a60008                 cmp     %i0, %o0
F00A7BD8: 113c046e                 sethi   %hi(aFirstFaultSAtP), %o0! "\t first fault %s at pc %x \n"
F00A7BDC: d2042340                 ld      [%l0+%lo(_cpuid)], %o1
F00A7BE0: 12800005                 bne     loc_F00A7BF4
F00A7BE4: 96122240                 or      %o0, %lo(aFirstFaultSAtP), %o3! "\t first fault %s at pc %x \n"
F00A7BE8: 113c046e                 sethi   %hi(aUserData), %o0! "User Data "
F00A7BEC: 10800004                 ba      loc_F00A7BFC
F00A7BF0: 94122260                 or      %o0, %lo(aUserData), %o2! "User Data "
F00A7BF4: 113c046e94122270         set     aUserText, %o2! "User text "
F00A7BFC: 7ffdb297                 call    _printf
F00A7C00: 9010000b                 mov     %o3, %o0
F00A7C04: 113c046e                 sethi   %hi(aSecondFaultTra), %o0! "\t second fault: translation error "
F00A7C08: 7ffdb294                 call    _printf
F00A7C0C: 90122280                 bset    %lo(aSecondFaultTra), %o0! "\t second fault: translation error "
F00A7C10: d207a04c                 ld      [%fp+arg_4C], %o1
F00A7C14: 113c046e                 sethi   %hi(aAtAddrX), %o0! "at addr %x\n"
F00A7C18: 7ffdb290                 call    _printf
F00A7C1C: 901222a8                 bset    %lo(aAtAddrX), %o0! "at addr %x\n"
F00A7C20: 808eec00                 btst    0xC00, %i3
F00A7C24: 0280000a                 be      loc_F00A7C4C
F00A7C28: 11000004                 sethi   0x1000, %o0
F00A7C2C: 808ec008                 btst    %o0, %i3
F00A7C30: 12800008                 bne     loc_F00A7C50
F00A7C34: 113c0464                 sethi   -0xFEE7000, %o0
F00A7C38: a4102001                 mov     1, %l2
F00A7C3C: d007a04c                 ld      [%fp+arg_4C], %o0
F00A7C40: a2102309                 mov     0x309, %l1
F00A7C44: 108001b5                 ba      loc_F00A8318
F00A7C48: d027bfec                 st      %o0, [%fp+var_14]
F00A7C4C: 113c0464                 sethi   -0xFEE7000, %o0
F00A7C50: d00222b0                 ld      [%o0+0x2B0], %o0
F00A7C54: 80a22000                 cmp     %o0, 0
F00A7C58: 12800008                 bne     loc_F00A7C78
F00A7C5C: 90100018                 mov     %i0, %o0
F00A7C60: 92100019                 mov     %i1, %o1
F00A7C64: d407a04c                 ld      [%fp+arg_4C], %o2
F00A7C68: 9610001b                 mov     %i3, %o3
F00A7C6C: 7ffffedd                 call    _check_fsr
F00A7C70: 9810001c                 mov     %i4, %o4
F00A7C74: 90100018                 mov     %i0, %o0
F00A7C78: 92100019                 mov     %i1, %o1
F00A7C7C: 9610001b                 mov     %i3, %o3
F00A7C80: d407a04c                 ld      [%fp+arg_4C], %o2
F00A7C84: 7ffffeb4                 call    _get_faulttype
F00A7C88: 9810001c                 mov     %i4, %o4
F00A7C8C: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F00A7C90: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F00A7C94: e24a2038                 ldsb    [%o0+0x38], %l1
F00A7C98: c02a2038                 clrb    [%o0+0x38]
F00A7C9C: d405600c                 ld      [%l5+0xC], %o2
F00A7CA0: 113c04d0                 sethi   %hi(_page_mask), %o0
F00A7CA4: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F00A7CA8: 80a72002                 cmp     %i4, 2
F00A7CAC: d007a04c                 ld      [%fp+arg_4C], %o0
F00A7CB0: 96102001                 mov     1, %o3
F00A7CB4: d402a00c                 ld      [%o2+0xC], %o2
F00A7CB8: 12800003                 bne     loc_F00A7CC4
F00A7CBC: 922a0009                 andn    %o0, %o1, %o1
F00A7CC0: 96102003                 mov     3, %o3
F00A7CC4: 9010000a                 mov     %o2, %o0
F00A7CC8: 9410000b                 mov     %o3, %o2
F00A7CCC: 96102000                 mov     0, %o3
F00A7CD0: 7fff656f                 call    _vm_fault
F00A7CD4: 98102000                 mov     0, %o4
F00A7CD8: a0100008                 mov     %o0, %l0
F00A7CDC: d004a1dc                 ld      [%l2+0x1DC], %o0
F00A7CE0: 80a42000                 cmp     %l0, 0
F00A7CE4: 0280021a                 be      locret_F00A854C
F00A7CE8: e22a2038                 stb     %l1, [%o0+0x38]
F00A7CEC: 113c046e                 sethi   %hi(_tudebug), %o0
F00A7CF0: d0022008                 ld      [%o0+%lo(_tudebug)], %o0
F00A7CF4: 80a22000                 cmp     %o0, 0
F00A7CF8: 02800007                 be      loc_F00A7D14
F00A7CFC: 90100018                 mov     %i0, %o0
F00A7D00: 92100019                 mov     %i1, %o1
F00A7D04: d407a04c                 ld      [%fp+arg_4C], %o2
F00A7D08: 9610001b                 mov     %i3, %o3
F00A7D0C: 400005bb                 call    _showregs
F00A7D10: 9810001c                 mov     %i4, %o4
F00A7D14: a4102001                 mov     1, %l2
F00A7D18: d007a04c                 ld      [%fp+arg_4C], %o0
F00A7D1C: a2100010                 mov     %l0, %l1
F00A7D20: 1080017e                 ba      loc_F00A8318
F00A7D24: d027bfec                 st      %o0, [%fp+var_14]
F00A7D28: d0022008                 ld      [%o0+8], %o0
F00A7D2C: 80a22000                 cmp     %o0, 0
F00A7D30: 02800007                 be      loc_F00A7D4C
F00A7D34: 90100018                 mov     %i0, %o0
F00A7D38: 92100019                 mov     %i1, %o1
F00A7D3C: 94102000                 mov     0, %o2
F00A7D40: 96102000                 mov     0, %o3
F00A7D44: 400005ad                 call    _showregs
F00A7D48: 98102000                 mov     0, %o4
F00A7D4C: 153c046e                 sethi   %hi(_alignfaults), %o2
F00A7D50: d002a018                 ld      [%o2+%lo(_alignfaults)], %o0
F00A7D54: d2056028                 ld      [%l5+0x28], %o1
F00A7D58: 90022001                 inc     %o0
F00A7D5C: d2026294                 ld      [%o1+0x294], %o1
F00A7D60: 808a6002                 btst    2, %o1
F00A7D64: 12800007                 bne     loc_F00A7D80
F00A7D68: d022a018                 st      %o0, [%o2+%lo(_alignfaults)]
F00A7D6C: 113c046e                 sethi   %hi(_fix_user_alignment), %o0
F00A7D70: d0022020                 ld      [%o0+%lo(_fix_user_alignment)], %o0
F00A7D74: 80a22000                 cmp     %o0, 0
F00A7D78: 02800024                 be      loc_F00A7E08
F00A7D7C: a4102001                 mov     1, %l2
F00A7D80: 113c046e                 sethi   %hi(_log_user_alignment_traps), %o0
F00A7D84: d002201c                 ld      [%o0+%lo(_log_user_alignment_traps)], %o0
F00A7D88: 80a22000                 cmp     %o0, 0
F00A7D8C: 02800018                 be      loc_F00A7DEC
F00A7D90: e00421d8                 ld      [%l0+0x1D8], %l0
F00A7D94: 113c046e                 sethi   %hi(aUserTrapCorrec), %o0! "user_trap(): corrected user alignment f"...
F00A7D98: 7ffdb230                 call    _printf
F00A7D9C: 90122370                 bset    %lo(aUserTrapCorrec), %o0! "user_trap(): corrected user alignment f"...
F00A7DA0: 80a42000                 cmp     %l0, 0
F00A7DA4: 113c046e                 sethi   %hi(aProgramSPidDPc), %o0! " program \"%s\", pid %d pc 0x%x\n"
F00A7DA8: 02800004                 be      loc_F00A7DB8
F00A7DAC: 961223a0                 or      %o0, %lo(aProgramSPidDPc), %o3! " program \"%s\", pid %d pc 0x%x\n"
F00A7DB0: 10800005                 ba      loc_F00A7DC4
F00A7DB4: 92042008                 add     %l0, 8, %o1
F00A7DB8: 113c046e921223c0         set     aUnknown_0, %o1! "Unknown"
F00A7DC0: 80a42000                 cmp     %l0, 0
F00A7DC4: 02800007                 be      loc_F00A7DE0
F00A7DC8: 94103fff                 mov     -1, %o2
F00A7DCC: d4040000                 ld      [%l0], %o2
F00A7DD0: 80a2a000                 cmp     %o2, 0
F00A7DD4: 22800003                 be,a    loc_F00A7DE0
F00A7DD8: 94103fff                 mov     -1, %o2
F00A7DDC: d452a030                 ldsh    [%o2+0x30], %o2
F00A7DE0: 9010000b                 mov     %o3, %o0! char *
F00A7DE4: 7ffdb21d                 call    _printf
F00A7DE8: d6066004                 ld      [%i1+4], %o3
F00A7DEC: 90100019                 mov     %i1, %o0
F00A7DF0: 92102001                 mov     1, %o1
F00A7DF4: 4000067c                 call    _do_unaligned
F00A7DF8: 94102000                 mov     0, %o2
F00A7DFC: 80a22001                 cmp     %o0, 1
F00A7E00: 02800030                 be      loc_F00A7EC0
F00A7E04: a4102001                 mov     1, %l2
F00A7E08: a2102304                 mov     0x304, %l1
F00A7E0C: 90100019                 mov     %i1, %o0
F00A7E10: 92102000                 mov     0, %o1
F00A7E14: 40000674                 call    _do_unaligned
F00A7E18: 9407bfec                 add     %fp, var_14, %o2
F00A7E1C: 10800140                 ba      loc_F00A831C
F00A7E20: 80a4a000                 cmp     %l2, 0
F00A7E24: d0022008                 ld      [%o0+8], %o0
F00A7E28: 80a22000                 cmp     %o0, 0
F00A7E2C: 02800007                 be      loc_F00A7E48
F00A7E30: 90100018                 mov     %i0, %o0
F00A7E34: 92100019                 mov     %i1, %o1
F00A7E38: 94102000                 mov     0, %o2
F00A7E3C: 96102000                 mov     0, %o3
F00A7E40: 4000056e                 call    _showregs
F00A7E44: 98102000                 mov     0, %o4
F00A7E48: a4102002                 mov     2, %l2
F00A7E4C: d0066004                 ld      [%i1+4], %o0
F00A7E50: a2102003                 mov     3, %l1
F00A7E54: 10800131                 ba      loc_F00A8318
F00A7E58: d027bfec                 st      %o0, [%fp+var_14]
F00A7E5C: d0022008                 ld      [%o0+8], %o0
F00A7E60: 80a22000                 cmp     %o0, 0
F00A7E64: 02800007                 be      loc_F00A7E80
F00A7E68: 90100018                 mov     %i0, %o0
F00A7E6C: 92100019                 mov     %i1, %o1
F00A7E70: 94102000                 mov     0, %o2
F00A7E74: 96102000                 mov     0, %o3
F00A7E78: 40000560                 call    _showregs
F00A7E7C: 98102000                 mov     0, %o4
F00A7E80: 40000771                 call    _simulate_unimp
F00A7E84: 90100019                 mov     %i1, %o0
F00A7E88: 80a23fff                 cmp     %o0, -1
F00A7E8C: 02800014                 be      loc_F00A7EDC
F00A7E90: a2102502                 mov     0x502, %l1
F00A7E94: 14800007                 bg      loc_F00A7EB0
F00A7E98: 80a22000                 cmp     %o0, 0
F00A7E9C: 80a23ffe                 cmp     %o0, -2
F00A7EA0: 0280000f                 be      loc_F00A7EDC
F00A7EA4: a2102606                 mov     0x606, %l1
F00A7EA8: 1080000d                 ba      loc_F00A7EDC
F00A7EAC: a2102502                 mov     0x502, %l1
F00A7EB0: 0280000a                 be      loc_F00A7ED8
F00A7EB4: 80a22001                 cmp     %o0, 1
F00A7EB8: 12800009                 bne     loc_F00A7EDC
F00A7EBC: a2102502                 mov     0x502, %l1
F00A7EC0: d2066008                 ld      [%i1+8], %o1
F00A7EC4: d0066008                 ld      [%i1+8], %o0
F00A7EC8: d2266004                 st      %o1, [%i1+4]
F00A7ECC: 90022004                 inc     4, %o0
F00A7ED0: 1080019f                 ba      locret_F00A854C
F00A7ED4: d0266008                 st      %o0, [%i1+8]
F00A7ED8: a2102502                 mov     0x502, %l1
F00A7EDC: d0066004                 ld      [%i1+4], %o0
F00A7EE0: a4102002                 mov     2, %l2
F00A7EE4: 1080010d                 ba      loc_F00A8318
F00A7EE8: d027bfec                 st      %o0, [%fp+var_14]
F00A7EEC: 113c046e                 sethi   -0xFEE4800, %o0
F00A7EF0: d0022008                 ld      [%o0+8], %o0
F00A7EF4: 80a22000                 cmp     %o0, 0
F00A7EF8: 0280000b                 be      loc_F00A7F24
F00A7EFC: 113c046e                 sethi   %hi(_tudebugfpe), %o0
F00A7F00: d0022010                 ld      [%o0+%lo(_tudebugfpe)], %o0
F00A7F04: 80a22000                 cmp     %o0, 0
F00A7F08: 02800007                 be      loc_F00A7F24
F00A7F0C: 90100018                 mov     %i0, %o0
F00A7F10: 92100019                 mov     %i1, %o1
F00A7F14: 94102000                 mov     0, %o2
F00A7F18: 96102000                 mov     0, %o3
F00A7F1C: 40000537                 call    _showregs
F00A7F20: 98102000                 mov     0, %o4
F00A7F24: a4102003                 mov     3, %l2
F00A7F28: d0066008                 ld      [%i1+8], %o0
F00A7F2C: 10800013                 ba      loc_F00A7F78
F00A7F30: a2102606                 mov     0x606, %l1
F00A7F34: 113c046e                 sethi   %hi(_tudebug), %o0
F00A7F38: d0022008                 ld      [%o0+%lo(_tudebug)], %o0
F00A7F3C: 80a22000                 cmp     %o0, 0
F00A7F40: 0280000b                 be      loc_F00A7F6C
F00A7F44: 113c046e                 sethi   %hi(_tudebugfpe), %o0
F00A7F48: d0022010                 ld      [%o0+%lo(_tudebugfpe)], %o0
F00A7F4C: 80a22000                 cmp     %o0, 0
F00A7F50: 02800007                 be      loc_F00A7F6C
F00A7F54: 90100018                 mov     %i0, %o0
F00A7F58: 92100019                 mov     %i1, %o1
F00A7F5C: 94102000                 mov     0, %o2
F00A7F60: 96102000                 mov     0, %o3
F00A7F64: 40000525                 call    _showregs
F00A7F68: 98102000                 mov     0, %o4
F00A7F6C: a4102003                 mov     3, %l2
F00A7F70: d0066008                 ld      [%i1+8], %o0
F00A7F74: a2102604                 mov     0x604, %l1
F00A7F78: d2066008                 ld      [%i1+8], %o1
F00A7F7C: d0266004                 st      %o0, [%i1+4]
F00A7F80: 92026004                 inc     4, %o1
F00A7F84: d0066004                 ld      [%i1+4], %o0
F00A7F88: d2266008                 st      %o1, [%i1+8]
F00A7F8C: 108000e3                 ba      loc_F00A8318
F00A7F90: d027bfec                 st      %o0, [%fp+var_14]
F00A7F94: d0022008                 ld      [%o0+8], %o0
F00A7F98: 80a22000                 cmp     %o0, 0
F00A7F9C: 0280000b                 be      loc_F00A7FC8
F00A7FA0: 113c046e                 sethi   %hi(_tudebugfpe), %o0
F00A7FA4: d0022010                 ld      [%o0+%lo(_tudebugfpe)], %o0
F00A7FA8: 80a22000                 cmp     %o0, 0
F00A7FAC: 02800007                 be      loc_F00A7FC8
F00A7FB0: 90100018                 mov     %i0, %o0
F00A7FB4: 92100019                 mov     %i1, %o1
F00A7FB8: d407a04c                 ld      [%fp+arg_4C], %o2
F00A7FBC: 96102000                 mov     0, %o3
F00A7FC0: 4000050e                 call    _showregs
F00A7FC4: 98102000                 mov     0, %o4
F00A7FC8: a4102003                 mov     3, %l2
F00A7FCC: d007a04c                 ld      [%fp+arg_4C], %o0
F00A7FD0: a2102008                 mov     8, %l1
F00A7FD4: 108000d1                 ba      loc_F00A8318
F00A7FD8: d027bfec                 st      %o0, [%fp+var_14]
F00A7FDC: d0022008                 ld      [%o0+8], %o0
F00A7FE0: 80a22000                 cmp     %o0, 0
F00A7FE4: 0280000b                 be      loc_F00A8010
F00A7FE8: 113c046e                 sethi   %hi(_tudebugbpt), %o0
F00A7FEC: d002200c                 ld      [%o0+%lo(_tudebugbpt)], %o0
F00A7FF0: 80a22000                 cmp     %o0, 0
F00A7FF4: 02800007                 be      loc_F00A8010
F00A7FF8: 90100018                 mov     %i0, %o0
F00A7FFC: 92100019                 mov     %i1, %o1
F00A8000: 94102000                 mov     0, %o2
F00A8004: 96102000                 mov     0, %o3
F00A8008: 400004fc                 call    _showregs
F00A800C: 98102000                 mov     0, %o4
F00A8010: a4102006                 mov     6, %l2
F00A8014: 108000c1                 ba      loc_F00A8318
F00A8018: a2102081                 mov     0x81, %l1
F00A801C: d0022008                 ld      [%o0+8], %o0
F00A8020: 80a22000                 cmp     %o0, 0
F00A8024: 02800007                 be      loc_F00A8040
F00A8028: 90100018                 mov     %i0, %o0
F00A802C: 92100019                 mov     %i1, %o1
F00A8030: 94102000                 mov     0, %o2
F00A8034: 96102000                 mov     0, %o3! int
F00A8038: 400004f0                 call    _showregs
F00A803C: 98102000                 mov     0, %o4! int
F00A8040: a4102003                 mov     3, %l2
F00A8044: d0066004                 ld      [%i1+4], %o0
F00A8048: a210200a                 mov     0xA, %l1
F00A804C: 108000b3                 ba      loc_F00A8318
F00A8050: d027bfec                 st      %o0, [%fp+var_14]
F00A8054: a4102002                 mov     2, %l2
F00A8058: a2102501                 mov     0x501, %l1
F00A805C: d0066004                 ld      [%i1+4], %o0
F00A8060: a8102004                 mov     4, %l4
F00A8064: 1080001a                 ba      loc_F00A80CC
F00A8068: d027bfec                 st      %o0, [%fp+var_14]
F00A806C: 7ffd73a4                 call    _flush_user_windows
F00A8070: a0102000                 mov     0, %l0
F00A8074: d4056028                 ld      [%l5+0x28], %o2! int
F00A8078: d002a230                 ld      [%o2+0x230], %o0
F00A807C: 80a44008                 cmp     %l1, %o0
F00A8080: 16800014                 bge     loc_F00A80D0
F00A8084: 80a52000                 cmp     %l4, 0
F00A8088: b4102010                 mov     0x10, %i2
F00A808C: 912c2002                 sll     %l0, 2, %o0
F00A8090: 9002000a                 add     %o0, %o2, %o0
F00A8094: d2022210                 ld      [%o0+0x210], %o1! int
F00A8098: 808a6007                 btst    7, %o1
F00A809C: 12bfffee                 bne     loc_F00A8054
F00A80A0: 9002801a                 add     %o2, %i2, %o0! int
F00A80A4: 7fffc00a                 call    _copyout
F00A80A8: 94102040                 mov     0x40, %o2 ! '@'
F00A80AC: 80a22000                 cmp     %o0, 0
F00A80B0: 12bfffe9                 bne     loc_F00A8054
F00A80B4: a0042001                 inc     %l0
F00A80B8: d4056028                 ld      [%l5+0x28], %o2
F00A80BC: d002a230                 ld      [%o2+0x230], %o0
F00A80C0: 80a40008                 cmp     %l0, %o0
F00A80C4: 06bffff2                 bl      loc_F00A808C
F00A80C8: b406a040                 inc     0x40, %i2 ! '@'
F00A80CC: 80a52000                 cmp     %l4, 0
F00A80D0: 12800005                 bne     loc_F00A80E4
F00A80D4: 113c046e                 sethi   -0xFEE4800, %o0
F00A80D8: d0056028                 ld      [%l5+0x28], %o0
F00A80DC: 1080011c                 ba      locret_F00A854C
F00A80E0: c0222230                 clr     [%o0+0x230]
F00A80E4: d0022008                 ld      [%o0+8], %o0
F00A80E8: 80a22000                 cmp     %o0, 0
F00A80EC: 0280008b                 be      loc_F00A8318
F00A80F0: 90100018                 mov     %i0, %o0
F00A80F4: 92100019                 mov     %i1, %o1
F00A80F8: 94102000                 mov     0, %o2
F00A80FC: 96102000                 mov     0, %o3
F00A8100: 400004be                 call    _showregs
F00A8104: 98102000                 mov     0, %o4
F00A8108: 10800085                 ba      loc_F00A831C
F00A810C: 80a4a000                 cmp     %l2, 0
F00A8110: a8100010                 mov     %l0, %l4
F00A8114: 113ff7ffb81223ff         set     -0x200001, %i4
F00A811C: 373c04cfb016e160         set     _need_ast, %i0
F00A8124: a0102000                 mov     0, %l0
F00A8128: f406e160                 ld      [%i3+0x160], %i2
F00A812C: 80a4e000                 cmp     %l3, 0
F00A8130: 02800037                 be      loc_F00A820C
F00A8134: 11000800                 sethi   0x200000, %o0
F00A8138: d204e028                 ld      [%l3+0x28], %o1
F00A813C: 808a4008                 btst    %o0, %o1
F00A8140: 0280000c                 be      loc_F00A8170
F00A8144: d20521d8                 ld      [%l4+0x1D8], %o1
F00A8148: d0026258                 ld      [%o1+0x258], %o0
F00A814C: 80a22000                 cmp     %o0, 0
F00A8150: 02800008                 be      loc_F00A8170
F00A8154: 92026244                 inc     0x244, %o1
F00A8158: d0066004                 ld      [%i1+4], %o0
F00A815C: 7fffc71f                 call    _addupc
F00A8160: 94102001                 mov     1, %o2
F00A8164: d004e028                 ld      [%l3+0x28], %o0
F00A8168: 900a001c                 and     %o0, %i4, %o0
F00A816C: d024e028                 st      %o0, [%l3+0x28]
F00A8170: d0040018                 ld      [%l0+%i0], %o0
F00A8174: 900a3fdf                 and     %o0, -0x21, %o0
F00A8178: d0240018                 st      %o0, [%l0+%i0]
F00A817C: d0040018                 ld      [%l0+%i0], %o0
F00A8180: d005618c                 ld      [%l5+0x18C], %o0
F00A8184: 808a2003                 btst    3, %o0
F00A8188: 12800021                 bne     loc_F00A820C
F00A818C: 01000000                 nop
F00A8190: d04ce017                 ldsb    [%l3+0x17], %o0
F00A8194: 80a22000                 cmp     %o0, 0
F00A8198: 12800014                 bne     loc_F00A81E8
F00A819C: 01000000                 nop
F00A81A0: d0056084                 ld      [%l5+0x84], %o0
F00A81A4: d204e018                 ld      [%l3+0x18], %o1
F00A81A8: d002204c                 ld      [%o0+0x4C], %o0
F00A81AC: 94924008                 orcc    %o1, %o0, %o2
F00A81B0: 02800017                 be      loc_F00A820C
F00A81B4: 01000000                 nop
F00A81B8: d004e028                 ld      [%l3+0x28], %o0
F00A81BC: 808a2010                 btst    0x10, %o0
F00A81C0: 32800009                 bne,a   loc_F00A81E4
F00A81C4: d04ce017                 ldsb    [%l3+0x17], %o0
F00A81C8: d004e020                 ld      [%l3+0x20], %o0
F00A81CC: d204e01c                 ld      [%l3+0x1C], %o1
F00A81D0: 90120009                 bset    %o1, %o0
F00A81D4: 80aa8008                 andncc  %o2, %o0, %g0
F00A81D8: 0280000d                 be      loc_F00A820C
F00A81DC: 01000000                 nop
F00A81E0: d04ce017                 ldsb    [%l3+0x17], %o0
F00A81E4: 80a22000                 cmp     %o0, 0
F00A81E8: 12800007                 bne     loc_F00A8204
F00A81EC: 01000000                 nop
F00A81F0: 7ffda5f0                 call    _issig
F00A81F4: 90102000                 mov     0, %o0
F00A81F8: 80a22000                 cmp     %o0, 0
F00A81FC: 02800004                 be      loc_F00A820C
F00A8200: 01000000                 nop
F00A8204: 7ffda752                 call    _psig
F00A8208: 01000000                 nop
F00A820C: d0040018                 ld      [%l0+%i0], %o0
F00A8210: 902a001a                 bclr    %i2, %o0
F00A8214: d0240018                 st      %o0, [%l0+%i0]
F00A8218: d0040018                 ld      [%l0+%i0], %o0
F00A821C: d005618c                 ld      [%l5+0x18C], %o0
F00A8220: 808a2003                 btst    3, %o0
F00A8224: 02800004                 be      loc_F00A8234
F00A8228: 808ea004                 btst    4, %i2
F00A822C: 7fff33b8                 call    _thread_halt_self
F00A8230: 9e03fef4                 inc     -0x10C, %o7
F00A8234: 12800032                 bne     loc_F00A82FC
F00A8238: d40521d8                 ld      [%l4+0x1D8], %o2
F00A823C: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F00A8240: d00221b0                 ld      [%o0+%lo(_processor_ptr)], %o0
F00A8244: d405604c                 ld      [%l5+0x4C], %o2
F00A8248: d202212c                 ld      [%o0+0x12C], %o1
F00A824C: d8022108                 ld      [%o0+0x108], %o4
F00A8250: c4022124                 ld      [%o0+0x124], %g2
F00A8254: da026108                 ld      [%o1+0x108], %o5
F00A8258: d6026104                 ld      [%o1+0x104], %o3
F00A825C: d0056060                 ld      [%l5+0x60], %o0
F00A8260: 808aa002                 btst    2, %o2
F00A8264: 12800020                 bne     loc_F00A82E4
F00A8268: d2056058                 ld      [%l5+0x58], %o1
F00A826C: 80a32000                 cmp     %o4, 0
F00A8270: 34800020                 bg,a    loc_F00A82F0
F00A8274: 90102001                 mov     1, %o0
F00A8278: 80a22002                 cmp     %o0, 2
F00A827C: 22800007                 be,a    loc_F00A8298
F00A8280: 80a36000                 cmp     %o5, 0
F00A8284: 14800005                 bg      loc_F00A8298
F00A8288: 80a36000                 cmp     %o5, 0
F00A828C: 80a22001                 cmp     %o0, 1
F00A8290: 0280000d                 be      loc_F00A82C4
F00A8294: 80a36000                 cmp     %o5, 0
F00A8298: 02800015                 be      loc_F00A82EC
F00A829C: 80a2c009                 cmp     %o3, %o1
F00A82A0: 06800014                 bl      loc_F00A82F0
F00A82A4: 90102000                 mov     0, %o0
F00A82A8: 14800012                 bg      loc_F00A82F0
F00A82AC: 90102001                 mov     1, %o0
F00A82B0: 80a0a000                 cmp     %g2, 0
F00A82B4: 1280000f                 bne     loc_F00A82F0
F00A82B8: 90102000                 mov     0, %o0
F00A82BC: 1080000d                 ba      loc_F00A82F0
F00A82C0: 90102001                 mov     1, %o0
F00A82C4: 80a0a000                 cmp     %g2, 0
F00A82C8: 1280000a                 bne     loc_F00A82F0
F00A82CC: 90102000                 mov     0, %o0
F00A82D0: 80a36000                 cmp     %o5, 0
F00A82D4: 04800007                 ble     loc_F00A82F0
F00A82D8: 80a2c009                 cmp     %o3, %o1
F00A82DC: 06800006                 bl      loc_F00A82F4
F00A82E0: 80a22000                 cmp     %o0, 0
F00A82E4: 10800003                 ba      loc_F00A82F0
F00A82E8: 90102001                 mov     1, %o0
F00A82EC: 90102000                 mov     0, %o0
F00A82F0: 80a22000                 cmp     %o0, 0
F00A82F4: 02800009                 be      loc_F00A8318
F00A82F8: d40521d8                 ld      [%l4+0x1D8], %o2
F00A82FC: 113c026f                 sethi   %hi(_thread_exception_return), %o0
F00A8300: d202a1b0                 ld      [%o2+0x1B0], %o1
F00A8304: 901223e4                 bset    %lo(_thread_exception_return), %o0
F00A8308: 92026001                 inc     %o1
F00A830C: 7fff250d                 call    _thread_block_with_continuation
F00A8310: d222a1b0                 st      %o1, [%o2+0x1B0]
F00A8314: 30bfff85                 ba,a    loc_F00A8128
F00A8318: 80a4a000                 cmp     %l2, 0
F00A831C: 02800005                 be      loc_F00A8330
F00A8320: 90100012                 mov     %l2, %o0
F00A8324: d407bfec                 ld      [%fp+var_14], %o2
F00A8328: 7ffeee74                 call    _exception
F00A832C: 92100011                 mov     %l1, %o1
F00A8330: 80a4e000                 cmp     %l3, 0
F00A8334: 02800025                 be      loc_F00A83C8
F00A8338: d005618c                 ld      [%l5+0x18C], %o0
F00A833C: 808a2003                 btst    3, %o0
F00A8340: 12800023                 bne     loc_F00A83CC
F00A8344: 01000000                 nop
F00A8348: d04ce017                 ldsb    [%l3+0x17], %o0
F00A834C: 80a22000                 cmp     %o0, 0
F00A8350: 12800014                 bne     loc_F00A83A0
F00A8354: 01000000                 nop
F00A8358: d0056084                 ld      [%l5+0x84], %o0
F00A835C: d204e018                 ld      [%l3+0x18], %o1
F00A8360: d002204c                 ld      [%o0+0x4C], %o0
F00A8364: 94924008                 orcc    %o1, %o0, %o2
F00A8368: 22800018                 be,a    loc_F00A83C8
F00A836C: d005618c                 ld      [%l5+0x18C], %o0
F00A8370: d004e028                 ld      [%l3+0x28], %o0
F00A8374: 808a2010                 btst    0x10, %o0
F00A8378: 32800009                 bne,a   loc_F00A839C
F00A837C: d04ce017                 ldsb    [%l3+0x17], %o0
F00A8380: d004e020                 ld      [%l3+0x20], %o0
F00A8384: d204e01c                 ld      [%l3+0x1C], %o1
F00A8388: 90120009                 bset    %o1, %o0
F00A838C: 80aa8008                 andncc  %o2, %o0, %g0
F00A8390: 2280000e                 be,a    loc_F00A83C8
F00A8394: d005618c                 ld      [%l5+0x18C], %o0
F00A8398: d04ce017                 ldsb    [%l3+0x17], %o0
F00A839C: 80a22000                 cmp     %o0, 0
F00A83A0: 12800007                 bne     loc_F00A83BC
F00A83A4: 01000000                 nop
F00A83A8: 7ffda582                 call    _issig
F00A83AC: 90102000                 mov     0, %o0
F00A83B0: 80a22000                 cmp     %o0, 0
F00A83B4: 22800005                 be,a    loc_F00A83C8
F00A83B8: d005618c                 ld      [%l5+0x18C], %o0
F00A83BC: 7ffda6e4                 call    _psig
F00A83C0: 01000000                 nop
F00A83C4: d005618c                 ld      [%l5+0x18C], %o0
F00A83C8: 808a2003                 btst    3, %o0
F00A83CC: 02800006                 be      loc_F00A83E4
F00A83D0: 80a4e000                 cmp     %l3, 0
F00A83D4: 7fff334e                 call    _thread_halt_self
F00A83D8: 01000000                 nop
F00A83DC: 10bfffd6                 ba      loc_F00A8334
F00A83E0: 80a4e000                 cmp     %l3, 0
F00A83E4: 02800023                 be      loc_F00A8470
F00A83E8: 113c04cf                 sethi   %hi(_active_u), %o0
F00A83EC: f00221d8                 ld      [%o0+%lo(_active_u)], %i0
F00A83F0: d0062258                 ld      [%i0+0x258], %o0
F00A83F4: 80a22000                 cmp     %o0, 0
F00A83F8: 0280001e                 be      loc_F00A8470
F00A83FC: d607bff4                 ld      [%fp+var_C], %o3
F00A8400: d0062178                 ld      [%i0+0x178], %o0
F00A8404: d4062174                 ld      [%i0+0x174], %o2
F00A8408: 9022000b                 sub     %o0, %o3, %o0! int
F00A840C: d607bff0                 ld      [%fp+var_10], %o3
F00A8410: 921023e8                 mov     0x3E8, %o1! int
F00A8414: 9422800b                 sub     %o2, %o3, %o2
F00A8418: a12aa005                 sll     %o2, 5, %l0
F00A841C: a024000a                 sub     %l0, %o2, %l0
F00A8420: a12c2002                 sll     %l0, 2, %l0
F00A8424: a004000a                 add     %l0, %o2, %l0
F00A8428: 7ffd7878                 call    _div
F00A842C: a12c2003                 sll     %l0, 3, %l0
F00A8430: 921023e8                 mov     0x3E8, %o1! int
F00A8434: 153c043e                 sethi   %hi(_tick), %o2
F00A8438: 96100008                 mov     %o0, %o3
F00A843C: d402a3e4                 ld      [%o2+%lo(_tick)], %o2
F00A8440: a004000b                 add     %l0, %o3, %l0
F00A8444: 7ffd7871                 call    _div
F00A8448: 9010000a                 mov     %o2, %o0! int
F00A844C: 92100008                 mov     %o0, %o1! int
F00A8450: 7ffd786e                 call    _div
F00A8454: 90100010                 mov     %l0, %o0
F00A8458: 94920000                 orcc    %o0, %g0, %o2
F00A845C: 02800006                 be      loc_F00A8474
F00A8460: 113c04d2                 sethi   -0xFECB800, %o0
F00A8464: d0066004                 ld      [%i1+4], %o0
F00A8468: 7fffc65c                 call    _addupc
F00A846C: 92062244                 add     %i0, 0x244, %o1
F00A8470: 113c04d2                 sethi   -0xFECB800, %o0
F00A8474: d00221b0                 ld      [%o0+0x1B0], %o0
F00A8478: d405604c                 ld      [%l5+0x4C], %o2
F00A847C: d202212c                 ld      [%o0+0x12C], %o1
F00A8480: d8022108                 ld      [%o0+0x108], %o4
F00A8484: c4022124                 ld      [%o0+0x124], %g2
F00A8488: da026108                 ld      [%o1+0x108], %o5
F00A848C: d6026104                 ld      [%o1+0x104], %o3
F00A8490: d0056060                 ld      [%l5+0x60], %o0
F00A8494: 808aa002                 btst    2, %o2
F00A8498: 12800020                 bne     loc_F00A8518
F00A849C: d2056058                 ld      [%l5+0x58], %o1
F00A84A0: 80a32000                 cmp     %o4, 0
F00A84A4: 34800020                 bg,a    loc_F00A8524
F00A84A8: 90102001                 mov     1, %o0
F00A84AC: 80a22002                 cmp     %o0, 2
F00A84B0: 22800007                 be,a    loc_F00A84CC
F00A84B4: 80a36000                 cmp     %o5, 0
F00A84B8: 14800005                 bg      loc_F00A84CC
F00A84BC: 80a36000                 cmp     %o5, 0
F00A84C0: 80a22001                 cmp     %o0, 1
F00A84C4: 0280000d                 be      loc_F00A84F8
F00A84C8: 80a36000                 cmp     %o5, 0
F00A84CC: 02800015                 be      loc_F00A8520
F00A84D0: 80a2c009                 cmp     %o3, %o1
F00A84D4: 06800014                 bl      loc_F00A8524
F00A84D8: 90102000                 mov     0, %o0
F00A84DC: 14800012                 bg      loc_F00A8524
F00A84E0: 90102001                 mov     1, %o0
F00A84E4: 80a0a000                 cmp     %g2, 0
F00A84E8: 1280000f                 bne     loc_F00A8524
F00A84EC: 90102000                 mov     0, %o0
F00A84F0: 1080000d                 ba      loc_F00A8524
F00A84F4: 90102001                 mov     1, %o0
F00A84F8: 80a0a000                 cmp     %g2, 0
F00A84FC: 1280000a                 bne     loc_F00A8524
F00A8500: 90102000                 mov     0, %o0
F00A8504: 80a36000                 cmp     %o5, 0
F00A8508: 04800007                 ble     loc_F00A8524
F00A850C: 80a2c009                 cmp     %o3, %o1
F00A8510: 06800006                 bl      loc_F00A8528
F00A8514: 80a22000                 cmp     %o0, 0
F00A8518: 10800003                 ba      loc_F00A8524
F00A851C: 90102001                 mov     1, %o0
F00A8520: 90102000                 mov     0, %o0
F00A8524: 80a22000                 cmp     %o0, 0
F00A8528: 02800009                 be      locret_F00A854C
F00A852C: 113c04cf                 sethi   %hi(_active_u), %o0
F00A8530: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F00A8534: 113c026f                 sethi   %hi(_thread_exception_return), %o0
F00A8538: d202a1b0                 ld      [%o2+0x1B0], %o1
F00A853C: 901223e4                 bset    %lo(_thread_exception_return), %o0
F00A8540: 92026001                 inc     %o1
F00A8544: 7fff247f                 call    _thread_block_with_continuation
F00A8548: d222a1b0                 st      %o1, [%o2+0x1B0]
F00A854C: 81c7e008                 ret
F00A8550: 81e80000                 restore
