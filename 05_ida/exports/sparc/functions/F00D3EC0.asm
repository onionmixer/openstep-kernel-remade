F00D3EC0: 9de3bf90                 save    %sp, -0x70, %sp
F00D3EC4: d0062168                 ld      [%i0+0x168], %o0
F00D3EC8: d402201c                 ld      [%o0+0x1C], %o2
F00D3ECC: 133c0505                 sethi   %hi(paChangecursor), %o1
F00D3ED0: d20262a0                 ld      [%o1+%lo(paChangecursor)], %o1! SEL
F00D3ED4: 90100018                 mov     %i0, %o0! id
F00D3ED8: 40007666                 call    _objc_msgSend
F00D3EDC: 9402a001                 inc     %o2
F00D3EE0: d01e21e8                 ldd     [%i0+0x1E8], %o0
F00D3EE4: d41e2200                 ldd     [%i0+0x200], %o2
F00D3EE8: 9282400b                 addcc   %o1, %o3, %o1
F00D3EEC: 9042000a                 addc    %o0, %o2, %o0
F00D3EF0: d03e21f0                 std     %o0, [%i0+0x1F0]
F00D3EF4: 81c7e008                 ret
F00D3EF8: 81e80000                 restore
