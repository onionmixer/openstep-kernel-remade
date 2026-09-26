F00EBBCC: 9de3bf90                 save    %sp, -0x70, %sp
F00EBBD0: 113c0506a2122228         set     paError, %l1
F00EBBD8: d0060000                 ld      [%i0], %o0
F00EBBDC: d0022010                 ld      [%o0+0x10], %o0! sel
F00EBBE0: 808a2002                 btst    2, %o0
F00EBBE4: 02800003                 be      loc_F00EBBF0
F00EBBE8: a010202d                 mov     0x2D, %l0 ! '-'
F00EBBEC: a010202b                 mov     0x2B, %l0 ! '+'
F00EBBF0: 40001ebb                 call    _sel_getName
F00EBBF4: 9010001a                 mov     %i2, %o0
F00EBBF8: 98100008                 mov     %o0, %o4
F00EBBFC: 90100018                 mov     %i0, %o0! id
F00EBC00: d2044000                 ld      [%l1], %o1! SEL
F00EBC04: 153c03e89412a250         set     aDoesNotRecogni_0, %o2! "does not recognize selector %c%s"
F00EBC0C: 40001719                 call    _objc_msgSend
F00EBC10: 96100010                 mov     %l0, %o3
F00EBC14: 81c7e008                 ret
F00EBC18: 91e80008                 restore %g0, %o0, %o0
