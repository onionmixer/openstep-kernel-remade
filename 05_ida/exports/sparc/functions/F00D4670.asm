F00D4670: 9de3bf90                 save    %sp, -0x70, %sp
F00D4674: fa27a058                 st      %i5, [%fp+arg_58]
F00D4678: d0062110                 ld      [%i0+0x110], %o0! id
F00D467C: d81fa058                 ldd     [%fp+arg_58], %o4
F00D4680: 133c0504                 sethi   %hi(paLock), %o1
F00D4684: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D4688: 872b2008                 sll     %o4, 8, %g3
F00D468C: 85336018                 srl     %o5, 24, %g2
F00D4690: 9610c002                 or      %g3, %g2, %o3
F00D4694: 95332018                 srl     %o4, 24, %o2
F00D4698: 40007476                 call    _objc_msgSend
F00D469C: ba10000b                 mov     %o3, %i5
F00D46A0: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D46A4: 80a22000                 cmp     %o0, 0
F00D46A8: 2280002a                 be,a    loc_F00D4750
F00D46AC: d0062110                 ld      [%i0+0x110], %o0
F00D46B0: d0062168                 ld      [%i0+0x168], %o0
F00D46B4: d0022008                 ld      [%o0+8], %o0
F00D46B8: 920ea004                 and     %i2, 4, %o1
F00D46BC: 900a2004                 and     %o0, 4, %o0
F00D46C0: 80a24008                 cmp     %o1, %o0
F00D46C4: 02800007                 be      loc_F00D46E0
F00D46C8: 80a26000                 cmp     %o1, 0
F00D46CC: 02800004                 be      loc_F00D46DC
F00D46D0: 901020ff                 mov     0xFF, %o0
F00D46D4: 10800003                 ba      loc_F00D46E0
F00D46D8: d02e21c0                 stb     %o0, [%i0+0x1C0]
F00D46DC: c02e21c0                 clrb    [%i0+0x1C0]
F00D46E0: 90100018                 mov     %i0, %o0! id
F00D46E4: 133c0505                 sethi   %hi(paSetbuttonstate), %o1
F00D46E8: d2026284                 ld      [%o1+%lo(paSetbuttonstate)], %o1! SEL
F00D46EC: 9410001a                 mov     %i2, %o2
F00D46F0: 40007460                 call    _objc_msgSend
F00D46F4: 9610001d                 mov     %i5, %o3
F00D46F8: 80a6e000                 cmp     %i3, 0
F00D46FC: 32800006                 bne,a   loc_F00D4714
F00D4700: d01621a8                 lduh    [%i0+0x1A8], %o0
F00D4704: 80a72000                 cmp     %i4, 0
F00D4708: 22800012                 be,a    loc_F00D4750
F00D470C: d0062110                 ld      [%i0+0x110], %o0
F00D4710: d01621a8                 lduh    [%i0+0x1A8], %o0
F00D4714: d21621aa                 lduh    [%i0+0x1AA], %o1
F00D4718: 9002001b                 add     %o0, %i3, %o0
F00D471C: d03621a8                 sth     %o0, [%i0+0x1A8]
F00D4720: 9202401c                 add     %o1, %i4, %o1
F00D4724: d04e2211                 ldsb    [%i0+0x211], %o0
F00D4728: 80a22000                 cmp     %o0, 0
F00D472C: 12800008                 bne     loc_F00D474C
F00D4730: d23621aa                 sth     %o1, [%i0+0x1AA]
F00D4734: 90100018                 mov     %i0, %o0! id
F00D4738: 133c0505                 sethi   %hi(paSetcursorposit_0), %o1
F00D473C: d20262c0                 ld      [%o1+%lo(paSetcursorposit_0)], %o1! SEL
F00D4740: 940621a8                 add     %i0, 0x1A8, %o2
F00D4744: 4000744b                 call    _objc_msgSend
F00D4748: 9610001d                 mov     %i5, %o3
F00D474C: d0062110                 ld      [%i0+0x110], %o0! id
F00D4750: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D4754: 40007447                 call    _objc_msgSend
F00D4758: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D475C: 81c7e008                 ret
F00D4760: 81e80000                 restore
