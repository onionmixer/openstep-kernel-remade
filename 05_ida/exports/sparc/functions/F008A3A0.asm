F008A3A0: 9de3bf98                 save    %sp, -0x68, %sp
F008A3A4: a8100018                 mov     %i0, %l4
F008A3A8: 113c04d0                 sethi   %hi(_page_mask), %o0
F008A3AC: a4102000                 mov     0, %l2
F008A3B0: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F008A3B4: 2f3c04f4                 sethi   %hi(_page_shift), %l7
F008A3B8: d205e348                 ld      [%l7+%lo(_page_shift)], %o1! size_t
F008A3BC: b8070008                 add     %i4, %o0, %i4
F008A3C0: 902f0008                 andn    %i4, %o0, %o0
F008A3C4: 7ffff0f7                 call    _vm_object_allocate
F008A3C8: a7320009                 srl     %o0, %o1, %l3
F008A3CC: b0100008                 mov     %o0, %i0
F008A3D0: a12ce001                 sll     %l3, 1, %l0
F008A3D4: a0040013                 add     %l0, %l3, %l0
F008A3D8: a12c2004                 sll     %l0, 4, %l0
F008A3DC: a0042010                 inc     0x10, %l0
F008A3E0: 7fff7724                 call    _kalloc
F008A3E4: 90100010                 mov     %l0, %o0! void *
F008A3E8: a2100008                 mov     %o0, %l1
F008A3EC: 40002a9b                 call    _bzero
F008A3F0: 92100010                 mov     %l0, %o1
F008A3F4: 90102001                 mov     1, %o0
F008A3F8: d0244000                 st      %o0, [%l1]
F008A3FC: f0246004                 st      %i0, [%l1+4]
F008A400: e2246008                 st      %l1, [%l1+8]
F008A404: e024600c                 st      %l0, [%l1+0xC]
F008A408: 80a48013                 cmp     %l2, %l3
F008A40C: 16800019                 bge     loc_F008A470
F008A410: b8046010                 add     %l1, 0x10, %i4
F008A414: ac102001                 mov     1, %l6
F008A418: ab2d2010                 sll     %l4, 16, %l5
F008A41C: a8100017                 mov     %l7, %l4
F008A420: a0046034                 add     %l1, 0x34, %l0 ! '4'
F008A424: ec343ff8                 sth     %l6, [%l0-8]
F008A428: 913d6010                 sra     %l5, 16, %o0
F008A42C: d2052348                 ld      [%l4+0x348], %o1
F008A430: 9410001a                 mov     %i2, %o2
F008A434: 932c8009                 sll     %l2, %o1, %o1
F008A438: 9fc64000                 call    %i1
F008A43C: 9206c009                 add     %i3, %o1, %o1
F008A440: d4052348                 ld      [%l4+0x348], %o2
F008A444: 92100018                 mov     %i0, %o1
F008A448: 912a000a                 sll     %o0, %o2, %o0
F008A44C: d0240000                 st      %o0, [%l0]
F008A450: 9010001c                 mov     %i4, %o0
F008A454: 7ffffa56                 call    _vm_page_insert
F008A458: 952c800a                 sll     %l2, %o2, %o2
F008A45C: a404a001                 inc     %l2
F008A460: a0042030                 inc     0x30, %l0 ! '0'
F008A464: 80a48013                 cmp     %l2, %l3
F008A468: 06bfffef                 bl      loc_F008A424
F008A46C: b8072030                 inc     0x30, %i4 ! '0'
F008A470: 90100018                 mov     %i0, %o0
F008A474: 92100011                 mov     %l1, %o1
F008A478: 94102000                 mov     0, %o2
F008A47C: 7ffff3a7                 call    _vm_object_setpager
F008A480: 96102000                 mov     0, %o3
F008A484: 81c7e008                 ret
F008A488: 81e80000                 restore
