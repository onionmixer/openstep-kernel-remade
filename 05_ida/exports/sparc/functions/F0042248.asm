F0042248: 9de3bf98                 save    %sp, -0x68, %sp
F004224C: 90100018                 mov     %i0, %o0! XDR *
F0042250: 7ffffd13                 call    _xdr_fhandle
F0042254: 92100019                 mov     %i1, %o1
F0042258: 80a22000                 cmp     %o0, 0
F004225C: 02800007                 be      loc_F0042278
F0042260: 90100018                 mov     %i0, %o0
F0042264: 7ffffd48                 call    sub_F0041784
F0042268: 92066020                 add     %i1, 0x20, %o1 ! ' '
F004226C: 80a22000                 cmp     %o0, 0
F0042270: 12800003                 bne     locret_F004227C
F0042274: b0102001                 mov     1, %i0
F0042278: b0102000                 mov     0, %i0
F004227C: 81c7e008                 ret
F0042280: 81e80000                 restore
