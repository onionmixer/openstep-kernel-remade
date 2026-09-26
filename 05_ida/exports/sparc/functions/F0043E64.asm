F0043E64: 9de3bf98                 save    %sp, -0x68, %sp
F0043E68: 90100018                 mov     %i0, %o0
F0043E6C: 7fffffe7                 call    _xdr_opaque_auth
F0043E70: 92100019                 mov     %i1, %o1! int *
F0043E74: 80a22000                 cmp     %o0, 0
F0043E78: 0280001a                 be      loc_F0043EE0
F0043E7C: 90100018                 mov     %i0, %o0! XDR *
F0043E80: 40000632                 call    _xdr_enum
F0043E84: 9206600c                 add     %i1, 0xC, %o1
F0043E88: 80a22000                 cmp     %o0, 0
F0043E8C: 2280001a                 be,a    locret_F0043EF4
F0043E90: b0102000                 mov     0, %i0
F0043E94: d006600c                 ld      [%i1+0xC], %o0
F0043E98: 80a22000                 cmp     %o0, 0
F0043E9C: 02800006                 be      loc_F0043EB4
F0043EA0: 80a22002                 cmp     %o0, 2
F0043EA4: 0280000a                 be      loc_F0043ECC
F0043EA8: 90100018                 mov     %i0, %o0
F0043EAC: 10800012                 ba      locret_F0043EF4
F0043EB0: b0102001                 mov     1, %i0
F0043EB4: d2066010                 ld      [%i1+0x10], %o1! unsigned __int32 *
F0043EB8: d4066014                 ld      [%i1+0x14], %o2
F0043EBC: 9fc28000                 call    %o2
F0043EC0: 90100018                 mov     %i0, %o0! XDR *
F0043EC4: 1080000c                 ba      locret_F0043EF4
F0043EC8: b0100008                 mov     %o0, %i0
F0043ECC: 40000588                 call    _xdr_u_long
F0043ED0: 92066010                 add     %i1, 0x10, %o1! unsigned __int32 *
F0043ED4: 80a22000                 cmp     %o0, 0
F0043ED8: 12800004                 bne     loc_F0043EE8
F0043EDC: 90100018                 mov     %i0, %o0! XDR *
F0043EE0: 10800005                 ba      locret_F0043EF4
F0043EE4: b0102000                 mov     0, %i0
F0043EE8: 40000581                 call    _xdr_u_long
F0043EEC: 92066014                 add     %i1, 0x14, %o1
F0043EF0: b0100008                 mov     %o0, %i0
F0043EF4: 81c7e008                 ret
F0043EF8: 81e80000                 restore
