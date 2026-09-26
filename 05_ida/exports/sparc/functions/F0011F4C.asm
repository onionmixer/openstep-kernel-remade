F0011F4C: 9de3bf98                 save    %sp, -0x68, %sp
F0011F50: 113c04cf                 sethi   %hi(_active_u), %o0
F0011F54: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0011F58: 113c04d0                 sethi   %hi(_master_cpu), %o0
F0011F5C: d00220c8                 ld      [%o0+%lo(_master_cpu)], %o0
F0011F60: 80a22000                 cmp     %o0, 0
F0011F64: 02800005                 be      loc_F0011F78
F0011F68: e2024000                 ld      [%o1], %l1
F0011F6C: 113c042c                 sethi   %hi(aPsigNotOnMaste), %o0! "psig not on master"
F0011F70: 40000c80                 call    _panic
F0011F74: 90122278                 bset    %lo(aPsigNotOnMaste), %o0! "psig not on master"
F0011F78: a0046070                 add     %l1, 0x70, %l0 ! 'p'
F0011F7C: d0040000                 ld      [%l0], %o0
F0011F80: 80a22000                 cmp     %o0, 0
F0011F84: 12bffffe                 bne     loc_F0011F7C
F0011F88: 01000000                 nop
F0011F8C: 400213c7                 call    _simple_lock_try
F0011F90: 90100010                 mov     %l0, %o0
F0011F94: 80a22000                 cmp     %o0, 0
F0011F98: 02bffff9                 be      loc_F0011F7C
F0011F9C: 01000000                 nop
F0011FA0: 1080001f                 ba      loc_F001201C
F0011FA4: d0046074                 ld      [%l1+0x74], %o0
F0011FA8: c0246070                 clr     [%l1+0x70]
F0011FAC: 80a26000                 cmp     %o1, 0
F0011FB0: 02800009                 be      loc_F0011FD4
F0011FB4: a0046070                 add     %l1, 0x70, %l0 ! 'p'
F0011FB8: 113c04d0                 sethi   %hi(_active_threads), %o0
F0011FBC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0011FC0: 80a20009                 cmp     %o0, %o1
F0011FC4: 028000c4                 be      locret_F00122D4
F0011FC8: 01000000                 nop
F0011FCC: 40018ca4                 call    _thread_hold
F0011FD0: 01000000                 nop
F0011FD4: 400181bb                 call    _thread_block
F0011FD8: 01000000                 nop
F0011FDC: 113c04d0                 sethi   %hi(_active_threads), %o0
F0011FE0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0011FE4: d002218c                 ld      [%o0+0x18C], %o0
F0011FE8: 808a2003                 btst    3, %o0
F0011FEC: 128000ba                 bne     locret_F00122D4
F0011FF0: 01000000                 nop
F0011FF4: d0040000                 ld      [%l0], %o0
F0011FF8: 80a22000                 cmp     %o0, 0
F0011FFC: 12bffffe                 bne     loc_F0011FF4
F0012000: 01000000                 nop
F0012004: 400213a9                 call    _simple_lock_try
F0012008: 90100010                 mov     %l0, %o0
F001200C: 80a22000                 cmp     %o0, 0
F0012010: 02bffff9                 be      loc_F0011FF4
F0012014: 01000000                 nop
F0012018: d0046074                 ld      [%l1+0x74], %o0
F001201C: 80a22000                 cmp     %o0, 0
F0012020: 32bfffe2                 bne,a   loc_F0011FA8
F0012024: d2046078                 ld      [%l1+0x78], %o1
F0012028: d0046078                 ld      [%l1+0x78], %o0
F001202C: 80a22000                 cmp     %o0, 0
F0012030: 32bfffde                 bne,a   loc_F0011FA8
F0012034: d2046078                 ld      [%l1+0x78], %o1
F0012038: e44c6017                 ldsb    [%l1+0x17], %l2
F001203C: 90102001                 mov     1, %o0
F0012040: 9204bfff                 add     %l2, -1, %o1
F0012044: 80a4a000                 cmp     %l2, 0
F0012048: 02800080                 be      loc_F0012248! jumptable F00121F0 cases 14,15,18,19
F001204C: a72a0009                 sll     %o0, %o1, %l3
F0012050: 11000007901222f8         set     0x1EF8, %o0
F0012058: 808cc008                 btst    %o0, %l3
F001205C: 02800007                 be      loc_F0012078
F0012060: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0012064: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0012068: d04a2048                 ldsb    [%o0+0x48], %o0
F001206C: 80a48008                 cmp     %l2, %o0
F0012070: 12800076                 bne     loc_F0012248! jumptable F00121F0 cases 14,15,18,19
F0012074: 01000000                 nop
F0012078: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F001207C: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0012080: d24a6040                 ldsb    [%o1+0x40], %o1
F0012084: 808a6080                 btst    0x80, %o1
F0012088: 02800004                 be      loc_F0012098
F001208C: a01221dc                 or      %o0, %lo(dword_F0133DDC), %l0
F0012090: 4000034a                 call    _rpcont
F0012094: 01000000                 nop
F0012098: d2043ffc                 ld      [%l0-4], %o1
F001209C: 912ca002                 sll     %l2, 2, %o0
F00120A0: 90020009                 add     %o0, %o1, %o0
F00120A4: e8022030                 ld      [%o0+0x30], %l4
F00120A8: 80a52000                 cmp     %l4, 0
F00120AC: 02800047                 be      loc_F00121C8
F00120B0: 80a52001                 cmp     %l4, 1
F00120B4: 02800006                 be      loc_F00120CC
F00120B8: 90102004                 mov     4, %o0
F00120BC: d004601c                 ld      [%l1+0x1C], %o0
F00120C0: 808a0013                 btst    %l3, %o0
F00120C4: 02800005                 be      loc_F00120D8
F00120C8: 90102004                 mov     4, %o0! __x
F00120CC: 133c042c                 sethi   %hi(aPsigProcessing), %o1! "psig: processing masked or ignored sign"...
F00120D0: 400009b9                 call    _log
F00120D4: 92126290                 bset    %lo(aPsigProcessing), %o1! "psig: processing masked or ignored sign"...
F00120D8: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F00120DC: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F00120E0: a01261dc                 or      %o1, %lo(dword_F0133DDC), %l0
F00120E4: 400212a9                 call    _splusclock
F00120E8: c02a2038                 clrb    [%o0+0x38]
F00120EC: d2046028                 ld      [%l1+0x28], %o1
F00120F0: 11000400                 sethi   0x100000, %o0
F00120F4: 808a4008                 btst    %o0, %o1
F00120F8: 0280000d                 be      loc_F001212C
F00120FC: 9004bffc                 add     %l2, -4, %o0
F0012100: 80a22001                 cmp     %o0, 1
F0012104: 08800008                 bleu    loc_F0012124
F0012108: 932ca002                 sll     %l2, 2, %o1
F001210C: d0043ffc                 ld      [%l0-4], %o0
F0012110: 92024008                 add     %o1, %o0, %o1
F0012114: c0226030                 clr     [%o1+0x30]
F0012118: d0046024                 ld      [%l1+0x24], %o0
F001211C: 902a0013                 bclr    %l3, %o0
F0012120: d0246024                 st      %o0, [%l1+0x24]
F0012124: a6102000                 mov     0, %l3
F0012128: d2046028                 ld      [%l1+0x28], %o1
F001212C: 808a6200                 btst    0x200, %o1
F0012130: 22800007                 be,a    loc_F001214C
F0012134: ea04601c                 ld      [%l1+0x1C], %l5
F0012138: 113c04cf                 sethi   %hi(_active_u), %o0
F001213C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0012140: ea022140                 ld      [%o0+0x140], %l5
F0012144: 900a7dff                 and     %o1, -0x201, %o0
F0012148: d0246028                 st      %o0, [%l1+0x28]
F001214C: 213c04cf                 sethi   %hi(_active_u), %l0
F0012150: 932ca002                 sll     %l2, 2, %o1
F0012154: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F0012158: 9404bfff                 add     %l2, -1, %o2
F001215C: 92024008                 add     %o1, %o0, %o1
F0012160: 11000007901222f8         set     0x1EF8, %o0
F0012168: 913a000a                 sra     %o0, %o2, %o0
F001216C: d20260b4                 ld      [%o1+0xB4], %o1
F0012170: 808a2001                 btst    1, %o0
F0012174: d004601c                 ld      [%l1+0x1C], %o0
F0012178: 92124013                 bset    %l3, %o1
F001217C: 90120009                 bset    %o1, %o0
F0012180: d024601c                 st      %o0, [%l1+0x1C]
F0012184: c02c6017                 clrb    [%l1+0x17]
F0012188: 02800004                 be      loc_F0012198
F001218C: 901421d8                 or      %l0, %lo(_active_u), %o0
F0012190: d0022004                 ld      [%o0+4], %o0
F0012194: c02a2048                 clrb    [%o0+0x48]
F0012198: c0246070                 clr     [%l1+0x70]
F001219C: 400212d1                 call    _spl0
F00121A0: 01000000                 nop
F00121A4: d60421d8                 ld      [%l0+0x1D8], %o3
F00121A8: 90100014                 mov     %l4, %o0
F00121AC: d402e1a8                 ld      [%o3+0x1A8], %o2
F00121B0: 92100012                 mov     %l2, %o1
F00121B4: 9402a001                 inc     %o2
F00121B8: d422e1a8                 st      %o2, [%o3+0x1A8]
F00121BC: 400260b2                 call    _sendsig
F00121C0: 94100015                 mov     %l5, %o2
F00121C4: 30800044                 ba,a    locret_F00122D4
F00121C8: d0126240                 lduh    [%o1+0x240], %o0
F00121CC: 9404bffd                 add     %l2, -3, %o2
F00121D0: 80a2a013                 cmp     %o2, 0x13! switch 20 cases
F00121D4: 90122010                 bset    0x10, %o0
F00121D8: 18800032                 bgu     def_F00121F0! jumptable F00121F0 default case, cases 6,10-13,16,17
F00121DC: d0326240                 sth     %o0, [%o1+0x240]
F00121E0: 113c0048901221f8         set     jpt_F00121F0, %o0
F00121E8: 932aa002                 sll     %o2, 2, %o1
F00121EC: d0024008                 ld      [%o1+%o0], %o0
F00121F0: 81c20000                 jmp     %o0! switch jump
F00121F4: 01000000                 nop
F0012248: c0246070                 clr     [%l1+0x70]! jumptable F00121F0 cases 14,15,18,19
F001224C: 30800022                 ba,a    locret_F00122D4
F0012250: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0! jumptable F00121F0 cases 0-5,7-9
F0012254: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0012258: e4222004                 st      %l2, [%o0+4]
F001225C: 213c04d0                 sethi   %hi(_active_threads), %l0
F0012260: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F0012264: d0246078                 st      %o0, [%l1+0x78]
F0012268: c0246070                 clr     [%l1+0x70]
F001226C: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F0012270: 400184c5                 call    _task_hold
F0012274: d002200c                 ld      [%o0+0xC], %o0
F0012278: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F001227C: d002200c                 ld      [%o0+0xC], %o0
F0012280: 400184e7                 call    _task_dowait
F0012284: 92102000                 mov     0, %o1
F0012288: 7fffdff1                 call    _core
F001228C: 01000000                 nop
F0012290: 80a22000                 cmp     %o0, 0
F0012294: 3280000e                 bne,a   loc_F00122CC
F0012298: a404a080                 inc     0x80, %l2
F001229C: 3080000c                 ba,a    loc_F00122CC
F00122A0: 213c04d0                 sethi   %hi(_active_threads), %l0! jumptable F00121F0 default case, cases 6,10-13,16,17
F00122A4: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F00122A8: d0246078                 st      %o0, [%l1+0x78]
F00122AC: c0246070                 clr     [%l1+0x70]
F00122B0: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F00122B4: 400184b4                 call    _task_hold
F00122B8: d002200c                 ld      [%o0+0xC], %o0
F00122BC: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F00122C0: d002200c                 ld      [%o0+0xC], %o0! int
F00122C4: 400184d6                 call    _task_dowait
F00122C8: 92102000                 mov     0, %o1
F00122CC: 7fffe912                 call    _exit
F00122D0: 90100012                 mov     %l2, %o0
F00122D4: 81c7e008                 ret
F00122D8: 81e80000                 restore
