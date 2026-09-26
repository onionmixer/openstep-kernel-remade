F0042208: 9de3bf98                 save    %sp, -0x68, %sp
F004220C: 90100018                 mov     %i0, %o0! XDR *
F0042210: 7ffffd23                 call    _xdr_fhandle
F0042214: 92100019                 mov     %i1, %o1
F0042218: 80a22000                 cmp     %o0, 0
F004221C: 02800008                 be      loc_F004223C
F0042220: 90100018                 mov     %i0, %o0! XDR *
F0042224: 92066020                 add     %i1, 0x20, %o1 ! ' '! char **
F0042228: 40000df5                 call    _xdr_string
F004222C: 941020ff                 mov     0xFF, %o2
F0042230: 80a22000                 cmp     %o0, 0
F0042234: 12800003                 bne     locret_F0042240
F0042238: b0102001                 mov     1, %i0
F004223C: b0102000                 mov     0, %i0
F0042240: 81c7e008                 ret
F0042244: 81e80000                 restore
