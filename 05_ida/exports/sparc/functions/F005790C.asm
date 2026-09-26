F005790C: 9de3bf70                 save    %sp, -0x90, %sp
F0057910: e4062014                 ld      [%i0+0x14], %l2
F0057914: e006201c                 ld      [%i0+0x1C], %l0
F0057918: b6100019                 mov     %i1, %i3
F005791C: e2062020                 ld      [%i0+0x20], %l1
F0057920: d0040000                 ld      [%l0], %o0
F0057924: 80a22000                 cmp     %o0, 0
F0057928: 12bffffe                 bne     loc_F0057920
F005792C: 01000000                 nop
F0057930: 4000fd5e                 call    _simple_lock_try
F0057934: 90100010                 mov     %l0, %o0
F0057938: 80a22000                 cmp     %o0, 0
F005793C: 02bffff9                 be      loc_F0057920
F0057940: 01000000                 nop
F0057944: d0042008                 ld      [%l0+8], %o0
F0057948: 80a22000                 cmp     %o0, 0
F005794C: 36800009                 bge,a   loc_F0057970
F0057950: d0042004                 ld      [%l0+4], %o0
F0057954: 9010001b                 mov     %i3, %o0
F0057958: 92100010                 mov     %l0, %o1
F005795C: 940ca0ff                 and     %l2, 0xFF, %o2
F0057960: 4000097d                 call    _ipc_object_copyout_dest
F0057964: 9607bfdc                 add     %fp, var_24, %o3
F0057968: 10800013                 ba      loc_F00579B4
F005796C: 80a46000                 cmp     %l1, 0
F0057970: 90023fff                 inc     -1, %o0
F0057974: d0242004                 st      %o0, [%l0+4]
F0057978: c0240000                 clr     [%l0]
F005797C: 80a22000                 cmp     %o0, 0
F0057980: 3280000c                 bne,a   loc_F00579B0
F0057984: c027bfdc                 clr     [%fp+var_24]
F0057988: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005798C: d0042008                 ld      [%l0+8], %o0
F0057990: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0057994: 912a2001                 sll     %o0, 1, %o0
F0057998: 91322011                 srl     %o0, 17, %o0
F005799C: 912a2002                 sll     %o0, 2, %o0
F00579A0: d0020009                 ld      [%o0+%o1], %o0
F00579A4: 4000860b                 call    _zfree
F00579A8: 92100010                 mov     %l0, %o1
F00579AC: c027bfdc                 clr     [%fp+var_24]
F00579B0: 80a46000                 cmp     %l1, 0
F00579B4: 02800011                 be      loc_F00579F8
F00579B8: 80a47fff                 cmp     %l1, -1
F00579BC: 0280000f                 be      loc_F00579F8
F00579C0: 9010001b                 mov     %i3, %o0
F00579C4: 92100011                 mov     %l1, %o1
F00579C8: 1500003f9412a300         set     0xFF00, %o2
F00579D0: 940c800a                 and     %l2, %o2, %o2
F00579D4: a132a008                 srl     %o2, 8, %l0
F00579D8: 94100010                 mov     %l0, %o2
F00579DC: 400009eb                 call    _ipc_object_copyout_compat
F00579E0: 9607bfd8                 add     %fp, var_28, %o3! flags
F00579E4: 80a22000                 cmp     %o0, 0
F00579E8: 02800005                 be      loc_F00579FC
F00579EC: 90100011                 mov     %l1, %o0
F00579F0: 400008ab                 call    _ipc_object_destroy
F00579F4: 92100010                 mov     %l0, %o1
F00579F8: c027bfd8                 clr     [%fp+var_28]
F00579FC: d00fbfe3                 ldub    [%fp+var_1D], %o0
F0057A00: d027bfe0                 st      %o0, [%fp-0x20]
F0057A04: 9134a01f                 srl     %l2, 31, %o0
F0057A08: 901a2001                 btog    1, %o0
F0057A0C: d02fbfe3                 stb     %o0, [%fp+var_1D]
F0057A10: d0062018                 ld      [%i0+0x18], %o0
F0057A14: d027bfe4                 st      %o0, [%fp+var_1C]
F0057A18: d0062024                 ld      [%i0+0x24], %o0
F0057A1C: d207bfdc                 ld      [%fp+var_24], %o1
F0057A20: d027bfe8                 st      %o0, [%fp+var_18]
F0057A24: d007bfd8                 ld      [%fp+var_28], %o0
F0057A28: d227bfec                 st      %o1, [%fp+var_14]
F0057A2C: d027bff0                 st      %o0, [%fp+var_10]
F0057A30: d0062028                 ld      [%i0+0x28], %o0
F0057A34: d207bfe0                 ld      [%fp-0x20], %o1
F0057A38: d027bff4                 st      %o0, [%fp+var_C]
F0057A3C: d2262014                 st      %o1, [%i0+0x14]
F0057A40: d007bfe4                 ld      [%fp+var_1C], %o0
F0057A44: d0262018                 st      %o0, [%i0+0x18]
F0057A48: d007bfe8                 ld      [%fp+var_18], %o0
F0057A4C: d026201c                 st      %o0, [%i0+0x1C]
F0057A50: d007bfec                 ld      [%fp+var_14], %o0
F0057A54: d0262020                 st      %o0, [%i0+0x20]
F0057A58: d007bff0                 ld      [%fp+var_10], %o0
F0057A5C: d0262024                 st      %o0, [%i0+0x24]
F0057A60: d007bff4                 ld      [%fp+var_C], %o0
F0057A64: d0262028                 st      %o0, [%i0+0x28]
F0057A68: d00fbfe3                 ldub    [%fp+var_1D], %o0
F0057A6C: 80a22000                 cmp     %o0, 0
F0057A70: 12800085                 bne     locret_F0057C84
F0057A74: a406202c                 add     %i0, 0x2C, %l2 ! ','
F0057A78: d0062018                 ld      [%i0+0x18], %o0
F0057A7C: 90022014                 inc     0x14, %o0
F0057A80: b2060008                 add     %i0, %o0, %i1
F0057A84: 80a48019                 cmp     %l2, %i1
F0057A88: 1a80007f                 bcc     locret_F0057C84
F0057A8C: 393c04ef                 sethi   -0xFEC4400, %i4
F0057A90: d0048000                 ld      [%l2], %o0
F0057A94: a6100012                 mov     %l2, %l3
F0057A98: a2100012                 mov     %l2, %l1
F0057A9C: b1322003                 srl     %o0, 3, %i0
F0057AA0: a1322002                 srl     %o0, 2, %l0
F0057AA4: a08c2001                 andcc   %l0, 1, %l0
F0057AA8: 02800007                 be      loc_F0057AC4
F0057AAC: b00e2001                 and     %i0, 1, %i0
F0057AB0: ec14a004                 lduh    [%l2+4], %l6
F0057AB4: d214a006                 lduh    [%l2+6], %o1
F0057AB8: ea04a008                 ld      [%l2+8], %l5
F0057ABC: 10800008                 ba      loc_F0057ADC
F0057AC0: a404a00c                 inc     0xC, %l2
F0057AC4: ec0c8000                 ldub    [%l2], %l6
F0057AC8: 93322010                 srl     %o0, 16, %o1
F0057ACC: 920a60ff                 and     %o1, 0xFF, %o1
F0057AD0: ab322004                 srl     %o0, 4, %l5
F0057AD4: aa0d6fff                 and     %l5, 0xFFF, %l5
F0057AD8: a404a004                 inc     4, %l2
F0057ADC: 7ffeba89                 call    _umul
F0057AE0: 90100015                 mov     %l5, %o0
F0057AE4: ae05bff0                 add     %l6, -0x10, %l7
F0057AE8: 80a5e005                 cmp     %l7, 5
F0057AEC: 28800003                 bleu,a  loc_F0057AF8
F0057AF0: ae102001                 mov     1, %l7
F0057AF4: ae102000                 mov     0, %l7
F0057AF8: 80a5e000                 cmp     %l7, 0
F0057AFC: 90022007                 inc     7, %o0
F0057B00: 02800036                 be      loc_F0057BD8
F0057B04: a9322003                 srl     %o0, 3, %l4
F0057B08: 80a62000                 cmp     %i0, 0
F0057B0C: 1280000f                 bne     loc_F0057B48
F0057B10: 80a52000                 cmp     %l4, 0
F0057B14: 0280000d                 be      loc_F0057B48
F0057B18: 9010001a                 mov     %i2, %o0! target_task
F0057B1C: 9207bfd4                 add     %fp, var_2C, %o1! address
F0057B20: 94100014                 mov     %l4, %o2! size
F0057B24: 4000cb3f                 call    _vm_allocate
F0057B28: 96102001                 mov     1, %o3
F0057B2C: 80a22000                 cmp     %o0, 0
F0057B30: 02800006                 be      loc_F0057B48
F0057B34: 90100013                 mov     %l3, %o0
F0057B38: 7ffff4e2                 call    _ipc_kmsg_clean_body
F0057B3C: 92100012                 mov     %l2, %o1
F0057B40: 1080004b                 ba      loc_F0057C6C
F0057B44: c027bfd4                 clr     [%fp+var_2C]
F0057B48: 40000964                 call    _ipc_object_copyout_type_compat
F0057B4C: 90100016                 mov     %l6, %o0
F0057B50: 80a42000                 cmp     %l0, 0
F0057B54: 22800003                 be,a    loc_F0057B60
F0057B58: d02c4000                 stb     %o0, [%l1]
F0057B5C: d0346004                 sth     %o0, [%l1+4]
F0057B60: 80a62000                 cmp     %i0, 0
F0057B64: 12800003                 bne     loc_F0057B70
F0057B68: 96100012                 mov     %l2, %o3
F0057B6C: d6048000                 ld      [%l2], %o3
F0057B70: a6102000                 mov     0, %l3
F0057B74: 80a4c015                 cmp     %l3, %l5
F0057B78: 1a800019                 bcc     loc_F0057BDC
F0057B7C: 80a62000                 cmp     %i0, 0
F0057B80: a010000b                 mov     %o3, %l0
F0057B84: e2040000                 ld      [%l0], %l1
F0057B88: 80a46000                 cmp     %l1, 0
F0057B8C: 0280000e                 be      loc_F0057BC4
F0057B90: 80a47fff                 cmp     %l1, -1
F0057B94: 0280000c                 be      loc_F0057BC4
F0057B98: 9010001b                 mov     %i3, %o0
F0057B9C: 92100011                 mov     %l1, %o1
F0057BA0: 94100016                 mov     %l6, %o2
F0057BA4: 40000979                 call    _ipc_object_copyout_compat
F0057BA8: 96100010                 mov     %l0, %o3
F0057BAC: 80a22000                 cmp     %o0, 0
F0057BB0: 22800007                 be,a    loc_F0057BCC
F0057BB4: a604e001                 inc     %l3
F0057BB8: 90100011                 mov     %l1, %o0
F0057BBC: 40000838                 call    _ipc_object_destroy
F0057BC0: 92100016                 mov     %l6, %o1
F0057BC4: c0240000                 clr     [%l0]
F0057BC8: a604e001                 inc     %l3
F0057BCC: 80a4c015                 cmp     %l3, %l5
F0057BD0: 0abfffed                 bcs     loc_F0057B84
F0057BD4: a0042004                 inc     4, %l0
F0057BD8: 80a62000                 cmp     %i0, 0
F0057BDC: 02800005                 be      loc_F0057BF0
F0057BE0: 90052003                 add     %l4, 3, %o0
F0057BE4: 900a3ffc                 and     %o0, -4, %o0
F0057BE8: 10800024                 ba      loc_F0057C78
F0057BEC: a4048008                 add     %l2, %o0, %l2
F0057BF0: 80a52000                 cmp     %l4, 0
F0057BF4: 0280001d                 be      loc_F0057C68
F0057BF8: e0048000                 ld      [%l2], %l0
F0057BFC: 80a5e000                 cmp     %l7, 0
F0057C00: 0280000b                 be      loc_F0057C2C
F0057C04: 9010001a                 mov     %i2, %o0
F0057C08: 92100010                 mov     %l0, %o1
F0057C0C: d407bfd4                 ld      [%fp+var_2C], %o2
F0057C10: 4000afd2                 call    _copyoutmap
F0057C14: 96100014                 mov     %l4, %o3
F0057C18: 90100010                 mov     %l0, %o0
F0057C1C: 40004161                 call    _kfree
F0057C20: 92100014                 mov     %l4, %o1
F0057C24: 10800013                 ba      loc_F0057C70
F0057C28: d007bfd4                 ld      [%fp+var_2C], %o0
F0057C2C: 92100010                 mov     %l0, %o1
F0057C30: 9410001a                 mov     %i2, %o2! size
F0057C34: 96100014                 mov     %l4, %o3
F0057C38: 98102000                 mov     0, %o4
F0057C3C: d0072320                 ld      [%i4+0x320], %o0
F0057C40: 4000b98e                 call    _vm_move
F0057C44: 9a07bfd4                 add     %fp, var_2C, %o5
F0057C48: 92100010                 mov     %l0, %o1! address
F0057C4C: a0100008                 mov     %o0, %l0
F0057C50: d0072320                 ld      [%i4+0x320], %o0! target_task
F0057C54: 4000cb13                 call    _vm_deallocate
F0057C58: 94100014                 mov     %l4, %o2
F0057C5C: 80a42000                 cmp     %l0, 0
F0057C60: 02800004                 be      loc_F0057C70
F0057C64: d007bfd4                 ld      [%fp+var_2C], %o0
F0057C68: c027bfd4                 clr     [%fp+var_2C]
F0057C6C: d007bfd4                 ld      [%fp+var_2C], %o0
F0057C70: d0248000                 st      %o0, [%l2]
F0057C74: a404a004                 inc     4, %l2
F0057C78: 80a48019                 cmp     %l2, %i1
F0057C7C: 2abfff86                 bcs,a   loc_F0057A94
F0057C80: d0048000                 ld      [%l2], %o0
F0057C84: 81c7e008                 ret
F0057C88: 91e82000                 restore %g0, 0, %o0
