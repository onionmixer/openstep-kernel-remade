F00C024C: 9de3bf90                 save    %sp, -0x70, %sp
F00C0250: 80a6a014                 cmp     %i2, 0x14
F00C0254: 38800002                 bgu,a   loc_F00C025C
F00C0258: b4102014                 mov     0x14, %i2
F00C025C: d0062124                 ld      [%i0+0x124], %o0! id
F00C0260: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C0264: 4000c583                 call    _objc_msgSend
F00C0268: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C026C: 94102000                 mov     0, %o2
F00C0270: 80a2801a                 cmp     %o2, %i2
F00C0274: 1a80000d                 bcc     loc_F00C02A8
F00C0278: f4262138                 st      %i2, [%i0+0x138]
F00C027C: 92100018                 mov     %i0, %o1
F00C0280: d006c000                 ld      [%i3], %o0
F00C0284: 9402a001                 inc     %o2
F00C0288: d032613c                 sth     %o0, [%o1+0x13C]
F00C028C: b606e004                 inc     4, %i3
F00C0290: d006c000                 ld      [%i3], %o0
F00C0294: 80a2801a                 cmp     %o2, %i2
F00C0298: d0326164                 sth     %o0, [%o1+0x164]
F00C029C: b606e004                 inc     4, %i3
F00C02A0: 0abffff8                 bcs     loc_F00C0280
F00C02A4: 92026002                 inc     2, %o1
F00C02A8: d0062124                 ld      [%i0+0x124], %o0! id
F00C02AC: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C02B0: 4000c570                 call    _objc_msgSend
F00C02B4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C02B8: 81c7e008                 ret
F00C02BC: 81e80000                 restore
