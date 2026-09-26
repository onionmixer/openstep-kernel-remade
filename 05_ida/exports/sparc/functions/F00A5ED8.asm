F00A5ED8: 9de3bf98                 save    %sp, -0x68, %sp
F00A5EDC: 213c0466                 sethi   %hi(_nofault), %l0
F00A5EE0: d0042144                 ld      [%l0+%lo(_nofault)], %o0
F00A5EE4: 80a22000                 cmp     %o0, 0
F00A5EE8: 02800004                 be      loc_F00A5EF8
F00A5EEC: 133c0466                 sethi   %hi(_pokefault), %o1
F00A5EF0: 90102001                 mov     1, %o0
F00A5EF4: d0226148                 st      %o0, [%o1+%lo(_pokefault)]
F00A5EF8: 111e0000                 sethi   0x78000000, %o0
F00A5EFC: 808e0008                 btst    %o0, %i0
F00A5F00: 32800008                 bne,a   loc_F00A5F20
F00A5F04: 11040000                 sethi   0x10000000, %o0
F00A5F08: 113c0466                 sethi   %hi(aLevel15ErrorWa), %o0! "Level 15 Error: Watchdog Reset\n"
F00A5F0C: 7ffdb9d3                 call    _printf
F00A5F10: 90122240                 bset    %lo(aLevel15ErrorWa), %o0! "Level 15 Error: Watchdog Reset\n"
F00A5F14: 40002750                 call    _prom_stopcpu
F00A5F18: 90102000                 mov     0, %o0
F00A5F1C: 11040000                 sethi   0x10000000, %o0
F00A5F20: 808e0008                 btst    %o0, %i0
F00A5F24: 02800005                 be      loc_F00A5F38
F00A5F28: 11080000                 sethi   0x20000000, %o0
F00A5F2C: 400000a7                 call    _l15_ecc_async_flt
F00A5F30: 01000000                 nop
F00A5F34: 11080000                 sethi   0x20000000, %o0
F00A5F38: 808e0008                 btst    %o0, %i0
F00A5F3C: 02800005                 be      loc_F00A5F50
F00A5F40: 11100000                 sethi   0x40000000, %o0
F00A5F44: 400000ed                 call    _l15_mts_async_flt
F00A5F48: 01000000                 nop
F00A5F4C: 11100000                 sethi   0x40000000, %o0
F00A5F50: 808e0008                 btst    %o0, %i0
F00A5F54: 02800004                 be      loc_F00A5F64
F00A5F58: 113c0466                 sethi   %hi(_module_error), %o0
F00A5F5C: 7fffc3d3                 call    _simple_lock_try
F00A5F60: 9012214c                 bset    %lo(_module_error), %o0
F00A5F64: 113c0466                 sethi   %hi(_module_error), %o0
F00A5F68: d002214c                 ld      [%o0+%lo(_module_error)], %o0
F00A5F6C: 80a22000                 cmp     %o0, 0
F00A5F70: 02800005                 be      loc_F00A5F84
F00A5F74: d0042144                 ld      [%l0+0x144], %o0
F00A5F78: 40000106                 call    _l15_mod_async_flt
F00A5F7C: 01000000                 nop
F00A5F80: d0042144                 ld      [%l0+0x144], %o0
F00A5F84: 80a22000                 cmp     %o0, 0
F00A5F88: 1280005e                 bne     locret_F00A6100
F00A5F8C: 113c0466                 sethi   %hi(_system_fatal), %o0
F00A5F90: d0022150                 ld      [%o0+%lo(_system_fatal)], %o0
F00A5F94: 80a22000                 cmp     %o0, 0
F00A5F98: 0280005a                 be      locret_F00A6100
F00A5F9C: 133c04fb                 sethi   %hi(dword_F013EC74), %o1
F00A5FA0: e2026074                 ld      [%o1+%lo(dword_F013EC74)], %l1
F00A5FA4: 92126074                 bset    %lo(dword_F013EC74), %o1
F00A5FA8: e4026004                 ld      [%o1+4], %l2
F00A5FAC: e6026008                 ld      [%o1+8], %l3
F00A5FB0: ea02600c                 ld      [%o1+0xC], %l5
F00A5FB4: e8026010                 ld      [%o1+0x10], %l4
F00A5FB8: 113c0466                 sethi   %hi(aFatalSystemFau), %o0! "fatal system fault: sipr=%x\n"
F00A5FBC: e0127ffc                 lduh    [%o1-4], %l0
F00A5FC0: 90122260                 bset    %lo(aFatalSystemFau), %o0! "fatal system fault: sipr=%x\n"
F00A5FC4: 7ffdb9a5                 call    _printf
F00A5FC8: 92100018                 mov     %i0, %o1
F00A5FCC: 80a42002                 cmp     %l0, 2
F00A5FD0: 2280001b                 be,a    loc_F00A603C
F00A5FD4: 133c0466                 sethi   -0xFEE6800, %o1
F00A5FD8: 18800006                 bgu     loc_F00A5FF0
F00A5FDC: 80a42001                 cmp     %l0, 1
F00A5FE0: 22800009                 be,a    loc_F00A6004
F00A5FE4: 113c0466                 sethi   -0xFEE6800, %o0
F00A5FE8: 10800038                 ba      loc_F00A60C8
F00A5FEC: 113c0466                 sethi   -0xFEE6800, %o0
F00A5FF0: 80a42004                 cmp     %l0, 4
F00A5FF4: 22800029                 be,a    loc_F00A6098
F00A5FF8: 113c0466                 sethi   -0xFEE6800, %o0
F00A5FFC: 10800033                 ba      loc_F00A60C8
F00A6000: 113c0466                 sethi   -0xFEE6800, %o0! char *
F00A6004: 7ffdb995                 call    _printf
F00A6008: 90122280                 bset    0x280, %o0
F00A600C: 113c0466901222a0         set     aAfsrXAfarX, %o0! "afsr=%x afar=%x\n"
F00A6014: 92100011                 mov     %l1, %o1
F00A6018: 7ffdb990                 call    _printf
F00A601C: 94100012                 mov     %l2, %o2
F00A6020: 90100011                 mov     %l1, %o0
F00A6024: 92100012                 mov     %l2, %o1
F00A6028: 94100015                 mov     %l5, %o2
F00A602C: 7fffbdbf                 call    _mmu_log_module_err
F00A6030: 96100014                 mov     %l4, %o3
F00A6034: 1080002f                 ba      loc_F00A60F0
F00A6038: 113c0466                 sethi   -0xFEE6800, %o0
F00A603C: 90102001                 mov     1, %o0
F00A6040: d0226154                 st      %o0, [%o1+0x154]
F00A6044: 90100011                 mov     %l1, %o0
F00A6048: 92100012                 mov     %l2, %o1
F00A604C: 94100013                 mov     %l3, %o2
F00A6050: 40000275                 call    _log_mem_err
F00A6054: 96102000                 mov     0, %o3
F00A6058: 113c0466                 sethi   %hi(aControlRegiste), %o0! "Control Registers:\n"
F00A605C: 7ffdb97f                 call    _printf
F00A6060: 901222b8                 bset    %lo(aControlRegiste), %o0! "Control Registers:\n"
F00A6064: 113c0466901222d0         set     aEfsr0xXEfar00x, %o0! "\tefsr = 0x%x, efar0 = 0x%x "
F00A606C: 92100011                 mov     %l1, %o1
F00A6070: 7ffdb97a                 call    _printf
F00A6074: 94100012                 mov     %l2, %o2
F00A6078: 113c0466901222f0         set     aEfar10xX, %o0! "efar1 = 0x%x\n"
F00A6080: 7ffdb976                 call    _printf
F00A6084: 92100013                 mov     %l3, %o1
F00A6088: 113c0466                 sethi   %hi(aMemoryError), %o0! "memory error"
F00A608C: 7ffdbc39                 call    _panic
F00A6090: 90122300                 bset    %lo(aMemoryError), %o0! "memory error"
F00A6094: 113c0466                 sethi   -0xFEE6800, %o0! char *
F00A6098: 7ffdb970                 call    _printf
F00A609C: 90122310                 bset    0x310, %o0
F00A60A0: 113c046690122330         set     aAfsrXAfarX_0, %o0! "afsr=%x afar=%x\n"
F00A60A8: 92100011                 mov     %l1, %o1
F00A60AC: 7ffdb96b                 call    _printf
F00A60B0: 94100012                 mov     %l2, %o2
F00A60B4: 90100011                 mov     %l1, %o0
F00A60B8: 4000015e                 call    _log_mtos_err
F00A60BC: 92100012                 mov     %l2, %o1
F00A60C0: 1080000c                 ba      loc_F00A60F0
F00A60C4: 113c0466                 sethi   -0xFEE6800, %o0
F00A60C8: 90122348                 bset    0x348, %o0! char *
F00A60CC: 7ffdb963                 call    _printf
F00A60D0: 92100010                 mov     %l0, %o1
F00A60D4: 113c046690122360         set     aAfsrXAfarXX, %o0! "afsr=%x afar=%x,%x\n"
F00A60DC: 92100011                 mov     %l1, %o1
F00A60E0: 94100012                 mov     %l2, %o2
F00A60E4: 7ffdb95d                 call    _printf
F00A60E8: 96100013                 mov     %l3, %o3
F00A60EC: 113c0466                 sethi   -0xFEE6800, %o0! char *
F00A60F0: 7ffdbc20                 call    _panic
F00A60F4: 90122378                 bset    0x378, %o0
F00A60F8: 113c0466                 sethi   %hi(_system_fatal), %o0
F00A60FC: c0222150                 clr     [%o0+%lo(_system_fatal)]
F00A6100: 81c7e008                 ret
F00A6104: 81e80000                 restore
