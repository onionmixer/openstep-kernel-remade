F000EFEC: 9de3bf58                 save    %sp, -0xA8, %sp! int
F000EFF0: 133c04cf901261dc         set     dword_F0133DDC, %o0
F000EFF8: d0023ffc                 ld      [%o0-4], %o0
F000EFFC: d20261dc                 ld      [%o1+0x1DC], %o1
F000F000: d002201c                 ld      [%o0+0x1C], %o0
F000F004: e0026024                 ld      [%o1+0x24], %l0
F000F008: 9402202a                 add     %o0, 0x2A, %o2 ! '*'
F000F00C: 9002200a                 inc     0xA, %o0
F000F010: 80a28008                 cmp     %o2, %o0
F000F014: 0880000d                 bleu    loc_F000F048
F000F018: 113c04cf                 sethi   %hi(_active_u), %o0
F000F01C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000F020: d002201c                 ld      [%o0+0x1C], %o0
F000F024: 9202200a                 add     %o0, 0xA, %o1
F000F028: d052bffe                 ldsh    [%o2-2], %o0
F000F02C: 80a23fff                 cmp     %o0, -1
F000F030: 12800007                 bne     loc_F000F04C
F000F034: 173c04cf                 sethi   -0xFECC400, %o3
F000F038: 9402bffe                 inc     -2, %o2
F000F03C: 80a28009                 cmp     %o2, %o1
F000F040: 38bffffb                 bgu,a   loc_F000F02C
F000F044: d052bffe                 ldsh    [%o2-2], %o0
F000F048: 173c04cf                 sethi   -0xFECC400, %o3
F000F04C: d002e1d8                 ld      [%o3+0x1D8], %o0
F000F050: d202201c                 ld      [%o0+0x1C], %o1
F000F054: 9002bff6                 add     %o2, -0xA, %o0
F000F058: 90220009                 sub     %o0, %o1, %o0
F000F05C: d2040000                 ld      [%l0], %o1
F000F060: 953a2001                 sra     %o0, 1, %o2
F000F064: 80a2400a                 cmp     %o1, %o2
F000F068: 1a800006                 bcc     loc_F000F080
F000F06C: a212e1d8                 or      %o3, 0x1D8, %l1
F000F070: d2046004                 ld      [%l1+4], %o1
F000F074: 90102016                 mov     0x16, %o0
F000F078: 10800031                 ba      locret_F000F13C
F000F07C: d02a6038                 stb     %o0, [%o1+0x38]
F000F080: d4240000                 st      %o2, [%l0]
F000F084: d802e1d8                 ld      [%o3+0x1D8], %o4! int
F000F088: d0030000                 ld      [%o4], %o0
F000F08C: d2022014                 ld      [%o0+0x14], %o1
F000F090: 11000010                 sethi   0x4000, %o0
F000F094: 808a4008                 btst    %o0, %o1
F000F098: 02800009                 be      loc_F000F0BC
F000F09C: 9607bfb8                 add     %fp, var_48, %o3! int
F000F0A0: d003201c                 ld      [%o4+0x1C], %o0! int
F000F0A4: 952aa001                 sll     %o2, 1, %o2! int
F000F0A8: d2042004                 ld      [%l0+4], %o1! int
F000F0AC: 40022408                 call    _copyout
F000F0B0: 9002200a                 inc     0xA, %o0
F000F0B4: 10800019                 ba      loc_F000F118
F000F0B8: d2046004                 ld      [%l1+4], %o1
F000F0BC: d203201c                 ld      [%o4+0x1C], %o1
F000F0C0: 912aa002                 sll     %o2, 2, %o0
F000F0C4: 9002c008                 add     %o3, %o0, %o0
F000F0C8: 80a2c008                 cmp     %o3, %o0
F000F0CC: 9402600a                 add     %o1, 0xA, %o2
F000F0D0: 1a80000b                 bcc     loc_F000F0FC
F000F0D4: 9210000b                 mov     %o3, %o1
F000F0D8: d0528000                 ldsh    [%o2], %o0
F000F0DC: d022c000                 st      %o0, [%o3]
F000F0E0: d0040000                 ld      [%l0], %o0
F000F0E4: 9602e004                 inc     4, %o3! int
F000F0E8: 912a2002                 sll     %o0, 2, %o0
F000F0EC: 90024008                 add     %o1, %o0, %o0
F000F0F0: 80a2c008                 cmp     %o3, %o0
F000F0F4: 0abffff9                 bcs     loc_F000F0D8
F000F0F8: 9402a002                 inc     2, %o2
F000F0FC: d4040000                 ld      [%l0], %o2! int
F000F100: 9007bfb8                 add     %fp, var_48, %o0! int
F000F104: d2042004                 ld      [%l0+4], %o1! int
F000F108: 400223f1                 call    _copyout
F000F10C: 952aa002                 sll     %o2, 2, %o2
F000F110: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000F114: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F000F118: d02a6038                 stb     %o0, [%o1+0x38]
F000F11C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000F120: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000F124: d04a6038                 ldsb    [%o1+0x38], %o0
F000F128: 80a22000                 cmp     %o0, 0
F000F12C: 12800004                 bne     locret_F000F13C
F000F130: 01000000                 nop
F000F134: d0040000                 ld      [%l0], %o0
F000F138: d0226030                 st      %o0, [%o1+0x30]
F000F13C: 81c7e008                 ret
F000F140: 81e80000                 restore
