F00EC128: 9de3bf90                 save    %sp, -0x70, %sp
F00EC12C: 133c0506                 sethi   %hi(paIskindofclassn), %o1
F00EC130: 90100018                 mov     %i0, %o0! id
F00EC134: d2026210                 ld      [%o1+%lo(paIskindofclassn)], %o1! SEL
F00EC138: 400015ce                 call    _objc_msgSend
F00EC13C: 9410001a                 mov     %i2, %o2
F00EC140: 912a2018                 sll     %o0, 24, %o0
F00EC144: b13a2018                 sra     %o0, 24, %i0
F00EC148: 81c7e008                 ret
F00EC14C: 81e80000                 restore
