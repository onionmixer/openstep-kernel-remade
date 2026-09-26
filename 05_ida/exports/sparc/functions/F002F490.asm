F002F490: 9de3bf98                 save    %sp, -0x68, %sp
F002F494: 153c04d8                 sethi   %hi(_netisr), %o2
F002F498: 113c04d8                 sethi   %hi(_soft_net_wakeup), %o0
F002F49C: d202a3d8                 ld      [%o2+%lo(_netisr)], %o1
F002F4A0: 901223e0                 bset    %lo(_soft_net_wakeup), %o0
F002F4A4: 92126004                 bset    4, %o1
F002F4A8: 7fff8e50                 call    _wakeup
F002F4AC: d222a3d8                 st      %o1, [%o2+%lo(_netisr)]
F002F4B0: 113c04d9                 sethi   %hi(_ipintrq), %o0
F002F4B4: 40019dc1                 call    _spltty
F002F4B8: a2122080                 or      %o0, %lo(_ipintrq), %l1
F002F4BC: d4046008                 ld      [%l1+8], %o2
F002F4C0: d204600c                 ld      [%l1+0xC], %o1
F002F4C4: 80a28009                 cmp     %o2, %o1
F002F4C8: 16800046                 bge     loc_F002F5E0
F002F4CC: a8100008                 mov     %o0, %l4
F002F4D0: d2066004                 ld      [%i1+4], %o1
F002F4D4: 90027ff0                 add     %o1, -0x10, %o0
F002F4D8: 80a2206c                 cmp     %o0, 0x6C ! 'l'
F002F4DC: 18800008                 bgu     loc_F002F4FC
F002F4E0: a0100019                 mov     %i1, %l0
F002F4E4: 92027ffc                 inc     -4, %o1
F002F4E8: d0166008                 lduh    [%i1+8], %o0
F002F4EC: d2266004                 st      %o1, [%i1+4]
F002F4F0: 90022004                 inc     4, %o0
F002F4F4: 1080002b                 ba      loc_F002F5A0
F002F4F8: d0366008                 sth     %o0, [%i1+8]
F002F4FC: 40019daf                 call    _spltty
F002F500: 273c04d3                 sethi   %hi(_mfree), %l3
F002F504: e004e168                 ld      [%l3+%lo(_mfree)], %l0
F002F508: 80a42000                 cmp     %l0, 0
F002F50C: 02800018                 be      loc_F002F56C
F002F510: a4100008                 mov     %o0, %l2
F002F514: d054200a                 ldsh    [%l0+0xA], %o0
F002F518: 80a22000                 cmp     %o0, 0
F002F51C: 02800004                 be      loc_F002F52C
F002F520: 113c0431                 sethi   %hi(aMget_7), %o0! "mget"
F002F524: 7fff9713                 call    _panic
F002F528: 901220c0                 bset    %lo(aMget_7), %o0! "mget"
F002F52C: 90102002                 mov     2, %o0
F002F530: d034200a                 sth     %o0, [%l0+0xA]
F002F534: 153c04d29412a2f0         set     _mbstat, %o2
F002F53C: d012a01c                 lduh    [%o2+0x1C], %o0
F002F540: d212a020                 lduh    [%o2+0x20], %o1
F002F544: 90023fff                 inc     -1, %o0
F002F548: d032a01c                 sth     %o0, [%o2+0x1C]
F002F54C: 92026001                 inc     %o1
F002F550: d232a020                 sth     %o1, [%o2+0x20]
F002F554: 9010200c                 mov     0xC, %o0
F002F558: d2040000                 ld      [%l0], %o1
F002F55C: d0242004                 st      %o0, [%l0+4]
F002F560: d224e168                 st      %o1, [%l3+0x168]
F002F564: 10800006                 ba      loc_F002F57C
F002F568: c0240000                 clr     [%l0]
F002F56C: 90102000                 mov     0, %o0
F002F570: 7fffb97f                 call    _m_more
F002F574: 92102002                 mov     2, %o1
F002F578: a0100008                 mov     %o0, %l0
F002F57C: 40019dea                 call    _splx
F002F580: 90100012                 mov     %l2, %o0
F002F584: 80a42000                 cmp     %l0, 0
F002F588: 02800007                 be      loc_F002F5A4
F002F58C: 9010200c                 mov     0xC, %o0
F002F590: d0242004                 st      %o0, [%l0+4]
F002F594: 90102004                 mov     4, %o0
F002F598: d0342008                 sth     %o0, [%l0+8]
F002F59C: f2240000                 st      %i1, [%l0]
F002F5A0: 80a42000                 cmp     %l0, 0
F002F5A4: 22800010                 be,a    loc_F002F5E4
F002F5A8: d2046010                 ld      [%l1+0x10], %o1
F002F5AC: d0042004                 ld      [%l0+4], %o0
F002F5B0: f0240008                 st      %i0, [%l0+%o0]
F002F5B4: c024207c                 clr     [%l0+0x7C]
F002F5B8: d0046004                 ld      [%l1+4], %o0
F002F5BC: 80a22000                 cmp     %o0, 0
F002F5C0: 32800003                 bne,a   loc_F002F5CC
F002F5C4: e022207c                 st      %l0, [%o0+0x7C]
F002F5C8: e0244000                 st      %l0, [%l1]
F002F5CC: d0046008                 ld      [%l1+8], %o0
F002F5D0: e0246004                 st      %l0, [%l1+4]
F002F5D4: 90022001                 inc     %o0
F002F5D8: 10800007                 ba      loc_F002F5F4
F002F5DC: d0246008                 st      %o0, [%l1+8]
F002F5E0: d2046010                 ld      [%l1+0x10], %o1
F002F5E4: 90100019                 mov     %i1, %o0
F002F5E8: 92026001                 inc     %o1
F002F5EC: 7fffb99e                 call    _m_freem
F002F5F0: d2246010                 st      %o1, [%l1+0x10]
F002F5F4: 40019dcc                 call    _splx
F002F5F8: 90100014                 mov     %l4, %o0
F002F5FC: 81c7e008                 ret
F002F600: 81e80000                 restore
