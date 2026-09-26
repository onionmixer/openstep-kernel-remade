F00ECE2C: 9de3bf98                 save    %sp, -0x68, %sp
F00ECE30: 7ffe257c                 call    _current_thread_EXTERNAL
F00ECE34: 01000000                 nop
F00ECE38: 94100008                 mov     %o0, %o2
F00ECE3C: 113c04bc92122048         set     unk_F012F048, %o1
F00ECE44: 80a26000                 cmp     %o1, 0
F00ECE48: 0280000b                 be      loc_F00ECE74
F00ECE4C: 01000000                 nop
F00ECE50: d0026010                 ld      [%o1+0x10], %o0
F00ECE54: 80a2000a                 cmp     %o0, %o2
F00ECE58: 32800004                 bne,a   loc_F00ECE68
F00ECE5C: d2026014                 ld      [%o1+0x14], %o1
F00ECE60: 10800008                 ba      loc_F00ECE80
F00ECE64: a0100009                 mov     %o1, %l0
F00ECE68: 80a26000                 cmp     %o1, 0
F00ECE6C: 32bffffa                 bne,a   loc_F00ECE54
F00ECE70: d0026010                 ld      [%o1+0x10], %o0
F00ECE74: 7ffffe81                 call    sub_F00EC878
F00ECE78: 9010000a                 mov     %o2, %o0
F00ECE7C: a0100008                 mov     %o0, %l0
F00ECE80: d2040000                 ld      [%l0], %o1
F00ECE84: 80a26000                 cmp     %o1, 0
F00ECE88: 1280000f                 bne     loc_F00ECEC4
F00ECE8C: 808a6001                 btst    1, %o1
F00ECE90: 113c04fe                 sethi   %hi(__NXUncaughtExceptionHandler), %o0
F00ECE94: d60223f8                 ld      [%o0+%lo(__NXUncaughtExceptionHandler)], %o3
F00ECE98: 80a2e000                 cmp     %o3, 0
F00ECE9C: 02800005                 be      loc_F00ECEB0
F00ECEA0: 90100018                 mov     %i0, %o0
F00ECEA4: 92100019                 mov     %i1, %o1
F00ECEA8: 9fc2c000                 call    %o3
F00ECEAC: 9410001a                 mov     %i2, %o2
F00ECEB0: 113c03f3                 sethi   %hi(aUncaughtExcept), %o0! "Uncaught exception"
F00ECEB4: 7ffca0af                 call    _panic
F00ECEB8: 90122228                 bset    %lo(aUncaughtExcept), %o0! "Uncaught exception"
F00ECEBC: 10bffff2                 ba      loc_F00ECE84
F00ECEC0: d2040000                 ld      [%l0], %o1
F00ECEC4: 02800021                 be      loc_F00ECF48
F00ECEC8: 90027fff                 add     %o1, -1, %o0
F00ECECC: 9332201f                 srl     %o0, 31, %o1
F00ECED0: 90020009                 add     %o0, %o1, %o0
F00ECED4: 913a2001                 sra     %o0, 1, %o0
F00ECED8: 932a2001                 sll     %o0, 1, %o1
F00ECEDC: 92024008                 add     %o1, %o0, %o1
F00ECEE0: 932a6002                 sll     %o1, 2, %o1
F00ECEE4: d0042004                 ld      [%l0+4], %o0
F00ECEE8: 94024008                 add     %o1, %o0, %o2
F00ECEEC: d0024008                 ld      [%o1+%o0], %o0
F00ECEF0: d0240000                 st      %o0, [%l0]
F00ECEF4: d2042004                 ld      [%l0+4], %o1
F00ECEF8: 92228009                 sub     %o2, %o1, %o1
F00ECEFC: 912a6002                 sll     %o1, 2, %o0
F00ECF00: 90020009                 add     %o0, %o1, %o0
F00ECF04: 932a2004                 sll     %o0, 4, %o1
F00ECF08: 90020009                 add     %o0, %o1, %o0
F00ECF0C: 932a2008                 sll     %o0, 8, %o1
F00ECF10: 90020009                 add     %o0, %o1, %o0
F00ECF14: 932a2010                 sll     %o0, 16, %o1
F00ECF18: 90020009                 add     %o0, %o1, %o0
F00ECF1C: 90200008                 neg     %o0
F00ECF20: 913a2002                 sra     %o0, 2, %o0
F00ECF24: d024200c                 st      %o0, [%l0+0xC]
F00ECF28: d802a004                 ld      [%o2+4], %o4
F00ECF2C: d002a008                 ld      [%o2+8], %o0
F00ECF30: 92100018                 mov     %i0, %o1
F00ECF34: 94100019                 mov     %i1, %o2
F00ECF38: 9fc30000                 call    %o4
F00ECF3C: 9610001a                 mov     %i2, %o3
F00ECF40: 10bfffd1                 ba      loc_F00ECE84
F00ECF44: d2040000                 ld      [%l0], %o1! int
F00ECF48: f0226078                 st      %i0, [%o1+0x78]
F00ECF4C: f222607c                 st      %i1, [%o1+0x7C]
F00ECF50: f4226080                 st      %i2, [%o1+0x80]
F00ECF54: d0026074                 ld      [%o1+0x74], %o0
F00ECF58: d0240000                 st      %o0, [%l0]
F00ECF5C: 90100009                 mov     %o1, %o0! jmp_buf
F00ECF60: 7ffea781                 call    _longjmp
