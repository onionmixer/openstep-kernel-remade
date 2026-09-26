F00B52F4: 9de3bf98                 save    %sp, -0x68, %sp
F00B52F8: a0100018                 mov     %i0, %l0
F00B52FC: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B5300: d20c2043                 ldub    [%l0+0x43], %o1
F00B5304: d404209c                 ld      [%l0+0x9C], %o2
F00B5308: 912a2002                 sll     %o0, 2, %o0
F00B530C: 90020010                 add     %o0, %l0, %o0
F00B5310: 920a6007                 and     %o1, 7, %o1
F00B5314: 80a26006                 cmp     %o1, 6
F00B5318: 02800013                 be      loc_F00B5364
F00B531C: f00220b8                 ld      [%o0+0xB8], %i0
F00B5320: d00c2042                 ldub    [%l0+0x42], %o0
F00B5324: 80a22004                 cmp     %o0, 4
F00B5328: 12800010                 bne     loc_F00B5368
F00B532C: 92102001                 mov     1, %o1
F00B5330: 153c0479                 sethi   %hi(aTargetDRefused), %o2! "Target %d refused message resend"
F00B5334: 90100010                 mov     %l0, %o0
F00B5338: 92102004                 mov     4, %o1
F00B533C: d6162008                 lduh    [%i0+8], %o3
F00B5340: 40000a2b                 call    _esplog
F00B5344: 9412a178                 bset    %lo(aTargetDRefused), %o2! "Target %d refused message resend"
F00B5348: 9010200b                 mov     0xB, %o0
F00B534C: d02e2028                 stb     %o0, [%i0+0x28]
F00B5350: d00c2041                 ldub    [%l0+0x41], %o0
F00B5354: b0102002                 mov     2, %i0
F00B5358: d02c2042                 stb     %o0, [%l0+0x42]
F00B535C: 1080001e                 ba      loc_F00B53D4
F00B5360: 9010201a                 mov     0x1A, %o0
F00B5364: 92102001                 mov     1, %o1
F00B5368: d22aa00c                 stb     %o1, [%o2+0xC]
F00B536C: d00c2053                 ldub    [%l0+0x53], %o0
F00B5370: 80a22000                 cmp     %o0, 0
F00B5374: 32800007                 bne,a   loc_F00B5390
F00B5378: 92102000                 mov     0, %o1
F00B537C: 90102008                 mov     8, %o0
F00B5380: d02c204c                 stb     %o0, [%l0+0x4C]
F00B5384: d22c2053                 stb     %o1, [%l0+0x53]
F00B5388: d00c2053                 ldub    [%l0+0x53], %o0
F00B538C: 92102000                 mov     0, %o1
F00B5390: 80a24008                 cmp     %o1, %o0
F00B5394: 1680000b                 bge     loc_F00B53C0
F00B5398: 90102010                 mov     0x10, %o0
F00B539C: 90040009                 add     %l0, %o1, %o0
F00B53A0: d00a204c                 ldub    [%o0+0x4C], %o0
F00B53A4: d02aa008                 stb     %o0, [%o2+8]
F00B53A8: d00c2053                 ldub    [%l0+0x53], %o0
F00B53AC: 92026001                 inc     %o1
F00B53B0: 80a24008                 cmp     %o1, %o0
F00B53B4: 06bffffb                 bl      loc_F00B53A0
F00B53B8: 90040009                 add     %l0, %o1, %o0
F00B53BC: 90102010                 mov     0x10, %o0
F00B53C0: d02aa00c                 stb     %o0, [%o2+0xC]
F00B53C4: d00c2041                 ldub    [%l0+0x41], %o0
F00B53C8: b0103fff                 mov     -1, %i0
F00B53CC: d02c2042                 stb     %o0, [%l0+0x42]
F00B53D0: 90102004                 mov     4, %o0
F00B53D4: d02c2041                 stb     %o0, [%l0+0x41]
F00B53D8: 81c7e008                 ret
F00B53DC: 81e80000                 restore
