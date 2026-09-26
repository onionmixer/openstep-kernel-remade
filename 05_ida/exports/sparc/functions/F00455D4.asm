F00455D4: 9de3bf90                 save    %sp, -0x70, %sp
F00455D8: 90100018                 mov     %i0, %o0
F00455DC: d2020000                 ld      [%o0], %o1
F00455E0: 80a26001                 cmp     %o1, 1
F00455E4: 22800010                 be,a    loc_F0045624
F00455E8: d2022004                 ld      [%o0+4], %o1
F00455EC: 0a800006                 bcs     loc_F0045604
F00455F0: 80a26002                 cmp     %o1, 2
F00455F4: 0280001b                 be      locret_F0045660
F00455F8: b0102001                 mov     1, %i0
F00455FC: 10800016                 ba      loc_F0045654
F0045600: 113c0437                 sethi   -0xFEF2400, %o0
F0045604: d4164000                 lduh    [%i1], %o2
F0045608: d6022004                 ld      [%o0+4], %o3
F004560C: 9207bff4                 add     %fp, var_C, %o1
F0045610: d602e004                 ld      [%o3+4], %o3
F0045614: 9fc2c000                 call    %o3
F0045618: d427bff4                 st      %o2, [%fp+var_C]
F004561C: 10800011                 ba      locret_F0045660
F0045620: b0100008                 mov     %o0, %i0
F0045624: d4024000                 ld      [%o1], %o2
F0045628: 9fc28000                 call    %o2
F004562C: 9207bff4                 add     %fp, var_C, %o1
F0045630: 80a22000                 cmp     %o0, 0
F0045634: 32800005                 bne,a   loc_F0045648
F0045638: d007bff4                 ld      [%fp+var_C], %o0
F004563C: 113c0437                 sethi   %hi(aXdrUShortDecod), %o0! "xdr_u_short: decode FAILED\n"
F0045640: 10800006                 ba      loc_F0045658
F0045644: 901222c8                 bset    %lo(aXdrUShortDecod), %o0! "xdr_u_short: decode FAILED\n"
F0045648: b0102001                 mov     1, %i0
F004564C: 10800005                 ba      locret_F0045660
F0045650: d0364000                 sth     %o0, [%i1]
F0045654: 901222e8                 bset    0x2E8, %o0! char *
F0045658: 7fff3c00                 call    _printf
F004565C: b0102000                 mov     0, %i0
F0045660: 81c7e008                 ret
F0045664: 81e80000                 restore
