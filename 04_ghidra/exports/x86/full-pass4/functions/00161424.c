/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161424 */

void _pset_remove_processor(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 300) != param_1) {
                    /* WARNING: Subroutine does not return */
    _panic(s_pset_remove_processor__wrong_pse_001df228);
  }
  iVar1 = *(int *)(param_2 + 0x134);
  iVar2 = *(int *)(param_2 + 0x138);
  if (param_1 + 0x11c == iVar1) {
    *(int *)(param_1 + 0x120) = iVar2;
  }
  else {
    *(int *)(iVar1 + 0x138) = iVar2;
  }
  if (param_1 + 0x11c == iVar2) {
    *(int *)(param_1 + 0x11c) = iVar1;
  }
  else {
    *(int *)(iVar2 + 0x134) = iVar1;
  }
  *(undefined4 *)(param_2 + 300) = 0;
  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + -1;
  _quantum_set(param_1);
  return;
}

