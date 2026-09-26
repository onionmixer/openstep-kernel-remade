F00ECD94: 9de3bf98                 save    %sp, -0x68, %sp
F00ECD98: 113c04bc92122048         set     unk_F012F048, %o1
F00ECDA0: 80a26000                 cmp     %o1, 0
F00ECDA4: 0280000d                 be      loc_F00ECDD8
F00ECDA8: 90100018                 mov     %i0, %o0
F00ECDAC: d0024000                 ld      [%o1], %o0
F00ECDB0: 80a20018                 cmp     %o0, %i0
F00ECDB4: 32800005                 bne,a   loc_F00ECDC8
F00ECDB8: d2026014                 ld      [%o1+0x14], %o1
F00ECDBC: d0062074                 ld      [%i0+0x74], %o0
F00ECDC0: 10800008                 ba      locret_F00ECDE0
F00ECDC4: d0224000                 st      %o0, [%o1]
F00ECDC8: 80a26000                 cmp     %o1, 0
F00ECDCC: 32bffff9                 bne,a   loc_F00ECDB0
F00ECDD0: d0024000                 ld      [%o1], %o0
F00ECDD4: 90100018                 mov     %i0, %o0
F00ECDD8: 7ffffee5                 call    sub_F00EC96C
F00ECDDC: 92102000                 mov     0, %o1
F00ECDE0: 81c7e008                 ret
F00ECDE4: 81e80000                 restore
