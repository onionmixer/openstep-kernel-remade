F0098CEC: 9de3bf68                 save    %sp, -0x98, %sp
F0098CF0: 233c04d0                 sethi   %hi(_active_threads), %l1
F0098CF4: d0046260                 ld      [%l1+%lo(_active_threads)], %o0
F0098CF8: d0022028                 ld      [%o0+0x28], %o0
F0098CFC: e0022284                 ld      [%o0+0x284], %l0
F0098D00: 80a42000                 cmp     %l0, 0
F0098D04: 12800009                 bne     loc_F0098D28
F0098D08: 113c044d                 sethi   -0xFEECC00, %o0
F0098D0C: 7fffff69                 call    _fpu_ctxalloc
F0098D10: 01000000                 nop
F0098D14: d2046260                 ld      [%l1+%lo(_active_threads)], %o1
F0098D18: d2026028                 ld      [%o1+0x28], %o1
F0098D1C: a0100008                 mov     %o0, %l0
F0098D20: e0226284                 st      %l0, [%o1+0x284]
F0098D24: 113c044d                 sethi   -0xFEECC00, %o0
F0098D28: 133c044a                 sethi   %hi(_fpu_exists), %o1
F0098D2C: d20260c8                 ld      [%o1+%lo(_fpu_exists)], %o1
F0098D30: 80a26000                 cmp     %o1, 0
F0098D34: 0280000f                 be      loc_F0098D70
F0098D38: e0222078                 st      %l0, [%o0+0x78]
F0098D3C: d0060000                 ld      [%i0], %o0
F0098D40: 13000004                 sethi   0x1000, %o1
F0098D44: 808a0009                 btst    %o1, %o0
F0098D48: 02800006                 be      loc_F0098D60
F0098D4C: 90120009                 bset    %o1, %o0
F0098D50: 113c044d                 sethi   %hi(aFpDisabledNoFp), %o0! "fp_disabled: no FPU but EF bit set"
F0098D54: 7ffdf107                 call    _panic
F0098D58: 901220c0                 bset    %lo(aFpDisabledNoFp), %o0! "fp_disabled: no FPU but EF bit set"
F0098D5C: 30800013                 ba,a    locret_F0098DA8
F0098D60: d0260000                 st      %o0, [%i0]
F0098D64: 7ffff131                 call    _fp_enable
F0098D68: 90100010                 mov     %l0, %o0
F0098D6C: 3080000f                 ba,a    locret_F0098DA8
F0098D70: 400033b2                 call    _flush_user_windows_to_stack
F0098D74: 01000000                 nop
F0098D78: a207bfc8                 add     %fp, var_38, %l1
F0098D7C: 90100011                 mov     %l1, %o0
F0098D80: d2062004                 ld      [%i0+4], %o1
F0098D84: 94100018                 mov     %i0, %o2
F0098D88: d6062044                 ld      [%i0+0x44], %o3
F0098D8C: 40004f06                 call    _fp_emulator
F0098D90: 98100010                 mov     %l0, %o4
F0098D94: 92920000                 orcc    %o0, %g0, %o1
F0098D98: 02800004                 be      locret_F0098DA8
F0098D9C: 90100011                 mov     %l1, %o0
F0098DA0: 7fffffa2                 call    _fp_traps
F0098DA4: 94100018                 mov     %i0, %o2
F0098DA8: 81c7e008                 ret
F0098DAC: 81e80000                 restore
