F00BC654: 9de3bf90                 save    %sp, -0x70, %sp
F00BC658: d0062108                 ld      [%i0+0x108], %o0! id
F00BC65C: 133c0504                 sethi   %hi(paLock), %o1
F00BC660: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00BC664: 4000d483                 call    _objc_msgSend
F00BC668: a0102000                 mov     0, %l0
F00BC66C: 11280000                 sethi   -0x60000000, %o0
F00BC670: 808e8008                 btst    %o0, %i2
F00BC674: 22800038                 be,a    loc_F00BC754
F00BC678: d0062108                 ld      [%i0+0x108], %o0
F00BC67C: d0062114                 ld      [%i0+0x114], %o0
F00BC680: 80a22001                 cmp     %o0, 1
F00BC684: 02800033                 be      loc_F00BC750
F00BC688: 80a22003                 cmp     %o0, 3
F00BC68C: 22800032                 be,a    loc_F00BC754
F00BC690: d0062108                 ld      [%i0+0x108], %o0
F00BC694: 7ffd4cb6                 call    _suser
F00BC698: 01000000                 nop
F00BC69C: 80a22000                 cmp     %o0, 0
F00BC6A0: 32800004                 bne,a   loc_F00BC6B0
F00BC6A4: d0062114                 ld      [%i0+0x114], %o0
F00BC6A8: 1080002a                 ba      loc_F00BC750
F00BC6AC: a010200d                 mov     0xD, %l0
F00BC6B0: 80a22004                 cmp     %o0, 4
F00BC6B4: 12800004                 bne     loc_F00BC6C4
F00BC6B8: 01000000                 nop
F00BC6BC: 10800025                 ba      loc_F00BC750
F00BC6C0: a0102010                 mov     0x10, %l0
F00BC6C4: 40000a15                 call    _FBAllocateConsole
F00BC6C8: 01000000                 nop
F00BC6CC: 133c0482                 sethi   %hi(_wserver_on), %o1
F00BC6D0: d20262ec                 ld      [%o1+%lo(_wserver_on)], %o1
F00BC6D4: 80a26000                 cmp     %o1, 0
F00BC6D8: 12800009                 bne     loc_F00BC6FC
F00BC6DC: d0262110                 st      %o0, [%i0+0x110]
F00BC6E0: 113c04fd                 sethi   %hi(_basicConsoleMode), %o0
F00BC6E4: d0022230                 ld      [%o0+%lo(_basicConsoleMode)], %o0
F00BC6E8: 80a22000                 cmp     %o0, 0
F00BC6EC: 02800004                 be      loc_F00BC6FC
F00BC6F0: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BC6F4: d0022228                 ld      [%o0+%lo(_basicConsole)], %o0
F00BC6F8: d0262110                 st      %o0, [%i0+0x110]
F00BC6FC: d0062110                 ld      [%i0+0x110], %o0
F00BC700: 80a22000                 cmp     %o0, 0
F00BC704: 12800006                 bne     loc_F00BC71C
F00BC708: 92102003                 mov     3, %o1
F00BC70C: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BC710: d0022228                 ld      [%o0+%lo(_basicConsole)], %o0
F00BC714: d0262110                 st      %o0, [%i0+0x110]
F00BC718: d0062110                 ld      [%i0+0x110], %o0
F00BC71C: 173c047f                 sethi   %hi(off_F011FE80), %o3! "Alert"
F00BC720: d802e280                 ld      [%o3+%lo(off_F011FE80)], %o4! "Alert"
F00BC724: 94102000                 mov     0, %o2
F00BC728: da022004                 ld      [%o0+4], %o5
F00BC72C: 9fc34000                 call    %o5
F00BC730: 96102001                 mov     1, %o3
F00BC734: d0062114                 ld      [%i0+0x114], %o0
F00BC738: 92102003                 mov     3, %o1
F00BC73C: d0262118                 st      %o0, [%i0+0x118]
F00BC740: d006211c                 ld      [%i0+0x11C], %o0
F00BC744: d2262114                 st      %o1, [%i0+0x114]
F00BC748: 90022001                 inc     %o0
F00BC74C: d026211c                 st      %o0, [%i0+0x11C]
F00BC750: d0062108                 ld      [%i0+0x108], %o0! id
F00BC754: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00BC758: 4000d446                 call    _objc_msgSend
F00BC75C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BC760: 81c7e008                 ret
F00BC764: 91e80010                 restore %g0, %l0, %o0
