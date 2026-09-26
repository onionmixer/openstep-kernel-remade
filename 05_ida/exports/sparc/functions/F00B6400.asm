F00B6400: 9de3bf98                 save    %sp, -0x68, %sp
F00B6404: 213c047a                 sethi   %hi(aTwoByteMessage), %l0! "Two byte message '%s' 0x%x rejected"
F00B6408: d00e2054                 ldub    [%i0+0x54], %o0
F00B640C: 40000bf3                 call    _scsi_mname
F00B6410: a0142080                 bset    %lo(aTwoByteMessage), %l0! "Two byte message '%s' 0x%x rejected"
F00B6414: 96100008                 mov     %o0, %o3
F00B6418: 90100018                 mov     %i0, %o0
F00B641C: 92102004                 mov     4, %o1
F00B6420: d80a2055                 ldub    [%o0+0x55], %o4
F00B6424: 400005f2                 call    _esplog
F00B6428: 94100010                 mov     %l0, %o2
F00B642C: 81c7e008                 ret
F00B6430: 91e82007                 restore %g0, 7, %o0
