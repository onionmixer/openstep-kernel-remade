F00DB674: 9de3bf90                 save    %sp, -0x70, %sp
F00DB678: d0062028                 ld      [%i0+0x28], %o0! id
F00DB67C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DB680: 4000587c                 call    _objc_msgSend
F00DB684: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DB688: d006202c                 ld      [%i0+0x2C], %o0
F00DB68C: 9406202c                 add     %i0, 0x2C, %o2 ! ','
F00DB690: 80a28008                 cmp     %o2, %o0
F00DB694: 12800008                 bne     loc_F00DB6B4
F00DB698: 92100008                 mov     %o0, %o1
F00DB69C: d0062028                 ld      [%i0+0x28], %o0! id
F00DB6A0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DB6A4: 40005873                 call    _objc_msgSend
F00DB6A8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DB6AC: 10800011                 ba      locret_F00DB6F0
F00DB6B0: b0102000                 mov     0, %i0
F00DB6B4: 96102001                 mov     1, %o3
F00DB6B8: 912ea018                 sll     %i2, 24, %o0
F00DB6BC: 913a2018                 sra     %o0, 24, %o0
F00DB6C0: b4102001                 mov     1, %i2
F00DB6C4: d6226034                 st      %o3, [%o1+0x34]
F00DB6C8: d0226038                 st      %o0, [%o1+0x38]
F00DB6CC: d202603c                 ld      [%o1+0x3C], %o1
F00DB6D0: 80a28009                 cmp     %o2, %o1
F00DB6D4: 32bffffd                 bne,a   loc_F00DB6C8
F00DB6D8: d6226034                 st      %o3, [%o1+0x34]
F00DB6DC: d0062028                 ld      [%i0+0x28], %o0! id
F00DB6E0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DB6E4: 40005863                 call    _objc_msgSend
F00DB6E8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DB6EC: b010001a                 mov     %i2, %i0
F00DB6F0: 81c7e008                 ret
F00DB6F4: 81e80000                 restore
