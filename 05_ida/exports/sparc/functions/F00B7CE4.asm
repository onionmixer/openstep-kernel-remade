F00B7CE4: 9de3bf98                 save    %sp, -0x68, %sp
F00B7CE8: d20e2043                 ldub    [%i0+0x43], %o1
F00B7CEC: 113c0478                 sethi   %hi(_esp_stat_bits), %o0
F00B7CF0: d40221d8                 ld      [%o0+%lo(_esp_stat_bits)], %o2
F00B7CF4: d60e2044                 ldub    [%i0+0x44], %o3
F00B7CF8: 193c0478                 sethi   %hi(_esp_int_bits), %o4
F00B7CFC: d8032208                 ld      [%o4+%lo(_esp_int_bits)], %o4
F00B7D00: 113c047b                 sethi   %hi(aStat0xBIntr0xB), %o0! "\tStat=0x%b, Intr=0x%b\n"
F00B7D04: 7ffd7255                 call    _printf
F00B7D08: 901220c0                 bset    %lo(aStat0xBIntr0xB), %o0! "\tStat=0x%b, Intr=0x%b\n"
F00B7D0C: 81c7e008                 ret
F00B7D10: 81e80000                 restore
