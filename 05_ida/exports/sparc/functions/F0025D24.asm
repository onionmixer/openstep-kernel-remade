F0025D24: 9de3bf98                 save    %sp, -0x68, %sp
F0025D28: 233c04d5                 sethi   %hi(dword_F01355D8), %l1
F0025D2C: 113c04d5a01221d0         set     _nc_lru, %l0
F0025D34: d20461d8                 ld      [%l1+%lo(dword_F01355D8)], %o1
F0025D38: 80a24010                 cmp     %o1, %l0
F0025D3C: 02800013                 be      loc_F0025D88
F0025D40: 94102000                 mov     0, %o2
F0025D44: 113c04d5961221d0         set     _nc_lru, %o3
F0025D4C: d0026014                 ld      [%o1+0x14], %o0
F0025D50: 80a20018                 cmp     %o0, %i0
F0025D54: 02800006                 be      loc_F0025D6C
F0025D58: 01000000                 nop
F0025D5C: d0026010                 ld      [%o1+0x10], %o0
F0025D60: 80a20018                 cmp     %o0, %i0
F0025D64: 32800006                 bne,a   loc_F0025D7C
F0025D68: d2026008                 ld      [%o1+8], %o1
F0025D6C: 40000023                 call    sub_F0025DF8
F0025D70: 90100009                 mov     %o1, %o0
F0025D74: 10800005                 ba      loc_F0025D88
F0025D78: 94102001                 mov     1, %o2
F0025D7C: 80a2400b                 cmp     %o1, %o3
F0025D80: 32bffff4                 bne,a   loc_F0025D50
F0025D84: d0026014                 ld      [%o1+0x14], %o0
F0025D88: 80a2a000                 cmp     %o2, 0
F0025D8C: 12bfffeb                 bne     loc_F0025D38
F0025D90: d20461d8                 ld      [%l1+0x1D8], %o1
F0025D94: 81c7e008                 ret
F0025D98: 81e80000                 restore
