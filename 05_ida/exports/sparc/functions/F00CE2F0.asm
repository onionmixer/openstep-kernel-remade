F00CE2F0: 9de3bf90                 save    %sp, -0x70, %sp
F00CE2F4: 900621a8                 add     %i0, 0x1A8, %o0
F00CE2F8: d02621ac                 st      %o0, [%i0+0x1AC]
F00CE2FC: d02621a8                 st      %o0, [%i0+0x1A8]
F00CE300: 900621b0                 add     %i0, 0x1B0, %o0
F00CE304: d02621b4                 st      %o0, [%i0+0x1B4]
F00CE308: d02621b0                 st      %o0, [%i0+0x1B0]
F00CE30C: a8102000                 mov     0, %l4
F00CE310: 113c0506                 sethi   %hi(paNxconditionloc), %o0
F00CE314: e402226c                 ld      [%o0+%lo(paNxconditionloc)], %l2
F00CE318: 2b3c033e                 sethi   -0xFF30800, %l5
F00CE31C: 113c0503                 sethi   %hi(paAlloc), %o0
F00CE320: e20223f0                 ld      [%o0+%lo(paAlloc)], %l1
F00CE324: a6100018                 mov     %i0, %l3
F00CE328: 90100012                 mov     %l2, %o0! id
F00CE32C: 40008d51                 call    _objc_msgSend
F00CE330: 92100011                 mov     %l1, %o1
F00CE334: d02621b8                 st      %o0, [%i0+0x1B8]
F00CE338: 133c0503                 sethi   %hi(paInitwith), %o1! SEL
F00CE33C: e00263f4                 ld      [%o1+%lo(paInitwith)], %l0
F00CE340: 94102000                 mov     0, %o2
F00CE344: 40008d4b                 call    _objc_msgSend
F00CE348: 92100010                 mov     %l0, %o1
F00CE34C: 90100018                 mov     %i0, %o0! id
F00CE350: 133c0506                 sethi   %hi(paSetlastreadyst), %o1
F00CE354: d2026178                 ld      [%o1+%lo(paSetlastreadyst)], %o1! SEL
F00CE358: 40008d46                 call    _objc_msgSend
F00CE35C: 94102001                 mov     1, %o2
F00CE360: 90100012                 mov     %l2, %o0! id
F00CE364: 40008d43                 call    _objc_msgSend
F00CE368: 92100011                 mov     %l1, %o1
F00CE36C: d02621c0                 st      %o0, [%i0+0x1C0]
F00CE370: 92100010                 mov     %l0, %o1! SEL
F00CE374: 40008d3f                 call    _objc_msgSend
F00CE378: 94102000                 mov     0, %o2
F00CE37C: c02621c4                 clr     [%i0+0x1C4]
F00CE380: c02e21c8                 clrb    [%i0+0x1C8]
F00CE384: c026218c                 clr     [%i0+0x18C]
F00CE388: d0062188                 ld      [%i0+0x188], %o0
F00CE38C: 13000020                 sethi   0x8000, %o1
F00CE390: 922a0009                 andn    %o0, %o1, %o1
F00CE394: 11000010                 sethi   0x4000, %o0
F00CE398: 902a4008                 andn    %o1, %o0, %o0
F00CE39C: d0262188                 st      %o0, [%i0+0x188]
F00CE3A0: 90156110                 or      %l5, 0x110, %o0
F00CE3A4: 7fffef47                 call    _IOForkThread
F00CE3A8: 92100018                 mov     %i0, %o1
F00CE3AC: d024e190                 st      %o0, [%l3+0x190]
F00CE3B0: a604e004                 inc     4, %l3
F00CE3B4: d006218c                 ld      [%i0+0x18C], %o0
F00CE3B8: a8052001                 inc     %l4
F00CE3BC: 80a52000                 cmp     %l4, 0
F00CE3C0: 90022001                 inc     %o0
F00CE3C4: 04bffff7                 ble     loc_F00CE3A0
F00CE3C8: d026218c                 st      %o0, [%i0+0x18C]
F00CE3CC: 81c7e008                 ret
F00CE3D0: 81e80000                 restore
