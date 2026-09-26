F00C6138: 9de3bf98                 save    %sp, -0x68, %sp
F00C613C: 92100019                 mov     %i1, %o1
F00C6140: d0026004                 ld      [%o1+4], %o0
F00C6144: 80a22000                 cmp     %o0, 0
F00C6148: 0280000d                 be      loc_F00C617C
F00C614C: 94100018                 mov     %i0, %o2
F00C6150: b0066004                 add     %i1, 4, %i0
F00C6154: d0024000                 ld      [%o1], %o0
F00C6158: 80a2000a                 cmp     %o0, %o2
F00C615C: 32800004                 bne,a   loc_F00C616C
F00C6160: b0062008                 inc     8, %i0
F00C6164: 1080000c                 ba      locret_F00C6194
F00C6168: f0060000                 ld      [%i0], %i0
F00C616C: d0060000                 ld      [%i0], %o0
F00C6170: 80a22000                 cmp     %o0, 0
F00C6174: 12bffff8                 bne     loc_F00C6154
F00C6178: 92026008                 inc     8, %o1
F00C617C: 313c04ccb0162050         set     unk_F0133050, %i0
F00C6184: 90100018                 mov     %i0, %o0! char *
F00C6188: 133c03ea                 sethi   %hi(aDDUndefined), %o1! "%d(d) (UNDEFINED)"
F00C618C: 7ffd3977                 call    _sprintf
F00C6190: 92126268                 bset    %lo(aDDUndefined), %o1! "%d(d) (UNDEFINED)"
F00C6194: 81c7e008                 ret
F00C6198: 81e80000                 restore
