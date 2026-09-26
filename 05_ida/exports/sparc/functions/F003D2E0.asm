F003D2E0: 9de3bf98                 save    %sp, -0x68, %sp
F003D2E4: a0100018                 mov     %i0, %l0
F003D2E8: d00c200a                 ldub    [%l0+0xA], %o0
F003D2EC: d40c200b                 ldub    [%l0+0xB], %o2
F003D2F0: d20c200c                 ldub    [%l0+0xC], %o1
F003D2F4: d60c2019                 ldub    [%l0+0x19], %o3
F003D2F8: 901a000a                 btog    %o2, %o0
F003D2FC: d40c200d                 ldub    [%l0+0xD], %o2
F003D300: 921a4008                 btog    %o0, %o1
F003D304: d00c200e                 ldub    [%l0+0xE], %o0
F003D308: 941a8009                 btog    %o1, %o2
F003D30C: d20c200f                 ldub    [%l0+0xF], %o1
F003D310: 901a000a                 btog    %o2, %o0
F003D314: d40c2010                 ldub    [%l0+0x10], %o2
F003D318: 921a4008                 btog    %o0, %o1
F003D31C: d00c2011                 ldub    [%l0+0x11], %o0
F003D320: 941a8009                 btog    %o1, %o2
F003D324: d20c2014                 ldub    [%l0+0x14], %o1
F003D328: 901a000a                 btog    %o2, %o0
F003D32C: d40c2015                 ldub    [%l0+0x15], %o2
F003D330: 921a4008                 btog    %o0, %o1
F003D334: d00c2016                 ldub    [%l0+0x16], %o0
F003D338: 941a8009                 btog    %o1, %o2
F003D33C: d20c2017                 ldub    [%l0+0x17], %o1
F003D340: 901a000a                 btog    %o2, %o0
F003D344: d40c2018                 ldub    [%l0+0x18], %o2
F003D348: 921a4008                 btog    %o0, %o1
F003D34C: 941a8009                 btog    %o1, %o2! size_t
F003D350: d20c201a                 ldub    [%l0+0x1A], %o1
F003D354: 961ac00a                 btog    %o2, %o3
F003D358: d00c201b                 ldub    [%l0+0x1B], %o0
F003D35C: 921a400b                 btog    %o3, %o1
F003D360: 901a0009                 btog    %o1, %o0
F003D364: 900a203f                 and     %o0, 0x3F, %o0
F003D368: 133c04ea921262a0         set     _rtable, %o1
F003D370: 912a2002                 sll     %o0, 2, %o0
F003D374: f0020009                 ld      [%o0+%o1], %i0
F003D378: 80a62000                 cmp     %i0, 0
F003D37C: 2280002b                 be,a    locret_F003D428
F003D380: b0102000                 mov     0, %i0
F003D384: 253c04ea                 sethi   -0xFEC5800, %l2
F003D388: 233c04ea                 sethi   -0xFEC5800, %l1
F003D38C: 90062040                 add     %i0, 0x40, %o0 ! '@'! void *
F003D390: 92100010                 mov     %l0, %o1! void *
F003D394: 7fff22f2                 call    _bcmp
F003D398: 94102020                 mov     0x20, %o2 ! ' '
F003D39C: 80a22000                 cmp     %o0, 0
F003D3A0: 3280001e                 bne,a   loc_F003D418
F003D3A4: f0062008                 ld      [%i0+8], %i0
F003D3A8: d0062030                 ld      [%i0+0x30], %o0
F003D3AC: 80a64008                 cmp     %i1, %o0
F003D3B0: 3280001a                 bne,a   loc_F003D418
F003D3B4: f0062008                 ld      [%i0+8], %i0
F003D3B8: d0162012                 lduh    [%i0+0x12], %o0
F003D3BC: 90022001                 inc     %o0
F003D3C0: d0362012                 sth     %o0, [%i0+0x12]
F003D3C4: 912a2010                 sll     %o0, 16, %o0
F003D3C8: 91322010                 srl     %o0, 16, %o0
F003D3CC: 80a22001                 cmp     %o0, 1
F003D3D0: 1280000d                 bne     loc_F003D404
F003D3D4: d0046248                 ld      [%l1+0x248], %o0
F003D3D8: 7fffff8f                 call    sub_F003D214
F003D3DC: 90100018                 mov     %i0, %o0
F003D3E0: d0062030                 ld      [%i0+0x30], %o0
F003D3E4: d204a288                 ld      [%l2+0x288], %o1
F003D3E8: d4022128                 ld      [%o0+0x128], %o2
F003D3EC: 92026001                 inc     %o1
F003D3F0: d002a018                 ld      [%o2+0x18], %o0
F003D3F4: d224a288                 st      %o1, [%l2+0x288]
F003D3F8: 90022001                 inc     %o0
F003D3FC: 10800004                 ba      loc_F003D40C
F003D400: d022a018                 st      %o0, [%o2+0x18]
F003D404: 90022001                 inc     %o0
F003D408: d0246248                 st      %o0, [%l1+0x248]
F003D40C: 7fffff82                 call    sub_F003D214
F003D410: 90100018                 mov     %i0, %o0
F003D414: 30800005                 ba,a    locret_F003D428
F003D418: 80a62000                 cmp     %i0, 0
F003D41C: 12bfffdd                 bne     loc_F003D390
F003D420: 90062040                 add     %i0, 0x40, %o0 ! '@'
F003D424: b0102000                 mov     0, %i0
F003D428: 81c7e008                 ret
F003D42C: 81e80000                 restore
