/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001037d0 */

int _add_profil(char *param_1,size_t param_2,ulong param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _active_u;
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = DAT_001e875c;
  if (*(int *)(_active_u + 0x25c) != 0) {
    iVar3 = _kalloc(0x18);
    *(undefined4 *)(iVar3 + 8) = *puVar1;
    *(undefined4 *)(iVar3 + 0xc) = puVar1[1];
    *(undefined4 *)(iVar3 + 0x10) = puVar1[2];
    *(undefined4 *)(iVar3 + 0x14) = puVar1[3];
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar2 + 0x24c);
    *(int *)(iVar2 + 0x24c) = iVar3;
  }
  return iVar3;
}

