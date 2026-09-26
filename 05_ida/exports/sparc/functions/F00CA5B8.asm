F00CA5B8: 9de3bf90                 save    %sp, -0x70, %sp
F00CA5BC: 9410001a                 mov     %i2, %o2
F00CA5C0: 80a2bcdf                 cmp     %o2, -0x321
F00CA5C4: 02800007                 be      loc_F00CA5E0
F00CA5C8: 80a2bce0                 cmp     %o2, -0x320
F00CA5CC: 12800008                 bne     loc_F00CA5EC
F00CA5D0: 113c0508                 sethi   -0xFEBE000, %o0! objc_super *
F00CA5D4: 313c03ec                 sethi   %hi(aBufferFlushed), %i0! "Buffer Flushed"
F00CA5D8: 1080000d                 ba      locret_F00CA60C
F00CA5DC: b0162088                 bset    %lo(aBufferFlushed), %i0! "Buffer Flushed"
F00CA5E0: 313c03ec                 sethi   %hi(aNotOwner), %i0! "Not Owner"
F00CA5E4: 1080000a                 ba      locret_F00CA60C
F00CA5E8: b0162098                 bset    %lo(aNotOwner), %i0! "Not Owner"
F00CA5EC: d2022028                 ld      [%o0+0x28], %o1
F00CA5F0: f027bff0                 st      %i0, [%fp+var_10]
F00CA5F4: d227bff4                 st      %o1, [%fp+var_C]
F00CA5F8: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00CA5FC: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00CA600: 40009cdf                 call    _objc_msgSendSuper
F00CA604: 9007bff0                 add     %fp, var_10, %o0
F00CA608: b0100008                 mov     %o0, %i0
F00CA60C: 81c7e008                 ret
F00CA610: 81e80000                 restore
