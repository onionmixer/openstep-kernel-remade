F0032954: 9de3bf98                 save    %sp, -0x68, %sp
F0032958: 133c04d9                 sethi   %hi(_ipq), %o1
F003295C: d00260b0                 ld      [%o1+%lo(_ipq)], %o0
F0032960: 941260b0                 or      %o1, %lo(_ipq), %o2
F0032964: 80a2000a                 cmp     %o0, %o2
F0032968: 0280000e                 be      locret_F00329A0
F003296C: 113c04d9                 sethi   %hi(_ipstat), %o0
F0032970: a21220d0                 or      %o0, %lo(_ipstat), %l1
F0032974: a0100009                 mov     %o1, %l0
F0032978: a410000a                 mov     %o2, %l2
F003297C: d204601c                 ld      [%l1+0x1C], %o1
F0032980: d00420b0                 ld      [%l0+0xB0], %o0
F0032984: 92026001                 inc     %o1
F0032988: 7fffffa5                 call    _ip_freef
F003298C: d224601c                 st      %o1, [%l1+0x1C]
F0032990: d00420b0                 ld      [%l0+0xB0], %o0
F0032994: 80a20012                 cmp     %o0, %l2
F0032998: 32bffffb                 bne,a   loc_F0032984
F003299C: d204601c                 ld      [%l1+0x1C], %o1
F00329A0: 81c7e008                 ret
F00329A4: 81e80000                 restore
