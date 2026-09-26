F00BF944: 9de3bf90                 save    %sp, -0x70, %sp
F00BF948: 94100018                 mov     %i0, %o2
F00BF94C: 213c0482                 sethi   %hi(dword_F0120AE8), %l0
F00BF950: f00422e8                 ld      [%l0+%lo(dword_F0120AE8)], %i0
F00BF954: 80a62000                 cmp     %i0, 0
F00BF958: 12800025                 bne     locret_F00BF9EC
F00BF95C: 113c0503                 sethi   %hi(paAlloc), %o0! id
F00BF960: d20223f0                 ld      [%o0+%lo(paAlloc)], %o1! SEL
F00BF964: 4000c7c3                 call    _objc_msgSend
F00BF968: 9010000a                 mov     %o2, %o0
F00BF96C: d02422e8                 st      %o0, [%l0+%lo(dword_F0120AE8)]
F00BF970: 113c0506                 sethi   %hi(paNxlock), %o0
F00BF974: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00BF978: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00BF97C: 4000c7bd                 call    _objc_msgSend
F00BF980: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00BF984: 153c04829412a358         set     aEventsrcpckeyb_0, %o2! "EventSrcPCKeyboard0"
F00BF98C: d60422e8                 ld      [%l0+%lo(dword_F0120AE8)], %o3
F00BF990: 133c0504                 sethi   %hi(paSetname), %o1
F00BF994: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00BF998: d022e124                 st      %o0, [%o3+0x124]
F00BF99C: 4000c7b5                 call    _objc_msgSend
F00BF9A0: 9010000b                 mov     %o3, %o0
F00BF9A4: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00BF9A8: d00422e8                 ld      [%l0+0x2E8], %o0! id
F00BF9AC: 153c0482                 sethi   %hi(aEventsrcpckeyb_1), %o2! "EventSrcPCKeyboard"
F00BF9B0: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00BF9B4: 4000c7af                 call    _objc_msgSend
F00BF9B8: 9412a370                 bset    %lo(aEventsrcpckeyb_1), %o2! "EventSrcPCKeyboard"
F00BF9BC: d00422e8                 ld      [%l0+0x2E8], %o0! id
F00BF9C0: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00BF9C4: 4000c7ab                 call    _objc_msgSend
F00BF9C8: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00BF9CC: 80a22000                 cmp     %o0, 0
F00BF9D0: 12800007                 bne     locret_F00BF9EC
F00BF9D4: f00422e8                 ld      [%l0+0x2E8], %i0
F00BF9D8: d00422e8                 ld      [%l0+0x2E8], %o0! id
F00BF9DC: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00BF9E0: 4000c7a4                 call    _objc_msgSend
F00BF9E4: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00BF9E8: f00422e8                 ld      [%l0+0x2E8], %i0
F00BF9EC: 81c7e008                 ret
F00BF9F0: 81e80000                 restore
