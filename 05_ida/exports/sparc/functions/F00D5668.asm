F00D5668: 9de3bf90                 save    %sp, -0x70, %sp
F00D566C: f027bff0                 st      %i0, [%fp+var_10]
F00D5670: 133c0508                 sethi   %hi(stru_F01421DC.ext), %o1
F00D5674: d4026208                 ld      [%o1+%lo(stru_F01421DC.ext)], %o2
F00D5678: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D567C: 133c0504                 sethi   %hi(paInit), %o1
F00D5680: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00D5684: 400070be                 call    _objc_msgSendSuper
F00D5688: d427bff4                 st      %o2, [%fp+var_C]
F00D568C: c0262108                 clr     [%i0+0x108]
F00D5690: d4062110                 ld      [%i0+0x110], %o2
F00D5694: 80a2a000                 cmp     %o2, 0
F00D5698: 02800006                 be      loc_F00D56B0
F00D569C: c026210c                 clr     [%i0+0x10C]
F00D56A0: 113c0503                 sethi   %hi(paFree), %o0! id
F00D56A4: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00D56A8: 40007072                 call    _objc_msgSend
F00D56AC: 9010000a                 mov     %o2, %o0
F00D56B0: 113c0506                 sethi   %hi(paNxlock), %o0
F00D56B4: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00D56B8: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00D56BC: 4000706d                 call    _objc_msgSend
F00D56C0: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00D56C4: d0262110                 st      %o0, [%i0+0x110]
F00D56C8: 81c7e008                 ret
F00D56CC: 81e80000                 restore
