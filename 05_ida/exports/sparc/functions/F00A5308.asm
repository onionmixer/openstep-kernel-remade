F00A5308: 9de3bf98                 save    %sp, -0x68, %sp
F00A530C: 213c043e                 sethi   %hi(_hz), %l0
F00A5310: d00423e0                 ld      [%l0+%lo(_hz)], %o0
F00A5314: 80a22064                 cmp     %o0, 0x64 ! 'd'
F00A5318: 22800006                 be,a    loc_F00A5330
F00A531C: d20423e0                 ld      [%l0+%lo(_hz)], %o1
F00A5320: 113c0466                 sethi   %hi(aStartrtclock), %o0! "startrtclock"
F00A5324: 7ffdbf93                 call    _panic
F00A5328: 901220f0                 bset    %lo(aStartrtclock), %o0! "startrtclock"
F00A532C: d20423e0                 ld      [%l0+%lo(_hz)], %o1! int
F00A5330: 110003d0                 sethi   0xF4000, %o0! int
F00A5334: 7ffd84b5                 call    _div
F00A5338: 90122240                 bset    0x240, %o0
F00A533C: 173fbfe4                 sethi   -0x1007000, %o3
F00A5340: 15000010                 sethi   0x4000, %o2
F00A5344: 90022001                 inc     %o0
F00A5348: 912a200a                 sll     %o0, 10, %o0
F00A534C: 131fffff                 sethi   0x7FFFFC00, %o1
F00A5350: 900a0009                 and     %o0, %o1, %o0
F00A5354: d022c00a                 st      %o0, [%o3+%o2]
F00A5358: 11000200                 sethi   0x80000, %o0
F00A535C: 40000004                 call    _set_clk_mode
F00A5360: 92102000                 mov     0, %o1
F00A5364: 81c7e008                 ret
F00A5368: 81e80000                 restore
