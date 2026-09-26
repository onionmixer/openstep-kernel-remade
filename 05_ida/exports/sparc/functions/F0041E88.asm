F0041E88: 9de3bf98                 save    %sp, -0x68, %sp
F0041E8C: 94100019                 mov     %i1, %o2! unsigned int *
F0041E90: 90100018                 mov     %i0, %o0! XDR *
F0041E94: 9202a004                 add     %o2, 4, %o1! char **
F0041E98: 40000e70                 call    _xdr_bytes
F0041E9C: 96102400                 mov     0x400, %o3
F0041EA0: 80a00008                 cmp     %g0, %o0
F0041EA4: b0402000                 addc    %g0, 0, %i0
F0041EA8: 81c7e008                 ret
F0041EAC: 81e80000                 restore
