F00DED9C: 9de3bf90                 save    %sp, -0x70, %sp
F00DEDA0: 94100019                 mov     %i1, %o2
F00DEDA4: 9610001a                 mov     %i2, %o3
F00DEDA8: 9810001b                 mov     %i3, %o4
F00DEDAC: 80a62000                 cmp     %i0, 0
F00DEDB0: 12800004                 bne     loc_F00DEDC0
F00DEDB4: 9a10001c                 mov     %i4, %o5
F00DEDB8: 1080000b                 ba      locret_F00DEDE4
F00DEDBC: b01020ca                 mov     0xCA, %i0
F00DEDC0: 113c0504                 sethi   %hi(paPlaybufferSize), %o0! id
F00DEDC4: d20223f8                 ld      [%o0+%lo(paPlaybufferSize)], %o1! SEL
F00DEDC8: fa23a05c                 st      %i5, [%sp+0x70+var_14]
F00DEDCC: 40004aa9                 call    _objc_msgSend
F00DEDD0: 90100018                 mov     %i0, %o0
F00DEDD4: 912a2018                 sll     %o0, 24, %o0
F00DEDD8: 80a00008                 cmp     %g0, %o0
F00DEDDC: b0403fff                 addc    %g0, -1, %i0
F00DEDE0: b00e20cc                 and     %i0, 0xCC, %i0
F00DEDE4: 81c7e008                 ret
F00DEDE8: 81e80000                 restore
