F0046554: 9de3bf98                 save    %sp, -0x68, %sp
F0046558: 90100018                 mov     %i0, %o0! XDR *
F004655C: 7fffff93                 call    _xdr_bp_machine_name_t
F0046560: 92100019                 mov     %i1, %o1! bp_address *
F0046564: 80a22000                 cmp     %o0, 0
F0046568: 02800007                 be      loc_F0046584
F004656C: 90100018                 mov     %i0, %o0! XDR *
F0046570: 7fffffc2                 call    _xdr_bp_address
F0046574: 92066004                 add     %i1, 4, %o1! bp_path_t *
F0046578: 80a22000                 cmp     %o0, 0
F004657C: 12800004                 bne     loc_F004658C
F0046580: 90100018                 mov     %i0, %o0! XDR *
F0046584: 10800006                 ba      locret_F004659C
F0046588: b0102000                 mov     0, %i0
F004658C: 7fffff90                 call    _xdr_bp_path_t
F0046590: 9206600c                 add     %i1, 0xC, %o1
F0046594: 80a00008                 cmp     %g0, %o0
F0046598: b0402000                 addc    %g0, 0, %i0
F004659C: 81c7e008                 ret
F00465A0: 81e80000                 restore
