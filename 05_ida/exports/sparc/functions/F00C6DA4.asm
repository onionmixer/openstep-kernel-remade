F00C6DA4: 9de3bf90                 save    %sp, -0x70, %sp
F00C6DA8: 113c0506                 sethi   %hi(paNextlogicaldis_0), %o0! id
F00C6DAC: d2022198                 ld      [%o0+%lo(paNextlogicaldis_0)], %o1! SEL
F00C6DB0: 4000aab0                 call    _objc_msgSend
F00C6DB4: 90100018                 mov     %i0, %o0
F00C6DB8: 94920000                 orcc    %o0, %g0, %o2
F00C6DBC: 02800005                 be      loc_F00C6DD0
F00C6DC0: 113c0503                 sethi   %hi(paFree), %o0! id
F00C6DC4: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C6DC8: 4000aaaa                 call    _objc_msgSend
F00C6DCC: 9010000a                 mov     %o2, %o0
F00C6DD0: f027bff0                 st      %i0, [%fp+var_10]
F00C6DD4: 133c0507                 sethi   %hi(stru_F0141F0C.super_class), %o1
F00C6DD8: d4026310                 ld      [%o1+%lo(stru_F0141F0C.super_class)], %o2
F00C6DDC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C6DE0: 133c0503                 sethi   %hi(paFree), %o1
F00C6DE4: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C6DE8: 4000aae5                 call    _objc_msgSendSuper
F00C6DEC: d427bff4                 st      %o2, [%fp+var_C]
F00C6DF0: 81c7e008                 ret
F00C6DF4: 91e80008                 restore %g0, %o0, %o0
