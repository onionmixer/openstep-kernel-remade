F00C8E5C: 9de3bf90                 save    %sp, -0x70, %sp
F00C8E60: 113c0506                 sethi   %hi(paDelegate), %o0! id
F00C8E64: d2022118                 ld      [%o0+%lo(paDelegate)], %o1! SEL
F00C8E68: a0103d42                 mov     -0x2BE, %l0
F00C8E6C: 4000a281                 call    _objc_msgSend
F00C8E70: 90100018                 mov     %i0, %o0! id
F00C8E74: 133c0506                 sethi   %hi(paAllocateitemsN), %o1
F00C8E78: 193c03eb                 sethi   %hi(aIrqLevels), %o4! "IRQ Levels"
F00C8E7C: 9410001a                 mov     %i2, %o2
F00C8E80: 9610001b                 mov     %i3, %o3
F00C8E84: d2026110                 ld      [%o1+%lo(paAllocateitemsN)], %o1! SEL
F00C8E88: 4000a27a                 call    _objc_msgSend
F00C8E8C: 981323d8                 bset    %lo(aIrqLevels), %o4! "IRQ Levels"
F00C8E90: 80a22000                 cmp     %o0, 0
F00C8E94: 0280000c                 be      locret_F00C8EC4
F00C8E98: 01000000                 nop
F00C8E9C: f0062010                 ld      [%i0+0x10], %i0
F00C8EA0: d2062004                 ld      [%i0+4], %o1
F00C8EA4: 80a26000                 cmp     %o1, 0
F00C8EA8: 22800006                 be,a    loc_F00C8EC0
F00C8EAC: c0262004                 clr     [%i0+4]
F00C8EB0: d0060000                 ld      [%i0], %o0
F00C8EB4: 7ffff424                 call    _IOFree
F00C8EB8: 932a6002                 sll     %o1, 2, %o1
F00C8EBC: c0262004                 clr     [%i0+4]
F00C8EC0: a0102000                 mov     0, %l0
F00C8EC4: 81c7e008                 ret
F00C8EC8: 91e80010                 restore %g0, %l0, %o0
