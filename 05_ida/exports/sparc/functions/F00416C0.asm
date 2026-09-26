F00416C0: 9de3bf98                 save    %sp, -0x68, %sp
F00416C4: 90100018                 mov     %i0, %o0! XDR *
F00416C8: 7ffffff5                 call    _xdr_fhandle
F00416CC: 92100019                 mov     %i1, %o1! __int32 *
F00416D0: 80a22000                 cmp     %o0, 0
F00416D4: 02800029                 be      loc_F0041778
F00416D8: 90100018                 mov     %i0, %o0! XDR *
F00416DC: 40000f6a                 call    _xdr_long
F00416E0: 92066020                 add     %i1, 0x20, %o1 ! ' '! __int32 *
F00416E4: 80a22000                 cmp     %o0, 0
F00416E8: 02800024                 be      loc_F0041778
F00416EC: 90100018                 mov     %i0, %o0! XDR *
F00416F0: 40000f65                 call    _xdr_long
F00416F4: 92066024                 add     %i1, 0x24, %o1 ! '$'! __int32 *
F00416F8: 80a22000                 cmp     %o0, 0
F00416FC: 0280001f                 be      loc_F0041778
F0041700: 90100018                 mov     %i0, %o0! XDR *
F0041704: 40000f60                 call    _xdr_long
F0041708: 92066028                 add     %i1, 0x28, %o1 ! '('
F004170C: 80a22000                 cmp     %o0, 0
F0041710: 0280001a                 be      loc_F0041778
F0041714: 113c0438                 sethi   %hi(_xdrmbuf_ops), %o0
F0041718: d2062004                 ld      [%i0+4], %o1
F004171C: 901220b0                 bset    %lo(_xdrmbuf_ops), %o0
F0041720: 80a24008                 cmp     %o1, %o0
F0041724: 1280000e                 bne     loc_F004175C
F0041728: 90100018                 mov     %i0, %o0
F004172C: d0060000                 ld      [%i0], %o0
F0041730: 80a22001                 cmp     %o0, 1
F0041734: 1280000a                 bne     loc_F004175C
F0041738: 90100018                 mov     %i0, %o0! XDR *
F004173C: 92066034                 add     %i1, 0x34, %o1 ! '4'
F0041740: 400011cd                 call    _xdrmbuf_getmbuf
F0041744: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F0041748: 80a22000                 cmp     %o0, 0
F004174C: 1280000c                 bne     locret_F004177C
F0041750: b0102001                 mov     1, %i0
F0041754: 1080000a                 ba      locret_F004177C
F0041758: b0102000                 mov     0, %i0
F004175C: 92066030                 add     %i1, 0x30, %o1 ! '0'! char **
F0041760: 9406602c                 add     %i1, 0x2C, %o2 ! ','! unsigned int *
F0041764: 4000103d                 call    _xdr_bytes
F0041768: 17000008                 sethi   0x2000, %o3
F004176C: 80a22000                 cmp     %o0, 0
F0041770: 12800003                 bne     locret_F004177C
F0041774: b0102001                 mov     1, %i0
F0041778: b0102000                 mov     0, %i0
F004177C: 81c7e008                 ret
F0041780: 81e80000                 restore
