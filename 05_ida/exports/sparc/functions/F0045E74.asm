F0045E74: 9de3bf98                 save    %sp, -0x68, %sp
F0045E78: 90100018                 mov     %i0, %o0! XDR *
F0045E7C: 7ffffd7c                 call    _xdr_u_int
F0045E80: 9210001a                 mov     %i2, %o1
F0045E84: 80a22000                 cmp     %o0, 0
F0045E88: 0280001b                 be      loc_F0045EF4
F0045E8C: 98102000                 mov     0, %o4
F0045E90: d6062010                 ld      [%i0+0x10], %o3
F0045E94: d0062014                 ld      [%i0+0x14], %o0
F0045E98: d452e008                 ldsh    [%o3+8], %o2
F0045E9C: 80a2e000                 cmp     %o3, 0
F0045EA0: d202e004                 ld      [%o3+4], %o1
F0045EA4: 94228008                 sub     %o2, %o0, %o2
F0045EA8: 9202400a                 add     %o1, %o2, %o1
F0045EAC: d012e008                 lduh    [%o3+8], %o0
F0045EB0: d222e004                 st      %o1, [%o3+4]
F0045EB4: 9022000a                 sub     %o0, %o2, %o0
F0045EB8: d032e008                 sth     %o0, [%o3+8]
F0045EBC: 02800007                 be      loc_F0045ED8
F0045EC0: d6264000                 st      %o3, [%i1]
F0045EC4: d052e008                 ldsh    [%o3+8], %o0
F0045EC8: d602c000                 ld      [%o3], %o3
F0045ECC: 80a2e000                 cmp     %o3, 0
F0045ED0: 12bffffd                 bne     loc_F0045EC4
F0045ED4: 98030008                 add     %o4, %o0, %o4
F0045ED8: d0068000                 ld      [%i2], %o0
F0045EDC: 80a30008                 cmp     %o4, %o0
F0045EE0: 1a800006                 bcc     locret_F0045EF8
F0045EE4: b0102001                 mov     1, %i0
F0045EE8: 113c0438                 sethi   %hi(aXdrmbufGetmbuf), %o0! "xdrmbuf_getmbuf failed\n"
F0045EEC: 7fff39db                 call    _printf
F0045EF0: 90122118                 bset    %lo(aXdrmbufGetmbuf), %o0! "xdrmbuf_getmbuf failed\n"
F0045EF4: b0102000                 mov     0, %i0
F0045EF8: 81c7e008                 ret
F0045EFC: 81e80000                 restore
