F0053E78: 9de3bf60                 save    %sp, -0xA0, %sp
F0053E7C: e4062018                 ld      [%i0+0x18], %l2
F0053E80: a1366008                 srl     %i1, 8, %l0
F0053E84: 80a40012                 cmp     %l0, %l2
F0053E88: 1a800053                 bcc     loc_F0053FD4
F0053E8C: e2062014                 ld      [%i0+0x14], %l1
F0053E90: a72c2004                 sll     %l0, 4, %l3
F0053E94: 90044013                 add     %l1, %l3, %o0
F0053E98: 80a68008                 cmp     %i2, %o0
F0053E9C: 3280004f                 bne,a   loc_F0053FD8
F0053EA0: 90062020                 add     %i0, 0x20, %o0 ! ' '
F0053EA4: d2044013                 ld      [%l1+%l3], %o1
F0053EA8: 37002000                 sethi   0x800000, %i3
F0053EAC: 808a401b                 btst    %i3, %o1
F0053EB0: 02800042                 be      loc_F0053FB8
F0053EB4: a8062020                 add     %i0, 0x20, %l4 ! ' '
F0053EB8: 90100014                 mov     %l4, %o0
F0053EBC: 92042001                 add     %l0, 1, %o1
F0053EC0: 932a6008                 sll     %o1, 8, %o1
F0053EC4: a407bfc8                 add     %fp, var_38, %l2
F0053EC8: 400029be                 call    _ipc_splay_tree_split
F0053ECC: 94100012                 mov     %l2, %o2
F0053ED0: 90100012                 mov     %l2, %o0
F0053ED4: 932c2008                 sll     %l0, 8, %o1
F0053ED8: ae07bfe0                 add     %fp, var_20, %l7
F0053EDC: 400029b9                 call    _ipc_splay_tree_split
F0053EE0: 94100017                 mov     %l7, %o2
F0053EE4: 90100012                 mov     %l2, %o0
F0053EE8: aa07bfc4                 add     %fp, var_3C, %l5
F0053EEC: 92100015                 mov     %l5, %o1
F0053EF0: ac07bfc0                 add     %fp, var_40, %l6
F0053EF4: 40002904                 call    _ipc_splay_tree_pick
F0053EF8: 94100016                 mov     %l6, %o2
F0053EFC: d607bfc0                 ld      [%fp+var_40], %o3
F0053F00: d807bfc4                 ld      [%fp+var_3C], %o4
F0053F04: d202c000                 ld      [%o3], %o1
F0053F08: 912b2018                 sll     %o4, 24, %o0
F0053F0C: 90124008                 bset    %o1, %o0
F0053F10: d0244013                 st      %o0, [%l1+%l3]
F0053F14: 110007c0                 sethi   0x1F0000, %o0
F0053F18: 920a4008                 and     %o1, %o0, %o1
F0053F1C: f202e004                 ld      [%o3+4], %i1
F0053F20: 11000040                 sethi   0x10000, %o0
F0053F24: f226a004                 st      %i1, [%i2+4]
F0053F28: d402e008                 ld      [%o3+8], %o2
F0053F2C: 80a24008                 cmp     %o1, %o0
F0053F30: 1280000b                 bne     loc_F0053F5C
F0053F34: d426a008                 st      %o2, [%i2+8]
F0053F38: 90100018                 mov     %i0, %o0
F0053F3C: 92100019                 mov     %i1, %o1
F0053F40: 40000209                 call    _ipc_hash_global_delete
F0053F44: 9410000c                 mov     %o4, %o2
F0053F48: 90100018                 mov     %i0, %o0
F0053F4C: 92100019                 mov     %i1, %o1
F0053F50: 94100010                 mov     %l0, %o2
F0053F54: 40000255                 call    _ipc_hash_local_insert
F0053F58: 9610001a                 mov     %i2, %o3
F0053F5C: d207bfc4                 ld      [%fp+var_3C], %o1
F0053F60: d407bfc0                 ld      [%fp+var_40], %o2
F0053F64: 4000294d                 call    _ipc_splay_tree_delete
F0053F68: 90100012                 mov     %l2, %o0
F0053F6C: 90100012                 mov     %l2, %o0
F0053F70: 92100015                 mov     %l5, %o1
F0053F74: d6062038                 ld      [%i0+0x38], %o3
F0053F78: 94100016                 mov     %l6, %o2
F0053F7C: 9602ffff                 inc     -1, %o3
F0053F80: 400028e1                 call    _ipc_splay_tree_pick
F0053F84: d6262038                 st      %o3, [%i0+0x38]
F0053F88: 80a22000                 cmp     %o0, 0
F0053F8C: 02800007                 be      loc_F0053FA8
F0053F90: 90100014                 mov     %l4, %o0
F0053F94: d4044013                 ld      [%l1+%l3], %o2
F0053F98: 92100012                 mov     %l2, %o1
F0053F9C: 9412801b                 bset    %i3, %o2
F0053FA0: 400029d7                 call    _ipc_splay_tree_join
F0053FA4: d4244013                 st      %o2, [%l1+%l3]
F0053FA8: 90100014                 mov     %l4, %o0
F0053FAC: 400029d4                 call    _ipc_splay_tree_join
F0053FB0: 92100017                 mov     %l7, %o1
F0053FB4: 30800029                 ba,a    locret_F0054058
F0053FB8: 113fc000                 sethi   -0x1000000, %o0
F0053FBC: 900a4008                 and     %o1, %o0, %o0
F0053FC0: d0244013                 st      %o0, [%l1+%l3]
F0053FC4: d0046008                 ld      [%l1+8], %o0
F0053FC8: d026a008                 st      %o0, [%i2+8]
F0053FCC: 10800023                 ba      locret_F0054058
F0053FD0: e0246008                 st      %l0, [%l1+8]
F0053FD4: 90062020                 add     %i0, 0x20, %o0 ! ' '
F0053FD8: 92100019                 mov     %i1, %o1
F0053FDC: 4000292f                 call    _ipc_splay_tree_delete
F0053FE0: 9410001a                 mov     %i2, %o2
F0053FE4: d0062038                 ld      [%i0+0x38], %o0
F0053FE8: 80a40012                 cmp     %l0, %l2
F0053FEC: 90023fff                 inc     -1, %o0
F0053FF0: 1a80000d                 bcc     loc_F0054024
F0053FF4: d0262038                 st      %o0, [%i0+0x38]
F0053FF8: 90100018                 mov     %i0, %o0
F0053FFC: 7ffffe78                 call    _ipc_entry_tree_collision
F0054000: 92100019                 mov     %i1, %o1
F0054004: 80a22000                 cmp     %o0, 0
F0054008: 12800014                 bne     locret_F0054058
F005400C: b12c2004                 sll     %l0, 4, %i0
F0054010: d2044018                 ld      [%l1+%i0], %o1
F0054014: 11002000                 sethi   0x800000, %o0
F0054018: 902a4008                 andn    %o1, %o0, %o0
F005401C: 1080000f                 ba      locret_F0054058
F0054020: d0244018                 st      %o0, [%l1+%i0]
F0054024: d006201c                 ld      [%i0+0x1C], %o0
F0054028: d0020000                 ld      [%o0], %o0
F005402C: 80a40008                 cmp     %l0, %o0
F0054030: 1a80000a                 bcc     locret_F0054058
F0054034: 90100018                 mov     %i0, %o0
F0054038: 7ffffe69                 call    _ipc_entry_tree_collision
F005403C: 92100019                 mov     %i1, %o1
F0054040: 80a22000                 cmp     %o0, 0
F0054044: 12800005                 bne     locret_F0054058
F0054048: 01000000                 nop
F005404C: d006203c                 ld      [%i0+0x3C], %o0
F0054050: 90023fff                 inc     -1, %o0
F0054054: d026203c                 st      %o0, [%i0+0x3C]
F0054058: 81c7e008                 ret
F005405C: 81e80000                 restore
