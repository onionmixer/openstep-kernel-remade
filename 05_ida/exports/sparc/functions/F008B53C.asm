F008B53C: 9de3bf98                 save    %sp, -0x68, %sp
F008B540: 80a66000                 cmp     %i1, 0
F008B544: 22800006                 be,a    loc_F008B55C
F008B548: d0060000                 ld      [%i0], %o0
F008B54C: d0162004                 lduh    [%i0+4], %o0
F008B550: 90122002                 bset    2, %o0
F008B554: d0362004                 sth     %o0, [%i0+4]
F008B558: d0060000                 ld      [%i0], %o0
F008B55C: d0020000                 ld      [%o0], %o0
F008B560: 80a22000                 cmp     %o0, 0
F008B564: 1280001c                 bne     loc_F008B5D4
F008B568: 113c04f6                 sethi   -0xFEC2800, %o0
F008B56C: 113c04c3                 sethi   %hi(dword_F0130F64), %o0
F008B570: d2022364                 ld      [%o0+%lo(dword_F0130F64)], %o1
F008B574: 90122364                 bset    %lo(dword_F0130F64), %o0
F008B578: 80a24008                 cmp     %o1, %o0
F008B57C: 0280000b                 be      loc_F008B5A8
F008B580: 94100008                 mov     %o0, %o2
F008B584: d0026008                 ld      [%o1+8], %o0
F008B588: 80a20018                 cmp     %o0, %i0
F008B58C: 32800004                 bne,a   loc_F008B59C
F008B590: d2024000                 ld      [%o1], %o1
F008B594: 10800018                 ba      locret_F008B5F4
F008B598: b0102000                 mov     0, %i0
F008B59C: 80a2400a                 cmp     %o1, %o2
F008B5A0: 32bffffa                 bne,a   loc_F008B588
F008B5A4: d0026008                 ld      [%o1+8], %o0
F008B5A8: 7fffffca                 call    _vnode_pager_create
F008B5AC: 90100018                 mov     %i0, %o0
F008B5B0: 80a6a000                 cmp     %i2, 0
F008B5B4: 22800008                 be,a    loc_F008B5D4
F008B5B8: 113c04f6                 sethi   -0xFEC2800, %o0
F008B5BC: d0060000                 ld      [%i0], %o0
F008B5C0: 7fffef66                 call    _vm_object_lookup
F008B5C4: d0020000                 ld      [%o0], %o0
F008B5C8: 7fffee26                 call    _vm_object_cache_object
F008B5CC: 92102001                 mov     1, %o1
F008B5D0: 113c04f6                 sethi   -0xFEC2800, %o0
F008B5D4: e00221a0                 ld      [%o0+0x1A0], %l0
F008B5D8: 7fffb6bd                 call    _zalloc
F008B5DC: 90100010                 mov     %l0, %o0
F008B5E0: 92100008                 mov     %o0, %o1
F008B5E4: 7fffb6fb                 call    _zfree
F008B5E8: 90100010                 mov     %l0, %o0
F008B5EC: d0060000                 ld      [%i0], %o0
F008B5F0: f0020000                 ld      [%o0], %i0
F008B5F4: 81c7e008                 ret
F008B5F8: 81e80000                 restore
