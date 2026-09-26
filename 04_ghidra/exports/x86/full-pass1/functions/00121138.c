/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121138 */

undefined4 _if_output_mbuf(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_18;
  uint local_14;
  void *local_10;
  uint local_c;
  
  local_c = 0;
  for (puVar1 = param_2; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    local_c = local_c + (int)*(short *)(puVar1 + 2);
  }
  if ((int)*(short *)(param_1 + 10) < (int)local_c) {
    _m_freem(param_2);
    uVar2 = 0x28;
  }
  else {
    iVar3 = (**(code **)(param_1 + 0x40))(param_1);
    if (iVar3 == 0) {
      _m_freem(param_2);
      uVar2 = 0x37;
    }
    else {
      local_10 = (void *)_nb_map(iVar3);
      local_14 = 0;
      uVar6 = 0;
      local_18 = local_c;
      for (puVar1 = param_2; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
        if ((uVar6 <= local_14) && (local_14 < (int)*(short *)(puVar1 + 2) + uVar6)) {
          uVar5 = (int)*(short *)(puVar1 + 2) - (local_14 - uVar6);
          if (local_18 < uVar5) {
            uVar5 = local_18;
          }
          _bcopy((void *)((int)puVar1 + (local_14 - uVar6) + puVar1[1]),local_10,uVar5);
          local_10 = (void *)((int)local_10 + uVar5);
          local_14 = local_14 + uVar5;
          local_18 = local_18 - uVar5;
          if (local_18 == 0) break;
        }
        uVar6 = uVar6 + (int)*(short *)(puVar1 + 2);
      }
      iVar4 = _nb_size(iVar3);
      _nb_shrink_bot(iVar3,iVar4 - local_c);
      _m_freem(param_2);
      uVar2 = (**(code **)(param_1 + 0x34))(param_1,iVar3,param_3);
    }
  }
  return uVar2;
}

