F0068070: 9de3bf90                 save    %sp, -0x70, %sp
F0068074: 113c04f0                 sethi   %hi(_k_zone_maxsize), %o0
F0068078: d00220b0                 ld      [%o0+%lo(_k_zone_maxsize)], %o0
F006807C: 94100018                 mov     %i0, %o2
F0068080: 80a28008                 cmp     %o2, %o0
F0068084: 1880000e                 bgu     loc_F00680BC
F0068088: 92102000                 mov     0, %o1
F006808C: 113c043e                 sethi   %hi(_k_zone_elemsize), %o0
F0068090: d40222a8                 ld      [%o0+%lo(_k_zone_elemsize)], %o2
F0068094: 80a28018                 cmp     %o2, %i0
F0068098: 3a80000a                 bcc,a   loc_F00680C0
F006809C: 113c04f0961222a8         set     unk_F013C2A8, %o3
F00680A4: 90102000                 mov     0, %o0
F00680A8: 90022004                 inc     4, %o0
F00680AC: d402000b                 ld      [%o0+%o3], %o2
F00680B0: 80a28018                 cmp     %o2, %i0
F00680B4: 0abffffd                 bcs     loc_F00680A8
F00680B8: 92026001                 inc     %o1
F00680BC: 113c04f0                 sethi   -0xFEC4000, %o0
F00680C0: d00220b0                 ld      [%o0+0xB0], %o0
F00680C4: 80a28008                 cmp     %o2, %o0
F00680C8: 18800008                 bgu     loc_F00680E8
F00680CC: 113c04f0                 sethi   %hi(_k_zone), %o0
F00680D0: 90122070                 bset    %lo(_k_zone), %o0
F00680D4: 932a6002                 sll     %o1, 2, %o1
F00680D8: 400043fd                 call    _zalloc
F00680DC: d0024008                 ld      [%o1+%o0], %o0
F00680E0: 10800009                 ba      loc_F0068104
F00680E4: d027bff4                 st      %o0, [%fp+var_C]
F00680E8: 113c04f0                 sethi   %hi(_kalloc_map), %o0
F00680EC: d0022038                 ld      [%o0+%lo(_kalloc_map)], %o0
F00680F0: 40006dc5                 call    _kmem_alloc_wired
F00680F4: 9207bff4                 add     %fp, var_C, %o1
F00680F8: 80a22000                 cmp     %o0, 0
F00680FC: 32800002                 bne,a   loc_F0068104
F0068100: c027bff4                 clr     [%fp+var_C]
F0068104: f007bff4                 ld      [%fp+var_C], %i0
F0068108: 81c7e008                 ret
F006810C: 81e80000                 restore
