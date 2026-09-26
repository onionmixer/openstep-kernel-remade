F000CF20: 9de3bf98                 save    %sp, -0x68, %sp
F000CF24: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F000CF28: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F000CF2C: d04a6038                 ldsb    [%o1+0x38], %o0
F000CF30: 80a22000                 cmp     %o0, 0
F000CF34: 1680001c                 bge     loc_F000CFA4
F000CF38: a01461dc                 or      %l1, %lo(dword_F0133DDC), %l0
F000CF3C: 400195db                 call    _thread_wait_result
F000CF40: 01000000                 nop
F000CF44: 90023ffe                 inc     -2, %o0
F000CF48: 80a22001                 cmp     %o0, 1
F000CF4C: 18800014                 bgu     loc_F000CF9C
F000CF50: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F000CF54: d0043ffc                 ld      [%l0-4], %o0
F000CF58: e0020000                 ld      [%o0], %l0
F000CF5C: d24c2017                 ldsb    [%l0+0x17], %o1
F000CF60: d002213c                 ld      [%o0+0x13C], %o0
F000CF64: 92027fff                 inc     -1, %o1
F000CF68: 913a0009                 sra     %o0, %o1, %o0
F000CF6C: 808a2001                 btst    1, %o0
F000CF70: 02800005                 be      loc_F000CF84
F000CF74: 90102000                 mov     0, %o0
F000CF78: 40026ef7                 call    _unix_syscall_return
F000CF7C: 90102004                 mov     4, %o0
F000CF80: 90102000                 mov     0, %o0
F000CF84: d40461dc                 ld      [%l1+0x1DC], %o2
F000CF88: 92102002                 mov     2, %o1
F000CF8C: 40026ef2                 call    _unix_syscall_return
F000CF90: d22aa039                 stb     %o1, [%o2+0x39]
F000CF94: 10800006                 ba      loc_F000CFAC
F000CF98: 113c04cf                 sethi   -0xFECC400, %o0
F000CF9C: 10800003                 ba      loc_F000CFA8
F000CFA0: c02a2038                 clrb    [%o0+0x38]
F000CFA4: c0226058                 clr     [%o1+0x58]
F000CFA8: 113c04cf                 sethi   -0xFECC400, %o0
F000CFAC: d00221d8                 ld      [%o0+0x1D8], %o0
F000CFB0: d4020000                 ld      [%o0], %o2
F000CFB4: e002a048                 ld      [%o2+0x48], %l0
F000CFB8: 80a42000                 cmp     %l0, 0
F000CFBC: 2280007f                 be,a    loc_F000D1B8
F000CFC0: d402a080                 ld      [%o2+0x80], %o2! __n
F000CFC4: 173c04cf                 sethi   -0xFECC400, %o3
F000CFC8: 233c04d2                 sethi   -0xFECB800, %l1
F000CFCC: 80a6e000                 cmp     %i3, 0
F000CFD0: 02800007                 be      loc_F000CFEC
F000CFD4: d202e1dc                 ld      [%o3+0x1DC], %o1
F000CFD8: d0542030                 ldsh    [%l0+0x30], %o0
F000CFDC: 80a6c008                 cmp     %i3, %o0
F000CFE0: 32800072                 bne,a   loc_F000D1A8
F000CFE4: e004204c                 ld      [%l0+0x4C], %l0
F000CFE8: d202e1dc                 ld      [%o3+0x1DC], %o1
F000CFEC: d0026058                 ld      [%o1+0x58], %o0
F000CFF0: 90022001                 inc     %o0
F000CFF4: d0226058                 st      %o0, [%o1+0x58]
F000CFF8: d0042068                 ld      [%l0+0x68], %o0
F000CFFC: 80a22000                 cmp     %o0, 0
F000D000: 32800052                 bne,a   loc_F000D148
F000D004: d0022044                 ld      [%o0+0x44], %o0
F000D008: d004207c                 ld      [%l0+0x7C], %o0
F000D00C: 80a22000                 cmp     %o0, 0
F000D010: 02800004                 be      loc_F000D020
F000D014: 80a2000a                 cmp     %o0, %o2
F000D018: 32800064                 bne,a   loc_F000D1A8
F000D01C: e004204c                 ld      [%l0+0x4C], %l0
F000D020: d002e1dc                 ld      [%o3+0x1DC], %o0
F000D024: d2542030                 ldsh    [%l0+0x30], %o1
F000D028: d2222030                 st      %o1, [%o0+0x30]
F000D02C: d0142034                 lduh    [%l0+0x34], %o0
F000D030: 80a66000                 cmp     %i1, 0
F000D034: d0268000                 st      %o0, [%i2]
F000D038: 02800008                 be      loc_F000D058
F000D03C: c0342034                 clrh    [%l0+0x34]
F000D040: d2042038                 ld      [%l0+0x38], %o1! __src
F000D044: 80a26000                 cmp     %o1, 0
F000D048: 02800006                 be      loc_F000D060
F000D04C: 90100019                 mov     %i1, %o0! __dst
F000D050: 7fffe894                 call    _memcpy
F000D054: 94102048                 mov     0x48, %o2 ! 'H'
F000D058: d2042038                 ld      [%l0+0x38], %o1
F000D05C: 80a26000                 cmp     %o1, 0
F000D060: 02800009                 be      loc_F000D084
F000D064: 113c04cf                 sethi   %hi(_active_u), %o0
F000D068: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000D06C: 40000cea                 call    _ruadd
F000D070: 900221b4                 inc     0x1B4, %o0
F000D074: d0042038                 ld      [%l0+0x38], %o0
F000D078: 40016c4a                 call    _kfree
F000D07C: 92102048                 mov     0x48, %o1 ! 'H'
F000D080: c0242038                 clr     [%l0+0x38]
F000D084: 400005ec                 call    _leavepgrp
F000D088: 90100010                 mov     %l0, %o0
F000D08C: 4000070d                 call    _delete_posix_proc
F000D090: 90100010                 mov     %l0, %o0
F000D094: c02c2013                 clrb    [%l0+0x13]
F000D098: d204200c                 ld      [%l0+0xC], %o1
F000D09C: c0342030                 clrh    [%l0+0x30]
F000D0A0: d0042008                 ld      [%l0+8], %o0
F000D0A4: c0342032                 clrh    [%l0+0x32]
F000D0A8: 80a22000                 cmp     %o0, 0
F000D0AC: 02800005                 be      loc_F000D0C0
F000D0B0: d0224000                 st      %o0, [%o1]
F000D0B4: d2042008                 ld      [%l0+8], %o1
F000D0B8: d004200c                 ld      [%l0+0xC], %o0
F000D0BC: d022600c                 st      %o0, [%o1+0xC]
F000D0C0: d00462e0                 ld      [%l1+0x2E0], %o0
F000D0C4: d2042050                 ld      [%l0+0x50], %o1
F000D0C8: d0242008                 st      %o0, [%l0+8]
F000D0CC: 80a26000                 cmp     %o1, 0
F000D0D0: 02800004                 be      loc_F000D0E0
F000D0D4: e02462e0                 st      %l0, [%l1+0x2E0]
F000D0D8: d004204c                 ld      [%l0+0x4C], %o0
F000D0DC: d022604c                 st      %o0, [%o1+0x4C]
F000D0E0: d204204c                 ld      [%l0+0x4C], %o1
F000D0E4: 80a26000                 cmp     %o1, 0
F000D0E8: 22800005                 be,a    loc_F000D0FC
F000D0EC: d2042044                 ld      [%l0+0x44], %o1
F000D0F0: d0042050                 ld      [%l0+0x50], %o0
F000D0F4: d0226050                 st      %o0, [%o1+0x50]
F000D0F8: d2042044                 ld      [%l0+0x44], %o1
F000D0FC: d0026048                 ld      [%o1+0x48], %o0
F000D100: 80a20010                 cmp     %o0, %l0
F000D104: 32800005                 bne,a   loc_F000D118
F000D108: c0242044                 clr     [%l0+0x44]
F000D10C: d004204c                 ld      [%l0+0x4C], %o0
F000D110: d0226048                 st      %o0, [%o1+0x48]
F000D114: c0242044                 clr     [%l0+0x44]
F000D118: c0242050                 clr     [%l0+0x50]
F000D11C: c024204c                 clr     [%l0+0x4C]
F000D120: c0242048                 clr     [%l0+0x48]
F000D124: c0242018                 clr     [%l0+0x18]
F000D128: c0242024                 clr     [%l0+0x24]
F000D12C: c0242020                 clr     [%l0+0x20]
F000D130: c024201c                 clr     [%l0+0x1C]
F000D134: c034202e                 clrh    [%l0+0x2E]
F000D138: c0242028                 clr     [%l0+0x28]
F000D13C: c02c2017                 clrb    [%l0+0x17]
F000D140: 10800065                 ba      locret_F000D2D4
F000D144: b0102000                 mov     0, %i0
F000D148: 80a22000                 cmp     %o0, 0
F000D14C: 24800017                 ble,a   loc_F000D1A8
F000D150: e004204c                 ld      [%l0+0x4C], %l0
F000D154: d04c2013                 ldsb    [%l0+0x13], %o0
F000D158: 80a22006                 cmp     %o0, 6
F000D15C: 32800013                 bne,a   loc_F000D1A8
F000D160: e004204c                 ld      [%l0+0x4C], %l0
F000D164: d0042028                 ld      [%l0+0x28], %o0
F000D168: 808a2020                 btst    0x20, %o0 ! ' '
F000D16C: 3280000f                 bne,a   loc_F000D1A8
F000D170: e004204c                 ld      [%l0+0x4C], %l0
F000D174: 808a2010                 btst    0x10, %o0
F000D178: 32800006                 bne,a   loc_F000D190
F000D17C: d204207c                 ld      [%l0+0x7C], %o1
F000D180: 808e2002                 btst    2, %i0
F000D184: 22800009                 be,a    loc_F000D1A8
F000D188: e004204c                 ld      [%l0+0x4C], %l0
F000D18C: d204207c                 ld      [%l0+0x7C], %o1
F000D190: 80a26000                 cmp     %o1, 0
F000D194: 0280002e                 be      loc_F000D24C
F000D198: 80a2400a                 cmp     %o1, %o2
F000D19C: 2280002d                 be,a    loc_F000D250
F000D1A0: 90122020                 bset    0x20, %o0 ! ' '
F000D1A4: e004204c                 ld      [%l0+0x4C], %l0
F000D1A8: 80a42000                 cmp     %l0, 0
F000D1AC: 12bfff89                 bne     loc_F000CFD0
F000D1B0: 80a6e000                 cmp     %i3, 0
F000D1B4: d402a080                 ld      [%o2+0x80], %o2
F000D1B8: 80a2a000                 cmp     %o2, 0
F000D1BC: 02800032                 be      loc_F000D284
F000D1C0: 173c04cf                 sethi   %hi(dword_F0133DDC), %o3
F000D1C4: d202e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o1
F000D1C8: d0026058                 ld      [%o1+0x58], %o0
F000D1CC: a010000a                 mov     %o2, %l0
F000D1D0: 90022001                 inc     %o0
F000D1D4: d0226058                 st      %o0, [%o1+0x58]
F000D1D8: d0042068                 ld      [%l0+0x68], %o0
F000D1DC: 80a22000                 cmp     %o0, 0
F000D1E0: 3280000a                 bne,a   loc_F000D208
F000D1E4: d0022044                 ld      [%o0+0x44], %o0
F000D1E8: d2042028                 ld      [%l0+0x28], %o1
F000D1EC: c024207c                 clr     [%l0+0x7C]
F000D1F0: d0042044                 ld      [%l0+0x44], %o0
F000D1F4: 920a7fef                 and     %o1, -0x11, %o1
F000D1F8: 400016fc                 call    _wakeup
F000D1FC: d2242028                 st      %o1, [%l0+0x28]
F000D200: 10800035                 ba      locret_F000D2D4
F000D204: b0102000                 mov     0, %i0
F000D208: 80a22000                 cmp     %o0, 0
F000D20C: 0480001f                 ble     loc_F000D288
F000D210: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000D214: d04c2013                 ldsb    [%l0+0x13], %o0
F000D218: 80a22006                 cmp     %o0, 6
F000D21C: 1280001c                 bne     loc_F000D28C
F000D220: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F000D224: d0042028                 ld      [%l0+0x28], %o0
F000D228: 808a2020                 btst    0x20, %o0 ! ' '
F000D22C: 32800019                 bne,a   loc_F000D290
F000D230: d002a058                 ld      [%o2+0x58], %o0
F000D234: 808a2010                 btst    0x10, %o0
F000D238: 32800006                 bne,a   loc_F000D250
F000D23C: 90122020                 bset    0x20, %o0 ! ' '
F000D240: 808e2002                 btst    2, %i0
F000D244: 22800013                 be,a    loc_F000D290
F000D248: d002a058                 ld      [%o2+0x58], %o0
F000D24C: 90122020                 bset    0x20, %o0 ! ' '
F000D250: d0242028                 st      %o0, [%l0+0x28]
F000D254: d202e1dc                 ld      [%o3+0x1DC], %o1
F000D258: d0542030                 ldsh    [%l0+0x30], %o0
F000D25C: d0226030                 st      %o0, [%o1+0x30]
F000D260: d04c2017                 ldsb    [%l0+0x17], %o0
F000D264: 80a22000                 cmp     %o0, 0
F000D268: 22800002                 be,a    loc_F000D270
F000D26C: d004203c                 ld      [%l0+0x3C], %o0
F000D270: 912a2008                 sll     %o0, 8, %o0
F000D274: 9012207f                 bset    0x7F, %o0
F000D278: d0268000                 st      %o0, [%i2]
F000D27C: 10800016                 ba      locret_F000D2D4
F000D280: b0102000                 mov     0, %i0
F000D284: 133c04cf                 sethi   -0xFECC400, %o1
F000D288: d40261dc                 ld      [%o1+0x1DC], %o2
F000D28C: d002a058                 ld      [%o2+0x58], %o0
F000D290: 80a22000                 cmp     %o0, 0
F000D294: 12800004                 bne     loc_F000D2A4
F000D298: 921261dc                 bset    0x1DC, %o1
F000D29C: 1080000e                 ba      locret_F000D2D4
F000D2A0: b010200a                 mov     0xA, %i0
F000D2A4: 808e2001                 btst    1, %i0
F000D2A8: 02800004                 be      loc_F000D2B8
F000D2AC: b0102000                 mov     0, %i0
F000D2B0: 10800009                 ba      locret_F000D2D4
F000D2B4: c022a030                 clr     [%o2+0x30]
F000D2B8: 90103fff                 mov     -1, %o0
F000D2BC: d02aa038                 stb     %o0, [%o2+0x38]
F000D2C0: d0027ffc                 ld      [%o1-4], %o0
F000D2C4: 9410001c                 mov     %i4, %o2
F000D2C8: d0020000                 ld      [%o0], %o0
F000D2CC: 4000156b                 call    _sleep_with_continuation
F000D2D0: 9210201e                 mov     0x1E, %o1
F000D2D4: 81c7e008                 ret
F000D2D8: 81e80000                 restore
