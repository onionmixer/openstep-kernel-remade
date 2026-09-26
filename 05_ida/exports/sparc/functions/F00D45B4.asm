F00D45B4: 9de3bf90                 save    %sp, -0x70, %sp
F00D45B8: 9010001a                 mov     %i2, %o0! id
F00D45BC: 133c0504                 sethi   %hi(paBecomeowner), %o1
F00D45C0: d2026264                 ld      [%o1+%lo(paBecomeowner)], %o1! SEL
F00D45C4: 400074ab                 call    _objc_msgSend
F00D45C8: 94100018                 mov     %i0, %o2
F00D45CC: a6920000                 orcc    %o0, %g0, %l3
F00D45D0: 02800017                 be      locret_F00D462C
F00D45D4: 113c0504                 sethi   %hi(paName), %o0
F00D45D8: 213c03f0                 sethi   %hi(aSBecomeownerOf_0), %l0! "%s: becomeOwner of %s failed (%s)\n"
F00D45DC: e2022008                 ld      [%o0+%lo(paName)], %l1
F00D45E0: a0142008                 bset    %lo(aSBecomeownerOf_0), %l0! "%s: becomeOwner of %s failed (%s)\n"
F00D45E4: 90100018                 mov     %i0, %o0! id
F00D45E8: 400074a2                 call    _objc_msgSend
F00D45EC: 92100011                 mov     %l1, %o1! SEL
F00D45F0: a4100008                 mov     %o0, %l2
F00D45F4: 9010001a                 mov     %i2, %o0! id
F00D45F8: 4000749e                 call    _objc_msgSend
F00D45FC: 92100011                 mov     %l1, %o1
F00D4600: a2100008                 mov     %o0, %l1
F00D4604: 90100018                 mov     %i0, %o0! id
F00D4608: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00D460C: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00D4610: 40007498                 call    _objc_msgSend
F00D4614: 94100013                 mov     %l3, %o2
F00D4618: 96100008                 mov     %o0, %o3
F00D461C: 90100010                 mov     %l0, %o0
F00D4620: 92100012                 mov     %l2, %o1
F00D4624: 7fffc6b4                 call    _IOLog
F00D4628: 94100011                 mov     %l1, %o2
F00D462C: 81c7e008                 ret
F00D4630: 81e80000                 restore
