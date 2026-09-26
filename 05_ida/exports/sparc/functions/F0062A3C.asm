F0062A3C: 9de3bf90                 save    %sp, -0x70, %sp
F0062A40: 80a62000                 cmp     %i0, 0
F0062A44: 12800004                 bne     loc_F0062A54
F0062A48: 92100019                 mov     %i1, %o1
F0062A4C: 10800027                 ba      locret_F0062AE8
F0062A50: b0102010                 mov     0x10, %i0
F0062A54: 90100018                 mov     %i0, %o0
F0062A58: 7fffe409                 call    _ipc_right_lookup_write
F0062A5C: 9407bff4                 add     %fp, var_C, %o2
F0062A60: 80a22000                 cmp     %o0, 0
F0062A64: 32800021                 bne,a   locret_F0062AE8
F0062A68: b0100008                 mov     %o0, %i0
F0062A6C: d407bff4                 ld      [%fp+var_C], %o2
F0062A70: d2028000                 ld      [%o2], %o1
F0062A74: 11000080                 sethi   0x20000, %o0
F0062A78: 808a4008                 btst    %o0, %o1
F0062A7C: 02800014                 be      loc_F0062ACC
F0062A80: 80a6a000                 cmp     %i2, 0
F0062A84: 12800004                 bne     loc_F0062A94
F0062A88: f202a004                 ld      [%o2+4], %i1
F0062A8C: 10800013                 ba      loc_F0062AD8
F0062A90: 94102000                 mov     0, %o2
F0062A94: 90100018                 mov     %i0, %o0
F0062A98: 7fffc3e9                 call    _ipc_entry_lookup
F0062A9C: 9210001a                 mov     %i2, %o1
F0062AA0: 94920000                 orcc    %o0, %g0, %o2
F0062AA4: 12800005                 bne     loc_F0062AB8
F0062AA8: d427bff4                 st      %o2, [%fp+var_C]
F0062AAC: c0262008                 clr     [%i0+8]
F0062AB0: 1080000e                 ba      locret_F0062AE8
F0062AB4: b010200f                 mov     0xF, %i0
F0062AB8: d2028000                 ld      [%o2], %o1
F0062ABC: 11000200                 sethi   0x80000, %o0
F0062AC0: 808a4008                 btst    %o0, %o1
F0062AC4: 32800005                 bne,a   loc_F0062AD8
F0062AC8: d402a004                 ld      [%o2+4], %o2
F0062ACC: c0262008                 clr     [%i0+8]
F0062AD0: 10800006                 ba      locret_F0062AE8
F0062AD4: b0102011                 mov     0x11, %i0
F0062AD8: 90100018                 mov     %i0, %o0
F0062ADC: 7fffe33a                 call    _ipc_pset_move
F0062AE0: 92100019                 mov     %i1, %o1
F0062AE4: b0100008                 mov     %o0, %i0
F0062AE8: 81c7e008                 ret
F0062AEC: 81e80000                 restore
