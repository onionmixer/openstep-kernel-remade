F00D5464: 9de3bf98                 save    %sp, -0x68, %sp
F00D5468: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D546C: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D5470: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00D5474: 400070ff                 call    _objc_msgSend
F00D5478: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00D547C: a0920000                 orcc    %o0, %g0, %l0
F00D5480: 12800004                 bne     loc_F00D5490
F00D5484: 9010001a                 mov     %i2, %o0! __s1
F00D5488: 10800018                 ba      locret_F00D54E8
F00D548C: b0103d27                 mov     -0x2D9, %i0
F00D5490: 133c03f092126030         set     aEv, %o1! "Ev_"
F00D5498: 7ffccc14                 call    _strncmp
F00D549C: 94102003                 mov     3, %o2
F00D54A0: 80a22000                 cmp     %o0, 0
F00D54A4: 3280000a                 bne,a   loc_F00D54CC
F00D54A8: 90100010                 mov     %l0, %o0
F00D54AC: 113c0505                 sethi   %hi(paEvPort), %o0! id
F00D54B0: d2022274                 ld      [%o0+%lo(paEvPort)], %o1! SEL
F00D54B4: 400070ef                 call    _objc_msgSend
F00D54B8: 90100010                 mov     %l0, %o0
F00D54BC: 80a20018                 cmp     %o0, %i0
F00D54C0: 1280000a                 bne     locret_F00D54E8
F00D54C4: b0103d3f                 mov     -0x2C1, %i0
F00D54C8: 90100010                 mov     %l0, %o0! id
F00D54CC: 133c0504                 sethi   %hi(paSetcharvaluesF_0), %o1
F00D54D0: d20262d8                 ld      [%o1+%lo(paSetcharvaluesF_0)], %o1! SEL
F00D54D4: 9410001b                 mov     %i3, %o2
F00D54D8: 9610001a                 mov     %i2, %o3
F00D54DC: 400070e5                 call    _objc_msgSend
F00D54E0: 9810001c                 mov     %i4, %o4
F00D54E4: b0100008                 mov     %o0, %i0
F00D54E8: 81c7e008                 ret
F00D54EC: 81e80000                 restore
