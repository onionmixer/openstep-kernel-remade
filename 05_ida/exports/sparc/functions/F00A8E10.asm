F00A8E10: 9de3bf88                 save    %sp, -0x78, %sp! int
F00A8E14: d2060000                 ld      [%i0], %o1
F00A8E18: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A8E1C: 808a6040                 btst    0x40, %o1 ! '@'
F00A8E20: 02800005                 be      loc_F00A8E34
F00A8E24: e8022260                 ld      [%o0+%lo(_active_threads)], %l4
F00A8E28: 113c046f                 sethi   %hi(aMachcallNotUse), %o0! "machcall: not user mode"
F00A8E2C: 7ffdb0d1                 call    _panic
F00A8E30: 90122040                 bset    %lo(aMachcallNotUse), %o0! "machcall: not user mode"
F00A8E34: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F00A8E38: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F00A8E3C: ea052084                 ld      [%l4+0x84], %l5
F00A8E40: f0220000                 st      %i0, [%o0]
F00A8E44: 901461dc                 or      %l1, %lo(dword_F0133DDC), %o0
F00A8E48: d2023ffc                 ld      [%o0-4], %o1
F00A8E4C: e4024000                 ld      [%o1], %l2
F00A8E50: 80a4a000                 cmp     %l2, 0
F00A8E54: 22800007                 be,a    loc_F00A8E70
F00A8E58: d0062008                 ld      [%i0+8], %o0
F00A8E5C: d0026174                 ld      [%o1+0x174], %o0
F00A8E60: d027bff0                 st      %o0, [%fp+var_10]
F00A8E64: d0026178                 ld      [%o1+0x178], %o0
F00A8E68: d027bff4                 st      %o0, [%fp+var_C]
F00A8E6C: d0062008                 ld      [%i0+8], %o0
F00A8E70: d2062008                 ld      [%i0+8], %o1
F00A8E74: d0262004                 st      %o0, [%i0+4]
F00A8E78: 92026004                 inc     4, %o1
F00A8E7C: d0062010                 ld      [%i0+0x10], %o0
F00A8E80: d2262008                 st      %o1, [%i0+8]
F00A8E84: 92a00008                 subcc   %g0, %o0, %o1
F00A8E88: 0c800006                 bneg    loc_F00A8EA0
F00A8E8C: 113c0442                 sethi   %hi(_mach_trap_count), %o0
F00A8E90: d002224c                 ld      [%o0+%lo(_mach_trap_count)], %o0
F00A8E94: 80a24008                 cmp     %o1, %o0
F00A8E98: 06800006                 bl      loc_F00A8EB0
F00A8E9C: 932a6004                 sll     %o1, 4, %o1
F00A8EA0: 7fff27d6                 call    _kern_invalid
F00A8EA4: 01000000                 nop
F00A8EA8: 1080002d                 ba      loc_F00A8F5C
F00A8EAC: d026202c                 st      %o0, [%i0+0x2C]
F00A8EB0: 113c0441901221ec         set     _mach_trap_table, %o0
F00A8EB8: e0024008                 ld      [%o1+%o0], %l0
F00A8EBC: 80a42006                 cmp     %l0, 6
F00A8EC0: 0480001d                 ble     loc_F00A8F34
F00A8EC4: a6024008                 add     %o1, %o0, %l3
F00A8EC8: 92056004                 add     %l5, 4, %o1! int
F00A8ECC: d0062044                 ld      [%i0+0x44], %o0! int
F00A8ED0: 94043ffa                 add     %l0, -6, %o2
F00A8ED4: 952aa002                 sll     %o2, 2, %o2! int
F00A8ED8: 7fffbc60                 call    _copyin
F00A8EDC: 9002205c                 inc     0x5C, %o0 ! '\'
F00A8EE0: 80a22000                 cmp     %o0, 0
F00A8EE4: 02800005                 be      loc_F00A8EF8
F00A8EE8: d20461dc                 ld      [%l1+0x1DC], %o1
F00A8EEC: 9010200e                 mov     0xE, %o0
F00A8EF0: 1080001b                 ba      loc_F00A8F5C
F00A8EF4: d02a6038                 stb     %o0, [%o1+0x38]
F00A8EF8: 80a42007                 cmp     %l0, 7
F00A8EFC: 04800005                 ble     loc_F00A8F10
F00A8F00: 113c046f                 sethi   %hi(aMachKernelTrap), %o0! "mach_kernel_trap(): nargs = %d!\n"
F00A8F04: 90122058                 bset    %lo(aMachKernelTrap), %o0! "mach_kernel_trap(): nargs = %d!\n"
F00A8F08: 7ffdb09a                 call    _panic
F00A8F0C: 92100010                 mov     %l0, %o1
F00A8F10: d006202c                 ld      [%i0+0x2C], %o0
F00A8F14: d2062030                 ld      [%i0+0x30], %o1
F00A8F18: d4062034                 ld      [%i0+0x34], %o2
F00A8F1C: d6062038                 ld      [%i0+0x38], %o3
F00A8F20: d806203c                 ld      [%i0+0x3C], %o4
F00A8F24: c4056004                 ld      [%l5+4], %g2
F00A8F28: da062040                 ld      [%i0+0x40], %o5
F00A8F2C: 10800008                 ba      loc_F00A8F4C
F00A8F30: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F00A8F34: d006202c                 ld      [%i0+0x2C], %o0
F00A8F38: d2062030                 ld      [%i0+0x30], %o1
F00A8F3C: d4062034                 ld      [%i0+0x34], %o2
F00A8F40: d6062038                 ld      [%i0+0x38], %o3
F00A8F44: d806203c                 ld      [%i0+0x3C], %o4
F00A8F48: da062040                 ld      [%i0+0x40], %o5
F00A8F4C: c404e004                 ld      [%l3+4], %g2
F00A8F50: 9fc08000                 call    %g2
F00A8F54: 01000000                 nop
F00A8F58: d026202c                 st      %o0, [%i0+0x2C]
F00A8F5C: 80a4a000                 cmp     %l2, 0
F00A8F60: 02800049                 be      loc_F00A9084
F00A8F64: 113c04cf                 sethi   -0xFECC400, %o0
F00A8F68: d005218c                 ld      [%l4+0x18C], %o0
F00A8F6C: 808a2003                 btst    3, %o0
F00A8F70: 12800022                 bne     loc_F00A8FF8
F00A8F74: 80a4a000                 cmp     %l2, 0
F00A8F78: d04ca017                 ldsb    [%l2+0x17], %o0
F00A8F7C: 80a22000                 cmp     %o0, 0
F00A8F80: 12800014                 bne     loc_F00A8FD0
F00A8F84: 01000000                 nop
F00A8F88: d0052084                 ld      [%l4+0x84], %o0
F00A8F8C: d204a018                 ld      [%l2+0x18], %o1
F00A8F90: d002204c                 ld      [%o0+0x4C], %o0
F00A8F94: 94924008                 orcc    %o1, %o0, %o2
F00A8F98: 02800018                 be      loc_F00A8FF8
F00A8F9C: 80a4a000                 cmp     %l2, 0
F00A8FA0: d004a028                 ld      [%l2+0x28], %o0
F00A8FA4: 808a2010                 btst    0x10, %o0
F00A8FA8: 32800009                 bne,a   loc_F00A8FCC
F00A8FAC: d04ca017                 ldsb    [%l2+0x17], %o0
F00A8FB0: d004a020                 ld      [%l2+0x20], %o0
F00A8FB4: d204a01c                 ld      [%l2+0x1C], %o1
F00A8FB8: 90120009                 bset    %o1, %o0
F00A8FBC: 80aa8008                 andncc  %o2, %o0, %g0
F00A8FC0: 0280000e                 be      loc_F00A8FF8
F00A8FC4: 80a4a000                 cmp     %l2, 0
F00A8FC8: d04ca017                 ldsb    [%l2+0x17], %o0
F00A8FCC: 80a22000                 cmp     %o0, 0
F00A8FD0: 12800007                 bne     loc_F00A8FEC
F00A8FD4: 01000000                 nop
F00A8FD8: 7ffda276                 call    _issig
F00A8FDC: 90102000                 mov     0, %o0
F00A8FE0: 80a22000                 cmp     %o0, 0
F00A8FE4: 02800005                 be      loc_F00A8FF8
F00A8FE8: 80a4a000                 cmp     %l2, 0
F00A8FEC: 7ffda3d8                 call    _psig
F00A8FF0: 01000000                 nop
F00A8FF4: 80a4a000                 cmp     %l2, 0
F00A8FF8: 02800023                 be      loc_F00A9084
F00A8FFC: 113c04cf                 sethi   %hi(_active_u), %o0
F00A9000: e20221d8                 ld      [%o0+%lo(_active_u)], %l1
F00A9004: d0046258                 ld      [%l1+0x258], %o0
F00A9008: 80a22000                 cmp     %o0, 0
F00A900C: 0280001e                 be      loc_F00A9084
F00A9010: d607bff4                 ld      [%fp+var_C], %o3
F00A9014: d0046178                 ld      [%l1+0x178], %o0
F00A9018: d4046174                 ld      [%l1+0x174], %o2
F00A901C: 9022000b                 sub     %o0, %o3, %o0! int
F00A9020: d607bff0                 ld      [%fp+var_10], %o3
F00A9024: 921023e8                 mov     0x3E8, %o1! int
F00A9028: 9422800b                 sub     %o2, %o3, %o2
F00A902C: a12aa005                 sll     %o2, 5, %l0
F00A9030: a024000a                 sub     %l0, %o2, %l0
F00A9034: a12c2002                 sll     %l0, 2, %l0
F00A9038: a004000a                 add     %l0, %o2, %l0
F00A903C: 7ffd7573                 call    _div
F00A9040: a12c2003                 sll     %l0, 3, %l0
F00A9044: 921023e8                 mov     0x3E8, %o1! int
F00A9048: 153c043e                 sethi   %hi(_tick), %o2
F00A904C: 96100008                 mov     %o0, %o3
F00A9050: d402a3e4                 ld      [%o2+%lo(_tick)], %o2
F00A9054: a004000b                 add     %l0, %o3, %l0
F00A9058: 7ffd756c                 call    _div
F00A905C: 9010000a                 mov     %o2, %o0! int
F00A9060: 92100008                 mov     %o0, %o1! int
F00A9064: 7ffd7569                 call    _div
F00A9068: 90100010                 mov     %l0, %o0
F00A906C: 94920000                 orcc    %o0, %g0, %o2
F00A9070: 02800006                 be      loc_F00A9088
F00A9074: 113c04d2                 sethi   -0xFECB800, %o0
F00A9078: d0062004                 ld      [%i0+4], %o0
F00A907C: 7fffc357                 call    _addupc
F00A9080: 92046244                 add     %l1, 0x244, %o1
F00A9084: 113c04d2                 sethi   -0xFECB800, %o0
F00A9088: d00221b0                 ld      [%o0+0x1B0], %o0
F00A908C: d405204c                 ld      [%l4+0x4C], %o2
F00A9090: d202212c                 ld      [%o0+0x12C], %o1
F00A9094: d8022108                 ld      [%o0+0x108], %o4
F00A9098: c4022124                 ld      [%o0+0x124], %g2
F00A909C: da026108                 ld      [%o1+0x108], %o5
F00A90A0: d6026104                 ld      [%o1+0x104], %o3
F00A90A4: d0052060                 ld      [%l4+0x60], %o0
F00A90A8: 808aa002                 btst    2, %o2
F00A90AC: 12800020                 bne     loc_F00A912C
F00A90B0: d2052058                 ld      [%l4+0x58], %o1
F00A90B4: 80a32000                 cmp     %o4, 0
F00A90B8: 34800020                 bg,a    loc_F00A9138
F00A90BC: 90102001                 mov     1, %o0
F00A90C0: 80a22002                 cmp     %o0, 2
F00A90C4: 22800007                 be,a    loc_F00A90E0
F00A90C8: 80a36000                 cmp     %o5, 0
F00A90CC: 14800005                 bg      loc_F00A90E0
F00A90D0: 80a36000                 cmp     %o5, 0
F00A90D4: 80a22001                 cmp     %o0, 1
F00A90D8: 0280000d                 be      loc_F00A910C
F00A90DC: 80a36000                 cmp     %o5, 0
F00A90E0: 02800015                 be      loc_F00A9134
F00A90E4: 80a2c009                 cmp     %o3, %o1
F00A90E8: 06800014                 bl      loc_F00A9138
F00A90EC: 90102000                 mov     0, %o0
F00A90F0: 14800012                 bg      loc_F00A9138
F00A90F4: 90102001                 mov     1, %o0
F00A90F8: 80a0a000                 cmp     %g2, 0
F00A90FC: 1280000f                 bne     loc_F00A9138
F00A9100: 90102000                 mov     0, %o0
F00A9104: 1080000d                 ba      loc_F00A9138
F00A9108: 90102001                 mov     1, %o0
F00A910C: 80a0a000                 cmp     %g2, 0
F00A9110: 1280000a                 bne     loc_F00A9138
F00A9114: 90102000                 mov     0, %o0
F00A9118: 80a36000                 cmp     %o5, 0
F00A911C: 04800007                 ble     loc_F00A9138
F00A9120: 80a2c009                 cmp     %o3, %o1
F00A9124: 06800006                 bl      loc_F00A913C
F00A9128: 80a22000                 cmp     %o0, 0
F00A912C: 10800003                 ba      loc_F00A9138
F00A9130: 90102001                 mov     1, %o0
F00A9134: 90102000                 mov     0, %o0
F00A9138: 80a22000                 cmp     %o0, 0
F00A913C: 0280000b                 be      loc_F00A9168
F00A9140: 113c04cf                 sethi   %hi(_active_u), %o0
F00A9144: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F00A9148: 113c026f                 sethi   %hi(_thread_exception_return), %o0
F00A914C: d202a1b0                 ld      [%o2+0x1B0], %o1
F00A9150: 901223e4                 bset    %lo(_thread_exception_return), %o0
F00A9154: 92026001                 inc     %o1
F00A9158: 7fff217a                 call    _thread_block_with_continuation
F00A915C: d222a1b0                 st      %o1, [%o2+0x1B0]
F00A9160: 10bfff80                 ba      loc_F00A8F60
F00A9164: 80a4a000                 cmp     %l2, 0
F00A9168: 7fffcb9f                 call    _thread_exception_return
F00A916C: 01000000                 nop
F00A9170: 81c7e008                 ret
F00A9174: 81e80000                 restore
