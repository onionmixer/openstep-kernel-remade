F0027654: 9de3bf98                 save    %sp, -0x68, %sp
F0027658: 273c04cf9014e1dc         set     dword_F0133DDC, %o0
F0027660: d0023ffc                 ld      [%o0-4], %o0
F0027664: d204e1dc                 ld      [%l3+0x1DC], %o1
F0027668: d0020000                 ld      [%o0], %o0
F002766C: e0026024                 ld      [%o1+0x24], %l0
F0027670: 7fff9d2c                 call    _get_posix_proc
F0027674: d0522030                 ldsh    [%o0+0x30], %o0
F0027678: a4100008                 mov     %o0, %l2
F002767C: 232fffff                 sethi   -0x40000400, %l1
F0027680: d204a018                 ld      [%l2+0x18], %o1
F0027684: a21463ff                 bset    0x3FF, %l1
F0027688: d0042004                 ld      [%l0+4], %o0
F002768C: 920a4011                 and     %o1, %l1, %o1
F0027690: 91322004                 srl     %o0, 4, %o0
F0027694: 900a2001                 and     %o0, 1, %o0
F0027698: 912a201e                 sll     %o0, 30, %o0
F002769C: 92124008                 bset    %o0, %o1
F00276A0: d224a018                 st      %o1, [%l2+0x18]
F00276A4: d0040000                 ld      [%l0], %o0
F00276A8: d2042004                 ld      [%l0+4], %o1
F00276AC: d4042008                 ld      [%l0+8], %o2
F00276B0: 40000015                 call    _copen
F00276B4: 92026001                 inc     %o1
F00276B8: d204e1dc                 ld      [%l3+0x1DC], %o1
F00276BC: d02a6038                 stb     %o0, [%o1+0x38]
F00276C0: d004a018                 ld      [%l2+0x18], %o0
F00276C4: 900a0011                 and     %o0, %l1, %o0
F00276C8: d024a018                 st      %o0, [%l2+0x18]
F00276CC: 81c7e008                 ret
F00276D0: 81e80000                 restore
