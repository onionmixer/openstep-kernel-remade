F00EE030: 9de3bf98                 save    %sp, -0x68, %sp
F00EE034: a4100018                 mov     %i0, %l2
F00EE038: 7ffc6500                 call    _strlen
F00EE03C: 90100012                 mov     %l2, %o0
F00EE040: a2022001                 add     %o0, 1, %l1
F00EE044: 80a460b4                 cmp     %l1, 0xB4
F00EE048: 08800009                 bleu    loc_F00EE06C
F00EE04C: 213c04bc                 sethi   -0xFED1000, %l0
F00EE050: 7ffde808                 call    _kalloc
F00EE054: 90100011                 mov     %l1, %o0! __dst
F00EE058: b0100008                 mov     %o0, %i0
F00EE05C: 92100012                 mov     %l2, %o1! __src
F00EE060: 7ffc67dc                 call    _memmove
F00EE064: 94100011                 mov     %l1, %o2! __len
F00EE068: 30800034                 ba,a    locret_F00EE138
F00EE06C: d0042094                 ld      [%l0+0x94], %o0
F00EE070: 80a22000                 cmp     %o0, 0
F00EE074: 12800007                 bne     loc_F00EE090
F00EE078: 113c04bc                 sethi   -0xFED1000, %o0
F00EE07C: 7ffdeb0d                 call    _simple_lock_alloc
F00EE080: 01000000                 nop
F00EE084: d0242094                 st      %o0, [%l0+0x94]
F00EE088: c0220000                 clr     [%o0]
F00EE08C: 113c04bc                 sethi   -0xFED1000, %o0
F00EE090: e0022094                 ld      [%o0+0x94], %l0
F00EE094: d0040000                 ld      [%l0], %o0
F00EE098: 80a22000                 cmp     %o0, 0
F00EE09C: 12bffffe                 bne     loc_F00EE094
F00EE0A0: 01000000                 nop
F00EE0A4: 7ffea381                 call    _simple_lock_try
F00EE0A8: 90100010                 mov     %l0, %o0
F00EE0AC: 80a22000                 cmp     %o0, 0
F00EE0B0: 02bffff9                 be      loc_F00EE094
F00EE0B4: 01000000                 nop
F00EE0B8: 213c04bc                 sethi   %hi(dword_F012F090), %l0
F00EE0BC: d0042090                 ld      [%l0+%lo(dword_F012F090)], %o0
F00EE0C0: 80a20011                 cmp     %o0, %l1
F00EE0C4: 1a80000d                 bcc     loc_F00EE0F8
F00EE0C8: 90046167                 add     %l1, 0x167, %o0
F00EE0CC: 7ffc614d                 call    _udiv
F00EE0D0: 92102168                 mov     0x168, %o1
F00EE0D4: 932a2001                 sll     %o0, 1, %o1
F00EE0D8: 92024008                 add     %o1, %o0, %o1
F00EE0DC: 912a6004                 sll     %o1, 4, %o0
F00EE0E0: 90220009                 sub     %o0, %o1, %o0
F00EE0E4: 912a2003                 sll     %o0, 3, %o0
F00EE0E8: 7ffde7e2                 call    _kalloc
F00EE0EC: d0242090                 st      %o0, [%l0+%lo(dword_F012F090)]
F00EE0F0: 133c04bc                 sethi   %hi(dword_F012F08C), %o1
F00EE0F4: d022608c                 st      %o0, [%o1+%lo(dword_F012F08C)]
F00EE0F8: 213c04bc                 sethi   %hi(dword_F012F08C), %l0
F00EE0FC: f004208c                 ld      [%l0+%lo(dword_F012F08C)], %i0
F00EE100: 90100018                 mov     %i0, %o0! __dst
F00EE104: 92100012                 mov     %l2, %o1! __src
F00EE108: 7ffc67b2                 call    _memmove
F00EE10C: 94100011                 mov     %l1, %o2
F00EE110: d004208c                 ld      [%l0+%lo(dword_F012F08C)], %o0
F00EE114: 90044008                 add     %l1, %o0, %o0
F00EE118: d024208c                 st      %o0, [%l0+%lo(dword_F012F08C)]
F00EE11C: 133c04bc                 sethi   %hi(dword_F012F090), %o1
F00EE120: d0026090                 ld      [%o1+%lo(dword_F012F090)], %o0
F00EE124: 90220011                 sub     %o0, %l1, %o0
F00EE128: d0226090                 st      %o0, [%o1+%lo(dword_F012F090)]
F00EE12C: 113c04bc                 sethi   %hi(dword_F012F094), %o0
F00EE130: d0022094                 ld      [%o0+%lo(dword_F012F094)], %o0
F00EE134: c0220000                 clr     [%o0]
F00EE138: 81c7e008                 ret
F00EE13C: 81e80000                 restore
