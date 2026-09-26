F00B1748: 9de3bf98                 save    %sp, -0x68, %sp
F00B174C: 7fffa259                 call    _ipltospl
F00B1750: 900e200f                 and     %i0, 0xF, %o0
F00B1754: 153c0471                 sethi   %hi(_splvm_val), %o2
F00B1758: d202a018                 ld      [%o2+%lo(_splvm_val)], %o1
F00B175C: 80a20009                 cmp     %o0, %o1
F00B1760: 04800007                 ble     locret_F00B177C
F00B1764: 133c0471                 sethi   %hi(_SPLMB), %o1
F00B1768: d022a018                 st      %o0, [%o2+%lo(_splvm_val)]
F00B176C: 90022100                 inc     0x100, %o0
F00B1770: 913a2009                 sra     %o0, 9, %o0
F00B1774: 900a200f                 and     %o0, 0xF, %o0
F00B1778: d0226014                 st      %o0, [%o1+%lo(_SPLMB)]
F00B177C: 81c7e008                 ret
F00B1780: 81e80000                 restore
