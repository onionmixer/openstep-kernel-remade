F000C394: 9de3bf90                 save    %sp, -0x70, %sp
F000C398: 133c04cf                 sethi   %hi(_active_u), %o1
F000C39C: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F000C3A0: d0020000                 ld      [%o0], %o0
F000C3A4: f2222084                 st      %i1, [%o0+0x84]
F000C3A8: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F000C3AC: 94102000                 mov     0, %o2
F000C3B0: d8022278                 ld      [%o0+0x278], %o4
F000C3B4: 9607bff4                 add     %fp, var_C, %o3
F000C3B8: 113c04d0                 sethi   %hi(_page_mask), %o0
F000C3BC: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F000C3C0: 9a102000                 mov     0, %o5
F000C3C4: 90100018                 mov     %i0, %o0
F000C3C8: 98030009                 add     %o4, %o1, %o4
F000C3CC: 92380009                 xnor    %g0, %o1, %o1
F000C3D0: 980b0009                 and     %o4, %o1, %o4
F000C3D4: b226400c                 sub     %i1, %o4, %i1
F000C3D8: b20e4009                 and     %i1, %o1, %i1
F000C3DC: f227bff4                 st      %i1, [%fp+var_C]
F000C3E0: 4001e07c                 call    _vm_map_find
F000C3E4: 92102000                 mov     0, %o1
F000C3E8: 81c7e008                 ret
F000C3EC: 91e80008                 restore %g0, %o0, %o0
