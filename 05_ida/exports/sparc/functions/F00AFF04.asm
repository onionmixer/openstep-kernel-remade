F00AFF04: 9de3bf98                 save    %sp, -0x68, %sp
F00AFF08: 7ffffdf7                 call    _prom_stdoutpath
F00AFF0C: 01000000                 nop
F00AFF10: 80a22000                 cmp     %o0, 0
F00AFF14: 2280000f                 be,a    loc_F00AFF50
F00AFF18: 113c0470                 sethi   -0xFEE4000, %o0
F00AFF1C: 40000bf5                 call    _path_to_devi
F00AFF20: 01000000                 nop
F00AFF24: 92920000                 orcc    %o0, %g0, %o1
F00AFF28: 02800009                 be      loc_F00AFF4C
F00AFF2C: 80a66002                 cmp     %i1, 2
F00AFF30: 04800022                 ble     loc_F00AFFB8
F00AFF34: 90060019                 add     %i0, %i1, %o0
F00AFF38: c02a3fff                 clrb    [%o0-1]
F00AFF3C: 90100018                 mov     %i0, %o0
F00AFF40: d202600c                 ld      [%o1+0xC], %o1
F00AFF44: 1080001a                 ba      loc_F00AFFAC
F00AFF48: 94067fff                 add     %i1, -1, %o2
F00AFF4C: 113c0470                 sethi   -0xFEE4000, %o0
F00AFF50: d0022278                 ld      [%o0+0x278], %o0
F00AFF54: 80a22000                 cmp     %o0, 0
F00AFF58: 02800004                 be      loc_F00AFF68
F00AFF5C: 80a22002                 cmp     %o0, 2
F00AFF60: 32800017                 bne,a   locret_F00AFFBC
F00AFF64: b0103fff                 mov     -1, %i0
F00AFF68: 113c000c                 sethi   %hi(_romp), %o0
F00AFF6C: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AFF70: d002204c                 ld      [%o0+0x4C], %o0
F00AFF74: d00a0000                 ldub    [%o0], %o0
F00AFF78: 80a22000                 cmp     %o0, 0
F00AFF7C: 22800010                 be,a    locret_F00AFFBC
F00AFF80: b0103fff                 mov     -1, %i0
F00AFF84: 0680000d                 bl      loc_F00AFFB8
F00AFF88: 80a22004                 cmp     %o0, 4
F00AFF8C: 3480000c                 bg,a    locret_F00AFFBC
F00AFF90: b0103fff                 mov     -1, %i0
F00AFF94: 80a66002                 cmp     %i1, 2
F00AFF98: 04800008                 ble     loc_F00AFFB8
F00AFF9C: 90100018                 mov     %i0, %o0! __dst
F00AFFA0: 133c047092126358         set     aZs_0, %o1! "zs"
F00AFFA8: 94100019                 mov     %i1, %o2! __n
F00AFFAC: 7ffd5e5c                 call    _strncpy
F00AFFB0: b0102000                 mov     0, %i0
F00AFFB4: 30800002                 ba,a    locret_F00AFFBC
F00AFFB8: b0103fff                 mov     -1, %i0
F00AFFBC: 81c7e008                 ret
F00AFFC0: 81e80000                 restore
