F008AF5C: 9de3bf98                 save    %sp, -0x68, %sp
F008AF60: 113c04f6                 sethi   %hi(_vstruct_zone), %o0
F008AF64: d00221a0                 ld      [%o0+%lo(_vstruct_zone)], %o0
F008AF68: 7fffb85f                 call    _zalloc_noblock
F008AF6C: a0100018                 mov     %i0, %l0
F008AF70: b0920000                 orcc    %o0, %g0, %i0
F008AF74: 12800004                 bne     loc_F008AF84
F008AF78: 113c04d0                 sethi   -0xFECC000, %o0
F008AF7C: 10800049                 ba      locret_F008B0A0
F008AF80: b0102000                 mov     0, %i0
F008AF84: d00220d8                 ld      [%o0+0xD8], %o0
F008AF88: 133c04f4                 sethi   %hi(_page_shift), %o1
F008AF8C: d2026348                 ld      [%o1+%lo(_page_shift)], %o1
F008AF90: 94064008                 add     %i1, %o0, %o2
F008AF94: 902a8008                 andn    %o2, %o0, %o0
F008AF98: 91320009                 srl     %o0, %o1, %o0
F008AF9C: 80a22000                 cmp     %o0, 0
F008AFA0: 12800004                 bne     loc_F008AFB0
F008AFA4: d0262010                 st      %o0, [%i0+0x10]
F008AFA8: 1080002f                 ba      loc_F008B064
F008AFAC: c0262008                 clr     [%i0+8]
F008AFB0: 932a2002                 sll     %o0, 2, %o1
F008AFB4: 80a26040                 cmp     %o1, 0x40 ! '@'
F008AFB8: 08800006                 bleu    loc_F008AFD0
F008AFBC: 90023fff                 inc     -1, %o0
F008AFC0: 91322004                 srl     %o0, 4, %o0
F008AFC4: 90022001                 inc     %o0
F008AFC8: 10800003                 ba      loc_F008AFD4
F008AFCC: 912a2002                 sll     %o0, 2, %o0
F008AFD0: 90100009                 mov     %o1, %o0
F008AFD4: 7fff73fe                 call    _kalloc_noblock
F008AFD8: 01000000                 nop
F008AFDC: d0262008                 st      %o0, [%i0+8]
F008AFE0: d4062008                 ld      [%i0+8], %o2
F008AFE4: 80a2a000                 cmp     %o2, 0
F008AFE8: 32800008                 bne,a   loc_F008B008
F008AFEC: d2062010                 ld      [%i0+0x10], %o1
F008AFF0: 113c04f6                 sethi   %hi(_vstruct_zone), %o0
F008AFF4: d00221a0                 ld      [%o0+%lo(_vstruct_zone)], %o0
F008AFF8: 7fffb876                 call    _zfree
F008AFFC: 92100018                 mov     %i0, %o1
F008B000: 10800028                 ba      locret_F008B0A0
F008B004: b0102000                 mov     0, %i0
F008B008: 912a6002                 sll     %o1, 2, %o0
F008B00C: 80a22040                 cmp     %o0, 0x40 ! '@'
F008B010: 08800009                 bleu    loc_F008B034
F008B014: 9010000a                 mov     %o2, %o0! void *
F008B018: 92027fff                 inc     -1, %o1
F008B01C: 93326004                 srl     %o1, 4, %o1! size_t
F008B020: 92026001                 inc     %o1
F008B024: 4000278d                 call    _bzero
F008B028: 932a6002                 sll     %o1, 2, %o1
F008B02C: 1080000f                 ba      loc_F008B068
F008B030: c0260000                 clr     [%i0]
F008B034: 94102000                 mov     0, %o2
F008B038: 80a28009                 cmp     %o2, %o1
F008B03C: 3680000b                 bge,a   loc_F008B068
F008B040: c0260000                 clr     [%i0]
F008B044: d0062008                 ld      [%i0+8], %o0
F008B048: 932aa002                 sll     %o2, 2, %o1
F008B04C: c02a0009                 clrb    [%o0+%o1]
F008B050: d0062010                 ld      [%i0+0x10], %o0
F008B054: 9402a001                 inc     %o2
F008B058: 80a28008                 cmp     %o2, %o0
F008B05C: 26bffffb                 bl,a    loc_F008B048
F008B060: d0062008                 ld      [%i0+8], %o0
F008B064: c0260000                 clr     [%i0]
F008B068: 90102001                 mov     1, %o0
F008B06C: d036200e                 sth     %o0, [%i0+0xE]
F008B070: d0042008                 ld      [%l0+8], %o0
F008B074: 13200000                 sethi   0x80000000, %o1
F008B078: d0262014                 st      %o0, [%i0+0x14]
F008B07C: d006200c                 ld      [%i0+0xC], %o0
F008B080: e0262004                 st      %l0, [%i0+4]
F008B084: 90120009                 bset    %o1, %o0
F008B088: d026200c                 st      %o0, [%i0+0xC]
F008B08C: d204200c                 ld      [%l0+0xC], %o1
F008B090: 90100018                 mov     %i0, %o0
F008B094: 92026001                 inc     %o1
F008B098: 7ffffee4                 call    _vnode_pager_vput
F008B09C: d224200c                 st      %o1, [%l0+0xC]
F008B0A0: 81c7e008                 ret
F008B0A4: 81e80000                 restore
