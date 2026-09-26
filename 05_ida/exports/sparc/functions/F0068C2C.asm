F0068C2C: 9de3bf98                 save    %sp, -0x68, %sp
F0068C30: 113c04f0                 sethi   %hi(_stack_queue_lock), %o0
F0068C34: 40000130                 call    _lock_read
F0068C38: 901220e0                 bset    %lo(_stack_queue_lock), %o0
F0068C3C: 113c0442                 sethi   %hi(_stack_check_usage), %o0
F0068C40: d0022290                 ld      [%o0+%lo(_stack_check_usage)], %o0
F0068C44: 80a22000                 cmp     %o0, 0
F0068C48: 02800012                 be      loc_F0068C90
F0068C4C: 113c04bd                 sethi   %hi(dword_F012F670), %o0
F0068C50: e0022270                 ld      [%o0+%lo(dword_F012F670)], %l0
F0068C54: 90122270                 bset    %lo(dword_F012F670), %o0
F0068C58: 80a40008                 cmp     %l0, %o0
F0068C5C: 2280000e                 be,a    loc_F0068C94
F0068C60: 113c043e                 sethi   -0xFEF0800, %o0
F0068C64: a2100008                 mov     %o0, %l1
F0068C68: 400034e2                 call    _stack_usage
F0068C6C: 9004200c                 add     %l0, 0xC, %o0
F0068C70: d2064000                 ld      [%i1], %o1
F0068C74: 80a20009                 cmp     %o0, %o1
F0068C78: 38800002                 bgu,a   loc_F0068C80
F0068C7C: d0264000                 st      %o0, [%i1]
F0068C80: e0040000                 ld      [%l0], %l0
F0068C84: 80a40011                 cmp     %l0, %l1
F0068C88: 12bffff8                 bne     loc_F0068C68
F0068C8C: 01000000                 nop
F0068C90: 113c043e                 sethi   -0xFEF0800, %o0
F0068C94: d2022300                 ld      [%o0+0x300], %o1
F0068C98: 113c04f0901220e0         set     _stack_queue_lock, %o0
F0068CA0: 400000e5                 call    _lock_done
F0068CA4: d2260000                 st      %o1, [%i0]
F0068CA8: 81c7e008                 ret
F0068CAC: 81e80000                 restore
