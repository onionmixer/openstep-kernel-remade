/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118a20 */

undefined4 _unp_externalize(int param_1)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  
  uVar6 = (uint)(int)*(short *)(param_1 + 8) >> 2;
  piVar7 = (int *)(param_1 + *(int *)(param_1 + 4));
  iVar3 = _ufavail();
  if (iVar3 < (int)uVar6) {
    iVar3 = 0;
    if (uVar6 != 0) {
      do {
        _unp_discard(*piVar7);
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)uVar6);
    }
    uVar4 = 0x28;
  }
  else {
    iVar3 = 0;
    if (uVar6 != 0) {
      do {
        iVar5 = _ufalloc(0);
        if (iVar5 < 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_unp_externalize_001db420);
        }
        iVar2 = *piVar7;
        *(int *)(*(int *)(_active_u + 0x150) + iVar5 * 4) = iVar2;
        psVar1 = (short *)(iVar2 + 0x10);
        *psVar1 = *psVar1 + -1;
        _unp_rights = _unp_rights + -1;
        *piVar7 = iVar5;
        piVar7 = piVar7 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)uVar6);
    }
    uVar4 = 0;
  }
  return uVar4;
}

