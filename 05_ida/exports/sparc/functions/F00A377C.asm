F00A377C: 9de3bf98                 save    %sp, -0x68, %sp
F00A3780: 113c0464                 sethi   %hi(aText), %o0! "__TEXT"
F00A3784: 7fff1ad7                 call    _getsegbyname
F00A3788: 90122370                 bset    %lo(aText), %o0! "__TEXT"
F00A378C: d2022018                 ld      [%o0+0x18], %o1
F00A3790: f002201c                 ld      [%o0+0x1C], %i0
F00A3794: 81c7e008                 ret
F00A3798: 91ea4018                 restore %o1, %i0, %o0
