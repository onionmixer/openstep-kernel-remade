F009A044: 9de3bf98                 save    %sp, -0x68, %sp
F009A048: 11000040                 sethi   0x10000, %o0
F009A04C: 808e4008                 btst    %o0, %i1
F009A050: 02800005                 be      loc_F009A064
F009A054: 808e6008                 btst    8, %i1
F009A058: 7ffffff4                 call    _system_power_down
F009A05C: 01000000                 nop
F009A060: 808e6008                 btst    8, %i1
F009A064: 02800005                 be      loc_F009A078
F009A068: 80a62000                 cmp     %i0, 0
F009A06C: 7fffffcc                 call    _halt_cpu
F009A070: 01000000                 nop
F009A074: 80a62000                 cmp     %i0, 0
F009A078: 12800004                 bne     loc_F009A088
F009A07C: 01000000                 nop
F009A080: 7fffffc7                 call    _halt_cpu
F009A084: 01000000                 nop
F009A088: 40005396                 call    _prom_boot
F009A08C: 9010001a                 mov     %i2, %o0
F009A090: 81c7e008                 ret
F009A094: 81e80000                 restore
