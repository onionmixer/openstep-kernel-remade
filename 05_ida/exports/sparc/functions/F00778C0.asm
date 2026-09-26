F00778C0: 9de3bf90                 save    %sp, -0x70, %sp! int
F00778C4: 40008011                 call    _clock_value
F00778C8: 90102001                 mov     1, %o0
F00778CC: a007bff0                 add     %fp, var_10, %l0
F00778D0: 7fffda8d                 call    _ns_time_to_tsval
F00778D4: 94100010                 mov     %l0, %o2! int
F00778D8: 90100010                 mov     %l0, %o0! int
F00778DC: 92100018                 mov     %i0, %o1! int
F00778E0: 400081fb                 call    _copyout
F00778E4: 94102008                 mov     8, %o2
F00778E8: 80a00008                 cmp     %g0, %o0
F00778EC: b0402000                 addc    %g0, 0, %i0
F00778F0: 81c7e008                 ret
F00778F4: 81e80000                 restore
