F00A3804: 9de3bf98                 save    %sp, -0x68, %sp
F00A3808: 7fffc64a                 call    _fpu_probe
F00A380C: 01000000                 nop
F00A3810: 133c04d1                 sethi   %hi(_machine_slot), %o1
F00A3814: 90102001                 mov     1, %o0
F00A3818: d0226360                 st      %o0, [%o1+%lo(_machine_slot)]
F00A381C: 92126360                 bset    %lo(_machine_slot), %o1
F00A3820: d022600c                 st      %o0, [%o1+0xC]
F00A3824: 113c044a                 sethi   %hi(_mod_info), %o0
F00A3828: d0022264                 ld      [%o0+%lo(_mod_info)], %o0
F00A382C: 9410200e                 mov     0xE, %o2
F00A3830: d4226004                 st      %o2, [%o1+4]
F00A3834: 113c04d1                 sethi   %hi(dword_F0134768), %o0
F00A3838: c0222368                 clr     [%o0+%lo(dword_F0134768)]
F00A383C: 81c7e008                 ret
F00A3840: 81e80000                 restore
