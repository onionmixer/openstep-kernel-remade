F00BF56C: 9de3bf88                 save    %sp, -0x78, %sp
F00BF570: 113c0504                 sethi   %hi(paOwner_0), %o0! id
F00BF574: d2022298                 ld      [%o0+%lo(paOwner_0)], %o1! SEL
F00BF578: 4000c8be                 call    _objc_msgSend
F00BF57C: 90100018                 mov     %i0, %o0! id
F00BF580: d6062148                 ld      [%i0+0x148], %o3
F00BF584: 9410001a                 mov     %i2, %o2
F00BF588: d81e2158                 ldd     [%i0+0x158], %o4
F00BF58C: 133c0504                 sethi   %hi(paKeyboardspecia_0), %o1
F00BF590: d20262a4                 ld      [%o1+%lo(paKeyboardspecia_0)], %o1! SEL
F00BF594: d823a05c                 st      %o4, [%sp+0x78+var_1C]
F00BF598: da23a060                 st      %o5, [%sp+0x78+var_18]
F00BF59C: 9616c00b                 bset    %i3, %o3
F00BF5A0: 9810001c                 mov     %i4, %o4
F00BF5A4: 4000c8b3                 call    _objc_msgSend
F00BF5A8: 9a10001d                 mov     %i5, %o5
F00BF5AC: 80a76004                 cmp     %i5, 4
F00BF5B0: 02800008                 be      locret_F00BF5D0
F00BF5B4: 90100018                 mov     %i0, %o0! id
F00BF5B8: 133c0504                 sethi   %hi(paSetrepeatForco), %o1
F00BF5BC: d20262a0                 ld      [%o1+%lo(paSetrepeatForco)], %o1! SEL
F00BF5C0: 9410001a                 mov     %i2, %o2
F00BF5C4: 4000c8ab                 call    _objc_msgSend
F00BF5C8: 9610001c                 mov     %i4, %o3
F00BF5CC: b0100008                 mov     %o0, %i0
F00BF5D0: 81c7e008                 ret
F00BF5D4: 81e80000                 restore
