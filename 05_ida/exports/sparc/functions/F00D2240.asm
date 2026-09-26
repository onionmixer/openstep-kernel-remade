F00D2240: 9de3bf90                 save    %sp, -0x70, %sp
F00D2244: 113c0504                 sethi   %hi(paLock), %o0
F00D2248: e0022000                 ld      [%o0+%lo(paLock)], %l0
F00D224C: d0062110                 ld      [%i0+0x110], %o0! id
F00D2250: 40007d88                 call    _objc_msgSend
F00D2254: 92100010                 mov     %l0, %o1
F00D2258: d04e21d0                 ldsb    [%i0+0x1D0], %o0
F00D225C: 80a22000                 cmp     %o0, 0
F00D2260: 22800007                 be,a    loc_F00D227C
F00D2264: d0062110                 ld      [%i0+0x110], %o0
F00D2268: d0062114                 ld      [%i0+0x114], %o0
F00D226C: 80a6c008                 cmp     %i3, %o0
F00D2270: 02800008                 be      loc_F00D2290
F00D2274: 90100018                 mov     %i0, %o0
F00D2278: d0062110                 ld      [%i0+0x110], %o0! id
F00D227C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D2280: 40007d7c                 call    _objc_msgSend
F00D2284: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D2288: 10800033                 ba      locret_F00D2354
F00D228C: b0103d3e                 mov     -0x2C2, %i0
F00D2290: 133c0505                 sethi   %hi(paForceautodimst), %o1
F00D2294: d2026350                 ld      [%o1+%lo(paForceautodimst)], %o1! SEL
F00D2298: 40007d76                 call    _objc_msgSend
F00D229C: 94102000                 mov     0, %o2
F00D22A0: 113c0505                 sethi   %hi(paHidecursor_0), %o0! id
F00D22A4: d202234c                 ld      [%o0+%lo(paHidecursor_0)], %o1! SEL
F00D22A8: 40007d72                 call    _objc_msgSend
F00D22AC: 90100018                 mov     %i0, %o0
F00D22B0: 113c0504                 sethi   %hi(paUnlock), %o0
F00D22B4: f6022244                 ld      [%o0+%lo(paUnlock)], %i3
F00D22B8: d0062110                 ld      [%i0+0x110], %o0! id
F00D22BC: 40007d6d                 call    _objc_msgSend
F00D22C0: 9210001b                 mov     %i3, %o1
F00D22C4: 113c0505                 sethi   %hi(paDetacheventsou), %o0! id
F00D22C8: d2022348                 ld      [%o0+%lo(paDetacheventsou)], %o1! SEL
F00D22CC: 40007d69                 call    _objc_msgSend
F00D22D0: 90100018                 mov     %i0, %o0
F00D22D4: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D22D8: 80a22001                 cmp     %o0, 1
F00D22DC: 32800008                 bne,a   loc_F00D22FC
F00D22E0: d0062110                 ld      [%i0+0x110], %o0
F00D22E4: 113c0505                 sethi   %hi(paUnmapeventshme), %o0! id
F00D22E8: d2022344                 ld      [%o0+%lo(paUnmapeventshme)], %o1! SEL
F00D22EC: d4062114                 ld      [%i0+0x114], %o2
F00D22F0: 40007d60                 call    _objc_msgSend
F00D22F4: 90100018                 mov     %i0, %o0
F00D22F8: d0062110                 ld      [%i0+0x110], %o0! id
F00D22FC: 40007d5d                 call    _objc_msgSend
F00D2300: 92100010                 mov     %l0, %o1
F00D2304: d0062180                 ld      [%i0+0x180], %o0
F00D2308: 80a22000                 cmp     %o0, 0
F00D230C: 22800009                 be,a    loc_F00D2330
F00D2310: 90100018                 mov     %i0, %o0
F00D2314: 7fffcf0c                 call    _IOFree
F00D2318: d206217c                 ld      [%i0+0x17C], %o1
F00D231C: c0262180                 clr     [%i0+0x180]
F00D2320: c026217c                 clr     [%i0+0x17C]
F00D2324: c0262188                 clr     [%i0+0x188]
F00D2328: c0262184                 clr     [%i0+0x184]
F00D232C: 90100018                 mov     %i0, %o0! id
F00D2330: 133c0505                 sethi   %hi(paSeteventport), %o1
F00D2334: d2026354                 ld      [%o1+%lo(paSeteventport)], %o1! SEL
F00D2338: 40007d4e                 call    _objc_msgSend
F00D233C: 94102000                 mov     0, %o2
F00D2340: c02e21d0                 clrb    [%i0+0x1D0]
F00D2344: d0062110                 ld      [%i0+0x110], %o0! id
F00D2348: 40007d4a                 call    _objc_msgSend
F00D234C: 9210001b                 mov     %i3, %o1
F00D2350: b0102000                 mov     0, %i0
F00D2354: 81c7e008                 ret
F00D2358: 81e80000                 restore
