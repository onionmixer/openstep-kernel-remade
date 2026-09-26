F00AFDC8: 9de3bf98                 save    %sp, -0x68, %sp
F00AFDCC: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AFDD0: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AFDD4: 80a22000                 cmp     %o0, 0
F00AFDD8: 02800008                 be      loc_F00AFDF8
F00AFDDC: 113c000c                 sethi   -0xFFFD000, %o0
F00AFDE0: 7ffffc05                 call    _prom_bootpath
F00AFDE4: 01000000                 nop
F00AFDE8: 40000ca9                 call    _get_part_from_path
F00AFDEC: 01000000                 nop
F00AFDF0: 10800006                 ba      locret_F00AFE08
F00AFDF4: b0100008                 mov     %o0, %i0
F00AFDF8: d0022030                 ld      [%o0+0x30], %o0
F00AFDFC: d0022080                 ld      [%o0+0x80], %o0
F00AFE00: d0020000                 ld      [%o0], %o0
F00AFE04: f0022090                 ld      [%o0+0x90], %i0
F00AFE08: 81c7e008                 ret
F00AFE0C: 81e80000                 restore
