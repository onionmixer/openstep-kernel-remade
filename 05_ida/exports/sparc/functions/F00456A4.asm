F00456A4: 9de3bf90                 save    %sp, -0x70, %sp
F00456A8: 90100018                 mov     %i0, %o0
F00456AC: d2020000                 ld      [%o0], %o1
F00456B0: 80a26001                 cmp     %o1, 1
F00456B4: 22800012                 be,a    loc_F00456FC
F00456B8: d2022004                 ld      [%o0+4], %o1
F00456BC: 0a800006                 bcs     loc_F00456D4
F00456C0: 80a26002                 cmp     %o1, 2
F00456C4: 0280001f                 be      locret_F0045740
F00456C8: b0102001                 mov     1, %i0
F00456CC: 1080001a                 ba      loc_F0045734
F00456D0: 113c0437                 sethi   -0xFEF2400, %o0
F00456D4: d4064000                 ld      [%i1], %o2
F00456D8: 9207bff4                 add     %fp, var_C, %o1
F00456DC: 80a0000a                 cmp     %g0, %o2
F00456E0: d4022004                 ld      [%o0+4], %o2
F00456E4: 96402000                 addc    %g0, 0, %o3
F00456E8: d402a004                 ld      [%o2+4], %o2
F00456EC: 9fc28000                 call    %o2
F00456F0: d627bff4                 st      %o3, [%fp+var_C]
F00456F4: 10800013                 ba      locret_F0045740
F00456F8: b0100008                 mov     %o0, %i0
F00456FC: d4024000                 ld      [%o1], %o2
F0045700: 9fc28000                 call    %o2
F0045704: 9207bff4                 add     %fp, var_C, %o1
F0045708: 80a22000                 cmp     %o0, 0
F004570C: 32800005                 bne,a   loc_F0045720
F0045710: d007bff4                 ld      [%fp+var_C], %o0
F0045714: 113c0437                 sethi   %hi(aXdrBoolDecodeF), %o0! "xdr_bool: decode FAILED\n"
F0045718: 10800008                 ba      loc_F0045738
F004571C: 90122308                 bset    %lo(aXdrBoolDecodeF), %o0! "xdr_bool: decode FAILED\n"
F0045720: b0102001                 mov     1, %i0
F0045724: 80a00008                 cmp     %g0, %o0
F0045728: 90402000                 addc    %g0, 0, %o0
F004572C: 10800005                 ba      locret_F0045740
F0045730: d0264000                 st      %o0, [%i1]
F0045734: 90122328                 bset    0x328, %o0! char *
F0045738: 7fff3bc8                 call    _printf
F004573C: b0102000                 mov     0, %i0
F0045740: 81c7e008                 ret
F0045744: 81e80000                 restore
