/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118868 */

undefined4 _unp_connect2(short *param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffff0;
  iVar1 = *(int *)(param_1 + 4);
  if (*param_2 == *param_1) {
    iVar2 = *(int *)(param_2 + 4);
    *(int *)(iVar1 + 0xc) = iVar2;
    if (*param_1 == 1) {
      *(int *)(iVar2 + 0xc) = iVar1;
      puVar4 = &stack0xffffffec;
      _soisconnected();
    }
    else {
      if (*param_1 != 2) {
                    /* WARNING: Subroutine does not return */
        _panic(s_unp_connect2_001db404);
      }
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
      *(int *)(iVar2 + 0x10) = iVar1;
    }
    *(short **)(puVar4 + -4) = param_1;
    *(undefined4 *)(puVar4 + -8) = 0x1188b7;
    _soisconnected();
    uVar3 = 0;
  }
  else {
    uVar3 = 0x29;
  }
  return uVar3;
}

