F00B1784: 9de3bf98                 save    %sp, -0x68, %sp
F00B1788: 80a62000                 cmp     %i0, 0
F00B178C: 22800013                 be,a    locret_F00B17D8
F00B1790: b0102000                 mov     0, %i0
F00B1794: 213c0471                 sethi   -0xFEE3C00, %l0
F00B1798: d006200c                 ld      [%i0+0xC], %o0! __s1
F00B179C: 7ffd5a84                 call    _strcmp
F00B17A0: 92100019                 mov     %i1, %o1
F00B17A4: 80a22000                 cmp     %o0, 0
F00B17A8: 32800008                 bne,a   loc_F00B17C8
F00B17AC: f0062004                 ld      [%i0+4], %i0
F00B17B0: d20423a8                 ld      [%l0+0x3A8], %o1
F00B17B4: 90026001                 add     %o1, 1, %o0
F00B17B8: 80a2401a                 cmp     %o1, %i2
F00B17BC: 02800007                 be      locret_F00B17D8
F00B17C0: d02423a8                 st      %o0, [%l0+0x3A8]
F00B17C4: f0062004                 ld      [%i0+4], %i0
F00B17C8: 80a62000                 cmp     %i0, 0
F00B17CC: 32bffff4                 bne,a   loc_F00B179C
F00B17D0: d006200c                 ld      [%i0+0xC], %o0
F00B17D4: b0102000                 mov     0, %i0
F00B17D8: 81c7e008                 ret
F00B17DC: 81e80000                 restore
