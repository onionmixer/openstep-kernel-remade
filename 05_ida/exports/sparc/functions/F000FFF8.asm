F000FFF8: 9de3bf98                 save    %sp, -0x68, %sp
F000FFFC: 133c04cf                 sethi   %hi(_active_u), %o1
F0010000: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F0010004: d002201c                 ld      [%o0+0x1C], %o0
F0010008: d6522002                 ldsh    [%o0+2], %o3
F001000C: 80a2e000                 cmp     %o3, 0
F0010010: 0280000f                 be      loc_F001004C
F0010014: 921261d8                 bset    %lo(_active_u), %o1
F0010018: d4522006                 ldsh    [%o0+6], %o2
F001001C: 80a2a000                 cmp     %o2, 0
F0010020: 0280000c                 be      loc_F0010050
F0010024: 80a66014                 cmp     %i1, 0x14
F0010028: d056202c                 ldsh    [%i0+0x2C], %o0
F001002C: 80a2c008                 cmp     %o3, %o0
F0010030: 02800007                 be      loc_F001004C
F0010034: 80a28008                 cmp     %o2, %o0
F0010038: 02800005                 be      loc_F001004C
F001003C: 90102001                 mov     1, %o0
F0010040: d2026004                 ld      [%o1+4], %o1
F0010044: 1080004c                 ba      locret_F0010174
F0010048: d02a6038                 stb     %o0, [%o1+0x38]
F001004C: 80a66014                 cmp     %i1, 0x14
F0010050: 34800002                 bg,a    loc_F0010058
F0010054: b2102014                 mov     0x14, %i1
F0010058: 80a67fec                 cmp     %i1, -0x14
F001005C: 26800002                 bl,a    loc_F0010064
F0010060: b2103fec                 mov     -0x14, %i1
F0010064: d04e2015                 ldsb    [%i0+0x15], %o0
F0010068: 80a64008                 cmp     %i1, %o0
F001006C: 36800010                 bge,a   loc_F00100AC
F0010070: e0062068                 ld      [%i0+0x68], %l0
F0010074: 7ffffe3e                 call    _suser
F0010078: 01000000                 nop
F001007C: 80a22000                 cmp     %o0, 0
F0010080: 3280000b                 bne,a   loc_F00100AC
F0010084: e0062068                 ld      [%i0+0x68], %l0
F0010088: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F001008C: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0010090: 9010200d                 mov     0xD, %o0
F0010094: 10800038                 ba      locret_F0010174
F0010098: d02a6038                 stb     %o0, [%o1+0x38]
F001009C: d20221dc                 ld      [%o0+0x1DC], %o1
F00100A0: 90102001                 mov     1, %o0
F00100A4: 10800033                 ba      loc_F0010170
F00100A8: d02a6038                 stb     %o0, [%o1+0x38]
F00100AC: 94102000                 mov     0, %o2
F00100B0: d60e2015                 ldub    [%i0+0x15], %o3
F00100B4: 90100010                 mov     %l0, %o0
F00100B8: 972ae018                 sll     %o3, 24, %o3
F00100BC: 933ae018                 sra     %o3, 24, %o1
F00100C0: 9732e01f                 srl     %o3, 31, %o3
F00100C4: 9202400b                 add     %o1, %o3, %o1
F00100C8: d8042048                 ld      [%l0+0x48], %o4
F00100CC: 933a6001                 sra     %o1, 1, %o1
F00100D0: f22e2015                 stb     %i1, [%i0+0x15]
F00100D4: 98030009                 add     %o4, %o1, %o4
F00100D8: 9336601f                 srl     %i1, 31, %o1
F00100DC: 92064009                 add     %i1, %o1, %o1
F00100E0: 933a6001                 sra     %o1, 1, %o1
F00100E4: b2230009                 sub     %o4, %o1, %i1
F00100E8: 40018f7e                 call    _task_priority
F00100EC: 92100019                 mov     %i1, %o1
F00100F0: d0040000                 ld      [%l0], %o0
F00100F4: 80a22000                 cmp     %o0, 0
F00100F8: 12bffffe                 bne     loc_F00100F0
F00100FC: 01000000                 nop
F0010100: 40021b6a                 call    _simple_lock_try
F0010104: 90100010                 mov     %l0, %o0
F0010108: 80a22000                 cmp     %o0, 0
F001010C: 02bffff9                 be      loc_F00100F0
F0010110: 9004201c                 add     %l0, 0x1C, %o0
F0010114: f004201c                 ld      [%l0+0x1C], %i0
F0010118: 80a20018                 cmp     %o0, %i0
F001011C: 02800015                 be      loc_F0010170
F0010120: 01000000                 nop
F0010124: a2100008                 mov     %o0, %l1
F0010128: d0062054                 ld      [%i0+0x54], %o0
F001012C: 80a64008                 cmp     %i1, %o0
F0010130: 04800005                 ble     loc_F0010144
F0010134: 90100018                 mov     %i0, %o0
F0010138: d2062190                 ld      [%i0+0x190], %o1
F001013C: 400196ef                 call    _thread_max_priority
F0010140: 94100019                 mov     %i1, %o2
F0010144: 90100018                 mov     %i0, %o0
F0010148: 92100019                 mov     %i1, %o1
F001014C: 400196a3                 call    _thread_priority
F0010150: 94102001                 mov     1, %o2
F0010154: 80a22000                 cmp     %o0, 0
F0010158: 32bfffd1                 bne,a   loc_F001009C
F001015C: 113c04cf                 sethi   -0xFECC400, %o0
F0010160: f0062010                 ld      [%i0+0x10], %i0
F0010164: 80a44018                 cmp     %l1, %i0
F0010168: 32bffff1                 bne,a   loc_F001012C
F001016C: d0062054                 ld      [%i0+0x54], %o0
F0010170: c0240000                 clr     [%l0]
F0010174: 81c7e008                 ret
F0010178: 81e80000                 restore
