F00420BC: 9de3bf90                 save    %sp, -0x70, %sp
F00420C0: 90103fff                 mov     -1, %o0
F00420C4: d027bff0                 st      %o0, [%fp+var_10]
F00420C8: 90100018                 mov     %i0, %o0! XDR *
F00420CC: 40000d9f                 call    _xdr_enum
F00420D0: 92066004                 add     %i1, 4, %o1! int *
F00420D4: 80a22000                 cmp     %o0, 0
F00420D8: 2280004a                 be,a    locret_F0042200
F00420DC: b0102000                 mov     0, %i0
F00420E0: d0066004                 ld      [%i1+4], %o0
F00420E4: 80a22000                 cmp     %o0, 0
F00420E8: 02800004                 be      loc_F00420F8
F00420EC: 1100003f                 sethi   0xFC00, %o0
F00420F0: 10800044                 ba      locret_F0042200
F00420F4: b0102001                 mov     1, %i0
F00420F8: e206600c                 ld      [%i1+0xC], %l1
F00420FC: a41223fc                 or      %o0, 0x3FC, %l2
F0042100: e0066014                 ld      [%i1+0x14], %l0
F0042104: 90100018                 mov     %i0, %o0! XDR *
F0042108: 40000d67                 call    _xdr_bool
F004210C: 9207bff4                 add     %fp, var_C, %o1! unsigned __int32 *
F0042110: 80a22000                 cmp     %o0, 0
F0042114: 0280003a                 be      loc_F00421FC
F0042118: d007bff4                 ld      [%fp+var_C], %o0
F004211C: 80a22000                 cmp     %o0, 0
F0042120: 0280002b                 be      loc_F00421CC
F0042124: 80a46005                 cmp     %l1, 5
F0042128: 04800035                 ble     loc_F00421FC
F004212C: 90100018                 mov     %i0, %o0! XDR *
F0042130: 40000cef                 call    _xdr_u_long
F0042134: 92100010                 mov     %l0, %o1! unsigned __int16 *
F0042138: 80a22000                 cmp     %o0, 0
F004213C: 02800030                 be      loc_F00421FC
F0042140: 90100018                 mov     %i0, %o0! XDR *
F0042144: 40000d24                 call    _xdr_u_short
F0042148: 92042006                 add     %l0, 6, %o1! char *
F004214C: 80a22000                 cmp     %o0, 0
F0042150: 2280002c                 be,a    locret_F0042200
F0042154: b0102000                 mov     0, %i0
F0042158: d4142006                 lduh    [%l0+6], %o2! unsigned int
F004215C: 9002a00c                 add     %o2, 0xC, %o0
F0042160: 900a3ffc                 and     %o0, -4, %o0
F0042164: 80a20011                 cmp     %o0, %l1
F0042168: 18800025                 bgu     loc_F00421FC
F004216C: 90100018                 mov     %i0, %o0! XDR *
F0042170: 40000d7c                 call    _xdr_opaque
F0042174: 92042008                 add     %l0, 8, %o1! unsigned __int32 *
F0042178: 80a22000                 cmp     %o0, 0
F004217C: 02800020                 be      loc_F00421FC
F0042180: 90100018                 mov     %i0, %o0! XDR *
F0042184: 40000cda                 call    _xdr_u_long
F0042188: 9207bff0                 add     %fp, var_10, %o1
F004218C: 80a22000                 cmp     %o0, 0
F0042190: 2280001c                 be,a    locret_F0042200
F0042194: b0102000                 mov     0, %i0
F0042198: d0142006                 lduh    [%l0+6], %o0
F004219C: d2142006                 lduh    [%l0+6], %o1
F00421A0: 9002200c                 inc     0xC, %o0
F00421A4: 900a0012                 and     %o0, %l2, %o0
F00421A8: d0342004                 sth     %o0, [%l0+4]
F00421AC: 92040009                 add     %l0, %o1, %o1! int *
F00421B0: c02a6008                 clrb    [%o1+8]
F00421B4: d0142004                 lduh    [%l0+4], %o0
F00421B8: a2a44008                 subcc   %l1, %o0, %l1
F00421BC: 0c800010                 bneg    loc_F00421FC
F00421C0: a0040008                 add     %l0, %o0, %l0
F00421C4: 10bfffd1                 ba      loc_F0042108
F00421C8: 90100018                 mov     %i0, %o0
F00421CC: 90100018                 mov     %i0, %o0! XDR *
F00421D0: 40000d35                 call    _xdr_bool
F00421D4: 92066010                 add     %i1, 0x10, %o1
F00421D8: 80a22000                 cmp     %o0, 0
F00421DC: 02800008                 be      loc_F00421FC
F00421E0: b0102001                 mov     1, %i0
F00421E4: d0066014                 ld      [%i1+0x14], %o0
F00421E8: d207bff0                 ld      [%fp+var_10], %o1
F00421EC: 90240008                 sub     %l0, %o0, %o0
F00421F0: d026600c                 st      %o0, [%i1+0xC]
F00421F4: 10800003                 ba      locret_F0042200
F00421F8: d2266008                 st      %o1, [%i1+8]
F00421FC: b0102000                 mov     0, %i0
F0042200: 81c7e008                 ret
F0042204: 81e80000                 restore
