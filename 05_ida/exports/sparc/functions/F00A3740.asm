F00A3740: 9de3bf98                 save    %sp, -0x68, %sp
F00A3744: 80a62072                 cmp     %i0, 0x72 ! 'r'
F00A3748: 02800005                 be      loc_F00A375C
F00A374C: 80a62080                 cmp     %i0, 0x80
F00A3750: 02800005                 be      loc_F00A3764
F00A3754: 01000000                 nop
F00A3758: 30800005                 ba,a    loc_F00A376C
F00A375C: 7fffce8e                 call    _p4m50_sys_setfunc
F00A3760: 9e03e008                 inc     8, %o7
F00A3764: 7fffcf0c                 call    _p4m35_sys_setfunc
F00A3768: 01000000                 nop
F00A376C: 7fffce86                 call    _init_all_fsr
F00A3770: 01000000                 nop
F00A3774: 81c7e008                 ret
F00A3778: 81e80000                 restore
