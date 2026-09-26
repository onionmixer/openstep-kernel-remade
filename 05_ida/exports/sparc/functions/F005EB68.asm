F005EB68: 9de3bf98                 save    %sp, -0x68, %sp
F005EB6C: 9010001a                 mov     %i2, %o0
F005EB70: 7ffe9e64                 call    _umul
F005EB74: 9210001b                 mov     %i3, %o1
F005EB78: a4102000                 mov     0, %l2
F005EB7C: a0102001                 mov     1, %l0
F005EB80: 80a48019                 cmp     %l2, %i1
F005EB84: 1a800013                 bcc     loc_F005EBD0
F005EB88: a8100008                 mov     %o0, %l4
F005EB8C: 273c0447                 sethi   -0xFEEE400, %l3
F005EB90: a2102000                 mov     0, %l1
F005EB94: d004e13c                 ld      [%l3+0x13C], %o0
F005EB98: 80a40008                 cmp     %l0, %o0
F005EB9C: 1a80000d                 bcc     loc_F005EBD0
F005EBA0: 80a40014                 cmp     %l0, %l4
F005EBA4: 0a800009                 bcs     loc_F005EBC8
F005EBA8: 80a48019                 cmp     %l2, %i1
F005EBAC: 90100010                 mov     %l0, %o0
F005EBB0: 7ffe9e94                 call    _udiv
F005EBB4: 9210001b                 mov     %i3, %o1
F005EBB8: d0244018                 st      %o0, [%l1+%i0]
F005EBBC: a2046004                 inc     4, %l1
F005EBC0: a404a001                 inc     %l2
F005EBC4: 80a48019                 cmp     %l2, %i1
F005EBC8: 0abffff3                 bcs     loc_F005EB94
F005EBCC: a12c2001                 sll     %l0, 1, %l0
F005EBD0: 113c0447                 sethi   %hi(_page_size), %o0
F005EBD4: 80a48019                 cmp     %l2, %i1
F005EBD8: 1a800016                 bcc     locret_F005EC30
F005EBDC: e602213c                 ld      [%o0+%lo(_page_size)], %l3
F005EBE0: a2102000                 mov     0, %l1
F005EBE4: b52ca002                 sll     %l2, 2, %i2
F005EBE8: 80a48019                 cmp     %l2, %i1
F005EBEC: 1a80000e                 bcc     loc_F005EC24
F005EBF0: 80a40014                 cmp     %l0, %l4
F005EBF4: 2a800009                 bcs,a   loc_F005EC18
F005EBF8: a2046001                 inc     %l1
F005EBFC: 90100010                 mov     %l0, %o0
F005EC00: 7ffe9e80                 call    _udiv
F005EC04: 9210001b                 mov     %i3, %o1
F005EC08: d0268018                 st      %o0, [%i2+%i0]
F005EC0C: b406a004                 inc     4, %i2
F005EC10: a404a001                 inc     %l2
F005EC14: a2046001                 inc     %l1
F005EC18: 80a4600e                 cmp     %l1, 0xE
F005EC1C: 08bffff3                 bleu    loc_F005EBE8
F005EC20: a0040013                 add     %l0, %l3, %l0
F005EC24: 80a48019                 cmp     %l2, %i1
F005EC28: 0abfffee                 bcs     loc_F005EBE0
F005EC2C: a72ce001                 sll     %l3, 1, %l3
F005EC30: 81c7e008                 ret
F005EC34: 81e80000                 restore
