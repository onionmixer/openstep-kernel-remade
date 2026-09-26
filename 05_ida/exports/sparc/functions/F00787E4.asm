F00787E4: 9de3bf90                 save    %sp, -0x70, %sp
F00787E8: a2960000                 orcc    %i0, %g0, %l1
F00787EC: 12800004                 bne     loc_F00787FC
F00787F0: c027bff4                 clr     [%fp+var_C]
F00787F4: 113c04f2a2122350         set     __zone_default_space, %l1
F00787FC: 80a66010                 cmp     %i1, 0x10
F0078800: 08800010                 bleu    loc_F0078840
F0078804: 9006600f                 add     %i1, 0xF, %o0
F0078808: 1080000f                 ba      loc_F0078844
F007880C: b20a3ff0                 and     %o0, -0x10, %i1
F0078810: d42523f4                 st      %o2, [%l4+0x3F4]
F0078814: 90100011                 mov     %l1, %o0
F0078818: 173c04f2                 sethi   %hi(_zdata), %o3
F007881C: d802e3a0                 ld      [%o3+%lo(_zdata)], %o4
F0078820: 92100019                 mov     %i1, %o1
F0078824: 96100012                 mov     %l2, %o3
F0078828: 7ffffe6a                 call    _zone_free_space_add
F007882C: 9403000a                 add     %o4, %o2, %o2
F0078830: 10800065                 ba      loc_F00789C4
F0078834: b0100008                 mov     %o0, %i0
F0078838: 1080006c                 ba      locret_F00789E8
F007883C: b0102000                 mov     0, %i0
F0078840: b2102010                 mov     0x10, %i1
F0078844: 113c04f2a01223a8         set     _zget_space_lock, %l0
F007884C: d0040000                 ld      [%l0], %o0
F0078850: 80a22000                 cmp     %o0, 0
F0078854: 12bffffe                 bne     loc_F007884C
F0078858: 01000000                 nop
F007885C: 40007993                 call    _simple_lock_try
F0078860: 90100010                 mov     %l0, %o0
F0078864: 80a22000                 cmp     %o0, 0
F0078868: 02bffff9                 be      loc_F007884C
F007886C: 293c0442                 sethi   -0xFEEF800, %l4
F0078870: 273c04f2                 sethi   -0xFEC3800, %l3
F0078874: 90100011                 mov     %l1, %o0
F0078878: 7ffffd59                 call    sub_F0077DDC
F007887C: 92100019                 mov     %i1, %o1
F0078880: b0920000                 orcc    %o0, %g0, %i0
F0078884: 0280002c                 be      loc_F0078934
F0078888: d407bff4                 ld      [%fp+var_C], %o2
F007888C: d0062004                 ld      [%i0+4], %o0
F0078890: 90220019                 sub     %o0, %i1, %o0
F0078894: 80a2200f                 cmp     %o0, 0xF
F0078898: 1880000c                 bgu     loc_F00788C8
F007889C: d2062008                 ld      [%i0+8], %o1
F00788A0: d0060000                 ld      [%i0], %o0
F00788A4: 80a22000                 cmp     %o0, 0
F00788A8: 02800004                 be      loc_F00788B8
F00788AC: d0224000                 st      %o0, [%o1]
F00788B0: d0060000                 ld      [%i0], %o0
F00788B4: d2222008                 st      %o1, [%o0+8]
F00788B8: d004600c                 ld      [%l1+0xC], %o0
F00788BC: 90023fff                 inc     -1, %o0
F00788C0: 10800041                 ba      loc_F00789C4
F00788C4: d024600c                 st      %o0, [%l1+0xC]
F00788C8: 94060019                 add     %i0, %i1, %o2
F00788CC: d022a004                 st      %o0, [%o2+4]
F00788D0: d0060000                 ld      [%i0], %o0
F00788D4: 80a22000                 cmp     %o0, 0
F00788D8: 02800003                 be      loc_F00788E4
F00788DC: d0260019                 st      %o0, [%i0+%i1]
F00788E0: d4222008                 st      %o2, [%o0+8]
F00788E4: d222a008                 st      %o1, [%o2+8]
F00788E8: d4224000                 st      %o2, [%o1]
F00788EC: d002a004                 ld      [%o2+4], %o0
F00788F0: d2046010                 ld      [%l1+0x10], %o1
F00788F4: d6046018                 ld      [%l1+0x18], %o3
F00788F8: 91320009                 srl     %o0, %o1, %o0
F00788FC: 80a2000b                 cmp     %o0, %o3
F0078900: 34800002                 bg,a    loc_F0078908
F0078904: 9010000b                 mov     %o3, %o0
F0078908: d2046014                 ld      [%l1+0x14], %o1
F007890C: 912a2004                 sll     %o0, 4, %o0
F0078910: 92024008                 add     %o1, %o0, %o1
F0078914: d0027ff0                 ld      [%o1-0x10], %o0
F0078918: 80a22000                 cmp     %o0, 0
F007891C: 02800004                 be      loc_F007892C
F0078920: 80a28008                 cmp     %o2, %o0
F0078924: 1a800029                 bcc     loc_F00789C8
F0078928: 113c04f2                 sethi   -0xFEC3800, %o0
F007892C: 10800026                 ba      loc_F00789C4
F0078930: d4227ff0                 st      %o2, [%o1-0x10]
F0078934: 80a2a000                 cmp     %o2, 0
F0078938: 1280001e                 bne     loc_F00789B0
F007893C: 90100011                 mov     %l1, %o0
F0078940: 113c04d0                 sethi   %hi(_page_mask), %o0
F0078944: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F0078948: d40523f4                 ld      [%l4+0x3F4], %o2
F007894C: 92064008                 add     %i1, %o0, %o1
F0078950: a42a4008                 andn    %o1, %o0, %l2
F0078954: 80a28012                 cmp     %o2, %l2
F0078958: 1abfffae                 bcc     loc_F0078810
F007895C: 94228012                 sub     %o2, %l2, %o2
F0078960: c024e3a8                 clr     [%l3+0x3A8]
F0078964: 113c0442                 sethi   %hi(_zone_map), %o0
F0078968: d00223ec                 ld      [%o0+%lo(_zone_map)], %o0
F007896C: 9207bff4                 add     %fp, var_C, %o1
F0078970: 94100012                 mov     %l2, %o2
F0078974: 40002c92                 call    _kmem_alloc_zone
F0078978: 9610001a                 mov     %i2, %o3
F007897C: 80a22000                 cmp     %o0, 0
F0078980: 12bfffae                 bne     loc_F0078838
F0078984: a014e3a8                 or      %l3, 0x3A8, %l0
F0078988: d0040000                 ld      [%l0], %o0
F007898C: 80a22000                 cmp     %o0, 0
F0078990: 12bffffe                 bne     loc_F0078988
F0078994: 01000000                 nop
F0078998: 40007944                 call    _simple_lock_try
F007899C: 90100010                 mov     %l0, %o0
F00789A0: 80a22000                 cmp     %o0, 0
F00789A4: 02bffff9                 be      loc_F0078988
F00789A8: 90100011                 mov     %l1, %o0
F00789AC: 30bfffb3                 ba,a    loc_F0078878
F00789B0: 92100019                 mov     %i1, %o1
F00789B4: 7ffffe07                 call    _zone_free_space_add
F00789B8: 96100012                 mov     %l2, %o3
F00789BC: b0100008                 mov     %o0, %i0
F00789C0: c027bff4                 clr     [%fp+var_C]
F00789C4: 113c04f2                 sethi   -0xFEC3800, %o0
F00789C8: d207bff4                 ld      [%fp+var_C], %o1
F00789CC: c02223a8                 clr     [%o0+0x3A8]
F00789D0: 80a26000                 cmp     %o1, 0
F00789D4: 02800005                 be      locret_F00789E8
F00789D8: 113c0442                 sethi   %hi(_zone_map), %o0
F00789DC: d00223ec                 ld      [%o0+%lo(_zone_map)], %o0
F00789E0: 40002ba9                 call    _kmem_free
F00789E4: 94100012                 mov     %l2, %o2
F00789E8: 81c7e008                 ret
F00789EC: 81e80000                 restore
