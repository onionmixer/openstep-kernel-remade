F00465A4: 9de3bf98                 save    %sp, -0x68, %sp
F00465A8: 90100018                 mov     %i0, %o0! XDR *
F00465AC: 7ffffbaa                 call    _xdr_int
F00465B0: 92100019                 mov     %i1, %o1! _fhandle
F00465B4: 80a22000                 cmp     %o0, 0
F00465B8: 2280000d                 be,a    locret_F00465EC
F00465BC: b0102000                 mov     0, %i0
F00465C0: d0064000                 ld      [%i1], %o0
F00465C4: 80a22000                 cmp     %o0, 0
F00465C8: 32800009                 bne,a   locret_F00465EC
F00465CC: b0102001                 mov     1, %i0
F00465D0: 90100018                 mov     %i0, %o0! XDR *
F00465D4: 7fffec32                 call    _xdr_fhandle
F00465D8: 92066004                 add     %i1, 4, %o1
F00465DC: 80a22000                 cmp     %o0, 0
F00465E0: 12800003                 bne     locret_F00465EC
F00465E4: b0102001                 mov     1, %i0
F00465E8: b0102000                 mov     0, %i0
F00465EC: 81c7e008                 ret
F00465F0: 81e80000                 restore
