F00BF2B0: 9de3bf90                 save    %sp, -0x70, %sp
F00BF2B4: d04e2154                 ldsb    [%i0+0x154], %o0
F00BF2B8: 80a22001                 cmp     %o0, 1
F00BF2BC: 32800008                 bne,a   loc_F00BF2DC
F00BF2C0: d0062160                 ld      [%i0+0x160], %o0
F00BF2C4: 113c02fc901223fc         set     sub_F00BF3FC, %o0
F00BF2CC: 7ffebbaa                 call    _ns_untimeout
F00BF2D0: 92100018                 mov     %i0, %o1
F00BF2D4: c02e2154                 clrb    [%i0+0x154]
F00BF2D8: d0062160                 ld      [%i0+0x160], %o0
F00BF2DC: 80a22000                 cmp     %o0, 0
F00BF2E0: 12800006                 bne     loc_F00BF2F8
F00BF2E4: 113c02fc                 sethi   -0xFF41000, %o0
F00BF2E8: d0062164                 ld      [%i0+0x164], %o0
F00BF2EC: 80a22000                 cmp     %o0, 0
F00BF2F0: 02800009                 be      locret_F00BF314
F00BF2F4: 113c02fc                 sethi   -0xFF41000, %o0
F00BF2F8: 901223fc                 bset    0x3FC, %o0
F00BF2FC: 92100018                 mov     %i0, %o1
F00BF300: d41e2160                 ldd     [%i0+0x160], %o2
F00BF304: 7ffebb94                 call    _ns_abstimeout
F00BF308: 98102004                 mov     4, %o4
F00BF30C: 90102001                 mov     1, %o0
F00BF310: d02e2154                 stb     %o0, [%i0+0x154]
F00BF314: 81c7e008                 ret
F00BF318: 81e80000                 restore
