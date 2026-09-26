F0076D54: 9de3bf98                 save    %sp, -0x68, %sp
F0076D58: 40007f8c                 call    _splusclock
F0076D5C: 01000000                 nop
F0076D60: a2100008                 mov     %o0, %l1
F0076D64: 113c04c3a0122320         set     dword_F0130F20, %l0
F0076D6C: d0040000                 ld      [%l0], %o0
F0076D70: 80a22000                 cmp     %o0, 0
F0076D74: 12bffffe                 bne     loc_F0076D6C
F0076D78: 01000000                 nop
F0076D7C: 4000804b                 call    _simple_lock_try
F0076D80: 90100010                 mov     %l0, %o0
F0076D84: 80a22000                 cmp     %o0, 0
F0076D88: 02bffff9                 be      loc_F0076D6C
F0076D8C: 90100018                 mov     %i0, %o0
F0076D90: 92100019                 mov     %i1, %o1
F0076D94: 7ffffe91                 call    sub_F00767D8
F0076D98: 94102000                 mov     0, %o2
F0076D9C: 80a22000                 cmp     %o0, 0
F0076DA0: 32800007                 bne,a   loc_F0076DBC
F0076DA4: 113c04c3                 sethi   -0xFECF400, %o0
F0076DA8: 90100018                 mov     %i0, %o0
F0076DAC: 92100019                 mov     %i1, %o1
F0076DB0: 7ffffebe                 call    sub_F00768A8
F0076DB4: 94102000                 mov     0, %o2
F0076DB8: 113c04c3                 sethi   -0xFECF400, %o0
F0076DBC: c0222320                 clr     [%o0+0x320]
F0076DC0: 40007fd9                 call    _splx
F0076DC4: 90100011                 mov     %l1, %o0
F0076DC8: 81c7e008                 ret
F0076DCC: 81e80000                 restore
