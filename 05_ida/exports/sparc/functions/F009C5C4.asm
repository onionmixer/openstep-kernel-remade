F009C5C4: 9de3bf90                 save    %sp, -0x70, %sp
F009C5C8: f027a044                 st      %i0, [%fp+arg_44]
F009C5CC: 80a66000                 cmp     %i1, 0
F009C5D0: 113c04f790122270         set     _pmap_info, %o0
F009C5D8: d2022038                 ld      [%o0+0x38], %o1
F009C5DC: 153c04f0                 sethi   %hi(_kernel_pmap), %o2
F009C5E0: e202a100                 ld      [%o2+%lo(_kernel_pmap)], %l1
F009C5E4: 92026001                 inc     %o1
F009C5E8: 02800046                 be      locret_F009C700
F009C5EC: d2222038                 st      %o1, [%o0+0x38]
F009C5F0: 7fffe9c3                 call    _splvm
F009C5F4: b0046018                 add     %l1, 0x18, %i0
F009C5F8: a4100008                 mov     %o0, %l2
F009C5FC: d0060000                 ld      [%i0], %o0
F009C600: 80a22000                 cmp     %o0, 0
F009C604: 12bffffe                 bne     loc_F009C5FC
F009C608: 01000000                 nop
F009C60C: 7fffea27                 call    _simple_lock_try
F009C610: 90100018                 mov     %i0, %o0
F009C614: 80a22000                 cmp     %o0, 0
F009C618: 02bffff9                 be      loc_F009C5FC
F009C61C: 90100011                 mov     %l1, %o0
F009C620: d207a044                 ld      [%fp+arg_44], %o1
F009C624: 400000e5                 call    _pmap_page_table_entry
F009C628: 94102000                 mov     0, %o2
F009C62C: a0100008                 mov     %o0, %l0
F009C630: d00c200d                 ldub    [%l0+0xD], %o0
F009C634: 80a22003                 cmp     %o0, 3
F009C638: 12800007                 bne     loc_F009C654
F009C63C: 80a22002                 cmp     %o0, 2
F009C640: 113c04d0                 sethi   %hi(_page_mask), %o0
F009C644: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F009C648: d207a044                 ld      [%fp+arg_44], %o1
F009C64C: 10800008                 ba      loc_F009C66C
F009C650: 902a4008                 andn    %o1, %o0, %o0
F009C654: 12800004                 bne     loc_F009C664
F009C658: d007a044                 ld      [%fp+arg_44], %o0
F009C65C: 10800003                 ba      loc_F009C668
F009C660: 133fff00                 sethi   -0x40000, %o1
F009C664: 133fc000                 sethi   -0x1000000, %o1
F009C668: 900a0009                 and     %o0, %o1, %o0
F009C66C: d027a044                 st      %o0, [%fp+arg_44]
F009C670: d00c200d                 ldub    [%l0+0xD], %o0
F009C674: 80a22003                 cmp     %o0, 3
F009C678: 12800007                 bne     loc_F009C694
F009C67C: 80a22002                 cmp     %o0, 2
F009C680: d007a044                 ld      [%fp+arg_44], %o0
F009C684: d2040000                 ld      [%l0], %o1
F009C688: 9132200a                 srl     %o0, 10, %o0
F009C68C: 1080000a                 ba      loc_F009C6B4
F009C690: 900a20fc                 and     %o0, 0xFC, %o0
F009C694: 32800006                 bne,a   loc_F009C6AC
F009C698: d00fa044                 ldub    [%fp+arg_44], %o0
F009C69C: d017a044                 lduh    [%fp+arg_44], %o0
F009C6A0: d2040000                 ld      [%l0], %o1
F009C6A4: 10800004                 ba      loc_F009C6B4
F009C6A8: 900a20fc                 and     %o0, 0xFC, %o0
F009C6AC: d2040000                 ld      [%l0], %o1
F009C6B0: 912a2002                 sll     %o0, 2, %o0
F009C6B4: b0024008                 add     %o1, %o0, %i0
F009C6B8: d0060000                 ld      [%i0], %o0
F009C6BC: 900a2003                 and     %o0, 3, %o0
F009C6C0: 80a22002                 cmp     %o0, 2
F009C6C4: 1280000d                 bne     loc_F009C6F8
F009C6C8: 90100011                 mov     %l1, %o0
F009C6CC: 40001377                 call    _vm_to_srmmu_prot
F009C6D0: 92100019                 mov     %i1, %o1
F009C6D4: e027bff4                 st      %l0, [%fp+var_C]
F009C6D8: 94100008                 mov     %o0, %o2
F009C6DC: d6060000                 ld      [%i0], %o3
F009C6E0: 9007bff4                 add     %fp, var_C, %o0
F009C6E4: d207a044                 ld      [%fp+arg_44], %o1
F009C6E8: 9732e007                 srl     %o3, 7, %o3
F009C6EC: 400013ff                 call    _update_pte
F009C6F0: 960ae001                 and     %o3, 1, %o3
F009C6F4: c0246018                 clr     [%l1+0x18]
F009C6F8: 7fffe98b                 call    _splx
F009C6FC: 90100012                 mov     %l2, %o0
F009C700: 81c7e008                 ret
F009C704: 81e80000                 restore
