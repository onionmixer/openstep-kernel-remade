F005847C: 9de3bf98                 save    %sp, -0x68, %sp
F0058480: e006201c                 ld      [%i0+0x1C], %l0
F0058484: d0040000                 ld      [%l0], %o0
F0058488: 80a22000                 cmp     %o0, 0
F005848C: 12bffffe                 bne     loc_F0058484
F0058490: 01000000                 nop
F0058494: 4000fa85                 call    _simple_lock_try
F0058498: 90100010                 mov     %l0, %o0
F005849C: 80a22000                 cmp     %o0, 0
F00584A0: 02bffff9                 be      loc_F0058484
F00584A4: 133c04ef                 sethi   %hi(_ipc_space_kernel), %o1
F00584A8: d004200c                 ld      [%l0+0xC], %o0
F00584AC: d2026330                 ld      [%o1+%lo(_ipc_space_kernel)], %o1
F00584B0: 80a20009                 cmp     %o0, %o1
F00584B4: 1280000d                 bne     loc_F00584E8
F00584B8: 113c04ef                 sethi   -0xFEC4400, %o0
F00584BC: c0240000                 clr     [%l0]
F00584C0: 40003441                 call    _ipc_kobject_server
F00584C4: 90100018                 mov     %i0, %o0
F00584C8: 80a22000                 cmp     %o0, 0
F00584CC: 028000b5                 be      loc_F00587A0
F00584D0: 13000040                 sethi   0x10000, %o1
F00584D4: 94102000                 mov     0, %o2
F00584D8: 7fffffe9                 call    _ipc_mqueue_send
F00584DC: 96102000                 mov     0, %o3
F00584E0: 108000b1                 ba      locret_F00587A4
F00584E4: b0102000                 mov     0, %i0
F00584E8: a4122300                 or      %o0, 0x300, %l2
F00584EC: 11040000a6122001         set     0x10000001, %l3
F00584F4: d0042008                 ld      [%l0+8], %o0
F00584F8: 80a22000                 cmp     %o0, 0
F00584FC: 26800015                 bl,a    loc_F0058550
F0058500: d2042038                 ld      [%l0+0x38], %o1
F0058504: d0042004                 ld      [%l0+4], %o0
F0058508: 90023fff                 inc     -1, %o0
F005850C: d0242004                 st      %o0, [%l0+4]
F0058510: c0240000                 clr     [%l0]
F0058514: 80a22000                 cmp     %o0, 0
F0058518: 3280000a                 bne,a   loc_F0058540
F005851C: c026201c                 clr     [%i0+0x1C]
F0058520: d0042008                 ld      [%l0+8], %o0
F0058524: 912a2001                 sll     %o0, 1, %o0
F0058528: 91322011                 srl     %o0, 17, %o0
F005852C: 912a2002                 sll     %o0, 2, %o0
F0058530: d0020012                 ld      [%o0+%l2], %o0
F0058534: 40008327                 call    _zfree
F0058538: 92100010                 mov     %l0, %o1
F005853C: c026201c                 clr     [%i0+0x1C]
F0058540: 7ffff23a                 call    _ipc_kmsg_destroy
F0058544: 90100018                 mov     %i0, %o0
F0058548: 10800097                 ba      locret_F00587A4
F005854C: b0102000                 mov     0, %i0
F0058550: d004203c                 ld      [%l0+0x3C], %o0
F0058554: 80a24008                 cmp     %o1, %o0
F0058558: 0a800039                 bcs     loc_F005863C
F005855C: 11000040                 sethi   0x10000, %o0
F0058560: 808e4008                 btst    %o0, %i1
F0058564: 32800037                 bne,a   loc_F0058640
F0058568: d2062014                 ld      [%i0+0x14], %o1
F005856C: d00e2017                 ldub    [%i0+0x17], %o0
F0058570: 80a22012                 cmp     %o0, 0x12
F0058574: 02800032                 be      loc_F005863C
F0058578: 113c04d0                 sethi   %hi(_active_threads), %o0
F005857C: 808e6010                 btst    0x10, %i1
F0058580: 02800009                 be      loc_F00585A4
F0058584: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0058588: 80a6a000                 cmp     %i2, 0
F005858C: 0280003a                 be      loc_F0058674
F0058590: 90100011                 mov     %l1, %o0
F0058594: 400038c5                 call    _thread_will_wait_with_timeout
F0058598: 9210001a                 mov     %i2, %o1
F005859C: 10800005                 ba      loc_F00585B0
F00585A0: 9004204c                 add     %l0, 0x4C, %o0 ! 'L'
F00585A4: 400038ac                 call    _thread_will_wait
F00585A8: 90100011                 mov     %l1, %o0
F00585AC: 9004204c                 add     %l0, 0x4C, %o0 ! 'L'
F00585B0: 400019f8                 call    _ipc_thread_enqueue
F00585B4: 92100011                 mov     %l1, %o1
F00585B8: e6246098                 st      %l3, [%l1+0x98]
F00585BC: c0240000                 clr     [%l0]
F00585C0: 40006460                 call    _thread_block_with_continuation
F00585C4: 90102000                 mov     0, %o0
F00585C8: d0040000                 ld      [%l0], %o0
F00585CC: 80a22000                 cmp     %o0, 0
F00585D0: 12bffffe                 bne     loc_F00585C8
F00585D4: 01000000                 nop
F00585D8: 4000fa34                 call    _simple_lock_try
F00585DC: 90100010                 mov     %l0, %o0
F00585E0: 80a22000                 cmp     %o0, 0
F00585E4: 02bffff9                 be      loc_F00585C8
F00585E8: 01000000                 nop
F00585EC: d0046098                 ld      [%l1+0x98], %o0
F00585F0: 80a22000                 cmp     %o0, 0
F00585F4: 22bfffc1                 be,a    loc_F00584F8
F00585F8: d0042008                 ld      [%l0+8], %o0
F00585FC: 9004204c                 add     %l0, 0x4C, %o0 ! 'L'
F0058600: 40001a04                 call    _ipc_thread_rmqueue
F0058604: 92100011                 mov     %l1, %o1
F0058608: d0046044                 ld      [%l1+0x44], %o0
F005860C: 80a22001                 cmp     %o0, 1
F0058610: 22bfffb9                 be,a    loc_F00584F4
F0058614: b4102000                 mov     0, %i2
F0058618: 26bfffb8                 bl,a    loc_F00584F8
F005861C: d0042008                 ld      [%l0+8], %o0
F0058620: 80a22003                 cmp     %o0, 3
F0058624: 34bfffb5                 bg,a    loc_F00584F8
F0058628: d0042008                 ld      [%l0+8], %o0
F005862C: c0240000                 clr     [%l0]
F0058630: 31040000                 sethi   0x10000000, %i0
F0058634: 1080005c                 ba      locret_F00587A4
F0058638: b0162007                 bset    7, %i0
F005863C: d2062014                 ld      [%i0+0x14], %o1
F0058640: 11100000                 sethi   0x40000000, %o0
F0058644: 808a4008                 btst    %o0, %o1
F0058648: 22800004                 be,a    loc_F0058658
F005864C: d0042038                 ld      [%l0+0x38], %o0
F0058650: c0240000                 clr     [%l0]
F0058654: 30bfffbb                 ba,a    loc_F0058540
F0058658: d2042030                 ld      [%l0+0x30], %o1
F005865C: 90022001                 inc     %o0
F0058660: 80a26000                 cmp     %o1, 0
F0058664: 1280000c                 bne     loc_F0058694
F0058668: d0242038                 st      %o0, [%l0+0x38]
F005866C: 1080000b                 ba      loc_F0058698
F0058670: a2042040                 add     %l0, 0x40, %l1 ! '@'
F0058674: c0240000                 clr     [%l0]
F0058678: 31040000                 sethi   0x10000000, %i0
F005867C: 1080004a                 ba      locret_F00587A4
F0058680: b0162004                 bset    4, %i0
F0058684: 40003821                 call    _thread_go_and_switch
F0058688: 9210000a                 mov     %o2, %o1
F005868C: 10800046                 ba      locret_F00587A4
F0058690: b0102000                 mov     0, %i0
F0058694: a2026010                 add     %o1, 0x10, %l1
F0058698: d0044000                 ld      [%l1], %o0
F005869C: 80a22000                 cmp     %o0, 0
F00586A0: 12bffffe                 bne     loc_F0058698
F00586A4: 01000000                 nop
F00586A8: 4000fa00                 call    _simple_lock_try
F00586AC: 90100011                 mov     %l1, %o0
F00586B0: 80a22000                 cmp     %o0, 0
F00586B4: 02bffff9                 be      loc_F0058698
F00586B8: b4046008                 add     %l1, 8, %i2
F00586BC: c0240000                 clr     [%l0]
F00586C0: 27000080                 sethi   0x20000, %l3
F00586C4: 11040010a4122004         set     0x10004004, %l2
F00586CC: d4068000                 ld      [%i2], %o2
F00586D0: 80a2a000                 cmp     %o2, 0
F00586D4: 32800011                 bne,a   loc_F0058718
F00586D8: d202a090                 ld      [%o2+0x90], %o1
F00586DC: d2046004                 ld      [%l1+4], %o1
F00586E0: 80a26000                 cmp     %o1, 0
F00586E4: 2280000a                 be,a    loc_F005870C
F00586E8: f0246004                 st      %i0, [%l1+4]
F00586EC: d0026004                 ld      [%o1+4], %o0
F00586F0: d2260000                 st      %o1, [%i0]
F00586F4: d0262004                 st      %o0, [%i0+4]
F00586F8: f0226004                 st      %i0, [%o1+4]
F00586FC: f0220000                 st      %i0, [%o0]
F0058700: c0244000                 clr     [%l1]
F0058704: 10800028                 ba      locret_F00587A4
F0058708: b0102000                 mov     0, %i0
F005870C: f0260000                 st      %i0, [%i0]
F0058710: 10bffffc                 ba      loc_F0058700
F0058714: f0262004                 st      %i0, [%i0+4]
F0058718: 80a2400a                 cmp     %o1, %o2
F005871C: 22800008                 be,a    loc_F005873C
F0058720: c0268000                 clr     [%i2]
F0058724: d002a094                 ld      [%o2+0x94], %o0
F0058728: d2268000                 st      %o1, [%i2]
F005872C: d0226094                 st      %o0, [%o1+0x94]
F0058730: d2222090                 st      %o1, [%o0+0x90]
F0058734: d422a090                 st      %o2, [%o2+0x90]
F0058738: d422a094                 st      %o2, [%o2+0x94]
F005873C: d2062018                 ld      [%i0+0x18], %o1
F0058740: d002a09c                 ld      [%o2+0x9C], %o0
F0058744: 80a24008                 cmp     %o1, %o0
F0058748: 1880000f                 bgu     loc_F0058784
F005874C: 808e4013                 btst    %l3, %i1
F0058750: c022a098                 clr     [%o2+0x98]
F0058754: f022a09c                 st      %i0, [%o2+0x9C]
F0058758: d2042034                 ld      [%l0+0x34], %o1
F005875C: 90026001                 add     %o1, 1, %o0
F0058760: d0242034                 st      %o0, [%l0+0x34]
F0058764: d222a0a0                 st      %o1, [%o2+0xA0]
F0058768: c0244000                 clr     [%l1]
F005876C: 12bfffc6                 bne     loc_F0058684
F0058770: 9010001b                 mov     %i3, %o0
F0058774: 400037a8                 call    _thread_go
F0058778: 9010000a                 mov     %o2, %o0
F005877C: 1080000a                 ba      locret_F00587A4
F0058780: b0102000                 mov     0, %i0
F0058784: e422a098                 st      %l2, [%o2+0x98]
F0058788: d2062018                 ld      [%i0+0x18], %o1
F005878C: 9010000a                 mov     %o2, %o0
F0058790: 400037a1                 call    _thread_go
F0058794: d222209c                 st      %o1, [%o0+0x9C]
F0058798: 10bfffce                 ba      loc_F00586D0
F005879C: d4068000                 ld      [%i2], %o2
F00587A0: b0102000                 mov     0, %i0
F00587A4: 81c7e008                 ret
F00587A8: 81e80000                 restore
