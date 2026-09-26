F0065104: 9de3bf98                 save    %sp, -0x68, %sp
F0065108: a0062158                 add     %i0, 0x158, %l0
F006510C: d0040000                 ld      [%l0], %o0
F0065110: 80a22000                 cmp     %o0, 0
F0065114: 12bffffe                 bne     loc_F006510C
F0065118: 01000000                 nop
F006511C: 4000c763                 call    _simple_lock_try
F0065120: 90100010                 mov     %l0, %o0
F0065124: 80a22000                 cmp     %o0, 0
F0065128: 02bffff9                 be      loc_F006510C
F006512C: 01000000                 nop
F0065130: d0062154                 ld      [%i0+0x154], %o0
F0065134: 80a22000                 cmp     %o0, 0
F0065138: 02800017                 be      loc_F0065194
F006513C: 92100018                 mov     %i0, %o1
F0065140: 94102006                 mov     6, %o2
F0065144: d006215c                 ld      [%i0+0x15C], %o0
F0065148: 400001b6                 call    _ipc_kobject_set
F006514C: a0062148                 add     %i0, 0x148, %l0
F0065150: 92100018                 mov     %i0, %o1
F0065154: d0062160                 ld      [%i0+0x160], %o0
F0065158: 400001b2                 call    _ipc_kobject_set
F006515C: 94102007                 mov     7, %o2
F0065160: d0040000                 ld      [%l0], %o0
F0065164: 80a22000                 cmp     %o0, 0
F0065168: 12bffffe                 bne     loc_F0065160
F006516C: 01000000                 nop
F0065170: 4000c74e                 call    _simple_lock_try
F0065174: 90100010                 mov     %l0, %o0
F0065178: 80a22000                 cmp     %o0, 0
F006517C: 02bffff9                 be      loc_F0065160
F0065180: 01000000                 nop
F0065184: d0062144                 ld      [%i0+0x144], %o0
F0065188: c0262148                 clr     [%i0+0x148]
F006518C: 90022002                 inc     2, %o0
F0065190: d0262144                 st      %o0, [%i0+0x144]
F0065194: c0262158                 clr     [%i0+0x158]
F0065198: 81c7e008                 ret
F006519C: 81e80000                 restore
