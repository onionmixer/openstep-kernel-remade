F008F214: 9de3bf90                 save    %sp, -0x70, %sp
F008F218: 7fffff05                 call    sub_F008EE2C
F008F21C: 9010001a                 mov     %i2, %o0
F008F220: 96100008                 mov     %o0, %o3
F008F224: d0062010                 ld      [%i0+0x10], %o0! id
F008F228: 133c0504                 sethi   %hi(paInsertkeyValue), %o1
F008F22C: d2026068                 ld      [%o1+%lo(paInsertkeyValue)], %o1! SEL
F008F230: 40018990                 call    _objc_msgSend
F008F234: 9410001b                 mov     %i3, %o2
F008F238: 80a22000                 cmp     %o0, 0
F008F23C: 02800004                 be      locret_F008F24C
F008F240: 01000000                 nop
F008F244: 7fffff06                 call    sub_F008EE5C
F008F248: 01000000                 nop
F008F24C: 81c7e008                 ret
F008F250: 81e80000                 restore
