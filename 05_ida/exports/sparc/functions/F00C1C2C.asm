F00C1C2C: 9de3bf90                 save    %sp, -0x70, %sp
F00C1C30: f4262138                 st      %i2, [%i0+0x138]
F00C1C34: 7ffe959f                 call    _task_self
F00C1C38: f626213c                 st      %i3, [%i0+0x13C]
F00C1C3C: d2062128                 ld      [%i0+0x128], %o1
F00C1C40: 4000c84a                 call    _port_set_add_EXTERNAL
F00C1C44: d406213c                 ld      [%i0+0x13C], %o2
F00C1C48: 92920000                 orcc    %o0, %g0, %o1
F00C1C4C: 12800004                 bne     loc_F00C1C5C
F00C1C50: 113c0484                 sethi   -0xFEDF000, %o0
F00C1C54: 10800005                 ba      locret_F00C1C68
F00C1C58: b0102000                 mov     0, %i0
F00C1C5C: 40001126                 call    _IOLog
F00C1C60: 90122078                 bset    0x78, %o0 ! 'x'
F00C1C64: b0103fff                 mov     -1, %i0
F00C1C68: 81c7e008                 ret
F00C1C6C: 81e80000                 restore
