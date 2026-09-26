F00D3E88: 9de3bf90                 save    %sp, -0x70, %sp
F00D3E8C: 133c0505                 sethi   %hi(paChangecursor), %o1
F00D3E90: d0062168                 ld      [%i0+0x168], %o0! id
F00D3E94: 94102000                 mov     0, %o2
F00D3E98: d20262a0                 ld      [%o1+%lo(paChangecursor)], %o1! SEL
F00D3E9C: c0222044                 clr     [%o0+0x44]
F00D3EA0: 40007674                 call    _objc_msgSend
F00D3EA4: 90100018                 mov     %i0, %o0
F00D3EA8: 98102000                 mov     0, %o4
F00D3EAC: 9a102000                 mov     0, %o5
F00D3EB0: d83e21f0                 std     %o4, [%i0+0x1F0]
F00D3EB4: d83e21e0                 std     %o4, [%i0+0x1E0]
F00D3EB8: 81c7e008                 ret
F00D3EBC: 81e80000                 restore
