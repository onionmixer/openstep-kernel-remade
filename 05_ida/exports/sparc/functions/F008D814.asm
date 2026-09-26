F008D814: 9de3bf90                 save    %sp, -0x70, %sp
F008D818: 9410001a                 mov     %i2, %o2
F008D81C: 113c0504                 sethi   %hi(paValueforkey), %o0
F008D820: f402206c                 ld      [%o0+%lo(paValueforkey)], %i2
F008D824: b0102000                 mov     0, %i0
F008D828: 113c04c3                 sethi   %hi(dword_F0130FFC), %o0
F008D82C: d00223fc                 ld      [%o0+%lo(dword_F0130FFC)], %o0! id
F008D830: 40019010                 call    _objc_msgSend
F008D834: 9210001a                 mov     %i2, %o1
F008D838: 80a22000                 cmp     %o0, 0
F008D83C: 02800005                 be      locret_F008D850
F008D840: 9210001a                 mov     %i2, %o1! SEL
F008D844: 4001900b                 call    _objc_msgSend
F008D848: 9410001b                 mov     %i3, %o2
F008D84C: b0100008                 mov     %o0, %i0
F008D850: 81c7e008                 ret
F008D854: 81e80000                 restore
