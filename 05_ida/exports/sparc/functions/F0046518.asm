F0046518: 9de3bf98                 save    %sp, -0x68, %sp
F004651C: 90100018                 mov     %i0, %o0! XDR *
F0046520: 7fffffa2                 call    _xdr_bp_machine_name_t
F0046524: 92100019                 mov     %i1, %o1! bp_fileid_t *
F0046528: 80a22000                 cmp     %o0, 0
F004652C: 12800004                 bne     loc_F004653C
F0046530: 90100018                 mov     %i0, %o0! XDR *
F0046534: 10800006                 ba      locret_F004654C
F0046538: b0102000                 mov     0, %i0
F004653C: 7fffffad                 call    _xdr_bp_fileid_t
F0046540: 92066004                 add     %i1, 4, %o1
F0046544: 80a00008                 cmp     %g0, %o0
F0046548: b0402000                 addc    %g0, 0, %i0
F004654C: 81c7e008                 ret
F0046550: 81e80000                 restore
