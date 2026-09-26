F008F074: 9de3bf90                 save    %sp, -0x70, %sp
F008F078: 213c023ba0142250         set     sub_F008EE50, %l0
F008F080: 94100010                 mov     %l0, %o2
F008F084: 113c0504                 sethi   %hi(paFreekeysValues), %o0
F008F088: 173c023b                 sethi   %hi(sub_F008EE5C), %o3
F008F08C: e40220f8                 ld      [%o0+%lo(paFreekeysValues)], %l2
F008F090: 9612e25c                 bset    %lo(sub_F008EE5C), %o3
F008F094: d0062010                 ld      [%i0+0x10], %o0! id
F008F098: 400189f6                 call    _objc_msgSend
F008F09C: 92100012                 mov     %l2, %o1! SEL
F008F0A0: 113c0503                 sethi   %hi(paFree), %o0
F008F0A4: e20223fc                 ld      [%o0+%lo(paFree)], %l1
F008F0A8: d0062010                 ld      [%i0+0x10], %o0! id
F008F0AC: 400189f1                 call    _objc_msgSend
F008F0B0: 92100011                 mov     %l1, %o1
F008F0B4: 92100012                 mov     %l2, %o1! SEL
F008F0B8: 94100010                 mov     %l0, %o2
F008F0BC: 173c023b                 sethi   %hi(sub_F008EE7C), %o3
F008F0C0: d006200c                 ld      [%i0+0xC], %o0! id
F008F0C4: 400189eb                 call    _objc_msgSend
F008F0C8: 9612e27c                 bset    %lo(sub_F008EE7C), %o3
F008F0CC: d006200c                 ld      [%i0+0xC], %o0! id
F008F0D0: 400189e8                 call    _objc_msgSend
F008F0D4: 92100011                 mov     %l1, %o1! SEL
F008F0D8: d0062014                 ld      [%i0+0x14], %o0! id
F008F0DC: 400189e5                 call    _objc_msgSend
F008F0E0: 92100011                 mov     %l1, %o1
F008F0E4: f027bff0                 st      %i0, [%fp+var_10]
F008F0E8: 133c0507                 sethi   %hi(stru_F0141CDC.super_class), %o1
F008F0EC: d40260e0                 ld      [%o1+%lo(stru_F0141CDC.super_class)], %o2
F008F0F0: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008F0F4: 92100011                 mov     %l1, %o1! SEL
F008F0F8: 40018a21                 call    _objc_msgSendSuper
F008F0FC: d427bff4                 st      %o2, [%fp+var_C]
F008F100: 81c7e008                 ret
F008F104: 91e80008                 restore %g0, %o0, %o0
