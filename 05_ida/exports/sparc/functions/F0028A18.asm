F0028A18: 9de3bf98                 save    %sp, -0x68, %sp
F0028A1C: 7fff8a9a                 call    _getf
F0028A20: 90100018                 mov     %i0, %o0
F0028A24: 92920000                 orcc    %o0, %g0, %o1
F0028A28: 32800004                 bne,a   loc_F0028A38
F0028A2C: d052600c                 ldsh    [%o1+0xC], %o0
F0028A30: 10800007                 ba      locret_F0028A4C
F0028A34: b0102009                 mov     9, %i0
F0028A38: 80a22001                 cmp     %o0, 1
F0028A3C: 12800004                 bne     locret_F0028A4C
F0028A40: b0102016                 mov     0x16, %i0
F0028A44: d2264000                 st      %o1, [%i1]
F0028A48: b0102000                 mov     0, %i0
F0028A4C: 81c7e008                 ret
F0028A50: 81e80000                 restore
