F0045958: 9de3bf98                 save    %sp, -0x68, %sp
F004595C: 90100018                 mov     %i0, %o0! XDR *
F0045960: 7fffff7a                 call    _xdr_enum
F0045964: 92100019                 mov     %i1, %o1
F0045968: 80a22000                 cmp     %o0, 0
F004596C: 32800007                 bne,a   loc_F0045988
F0045970: d006e004                 ld      [%i3+4], %o0
F0045974: 113c0438                 sethi   %hi(aXdrEnumDscmpFa), %o0! "xdr_enum: dscmp FAILED\n"
F0045978: 7fff3b38                 call    _printf
F004597C: 90122000                 bset    %lo(aXdrEnumDscmpFa), %o0! "xdr_enum: dscmp FAILED\n"
F0045980: 1080001d                 ba      locret_F00459F4
F0045984: b0102000                 mov     0, %i0
F0045988: 80a22000                 cmp     %o0, 0
F004598C: 0280000b                 be      loc_F00459B8
F0045990: d2064000                 ld      [%i1], %o1
F0045994: d006c000                 ld      [%i3], %o0
F0045998: 80a20009                 cmp     %o0, %o1
F004599C: 0280000c                 be      loc_F00459CC
F00459A0: 90100018                 mov     %i0, %o0
F00459A4: b606e008                 inc     8, %i3
F00459A8: d006e004                 ld      [%i3+4], %o0
F00459AC: 80a22000                 cmp     %o0, 0
F00459B0: 32bffffa                 bne,a   loc_F0045998
F00459B4: d006c000                 ld      [%i3], %o0
F00459B8: 80a72000                 cmp     %i4, 0
F00459BC: 1280000a                 bne     loc_F00459E4
F00459C0: 90100018                 mov     %i0, %o0
F00459C4: 1080000c                 ba      locret_F00459F4
F00459C8: b0102000                 mov     0, %i0
F00459CC: 9210001a                 mov     %i2, %o1
F00459D0: d606e004                 ld      [%i3+4], %o3
F00459D4: 9fc2c000                 call    %o3
F00459D8: 94103fff                 mov     -1, %o2
F00459DC: 10800006                 ba      locret_F00459F4
F00459E0: b0100008                 mov     %o0, %i0
F00459E4: 9210001a                 mov     %i2, %o1
F00459E8: 9fc70000                 call    %i4
F00459EC: 94103fff                 mov     -1, %o2
F00459F0: b0100008                 mov     %o0, %i0
F00459F4: 81c7e008                 ret
F00459F8: 81e80000                 restore
