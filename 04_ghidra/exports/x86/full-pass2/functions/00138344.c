/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138344 */

undefined4 _xdrmbuf_getbytes(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = *(int *)(param_1 + 0x14) - param_3;
    *(int *)(param_1 + 0x14) = iVar2;
    if (-1 < iVar2) {
      _bcopy(*(void **)(param_1 + 0xc),param_2,param_3);
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
      return 1;
    }
    sVar1 = *(int *)(param_1 + 0x14) + param_3;
    *(size_t *)(param_1 + 0x14) = sVar1;
    if (0 < (int)sVar1) {
      _bcopy(*(void **)(param_1 + 0xc),param_2,sVar1);
      param_2 = (void *)((int)param_2 + *(int *)(param_1 + 0x14));
      param_3 = param_3 - *(int *)(param_1 + 0x14);
    }
    if (*(int **)(param_1 + 0x10) == (int *)0x0) break;
    iVar2 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0xc) = *(int *)(iVar2 + 4) + iVar2;
    *(int *)(param_1 + 0x14) = (int)*(short *)(iVar2 + 8);
  }
  return 0;
}

