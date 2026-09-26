F006C8F4: 9de3bf98                 save    %sp, -0x68, %sp
F006C8F8: 113c04f0a0122210         set     _vm_info_lock_data, %l0
F006C900: d0040000                 ld      [%l0], %o0
F006C904: 80a22000                 cmp     %o0, 0
F006C908: 12bffffe                 bne     loc_F006C900
F006C90C: 01000000                 nop
F006C910: 4000a966                 call    _simple_lock_try
F006C914: 90100010                 mov     %l0, %o0
F006C918: 80a22000                 cmp     %o0, 0
F006C91C: 02bffff9                 be      loc_F006C900
F006C920: 01000000                 nop
F006C924: d0162006                 lduh    [%i0+6], %o0
F006C928: 90023fff                 inc     -1, %o0
F006C92C: d0362006                 sth     %o0, [%i0+6]
F006C930: 912a2010                 sll     %o0, 16, %o0
F006C934: 80a22000                 cmp     %o0, 0
F006C938: 32800005                 bne,a   loc_F006C94C
F006C93C: 113c04f0                 sethi   -0xFEC4000, %o0
F006C940: 7ffffe32                 call    _vm_info_enqueue
F006C944: 90100018                 mov     %i0, %o0
F006C948: 113c04f0                 sethi   -0xFEC4000, %o0
F006C94C: c0222210                 clr     [%o0+0x210]
F006C950: 7ffff1b9                 call    _lock_done
F006C954: 90062018                 add     %i0, 0x18, %o0
F006C958: 113c043f                 sethi   %hi(_mfs_files_mapped), %o0
F006C95C: d202212c                 ld      [%o0+%lo(_mfs_files_mapped)], %o1
F006C960: 113c043f                 sethi   %hi(_mfs_files_max), %o0
F006C964: d0022128                 ld      [%o0+%lo(_mfs_files_max)], %o0
F006C968: 80a24008                 cmp     %o1, %o0
F006C96C: 24800005                 ble,a   loc_F006C980
F006C970: d2062038                 ld      [%i0+0x38], %o1
F006C974: 40000056                 call    _mfs_cache_trim
F006C978: 01000000                 nop
F006C97C: d2062038                 ld      [%i0+0x38], %o1
F006C980: 11040000                 sethi   0x10000000, %o0
F006C984: 808a4008                 btst    %o0, %o1
F006C988: 02800005                 be      locret_F006C99C
F006C98C: 902a4008                 andn    %o1, %o0, %o0
F006C990: d0262038                 st      %o0, [%i0+0x38]
F006C994: 400002b3                 call    _vmp_invalidate
F006C998: 90100018                 mov     %i0, %o0
F006C99C: 81c7e008                 ret
F006C9A0: 81e80000                 restore
