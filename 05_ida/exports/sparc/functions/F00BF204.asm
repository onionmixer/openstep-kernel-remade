F00BF204: 9de3bf90                 save    %sp, -0x70, %sp
F00BF208: d0062124                 ld      [%i0+0x124], %o0! id
F00BF20C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BF210: 4000c998                 call    _objc_msgSend
F00BF214: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BF218: d4062128                 ld      [%i0+0x128], %o2
F00BF21C: 80a2a000                 cmp     %o2, 0
F00BF220: 02800005                 be      loc_F00BF234
F00BF224: 113c0503                 sethi   %hi(paFree), %o0! id
F00BF228: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00BF22C: 4000c991                 call    _objc_msgSend
F00BF230: 9010000a                 mov     %o2, %o0
F00BF234: 113c0506                 sethi   %hi(paKeymap), %o0
F00BF238: d00222a4                 ld      [%o0+%lo(paKeymap)], %o0! id
F00BF23C: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00BF240: 4000c98c                 call    _objc_msgSend
F00BF244: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00BF248: 153c03e39412a290         set     unk_F00F8E90, %o2
F00BF250: 133c0504                 sethi   %hi(paInitfromkeymap), %o1
F00BF254: 9610235a                 mov     0x35A, %o3
F00BF258: d2026284                 ld      [%o1+%lo(paInitfromkeymap)], %o1! SEL
F00BF25C: 4000c985                 call    _objc_msgSend
F00BF260: 98102000                 mov     0, %o4
F00BF264: d0262128                 st      %o0, [%i0+0x128]
F00BF268: 133c0504                 sethi   %hi(paSetdelegate), %o1
F00BF26C: d2026288                 ld      [%o1+%lo(paSetdelegate)], %o1! SEL
F00BF270: 4000c980                 call    _objc_msgSend
F00BF274: 94100018                 mov     %i0, %o2
F00BF278: 90102000                 mov     0, %o0
F00BF27C: 1301dcd692126140         set     0x7735940, %o1
F00BF284: d03e2168                 std     %o0, [%i0+0x168]
F00BF288: 133c0504                 sethi   %hi(paUnlock), %o1
F00BF28C: d0062124                 ld      [%i0+0x124], %o0! id
F00BF290: 94102000                 mov     0, %o2
F00BF294: 170773599612e100         set     0x1DCD6500, %o3
F00BF29C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00BF2A0: 4000c974                 call    _objc_msgSend
F00BF2A4: d43e2170                 std     %o2, [%i0+0x170]
F00BF2A8: 81c7e008                 ret
F00BF2AC: 81e80000                 restore
