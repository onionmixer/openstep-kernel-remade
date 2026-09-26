F0075724: 9de3bf98                 save    %sp, -0x68, %sp
F0075728: 80a62000                 cmp     %i0, 0
F007572C: 0280009d                 be      loc_F00759A0
F0075730: 9210001a                 mov     %i2, %o1
F0075734: 80a66001                 cmp     %i1, 1
F0075738: 12800065                 bne     loc_F00758CC
F007573C: 80a66002                 cmp     %i1, 2
F0075740: d006c000                 ld      [%i3], %o0
F0075744: 80a2200a                 cmp     %o0, 0xA
F0075748: 28800097                 bleu,a  locret_F00759A4
F007574C: b0102004                 mov     4, %i0
F0075750: 4000850e                 call    _splusclock
F0075754: b4100009                 mov     %o1, %i2
F0075758: a0100008                 mov     %o0, %l0
F007575C: b2062020                 add     %i0, 0x20, %i1 ! ' '
F0075760: d0064000                 ld      [%i1], %o0
F0075764: 80a22000                 cmp     %o0, 0
F0075768: 12bffffe                 bne     loc_F0075760
F007576C: 01000000                 nop
F0075770: 400085ce                 call    _simple_lock_try
F0075774: 90100019                 mov     %i1, %o0
F0075778: 80a22000                 cmp     %o0, 0
F007577C: 02bffff9                 be      loc_F0075760
F0075780: 01000000                 nop
F0075784: d006204c                 ld      [%i0+0x4C], %o0
F0075788: 808a2004                 btst    4, %o0
F007578C: 1280000b                 bne     loc_F00757B8
F0075790: 90100018                 mov     %i0, %o0
F0075794: d0062070                 ld      [%i0+0x70], %o0
F0075798: 133c04f0                 sethi   %hi(_sched_tick), %o1
F007579C: d2026298                 ld      [%o1+%lo(_sched_tick)], %o1
F00757A0: 80a20009                 cmp     %o0, %o1
F00757A4: 22800005                 be,a    loc_F00757B8
F00757A8: 90100018                 mov     %i0, %o0
F00757AC: 7ffff0a7                 call    _update_priority
F00757B0: 90100018                 mov     %i0, %o0
F00757B4: 90100018                 mov     %i0, %o0
F00757B8: 9210001a                 mov     %i2, %o1
F00757BC: 4000088e                 call    _thread_read_times
F00757C0: 9406a008                 add     %i2, 8, %o2
F00757C4: d0062050                 ld      [%i0+0x50], %o0
F00757C8: d026a014                 st      %o0, [%i2+0x14]
F00757CC: d0062058                 ld      [%i0+0x58], %o0
F00757D0: d026a018                 st      %o0, [%i2+0x18]
F00757D4: d0062068                 ld      [%i0+0x68], %o0
F00757D8: 7ffe438a                 call    _udiv
F00757DC: 921023e8                 mov     0x3E8, %o1
F00757E0: 92100008                 mov     %o0, %o1! int
F00757E4: d226a010                 st      %o1, [%i2+0x10]
F00757E8: 912a6001                 sll     %o1, 1, %o0
F00757EC: 90020009                 add     %o0, %o1, %o0! int
F00757F0: 7ffe4386                 call    _div
F00757F4: 92102005                 mov     5, %o1
F00757F8: 96100008                 mov     %o0, %o3
F00757FC: d626a010                 st      %o3, [%i2+0x10]
F0075800: 113c04f1                 sethi   %hi(_sched_usec), %o0
F0075804: 952ae005                 sll     %o3, 5, %o2
F0075808: d2022080                 ld      [%o0+%lo(_sched_usec)], %o1! int
F007580C: 9422800b                 sub     %o2, %o3, %o2
F0075810: 912aa006                 sll     %o2, 6, %o0
F0075814: 9022000a                 sub     %o0, %o2, %o0
F0075818: 912a2003                 sll     %o0, 3, %o0
F007581C: 9002000b                 add     %o0, %o3, %o0! int
F0075820: 7ffe437a                 call    _div
F0075824: 912a2006                 sll     %o0, 6, %o0
F0075828: d026a010                 st      %o0, [%i2+0x10]
F007582C: d006204c                 ld      [%i0+0x4C], %o0
F0075830: 808a2100                 btst    0x100, %o0
F0075834: 12800005                 bne     loc_F0075848
F0075838: 94102001                 mov     1, %o2
F007583C: 91322006                 srl     %o0, 6, %o0
F0075840: 940a2002                 and     %o0, 2, %o2
F0075844: d006204c                 ld      [%i0+0x4C], %o0
F0075848: 808a2010                 btst    0x10, %o0
F007584C: 1280000e                 bne     loc_F0075884
F0075850: 92102005                 mov     5, %o1
F0075854: 808a2004                 btst    4, %o0
F0075858: 1280000b                 bne     loc_F0075884
F007585C: 92102001                 mov     1, %o1
F0075860: 808a2008                 btst    8, %o0
F0075864: 12800008                 bne     loc_F0075884
F0075868: 92102004                 mov     4, %o1
F007586C: 808a2002                 btst    2, %o0
F0075870: 12800005                 bne     loc_F0075884
F0075874: 92102002                 mov     2, %o1
F0075878: 900a2001                 and     %o0, 1, %o0
F007587C: 90200008                 neg     %o0
F0075880: 920a2003                 and     %o0, 3, %o1
F0075884: d226a01c                 st      %o1, [%i2+0x1C]
F0075888: d426a020                 st      %o2, [%i2+0x20]
F007588C: d006208c                 ld      [%i0+0x8C], %o0
F0075890: 80a26001                 cmp     %o1, 1
F0075894: 12800004                 bne     loc_F00758A4
F0075898: d026a024                 st      %o0, [%i2+0x24]
F007589C: 10800007                 ba      loc_F00758B8
F00758A0: c026a028                 clr     [%i2+0x28]
F00758A4: 113c04f0                 sethi   %hi(_sched_tick), %o0
F00758A8: d0022298                 ld      [%o0+%lo(_sched_tick)], %o0
F00758AC: d2062070                 ld      [%i0+0x70], %o1
F00758B0: 90220009                 sub     %o0, %o1, %o0
F00758B4: d026a028                 st      %o0, [%i2+0x28]
F00758B8: c0262020                 clr     [%i0+0x20]
F00758BC: 4000851a                 call    _splx
F00758C0: 90100010                 mov     %l0, %o0
F00758C4: 10800034                 ba      loc_F0075994
F00758C8: 9010200b                 mov     0xB, %o0
F00758CC: 32800036                 bne,a   locret_F00759A4
F00758D0: b0102004                 mov     4, %i0
F00758D4: d006c000                 ld      [%i3], %o0
F00758D8: 80a22006                 cmp     %o0, 6
F00758DC: 28800032                 bleu,a  locret_F00759A4
F00758E0: b0102004                 mov     4, %i0
F00758E4: 400084a9                 call    _splusclock
F00758E8: b4100009                 mov     %o1, %i2
F00758EC: a0100008                 mov     %o0, %l0
F00758F0: b2062020                 add     %i0, 0x20, %i1 ! ' '
F00758F4: d0064000                 ld      [%i1], %o0
F00758F8: 80a22000                 cmp     %o0, 0
F00758FC: 12bffffe                 bne     loc_F00758F4
F0075900: 01000000                 nop
F0075904: 40008569                 call    _simple_lock_try
F0075908: 90100019                 mov     %i1, %o0
F007590C: 80a22000                 cmp     %o0, 0
F0075910: 02bffff9                 be      loc_F00758F4
F0075914: 01000000                 nop
F0075918: d0062060                 ld      [%i0+0x60], %o0
F007591C: d0268000                 st      %o0, [%i2]
F0075920: d0062060                 ld      [%i0+0x60], %o0
F0075924: 80a22002                 cmp     %o0, 2
F0075928: 02800004                 be      loc_F0075938
F007592C: 80a22004                 cmp     %o0, 4
F0075930: 32800009                 bne,a   loc_F0075954
F0075934: c026a004                 clr     [%i2+4]
F0075938: d006205c                 ld      [%i0+0x5C], %o0! int
F007593C: 133c043e                 sethi   %hi(_tick), %o1
F0075940: 7ffe42f0                 call    _umul
F0075944: d20263e4                 ld      [%o1+%lo(_tick)], %o1! int
F0075948: 7ffe4330                 call    _div
F007594C: 921023e8                 mov     0x3E8, %o1
F0075950: d026a004                 st      %o0, [%i2+4]
F0075954: d0062050                 ld      [%i0+0x50], %o0
F0075958: d026a008                 st      %o0, [%i2+8]
F007595C: d0062054                 ld      [%i0+0x54], %o0
F0075960: d026a00c                 st      %o0, [%i2+0xC]
F0075964: d0062058                 ld      [%i0+0x58], %o0
F0075968: d026a010                 st      %o0, [%i2+0x10]
F007596C: d0062064                 ld      [%i0+0x64], %o0
F0075970: 90380008                 xnor    %g0, %o0, %o0
F0075974: 9132201f                 srl     %o0, 31, %o0
F0075978: d026a014                 st      %o0, [%i2+0x14]
F007597C: d2062064                 ld      [%i0+0x64], %o1
F0075980: d226a018                 st      %o1, [%i2+0x18]
F0075984: c0262020                 clr     [%i0+0x20]
F0075988: 400084e7                 call    _splx
F007598C: 90100010                 mov     %l0, %o0
F0075990: 90102007                 mov     7, %o0
F0075994: d026c000                 st      %o0, [%i3]
F0075998: 10800003                 ba      locret_F00759A4
F007599C: b0102000                 mov     0, %i0
F00759A0: b0102004                 mov     4, %i0
F00759A4: 81c7e008                 ret
F00759A8: 81e80000                 restore
