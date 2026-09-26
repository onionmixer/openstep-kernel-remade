F0071F88: 9de3bf98                 save    %sp, -0x68, %sp
F0071F8C: a2100018                 mov     %i0, %l1
F0071F90: d0066108                 ld      [%i1+0x108], %o0
F0071F94: 80a22000                 cmp     %o0, 0
F0071F98: 0480002e                 ble     loc_F0072050
F0071F9C: a0100019                 mov     %i1, %l0
F0071FA0: d2066104                 ld      [%i1+0x104], %o1
F0071FA4: 912a6003                 sll     %o1, 3, %o0
F0071FA8: 80a26000                 cmp     %o1, 0
F0071FAC: 06800026                 bl      loc_F0072044
F0071FB0: 94064008                 add     %i1, %o0, %o2
F0071FB4: f0028000                 ld      [%o2], %i0
F0071FB8: 80a28018                 cmp     %o2, %i0
F0071FBC: 0280001f                 be      loc_F0072038
F0071FC0: 80a6000a                 cmp     %i0, %o2
F0071FC4: 32800004                 bne,a   loc_F0071FD4
F0071FC8: d0060000                 ld      [%i0], %o0
F0071FCC: 10800005                 ba      loc_F0071FE0
F0071FD0: b0102000                 mov     0, %i0
F0071FD4: d4222004                 st      %o2, [%o0+4]
F0071FD8: d0060000                 ld      [%i0], %o0
F0071FDC: d0228000                 st      %o0, [%o2]
F0071FE0: c0262008                 clr     [%i0+8]
F0071FE4: d0042108                 ld      [%l0+0x108], %o0
F0071FE8: 90023fff                 inc     -1, %o0
F0071FEC: 80a22000                 cmp     %o0, 0
F0071FF0: 0480000f                 ble     loc_F007202C
F0071FF4: d0242108                 st      %o0, [%l0+0x108]
F0071FF8: d0066168                 ld      [%i1+0x168], %o0
F0071FFC: 808a2002                 btst    2, %o0
F0072000: 2280000c                 be,a    loc_F0072030
F0072004: d2242104                 st      %o1, [%l0+0x104]
F0072008: d0028000                 ld      [%o2], %o0
F007200C: 80a28008                 cmp     %o2, %o0
F0072010: 32800008                 bne,a   loc_F0072030
F0072014: d2242104                 st      %o1, [%l0+0x104]
F0072018: 9402bff8                 inc     -8, %o2
F007201C: d0028000                 ld      [%o2], %o0
F0072020: 80a28008                 cmp     %o2, %o0
F0072024: 02bffffd                 be      loc_F0072018
F0072028: 92027fff                 inc     -1, %o1
F007202C: d2242104                 st      %o1, [%l0+0x104]
F0072030: c0242100                 clr     [%l0+0x100]
F0072034: 30800035                 ba,a    locret_F0072108
F0072038: 92827fff                 inccc   -1, %o1
F007203C: 1cbfffde                 bpos    loc_F0071FB4
F0072040: 9402bff8                 inc     -8, %o2
F0072044: 113c0441                 sethi   %hi(aChoosePsetThre), %o0! "choose_pset_thread"
F0072048: 7ffe8c4a                 call    _panic
F007204C: 90122170                 bset    %lo(aChoosePsetThre), %o0! "choose_pset_thread"
F0072050: c0242100                 clr     [%l0+0x100]
F0072054: a0066118                 add     %i1, 0x118, %l0
F0072058: d0040000                 ld      [%l0], %o0
F007205C: 80a22000                 cmp     %o0, 0
F0072060: 12bffffe                 bne     loc_F0072058
F0072064: 01000000                 nop
F0072068: 40009390                 call    _simple_lock_try
F007206C: 90100010                 mov     %l0, %o0
F0072070: 80a22000                 cmp     %o0, 0
F0072074: 02bffff9                 be      loc_F0072058
F0072078: 01000000                 nop
F007207C: d0046114                 ld      [%l1+0x114], %o0
F0072080: 80a22001                 cmp     %o0, 1
F0072084: 1280001f                 bne     loc_F0072100
F0072088: 90102002                 mov     2, %o0
F007208C: 133c04d8                 sethi   %hi(_master_processor), %o1
F0072090: d20263d0                 ld      [%o1+%lo(_master_processor)], %o1
F0072094: 80a44009                 cmp     %l1, %o1
F0072098: 1280000d                 bne     loc_F00720CC
F007209C: d0246114                 st      %o0, [%l1+0x114]
F00720A0: d2066110                 ld      [%i1+0x110], %o1
F00720A4: 9006610c                 add     %i1, 0x10C, %o0
F00720A8: 80a20009                 cmp     %o0, %o1
F00720AC: 32800003                 bne,a   loc_F00720B8
F00720B0: e222610c                 st      %l1, [%o1+0x10C]
F00720B4: e226610c                 st      %l1, [%i1+0x10C]
F00720B8: d2246110                 st      %o1, [%l1+0x110]
F00720BC: 9006610c                 add     %i1, 0x10C, %o0
F00720C0: d024610c                 st      %o0, [%l1+0x10C]
F00720C4: 1080000c                 ba      loc_F00720F4
F00720C8: e2266110                 st      %l1, [%i1+0x110]
F00720CC: d206610c                 ld      [%i1+0x10C], %o1
F00720D0: 9006610c                 add     %i1, 0x10C, %o0
F00720D4: 80a20009                 cmp     %o0, %o1
F00720D8: 32800003                 bne,a   loc_F00720E4
F00720DC: e2226110                 st      %l1, [%o1+0x110]
F00720E0: e2266110                 st      %l1, [%i1+0x110]
F00720E4: d224610c                 st      %o1, [%l1+0x10C]
F00720E8: 9006610c                 add     %i1, 0x10C, %o0
F00720EC: d0246110                 st      %o0, [%l1+0x110]
F00720F0: e226610c                 st      %l1, [%i1+0x10C]
F00720F4: d0066114                 ld      [%i1+0x114], %o0
F00720F8: 90022001                 inc     %o0
F00720FC: d0266114                 st      %o0, [%i1+0x114]
F0072100: c0266118                 clr     [%i1+0x118]
F0072104: f004611c                 ld      [%l1+0x11C], %i0
F0072108: 81c7e008                 ret
F007210C: 81e80000                 restore
