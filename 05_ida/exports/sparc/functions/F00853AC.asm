F00853AC: 9de3bf90                 save    %sp, -0x70, %sp
F00853B0: 90100018                 mov     %i0, %o0
F00853B4: 92100019                 mov     %i1, %o1
F00853B8: 7ffffc3c                 call    _vm_map_lookup_entry
F00853BC: 9407bff4                 add     %fp, var_C, %o2
F00853C0: 80a22000                 cmp     %o0, 0
F00853C4: 12800004                 bne     loc_F00853D4
F00853C8: 80a6401a                 cmp     %i1, %i2
F00853CC: 10800016                 ba      locret_F0085424
F00853D0: b0102000                 mov     0, %i0
F00853D4: 1a800013                 bcc     loc_F0085420
F00853D8: d207bff4                 ld      [%fp+var_C], %o1
F00853DC: b006200c                 inc     0xC, %i0
F00853E0: 80a24018                 cmp     %o1, %i0
F00853E4: 22800010                 be,a    locret_F0085424
F00853E8: b0102000                 mov     0, %i0
F00853EC: d0026008                 ld      [%o1+8], %o0
F00853F0: 80a64008                 cmp     %i1, %o0
F00853F4: 2a80000c                 bcs,a   locret_F0085424
F00853F8: b0102000                 mov     0, %i0
F00853FC: d002601c                 ld      [%o1+0x1C], %o0
F0085400: 900a001b                 and     %o0, %i3, %o0
F0085404: 80a2001b                 cmp     %o0, %i3
F0085408: 32800007                 bne,a   locret_F0085424
F008540C: b0102000                 mov     0, %i0
F0085410: f202600c                 ld      [%o1+0xC], %i1
F0085414: 80a6401a                 cmp     %i1, %i2
F0085418: 0abffff2                 bcs     loc_F00853E0
F008541C: d2026004                 ld      [%o1+4], %o1
F0085420: b0102001                 mov     1, %i0
F0085424: 81c7e008                 ret
F0085428: 81e80000                 restore
