/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00103e60 */

int _dup(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int unaff_EBX;
  int unaff_ESI;
  
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  uVar2 = *puVar1;
  if ((uVar2 & 0xffffffc0) != 0) {
    *puVar1 = uVar2 & 0x3f;
    iVar3 = _dup2(unaff_EBX,unaff_ESI);
    return iVar3;
  }
  if (((uVar2 < *(uint *)(_active_u + 0x15c)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x150) + uVar2 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    iVar4 = _ufalloc(0);
    if (iVar4 < 0) {
      return iVar4;
    }
    if (*(int *)(*(int *)(_active_u + 0x150) + *puVar1 * 4) == iVar3) {
      iVar3 = _dupit(iVar4,iVar3,(int)*(char *)(*puVar1 + *(int *)(_active_u + 0x154)));
      return iVar3;
    }
    *(undefined4 *)(*(int *)(_active_u + 0x150) + iVar4 * 4) = 0;
  }
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = 9;
  return iVar3;
}

