F007CFAC: 9de3bf90                 save    %sp, -0x70, %sp
F007CFB0: d0062004                 ld      [%i0+4], %o0
F007CFB4: 80a22018                 cmp     %o0, 0x18
F007CFB8: 12800008                 bne     loc_F007CFD8
F007CFBC: 90103ed0                 mov     -0x130, %o0
F007CFC0: d0060000                 ld      [%i0], %o0
F007CFC4: 23200000                 sethi   0x80000000, %l1
F007CFC8: 808a0011                 btst    %l1, %o0
F007CFCC: 02800005                 be      loc_F007CFE0
F007CFD0: 01000000                 nop
F007CFD4: 90103ed0                 mov     -0x130, %o0
F007CFD8: 1080001d                 ba      locret_F007D04C
F007CFDC: d026601c                 st      %o0, [%i1+0x1C]
F007CFE0: 7fffa100                 call    _convert_port_to_pset
F007CFE4: d0062008                 ld      [%i0+8], %o0! processor_set
F007CFE8: a0100008                 mov     %o0, %l0
F007CFEC: 9206602c                 add     %i1, 0x2C, %o1 ! ','! thread_list
F007CFF0: 7fffca43                 call    _processor_set_threads
F007CFF4: 9407bff4                 add     %fp, var_C, %o2
F007CFF8: d026601c                 st      %o0, [%i1+0x1C]
F007CFFC: 7fffc84f                 call    _pset_deallocate
F007D000: 90100010                 mov     %l0, %o0
F007D004: d006601c                 ld      [%i1+0x1C], %o0
F007D008: 80a22000                 cmp     %o0, 0
F007D00C: 12800010                 bne     locret_F007D04C
F007D010: 92102030                 mov     0x30, %o1 ! '0'
F007D014: d0064000                 ld      [%i1], %o0
F007D018: d2266004                 st      %o1, [%i1+4]
F007D01C: 90120011                 bset    %l1, %o0
F007D020: d0264000                 st      %o0, [%i1]
F007D024: 113c0444                 sethi   %hi(dword_F011110C), %o0
F007D028: d202210c                 ld      [%o0+%lo(dword_F011110C)], %o1
F007D02C: d2266020                 st      %o1, [%i1+0x20]
F007D030: 9012210c                 bset    %lo(dword_F011110C), %o0
F007D034: d2022004                 ld      [%o0+4], %o1
F007D038: d2266024                 st      %o1, [%i1+0x24]
F007D03C: d0022008                 ld      [%o0+8], %o0
F007D040: d207bff4                 ld      [%fp+var_C], %o1
F007D044: d0266028                 st      %o0, [%i1+0x28]
F007D048: d2266028                 st      %o1, [%i1+0x28]
F007D04C: 81c7e008                 ret
F007D050: 81e80000                 restore
