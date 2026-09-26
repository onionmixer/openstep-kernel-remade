F00EF13C: 9de3bf98                 save    %sp, -0x68, %sp
F00EF140: 133c0505                 sethi   %hi(paIsequal), %o1
F00EF144: 90100019                 mov     %i1, %o0! id
F00EF148: d2026150                 ld      [%o1+%lo(paIsequal)], %o1! SEL
F00EF14C: 400009c9                 call    _objc_msgSend
F00EF150: 9410001a                 mov     %i2, %o2
F00EF154: 912a2018                 sll     %o0, 24, %o0
F00EF158: b13a2018                 sra     %o0, 24, %i0
F00EF15C: 81c7e008                 ret
F00EF160: 81e80000                 restore
