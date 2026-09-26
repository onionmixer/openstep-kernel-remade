F004169C: 9de3bf98                 save    %sp, -0x68, %sp
F00416A0: 90100018                 mov     %i0, %o0! XDR *
F00416A4: 92100019                 mov     %i1, %o1! char *
F00416A8: 4000102e                 call    _xdr_opaque
F00416AC: 94102020                 mov     0x20, %o2 ! ' '
F00416B0: 80a00008                 cmp     %g0, %o0
F00416B4: b0402000                 addc    %g0, 0, %i0
F00416B8: 81c7e008                 ret
F00416BC: 81e80000                 restore
