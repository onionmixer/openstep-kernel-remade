F00BA60C: 9de3bf98                 save    %sp, -0x68, %sp
F00BA610: d6062010                 ld      [%i0+0x10], %o3
F00BA614: e0062018                 ld      [%i0+0x18], %l0
F00BA618: d40ac000                 ldub    [%o3], %o2
F00BA61C: d20c200e                 ldub    [%l0+0xE], %o1
F00BA620: 90102010                 mov     0x10, %o0
F00BA624: d8040000                 ld      [%l0], %o4
F00BA628: d42c200e                 stb     %o2, [%l0+0xE]
F00BA62C: d02ac000                 stb     %o0, [%o3]
F00BA630: 921a8009                 btog    %o2, %o1
F00BA634: 808a6080                 btst    0x80, %o1
F00BA638: 02800011                 be      loc_F00BA67C
F00BA63C: 808aa080                 btst    0x80, %o2
F00BA640: 32800010                 bne,a   loc_F00BA680
F00BA644: d014200c                 lduh    [%l0+0xC], %o0
F00BA648: d0142006                 lduh    [%l0+6], %o0
F00BA64C: 90022001                 inc     %o0
F00BA650: d0342006                 sth     %o0, [%l0+6]
F00BA654: d00ae002                 ldub    [%o3+2], %o0
F00BA658: 90102030                 mov     0x30, %o0 ! '0'
F00BA65C: d02ac000                 stb     %o0, [%o3]
F00BA660: d0132038                 lduh    [%o4+0x38], %o0
F00BA664: 900a201f                 and     %o0, 0x1F, %o0
F00BA668: 80a22002                 cmp     %o0, 2
F00BA66C: 32800005                 bne,a   loc_F00BA680
F00BA670: d014200c                 lduh    [%l0+0xC], %o0
F00BA674: 7fffd214                 call    _prom_enter_mon
F00BA678: 01000000                 nop
F00BA67C: d014200c                 lduh    [%l0+0xC], %o0
F00BA680: d214200a                 lduh    [%l0+0xA], %o1
F00BA684: 90022001                 inc     %o0
F00BA688: d034200c                 sth     %o0, [%l0+0xC]
F00BA68C: 92026001                 inc     %o1
F00BA690: d234200a                 sth     %o1, [%l0+0xA]
F00BA694: d00e2030                 ldub    [%i0+0x30], %o0
F00BA698: 133c04fd                 sethi   %hi(_zssoftpend), %o1
F00BA69C: 90122001                 bset    1, %o0
F00BA6A0: d02e2030                 stb     %o0, [%i0+0x30]
F00BA6A4: d00261d8                 ld      [%o1+%lo(_zssoftpend)], %o0
F00BA6A8: 80a22000                 cmp     %o0, 0
F00BA6AC: 12800004                 bne     locret_F00BA6BC
F00BA6B0: 90102001                 mov     1, %o0
F00BA6B4: 400003a3                 call    _setzssoft
F00BA6B8: d02261d8                 st      %o0, [%o1+%lo(_zssoftpend)]
F00BA6BC: 81c7e008                 ret
F00BA6C0: 81e80000                 restore
