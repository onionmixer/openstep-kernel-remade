F00A6630: 9de3bf98                 save    %sp, -0x68, %sp
F00A6634: 11000200                 sethi   0x80000, %o0
F00A6638: 808e0008                 btst    %o0, %i0
F00A663C: 02800004                 be      loc_F00A664C
F00A6640: 113c0467                 sethi   %hi(aMultipleErrors_0), %o0! "\tMultiple Errors\n"
F00A6644: 7ffdb805                 call    _printf
F00A6648: 90122138                 bset    %lo(aMultipleErrors_0), %o0! "\tMultiple Errors\n"
F00A664C: 11004000                 sethi   0x1000000, %o0
F00A6650: 808e0008                 btst    %o0, %i0
F00A6654: 02800004                 be      loc_F00A6664
F00A6658: 113c0467                 sethi   %hi(aErrorDuringSup), %o0! "\tError during Supv mode cycle\n"
F00A665C: 10800004                 ba      loc_F00A666C
F00A6660: 90122150                 bset    %lo(aErrorDuringSup), %o0! "\tError during Supv mode cycle\n"
F00A6664: 113c046790122170         set     aErrorDuringUse, %o0! "\tError during User mode cycle\n"
F00A666C: 7ffdb7fb                 call    _printf
F00A6670: 01000000                 nop
F00A6674: 11100000                 sethi   0x40000000, %o0
F00A6678: 808e0008                 btst    %o0, %i0
F00A667C: 02800004                 be      loc_F00A668C
F00A6680: 113c0467                 sethi   %hi(aLateError), %o0! "\tLate Error\n"
F00A6684: 7ffdb7f5                 call    _printf
F00A6688: 90122190                 bset    %lo(aLateError), %o0! "\tLate Error\n"
F00A668C: 11080000                 sethi   0x20000000, %o0
F00A6690: 808e0008                 btst    %o0, %i0
F00A6694: 02800004                 be      loc_F00A66A4
F00A6698: 113c0467                 sethi   %hi(aTimeoutError_0), %o0! "\tTimeout Error\n"
F00A669C: 7ffdb7ef                 call    _printf
F00A66A0: 901221a0                 bset    %lo(aTimeoutError_0), %o0! "\tTimeout Error\n"
F00A66A4: 11040000                 sethi   0x10000000, %o0
F00A66A8: 808e0008                 btst    %o0, %i0
F00A66AC: 02800004                 be      loc_F00A66BC
F00A66B0: 113c0467                 sethi   %hi(aBusError_0), %o0! "\tBus Error\n"
F00A66B4: 7ffdb7e9                 call    _printf
F00A66B8: 901221b0                 bset    %lo(aBusError_0), %o0! "\tBus Error\n"
F00A66BC: 11004000                 sethi   0x1000000, %o0
F00A66C0: 808e0008                 btst    %o0, %i0
F00A66C4: 113c0467                 sethi   %hi(aRequestedTrans_0), %o0! "\tRequested transaction: %s%s at %x:%x "...
F00A66C8: 02800005                 be      loc_F00A66DC
F00A66CC: 941221c0                 or      %o0, %lo(aRequestedTrans_0), %o2! "\tRequested transaction: %s%s at %x:%x "...
F00A66D0: 113c0467                 sethi   %hi(aSupv_3), %o0! "supv "
F00A66D4: 10800004                 ba      loc_F00A66E4
F00A66D8: 921221f8                 or      %o0, %lo(aSupv_3), %o1! "supv "
F00A66DC: 113c046792122200         set     aUser_4, %o1! "user "
F00A66E4: 9010000a                 mov     %o2, %o0! char *
F00A66E8: a00e200f                 and     %i0, 0xF, %l0
F00A66EC: 96100010                 mov     %l0, %o3
F00A66F0: 99362017                 srl     %i0, 23, %o4
F00A66F4: 153c04679412a074         set     _nameof_siz, %o2
F00A66FC: 980b201c                 and     %o4, 0x1C, %o4
F00A6700: 9b362014                 srl     %i0, 20, %o5
F00A6704: d403000a                 ld      [%o4+%o2], %o2
F00A6708: 9a0b600f                 and     %o5, 0xF, %o5
F00A670C: 7ffdb7d3                 call    _printf
F00A6710: 98100019                 mov     %i1, %o4
F00A6714: 113c046790122208         set     aSpecificCycleS, %o0! "\tSpecific cycle: %s at %x:%x\n"
F00A671C: 94100010                 mov     %l0, %o2
F00A6720: 960e2e00                 and     %i0, 0xE00, %o3
F00A6724: 133c0467921260d8         set     _nameof_ssiz, %o1
F00A672C: 9732e007                 srl     %o3, 7, %o3
F00A6730: d202c009                 ld      [%o3+%o1], %o1
F00A6734: 980e7fe0                 and     %i1, -0x20, %o4
F00A6738: 9736200c                 srl     %i0, 12, %o3
F00A673C: 960ae01f                 and     %o3, 0x1F, %o3
F00A6740: 7ffdb7c6                 call    _printf
F00A6744: 9613000b                 bset    %o4, %o3
F00A6748: 81c7e008                 ret
F00A674C: 81e80000                 restore
