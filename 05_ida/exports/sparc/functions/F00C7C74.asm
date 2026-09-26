F00C7C74: 9de3bf90                 save    %sp, -0x70, %sp
F00C7C78: 90100018                 mov     %i0, %o0! id
F00C7C7C: 133c0506                 sethi   %hi(paChecksafeconfi), %o1
F00C7C80: d202615c                 ld      [%o1+%lo(paChecksafeconfi)], %o1! SEL
F00C7C84: 153c03eb                 sethi   %hi(aSetformatted), %o2! "setFormatted"
F00C7C88: 4000a6fa                 call    _objc_msgSend
F00C7C8C: 9412a238                 bset    %lo(aSetformatted), %o2! "setFormatted"
F00C7C90: 80a22000                 cmp     %o0, 0
F00C7C94: 22800004                 be,a    loc_F00C7CA4
F00C7C98: 113c0506                 sethi   -0xFEBE800, %o0! id
F00C7C9C: 1080001c                 ba      locret_F00C7D0C
F00C7CA0: b0100008                 mov     %o0, %i0
F00C7CA4: d2022164                 ld      [%o0+0x164], %o1! SEL
F00C7CA8: 4000a6f2                 call    _objc_msgSend
F00C7CAC: 90100018                 mov     %i0, %o0! id
F00C7CB0: a0100008                 mov     %o0, %l0
F00C7CB4: 153c0506                 sethi   %hi(paSetformattedin), %o2
F00C7CB8: 932ea018                 sll     %i2, 24, %o1! SEL
F00C7CBC: e202a1ac                 ld      [%o2+%lo(paSetformattedin)], %l1
F00C7CC0: b53a6018                 sra     %o1, 24, %i2
F00C7CC4: 9410001a                 mov     %i2, %o2
F00C7CC8: 4000a6ea                 call    _objc_msgSend
F00C7CCC: 92100011                 mov     %l1, %o1
F00C7CD0: 80a6a000                 cmp     %i2, 0
F00C7CD4: 02800005                 be      loc_F00C7CE8
F00C7CD8: 113c0504                 sethi   %hi(paUpdatephysical), %o0! id
F00C7CDC: d20221c4                 ld      [%o0+%lo(paUpdatephysical)], %o1! SEL
F00C7CE0: 4000a6e4                 call    _objc_msgSend
F00C7CE4: 90100010                 mov     %l0, %o0
F00C7CE8: 90100010                 mov     %l0, %o0! id
F00C7CEC: 92100011                 mov     %l1, %o1! SEL
F00C7CF0: 4000a6e0                 call    _objc_msgSend
F00C7CF4: 9410001a                 mov     %i2, %o2
F00C7CF8: 90100018                 mov     %i0, %o0! id
F00C7CFC: 92100011                 mov     %l1, %o1! SEL
F00C7D00: 4000a6dc                 call    _objc_msgSend
F00C7D04: 9410001a                 mov     %i2, %o2
F00C7D08: b0102000                 mov     0, %i0
F00C7D0C: 81c7e008                 ret
F00C7D10: 81e80000                 restore
