F0070004: 9de3bf90                 save    %sp, -0x70, %sp
F0070008: d0064000                 ld      [%i1], %o0
F007000C: 80a2200f                 cmp     %o0, 0xF
F0070010: 0880001b                 bleu    loc_F007007C
F0070014: 2100003f                 sethi   0xFC00, %l0
F0070018: a01423ff                 bset    0x3FF, %l0
F007001C: d2060000                 ld      [%i0], %o1
F0070020: 94062010                 add     %i0, 0x10, %o2
F0070024: d0062008                 ld      [%i0+8], %o0
F0070028: 920a4010                 and     %o1, %l0, %o1
F007002C: 92027ff4                 inc     -0xC, %o1
F0070030: d227bff4                 st      %o1, [%fp+var_C]
F0070034: d206200c                 ld      [%i0+0xC], %o1
F0070038: 4000917a                 call    _kdp_machine_write_regs
F007003C: 9607bff4                 add     %fp, var_C, %o3
F0070040: d0262008                 st      %o0, [%i0+8]
F0070044: d0060000                 ld      [%i0], %o0
F0070048: 13004000                 sethi   0x1000000, %o1
F007004C: 90120009                 bset    %o1, %o0
F0070050: d0260000                 st      %o0, [%i0]
F0070054: 9010200c                 mov     0xC, %o0
F0070058: d0362002                 sth     %o0, [%i0+2]
F007005C: 113c04f1                 sethi   %hi(_kdp), %o0
F0070060: d0122000                 lduh    [%o0+%lo(_kdp)], %o0
F0070064: d0368000                 sth     %o0, [%i2]
F0070068: d0060000                 ld      [%i0], %o0
F007006C: b0102001                 mov     1, %i0
F0070070: 900a0010                 and     %o0, %l0, %o0
F0070074: 10800003                 ba      locret_F0070080
F0070078: d0264000                 st      %o0, [%i1]
F007007C: b0102000                 mov     0, %i0
F0070080: 81c7e008                 ret
F0070084: 81e80000                 restore
