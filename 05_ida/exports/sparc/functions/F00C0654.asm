F00C0654: 9de3bf90                 save    %sp, -0x70, %sp
F00C0658: 94100018                 mov     %i0, %o2
F00C065C: 213c0483                 sethi   %hi(dword_F0120C50), %l0
F00C0660: f0042050                 ld      [%l0+%lo(dword_F0120C50)], %i0
F00C0664: 80a62000                 cmp     %i0, 0
F00C0668: 1280001d                 bne     locret_F00C06DC
F00C066C: 113c0503                 sethi   %hi(paAlloc), %o0! id
F00C0670: d20223f0                 ld      [%o0+%lo(paAlloc)], %o1! SEL
F00C0674: 4000c47f                 call    _objc_msgSend
F00C0678: 9010000a                 mov     %o2, %o0! id
F00C067C: d0242050                 st      %o0, [%l0+%lo(dword_F0120C50)]
F00C0680: 133c0504                 sethi   %hi(paSetname), %o1
F00C0684: 153c0483                 sethi   %hi(aEventsrcpcpoin_0), %o2! "EventSrcPCPointer0"
F00C0688: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00C068C: 4000c479                 call    _objc_msgSend
F00C0690: 9412a0d0                 bset    %lo(aEventsrcpcpoin_0), %o2! "EventSrcPCPointer0"
F00C0694: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00C0698: d0042050                 ld      [%l0+%lo(dword_F0120C50)], %o0! id
F00C069C: 153c0483                 sethi   %hi(aEventsrcpcpoin_1), %o2! "EventSrcPCPointer"
F00C06A0: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00C06A4: 4000c473                 call    _objc_msgSend
F00C06A8: 9412a0e8                 bset    %lo(aEventsrcpcpoin_1), %o2! "EventSrcPCPointer"
F00C06AC: d0042050                 ld      [%l0+0x50], %o0! id
F00C06B0: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00C06B4: 4000c46f                 call    _objc_msgSend
F00C06B8: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00C06BC: 80a22000                 cmp     %o0, 0
F00C06C0: 12800007                 bne     locret_F00C06DC
F00C06C4: f0042050                 ld      [%l0+0x50], %i0
F00C06C8: d0042050                 ld      [%l0+0x50], %o0! id
F00C06CC: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00C06D0: 4000c468                 call    _objc_msgSend
F00C06D4: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00C06D8: f0042050                 ld      [%l0+0x50], %i0
F00C06DC: 81c7e008                 ret
F00C06E0: 81e80000                 restore
