F00899A8: 9de3bf98                 save    %sp, -0x68, %sp
F00899AC: a2100018                 mov     %i0, %l1
F00899B0: b0102000                 mov     0, %i0
F00899B4: 7fff7dd0                 call    _lock_read
F00899B8: 90100011                 mov     %l1, %o0
F00899BC: e0046010                 ld      [%l1+0x10], %l0
F00899C0: 9004600c                 add     %l1, 0xC, %o0
F00899C4: 80a40008                 cmp     %l0, %o0
F00899C8: 0280002e                 be      loc_F0089A80
F00899CC: 01000000                 nop
F00899D0: 27280000                 sethi   -0x60000000, %l3
F00899D4: a4100008                 mov     %o0, %l2
F00899D8: d0042018                 ld      [%l0+0x18], %o0
F00899DC: 808a0013                 btst    %l3, %o0
F00899E0: 0280000a                 be      loc_F0089A08
F00899E4: 92100019                 mov     %i1, %o1
F00899E8: d0042010                 ld      [%l0+0x10], %o0
F00899EC: 7fffffef                 call    sub_F00899A8
F00899F0: 9410001a                 mov     %i2, %o2
F00899F4: 80a22005                 cmp     %o0, 5
F00899F8: 3280001f                 bne,a   loc_F0089A74
F00899FC: e0042004                 ld      [%l0+4], %l0
F0089A00: 1080001c                 ba      loc_F0089A70
F0089A04: b0102005                 mov     5, %i0
F0089A08: d4042008                 ld      [%l0+8], %o2
F0089A0C: 80a2801a                 cmp     %o2, %i2
F0089A10: 38800019                 bgu,a   loc_F0089A74
F0089A14: e0042004                 ld      [%l0+4], %l0
F0089A18: d204200c                 ld      [%l0+0xC], %o1
F0089A1C: 80a24019                 cmp     %o1, %i1
F0089A20: 28800015                 bleu,a  loc_F0089A74
F0089A24: e0042004                 ld      [%l0+4], %l0
F0089A28: 80a28019                 cmp     %o2, %i1
F0089A2C: 08800003                 bleu    loc_F0089A38
F0089A30: d0042010                 ld      [%l0+0x10], %o0
F0089A34: b210000a                 mov     %o2, %i1
F0089A38: 80a2401a                 cmp     %o1, %i2
F0089A3C: 18800003                 bgu     loc_F0089A48
F0089A40: 9610001a                 mov     %i2, %o3
F0089A44: 96100009                 mov     %o1, %o3
F0089A48: d2042014                 ld      [%l0+0x14], %o1
F0089A4C: 92024019                 add     %o1, %i1, %o1
F0089A50: 9222400a                 sub     %o1, %o2, %o1
F0089A54: 9402400b                 add     %o1, %o3, %o2
F0089A58: 40000092                 call    sub_F0089CA0
F0089A5C: 94228019                 sub     %o2, %i1, %o2
F0089A60: 80a22000                 cmp     %o0, 0
F0089A64: 22800004                 be,a    loc_F0089A74
F0089A68: e0042004                 ld      [%l0+4], %l0
F0089A6C: b0102005                 mov     5, %i0
F0089A70: e0042004                 ld      [%l0+4], %l0
F0089A74: 80a40012                 cmp     %l0, %l2
F0089A78: 32bfffd9                 bne,a   loc_F00899DC
F0089A7C: d0042018                 ld      [%l0+0x18], %o0
F0089A80: 7fff7d6d                 call    _lock_done
F0089A84: 90100011                 mov     %l1, %o0
F0089A88: 81c7e008                 ret
F0089A8C: 81e80000                 restore
