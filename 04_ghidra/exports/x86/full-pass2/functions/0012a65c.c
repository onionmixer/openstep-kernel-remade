/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a65c */

void * _tcp_newtcpcb(int param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)_kalloc(0x6c);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    _bzero(pvVar1,0x6c);
    *(void **)((int)pvVar1 + 4) = pvVar1;
    *(void **)pvVar1 = pvVar1;
    *(undefined2 *)((int)pvVar1 + 0x18) = _tcp_mssdflt;
    *(undefined1 *)((int)pvVar1 + 0x1b) = 0;
    *(int *)((int)pvVar1 + 0x20) = param_1;
    *(undefined2 *)((int)pvVar1 + 0x60) = 0;
    *(short *)((int)pvVar1 + 0x62) = _tcp_rttdflt << 3;
    *(undefined2 *)((int)pvVar1 + 100) = 2;
    *(undefined2 *)((int)pvVar1 + 0x14) = 0xc;
    *(undefined2 *)((int)pvVar1 + 0x54) = 0xffff;
    *(undefined2 *)((int)pvVar1 + 0x56) = 0xffff;
    *(void **)(param_1 + 0x20) = pvVar1;
  }
  return pvVar1;
}

