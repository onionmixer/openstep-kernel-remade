F004236C: 9de3bf98                 save    %sp, -0x68, %sp
F0042370: 90100018                 mov     %i0, %o0! XDR *
F0042374: 7ffffcca                 call    _xdr_fhandle
F0042378: 92100019                 mov     %i1, %o1
F004237C: 80a22000                 cmp     %o0, 0
F0042380: 02800007                 be      loc_F004239C
F0042384: 90100018                 mov     %i0, %o0
F0042388: 7fffffa0                 call    _xdr_diropargs
F004238C: 92066020                 add     %i1, 0x20, %o1 ! ' '
F0042390: 80a22000                 cmp     %o0, 0
F0042394: 12800003                 bne     locret_F00423A0
F0042398: b0102001                 mov     1, %i0
F004239C: b0102000                 mov     0, %i0
F00423A0: 81c7e008                 ret
F00423A4: 81e80000                 restore
