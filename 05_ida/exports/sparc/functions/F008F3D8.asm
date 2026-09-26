F008F3D8: 9de3bf90                 save    %sp, -0x70, %sp
F008F3DC: 133c0504                 sethi   %hi(paNextstateKeyVa), %o1
F008F3E0: 9410001a                 mov     %i2, %o2
F008F3E4: d0062010                 ld      [%i0+0x10], %o0! id
F008F3E8: 9610001b                 mov     %i3, %o3
F008F3EC: d2026108                 ld      [%o1+%lo(paNextstateKeyVa)], %o1! SEL
F008F3F0: 40018920                 call    _objc_msgSend
F008F3F4: 9810001c                 mov     %i4, %o4
F008F3F8: 912a2018                 sll     %o0, 24, %o0
F008F3FC: b13a2018                 sra     %o0, 24, %i0
F008F400: 81c7e008                 ret
F008F404: 81e80000                 restore
