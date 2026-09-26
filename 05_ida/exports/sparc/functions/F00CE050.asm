F00CE050: 9de3bf90                 save    %sp, -0x70, %sp
F00CE054: 113c0506                 sethi   %hi(paLastreadystate_0), %o0! id
F00CE058: d202217c                 ld      [%o0+%lo(paLastreadystate_0)], %o1! SEL
F00CE05C: a2100018                 mov     %i0, %l1
F00CE060: 40008e04                 call    _objc_msgSend
F00CE064: 90100011                 mov     %l1, %o0
F00CE068: 80a22000                 cmp     %o0, 0
F00CE06C: 12800004                 bne     loc_F00CE07C
F00CE070: 912ea018                 sll     %i2, 24, %o0
F00CE074: 1080001d                 ba      locret_F00CE0E8
F00CE078: b0102000                 mov     0, %i0
F00CE07C: 80a22000                 cmp     %o0, 0
F00CE080: 02800019                 be      loc_F00CE0E4
F00CE084: 90100011                 mov     %l1, %o0! id
F00CE088: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CE08C: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CE090: 40008df8                 call    _objc_msgSend
F00CE094: 94102000                 mov     0, %o2
F00CE098: a0100008                 mov     %o0, %l0
F00CE09C: 90102006                 mov     6, %o0
F00CE0A0: d0240000                 st      %o0, [%l0]
F00CE0A4: 90100011                 mov     %l1, %o0! id
F00CE0A8: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CE0AC: 94100010                 mov     %l0, %o2
F00CE0B0: d6042020                 ld      [%l0+0x20], %o3
F00CE0B4: 19200000                 sethi   0x80000000, %o4
F00CE0B8: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CE0BC: 9612c00c                 bset    %o4, %o3
F00CE0C0: 40008dec                 call    _objc_msgSend
F00CE0C4: d6242020                 st      %o3, [%l0+0x20]
F00CE0C8: b0100008                 mov     %o0, %i0
F00CE0CC: 90100011                 mov     %l1, %o0! id
F00CE0D0: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CE0D4: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CE0D8: 40008de6                 call    _objc_msgSend
F00CE0DC: 94100010                 mov     %l0, %o2
F00CE0E0: 30800002                 ba,a    locret_F00CE0E8
F00CE0E4: b0103bb2                 mov     -0x44E, %i0
F00CE0E8: 81c7e008                 ret
F00CE0EC: 81e80000                 restore
