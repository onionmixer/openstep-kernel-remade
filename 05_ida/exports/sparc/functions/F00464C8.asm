F00464C8: 9de3bf98                 save    %sp, -0x68, %sp
F00464CC: 90100018                 mov     %i0, %o0! XDR *
F00464D0: 7fffffb6                 call    _xdr_bp_machine_name_t
F00464D4: 92100019                 mov     %i1, %o1! bp_machine_name_t *
F00464D8: 80a22000                 cmp     %o0, 0
F00464DC: 02800007                 be      loc_F00464F8
F00464E0: 90100018                 mov     %i0, %o0! XDR *
F00464E4: 7fffffb1                 call    _xdr_bp_machine_name_t
F00464E8: 92066004                 add     %i1, 4, %o1! bp_address *
F00464EC: 80a22000                 cmp     %o0, 0
F00464F0: 12800004                 bne     loc_F0046500
F00464F4: 90100018                 mov     %i0, %o0! XDR *
F00464F8: 10800006                 ba      locret_F0046510
F00464FC: b0102000                 mov     0, %i0
F0046500: 7fffffde                 call    _xdr_bp_address
F0046504: 92066008                 add     %i1, 8, %o1
F0046508: 80a00008                 cmp     %g0, %o0
F004650C: b0402000                 addc    %g0, 0, %i0
F0046510: 81c7e008                 ret
F0046514: 81e80000                 restore
