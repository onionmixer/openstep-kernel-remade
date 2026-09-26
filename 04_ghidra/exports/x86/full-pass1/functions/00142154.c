/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142154 */

void FUN_00142154(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  if ((int)param_1[2] < 1) {
    iVar4 = (*param_1 & 0x3f) * 4;
    puVar1 = (uint *)(&_lf_svnode_hash + iVar4);
    uVar2 = *(uint *)(&_lf_svnode_hash + iVar4);
    while( true ) {
      if (uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_lf_free_svnode__cannot_find_shad_001de054);
      }
      puVar3 = (uint *)*puVar1;
      if (puVar3 == param_1) break;
      puVar1 = puVar3 + 3;
      uVar2 = puVar3[3];
    }
    _vn_rele(*puVar3);
    *puVar1 = puVar3[3];
    _kfree(puVar3,0x10);
  }
  return;
}

