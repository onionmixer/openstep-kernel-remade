F0067FCC: 9de3bf90                 save    %sp, -0x70, %sp
F0067FD0: 113c04f0                 sethi   %hi(_k_zone_maxsize), %o0
F0067FD4: d00220b0                 ld      [%o0+%lo(_k_zone_maxsize)], %o0
F0067FD8: 94100018                 mov     %i0, %o2
F0067FDC: 80a28008                 cmp     %o2, %o0
F0067FE0: 1880000e                 bgu     loc_F0068018
F0067FE4: 92102000                 mov     0, %o1
F0067FE8: 113c043e                 sethi   %hi(_k_zone_elemsize), %o0
F0067FEC: d40222a8                 ld      [%o0+%lo(_k_zone_elemsize)], %o2
F0067FF0: 80a28018                 cmp     %o2, %i0
F0067FF4: 3a80000a                 bcc,a   loc_F006801C
F0067FF8: 113c04f0961222a8         set     unk_F013C2A8, %o3
F0068000: 90102000                 mov     0, %o0
F0068004: 90022004                 inc     4, %o0
F0068008: d402000b                 ld      [%o0+%o3], %o2
F006800C: 80a28018                 cmp     %o2, %i0
F0068010: 0abffffd                 bcs     loc_F0068004
F0068014: 92026001                 inc     %o1
F0068018: 113c04f0                 sethi   -0xFEC4000, %o0
F006801C: d00220b0                 ld      [%o0+0xB0], %o0
F0068020: 80a28008                 cmp     %o2, %o0
F0068024: 18800008                 bgu     loc_F0068044
F0068028: 113c04f0                 sethi   %hi(_k_zone), %o0
F006802C: 90122070                 bset    %lo(_k_zone), %o0
F0068030: 932a6002                 sll     %o1, 2, %o1
F0068034: 4000442c                 call    _zalloc_noblock
F0068038: d0024008                 ld      [%o1+%o0], %o0
F006803C: 1080000a                 ba      loc_F0068064
F0068040: d027bff4                 st      %o0, [%fp+var_C]
F0068044: 113c04f0                 sethi   %hi(_kalloc_map), %o0
F0068048: d0022038                 ld      [%o0+%lo(_kalloc_map)], %o0
F006804C: 9207bff4                 add     %fp, var_C, %o1
F0068050: 40006edb                 call    _kmem_alloc_zone
F0068054: 96102000                 mov     0, %o3
F0068058: 80a22000                 cmp     %o0, 0
F006805C: 32800002                 bne,a   loc_F0068064
F0068060: c027bff4                 clr     [%fp+var_C]
F0068064: f007bff4                 ld      [%fp+var_C], %i0
F0068068: 81c7e008                 ret
F006806C: 81e80000                 restore
