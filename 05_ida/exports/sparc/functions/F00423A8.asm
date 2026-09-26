F00423A8: 9de3bf98                 save    %sp, -0x68, %sp
F00423AC: 90100018                 mov     %i0, %o0
F00423B0: 7fffff96                 call    _xdr_diropargs
F00423B4: 92100019                 mov     %i1, %o1
F00423B8: 80a22000                 cmp     %o0, 0
F00423BC: 02800007                 be      loc_F00423D8
F00423C0: 90100018                 mov     %i0, %o0
F00423C4: 7fffff91                 call    _xdr_diropargs
F00423C8: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00423CC: 80a22000                 cmp     %o0, 0
F00423D0: 12800003                 bne     locret_F00423DC
F00423D4: b0102001                 mov     1, %i0
F00423D8: b0102000                 mov     0, %i0
F00423DC: 81c7e008                 ret
F00423E0: 81e80000                 restore
