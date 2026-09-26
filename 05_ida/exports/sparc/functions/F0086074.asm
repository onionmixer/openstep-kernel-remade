F0086074: 9de3bf98                 save    %sp, -0x68, %sp
F0086078: d0066018                 ld      [%i1+0x18], %o0
F008607C: 80a22000                 cmp     %o0, 0
F0086080: 16800004                 bge     loc_F0086090
F0086084: 01000000                 nop
F0086088: 7fff8beb                 call    _lock_done
F008608C: d0066010                 ld      [%i1+0x10], %o0
F0086090: 7fff8be9                 call    _lock_done
F0086094: 90100018                 mov     %i0, %o0
F0086098: 81c7e008                 ret
F008609C: 81e80000                 restore
