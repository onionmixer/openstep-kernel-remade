F00B7864: 9de3bf98                 save    %sp, -0x68, %sp
F00B7868: 808e6020                 btst    0x20, %i1 ! ' '
F00B786C: 02800005                 be      loc_F00B7880
F00B7870: 90100018                 mov     %i0, %o0
F00B7874: 133c047b                 sethi   %hi(aReset), %o1! "Reset"
F00B7878: 40000127                 call    _esp_printstate
F00B787C: 92126040                 bset    %lo(aReset), %o1! "Reset"
F00B7880: 808e600f                 btst    0xF, %i1
F00B7884: 02800004                 be      loc_F00B7894
F00B7888: 90100018                 mov     %i0, %o0
F00B788C: 4000001f                 call    _esp_hw_reset
F00B7890: 92100019                 mov     %i1, %o1
F00B7894: 808e6010                 btst    0x10, %i1
F00B7898: 0280001a                 be      locret_F00B7900
F00B789C: 900620b8                 add     %i0, 0xB8, %o0! void *
F00B78A0: d41620b2                 lduh    [%i0+0xB2], %o2
F00B78A4: 92102100                 mov     0x100, %o1! size_t
F00B78A8: d43620b0                 sth     %o2, [%i0+0xB0]
F00B78AC: 94103fff                 mov     -1, %o2
F00B78B0: 7fff756a                 call    _bzero
F00B78B4: d43620b2                 sth     %o2, [%i0+0xB2]
F00B78B8: 9006205e                 add     %i0, 0x5E, %o0 ! '^'! void *
F00B78BC: 7fff7567                 call    _bzero
F00B78C0: 92102008                 mov     8, %o1! size_t
F00B78C4: 90062066                 add     %i0, 0x66, %o0 ! 'f'! void *
F00B78C8: 7fff7564                 call    _bzero
F00B78CC: 92102008                 mov     8, %o1
F00B78D0: c02e2078                 clrb    [%i0+0x78]
F00B78D4: c0262088                 clr     [%i0+0x88]
F00B78D8: c0262080                 clr     [%i0+0x80]
F00B78DC: c0262084                 clr     [%i0+0x84]
F00B78E0: c02e2053                 clrb    [%i0+0x53]
F00B78E4: 901020ff                 mov     0xFF, %o0
F00B78E8: d02e204c                 stb     %o0, [%i0+0x4C]
F00B78EC: d02e2052                 stb     %o0, [%i0+0x52]
F00B78F0: d20e2041                 ldub    [%i0+0x41], %o1
F00B78F4: d02e2054                 stb     %o0, [%i0+0x54]
F00B78F8: d22e2042                 stb     %o1, [%i0+0x42]
F00B78FC: c02e2041                 clrb    [%i0+0x41]
F00B7900: 81c7e008                 ret
F00B7904: 81e80000                 restore
