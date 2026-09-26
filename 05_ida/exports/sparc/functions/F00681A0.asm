F00681A0: 9de3bf98                 save    %sp, -0x68, %sp
F00681A4: 113c04f0                 sethi   %hi(_k_zone_maxsize), %o0
F00681A8: d00220b0                 ld      [%o0+%lo(_k_zone_maxsize)], %o0
F00681AC: 94100019                 mov     %i1, %o2
F00681B0: 80a28008                 cmp     %o2, %o0
F00681B4: 1880000e                 bgu     loc_F00681EC
F00681B8: 92102000                 mov     0, %o1
F00681BC: 113c043e                 sethi   %hi(_k_zone_elemsize), %o0
F00681C0: d40222a8                 ld      [%o0+%lo(_k_zone_elemsize)], %o2
F00681C4: 80a28019                 cmp     %o2, %i1
F00681C8: 3a80000a                 bcc,a   loc_F00681F0
F00681CC: 113c04f0961222a8         set     unk_F013C2A8, %o3
F00681D4: 90102000                 mov     0, %o0
F00681D8: 90022004                 inc     4, %o0
F00681DC: d402000b                 ld      [%o0+%o3], %o2
F00681E0: 80a28019                 cmp     %o2, %i1
F00681E4: 0abffffd                 bcs     loc_F00681D8
F00681E8: 92026001                 inc     %o1
F00681EC: 113c04f0                 sethi   -0xFEC4000, %o0
F00681F0: d00220b0                 ld      [%o0+0xB0], %o0
F00681F4: 80a28008                 cmp     %o2, %o0
F00681F8: 18800008                 bgu     loc_F0068218
F00681FC: 113c04f0                 sethi   %hi(_k_zone), %o0
F0068200: 90122070                 bset    %lo(_k_zone), %o0
F0068204: 932a6002                 sll     %o1, 2, %o1
F0068208: d0024008                 ld      [%o1+%o0], %o0
F006820C: 400043f1                 call    _zfree
F0068210: 92100018                 mov     %i0, %o1
F0068214: 30800005                 ba,a    locret_F0068228
F0068218: 113c04f0                 sethi   %hi(_kalloc_map), %o0
F006821C: d0022038                 ld      [%o0+%lo(_kalloc_map)], %o0
F0068220: 40006d99                 call    _kmem_free
F0068224: 92100018                 mov     %i0, %o1
F0068228: 81c7e008                 ret
F006822C: 81e80000                 restore
