F00F1F84: 9de3bf98                 save    %sp, -0x68, %sp
F00F1F88: a4100018                 mov     %i0, %l2
F00F1F8C: 313c04cf                 sethi   %hi(dword_F0133CE8), %i0
F00F1F90: d00620e8                 ld      [%i0+%lo(dword_F0133CE8)], %o0
F00F1F94: 90022001                 inc     %o0
F00F1F98: d02620e8                 st      %o0, [%i0+%lo(dword_F0133CE8)]
F00F1F9C: 233c04cf                 sethi   %hi(dword_F0133CEC), %l1
F00F1FA0: d00460ec                 ld      [%l1+%lo(dword_F0133CEC)], %o0
F00F1FA4: 80a22000                 cmp     %o0, 0
F00F1FA8: 0280000e                 be      loc_F00F1FE0
F00F1FAC: 01000000                 nop
F00F1FB0: 7ffffa42                 call    __objc_create_zone
F00F1FB4: 01000000                 nop
F00F1FB8: 7ffffa40                 call    __objc_create_zone
F00F1FBC: a0100008                 mov     %o0, %l0
F00F1FC0: d40620e8                 ld      [%i0+%lo(dword_F0133CE8)], %o2
F00F1FC4: 9402a001                 inc     %o2
F00F1FC8: d6040000                 ld      [%l0], %o3
F00F1FCC: d20460ec                 ld      [%l1+%lo(dword_F0133CEC)], %o1
F00F1FD0: 9fc2c000                 call    %o3
F00F1FD4: 952aa002                 sll     %o2, 2, %o2
F00F1FD8: 1080000e                 ba      loc_F00F2010
F00F1FDC: d02460ec                 st      %o0, [%l1+%lo(dword_F0133CEC)]
F00F1FE0: 7ffffa36                 call    __objc_create_zone
F00F1FE4: 01000000                 nop
F00F1FE8: 7ffffa34                 call    __objc_create_zone
F00F1FEC: a0100008                 mov     %o0, %l0
F00F1FF0: 133c04cf                 sethi   %hi(dword_F0133CE8), %o1
F00F1FF4: d20260e8                 ld      [%o1+%lo(dword_F0133CE8)], %o1
F00F1FF8: 92026001                 inc     %o1
F00F1FFC: d4042004                 ld      [%l0+4], %o2
F00F2000: 9fc28000                 call    %o2
F00F2004: 932a6002                 sll     %o1, 2, %o1
F00F2008: 133c04cf                 sethi   %hi(dword_F0133CEC), %o1
F00F200C: d02260ec                 st      %o0, [%o1+%lo(dword_F0133CEC)]
F00F2010: 113c04cf                 sethi   %hi(dword_F0133CEC), %o0
F00F2014: d00220ec                 ld      [%o0+%lo(dword_F0133CEC)], %o0
F00F2018: 80a22000                 cmp     %o0, 0
F00F201C: 32800006                 bne,a   loc_F00F2034
F00F2020: 113c04cf                 sethi   -0xFECC400, %o0
F00F2024: 113c03f4                 sethi   %hi(aUnableToReallo), %o0! "unable to reallocate module vector"
F00F2028: 7ffffa78                 call    __objc_fatal
F00F202C: 901222c0                 bset    %lo(aUnableToReallo), %o0! "unable to reallocate module vector"
F00F2030: 113c04cf                 sethi   -0xFECC400, %o0
F00F2034: d20220e8                 ld      [%o0+0xE8], %o1
F00F2038: 113c04cf                 sethi   %hi(dword_F0133CEC), %o0
F00F203C: f00220ec                 ld      [%o0+%lo(dword_F0133CEC)], %i0
F00F2040: 932a6002                 sll     %o1, 2, %o1
F00F2044: 90024018                 add     %o1, %i0, %o0
F00F2048: e4223ffc                 st      %l2, [%o0-4]
F00F204C: c0260009                 clr     [%i0+%o1]
F00F2050: 81c7e008                 ret
F00F2054: 81e80000                 restore
