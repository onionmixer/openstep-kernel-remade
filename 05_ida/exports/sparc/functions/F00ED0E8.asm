F00ED0E8: 9de3bf98                 save    %sp, -0x68, %sp
F00ED0EC: 7ffdec51                 call    _malloc
F00ED0F0: 90102008                 mov     8, %o0! void *
F00ED0F4: 7ffdec83                 call    _free
F00ED0F8: 253c04bc                 sethi   %hi(dword_F012F080), %l2
F00ED0FC: 40000e94                 call    _NXDefaultMallocZone
F00ED100: 233c04bc                 sethi   %hi(unk_F012F070), %l1
F00ED104: 40000e92                 call    _NXDefaultMallocZone
F00ED108: a0100008                 mov     %o0, %l0
F00ED10C: d4042004                 ld      [%l0+4], %o2
F00ED110: 9fc28000                 call    %o2
F00ED114: 92102014                 mov     0x14, %o1
F00ED118: d024a080                 st      %o0, [%l2+%lo(dword_F012F080)]
F00ED11C: a2146070                 bset    %lo(unk_F012F070), %l1
F00ED120: e2220000                 st      %l1, [%o0]
F00ED124: a0102001                 mov     1, %l0
F00ED128: e0222004                 st      %l0, [%o0+4]
F00ED12C: 40000e88                 call    _NXDefaultMallocZone
F00ED130: e0222008                 st      %l0, [%o0+8]
F00ED134: 92102001                 mov     1, %o1
F00ED138: 40000e90                 call    _NXZoneCalloc
F00ED13C: 94102008                 mov     8, %o2
F00ED140: d204a080                 ld      [%l2+0x80], %o1
F00ED144: d022600c                 st      %o0, [%o1+0xC]
F00ED148: c0226010                 clr     [%o1+0x10]
F00ED14C: d002600c                 ld      [%o1+0xC], %o0
F00ED150: e0220000                 st      %l0, [%o0]
F00ED154: d002600c                 ld      [%o1+0xC], %o0
F00ED158: e2222004                 st      %l1, [%o0+4]
F00ED15C: 81c7e008                 ret
F00ED160: 81e80000                 restore
