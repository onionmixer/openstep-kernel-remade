F00C06E4: 9de3bf90                 save    %sp, -0x70, %sp
F00C06E8: d0062124                 ld      [%i0+0x124], %o0! id
F00C06EC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C06F0: 4000c460                 call    _objc_msgSend
F00C06F4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C06F8: 113c0483                 sethi   %hi(dword_F0120C50), %o0
F00C06FC: e2062124                 ld      [%i0+0x124], %l1
F00C0700: c0222050                 clr     [%o0+%lo(dword_F0120C50)]
F00C0704: d0062128                 ld      [%i0+0x128], %o0! id
F00C0708: 80a22000                 cmp     %o0, 0
F00C070C: 02800006                 be      loc_F00C0724
F00C0710: c0262124                 clr     [%i0+0x124]
F00C0714: 133c0504                 sethi   %hi(paSeteventtarget), %o1
F00C0718: d20262e0                 ld      [%o1+%lo(paSeteventtarget)], %o1! SEL
F00C071C: 4000c455                 call    _objc_msgSend
F00C0720: 94102000                 mov     0, %o2
F00C0724: 113c0504                 sethi   %hi(paUnlock), %o0! id
F00C0728: d2022244                 ld      [%o0+%lo(paUnlock)], %o1! SEL
F00C072C: 4000c451                 call    _objc_msgSend
F00C0730: 90100011                 mov     %l1, %o0
F00C0734: 113c0503                 sethi   %hi(paFree), %o0
F00C0738: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00C073C: 90100011                 mov     %l1, %o0! id
F00C0740: 4000c44c                 call    _objc_msgSend
F00C0744: 92100010                 mov     %l0, %o1
F00C0748: f027bff0                 st      %i0, [%fp+var_10]
F00C074C: 133c0507                 sethi   %hi(stru_F0141D7C.super_class), %o1
F00C0750: d4026180                 ld      [%o1+%lo(stru_F0141D7C.super_class)], %o2
F00C0754: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C0758: 92100010                 mov     %l0, %o1! SEL
F00C075C: 4000c488                 call    _objc_msgSendSuper
F00C0760: d427bff4                 st      %o2, [%fp+var_C]
F00C0764: 81c7e008                 ret
F00C0768: 91e80008                 restore %g0, %o0, %o0
