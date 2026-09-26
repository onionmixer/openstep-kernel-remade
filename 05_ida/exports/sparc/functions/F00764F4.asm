F00764F4: 9de3bf98                 save    %sp, -0x68, %sp
F00764F8: 90100018                 mov     %i0, %o0
F00764FC: 133c01c5                 sethi   %hi(_thread_continue), %o1
F0076500: 7fffc9ae                 call    _stack_alloc
F0076504: 92126308                 bset    %lo(_thread_continue), %o1
F0076508: 400081a0                 call    _splusclock
F007650C: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0076510: a2100008                 mov     %o0, %l1
F0076514: d0040000                 ld      [%l0], %o0
F0076518: 80a22000                 cmp     %o0, 0
F007651C: 12bffffe                 bne     loc_F0076514
F0076520: 01000000                 nop
F0076524: 40008261                 call    _simple_lock_try
F0076528: 90100010                 mov     %l0, %o0
F007652C: 80a22000                 cmp     %o0, 0
F0076530: 02bffff9                 be      loc_F0076514
F0076534: 01000000                 nop
F0076538: d206204c                 ld      [%i0+0x4C], %o1
F007653C: 900a7cff                 and     %o1, -0x301, %o0
F0076540: 808a6004                 btst    4, %o1
F0076544: 02800005                 be      loc_F0076558
F0076548: d026204c                 st      %o0, [%i0+0x4C]
F007654C: 90100018                 mov     %i0, %o0
F0076550: 7fffedd4                 call    _thread_setrun
F0076554: 92102001                 mov     1, %o1
F0076558: c0262020                 clr     [%i0+0x20]
F007655C: 400081f2                 call    _splx
F0076560: 90100011                 mov     %l1, %o0
F0076564: 81c7e008                 ret
F0076568: 81e80000                 restore
