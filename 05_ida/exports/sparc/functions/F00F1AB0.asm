F00F1AB0: 9de3bfa0                 save    %sp, -0x60, %sp
F00F1AB4: 053c0506                 sethi   %hi(paForward), %g2
F00F1AB8: c400a1f8                 ld      [%g2+%lo(paForward)], %g2
F00F1ABC: 80a64002                 cmp     %i1, %g2
F00F1AC0: 02800010                 be      loc_F00F1B00
F00F1AC4: 01000000                 nop
F00F1AC8: 8207a044                 add     %fp, arg_44, %g1
F00F1ACC: f0204000                 st      %i0, [%g1]
F00F1AD0: f2206004                 st      %i1, [%g1+4]
F00F1AD4: f4206008                 st      %i2, [%g1+8]
F00F1AD8: f620600c                 st      %i3, [%g1+0xC]
F00F1ADC: f8206010                 st      %i4, [%g1+0x10]
F00F1AE0: fa206014                 st      %i5, [%g1+0x14]
F00F1AE4: 94100019                 mov     %i1, %o2
F00F1AE8: 92100002                 mov     %g2, %o1! SEL
F00F1AEC: 96100001                 mov     %g1, %o3
F00F1AF0: 7fffff60                 call    _objc_msgSend
F00F1AF4: 90100018                 mov     %i0, %o0
F00F1AF8: 81c7e008                 ret
F00F1AFC: 91e80008                 restore %g0, %o0, %o0
F00F1B00: 94100019                 mov     %i1, %o2
F00F1B04: 333c03f4b2166250         set     aDoesNotRecogni, %i1! "Does not recognize selector %s"
F00F1B0C: 10bffba5                 ba      __objc_error
F00F1B10: 01000000                 nop
