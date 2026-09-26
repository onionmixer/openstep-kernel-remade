F00B374C: 9de3bf98                 save    %sp, -0x68, %sp
F00B3750: 90100018                 mov     %i0, %o0! __s1
F00B3754: 133c0478                 sethi   %hi(unk_F011E2B0), %o1! __s2
F00B3758: 7ffd5295                 call    _strcmp
F00B375C: 921262b0                 bset    %lo(unk_F011E2B0), %o1
F00B3760: 80a22000                 cmp     %o0, 0
F00B3764: 02800008                 be      loc_F00B3784
F00B3768: 90100018                 mov     %i0, %o0! __s1
F00B376C: 133c0478                 sethi   %hi(aSunwEsp), %o1! "SUNW,esp"
F00B3770: 7ffd528f                 call    _strcmp
F00B3774: 921262b8                 bset    %lo(aSunwEsp), %o1! "SUNW,esp"
F00B3778: 80a22000                 cmp     %o0, 0
F00B377C: 12800007                 bne     locret_F00B3798
F00B3780: b0102000                 mov     0, %i0
F00B3784: 133c04fc                 sethi   %hi(_nesp), %o1
F00B3788: d0026098                 ld      [%o1+%lo(_nesp)], %o0
F00B378C: b0102001                 mov     1, %i0
F00B3790: 90022001                 inc     %o0
F00B3794: d0226098                 st      %o0, [%o1+%lo(_nesp)]
F00B3798: 81c7e008                 ret
F00B379C: 81e80000                 restore
