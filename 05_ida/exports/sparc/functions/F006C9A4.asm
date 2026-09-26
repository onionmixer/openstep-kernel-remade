F006C9A4: 9de3bf98                 save    %sp, -0x68, %sp
F006C9A8: f0060000                 ld      [%i0], %i0
F006C9AC: d2062038                 ld      [%i0+0x38], %o1
F006C9B0: 11020000                 sethi   0x8000000, %o0
F006C9B4: 808a4008                 btst    %o0, %o1
F006C9B8: 02800008                 be      locret_F006C9D8
F006C9BC: 01000000                 nop
F006C9C0: d0562004                 ldsh    [%i0+4], %o0
F006C9C4: 80a22000                 cmp     %o0, 0
F006C9C8: 12800004                 bne     locret_F006C9D8
F006C9CC: 90100018                 mov     %i0, %o0
F006C9D0: 40000004                 call    _mfs_memfree
F006C9D4: 92102000                 mov     0, %o1
F006C9D8: 81c7e008                 ret
F006C9DC: 81e80000                 restore
