F0032D14: 9de3bf98                 save    %sp, -0x68, %sp
F0032D18: 113c04d9a0122324         set     unk_F0136724, %l0
F0032D20: d2043ffc                 ld      [%l0-4], %o1
F0032D24: 80a26000                 cmp     %o1, 0
F0032D28: 02800007                 be      loc_F0032D44
F0032D2C: f0060000                 ld      [%i0], %i0
F0032D30: d0042004                 ld      [%l0+4], %o0
F0032D34: 80a60008                 cmp     %i0, %o0
F0032D38: 02800017                 be      loc_F0032D94
F0032D3C: 113c04d9                 sethi   -0xFEC9C00, %o0
F0032D40: 80a26000                 cmp     %o1, 0
F0032D44: 0280000e                 be      loc_F0032D7C
F0032D48: 90102002                 mov     2, %o0
F0032D4C: d0526026                 ldsh    [%o1+0x26], %o0
F0032D50: 80a22001                 cmp     %o0, 1
F0032D54: 32800006                 bne,a   loc_F0032D6C
F0032D58: 90023fff                 inc     -1, %o0
F0032D5C: 7fffe832                 call    _rtfree
F0032D60: 90100009                 mov     %o1, %o0
F0032D64: 10800004                 ba      loc_F0032D74
F0032D68: 113c04d9                 sethi   -0xFEC9C00, %o0
F0032D6C: d0326026                 sth     %o0, [%o1+0x26]
F0032D70: 113c04d9                 sethi   -0xFEC9C00, %o0
F0032D74: c0222320                 clr     [%o0+0x320]
F0032D78: 90102002                 mov     2, %o0
F0032D7C: d0340000                 sth     %o0, [%l0]
F0032D80: f0242004                 st      %i0, [%l0+4]
F0032D84: 113c04d9                 sethi   %hi(_ipforward_rt), %o0
F0032D88: 7fffe7b4                 call    _rtalloc
F0032D8C: 90122320                 bset    %lo(_ipforward_rt), %o0
F0032D90: 113c04d9                 sethi   -0xFEC9C00, %o0
F0032D94: d2022320                 ld      [%o0+0x320], %o1
F0032D98: 80a26000                 cmp     %o1, 0
F0032D9C: 12800004                 bne     loc_F0032DAC
F0032DA0: 113c04d9                 sethi   -0xFEC9C00, %o0
F0032DA4: 1080000f                 ba      locret_F0032DE0
F0032DA8: b0102000                 mov     0, %i0
F0032DAC: f0022070                 ld      [%o0+0x70], %i0
F0032DB0: 80a62000                 cmp     %i0, 0
F0032DB4: 0280000b                 be      locret_F0032DE0
F0032DB8: 01000000                 nop
F0032DBC: d202602c                 ld      [%o1+0x2C], %o1
F0032DC0: d0062020                 ld      [%i0+0x20], %o0
F0032DC4: 80a20009                 cmp     %o0, %o1
F0032DC8: 02800006                 be      locret_F0032DE0
F0032DCC: 01000000                 nop
F0032DD0: f0062040                 ld      [%i0+0x40], %i0
F0032DD4: 80a62000                 cmp     %i0, 0
F0032DD8: 32bffffb                 bne,a   loc_F0032DC4
F0032DDC: d0062020                 ld      [%i0+0x20], %o0
F0032DE0: 81c7e008                 ret
F0032DE4: 81e80000                 restore
