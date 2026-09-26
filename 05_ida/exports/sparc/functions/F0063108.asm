F0063108: 9de3bf90                 save    %sp, -0x70, %sp
F006310C: 90100018                 mov     %i0, %o0! task
F0063110: 92100019                 mov     %i1, %o1! name
F0063114: 7ffffc4d                 call    _mach_port_type
F0063118: 9407bff4                 add     %fp, var_C, %o2
F006311C: 80a22000                 cmp     %o0, 0
F0063120: 12800006                 bne     locret_F0063138
F0063124: b0102004                 mov     4, %i0
F0063128: 7fffff83                 call    _convert_port_type
F006312C: d007bff4                 ld      [%fp+var_C], %o0
F0063130: d0268000                 st      %o0, [%i2]
F0063134: b0102000                 mov     0, %i0
F0063138: 81c7e008                 ret
F006313C: 81e80000                 restore
