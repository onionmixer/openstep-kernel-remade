/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010374c */

int _profil(char *param_1,size_t param_2,ulong param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = _active_u;
  puVar4 = *(undefined4 **)(DAT_001e875c + 0x24);
  *(undefined4 *)(_active_u + 0x250) = *puVar4;
  *(undefined4 *)(iVar3 + 0x254) = puVar4[1];
  *(undefined4 *)(iVar3 + 600) = puVar4[2];
  *(undefined4 *)(iVar3 + 0x25c) = puVar4[3];
  if (*(int *)(iVar3 + 0x248) == 0) {
    puVar4 = (undefined4 *)_simple_lock_alloc();
    *(undefined4 **)(iVar3 + 0x248) = puVar4;
    *puVar4 = 0;
  }
  iVar2 = *(int *)(iVar3 + 0x24c);
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    _kfree(iVar2,0x18);
    iVar2 = iVar1;
  }
  *(undefined4 *)(iVar3 + 0x24c) = 0;
  return 0;
}

