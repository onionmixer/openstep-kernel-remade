F006BBA8: 9de3bf90                 save    %sp, -0x70, %sp
F006BBAC: 90102014                 mov     0x14, %o0
F006BBB0: 921027d0                 mov     0x7D0, %o1
F006BBB4: 94102014                 mov     0x14, %o2
F006BBB8: 96102000                 mov     0, %o3
F006BBBC: 193c043f                 sethi   %hi(aNetListenerZon), %o4! "net listener zone"
F006BBC0: 400030de                 call    _zinit
F006BBC4: 981320e8                 bset    %lo(aNetListenerZon), %o4! "net listener zone"
F006BBC8: 133c04f0                 sethi   %hi(_listener_zone), %o1
F006BBCC: d0226118                 st      %o0, [%o1+%lo(_listener_zone)]
F006BBD0: 113c04bd                 sethi   %hi(dword_F012F684), %o0
F006BBD4: 92102011                 mov     0x11, %o1
F006BBD8: d2222284                 st      %o1, [%o0+%lo(dword_F012F684)]
F006BBDC: 90122284                 bset    %lo(dword_F012F684), %o0
F006BBE0: 921027ec                 mov     0x7EC, %o1
F006BBE4: d2222004                 st      %o1, [%o0+4]
F006BBE8: c0222008                 clr     [%o0+8]
F006BBEC: c022200c                 clr     [%o0+0xC]
F006BBF0: 921027a7                 mov     0x7A7, %o1
F006BBF4: d2222014                 st      %o1, [%o0+0x14]
F006BBF8: 113c04f090122120         set     _listeners, %o0
F006BC00: 92022080                 add     %o0, 0x80, %o1
F006BC04: 80a20009                 cmp     %o0, %o1
F006BC08: 3a800008                 bcc,a   loc_F006BC28
F006BC0C: 90102800                 mov     0x800, %o0
F006BC10: c0220000                 clr     [%o0]
F006BC14: 90022008                 inc     8, %o0
F006BC18: 80a20009                 cmp     %o0, %o1
F006BC1C: 0abffffd                 bcs     loc_F006BC10
F006BC20: 01000000                 nop
F006BC24: 90102800                 mov     0x800, %o0
F006BC28: 13000008                 sethi   0x2000, %o1
F006BC2C: 94102800                 mov     0x800, %o2
F006BC30: 96102000                 mov     0, %o3
F006BC34: 193c043f                 sethi   %hi(aMachNetMessage), %o4! "mach_net messages"
F006BC38: 400030c0                 call    _zinit
F006BC3C: 98132100                 bset    %lo(aMachNetMessage), %o4! "mach_net messages"
F006BC40: 213c04f0                 sethi   %hi(_mach_net_kmsg_zone), %l0
F006BC44: d02421a0                 st      %o0, [%l0+%lo(_mach_net_kmsg_zone)]
F006BC48: 92102000                 mov     0, %o1
F006BC4C: 94102000                 mov     0, %o2
F006BC50: 96102000                 mov     0, %o3
F006BC54: 400035ab                 call    _zchange
F006BC58: 98102000                 mov     0, %o4
F006BC5C: 9207bff4                 add     %fp, var_C, %o1
F006BC60: 113c04d1                 sethi   %hi(_kernel_map), %o0
F006BC64: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F006BC68: 40005ee7                 call    _kmem_alloc_wired
F006BC6C: 15000008                 sethi   0x2000, %o2
F006BC70: d00421a0                 ld      [%l0+%lo(_mach_net_kmsg_zone)], %o0
F006BC74: d207bff4                 ld      [%fp+var_C], %o1
F006BC78: 40003111                 call    _zcram
F006BC7C: 15000008                 sethi   0x2000, %o2
F006BC80: 81c7e008                 ret
F006BC84: 81e80000                 restore
