F0016990: 9de3bf98                 save    %sp, -0x68, %sp
F0016994: 40020089                 call    _spltty
F0016998: 01000000                 nop
F001699C: d2062018                 ld      [%i0+0x18], %o1
F00169A0: a0100008                 mov     %o0, %l0
F00169A4: 10800017                 ba      loc_F0016A00
F00169A8: 80a26000                 cmp     %o1, 0
F00169AC: 808a2010                 btst    0x10, %o0
F00169B0: 3280000a                 bne,a   loc_F00169D8
F00169B4: d2062024                 ld      [%i0+0x24], %o1
F00169B8: 400011cc                 call    _ttynty
F00169BC: 90100018                 mov     %i0, %o0
F00169C0: d2022010                 ld      [%o0+0x10], %o1
F00169C4: 11000020                 sethi   0x8000, %o0
F00169C8: 808a4008                 btst    %o0, %o1
F00169CC: 02800015                 be      loc_F0016A20
F00169D0: 01000000                 nop
F00169D4: d2062024                 ld      [%i0+0x24], %o1
F00169D8: 9fc24000                 call    %o1
F00169DC: 90100018                 mov     %i0, %o0
F00169E0: d2062040                 ld      [%i0+0x40], %o1
F00169E4: 90062018                 add     %i0, 0x18, %o0! unsigned int
F00169E8: 92126040                 bset    0x40, %o1 ! '@'
F00169EC: d2262040                 st      %o1, [%i0+0x40]
F00169F0: 7fffef22                 call    _sleep
F00169F4: 9210201d                 mov     0x1D, %o1
F00169F8: d0062018                 ld      [%i0+0x18], %o0
F00169FC: 80a22000                 cmp     %o0, 0
F0016A00: 32bfffeb                 bne,a   loc_F00169AC
F0016A04: d0062040                 ld      [%i0+0x40], %o0
F0016A08: d2062040                 ld      [%i0+0x40], %o1
F0016A0C: 1100800090122020         set     0x2000020, %o0
F0016A14: 808a4008                 btst    %o0, %o1
F0016A18: 32bfffe5                 bne,a   loc_F00169AC
F0016A1C: d0062040                 ld      [%i0+0x40], %o0
F0016A20: 400200c1                 call    _splx
F0016A24: 90100010                 mov     %l0, %o0
F0016A28: 81c7e008                 ret
F0016A2C: 81e80000                 restore
