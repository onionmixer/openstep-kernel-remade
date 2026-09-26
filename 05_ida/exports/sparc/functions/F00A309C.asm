F00A309C: 9de3bf98                 save    %sp, -0x68, %sp
F00A30A0: 073c04f78610e270         set     _pmap_info, %g3
F00A30A8: c400e0fc                 ld      [%g3+0xFC], %g2
F00A30AC: 8400a001                 inc     %g2
F00A30B0: c420e0fc                 st      %g2, [%g3+0xFC]
F00A30B4: f2062014                 ld      [%i0+0x14], %i1
F00A30B8: 80a66000                 cmp     %i1, 0
F00A30BC: 0280000e                 be      loc_F00A30F4
F00A30C0: 053c04f8                 sethi   -0xFEC2000, %g2
F00A30C4: c4066008                 ld      [%i1+8], %g2
F00A30C8: 80a08018                 cmp     %g2, %i0
F00A30CC: 3280000a                 bne,a   loc_F00A30F4
F00A30D0: 053c04f8                 sethi   -0xFEC2000, %g2
F00A30D4: c6064000                 ld      [%i1], %g3
F00A30D8: c4066004                 ld      [%i1+4], %g2
F00A30DC: c420e004                 st      %g2, [%g3+4]
F00A30E0: c6066004                 ld      [%i1+4], %g3
F00A30E4: c4064000                 ld      [%i1], %g2
F00A30E8: c420c000                 st      %g2, [%g3]
F00A30EC: 1080000f                 ba      loc_F00A3128
F00A30F0: 053c04f8                 sethi   -0xFEC2000, %g2
F00A30F4: f200a10c                 ld      [%g2+0x10C], %i1
F00A30F8: 8410a10c                 bset    0x10C, %g2
F00A30FC: f4066004                 ld      [%i1+4], %i2
F00A3100: 8600bffc                 add     %g2, -4, %g3
F00A3104: 80a68003                 cmp     %i2, %g3
F00A3108: 32800003                 bne,a   loc_F00A3114
F00A310C: c6268000                 st      %g3, [%i2]
F00A3110: f420bffc                 st      %i2, [%g2-4]
F00A3114: 053c04f88610a108         set     _lru_context, %g3
F00A311C: f420e004                 st      %i2, [%g3+4]
F00A3120: f2262014                 st      %i1, [%i0+0x14]
F00A3124: f0266008                 st      %i0, [%i1+8]
F00A3128: c400a108                 ld      [%g2+0x108], %g2
F00A312C: f220a004                 st      %i1, [%g2+4]
F00A3130: c4264000                 st      %g2, [%i1]
F00A3134: 073c04f88410e108         set     _lru_context, %g2
F00A313C: c4266004                 st      %g2, [%i1+4]
F00A3140: f220e108                 st      %i1, [%g3+0x108]
F00A3144: 053c04f7                 sethi   %hi(_context_table), %g2
F00A3148: c400a210                 ld      [%g2+%lo(_context_table)], %g2
F00A314C: 84264002                 sub     %i1, %g2, %g2
F00A3150: b128a002                 sll     %g2, 2, %i0
F00A3154: b0060002                 add     %i0, %g2, %i0
F00A3158: 852e2004                 sll     %i0, 4, %g2
F00A315C: b0060002                 add     %i0, %g2, %i0
F00A3160: 852e2008                 sll     %i0, 8, %g2
F00A3164: b0060002                 add     %i0, %g2, %i0
F00A3168: 852e2010                 sll     %i0, 16, %g2
F00A316C: b0060002                 add     %i0, %g2, %i0
F00A3170: b0200018                 neg     %i0
F00A3174: b13e2002                 sra     %i0, 2, %i0
F00A3178: 81c7e008                 ret
F00A317C: 81e80000                 restore
