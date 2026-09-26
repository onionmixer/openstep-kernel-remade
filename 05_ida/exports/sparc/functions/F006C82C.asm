F006C82C: 9de3bf98                 save    %sp, -0x68, %sp
F006C830: e0060000                 ld      [%i0], %l0
F006C834: 40000015                 call    _vmp_get
F006C838: 90100010                 mov     %l0, %o0
F006C83C: 113c043f                 sethi   %hi(_mfs_max_window), %o0
F006C840: d0022124                 ld      [%o0+%lo(_mfs_max_window)], %o0
F006C844: 80a68008                 cmp     %i2, %o0
F006C848: 38800002                 bgu,a   loc_F006C850
F006C84C: b4100008                 mov     %o0, %i2
F006C850: d004200c                 ld      [%l0+0xC], %o0
F006C854: 80a68008                 cmp     %i2, %o0
F006C858: 08800005                 bleu    locret_F006C86C
F006C85C: 90100018                 mov     %i0, %o0
F006C860: 92100019                 mov     %i1, %o1
F006C864: 7fffff3b                 call    _remap_vnode
F006C868: 9410001a                 mov     %i2, %o2
F006C86C: 81c7e008                 ret
F006C870: 81e80000                 restore
