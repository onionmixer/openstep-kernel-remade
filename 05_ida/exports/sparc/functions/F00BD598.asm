F00BD598: 9de3bf98                 save    %sp, -0x68, %sp
F00BD59C: 213c04fd                 sethi   %hi(_kmId), %l0
F00BD5A0: d0042240                 ld      [%l0+%lo(_kmId)], %o0
F00BD5A4: 80a22000                 cmp     %o0, 0
F00BD5A8: 32800038                 bne,a   loc_F00BD688
F00BD5AC: d0022108                 ld      [%o0+0x108], %o0
F00BD5B0: 113c04fd                 sethi   %hi(_basicConsoleMode), %o0
F00BD5B4: d0022230                 ld      [%o0+%lo(_basicConsoleMode)], %o0
F00BD5B8: 80a22003                 cmp     %o0, 3
F00BD5BC: 02800004                 be      loc_F00BD5CC
F00BD5C0: 80a22001                 cmp     %o0, 1
F00BD5C4: 12800017                 bne     loc_F00BD620
F00BD5C8: 01000000                 nop
F00BD5CC: 153c04fd                 sethi   %hi(_basicConsole), %o2
F00BD5D0: d002a228                 ld      [%o2+%lo(_basicConsole)], %o0
F00BD5D4: 80a22000                 cmp     %o0, 0
F00BD5D8: 0280006b                 be      locret_F00BD784
F00BD5DC: 01000000                 nop
F00BD5E0: d04e4000                 ldsb    [%i1], %o0
F00BD5E4: 80a22000                 cmp     %o0, 0
F00BD5E8: 02800067                 be      locret_F00BD784
F00BD5EC: d20e4000                 ldub    [%i1], %o1
F00BD5F0: a010000a                 mov     %o2, %l0
F00BD5F4: b2066001                 inc     %i1
F00BD5F8: d0042228                 ld      [%l0+0x228], %o0
F00BD5FC: 932a6018                 sll     %o1, 24, %o1
F00BD600: d4022014                 ld      [%o0+0x14], %o2
F00BD604: 9fc28000                 call    %o2
F00BD608: 933a6018                 sra     %o1, 24, %o1
F00BD60C: d04e4000                 ldsb    [%i1], %o0
F00BD610: 80a22000                 cmp     %o0, 0
F00BD614: 12bffff8                 bne     loc_F00BD5F4
F00BD618: d20e4000                 ldub    [%i1], %o1
F00BD61C: 3080005a                 ba,a    locret_F00BD784
F00BD620: 4000021c                 call    _BasicAllocateConsole
F00BD624: 213c04fd                 sethi   %hi(_kmAlertConsole), %l0
F00BD628: 80a22000                 cmp     %o0, 0
F00BD62C: 02800056                 be      locret_F00BD784
F00BD630: d0242238                 st      %o0, [%l0+%lo(_kmAlertConsole)]
F00BD634: 92102003                 mov     3, %o1
F00BD638: 94102000                 mov     0, %o2
F00BD63C: 96102001                 mov     1, %o3
F00BD640: da022004                 ld      [%o0+4], %o5
F00BD644: 9fc34000                 call    %o5
F00BD648: 98100018                 mov     %i0, %o4
F00BD64C: d04e4000                 ldsb    [%i1], %o0
F00BD650: 80a22000                 cmp     %o0, 0
F00BD654: 0280004c                 be      locret_F00BD784
F00BD658: d20e4000                 ldub    [%i1], %o1
F00BD65C: b2066001                 inc     %i1
F00BD660: d0042238                 ld      [%l0+0x238], %o0
F00BD664: 932a6018                 sll     %o1, 24, %o1
F00BD668: d4022014                 ld      [%o0+0x14], %o2
F00BD66C: 9fc28000                 call    %o2
F00BD670: 933a6018                 sra     %o1, 24, %o1
F00BD674: d04e4000                 ldsb    [%i1], %o0
F00BD678: 80a22000                 cmp     %o0, 0
F00BD67C: 12bffff8                 bne     loc_F00BD65C
F00BD680: d20e4000                 ldub    [%i1], %o1
F00BD684: 30800040                 ba,a    locret_F00BD784
F00BD688: 133c0504                 sethi   %hi(paLock), %o1
F00BD68C: 153c04c8                 sethi   %hi(dword_F0132068), %o2
F00BD690: d402a068                 ld      [%o2+%lo(dword_F0132068)], %o2
F00BD694: 9fc28000                 call    %o2
F00BD698: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BD69C: d0042240                 ld      [%l0+0x240], %o0
F00BD6A0: d0022114                 ld      [%o0+0x114], %o0
F00BD6A4: 80a22001                 cmp     %o0, 1
F00BD6A8: 0280001d                 be      loc_F00BD71C
F00BD6AC: 80a22003                 cmp     %o0, 3
F00BD6B0: 0280001c                 be      loc_F00BD720
F00BD6B4: 113c0504                 sethi   -0xFEBF000, %o0
F00BD6B8: 40000618                 call    _FBAllocateConsole
F00BD6BC: 01000000                 nop
F00BD6C0: d2042240                 ld      [%l0+0x240], %o1
F00BD6C4: 80a22000                 cmp     %o0, 0
F00BD6C8: 12800005                 bne     loc_F00BD6DC
F00BD6CC: d0226110                 st      %o0, [%o1+0x110]
F00BD6D0: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BD6D4: d0022228                 ld      [%o0+%lo(_basicConsole)], %o0
F00BD6D8: d0226110                 st      %o0, [%o1+0x110]
F00BD6DC: 92102003                 mov     3, %o1
F00BD6E0: d0042240                 ld      [%l0+0x240], %o0
F00BD6E4: 94102000                 mov     0, %o2
F00BD6E8: d0022110                 ld      [%o0+0x110], %o0
F00BD6EC: 96102001                 mov     1, %o3
F00BD6F0: da022004                 ld      [%o0+4], %o5
F00BD6F4: 9fc34000                 call    %o5
F00BD6F8: 98100018                 mov     %i0, %o4
F00BD6FC: d2042240                 ld      [%l0+0x240], %o1
F00BD700: d0026114                 ld      [%o1+0x114], %o0
F00BD704: 94102003                 mov     3, %o2
F00BD708: d0226118                 st      %o0, [%o1+0x118]
F00BD70C: d002611c                 ld      [%o1+0x11C], %o0
F00BD710: d4226114                 st      %o2, [%o1+0x114]
F00BD714: 90022001                 inc     %o0
F00BD718: d022611c                 st      %o0, [%o1+0x11C]
F00BD71C: 113c0504                 sethi   -0xFEBF000, %o0
F00BD720: d2022244                 ld      [%o0+0x244], %o1
F00BD724: 153c04c8                 sethi   %hi(dword_F013206C), %o2
F00BD728: d402a06c                 ld      [%o2+%lo(dword_F013206C)], %o2
F00BD72C: 213c04fd                 sethi   %hi(_kmId), %l0
F00BD730: d0042240                 ld      [%l0+%lo(_kmId)], %o0
F00BD734: 9fc28000                 call    %o2
F00BD738: d0022108                 ld      [%o0+0x108], %o0
F00BD73C: d2042240                 ld      [%l0+%lo(_kmId)], %o1
F00BD740: d0026114                 ld      [%o1+0x114], %o0
F00BD744: 80a22003                 cmp     %o0, 3
F00BD748: 32800003                 bne,a   loc_F00BD754
F00BD74C: e002610c                 ld      [%o1+0x10C], %l0
F00BD750: e0026110                 ld      [%o1+0x110], %l0
F00BD754: 10800009                 ba      loc_F00BD778
F00BD758: d04e4000                 ldsb    [%i1], %o0
F00BD75C: b2066001                 inc     %i1
F00BD760: 90100010                 mov     %l0, %o0
F00BD764: 932a6018                 sll     %o1, 24, %o1
F00BD768: d4042014                 ld      [%l0+0x14], %o2
F00BD76C: 9fc28000                 call    %o2
F00BD770: 933a6018                 sra     %o1, 24, %o1
F00BD774: d04e4000                 ldsb    [%i1], %o0
F00BD778: 80a22000                 cmp     %o0, 0
F00BD77C: 12bffff8                 bne     loc_F00BD75C
F00BD780: d20e4000                 ldub    [%i1], %o1
F00BD784: 81c7e008                 ret
F00BD788: 81e80000                 restore
