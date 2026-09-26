F00442CC: 9de3bf98                 save    %sp, -0x68, %sp
F00442D0: c0266004                 clr     [%i1+4]
F00442D4: 90102002                 mov     2, %o0
F00442D8: d0266008                 st      %o0, [%i1+8]
F00442DC: d0060000                 ld      [%i0], %o0
F00442E0: 80a22000                 cmp     %o0, 0
F00442E4: 3280001c                 bne,a   locret_F0044354
F00442E8: b0102000                 mov     0, %i0
F00442EC: 90100018                 mov     %i0, %o0! XDR *
F00442F0: 4000047f                 call    _xdr_u_long
F00442F4: 92100019                 mov     %i1, %o1! int *
F00442F8: 80a22000                 cmp     %o0, 0
F00442FC: 02800015                 be      loc_F0044350
F0044300: 90100018                 mov     %i0, %o0! XDR *
F0044304: 40000511                 call    _xdr_enum
F0044308: 92066004                 add     %i1, 4, %o1! unsigned __int32 *
F004430C: 80a22000                 cmp     %o0, 0
F0044310: 02800010                 be      loc_F0044350
F0044314: 90100018                 mov     %i0, %o0! XDR *
F0044318: 40000475                 call    _xdr_u_long
F004431C: 92066008                 add     %i1, 8, %o1! unsigned __int32 *
F0044320: 80a22000                 cmp     %o0, 0
F0044324: 0280000b                 be      loc_F0044350
F0044328: 90100018                 mov     %i0, %o0! XDR *
F004432C: 40000470                 call    _xdr_u_long
F0044330: 9206600c                 add     %i1, 0xC, %o1! unsigned __int32 *
F0044334: 80a22000                 cmp     %o0, 0
F0044338: 02800006                 be      loc_F0044350
F004433C: 90100018                 mov     %i0, %o0! XDR *
F0044340: 4000046b                 call    _xdr_u_long
F0044344: 92066010                 add     %i1, 0x10, %o1
F0044348: 10800003                 ba      locret_F0044354
F004434C: b0100008                 mov     %o0, %i0
F0044350: b0102000                 mov     0, %i0
F0044354: 81c7e008                 ret
F0044358: 81e80000                 restore
