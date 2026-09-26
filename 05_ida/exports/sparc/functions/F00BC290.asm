F00BC290: 9de3bf98                 save    %sp, -0x68, %sp
F00BC294: 113c04fd                 sethi   %hi(_kmId), %o0
F00BC298: d0022240                 ld      [%o0+%lo(_kmId)], %o0! id
F00BC29C: 80a22000                 cmp     %o0, 0
F00BC2A0: 02800005                 be      locret_F00BC2B4
F00BC2A4: 94100018                 mov     %i0, %o2
F00BC2A8: 133c0504                 sethi   %hi(paGraphicpanelst), %o1! SEL
F00BC2AC: 4000d571                 call    _objc_msgSend
F00BC2B0: d2026234                 ld      [%o1+%lo(paGraphicpanelst)], %o1
F00BC2B4: 81c7e008                 ret
F00BC2B8: 81e80000                 restore
