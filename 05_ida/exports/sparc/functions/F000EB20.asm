F000EB20: 9de3bf48                 save    %sp, -0xB8, %sp
F000EB24: 94100018                 mov     %i0, %o2
F000EB28: 920aa03f                 and     %o2, 0x3F, %o1
F000EB2C: 113c04d2901220b0         set     _posix_proc_hash, %o0
F000EB34: 932a6002                 sll     %o1, 2, %o1
F000EB38: f0024008                 ld      [%o1+%o0], %i0
F000EB3C: 80a62000                 cmp     %i0, 0
F000EB40: 0280000b                 be      loc_F000EB6C
F000EB44: a007bfa8                 add     %fp, var_58, %l0
F000EB48: d0060000                 ld      [%i0], %o0
F000EB4C: 80a2000a                 cmp     %o0, %o2
F000EB50: 0280000d                 be      locret_F000EB84
F000EB54: 01000000                 nop
F000EB58: f006201c                 ld      [%i0+0x1C], %i0
F000EB5C: 80a62000                 cmp     %i0, 0
F000EB60: 32bffffb                 bne,a   loc_F000EB4C
F000EB64: d0060000                 ld      [%i0], %o0
F000EB68: a007bfa8                 add     %fp, var_58, %l0
F000EB6C: 90100010                 mov     %l0, %o0! char *
F000EB70: 133c042c                 sethi   %hi(aGetPosixProcNo), %o1! "get_posix_proc(): no posix proc struct "...
F000EB74: 400016fd                 call    _sprintf
F000EB78: 92126158                 bset    %lo(aGetPosixProcNo), %o1! "get_posix_proc(): no posix proc struct "...
F000EB7C: 4000197d                 call    _panic
F000EB80: 90100010                 mov     %l0, %o0
F000EB84: 81c7e008                 ret
F000EB88: 81e80000                 restore
