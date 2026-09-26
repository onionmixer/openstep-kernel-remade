F0053A3C: 9de3bf98                 save    %sp, -0x68, %sp
F0053A40: 96100018                 mov     %i0, %o3
F0053A44: d002e018                 ld      [%o3+0x18], %o0
F0053A48: 95366008                 srl     %i1, 8, %o2
F0053A4C: 80a28008                 cmp     %o2, %o0
F0053A50: 1a800013                 bcc     loc_F0053A9C
F0053A54: 912aa004                 sll     %o2, 4, %o0
F0053A58: d202e014                 ld      [%o3+0x14], %o1
F0053A5C: d4024008                 ld      [%o1+%o0], %o2
F0053A60: b0024008                 add     %o1, %o0, %i0
F0053A64: 113fc000                 sethi   -0x1000000, %o0
F0053A68: 900a8008                 and     %o2, %o0, %o0
F0053A6C: 932e6018                 sll     %i1, 24, %o1
F0053A70: 80a20009                 cmp     %o0, %o1
F0053A74: 02800004                 be      loc_F0053A84
F0053A78: 11002000                 sethi   0x800000, %o0
F0053A7C: 1080000a                 ba      loc_F0053AA4
F0053A80: 808a8008                 btst    %o0, %o2
F0053A84: 110007c0                 sethi   0x1F0000, %o0
F0053A88: 808a8008                 btst    %o0, %o2
F0053A8C: 1280000b                 bne     locret_F0053AB8
F0053A90: 01000000                 nop
F0053A94: 10800009                 ba      locret_F0053AB8
F0053A98: b0102000                 mov     0, %i0
F0053A9C: d002e038                 ld      [%o3+0x38], %o0
F0053AA0: 80a22000                 cmp     %o0, 0
F0053AA4: 02bffffc                 be      loc_F0053A94
F0053AA8: 9002e020                 add     %o3, 0x20, %o0 ! ' '
F0053AAC: 40002a21                 call    _ipc_splay_tree_lookup
F0053AB0: 92100019                 mov     %i1, %o1
F0053AB4: b0100008                 mov     %o0, %i0
F0053AB8: 81c7e008                 ret
F0053ABC: 81e80000                 restore
