F008BFC8: 9de3bf90                 save    %sp, -0x70, %sp
F008BFCC: 7ffffb2a                 call    _vnode_pager_vget
F008BFD0: 90100018                 mov     %i0, %o0
F008BFD4: 133c0447                 sethi   %hi(dword_F0111EA8), %o1
F008BFD8: d406200c                 ld      [%i0+0xC], %o2
F008BFDC: 80a2a000                 cmp     %o2, 0
F008BFE0: 16800057                 bge     loc_F008C13C
F008BFE4: c02262a8                 clr     [%o1+%lo(dword_F0111EA8)]
F008BFE8: d2062010                 ld      [%i0+0x10], %o1
F008BFEC: 912a6002                 sll     %o1, 2, %o0
F008BFF0: 80a22040                 cmp     %o0, 0x40 ! '@'
F008BFF4: 08800032                 bleu    loc_F008C0BC
F008BFF8: ec062004                 ld      [%i0+4], %l6
F008BFFC: 90027fff                 add     %o1, -1, %o0
F008C000: 91322004                 srl     %o0, 4, %o0
F008C004: 80a23fff                 cmp     %o0, -1
F008C008: 02800028                 be      loc_F008C0A8
F008C00C: a6102000                 mov     0, %l3
F008C010: aa07bff4                 add     %fp, var_C, %l5
F008C014: a8102000                 mov     0, %l4
F008C018: d0062008                 ld      [%i0+8], %o0
F008C01C: d0020014                 ld      [%o0+%l4], %o0
F008C020: 80a22000                 cmp     %o0, 0
F008C024: 22800019                 be,a    loc_F008C088
F008C028: d0062010                 ld      [%i0+0x10], %o0
F008C02C: a2102000                 mov     0, %l1
F008C030: a4100014                 mov     %l4, %l2
F008C034: d0062008                 ld      [%i0+8], %o0
F008C038: d0020012                 ld      [%o0+%l2], %o0
F008C03C: a12c6002                 sll     %l1, 2, %l0
F008C040: d2020010                 ld      [%o0+%l0], %o1
F008C044: 90100015                 mov     %l5, %o0
F008C048: 7ffffb99                 call    sub_F008AEAC
F008C04C: d227bff4                 st      %o1, [%fp+var_C]
F008C050: d0062008                 ld      [%i0+8], %o0
F008C054: d0020012                 ld      [%o0+%l2], %o0
F008C058: d2020010                 ld      [%o0+%l0], %o1
F008C05C: a2046001                 inc     %l1
F008C060: 90100015                 mov     %l5, %o0
F008C064: 7fffffac                 call    sub_F008BF14
F008C068: d227bff4                 st      %o1, [%fp+var_C]
F008C06C: 80a4600f                 cmp     %l1, 0xF
F008C070: 08bffff2                 bleu    loc_F008C038
F008C074: d0062008                 ld      [%i0+8], %o0
F008C078: d0020014                 ld      [%o0+%l4], %o0
F008C07C: 7fff7049                 call    _kfree
F008C080: 92102040                 mov     0x40, %o1 ! '@'
F008C084: d0062010                 ld      [%i0+0x10], %o0
F008C088: a604e001                 inc     %l3
F008C08C: 90023fff                 inc     -1, %o0
F008C090: 91322004                 srl     %o0, 4, %o0
F008C094: 90022001                 inc     %o0
F008C098: 80a4c008                 cmp     %l3, %o0
F008C09C: 0abfffdf                 bcs     loc_F008C018
F008C0A0: a8052004                 inc     4, %l4
F008C0A4: d2062010                 ld      [%i0+0x10], %o1
F008C0A8: d0062008                 ld      [%i0+8], %o0
F008C0AC: 92027fff                 inc     -1, %o1
F008C0B0: 93326004                 srl     %o1, 4, %o1
F008C0B4: 1080001c                 ba      loc_F008C124
F008C0B8: 92026001                 inc     %o1
F008C0BC: a6102000                 mov     0, %l3
F008C0C0: 80a4c009                 cmp     %l3, %o1
F008C0C4: 36800014                 bge,a   loc_F008C114
F008C0C8: d2062010                 ld      [%i0+0x10], %o1
F008C0CC: a207bff4                 add     %fp, var_C, %l1
F008C0D0: d0062008                 ld      [%i0+8], %o0
F008C0D4: a12ce002                 sll     %l3, 2, %l0
F008C0D8: d2020010                 ld      [%o0+%l0], %o1
F008C0DC: 90100011                 mov     %l1, %o0
F008C0E0: 7ffffb73                 call    sub_F008AEAC
F008C0E4: d227bff4                 st      %o1, [%fp+var_C]
F008C0E8: d0062008                 ld      [%i0+8], %o0
F008C0EC: d2020010                 ld      [%o0+%l0], %o1
F008C0F0: 90100011                 mov     %l1, %o0
F008C0F4: 7fffff88                 call    sub_F008BF14
F008C0F8: d227bff4                 st      %o1, [%fp+var_C]
F008C0FC: d0062010                 ld      [%i0+0x10], %o0
F008C100: a604e001                 inc     %l3
F008C104: 80a4c008                 cmp     %l3, %o0
F008C108: 26bffff3                 bl,a    loc_F008C0D4
F008C10C: d0062008                 ld      [%i0+8], %o0
F008C110: d2062010                 ld      [%i0+0x10], %o1
F008C114: 80a26000                 cmp     %o1, 0
F008C118: 24800006                 ble,a   loc_F008C130
F008C11C: d005a00c                 ld      [%l6+0xC], %o0
F008C120: d0062008                 ld      [%i0+8], %o0
F008C124: 7fff701f                 call    _kfree
F008C128: 932a6002                 sll     %o1, 2, %o1
F008C12C: d005a00c                 ld      [%l6+0xC], %o0
F008C130: 90023fff                 inc     -1, %o0
F008C134: 1080000a                 ba      loc_F008C15C
F008C138: d025a00c                 st      %o0, [%l6+0xC]
F008C13C: 1300003f                 sethi   0xFC00, %o1
F008C140: d4122004                 lduh    [%o0+4], %o2
F008C144: 921263fd                 bset    0x3FD, %o1
F008C148: 940a8009                 and     %o2, %o1, %o2
F008C14C: d2020000                 ld      [%o0], %o1
F008C150: d4322004                 sth     %o2, [%o0+4]
F008C154: 7ffe7284                 call    _vn_rele
F008C158: c0224000                 clr     [%o1]
F008C15C: 133c0447                 sethi   %hi(dword_F0111EA8), %o1
F008C160: d00262a8                 ld      [%o1+%lo(dword_F0111EA8)], %o0
F008C164: a0102000                 mov     0, %l0
F008C168: 80a40008                 cmp     %l0, %o0
F008C16C: 16800010                 bge     loc_F008C1AC
F008C170: 113c04f6                 sethi   -0xFEC2800, %o0
F008C174: 113c04c3a61223b0         set     unk_F0130FB0, %l3
F008C17C: a4100009                 mov     %o1, %l2
F008C180: a2102000                 mov     0, %l1
F008C184: 9007bff4                 add     %fp, var_C, %o0
F008C188: d2044013                 ld      [%l1+%l3], %o1
F008C18C: a0042001                 inc     %l0
F008C190: 7fffff0f                 call    _vnode_pager_truncate
F008C194: d227bff4                 st      %o1, [%fp+var_C]
F008C198: d004a2a8                 ld      [%l2+0x2A8], %o0
F008C19C: 80a40008                 cmp     %l0, %o0
F008C1A0: 06bffff9                 bl      loc_F008C184
F008C1A4: a2046004                 inc     4, %l1
F008C1A8: 113c04f6                 sethi   -0xFEC2800, %o0
F008C1AC: d00221a0                 ld      [%o0+0x1A0], %o0
F008C1B0: 7fffb408                 call    _zfree
F008C1B4: 92100018                 mov     %i0, %o1
F008C1B8: 81c7e008                 ret
F008C1BC: 81e80000                 restore
