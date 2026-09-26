F0042B98: 9de3bf98                 save    %sp, -0x68, %sp
F0042B9C: c6062008                 ld      [%i0+8], %g3
F0042BA0: f420e010                 st      %i2, [%g3+0x10]
F0042BA4: c4064000                 ld      [%i1], %g2
F0042BA8: c420e018                 st      %g2, [%g3+0x18]
F0042BAC: c4066004                 ld      [%i1+4], %g2
F0042BB0: c420e01c                 st      %g2, [%g3+0x1C]
F0042BB4: c4066008                 ld      [%i1+8], %g2
F0042BB8: c420e020                 st      %g2, [%g3+0x20]
F0042BBC: c406600c                 ld      [%i1+0xC], %g2
F0042BC0: c420e024                 st      %g2, [%g3+0x24]
F0042BC4: f620e074                 st      %i3, [%g3+0x74]
F0042BC8: c416c000                 lduh    [%i3], %g2
F0042BCC: 8400a001                 inc     %g2
F0042BD0: c436c000                 sth     %g2, [%i3]
F0042BD4: c400c000                 ld      [%g3], %g2
F0042BD8: 8408a018                 and     %g2, 0x18, %g2
F0042BDC: c420c000                 st      %g2, [%g3]
F0042BE0: 81c7e008                 ret
F0042BE4: 81e80000                 restore
