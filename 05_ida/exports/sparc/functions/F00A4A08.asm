F00A4A08: 9de3bf98                 save    %sp, -0x68, %sp
F00A4A0C: 7ffffff3                 call    _va_to_pfn
F00A4A10: 90100018                 mov     %i0, %o0
F00A4A14: 80a23fff                 cmp     %o0, -1
F00A4A18: 12800004                 bne     loc_F00A4A28
F00A4A1C: 912a200c                 sll     %o0, 12, %o0
F00A4A20: 10800004                 ba      locret_F00A4A30
F00A4A24: b0103fff                 mov     -1, %i0
F00A4A28: b00e2fff                 and     %i0, 0xFFF, %i0
F00A4A2C: b0120018                 bset    %o0, %i0
F00A4A30: 81c7e008                 ret
F00A4A34: 81e80000                 restore
