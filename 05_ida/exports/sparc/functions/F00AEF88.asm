F00AEF88: 9de3bf98                 save    %sp, -0x68, %sp
F00AEF8C: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AEF90: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AEF94: 80a22000                 cmp     %o0, 0
F00AEF98: 02800007                 be      locret_F00AEFB4
F00AEF9C: 113c000c                 sethi   %hi(_romp), %o0
F00AEFA0: d2022030                 ld      [%o0+%lo(_romp)], %o1
F00AEFA4: d40260a0                 ld      [%o1+0xA0], %o2
F00AEFA8: 90100018                 mov     %i0, %o0
F00AEFAC: 9fc28000                 call    %o2
F00AEFB0: 92100019                 mov     %i1, %o1
F00AEFB4: 81c7e008                 ret
F00AEFB8: 81e80000                 restore
