F00288E0: 9de3bf98                 save    %sp, -0x68, %sp
F00288E4: 053c04cfb210a1dc         set     dword_F0133DDC, %i1
F00288EC: c6067ffc                 ld      [%i1-4], %g3
F00288F0: c400a1dc                 ld      [%g2+0x1DC], %g2
F00288F4: c650e16a                 ldsh    [%g3+0x16A], %g3
F00288F8: f000a024                 ld      [%g2+0x24], %i0
F00288FC: c620a030                 st      %g3, [%g2+0x30]
F0028900: c4060000                 ld      [%i0], %g2
F0028904: c6067ffc                 ld      [%i1-4], %g3
F0028908: 8408afff                 and     %g2, 0xFFF, %g2
F002890C: c430e16a                 sth     %g2, [%g3+0x16A]
F0028910: 81c7e008                 ret
F0028914: 81e80000                 restore
