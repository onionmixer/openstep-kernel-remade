F008AEAC: 9de3bf98                 save    %sp, -0x68, %sp
F008AEB0: f0060000                 ld      [%i0], %i0
F008AEB4: 93362018                 srl     %i0, 24, %o1
F008AEB8: 80a26000                 cmp     %o1, 0
F008AEBC: 02800026                 be      locret_F008AF54
F008AEC0: 113c04c3                 sethi   %hi(unk_F0130F70), %o0
F008AEC4: 90122370                 bset    %lo(unk_F0130F70), %o0
F008AEC8: 932a6002                 sll     %o1, 2, %o1
F008AECC: e0024008                 ld      [%o1+%o0], %l0
F008AED0: a2042034                 add     %l0, 0x34, %l1 ! '4'
F008AED4: 90100011                 mov     %l1, %o0
F008AED8: 133fc000                 sethi   -0x1000000, %o1
F008AEDC: 7fff77ba                 call    _lock_write
F008AEE0: b02e0009                 bclr    %o1, %i0
F008AEE4: d0042014                 ld      [%l0+0x14], %o0
F008AEE8: 80a60008                 cmp     %i0, %o0
F008AEEC: 06800004                 bl      loc_F008AEFC
F008AEF0: 113c0447                 sethi   %hi(aVnodePagerDeal), %o0! "vnode_pager_deallocpage"
F008AEF4: 7ffe289f                 call    _panic
F008AEF8: 901222c8                 bset    %lo(aVnodePagerDeal), %o0! "vnode_pager_deallocpage"
F008AEFC: d0042024                 ld      [%l0+0x24], %o0
F008AF00: 80a60008                 cmp     %i0, %o0
F008AF04: 26800002                 bl,a    loc_F008AF0C
F008AF08: f0242024                 st      %i0, [%l0+0x24]
F008AF0C: 80a62000                 cmp     %i0, 0
F008AF10: 16800003                 bge     loc_F008AF1C
F008AF14: 94100018                 mov     %i0, %o2
F008AF18: 94062007                 add     %i0, 7, %o2
F008AF1C: 953aa003                 sra     %o2, 3, %o2
F008AF20: 932aa003                 sll     %o2, 3, %o1
F008AF24: 92260009                 sub     %i0, %o1, %o1
F008AF28: d8042010                 ld      [%l0+0x10], %o4
F008AF2C: 90102001                 mov     1, %o0
F008AF30: d60b000a                 ldub    [%o4+%o2], %o3
F008AF34: 912a0009                 sll     %o0, %o1, %o0
F008AF38: 902ac008                 andn    %o3, %o0, %o0
F008AF3C: d02b000a                 stb     %o0, [%o4+%o2]
F008AF40: d2042018                 ld      [%l0+0x18], %o1
F008AF44: 90100011                 mov     %l1, %o0
F008AF48: 92026001                 inc     %o1
F008AF4C: 7fff783a                 call    _lock_done
F008AF50: d2242018                 st      %o1, [%l0+0x18]
F008AF54: 81c7e008                 ret
F008AF58: 81e80000                 restore
