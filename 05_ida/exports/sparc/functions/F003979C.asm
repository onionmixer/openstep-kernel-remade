F003979C: 9de3bf90                 save    %sp, -0x70, %sp
F00397A0: e0062030                 ld      [%i0+0x30], %l0
F00397A4: 7fff65fa                 call    _getthetime
F00397A8: 9007bff0                 add     %fp, var_10, %o0
F00397AC: d007bff0                 ld      [%fp+var_10], %o0
F00397B0: d02420c0                 st      %o0, [%l0+0xC0]
F00397B4: d007bff4                 ld      [%fp+var_C], %o0
F00397B8: d20420a8                 ld      [%l0+0xA8], %o1
F00397BC: d02420c4                 st      %o0, [%l0+0xC4]
F00397C0: d007bff0                 ld      [%fp+var_10], %o0
F00397C4: 90220009                 sub     %o0, %o1, %o0
F00397C8: d2062028                 ld      [%i0+0x28], %o1
F00397CC: 80a26002                 cmp     %o1, 2
F00397D0: 1280000a                 bne     loc_F00397F8
F00397D4: 953a2004                 sra     %o0, 4, %o2
F00397D8: d0062024                 ld      [%i0+0x24], %o0
F00397DC: d2022128                 ld      [%o0+0x128], %o1
F00397E0: d0026068                 ld      [%o1+0x68], %o0
F00397E4: 80a28008                 cmp     %o2, %o0
F00397E8: 2a80000f                 bcs,a   loc_F0039824
F00397EC: 94100008                 mov     %o0, %o2
F00397F0: 10800009                 ba      loc_F0039814
F00397F4: d002606c                 ld      [%o1+0x6C], %o0
F00397F8: d0062024                 ld      [%i0+0x24], %o0
F00397FC: d2022128                 ld      [%o0+0x128], %o1
F0039800: d0026060                 ld      [%o1+0x60], %o0
F0039804: 80a28008                 cmp     %o2, %o0
F0039808: 2a800007                 bcs,a   loc_F0039824
F003980C: 94100008                 mov     %o0, %o2
F0039810: d0026064                 ld      [%o1+0x64], %o0
F0039814: 80a28008                 cmp     %o2, %o0
F0039818: 28800004                 bleu,a  loc_F0039828
F003981C: d00420c0                 ld      [%l0+0xC0], %o0
F0039820: 94100008                 mov     %o0, %o2
F0039824: d00420c0                 ld      [%l0+0xC0], %o0
F0039828: 9002000a                 add     %o0, %o2, %o0
F003982C: d02420c0                 st      %o0, [%l0+0xC0]
F0039830: 81c7e008                 ret
F0039834: 81e80000                 restore
