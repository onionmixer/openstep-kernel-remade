F0042330: 9de3bf98                 save    %sp, -0x68, %sp
F0042334: 90100018                 mov     %i0, %o0
F0042338: 7fffffb4                 call    _xdr_diropargs
F004233C: 92100019                 mov     %i1, %o1
F0042340: 80a22000                 cmp     %o0, 0
F0042344: 02800007                 be      loc_F0042360
F0042348: 90100018                 mov     %i0, %o0
F004234C: 7ffffe9f                 call    sub_F0041DC8
F0042350: 92066024                 add     %i1, 0x24, %o1 ! '$'
F0042354: 80a22000                 cmp     %o0, 0
F0042358: 12800003                 bne     locret_F0042364
F004235C: b0102001                 mov     1, %i0
F0042360: b0102000                 mov     0, %i0
F0042364: 81c7e008                 ret
F0042368: 81e80000                 restore
