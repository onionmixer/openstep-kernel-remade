F00BB598: 9de3bf90                 save    %sp, -0x70, %sp
F00BB59C: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00BB5A0: 92100018                 mov     %i0, %o1
F00BB5A4: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00BB5A8: 7fff86bc                 call    _pmap_getpte
F00BB5AC: 9407bff4                 add     %fp, var_C, %o2
F00BB5B0: f007bff4                 ld      [%fp+var_C], %i0
F00BB5B4: b1362008                 srl     %i0, 8, %i0
F00BB5B8: 81c7e008                 ret
F00BB5BC: 81e80000                 restore
