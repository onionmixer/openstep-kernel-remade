F0090C90: 9de3bf98                 save    %sp, -0x68, %sp
F0090C94: 80a62000                 cmp     %i0, 0
F0090C98: 12800004                 bne     loc_F0090CA8
F0090C9C: 94100019                 mov     %i1, %o2
F0090CA0: 10800029                 ba      locret_F0090D44
F0090CA4: b0103d3f                 mov     -0x2C1, %i0
F0090CA8: 113c0506                 sethi   %hi(paIoconfigtable), %o0
F0090CAC: d0022298                 ld      [%o0+%lo(paIoconfigtable)], %o0! name
F0090CB0: 133c0504                 sethi   %hi(paNewforconfigda), %o1! SEL
F0090CB4: 400182ef                 call    _objc_msgSend
F0090CB8: d202615c                 ld      [%o1+%lo(paNewforconfigda)], %o1
F0090CBC: b0100008                 mov     %o0, %i0
F0090CC0: 133c0504                 sethi   %hi(paValueforstring), %o1
F0090CC4: 153c0448                 sethi   %hi(aDriverName), %o2! "Driver Name"
F0090CC8: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F0090CCC: 400182e9                 call    _objc_msgSend
F0090CD0: 9412a1c0                 bset    %lo(aDriverName), %o2! "Driver Name"
F0090CD4: 4001840c                 call    _objc_getClass
F0090CD8: b2100008                 mov     %o0, %i1
F0090CDC: 80a22000                 cmp     %o0, 0
F0090CE0: 1280000e                 bne     loc_F0090D18
F0090CE4: 133c0504                 sethi   -0xFEBF000, %o1
F0090CE8: 113c0448901221d0         set     aIounloaddriver, %o0! "IOUnloadDriver: Couldn't find class nam"...
F0090CF0: 4000d501                 call    _IOLog
F0090CF4: 92100019                 mov     %i1, %o1
F0090CF8: 80a62000                 cmp     %i0, 0
F0090CFC: 02800005                 be      loc_F0090D10
F0090D00: 113c0503                 sethi   %hi(paFree), %o0! id
F0090D04: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F0090D08: 400182da                 call    _objc_msgSend
F0090D0C: 90100018                 mov     %i0, %o0! id
F0090D10: 1080000d                 ba      locret_F0090D44
F0090D14: b0103d3e                 mov     -0x2C2, %i0
F0090D18: d2026160                 ld      [%o1+0x160], %o1! SEL
F0090D1C: 400182d5                 call    _objc_msgSend
F0090D20: 94100008                 mov     %o0, %o2
F0090D24: 80a62000                 cmp     %i0, 0
F0090D28: 22800007                 be,a    locret_F0090D44
F0090D2C: b0102000                 mov     0, %i0
F0090D30: 113c0503                 sethi   %hi(paFree), %o0! id
F0090D34: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F0090D38: 400182ce                 call    _objc_msgSend
F0090D3C: 90100018                 mov     %i0, %o0
F0090D40: b0102000                 mov     0, %i0
F0090D44: 81c7e008                 ret
F0090D48: 81e80000                 restore
