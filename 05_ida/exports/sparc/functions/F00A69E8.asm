F00A69E8: 9de3bf98                 save    %sp, -0x68, %sp
F00A69EC: 90100019                 mov     %i1, %o0
F00A69F0: 9fc68000                 call    %i2
F00A69F4: 920e200f                 and     %i0, 0xF, %o1
F00A69F8: 92920000                 orcc    %o0, %g0, %o1
F00A69FC: 12800006                 bne     loc_F00A6A14
F00A6A00: 113c046b                 sethi   -0xFEE5400, %o0
F00A6A04: 113c046b                 sethi   %hi(aSimmDecodeFunc_0), %o0! "simm decode function failed\n"
F00A6A08: 7ffdb714                 call    _printf
F00A6A0C: 90122108                 bset    %lo(aSimmDecodeFunc_0), %o0! "simm decode function failed\n"
F00A6A10: 30800003                 ba,a    locret_F00A6A1C
F00A6A14: 7ffdb711                 call    _printf
F00A6A18: 90122128                 bset    0x128, %o0
F00A6A1C: 81c7e008                 ret
F00A6A20: 81e80000                 restore
