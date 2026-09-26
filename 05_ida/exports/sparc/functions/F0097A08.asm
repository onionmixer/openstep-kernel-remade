F0097A08: 9de3bf98                 save    %sp, -0x68, %sp
F0097A0C: 80a62000                 cmp     %i0, 0
F0097A10: 02800007                 be      loc_F0097A2C
F0097A14: 80a62001                 cmp     %i0, 1
F0097A18: 32800007                 bne,a   locret_F0097A34
F0097A1C: b0102000                 mov     0, %i0
F0097A20: 313c03d3                 sethi   %hi(unk_F00F4FC8), %i0
F0097A24: 10800004                 ba      locret_F0097A34
F0097A28: b01623c8                 bset    %lo(unk_F00F4FC8), %i0
F0097A2C: 313c03d3b01623d8         set     unk_F00F4FD8, %i0
F0097A34: 81c7e008                 ret
F0097A38: 81e80000                 restore
