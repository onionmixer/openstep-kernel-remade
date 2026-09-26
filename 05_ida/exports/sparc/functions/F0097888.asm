F0097888: 9de3bf98                 save    %sp, -0x68, %sp
F009788C: 113c04c5                 sethi   %hi(qword_F0131478), %o0
F0097890: 94102000                 mov     0, %o2
F0097894: 96102000                 mov     0, %o3
F0097898: d43a2078                 std     %o2, [%o0+%lo(qword_F0131478)]
F009789C: 253c04c5                 sethi   %hi(qword_F0131468), %l2
F00978A0: d43ca068                 std     %o2, [%l2+%lo(qword_F0131468)]
F00978A4: 213c043ea01423e8         set     _time, %l0
F00978AC: e023a040                 st      %l0, [%sp+0x68+var_28]
F00978B0: 400037ec                 call    _get_tod
F00978B4: 01000000                 nop
F00978B8: 00000008                 illtrap
F00978BC: c0242004                 clr     [%l0+4]
F00978C0: 7fff5a5f                 call    _timeval_to_ns_time
F00978C4: 90100010                 mov     %l0, %o0
F00978C8: a0100008                 mov     %o0, %l0
F00978CC: a2100009                 mov     %o1, %l1
F00978D0: 4000000e                 call    _clock_value
F00978D4: 90102001                 mov     1, %o0
F00978D8: a2a44009                 subcc   %l1, %o1, %l1
F00978DC: a0640008                 subc    %l0, %o0, %l0
F00978E0: 7ffffcaa                 call    _splusclock
F00978E4: e03ca068                 std     %l0, [%l2+0x68]
F00978E8: 7fffffe3                 call    _us_spin_calibrate
F00978EC: a0100008                 mov     %o0, %l0
F00978F0: 40003686                 call    _startrtclock
F00978F4: 01000000                 nop
F00978F8: 7ffffd0b                 call    _splx
F00978FC: 90100010                 mov     %l0, %o0
F0097900: 81c7e008                 ret
F0097904: 81e80000                 restore
