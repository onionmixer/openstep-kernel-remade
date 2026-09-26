F0024458: 9de3bf98                 save    %sp, -0x68, %sp
F002445C: b6100018                 mov     %i0, %i3
F0024460: b410001b                 mov     %i3, %i2
F0024464: 84068019                 add     %i2, %i1, %g2
F0024468: 80a68002                 cmp     %i2, %g2
F002446C: 1a80001d                 bcc     locret_F00244E0
F0024470: b0103fff                 mov     -1, %i0
F0024474: b8102001                 mov     1, %i4
F0024478: ba100002                 mov     %g2, %i5
F002447C: c44e8000                 ldsb    [%i2], %g2
F0024480: 80a0bfff                 cmp     %g2, -1
F0024484: 22800013                 be,a    loc_F00244D0
F0024488: b406a001                 inc     %i2
F002448C: b2102000                 mov     0, %i1
F0024490: 8426801b                 sub     %i2, %i3, %g2
F0024494: b128a003                 sll     %g2, 3, %i0
F0024498: c64e8000                 ldsb    [%i2], %g3
F002449C: 8538c019                 sra     %g3, %i1, %g2
F00244A0: 8088a001                 btst    1, %g2
F00244A4: 32800007                 bne,a   loc_F00244C0
F00244A8: b2066001                 inc     %i1
F00244AC: 852f0019                 sll     %i4, %i1, %g2
F00244B0: 8410c002                 bset    %g3, %g2
F00244B4: c42e8000                 stb     %g2, [%i2]
F00244B8: 1080000a                 ba      locret_F00244E0
F00244BC: b0060019                 add     %i0, %i1, %i0
F00244C0: 80a66007                 cmp     %i1, 7
F00244C4: 24bffff6                 ble,a   loc_F002449C
F00244C8: c64e8000                 ldsb    [%i2], %g3
F00244CC: b406a001                 inc     %i2
F00244D0: 80a6801d                 cmp     %i2, %i5
F00244D4: 2abfffeb                 bcs,a   loc_F0024480
F00244D8: c44e8000                 ldsb    [%i2], %g2
F00244DC: b0103fff                 mov     -1, %i0
F00244E0: 81c7e008                 ret
F00244E4: 81e80000                 restore
