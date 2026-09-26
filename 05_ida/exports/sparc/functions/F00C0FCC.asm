F00C0FCC: 9de3bf98                 save    %sp, -0x68, %sp
F00C0FD0: f027a044                 st      %i0, [%fp+arg_44]
F00C0FD4: 7fffffc8                 call    sub_F00C0EF4
F00C0FD8: 9007a044                 add     %fp, arg_44, %o0
F00C0FDC: b0920000                 orcc    %o0, %g0, %i0
F00C0FE0: 02800012                 be      locret_F00C1028
F00C0FE4: 01000000                 nop
F00C0FE8: d0062018                 ld      [%i0+0x18], %o0
F00C0FEC: 80a22000                 cmp     %o0, 0
F00C0FF0: 02800008                 be      loc_F00C1010
F00C0FF4: 90100018                 mov     %i0, %o0
F00C0FF8: c02e2001                 clrb    [%i0+1]
F00C0FFC: c02e2002                 clrb    [%i0+2]
F00C1000: d007a044                 ld      [%fp+arg_44], %o0! void *
F00C1004: 7fffffd2                 call    _kbdcmd
F00C1008: 92102001                 mov     1, %o1! size_t
F00C100C: 30800007                 ba,a    locret_F00C1028
F00C1010: 7fff4f92                 call    _bzero
F00C1014: 92102014                 mov     0x14, %o1
F00C1018: 9010200f                 mov     0xF, %o0
F00C101C: d02e0000                 stb     %o0, [%i0]
F00C1020: 90102003                 mov     3, %o0
F00C1024: d02e2001                 stb     %o0, [%i0+1]
F00C1028: 81c7e008                 ret
F00C102C: 81e80000                 restore
