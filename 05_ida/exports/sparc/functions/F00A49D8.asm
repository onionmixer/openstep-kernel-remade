F00A49D8: 9de3bf98                 save    %sp, -0x68, %sp
F00A49DC: 90100018                 mov     %i0, %o0
F00A49E0: 7fffc30b                 call    _mmu_probe
F00A49E4: 92102000                 mov     0, %o1
F00A49E8: 80a22000                 cmp     %o0, 0
F00A49EC: 02800005                 be      locret_F00A4A00
F00A49F0: b0103fff                 mov     -1, %i0
F00A49F4: 808a2003                 btst    3, %o0
F00A49F8: 32800002                 bne,a   locret_F00A4A00
F00A49FC: b1322008                 srl     %o0, 8, %i0
F00A4A00: 81c7e008                 ret
F00A4A04: 81e80000                 restore
