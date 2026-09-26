F00C3FE4: 9de3bf90                 save    %sp, -0x70, %sp
F00C3FE8: 90100018                 mov     %i0, %o0! id
F00C3FEC: 133c0504                 sethi   %hi(paRegisterbuscla), %o1
F00C3FF0: 173c04ba                 sethi   %hi(aSparc_2), %o3! "SPARC"
F00C3FF4: 94100018                 mov     %i0, %o2
F00C3FF8: d202636c                 ld      [%o1+%lo(paRegisterbuscla)], %o1! SEL
F00C3FFC: 4000b61d                 call    _objc_msgSend
F00C4000: 9612e1d0                 bset    %lo(aSparc_2), %o3! "SPARC"
F00C4004: 113c0506                 sethi   %hi(paList), %o0
F00C4008: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F00C400C: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00C4010: 4000b618                 call    _objc_msgSend
F00C4014: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00C4018: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00C401C: 4000b615                 call    _objc_msgSend
F00C4020: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00C4024: 133c04cc                 sethi   %hi(dword_F013302C), %o1
F00C4028: d022602c                 st      %o0, [%o1+%lo(dword_F013302C)]
F00C402C: 81c7e008                 ret
F00C4030: 81e80000                 restore
