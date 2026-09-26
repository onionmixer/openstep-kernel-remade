F006AE50: 9de3bf98                 save    %sp, -0x68, %sp
F006AE54: d206600c                 ld      [%i1+0xC], %o1
F006AE58: 113c04d0                 sethi   %hi(_active_threads), %o0
F006AE5C: 80a26000                 cmp     %o1, 0
F006AE60: 02800004                 be      loc_F006AE70
F006AE64: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F006AE68: 10800025                 ba      locret_F006AEFC
F006AE6C: b0102004                 mov     4, %i0
F006AE70: 90100011                 mov     %l1, %o0
F006AE74: a0062008                 add     %i0, 8, %l0
F006AE78: 92100010                 mov     %l0, %o1
F006AE7C: d4062004                 ld      [%i0+4], %o2
F006AE80: 96066008                 add     %i1, 8, %o3
F006AE84: 40000075                 call    sub_F006B058
F006AE88: 9402bff8                 inc     -8, %o2
F006AE8C: 80a22000                 cmp     %o0, 0
F006AE90: 3280001b                 bne,a   locret_F006AEFC
F006AE94: b0100008                 mov     %o0, %i0
F006AE98: 90100011                 mov     %l1, %o0
F006AE9C: 92100010                 mov     %l0, %o1
F006AEA0: d4062004                 ld      [%i0+4], %o2
F006AEA4: 96066004                 add     %i1, 4, %o3
F006AEA8: 40000087                 call    sub_F006B0C4
F006AEAC: 9402bff8                 inc     -8, %o2
F006AEB0: 80a22000                 cmp     %o0, 0
F006AEB4: 32800012                 bne,a   locret_F006AEFC
F006AEB8: b0100008                 mov     %o0, %i0
F006AEBC: 90100011                 mov     %l1, %o0
F006AEC0: d4062004                 ld      [%i0+4], %o2
F006AEC4: 92100010                 mov     %l0, %o1
F006AEC8: 4000004a                 call    sub_F006AFF0
F006AECC: 9402bff8                 inc     -8, %o2
F006AED0: 80a22000                 cmp     %o0, 0
F006AED4: 1280000a                 bne     locret_F006AEFC
F006AED8: b0100008                 mov     %o0, %i0
F006AEDC: b0102000                 mov     0, %i0
F006AEE0: d0066010                 ld      [%i1+0x10], %o0
F006AEE4: 13200000                 sethi   0x80000000, %o1
F006AEE8: 90120009                 bset    %o1, %o0
F006AEEC: d206600c                 ld      [%i1+0xC], %o1
F006AEF0: d0266010                 st      %o0, [%i1+0x10]
F006AEF4: 92026001                 inc     %o1
F006AEF8: d226600c                 st      %o1, [%i1+0xC]
F006AEFC: 81c7e008                 ret
F006AF00: 81e80000                 restore
