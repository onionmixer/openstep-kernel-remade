F00BC2BC: 9de3bf90                 save    %sp, -0x70, %sp
F00BC2C0: 113c04fd                 sethi   %hi(_kmId), %o0
F00BC2C4: d2022240                 ld      [%o0+%lo(_kmId)], %o1
F00BC2C8: 80a26000                 cmp     %o1, 0
F00BC2CC: 113c0485                 sethi   %hi(_static_KERNBOOTSTRUCT), %o0
F00BC2D0: 02800009                 be      loc_F00BC2F4
F00BC2D4: a0122050                 or      %o0, %lo(_static_KERNBOOTSTRUCT), %l0
F00BC2D8: 113c04c8                 sethi   %hi(dword_F0132060), %o0
F00BC2DC: d0022060                 ld      [%o0+%lo(dword_F0132060)], %o0
F00BC2E0: 80a22000                 cmp     %o0, 0
F00BC2E4: 12800005                 bne     loc_F00BC2F8
F00BC2E8: 113c0504                 sethi   -0xFEBF000, %o0
F00BC2EC: 10800007                 ba      loc_F00BC308
F00BC2F0: b0100009                 mov     %o1, %i0
F00BC2F4: 113c0504                 sethi   -0xFEBF000, %o0! id
F00BC2F8: d2022238                 ld      [%o0+0x238], %o1! SEL
F00BC2FC: 4000d55d                 call    _objc_msgSend
F00BC300: 90100018                 mov     %i0, %o0
F00BC304: b0100008                 mov     %o0, %i0
F00BC308: 96102001                 mov     1, %o3
F00BC30C: d2042138                 ld      [%l0+0x138], %o1
F00BC310: 113c0504                 sethi   %hi(paInitFbMode), %o0
F00BC314: 80a26000                 cmp     %o1, 0
F00BC318: 02800003                 be      loc_F00BC324
F00BC31C: d402223c                 ld      [%o0+%lo(paInitFbMode)], %o2
F00BC320: 96102002                 mov     2, %o3
F00BC324: 90100018                 mov     %i0, %o0! id
F00BC328: 9210000a                 mov     %o2, %o1! SEL
F00BC32C: 4000d551                 call    _objc_msgSend
F00BC330: 94102001                 mov     1, %o2
F00BC334: 80a22000                 cmp     %o0, 0
F00BC338: 02800004                 be      loc_F00BC348
F00BC33C: 113c047f                 sethi   -0xFEE0400, %o0
F00BC340: 1080000b                 ba      locret_F00BC36C
F00BC344: b0102001                 mov     1, %i0
F00BC348: 4000276b                 call    _IOLog
F00BC34C: 90122288                 bset    0x288, %o0
F00BC350: 113c0503                 sethi   %hi(paFree), %o0! id
F00BC354: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00BC358: 4000d546                 call    _objc_msgSend
F00BC35C: 90100018                 mov     %i0, %o0
F00BC360: 113c04fd                 sethi   %hi(_kmId), %o0
F00BC364: c0222240                 clr     [%o0+%lo(_kmId)]
F00BC368: b0102000                 mov     0, %i0
F00BC36C: 81c7e008                 ret
F00BC370: 81e80000                 restore
