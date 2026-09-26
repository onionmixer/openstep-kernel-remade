F0022234: 9de3bf90                 save    %sp, -0x70, %sp! int
F0022238: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F002223C: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0022240: e4022024                 ld      [%o0+0x24], %l2
F0022244: 40000063                 call    _getsock
F0022248: d0048000                 ld      [%l2], %o0
F002224C: 80a22000                 cmp     %o0, 0
F0022250: 02800044                 be      locret_F0022360
F0022254: 01000000                 nop
F0022258: e6022018                 ld      [%o0+0x18], %l3
F002225C: d014e006                 lduh    [%l3+6], %o0
F0022260: 808a2002                 btst    2, %o0
F0022264: 12800006                 bne     loc_F002227C
F0022268: 90102001                 mov     1, %o0
F002226C: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0022270: 90102039                 mov     0x39, %o0 ! '9'
F0022274: 1080003b                 ba      locret_F0022360
F0022278: d02a6038                 stb     %o0, [%o1+0x38]
F002227C: 7fffeddf                 call    _m_getclr
F0022280: 92102008                 mov     8, %o1
F0022284: a0920000                 orcc    %o0, %g0, %l0
F0022288: 12800006                 bne     loc_F00222A0
F002228C: a807bff4                 add     %fp, var_C, %l4
F0022290: d20461dc                 ld      [%l1+0x1DC], %o1
F0022294: 90102037                 mov     0x37, %o0 ! '7'
F0022298: 10800032                 ba      locret_F0022360
F002229C: d02a6038                 stb     %o0, [%o1+0x38]
F00222A0: 92100014                 mov     %l4, %o1! int
F00222A4: d004a008                 ld      [%l2+8], %o0! int
F00222A8: 4001d76c                 call    _copyin
F00222AC: 94102004                 mov     4, %o2
F00222B0: d20461dc                 ld      [%l1+0x1DC], %o1
F00222B4: d02a6038                 stb     %o0, [%o1+0x38]
F00222B8: d00461dc                 ld      [%l1+0x1DC], %o0
F00222BC: d04a2038                 ldsb    [%o0+0x38], %o0
F00222C0: 80a22000                 cmp     %o0, 0
F00222C4: 12800027                 bne     locret_F0022360
F00222C8: 90100013                 mov     %l3, %o0
F00222CC: 92102010                 mov     0x10, %o1
F00222D0: d802200c                 ld      [%o0+0xC], %o4
F00222D4: 94102000                 mov     0, %o2
F00222D8: da03201c                 ld      [%o4+0x1C], %o5! int
F00222DC: 96100010                 mov     %l0, %o3! int
F00222E0: 9fc34000                 call    %o5
F00222E4: 98102000                 mov     0, %o4! int
F00222E8: d20461dc                 ld      [%l1+0x1DC], %o1
F00222EC: d02a6038                 stb     %o0, [%o1+0x38]
F00222F0: d00461dc                 ld      [%l1+0x1DC], %o0
F00222F4: d04a2038                 ldsb    [%o0+0x38], %o0
F00222F8: 80a22000                 cmp     %o0, 0
F00222FC: 12800017                 bne     loc_F0022358
F0022300: d007bff4                 ld      [%fp+var_C], %o0
F0022304: d2542008                 ldsh    [%l0+8], %o1
F0022308: 80a20009                 cmp     %o0, %o1
F002230C: 34800002                 bg,a    loc_F0022314
F0022310: d227bff4                 st      %o1, [%fp+var_C]
F0022314: d204a004                 ld      [%l2+4], %o1! int
F0022318: d0042004                 ld      [%l0+4], %o0! int
F002231C: d407bff4                 ld      [%fp+var_C], %o2! int
F0022320: 4001d76b                 call    _copyout
F0022324: 90040008                 add     %l0, %o0, %o0
F0022328: d20461dc                 ld      [%l1+0x1DC], %o1
F002232C: d02a6038                 stb     %o0, [%o1+0x38]
F0022330: d00461dc                 ld      [%l1+0x1DC], %o0
F0022334: d04a2038                 ldsb    [%o0+0x38], %o0
F0022338: 80a22000                 cmp     %o0, 0
F002233C: 12800007                 bne     loc_F0022358
F0022340: 90100014                 mov     %l4, %o0! int
F0022344: d204a008                 ld      [%l2+8], %o1! int
F0022348: 4001d761                 call    _copyout
F002234C: 94102004                 mov     4, %o2
F0022350: d20461dc                 ld      [%l1+0x1DC], %o1
F0022354: d02a6038                 stb     %o0, [%o1+0x38]
F0022358: 7fffee43                 call    _m_freem
F002235C: 90100010                 mov     %l0, %o0
F0022360: 81c7e008                 ret
F0022364: 81e80000                 restore
