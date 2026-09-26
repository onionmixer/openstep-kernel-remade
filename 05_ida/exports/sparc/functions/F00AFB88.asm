F00AFB88: 9de3bf98                 save    %sp, -0x68, %sp
F00AFB8C: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AFB90: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AFB94: 80a22000                 cmp     %o0, 0
F00AFB98: 02800006                 be      loc_F00AFBB0
F00AFB9C: 133c000c                 sethi   %hi(_romp), %o1
F00AFBA0: d4026030                 ld      [%o1+%lo(_romp)], %o2
F00AFBA4: 90100018                 mov     %i0, %o0
F00AFBA8: 10800005                 ba      loc_F00AFBBC
F00AFBAC: d602a0bc                 ld      [%o2+0xBC], %o3
F00AFBB0: d4026030                 ld      [%o1+0x30], %o2
F00AFBB4: 90100018                 mov     %i0, %o0
F00AFBB8: d602a044                 ld      [%o2+0x44], %o3
F00AFBBC: 92100019                 mov     %i1, %o1
F00AFBC0: 9fc2c000                 call    %o3
F00AFBC4: 9410001a                 mov     %i2, %o2
F00AFBC8: 81c7e008                 ret
F00AFBCC: 91e80008                 restore %g0, %o0, %o0
