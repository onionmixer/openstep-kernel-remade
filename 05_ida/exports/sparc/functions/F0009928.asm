F0009928: 9de3bf90                 save    %sp, -0x70, %sp
F000992C: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0009930: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0009934: 4000180e                 call    _suser
F0009938: e0022024                 ld      [%o0+0x24], %l0
F000993C: 80a22000                 cmp     %o0, 0
F0009940: 02800041                 be      locret_F0009A44
F0009944: 153c04d2                 sethi   %hi(_savacctp), %o2
F0009948: d202a220                 ld      [%o2+%lo(_savacctp)], %o1
F000994C: 80a26000                 cmp     %o1, 0
F0009950: 02800004                 be      loc_F0009960
F0009954: 113c04d2                 sethi   %hi(_acctp), %o0
F0009958: d2222218                 st      %o1, [%o0+%lo(_acctp)]
F000995C: c022a220                 clr     [%o2+%lo(_savacctp)]
F0009960: d0040000                 ld      [%l0], %o0
F0009964: 80a22000                 cmp     %o0, 0
F0009968: 1280000a                 bne     loc_F0009990
F000996C: 92102000                 mov     0, %o1
F0009970: 133c04d2                 sethi   %hi(_acctp), %o1
F0009974: d0026218                 ld      [%o1+%lo(_acctp)], %o0
F0009978: 80a22000                 cmp     %o0, 0
F000997C: 02800032                 be      locret_F0009A44
F0009980: d027bff4                 st      %o0, [%fp+var_C]
F0009984: 40007c78                 call    _vn_rele
F0009988: c0226218                 clr     [%o1+%lo(_acctp)]
F000998C: 3080002e                 ba,a    locret_F0009A44
F0009990: 94102001                 mov     1, %o2
F0009994: 96102000                 mov     0, %o3
F0009998: 4000740b                 call    _lookupname
F000999C: 9807bff4                 add     %fp, var_C, %o4
F00099A0: d20461dc                 ld      [%l1+0x1DC], %o1
F00099A4: d02a6038                 stb     %o0, [%o1+0x38]
F00099A8: d40461dc                 ld      [%l1+0x1DC], %o2
F00099AC: d04aa038                 ldsb    [%o2+0x38], %o0
F00099B0: 80a22000                 cmp     %o0, 0
F00099B4: 12800024                 bne     locret_F0009A44
F00099B8: d207bff4                 ld      [%fp+var_C], %o1
F00099BC: d0026028                 ld      [%o1+0x28], %o0
F00099C0: 80a22001                 cmp     %o0, 1
F00099C4: 12800007                 bne     loc_F00099E0
F00099C8: 9010200d                 mov     0xD, %o0
F00099CC: d0026024                 ld      [%o1+0x24], %o0
F00099D0: d002200c                 ld      [%o0+0xC], %o0
F00099D4: 808a2001                 btst    1, %o0
F00099D8: 02800006                 be      loc_F00099F0
F00099DC: 9010201e                 mov     0x1E, %o0
F00099E0: d02aa038                 stb     %o0, [%o2+0x38]
F00099E4: 40007c60                 call    _vn_rele
F00099E8: d007bff4                 ld      [%fp+var_C], %o0
F00099EC: 30800016                 ba,a    locret_F0009A44
F00099F0: 153c04d2                 sethi   %hi(_acctp), %o2
F00099F4: d002a218                 ld      [%o2+%lo(_acctp)], %o0
F00099F8: 80a22000                 cmp     %o0, 0
F00099FC: 22800006                 be,a    loc_F0009A14
F0009A00: d222a218                 st      %o1, [%o2+%lo(_acctp)]
F0009A04: 40007c58                 call    _vn_rele
F0009A08: d222a218                 st      %o1, [%o2+%lo(_acctp)]
F0009A0C: 10800003                 ba      loc_F0009A18
F0009A10: 213c04d2                 sethi   -0xFECB800, %l0
F0009A14: 213c04d2                 sethi   -0xFECB800, %l0
F0009A18: d0042210                 ld      [%l0+0x210], %o0
F0009A1C: 80a22000                 cmp     %o0, 0
F0009A20: 22800005                 be,a    loc_F0009A34
F0009A24: 113c04cf                 sethi   -0xFECC400, %o0
F0009A28: 400017fc                 call    _crfree
F0009A2C: 01000000                 nop
F0009A30: 113c04cf                 sethi   -0xFECC400, %o0
F0009A34: d00221d8                 ld      [%o0+0x1D8], %o0
F0009A38: 4000181b                 call    _crdup
F0009A3C: d002201c                 ld      [%o0+0x1C], %o0
F0009A40: d0242210                 st      %o0, [%l0+0x210]
F0009A44: 81c7e008                 ret
F0009A48: 81e80000                 restore
