F00B8864: 9de3bf98                 save    %sp, -0x68, %sp
F00B8868: 213c04c5                 sethi   %hi(dword_F013179C), %l0
F00B886C: d004239c                 ld      [%l0+%lo(dword_F013179C)], %o0
F00B8870: 80a22000                 cmp     %o0, 0
F00B8874: 12800015                 bne     locret_F00B88C8
F00B8878: 113c047c                 sethi   %hi(_scsi_ncmds_per_dev), %o0
F00B887C: d0022150                 ld      [%o0+%lo(_scsi_ncmds_per_dev)], %o0
F00B8880: 40000014                 call    _scsi_addcmds
F00B8884: 912a2001                 sll     %o0, 1, %o0
F00B8888: d004239c                 ld      [%l0+%lo(dword_F013179C)], %o0
F00B888C: 80a22000                 cmp     %o0, 0
F00B8890: 32800006                 bne,a   loc_F00B88A8
F00B8894: 113c04c5                 sethi   -0xFECEC00, %o0
F00B8898: 113c047d                 sethi   %hi(aNoSpaceForScsi), %o0! "No space for scsi command structures"
F00B889C: 7ffd7235                 call    _panic
F00B88A0: 901220a8                 bset    %lo(aNoSpaceForScsi), %o0! "No space for scsi command structures"
F00B88A4: 113c04c5                 sethi   -0xFECEC00, %o0
F00B88A8: 901223d4                 bset    0x3D4, %o0
F00B88AC: 94102007                 mov     7, %o2
F00B88B0: d4222008                 st      %o2, [%o0+8]
F00B88B4: 133c04c5921263a0         set     dword_F01317A0, %o1
F00B88BC: d4226008                 st      %o2, [%o1+8]
F00B88C0: c0222010                 clr     [%o0+0x10]
F00B88C4: c0226010                 clr     [%o1+0x10]
F00B88C8: 81c7e008                 ret
F00B88CC: 81e80000                 restore
