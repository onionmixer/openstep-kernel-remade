F005E93C: 9de3bf78                 save    %sp, -0x88, %sp
F005E940: a4100018                 mov     %i0, %l2
F005E944: f004a008                 ld      [%l2+8], %i0
F005E948: 80a66000                 cmp     %i1, 0
F005E94C: f204a010                 ld      [%l2+0x10], %i1
F005E950: 0280005a                 be      loc_F005EAB8
F005E954: f027bff4                 st      %i0, [%fp+var_C]
F005E958: d2062018                 ld      [%i0+0x18], %o1
F005E95C: 80a26000                 cmp     %o1, 0
F005E960: 12800029                 bne     loc_F005EA04
F005E964: d006201c                 ld      [%i0+0x1C], %o0
F005E968: 80a22000                 cmp     %o0, 0
F005E96C: 32800020                 bne,a   loc_F005E9EC
F005E970: d027bff4                 st      %o0, [%fp+var_C]
F005E974: 80a66000                 cmp     %i1, 0
F005E978: 32800009                 bne,a   loc_F005E99C
F005E97C: d2062010                 ld      [%i0+0x10], %o1
F005E980: 113c04ef                 sethi   %hi(_ipc_tree_entry_zone), %o0
F005E984: d00222d8                 ld      [%o0+%lo(_ipc_tree_entry_zone)], %o0
F005E988: 40006a12                 call    _zfree
F005E98C: 92100018                 mov     %i0, %o1
F005E990: c024a004                 clr     [%l2+4]
F005E994: 10800066                 ba      locret_F005EB2C
F005E998: b0102000                 mov     0, %i0
F005E99C: d0066010                 ld      [%i1+0x10], %o0
F005E9A0: 80a24008                 cmp     %o1, %o0
F005E9A4: 1a80000a                 bcc     loc_F005E9CC
F005E9A8: 113c04ef                 sethi   %hi(_ipc_tree_entry_zone), %o0
F005E9AC: d00222d8                 ld      [%o0+%lo(_ipc_tree_entry_zone)], %o0
F005E9B0: 40006a08                 call    _zfree
F005E9B4: 92100018                 mov     %i0, %o1
F005E9B8: f227bff4                 st      %i1, [%fp+var_C]
F005E9BC: 90100019                 mov     %i1, %o0
F005E9C0: f2066018                 ld      [%i1+0x18], %i1
F005E9C4: 10800039                 ba      loc_F005EAA8
F005E9C8: c0222018                 clr     [%o0+0x18]
F005E9CC: d00222d8                 ld      [%o0+0x2D8], %o0
F005E9D0: 40006a00                 call    _zfree
F005E9D4: 92100018                 mov     %i0, %o1
F005E9D8: f227bff4                 st      %i1, [%fp+var_C]
F005E9DC: 90100019                 mov     %i1, %o0
F005E9E0: f206601c                 ld      [%i1+0x1C], %i1
F005E9E4: 1080003e                 ba      loc_F005EADC
F005E9E8: c022201c                 clr     [%o0+0x1C]
F005E9EC: 113c04ef                 sethi   %hi(_ipc_tree_entry_zone), %o0
F005E9F0: d00222d8                 ld      [%o0+%lo(_ipc_tree_entry_zone)], %o0
F005E9F4: 400069f7                 call    _zfree
F005E9F8: 92100018                 mov     %i0, %o1
F005E9FC: 10800025                 ba      loc_F005EA90
F005EA00: d007bff4                 ld      [%fp+var_C], %o0
F005EA04: 80a22000                 cmp     %o0, 0
F005EA08: 12800009                 bne     loc_F005EA2C
F005EA0C: 9007bfe4                 add     %fp, var_1C, %o0
F005EA10: d227bff4                 st      %o1, [%fp+var_C]
F005EA14: 113c04ef                 sethi   %hi(_ipc_tree_entry_zone), %o0
F005EA18: d00222d8                 ld      [%o0+%lo(_ipc_tree_entry_zone)], %o0
F005EA1C: 400069ed                 call    _zfree
F005EA20: 92100018                 mov     %i0, %o1
F005EA24: 1080002f                 ba      loc_F005EAE0
F005EA28: 80a66000                 cmp     %i1, 0
F005EA2C: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F005EA30: 90103fff                 mov     -1, %o0
F005EA34: 9407bff4                 add     %fp, var_C, %o2
F005EA38: a207bff0                 add     %fp, var_10, %l1
F005EA3C: 96100011                 mov     %l1, %o3
F005EA40: 9807bfec                 add     %fp, var_14, %o4
F005EA44: a007bfe8                 add     %fp, var_18, %l0
F005EA48: 7ffffdd7                 call    sub_F005E1A4
F005EA4C: 9a100010                 mov     %l0, %o5
F005EA50: d007bff4                 ld      [%fp+var_C], %o0
F005EA54: d407bfec                 ld      [%fp+var_14], %o2
F005EA58: 92100011                 mov     %l1, %o1
F005EA5C: d807bfe4                 ld      [%fp+var_1C], %o4
F005EA60: 7ffffe1a                 call    sub_F005E2C8
F005EA64: 96100010                 mov     %l0, %o3
F005EA68: d607bff4                 ld      [%fp+var_C], %o3
F005EA6C: 92100018                 mov     %i0, %o1
F005EA70: d402601c                 ld      [%o1+0x1C], %o2
F005EA74: 113c04ef                 sethi   %hi(_ipc_tree_entry_zone), %o0
F005EA78: d00222d8                 ld      [%o0+%lo(_ipc_tree_entry_zone)], %o0
F005EA7C: 400069d5                 call    _zfree
F005EA80: d422e01c                 st      %o2, [%o3+0x1C]
F005EA84: 1080000e                 ba      loc_F005EABC
F005EA88: d007bff4                 ld      [%fp+var_C], %o0
F005EA8C: d007bff4                 ld      [%fp+var_C], %o0
F005EA90: d2022018                 ld      [%o0+0x18], %o1
F005EA94: 80a26000                 cmp     %o1, 0
F005EA98: 02800005                 be      loc_F005EAAC
F005EA9C: f007bff4                 ld      [%fp+var_C], %i0
F005EAA0: 1080000c                 ba      loc_F005EAD0
F005EAA4: f2222018                 st      %i1, [%o0+0x18]
F005EAA8: f007bff4                 ld      [%fp+var_C], %i0
F005EAAC: f224a010                 st      %i1, [%l2+0x10]
F005EAB0: 1080001f                 ba      locret_F005EB2C
F005EAB4: f024a008                 st      %i0, [%l2+8]
F005EAB8: d007bff4                 ld      [%fp+var_C], %o0
F005EABC: d202201c                 ld      [%o0+0x1C], %o1
F005EAC0: 80a26000                 cmp     %o1, 0
F005EAC4: 02800007                 be      loc_F005EAE0
F005EAC8: 80a66000                 cmp     %i1, 0
F005EACC: f222201c                 st      %i1, [%o0+0x1C]
F005EAD0: b2100008                 mov     %o0, %i1
F005EAD4: 10bfffee                 ba      loc_F005EA8C
F005EAD8: d227bff4                 st      %o1, [%fp+var_C]
F005EADC: 80a66000                 cmp     %i1, 0
F005EAE0: 12800006                 bne     loc_F005EAF8
F005EAE4: d407bff4                 ld      [%fp+var_C], %o2
F005EAE8: d007bff4                 ld      [%fp+var_C], %o0
F005EAEC: b0102000                 mov     0, %i0
F005EAF0: 1080000f                 ba      locret_F005EB2C
F005EAF4: d024a004                 st      %o0, [%l2+4]
F005EAF8: d0066010                 ld      [%i1+0x10], %o0
F005EAFC: d202a010                 ld      [%o2+0x10], %o1
F005EB00: 80a24008                 cmp     %o1, %o0
F005EB04: 1a800006                 bcc     loc_F005EB1C
F005EB08: 90100019                 mov     %i1, %o0
F005EB0C: f227bff4                 st      %i1, [%fp+var_C]
F005EB10: f2066018                 ld      [%i1+0x18], %i1
F005EB14: 10bfffe5                 ba      loc_F005EAA8
F005EB18: d4222018                 st      %o2, [%o0+0x18]
F005EB1C: f227bff4                 st      %i1, [%fp+var_C]
F005EB20: f206601c                 ld      [%i1+0x1C], %i1
F005EB24: 10bfffee                 ba      loc_F005EADC
F005EB28: d422201c                 st      %o2, [%o0+0x1C]
F005EB2C: 81c7e008                 ret
F005EB30: 81e80000                 restore
