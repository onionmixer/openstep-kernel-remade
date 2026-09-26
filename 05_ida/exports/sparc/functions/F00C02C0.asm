F00C02C0: 9de3bf90                 save    %sp, -0x70, %sp
F00C02C4: d0062124                 ld      [%i0+0x124], %o0! id
F00C02C8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C02CC: 4000c569                 call    _objc_msgSend
F00C02D0: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C02D4: d0068000                 ld      [%i2], %o0
F00C02D8: d2062138                 ld      [%i0+0x138], %o1
F00C02DC: 80a20009                 cmp     %o0, %o1
F00C02E0: 38800002                 bgu,a   loc_F00C02E8
F00C02E4: d2268000                 st      %o1, [%i2]
F00C02E8: d0068000                 ld      [%i2], %o0
F00C02EC: 94102000                 mov     0, %o2
F00C02F0: 80a28008                 cmp     %o2, %o0
F00C02F4: 3a80000f                 bcc,a   loc_F00C0330
F00C02F8: d0062124                 ld      [%i0+0x124], %o0
F00C02FC: 92100018                 mov     %i0, %o1
F00C0300: d052613c                 ldsh    [%o1+0x13C], %o0
F00C0304: 9402a001                 inc     %o2
F00C0308: d026c000                 st      %o0, [%i3]
F00C030C: d0526164                 ldsh    [%o1+0x164], %o0
F00C0310: b606e004                 inc     4, %i3
F00C0314: d026c000                 st      %o0, [%i3]
F00C0318: b606e004                 inc     4, %i3
F00C031C: d0068000                 ld      [%i2], %o0
F00C0320: 80a28008                 cmp     %o2, %o0
F00C0324: 0abffff7                 bcs     loc_F00C0300
F00C0328: 92026002                 inc     2, %o1
F00C032C: d0062124                 ld      [%i0+0x124], %o0! id
F00C0330: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C0334: 4000c54f                 call    _objc_msgSend
F00C0338: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C033C: 81c7e008                 ret
F00C0340: 81e80000                 restore
