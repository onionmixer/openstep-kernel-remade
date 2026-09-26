F007AC94: 9de3bf98                 save    %sp, -0x68, %sp
F007AC98: 113c04d0                 sethi   %hi(_page_mask), %o0
F007AC9C: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F007ACA0: b32e6005                 sll     %i1, 5, %i1
F007ACA4: b2064008                 add     %i1, %o0, %i1
F007ACA8: 902e4008                 andn    %i1, %o0, %o0
F007ACAC: 7fffb4f1                 call    _kalloc
F007ACB0: a1322005                 srl     %o0, 5, %l0
F007ACB4: d0260000                 st      %o0, [%i0]
F007ACB8: a12c2005                 sll     %l0, 5, %l0
F007ACBC: 90020010                 add     %o0, %l0, %o0
F007ACC0: d0262008                 st      %o0, [%i0+8]
F007ACC4: d2060000                 ld      [%i0], %o1
F007ACC8: 113c0443                 sethi   %hi(aKernServLogIni), %o0! "kern_serv_log_init: log 0x%x log.last 0"...
F007ACCC: d4062008                 ld      [%i0+8], %o2
F007ACD0: 90122200                 bset    %lo(aKernServLogIni), %o0! "kern_serv_log_init: log 0x%x log.last 0"...
F007ACD4: d6060000                 ld      [%i0], %o3
F007ACD8: d2262004                 st      %o1, [%i0+4]
F007ACDC: 7ffe665f                 call    _printf
F007ACE0: 92100018                 mov     %i0, %o1
F007ACE4: 81c7e008                 ret
F007ACE8: 81e80000                 restore
