F0003040: 8e100008                 mov     %o0, %g7
F0003044: 8c100009                 mov     %o1, %g6
F0003048: 8a10000a                 mov     %o2, %g5
F000304C: 81902002                 wrpr    %g0, 2, %tpc
F0003050: 82102fa0                 mov     0xFA0, %g1
F0003054: 81884000                 saved
F0003058: 01000000                 nop
F000305C: 01000000                 nop
F0003060: 01000000                 nop
F0003064: 033c000c                 sethi   %hi(_romp), %g1
F0003068: ce206030                 st      %g7, [%g1+%lo(_romp)]
F000306C: 033c000c                 sethi   %hi(_dvec), %g1
F0003070: cc206034                 st      %g6, [%g1+%lo(_dvec)]
F0003074: 033c000c                 sethi   %hi(_bootops), %g1
F0003078: ca206038                 st      %g5, [%g1+%lo(_bootops)]
F000307C: 053c00088410a000         set     _start, %g2
F0003084: d418a0f0                 ldd     [%g2+0xF0], %o2
F0003088: d818a0f8                 ldd     [%g2+0xF8], %o4
F000308C: 9a2b60ff                 bclr    0xFF, %o5
F0003090: d438a000                 std     %o2, [%g2]
F0003094: d838a008                 std     %o4, [%g2+8]
F0003098: 81900000                 wrpr    %g0, %g0, %tpc
F000309C: 81e00000                 save
F00030A0: 83480000                 rdhpr   %hpstate, %g1
F00030A4: 8208601f                 and     %g1, 0x1F, %g1
F00030A8: 81e80000                 restore
F00030AC: 81902002                 wrpr    %g0, 2, %tpc
F00030B0: 82006001                 inc     %g1
F00030B4: 093c000c                 sethi   %hi(_nwindows), %g4
F00030B8: c221203c                 st      %g1, [%g4+%lo(_nwindows)]
F00030BC: a9580000                 flushw
F00030C0: a82d2fff                 bclr    0xFFF, %l4
F00030C4: 133c042892126010         set     _mon_clock14_vec, %o1
F00030CC: d41d21e0                 ldd     [%l4+0x1E0], %o2
F00030D0: d81d21e8                 ldd     [%l4+0x1E8], %o4
F00030D4: d43a4000                 std     %o2, [%o1]
F00030D8: d83a6008                 std     %o4, [%o1+8]
F00030DC: 133c0014921261c8         set     mon_breakpoint_vec, %o1
F00030E4: d41d2ff0                 ldd     [%l4+0xFF0], %o2
F00030E8: d81d2ff8                 ldd     [%l4+0xFF8], %o4
F00030EC: d43a4000                 std     %o2, [%o1]
F00030F0: d83a6008                 std     %o4, [%o1+8]
F00030F4: d438aff0                 std     %o2, [%g2+0xFF0]
F00030F8: d838aff8                 std     %o4, [%g2+0xFF8]
F00030FC: 81988000                 wrhpr   %g2, %g0, %hpstate
F0003100: 033c042782106358         set     unk_F0109F58, %g1
F0003108: 9c100001                 mov     %g1, %sp
F000310C: bc102000                 mov     0, %fp
F0003110: 40025d5d                 call    _module_setup
F0003114: d0800080                 lda     [%g0]#ASI_NUCLEUS, %o0
F0003118: 40028088                 call    _sparc_init
F000311C: 01000000                 nop
F0003120: 033fbfe0                 sethi   -0x1008000, %g1
F0003124: 84202001                 neg     1, %g2
F0003128: c4206008                 st      %g2, [%g1+8]
F000312C: 40019cf0                 call    _setup_main
F0003130: 01000000                 nop
F0003134: 400263c6                 call    _start_initial_context
F0003138: 01000000                 nop
F000313C: 10800000                 ba      loc_F000313C
F0003140: 01000000                 nop
