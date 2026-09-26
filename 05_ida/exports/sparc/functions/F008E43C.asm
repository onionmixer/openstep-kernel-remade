F008E43C: 9de3bf90                 save    %sp, -0x70, %sp
F008E440: 80a6a000                 cmp     %i2, 0
F008E444: 0280000b                 be      loc_F008E470
F008E448: 133c0507                 sethi   %hi(stru_F0141C8C.ext), %o1
F008E44C: f027bff0                 st      %i0, [%fp+var_10]
F008E450: d40260b8                 ld      [%o1+%lo(stru_F0141C8C.ext)], %o2
F008E454: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008E458: 133c0504                 sethi   %hi(paInit), %o1
F008E45C: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F008E460: 40018d47                 call    _objc_msgSendSuper
F008E464: d427bff4                 st      %o2, [%fp+var_C]
F008E468: 10800007                 ba      locret_F008E484
F008E46C: f426200c                 st      %i2, [%i0+0xC]
F008E470: 113c0503                 sethi   %hi(paFree), %o0! id
F008E474: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008E478: 40018cfe                 call    _objc_msgSend
F008E47C: 90100018                 mov     %i0, %o0
F008E480: b0100008                 mov     %o0, %i0
F008E484: 81c7e008                 ret
F008E488: 81e80000                 restore
