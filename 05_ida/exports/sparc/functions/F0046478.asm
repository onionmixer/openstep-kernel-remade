F0046478: 9de3bf98                 save    %sp, -0x68, %sp
F004647C: 92100019                 mov     %i1, %o1! int *
F0046480: 90100018                 mov     %i0, %o0! XDR *
F0046484: 173c0438                 sethi   %hi(unk_F010E170), %o3
F0046488: 94026004                 add     %o1, 4, %o2! char *
F004648C: 9612e170                 bset    %lo(unk_F010E170), %o3! xdr_discrim *
F0046490: 7ffffd32                 call    _xdr_union
F0046494: 98102000                 mov     0, %o4
F0046498: 80a00008                 cmp     %g0, %o0
F004649C: b0402000                 addc    %g0, 0, %i0
F00464A0: 81c7e008                 ret
F00464A4: 81e80000                 restore
