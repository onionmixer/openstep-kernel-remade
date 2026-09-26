F0083FF4: 9de3bf98                 save    %sp, -0x68, %sp
F0083FF8: 90102050                 mov     0x50, %o0 ! 'P'
F0083FFC: 13000064                 sethi   0x19000, %o1
F0084000: 94102000                 mov     0, %o2
F0084004: 96102000                 mov     0, %o3
F0084008: 193c0446                 sethi   %hi(aMaps), %o4! "maps"
F008400C: 7fffcfcb                 call    _zinit
F0084010: 98132228                 bset    %lo(aMaps), %o4! "maps"
F0084014: 253c04f4                 sethi   %hi(_vm_map_zone), %l2
F0084018: d024a388                 st      %o0, [%l2+%lo(_vm_map_zone)]
F008401C: 9010202c                 mov     0x2C, %o0 ! ','
F0084020: 13000400                 sethi   0x100000, %o1
F0084024: 94102000                 mov     0, %o2
F0084028: 96102000                 mov     0, %o3
F008402C: 193c0446                 sethi   %hi(aNonKernelMapEn), %o4! "non-kernel map entries"
F0084030: 7fffcfc2                 call    _zinit
F0084034: 98132230                 bset    %lo(aNonKernelMapEn), %o4! "non-kernel map entries"
F0084038: 133c04f4                 sethi   %hi(_vm_map_entry_zone), %o1
F008403C: d0226378                 st      %o0, [%o1+%lo(_vm_map_entry_zone)]
F0084040: 9010202c                 mov     0x2C, %o0 ! ','
F0084044: 94102000                 mov     0, %o2
F0084048: 96102000                 mov     0, %o3
F008404C: 233c04f4                 sethi   %hi(_kentry_data_size), %l1
F0084050: 193c0446                 sethi   %hi(aKernelMapEntri), %o4! "kernel map entries"
F0084054: d2046360                 ld      [%l1+%lo(_kentry_data_size)], %o1
F0084058: 7fffcfb8                 call    _zinit
F008405C: 98132248                 bset    %lo(aKernelMapEntri), %o4! "kernel map entries"
F0084060: 213c04f4                 sethi   %hi(_vm_map_kentry_zone), %l0
F0084064: d0242380                 st      %o0, [%l0+%lo(_vm_map_kentry_zone)]
F0084068: 92102000                 mov     0, %o1
F008406C: 94102000                 mov     0, %o2
F0084070: 96102000                 mov     0, %o3
F0084074: 7fffd4a3                 call    _zchange
F0084078: 98102000                 mov     0, %o4
F008407C: d004a388                 ld      [%l2+0x388], %o0
F0084080: 133c04f4                 sethi   %hi(_map_data), %o1
F0084084: d2026368                 ld      [%o1+%lo(_map_data)], %o1
F0084088: 153c04f4                 sethi   %hi(_map_data_size), %o2
F008408C: 7fffd00c                 call    _zcram
F0084090: d402a370                 ld      [%o2+%lo(_map_data_size)], %o2
F0084094: d0042380                 ld      [%l0+%lo(_vm_map_kentry_zone)], %o0
F0084098: 133c04f4                 sethi   %hi(_kentry_data), %o1
F008409C: d2026358                 ld      [%o1+%lo(_kentry_data)], %o1
F00840A0: 7fffd007                 call    _zcram
F00840A4: d4046360                 ld      [%l1+0x360], %o2
F00840A8: 81c7e008                 ret
F00840AC: 81e80000                 restore
