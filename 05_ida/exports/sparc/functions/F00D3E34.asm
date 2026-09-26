F00D3E34: 9de3bf90                 save    %sp, -0x70, %sp
F00D3E38: 90102001                 mov     1, %o0! id
F00D3E3C: d2062168                 ld      [%i0+0x168], %o1
F00D3E40: 94102001                 mov     1, %o2
F00D3E44: d0226044                 st      %o0, [%o1+0x44]
F00D3E48: 133c0505                 sethi   %hi(paChangecursor), %o1
F00D3E4C: d20262a0                 ld      [%o1+%lo(paChangecursor)], %o1! SEL
F00D3E50: 40007688                 call    _objc_msgSend
F00D3E54: 90100018                 mov     %i0, %o0
F00D3E58: d01e21e8                 ldd     [%i0+0x1E8], %o0
F00D3E5C: d81e2200                 ldd     [%i0+0x200], %o4
F00D3E60: d41e21d8                 ldd     [%i0+0x1D8], %o2
F00D3E64: 9282400d                 addcc   %o1, %o5, %o1
F00D3E68: 9042000c                 addc    %o0, %o4, %o0
F00D3E6C: d81e2200                 ldd     [%i0+0x200], %o4
F00D3E70: d03e21f0                 std     %o0, [%i0+0x1F0]
F00D3E74: 9682c00d                 addcc   %o3, %o5, %o3
F00D3E78: 9442800c                 addc    %o2, %o4, %o2
F00D3E7C: d43e21e0                 std     %o2, [%i0+0x1E0]
F00D3E80: 81c7e008                 ret
F00D3E84: 81e80000                 restore
