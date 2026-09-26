F003DD3C: 9de3bf58                 save    %sp, -0xA8, %sp
F003DD40: e607a064                 ld      [%fp+arg_64], %l3
F003DD44: 90100018                 mov     %i0, %o0
F003DD48: e407a05c                 ld      [%fp+arg_5C], %l2
F003DD4C: 9210206f                 mov     0x6F, %o1 ! 'o'
F003DD50: f007a060                 ld      [%fp+arg_60], %i0
F003DD54: d2322002                 sth     %o1, [%o0+2]
F003DD58: 133c04cf                 sethi   %hi(_active_u), %o1
F003DD5C: d20261d8                 ld      [%o1+%lo(_active_u)], %o1
F003DD60: 94102002                 mov     2, %o2
F003DD64: d802601c                 ld      [%o1+0x1C], %o4
F003DD68: 96102005                 mov     5, %o3
F003DD6C: e207a068                 ld      [%fp+arg_68], %l1
F003DD70: 13000061                 sethi   0x18400, %o1
F003DD74: 4000131b                 call    _clntkudp_create
F003DD78: 921262a0                 bset    0x2A0, %o1
F003DD7C: a0920000                 orcc    %o0, %g0, %l0
F003DD80: 32800006                 bne,a   loc_F003DD98
F003DD84: f227bfe0                 st      %i1, [%fp+var_20]
F003DD88: 113c0434                 sethi   %hi(aPmapRmtcallCln), %o0! "pmap_rmtcall: clntkudp_create failed"
F003DD8C: 7fff5cf9                 call    _panic
F003DD90: 901222a0                 bset    %lo(aPmapRmtcallCln), %o0! "pmap_rmtcall: clntkudp_create failed"
F003DD94: f227bfe0                 st      %i1, [%fp+var_20]
F003DD98: f427bfe4                 st      %i2, [%fp+var_1C]
F003DD9C: f627bfe8                 st      %i3, [%fp+var_18]
F003DDA0: fa27bff0                 st      %i5, [%fp+var_10]
F003DDA4: f827bff4                 st      %i4, [%fp+var_C]
F003DDA8: 9007bfcc                 add     %fp, var_34, %o0
F003DDAC: d027bfd0                 st      %o0, [%fp+var_30]
F003DDB0: f027bfd8                 st      %i0, [%fp+var_28]
F003DDB4: e427bfdc                 st      %l2, [%fp+var_24]
F003DDB8: 90100010                 mov     %l0, %o0
F003DDBC: 92102005                 mov     5, %o1
F003DDC0: 153c010e9412a07c         set     _xdr_rmtcall_args, %o2
F003DDC8: d804c000                 ld      [%l3], %o4
F003DDCC: 9607bfe0                 add     %fp, var_20, %o3
F003DDD0: d827bfc0                 st      %o4, [%fp+var_40]
F003DDD4: 193c010e                 sethi   %hi(_xdr_rmtcallres), %o4
F003DDD8: da04e004                 ld      [%l3+4], %o5
F003DDDC: 9813218c                 bset    %lo(_xdr_rmtcallres), %o4
F003DDE0: da27bfc4                 st      %o5, [%fp+var_3C]
F003DDE4: 9a07bfc0                 add     %fp, var_40, %o5
F003DDE8: da23a05c                 st      %o5, [%sp+0xA8+var_4C]
F003DDEC: e223a060                 st      %l1, [%sp+0xA8+var_48]
F003DDF0: 40001387                 call    _clntkudp_callit_addr
F003DDF4: 9a07bfd0                 add     %fp, var_30, %o5
F003DDF8: 80a46000                 cmp     %l1, 0
F003DDFC: 02800004                 be      loc_F003DE0C
F003DE00: b0100008                 mov     %o0, %i0
F003DE04: d007bfcc                 ld      [%fp+var_34], %o0
F003DE08: d0346002                 sth     %o0, [%l1+2]
F003DE0C: d0042004                 ld      [%l0+4], %o0
F003DE10: d2022010                 ld      [%o0+0x10], %o1
F003DE14: 9fc24000                 call    %o1
F003DE18: 90100010                 mov     %l0, %o0
F003DE1C: 81c7e008                 ret
F003DE20: 81e80000                 restore
