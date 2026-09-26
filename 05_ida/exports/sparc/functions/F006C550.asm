F006C550: 9de3bf90                 save    %sp, -0x70, %sp
F006C554: f0060000                 ld      [%i0], %i0
F006C558: d406200c                 ld      [%i0+0xC], %o2
F006C55C: 80a2a000                 cmp     %o2, 0
F006C560: 02800006                 be      loc_F006C578
F006C564: 90100018                 mov     %i0, %o0
F006C568: d2062008                 ld      [%i0+8], %o1
F006C56C: 96102001                 mov     1, %o3
F006C570: 400001aa                 call    _mfs_map_remove
F006C574: 9402400a                 add     %o1, %o2, %o2
F006C578: 113c04d0                 sethi   %hi(_page_mask), %o0
F006C57C: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F006C580: 94380009                 xnor    %g0, %o1, %o2
F006C584: a40e400a                 and     %i1, %o2, %l2
F006C588: 9006401a                 add     %i1, %i2, %o0
F006C58C: 90020009                 add     %o0, %o1, %o0
F006C590: 900a000a                 and     %o0, %o2, %o0
F006C594: b4220012                 sub     %o0, %l2, %i2
F006C598: 1100003f901223ff         set     0xFFFF, %o0
F006C5A0: 80a68008                 cmp     %i2, %o0
F006C5A4: 28800002                 bleu,a  loc_F006C5AC
F006C5A8: 35000040                 sethi   0x10000, %i2
F006C5AC: 273c04f0                 sethi   %hi(_mfs_map), %l3
F006C5B0: 2d3c04f0                 sethi   -0xFEC4000, %l6
F006C5B4: 2f3c04f0b615e218         set     _vm_info_queue, %i3
F006C5BC: 293c04f0a21521c0         set     _mfs_alloc_lock_data, %l1
F006C5C4: 2b3c043f                 sethi   -0xFEF0400, %l5
F006C5C8: d004e1d8                 ld      [%l3+%lo(_mfs_map)], %o0
F006C5CC: d2022014                 ld      [%o0+0x14], %o1
F006C5D0: 901521c0                 or      %l4, 0x1C0, %o0
F006C5D4: 7ffff1fc                 call    _lock_write
F006C5D8: d227bff4                 st      %o1, [%fp+var_C]
F006C5DC: 9207bff4                 add     %fp, var_C, %o1
F006C5E0: 9410001a                 mov     %i2, %o2
F006C5E4: d004e1d8                 ld      [%l3+0x1D8], %o0
F006C5E8: 96102001                 mov     1, %o3
F006C5EC: d8060000                 ld      [%i0], %o4
F006C5F0: 4000784d                 call    _vm_allocate_with_pager
F006C5F4: 9a100012                 mov     %l2, %o5
F006C5F8: a0100008                 mov     %o0, %l0
F006C5FC: 80a42003                 cmp     %l0, 3
F006C600: 1280002a                 bne     loc_F006C6A8
F006C604: 80a42000                 cmp     %l0, 0
F006C608: b215a210                 or      %l6, 0x210, %i1
F006C60C: d0064000                 ld      [%i1], %o0
F006C610: 80a22000                 cmp     %o0, 0
F006C614: 12bffffe                 bne     loc_F006C60C
F006C618: 01000000                 nop
F006C61C: 4000aa23                 call    _simple_lock_try
F006C620: 90100019                 mov     %i1, %o0
F006C624: 80a22000                 cmp     %o0, 0
F006C628: 02bffff9                 be      loc_F006C60C
F006C62C: d005e218                 ld      [%l7+0x218], %o0
F006C630: 80a2001b                 cmp     %o0, %i3
F006C634: 02800004                 be      loc_F006C644
F006C638: b2102000                 mov     0, %i1
F006C63C: 7fffff10                 call    _vm_info_dequeue
F006C640: b2100008                 mov     %o0, %i1
F006C644: c025a210                 clr     [%l6+0x210]
F006C648: 80a66000                 cmp     %i1, 0
F006C64C: 02800008                 be      loc_F006C66C
F006C650: 113c04f0                 sethi   -0xFEC4000, %o0
F006C654: 7ffff278                 call    _lock_done
F006C658: 90100011                 mov     %l1, %o0
F006C65C: 90100019                 mov     %i1, %o0
F006C660: 400000e0                 call    _mfs_memfree
F006C664: 92102001                 mov     1, %o1
F006C668: 3080000d                 ba,a    loc_F006C69C
F006C66C: 92102001                 mov     1, %o1
F006C670: d22221d0                 st      %o1, [%o0+0x1D0]
F006C674: 9014e1d8                 or      %l3, 0x1D8, %o0
F006C678: 40001197                 call    _assert_wait
F006C67C: 92102000                 mov     0, %o1
F006C680: d205611c                 ld      [%l5+0x11C], %o1
F006C684: 90100011                 mov     %l1, %o0
F006C688: 92026001                 inc     %o1
F006C68C: 7ffff26a                 call    _lock_done
F006C690: d225611c                 st      %o1, [%l5+0x11C]
F006C694: 4000180b                 call    _thread_block
F006C698: 01000000                 nop
F006C69C: 7ffff1ca                 call    _lock_write
F006C6A0: 90100011                 mov     %l1, %o0
F006C6A4: 30800009                 ba,a    loc_F006C6C8
F006C6A8: 02800008                 be      loc_F006C6C8
F006C6AC: 113c043f                 sethi   %hi(aUnexpectedErro), %o0! "Unexpected error on file map, ret = %d."...
F006C6B0: 90122148                 bset    %lo(aUnexpectedErro), %o0! "Unexpected error on file map, ret = %d."...
F006C6B4: 7ffe9fe9                 call    _printf
F006C6B8: 92100010                 mov     %l0, %o1
F006C6BC: 113c043f                 sethi   %hi(aRemapVnode), %o0! "remap_vnode"
F006C6C0: 7ffea2ac                 call    _panic
F006C6C4: 90122178                 bset    %lo(aRemapVnode), %o0! "remap_vnode"
F006C6C8: 7ffff25b                 call    _lock_done
F006C6CC: 901521c0                 or      %l4, 0x1C0, %o0
F006C6D0: 80a42000                 cmp     %l0, 0
F006C6D4: 12bfffbe                 bne     loc_F006C5CC
F006C6D8: d004e1d8                 ld      [%l3+0x1D8], %o0
F006C6DC: f426200c                 st      %i2, [%i0+0xC]
F006C6E0: d007bff4                 ld      [%fp+var_C], %o0
F006C6E4: e4262010                 st      %l2, [%i0+0x10]
F006C6E8: d0262008                 st      %o0, [%i0+8]
F006C6EC: 81c7e008                 ret
F006C6F0: 91e82001                 restore %g0, 1, %o0
