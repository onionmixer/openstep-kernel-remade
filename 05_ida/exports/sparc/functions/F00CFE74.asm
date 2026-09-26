F00CFE74: 9de3bf78                 save    %sp, -0x88, %sp
F00CFE78: b72ee018                 sll     %i3, 24, %i3
F00CFE7C: 80a6e000                 cmp     %i3, 0
F00CFE80: 02800006                 be      loc_F00CFE98
F00CFE84: 9007bfe0                 add     %fp, var_20, %o0! void *
F00CFE88: 9206a002                 add     %i2, 2, %o1
F00CFE8C: 94102004                 mov     4, %o2
F00CFE90: 10800005                 ba      loc_F00CFEA4
F00CFE94: 96102028                 mov     0x28, %o3 ! '('
F00CFE98: 9206a002                 add     %i2, 2, %o1! void *
F00CFE9C: 94102004                 mov     4, %o2! size_t
F00CFEA0: 9610202a                 mov     0x2A, %o3 ! '*'
F00CFEA4: d80e2189                 ldub    [%i0+0x189], %o4
F00CFEA8: a12f6010                 sll     %i5, 16, %l0
F00CFEAC: f827bfe0                 st      %i4, [%fp+var_20]
F00CFEB0: d62e8000                 stb     %o3, [%i2]
F00CFEB4: d60ea001                 ldub    [%i2+1], %o3
F00CFEB8: 992b2005                 sll     %o4, 5, %o4
F00CFEBC: 960ae01f                 and     %o3, 0x1F, %o3
F00CFEC0: 9612c00c                 bset    %o4, %o3
F00CFEC4: 7fff1313                 call    _bcopy
F00CFEC8: d62ea001                 stb     %o3, [%i2+1]
F00CFECC: 91342018                 srl     %l0, 24, %o0
F00CFED0: d02ea007                 stb     %o0, [%i2+7]
F00CFED4: a1342010                 srl     %l0, 16, %l0
F00CFED8: e02ea008                 stb     %l0, [%i2+8]
F00CFEDC: 81c7e008                 ret
F00CFEE0: 81e80000                 restore
