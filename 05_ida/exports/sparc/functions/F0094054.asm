F0094054: 9de3bf98                 save    %sp, -0x68, %sp
F0094058: b4100018                 mov     %i0, %i2
F009405C: 053c0449                 sethi   %hi(off_F0112528), %g2
F0094060: f000a128                 ld      [%g2+%lo(off_F0112528)], %i0
F0094064: 8610a128                 or      %g2, %lo(off_F0112528), %g3
F0094068: 80a60003                 cmp     %i0, %g3
F009406C: 22800018                 be,a    locret_F00940CC
F0094070: b0102000                 mov     0, %i0
F0094074: b6100002                 mov     %g2, %i3
F0094078: b2100003                 mov     %g3, %i1
F009407C: c4062008                 ld      [%i0+8], %g2
F0094080: 80a0801a                 cmp     %g2, %i2
F0094084: 3280000e                 bne,a   loc_F00940BC
F0094088: f0060000                 ld      [%i0], %i0
F009408C: c6060000                 ld      [%i0], %g3
F0094090: 80a0c019                 cmp     %g3, %i1
F0094094: 12800004                 bne     loc_F00940A4
F0094098: c4062004                 ld      [%i0+4], %g2
F009409C: 10800003                 ba      loc_F00940A8
F00940A0: c4266004                 st      %g2, [%i1+4]
F00940A4: c420e004                 st      %g2, [%g3+4]
F00940A8: 80a08019                 cmp     %g2, %i1
F00940AC: 22800008                 be,a    locret_F00940CC
F00940B0: c626e128                 st      %g3, [%i3+0x128]
F00940B4: 10800006                 ba      locret_F00940CC
F00940B8: c6208000                 st      %g3, [%g2]
F00940BC: 80a60019                 cmp     %i0, %i1
F00940C0: 32bffff0                 bne,a   loc_F0094080
F00940C4: c4062008                 ld      [%i0+8], %g2
F00940C8: b0102000                 mov     0, %i0
F00940CC: 81c7e008                 ret
F00940D0: 81e80000                 restore
