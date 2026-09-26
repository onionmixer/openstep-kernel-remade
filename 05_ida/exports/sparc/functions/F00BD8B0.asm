F00BD8B0: 9de3bf98                 save    %sp, -0x68, %sp
F00BD8B4: d0562002                 ldsh    [%i0+2], %o0
F00BD8B8: a6102000                 mov     0, %l3
F00BD8BC: 80a4c008                 cmp     %l3, %o0
F00BD8C0: 1680004e                 bge     loc_F00BD9F8
F00BD8C4: 173c04cb                 sethi   -0xFECD400, %o3
F00BD8C8: 2f3c04cb                 sethi   -0xFECD400, %l7
F00BD8CC: 2d3c0481                 sethi   -0xFEDFC00, %l6
F00BD8D0: 2b3c04cb                 sethi   -0xFECD400, %l5
F00BD8D4: 293c04cb                 sethi   -0xFECD400, %l4
F00BD8D8: d0560000                 ldsh    [%i0], %o0
F00BD8DC: 1080003e                 ba      loc_F00BD9D4
F00BD8E0: a4102000                 mov     0, %l2
F00BD8E4: 932a6010                 sll     %o1, 16, %o1
F00BD8E8: d0562002                 ldsh    [%i0+2], %o0
F00BD8EC: 933a6010                 sra     %o1, 16, %o1
F00BD8F0: 90220013                 sub     %o0, %l3, %o0
F00BD8F4: 7ffd2303                 call    _umul
F00BD8F8: 90023fff                 inc     -1, %o0
F00BD8FC: d206200c                 ld      [%i0+0xC], %o1
F00BD900: 92024008                 add     %o1, %o0, %o1
F00BD904: 92024012                 add     %o1, %l2, %o1
F00BD908: 113c0481                 sethi   %hi(off_F012054C), %o0
F00BD90C: d002214c                 ld      [%o0+%lo(off_F012054C)], %o0
F00BD910: 953a6003                 sra     %o1, 3, %o2
F00BD914: d0022610                 ld      [%o0+0x610], %o0
F00BD918: 92380009                 xnor    %g0, %o1, %o1
F00BD91C: d00a000a                 ldub    [%o0+%o2], %o0
F00BD920: 920a6007                 and     %o1, 7, %o1
F00BD924: 913a0009                 sra     %o0, %o1, %o0
F00BD928: 808a2001                 btst    1, %o0
F00BD92C: 22800029                 be,a    loc_F00BD9D0
F00BD930: d0560000                 ldsh    [%i0], %o0
F00BD934: 113c04cb                 sethi   %hi(dword_F0132F20), %o0
F00BD938: d2022320                 ld      [%o0+%lo(dword_F0132F20)], %o1
F00BD93C: d6562004                 ldsh    [%i0+4], %o3
F00BD940: 113c04cb                 sethi   %hi(dword_F0132F30), %o0
F00BD944: e0022330                 ld      [%o0+%lo(dword_F0132F30)], %l0
F00BD948: a2102003                 mov     3, %l1
F00BD94C: d4562006                 ldsh    [%i0+6], %o2
F00BD950: a004000b                 add     %l0, %o3, %l0
F00BD954: d005e334                 ld      [%l7+0x334], %o0
F00BD958: a0040012                 add     %l0, %l2, %l0
F00BD95C: 9022000a                 sub     %o0, %o2, %o0
F00BD960: 7ffd22e8                 call    _umul
F00BD964: 90220013                 sub     %o0, %l3, %o0
F00BD968: 90020010                 add     %o0, %l0, %o0
F00BD96C: 9b2a2001                 sll     %o0, 1, %o5
F00BD970: d805a148                 ld      [%l6+0x148], %o4
F00BD974: 953b6003                 sra     %o5, 3, %o2
F00BD978: d2056338                 ld      [%l5+0x338], %o1
F00BD97C: 9603000a                 add     %o4, %o2, %o3
F00BD980: 80a2c009                 cmp     %o3, %o1
F00BD984: 02800008                 be      loc_F00BD9A4
F00BD988: 80a26000                 cmp     %o1, 0
F00BD98C: 02800003                 be      loc_F00BD998
F00BD990: d00d233c                 ldub    [%l4+0x33C], %o0
F00BD994: d02a4000                 stb     %o0, [%o1]
F00BD998: d00b000a                 ldub    [%o4+%o2], %o0
F00BD99C: d02d233c                 stb     %o0, [%l4+0x33C]
F00BD9A0: d6256338                 st      %o3, [%l5+0x338]
F00BD9A4: 9038000d                 xnor    %g0, %o5, %o0
F00BD9A8: 900a2006                 and     %o0, 6, %o0
F00BD9AC: a32c4008                 sll     %l1, %o0, %l1
F00BD9B0: 92102003                 mov     3, %o1
F00BD9B4: d40d233c                 ldub    [%l4+0x33C], %o2
F00BD9B8: 932a4008                 sll     %o1, %o0, %o1
F00BD9BC: 942a8009                 bclr    %o1, %o2
F00BD9C0: 920c4009                 and     %l1, %o1, %o1
F00BD9C4: 94128009                 bset    %o1, %o2
F00BD9C8: d42d233c                 stb     %o2, [%l4+0x33C]
F00BD9CC: d0560000                 ldsh    [%i0], %o0
F00BD9D0: a404a001                 inc     %l2
F00BD9D4: 80a48008                 cmp     %l2, %o0
F00BD9D8: 06bfffc3                 bl      loc_F00BD8E4
F00BD9DC: d2160000                 lduh    [%i0], %o1
F00BD9E0: d0562002                 ldsh    [%i0+2], %o0
F00BD9E4: a604e001                 inc     %l3
F00BD9E8: 80a4c008                 cmp     %l3, %o0
F00BD9EC: 26bfffbc                 bl,a    loc_F00BD8DC
F00BD9F0: d0560000                 ldsh    [%i0], %o0
F00BD9F4: 173c04cb                 sethi   -0xFECD400, %o3
F00BD9F8: d202e338                 ld      [%o3+0x338], %o1
F00BD9FC: 80a26000                 cmp     %o1, 0
F00BDA00: 02800004                 be      loc_F00BDA10
F00BDA04: 113c04cb                 sethi   %hi(unk_F0132F3C), %o0
F00BDA08: d00a233c                 ldub    [%o0+%lo(unk_F0132F3C)], %o0
F00BDA0C: d02a4000                 stb     %o0, [%o1]
F00BDA10: d4562008                 ldsh    [%i0+8], %o2
F00BDA14: 133c04cb                 sethi   %hi(dword_F0132F30), %o1
F00BDA18: d0026330                 ld      [%o1+%lo(dword_F0132F30)], %o0
F00BDA1C: c022e338                 clr     [%o3+0x338]
F00BDA20: 9002000a                 add     %o0, %o2, %o0
F00BDA24: d0226330                 st      %o0, [%o1+%lo(dword_F0132F30)]
F00BDA28: 81c7e008                 ret
F00BDA2C: 81e80000                 restore
