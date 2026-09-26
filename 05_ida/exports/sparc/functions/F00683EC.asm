F00683EC: 9de3bf98                 save    %sp, -0x68, %sp
F00683F0: 96102001                 mov     1, %o3
F00683F4: 113c04d0                 sethi   %hi(_page_mask), %o0
F00683F8: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F00683FC: a2102000                 mov     0, %l1
F0068400: 113c04bd                 sethi   %hi(dword_F012F67C), %o0
F0068404: a02e0009                 andn    %i0, %o1, %l0
F0068408: d402227c                 ld      [%o0+%lo(dword_F012F67C)], %o2
F006840C: 80a4400a                 cmp     %l1, %o2
F0068410: 1680000d                 bge     loc_F0068444
F0068414: 9a100010                 mov     %l0, %o5
F0068418: 113c04bd                 sethi   %hi(dword_F012F678), %o0
F006841C: d8022278                 ld      [%o0+%lo(dword_F012F678)], %o4
F0068420: 9210000a                 mov     %o2, %o1
F0068424: d0042008                 ld      [%l0+8], %o0
F0068428: 80a22000                 cmp     %o0, 0
F006842C: 32800002                 bne,a   loc_F0068434
F0068430: 96102000                 mov     0, %o3
F0068434: a2046001                 inc     %l1
F0068438: 80a44009                 cmp     %l1, %o1
F006843C: 06bffffa                 bl      loc_F0068424
F0068440: a004000c                 add     %l0, %o4, %l0
F0068444: 80a2e000                 cmp     %o3, 0
F0068448: 1280000a                 bne     loc_F0068470
F006844C: 133c04bd                 sethi   -0xFED0C00, %o1
F0068450: 400000f6                 call    _canSwap
F0068454: 90100018                 mov     %i0, %o0
F0068458: 80a22000                 cmp     %o0, 0
F006845C: 02800031                 be      locret_F0068520
F0068460: 01000000                 nop
F0068464: 40000109                 call    _doSwapout
F0068468: 90100018                 mov     %i0, %o0
F006846C: 3080002d                 ba,a    locret_F0068520
F0068470: d002627c                 ld      [%o1+0x27C], %o0
F0068474: a2102000                 mov     0, %l1
F0068478: 80a44008                 cmp     %l1, %o0
F006847C: 1680001f                 bge     loc_F00684F8
F0068480: a010000d                 mov     %o5, %l0
F0068484: 2b3c04bda4156270         set     dword_F012F670, %l2
F006848C: 293c043e                 sethi   -0xFEF0800, %l4
F0068490: 113c04f0a61220c0         set     _stackStats, %l3
F0068498: 2f3c04bd                 sethi   -0xFED0C00, %l7
F006849C: ac100009                 mov     %o1, %l6
F00684A0: d0040000                 ld      [%l0], %o0
F00684A4: d2042004                 ld      [%l0+4], %o1
F00684A8: 80a24012                 cmp     %o1, %l2
F00684AC: 12800004                 bne     loc_F00684BC
F00684B0: d2222004                 st      %o1, [%o0+4]
F00684B4: 10800003                 ba      loc_F00684C0
F00684B8: d0256270                 st      %o0, [%l5+0x270]
F00684BC: d0224000                 st      %o0, [%o1]
F00684C0: d4052300                 ld      [%l4+0x300], %o2
F00684C4: 9004200c                 add     %l0, 0xC, %o0
F00684C8: d204e008                 ld      [%l3+8], %o1
F00684CC: 9402bfff                 inc     -1, %o2
F00684D0: d4252300                 st      %o2, [%l4+0x300]
F00684D4: 92027fff                 inc     -1, %o1
F00684D8: 400036e9                 call    _stack_finalize
F00684DC: d224e008                 st      %o1, [%l3+8]
F00684E0: d205e278                 ld      [%l7+0x278], %o1
F00684E4: a2046001                 inc     %l1
F00684E8: d005a27c                 ld      [%l6+0x27C], %o0
F00684EC: 80a44008                 cmp     %l1, %o0
F00684F0: 06bfffec                 bl      loc_F00684A0
F00684F4: a0040009                 add     %l0, %o1, %l0
F00684F8: 133c04bd                 sethi   %hi(dword_F012F678), %o1
F00684FC: d4026278                 ld      [%o1+%lo(dword_F012F678)], %o2
F0068500: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0068504: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0068508: 40006cdf                 call    _kmem_free
F006850C: 92100018                 mov     %i0, %o1
F0068510: 133c04f0                 sethi   %hi(_stackStats), %o1
F0068514: d00260c0                 ld      [%o1+%lo(_stackStats)], %o0
F0068518: 90023fff                 inc     -1, %o0
F006851C: d02260c0                 st      %o0, [%o1+%lo(_stackStats)]
F0068520: 81c7e008                 ret
F0068524: 81e80000                 restore
