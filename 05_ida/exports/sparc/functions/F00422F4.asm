F00422F4: 9de3bf98                 save    %sp, -0x68, %sp
F00422F8: 90100018                 mov     %i0, %o0! XDR *
F00422FC: 7ffffce8                 call    _xdr_fhandle
F0042300: 92100019                 mov     %i1, %o1
F0042304: 80a22000                 cmp     %o0, 0
F0042308: 02800007                 be      loc_F0042324
F004230C: 90100018                 mov     %i0, %o0
F0042310: 7ffffeae                 call    sub_F0041DC8
F0042314: 92066020                 add     %i1, 0x20, %o1 ! ' '
F0042318: 80a22000                 cmp     %o0, 0
F004231C: 12800003                 bne     locret_F0042328
F0042320: b0102001                 mov     1, %i0
F0042324: b0102000                 mov     0, %i0
F0042328: 81c7e008                 ret
F004232C: 81e80000                 restore
