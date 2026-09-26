/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ce08 */

void _addupc(int param_1,int param_2,short param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  short local_6;
  
  if (param_2 != 0) {
    iVar3 = param_2;
    do {
      uVar2 = param_1 - *(int *)(iVar3 + 0x10);
      uVar1 = *(uint *)(iVar3 + 8);
      uVar2 = ((uVar2 >> 0x10) * *(int *)(iVar3 + 0x14) +
               ((uVar2 & 0xffff) * *(int *)(iVar3 + 0x14) >> 0x10) & 0xfffffffe) + uVar1;
      if ((uVar1 <= uVar2) && (uVar2 < uVar1 + *(int *)(iVar3 + 0xc))) {
        iVar3 = _copyin(uVar2,&local_6,2);
        if (iVar3 != 0) {
          *(undefined4 *)(param_2 + 0x14) = 0;
          return;
        }
        local_6 = local_6 + param_3;
        _copyout(&local_6,uVar2,2);
        return;
      }
      iVar3 = *(int *)(iVar3 + 4);
    } while (iVar3 != 0);
  }
  return;
}

