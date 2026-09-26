F005C7A0: 9de3bf98                 save    %sp, -0x68, %sp
F005C7A4: 80a6e004                 cmp     %i3, 4! switch 5 cases
F005C7A8: 18800131                 bgu     def_F005C7C0! jumptable F005C7C0 default case
F005C7AC: e0068000                 ld      [%i2], %l0
F005C7B0: 113c0171901223c8         set     jpt_F005C7C0, %o0
F005C7B8: 932ee002                 sll     %i3, 2, %o1
F005C7BC: d0024008                 ld      [%o1+%o0], %o0
F005C7C0: 81c20000                 jmp     %o0! switch jump
F005C7C4: 01000000                 nop
F005C7DC: 11000200                 sethi   0x80000, %o0! jumptable F005C7C0 case 3
F005C7E0: 808c0008                 btst    %o0, %l0
F005C7E4: 0280012a                 be      loc_F005CC8C
F005C7E8: 80a72000                 cmp     %i4, 0
F005C7EC: 02800125                 be      loc_F005CC80
F005C7F0: 80a73fff                 cmp     %i4, -1
F005C7F4: 12800129                 bne     loc_F005CC98
F005C7F8: 90100018                 mov     %i0, %o0
F005C7FC: 92100019                 mov     %i1, %o1
F005C800: f206a004                 ld      [%i2+4], %i1
F005C804: 9410001a                 mov     %i2, %o2
F005C808: 7fffdd9c                 call    _ipc_entry_dealloc
F005C80C: c022a004                 clr     [%o2+4]
F005C810: d0064000                 ld      [%i1], %o0
F005C814: 80a22000                 cmp     %o0, 0
F005C818: 12bffffe                 bne     loc_F005C810
F005C81C: 01000000                 nop
F005C820: 4000e9a2                 call    _simple_lock_try
F005C824: 90100019                 mov     %i1, %o0
F005C828: 80a22000                 cmp     %o0, 0
F005C82C: 02bffff9                 be      loc_F005C810
F005C830: 01000000                 nop
F005C834: c0262008                 clr     [%i0+8]
F005C838: 7ffffc6d                 call    _ipc_pset_destroy
F005C83C: 90100019                 mov     %i1, %o0
F005C840: 1080011e                 ba      locret_F005CCB8
F005C844: b0102000                 mov     0, %i0
F005C848: 11000080                 sethi   0x20000, %o0! jumptable F005C7C0 case 1
F005C84C: 808c0008                 btst    %o0, %l0
F005C850: 0280010f                 be      loc_F005CC8C
F005C854: a2102000                 mov     0, %l1
F005C858: 80a72000                 cmp     %i4, 0
F005C85C: 02800109                 be      loc_F005CC80
F005C860: 80a73fff                 cmp     %i4, -1
F005C864: 1280010d                 bne     loc_F005CC98
F005C868: 11000800                 sethi   0x200000, %o0
F005C86C: 808c0008                 btst    %o0, %l0
F005C870: 22800007                 be,a    loc_F005C88C
F005C874: f606a004                 ld      [%i2+4], %i3
F005C878: a02c0008                 bclr    %o0, %l0
F005C87C: 90100018                 mov     %i0, %o0
F005C880: 7fffedbc                 call    _ipc_marequest_cancel
F005C884: 92100019                 mov     %i1, %o1
F005C888: f606a004                 ld      [%i2+4], %i3
F005C88C: d006c000                 ld      [%i3], %o0
F005C890: 80a22000                 cmp     %o0, 0
F005C894: 12bffffe                 bne     loc_F005C88C
F005C898: 01000000                 nop
F005C89C: 4000e983                 call    _simple_lock_try
F005C8A0: 9010001b                 mov     %i3, %o0
F005C8A4: 80a22000                 cmp     %o0, 0
F005C8A8: 02bffff9                 be      loc_F005C88C
F005C8AC: 11001000                 sethi   0x400000, %o0
F005C8B0: 808c0008                 btst    %o0, %l0
F005C8B4: 12800016                 bne     loc_F005C90C
F005C8B8: 90100018                 mov     %i0, %o0
F005C8BC: 11000040                 sethi   0x10000, %o0
F005C8C0: 808c0008                 btst    %o0, %l0
F005C8C4: 0280000d                 be      loc_F005C8F8
F005C8C8: 110007c0                 sethi   0x1F0000, %o0
F005C8CC: a02c0008                 bclr    %o0, %l0
F005C8D0: 11000400                 sethi   0x100000, %o0
F005C8D4: d206a008                 ld      [%i2+8], %o1
F005C8D8: 80a26000                 cmp     %o1, 0
F005C8DC: 02800004                 be      loc_F005C8EC
F005C8E0: a0140008                 bset    %o0, %l0
F005C8E4: c026a008                 clr     [%i2+8]
F005C8E8: a0042001                 inc     %l0
F005C8EC: e0268000                 st      %l0, [%i2]
F005C8F0: 10800011                 ba      loc_F005C934
F005C8F4: c026a004                 clr     [%i2+4]
F005C8F8: d006a008                 ld      [%i2+8], %o0
F005C8FC: 80a22000                 cmp     %o0, 0
F005C900: 02800008                 be      loc_F005C920
F005C904: a2102000                 mov     0, %l1
F005C908: 90100018                 mov     %i0, %o0
F005C90C: 9210001b                 mov     %i3, %o1
F005C910: 94100019                 mov     %i1, %o2
F005C914: 7ffffd16                 call    _ipc_right_dncancel
F005C918: 9610001a                 mov     %i2, %o3
F005C91C: a2100008                 mov     %o0, %l1
F005C920: c026a004                 clr     [%i2+4]
F005C924: 90100018                 mov     %i0, %o0
F005C928: 92100019                 mov     %i1, %o1
F005C92C: 7fffdd53                 call    _ipc_entry_dealloc
F005C930: 9410001a                 mov     %i2, %o2
F005C934: c0262008                 clr     [%i0+8]
F005C938: 7ffff7fc                 call    _ipc_port_clear_receiver
F005C93C: 9010001b                 mov     %i3, %o0
F005C940: 7ffff895                 call    _ipc_port_destroy
F005C944: 9010001b                 mov     %i3, %o0
F005C948: 80a46000                 cmp     %l1, 0
F005C94C: 028000ce                 be      loc_F005CC84
F005C950: 90100011                 mov     %l1, %o0
F005C954: 308000c2                 ba,a    loc_F005CC5C
F005C958: 11000100                 sethi   0x40000, %o0! jumptable F005C7C0 case 2
F005C95C: 808c0008                 btst    %o0, %l0
F005C960: 028000cb                 be      loc_F005CC8C
F005C964: 90072001                 add     %i4, 1, %o0
F005C968: 80a22001                 cmp     %o0, 1
F005C96C: 188000cb                 bgu     loc_F005CC98
F005C970: 90100018                 mov     %i0, %o0
F005C974: 94100019                 mov     %i1, %o2
F005C978: e206a004                 ld      [%i2+4], %l1
F005C97C: 9610001a                 mov     %i2, %o3
F005C980: 7ffffd49                 call    _ipc_right_check
F005C984: 92100011                 mov     %l1, %o1
F005C988: 80a22000                 cmp     %o0, 0
F005C98C: 32800071                 bne,a   loc_F005CB50
F005C990: 11001000                 sethi   0x400000, %o0
F005C994: 80a72000                 cmp     %i4, 0
F005C998: 32800004                 bne,a   loc_F005C9A8
F005C99C: d006a008                 ld      [%i2+8], %o0
F005C9A0: c0244000                 clr     [%l1]
F005C9A4: 308000b7                 ba,a    loc_F005CC80
F005C9A8: 80a22000                 cmp     %o0, 0
F005C9AC: 02800008                 be      loc_F005C9CC
F005C9B0: 92100011                 mov     %l1, %o1
F005C9B4: 90100018                 mov     %i0, %o0
F005C9B8: 94100019                 mov     %i1, %o2
F005C9BC: 7ffffcec                 call    _ipc_right_dncancel
F005C9C0: 9610001a                 mov     %i2, %o3
F005C9C4: 10800003                 ba      loc_F005C9D0
F005C9C8: a0100008                 mov     %o0, %l0
F005C9CC: a0102000                 mov     0, %l0
F005C9D0: c0244000                 clr     [%l1]
F005C9D4: c026a004                 clr     [%i2+4]
F005C9D8: 90100018                 mov     %i0, %o0
F005C9DC: 92100019                 mov     %i1, %o1
F005C9E0: 7fffdd26                 call    _ipc_entry_dealloc
F005C9E4: 9410001a                 mov     %i2, %o2
F005C9E8: c0262008                 clr     [%i0+8]
F005C9EC: 7ffff232                 call    _ipc_notify_send_once
F005C9F0: 90100011                 mov     %l1, %o0
F005C9F4: 80a42000                 cmp     %l0, 0
F005C9F8: 028000a3                 be      loc_F005CC84
F005C9FC: 90100010                 mov     %l0, %o0
F005CA00: 30800097                 ba,a    loc_F005CC5C
F005CA04: 11000140                 sethi   0x50000, %o0! jumptable F005C7C0 case 4
F005CA08: 808c0008                 btst    %o0, %l0
F005CA0C: 02800011                 be      loc_F005CA50
F005CA10: 90100018                 mov     %i0, %o0
F005CA14: 94100019                 mov     %i1, %o2
F005CA18: e206a004                 ld      [%i2+4], %l1
F005CA1C: 9610001a                 mov     %i2, %o3
F005CA20: 7ffffd21                 call    _ipc_right_check
F005CA24: 92100011                 mov     %l1, %o1
F005CA28: 80a22000                 cmp     %o0, 0
F005CA2C: 12800004                 bne     loc_F005CA3C
F005CA30: 11001000                 sethi   0x400000, %o0
F005CA34: c0244000                 clr     [%l1]
F005CA38: 30800095                 ba,a    loc_F005CC8C
F005CA3C: 808c0008                 btst    %o0, %l0
F005CA40: 1280009c                 bne     loc_F005CCB0
F005CA44: 01000000                 nop
F005CA48: 10800006                 ba      loc_F005CA60
F005CA4C: e0068000                 ld      [%i2], %l0
F005CA50: 11000400                 sethi   0x100000, %o0
F005CA54: 808c0008                 btst    %o0, %l0
F005CA58: 0280008d                 be      loc_F005CC8C
F005CA5C: 01000000                 nop
F005CA60: 80a72000                 cmp     %i4, 0
F005CA64: 1100003f941223ff         set     0xFFFF, %o2
F005CA6C: 16800006                 bge     loc_F005CA84
F005CA70: 920c000a                 and     %l0, %o2, %o1
F005CA74: 9020001c                 neg     %i4, %o0
F005CA78: 80a20009                 cmp     %o0, %o1
F005CA7C: 18800087                 bgu     loc_F005CC98
F005CA80: 80a72000                 cmp     %i4, 0
F005CA84: 04800007                 ble     loc_F005CAA0
F005CA88: 9002401c                 add     %o1, %i4, %o0
F005CA8C: 80a20009                 cmp     %o0, %o1
F005CA90: 08800085                 bleu    loc_F005CCA4
F005CA94: 80a2000a                 cmp     %o0, %o2
F005CA98: 18800083                 bgu     loc_F005CCA4
F005CA9C: 01000000                 nop
F005CAA0: 9002401c                 add     %o1, %i4, %o0
F005CAA4: 80a22000                 cmp     %o0, 0
F005CAA8: 12800007                 bne     loc_F005CAC4
F005CAAC: 9004001c                 add     %l0, %i4, %o0
F005CAB0: 90100018                 mov     %i0, %o0
F005CAB4: 92100019                 mov     %i1, %o1
F005CAB8: 7fffdcf0                 call    _ipc_entry_dealloc
F005CABC: 9410001a                 mov     %i2, %o2
F005CAC0: 30800070                 ba,a    loc_F005CC80
F005CAC4: 1080006f                 ba      loc_F005CC80
F005CAC8: d0268000                 st      %o0, [%i2]
F005CACC: a4102000                 mov     0, %l2! jumptable F005C7C0 case 0
F005CAD0: a6102000                 mov     0, %l3
F005CAD4: 11000040                 sethi   0x10000, %o0
F005CAD8: 808c0008                 btst    %o0, %l0
F005CADC: 0280006c                 be      loc_F005CC8C
F005CAE0: a8102000                 mov     0, %l4
F005CAE4: 80a72000                 cmp     %i4, 0
F005CAE8: 1100003f941223ff         set     0xFFFF, %o2
F005CAF0: 16800006                 bge     loc_F005CB08
F005CAF4: a20c000a                 and     %l0, %o2, %l1
F005CAF8: 9020001c                 neg     %i4, %o0
F005CAFC: 80a20011                 cmp     %o0, %l1
F005CB00: 18800066                 bgu     loc_F005CC98
F005CB04: 80a72000                 cmp     %i4, 0
F005CB08: 04800009                 ble     loc_F005CB2C
F005CB0C: 90072001                 add     %i4, 1, %o0
F005CB10: 92044008                 add     %l1, %o0, %o1
F005CB14: 90046001                 add     %l1, 1, %o0
F005CB18: 80a24008                 cmp     %o1, %o0
F005CB1C: 08800062                 bleu    loc_F005CCA4
F005CB20: 80a2400a                 cmp     %o1, %o2
F005CB24: 18800060                 bgu     loc_F005CCA4
F005CB28: 01000000                 nop
F005CB2C: 90100018                 mov     %i0, %o0
F005CB30: 94100019                 mov     %i1, %o2
F005CB34: f606a004                 ld      [%i2+4], %i3
F005CB38: 9610001a                 mov     %i2, %o3
F005CB3C: 7ffffcda                 call    _ipc_right_check
F005CB40: 9210001b                 mov     %i3, %o1
F005CB44: 80a22000                 cmp     %o0, 0
F005CB48: 02800006                 be      loc_F005CB60
F005CB4C: 11001000                 sethi   0x400000, %o0
F005CB50: 808c0008                 btst    %o0, %l0
F005CB54: 0280004e                 be      loc_F005CC8C
F005CB58: 01000000                 nop
F005CB5C: 30800055                 ba,a    loc_F005CCB0
F005CB60: 9004401c                 add     %l1, %i4, %o0
F005CB64: 80a22000                 cmp     %o0, 0
F005CB68: 12800032                 bne     loc_F005CC30
F005CB6C: 9004001c                 add     %l0, %i4, %o0
F005CB70: d006e01c                 ld      [%i3+0x1C], %o0
F005CB74: 90023fff                 inc     -1, %o0
F005CB78: 80a22000                 cmp     %o0, 0
F005CB7C: 12800008                 bne     loc_F005CB9C
F005CB80: d026e01c                 st      %o0, [%i3+0x1C]
F005CB84: e606e024                 ld      [%i3+0x24], %l3
F005CB88: 80a4e000                 cmp     %l3, 0
F005CB8C: 02800005                 be      loc_F005CBA0
F005CB90: 11000080                 sethi   0x20000, %o0
F005CB94: c026e024                 clr     [%i3+0x24]
F005CB98: e806e018                 ld      [%i3+0x18], %l4
F005CB9C: 11000080                 sethi   0x20000, %o0
F005CBA0: 808c0008                 btst    %o0, %l0
F005CBA4: 02800004                 be      loc_F005CBB4
F005CBA8: 113fff80                 sethi   -0x20000, %o0
F005CBAC: 10800021                 ba      loc_F005CC30
F005CBB0: 900c0008                 and     %l0, %o0, %o0
F005CBB4: d006a008                 ld      [%i2+8], %o0
F005CBB8: 80a22000                 cmp     %o0, 0
F005CBBC: 02800008                 be      loc_F005CBDC
F005CBC0: 90100018                 mov     %i0, %o0
F005CBC4: 9210001b                 mov     %i3, %o1
F005CBC8: 94100019                 mov     %i1, %o2
F005CBCC: 7ffffc68                 call    _ipc_right_dncancel
F005CBD0: 9610001a                 mov     %i2, %o3
F005CBD4: 10800003                 ba      loc_F005CBE0
F005CBD8: a4100008                 mov     %o0, %l2
F005CBDC: a4102000                 mov     0, %l2
F005CBE0: 90100018                 mov     %i0, %o0
F005CBE4: 9210001b                 mov     %i3, %o1
F005CBE8: 94100019                 mov     %i1, %o2
F005CBEC: 7fffde71                 call    _ipc_hash_delete
F005CBF0: 9610001a                 mov     %i2, %o3
F005CBF4: 11000800                 sethi   0x200000, %o0
F005CBF8: 808c0008                 btst    %o0, %l0
F005CBFC: 02800004                 be      loc_F005CC0C
F005CC00: 90100018                 mov     %i0, %o0
F005CC04: 7fffecdb                 call    _ipc_marequest_cancel
F005CC08: 92100019                 mov     %i1, %o1
F005CC0C: d006e004                 ld      [%i3+4], %o0
F005CC10: 90023fff                 inc     -1, %o0
F005CC14: d026e004                 st      %o0, [%i3+4]
F005CC18: c026a004                 clr     [%i2+4]
F005CC1C: 90100018                 mov     %i0, %o0
F005CC20: 92100019                 mov     %i1, %o1
F005CC24: 7fffdc95                 call    _ipc_entry_dealloc
F005CC28: 9410001a                 mov     %i2, %o2
F005CC2C: 30800002                 ba,a    loc_F005CC34
F005CC30: d0268000                 st      %o0, [%i2]
F005CC34: c026c000                 clr     [%i3]
F005CC38: c0262008                 clr     [%i0+8]
F005CC3C: 80a4e000                 cmp     %l3, 0
F005CC40: 02800004                 be      loc_F005CC50
F005CC44: 90100013                 mov     %l3, %o0
F005CC48: 7ffff16f                 call    _ipc_notify_no_senders
F005CC4C: 92100014                 mov     %l4, %o1
F005CC50: 80a4a000                 cmp     %l2, 0
F005CC54: 0280000c                 be      loc_F005CC84
F005CC58: 90100012                 mov     %l2, %o0
F005CC5C: 7ffff0e4                 call    _ipc_notify_port_deleted
F005CC60: 92100019                 mov     %i1, %o1
F005CC64: 10800015                 ba      locret_F005CCB8
F005CC68: b0102000                 mov     0, %i0
F005CC6C: 113c043d                 sethi   %hi(aIpcRightDeltaS), %o0! jumptable F005C7C0 default case
F005CC70: 7ffee140                 call    _panic
F005CC74: 901222d8                 bset    %lo(aIpcRightDeltaS), %o0! "ipc_right_delta: strange right"
F005CC78: 10800010                 ba      locret_F005CCB8
F005CC7C: b0102000                 mov     0, %i0
F005CC80: c0262008                 clr     [%i0+8]
F005CC84: 1080000d                 ba      locret_F005CCB8
F005CC88: b0102000                 mov     0, %i0
F005CC8C: c0262008                 clr     [%i0+8]
F005CC90: 1080000a                 ba      locret_F005CCB8
F005CC94: b0102011                 mov     0x11, %i0
F005CC98: c0262008                 clr     [%i0+8]
F005CC9C: 10800007                 ba      locret_F005CCB8
F005CCA0: b0102012                 mov     0x12, %i0
F005CCA4: c0262008                 clr     [%i0+8]
F005CCA8: 10800004                 ba      locret_F005CCB8
F005CCAC: b0102013                 mov     0x13, %i0
F005CCB0: c0262008                 clr     [%i0+8]
F005CCB4: b010200f                 mov     0xF, %i0
F005CCB8: 81c7e008                 ret
F005CCBC: 81e80000                 restore
