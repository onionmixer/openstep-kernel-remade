F0069FA4: 9de3bf98                 save    %sp, -0x68, %sp
F0069FA8: b0102000                 mov     0, %i0
F0069FAC: 053c00008410a000         set     dword_F0000000, %g2
F0069FB4: b200a01c                 add     %g2, 0x1C, %i1
F0069FB8: c400a010                 ld      [%g2+0x10], %g2
F0069FBC: 80a60002                 cmp     %i0, %g2
F0069FC0: 1a800012                 bcc     locret_F006A008
F0069FC4: b4102000                 mov     0, %i2
F0069FC8: b6100002                 mov     %g2, %i3
F0069FCC: c4064000                 ld      [%i1], %g2
F0069FD0: 80a0a001                 cmp     %g2, 1
F0069FD4: 32800009                 bne,a   loc_F0069FF8
F0069FD8: b406a001                 inc     %i2
F0069FDC: c6066018                 ld      [%i1+0x18], %g3
F0069FE0: c406601c                 ld      [%i1+0x1C], %g2
F0069FE4: 8600c002                 add     %g3, %g2, %g3
F0069FE8: 80a0c018                 cmp     %g3, %i0
F0069FEC: 38800002                 bgu,a   loc_F0069FF4
F0069FF0: b0100003                 mov     %g3, %i0
F0069FF4: b406a001                 inc     %i2
F0069FF8: c4066004                 ld      [%i1+4], %g2
F0069FFC: 80a6801b                 cmp     %i2, %i3
F006A000: 0abffff3                 bcs     loc_F0069FCC
F006A004: b2064002                 add     %i1, %g2, %i1
F006A008: 81c7e008                 ret
F006A00C: 81e80000                 restore
