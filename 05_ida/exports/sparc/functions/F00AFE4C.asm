F00AFE4C: 9de3bf98                 save    %sp, -0x68, %sp
F00AFE50: 7ffffcf4                 call    _prom_stdinpath
F00AFE54: 01000000                 nop
F00AFE58: 80a22000                 cmp     %o0, 0
F00AFE5C: 2280000f                 be,a    loc_F00AFE98
F00AFE60: 113c0470                 sethi   -0xFEE4000, %o0
F00AFE64: 40000c23                 call    _path_to_devi
F00AFE68: 01000000                 nop
F00AFE6C: 92920000                 orcc    %o0, %g0, %o1
F00AFE70: 02800009                 be      loc_F00AFE94
F00AFE74: 80a66002                 cmp     %i1, 2
F00AFE78: 04800020                 ble     loc_F00AFEF8
F00AFE7C: 90060019                 add     %i0, %i1, %o0
F00AFE80: c02a3fff                 clrb    [%o0-1]
F00AFE84: 90100018                 mov     %i0, %o0
F00AFE88: d202600c                 ld      [%o1+0xC], %o1
F00AFE8C: 10800018                 ba      loc_F00AFEEC
F00AFE90: 94067fff                 add     %i1, -1, %o2
F00AFE94: 113c0470                 sethi   -0xFEE4000, %o0
F00AFE98: d0022278                 ld      [%o0+0x278], %o0
F00AFE9C: 80a22000                 cmp     %o0, 0
F00AFEA0: 02800004                 be      loc_F00AFEB0
F00AFEA4: 80a22002                 cmp     %o0, 2
F00AFEA8: 32800015                 bne,a   locret_F00AFEFC
F00AFEAC: b0103fff                 mov     -1, %i0
F00AFEB0: 113c000c                 sethi   %hi(_romp), %o0
F00AFEB4: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AFEB8: d0022048                 ld      [%o0+0x48], %o0
F00AFEBC: d00a0000                 ldub    [%o0], %o0
F00AFEC0: 80a22004                 cmp     %o0, 4
F00AFEC4: 3480000e                 bg,a    locret_F00AFEFC
F00AFEC8: b0103fff                 mov     -1, %i0
F00AFECC: 80a22000                 cmp     %o0, 0
F00AFED0: 0680000a                 bl      loc_F00AFEF8
F00AFED4: 80a66002                 cmp     %i1, 2
F00AFED8: 04800008                 ble     loc_F00AFEF8
F00AFEDC: 90100018                 mov     %i0, %o0! __dst
F00AFEE0: 133c047092126350         set     aZs, %o1! "zs"
F00AFEE8: 94100019                 mov     %i1, %o2! __n
F00AFEEC: 7ffd5e8c                 call    _strncpy
F00AFEF0: b0102000                 mov     0, %i0
F00AFEF4: 30800002                 ba,a    locret_F00AFEFC
F00AFEF8: b0103fff                 mov     -1, %i0
F00AFEFC: 81c7e008                 ret
F00AFF00: 81e80000                 restore
