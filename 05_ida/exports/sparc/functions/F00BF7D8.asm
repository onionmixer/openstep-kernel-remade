F00BF7D8: 9de3bf90                 save    %sp, -0x70, %sp
F00BF7DC: 9010001a                 mov     %i2, %o0! id
F00BF7E0: 133c0504                 sethi   %hi(paBecomeowner), %o1
F00BF7E4: d2026264                 ld      [%o1+%lo(paBecomeowner)], %o1! SEL
F00BF7E8: 4000c822                 call    _objc_msgSend
F00BF7EC: 94100018                 mov     %i0, %o2
F00BF7F0: a6920000                 orcc    %o0, %g0, %l3
F00BF7F4: 02800018                 be      loc_F00BF854
F00BF7F8: 113c0504                 sethi   %hi(paName), %o0
F00BF7FC: 213c0482                 sethi   %hi(aSBecomeownerOf_1), %l0! "%s: becomeOwner of %s failed (%s)\n"
F00BF800: e2022008                 ld      [%o0+%lo(paName)], %l1
F00BF804: a0142330                 bset    %lo(aSBecomeownerOf_1), %l0! "%s: becomeOwner of %s failed (%s)\n"
F00BF808: 90100018                 mov     %i0, %o0! id
F00BF80C: 4000c819                 call    _objc_msgSend
F00BF810: 92100011                 mov     %l1, %o1! SEL
F00BF814: a4100008                 mov     %o0, %l2
F00BF818: 9010001a                 mov     %i2, %o0! id
F00BF81C: 4000c815                 call    _objc_msgSend
F00BF820: 92100011                 mov     %l1, %o1
F00BF824: a2100008                 mov     %o0, %l1
F00BF828: 90100018                 mov     %i0, %o0! id
F00BF82C: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00BF830: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00BF834: 4000c80f                 call    _objc_msgSend
F00BF838: 94100013                 mov     %l3, %o2
F00BF83C: 96100008                 mov     %o0, %o3
F00BF840: 90100010                 mov     %l0, %o0
F00BF844: 92100012                 mov     %l2, %o1
F00BF848: 40001a2b                 call    _IOLog
F00BF84C: 94100011                 mov     %l1, %o2
F00BF850: 30800003                 ba,a    locret_F00BF85C
F00BF854: 90102001                 mov     1, %o0
F00BF858: d02e2130                 stb     %o0, [%i0+0x130]
F00BF85C: 81c7e008                 ret
F00BF860: 81e80000                 restore
