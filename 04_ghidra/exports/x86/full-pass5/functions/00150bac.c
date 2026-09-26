/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00150bac */

void _ipc_splay_tree_insert(uint *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint *local_18;
  uint *local_14;
  uint local_8;
  
  local_8 = param_1[1];
  if (local_8 == 0) {
    *(undefined4 *)(param_3 + 0x18) = 0;
    *(undefined4 *)(param_3 + 0x1c) = 0;
  }
  else {
    if (*param_1 != param_2) {
      puVar1 = (undefined4 *)param_1[5];
      *(undefined4 *)param_1[3] = *(undefined4 *)(local_8 + 0x18);
      *puVar1 = *(undefined4 *)(local_8 + 0x1c);
      *(uint *)(local_8 + 0x18) = param_1[2];
      *(uint *)(local_8 + 0x1c) = param_1[4];
      local_18 = param_1 + 2;
      local_14 = param_1 + 4;
      while (param_2 != *(uint *)(local_8 + 0x10)) {
        if (param_2 < *(uint *)(local_8 + 0x10)) {
          uVar2 = *(uint *)(local_8 + 0x18);
          if (uVar2 == 0) break;
          uVar3 = *(uint *)(uVar2 + 0x10);
          if ((param_2 < uVar3) && (*(int *)(uVar2 + 0x18) != 0)) {
            *(undefined4 *)(local_8 + 0x18) = *(undefined4 *)(uVar2 + 0x1c);
            *(uint *)(uVar2 + 0x1c) = local_8;
            local_8 = uVar2;
          }
          *local_14 = local_8;
          local_14 = (uint *)(local_8 + 0x18);
          local_8 = *(uint *)(local_8 + 0x18);
          if ((uVar3 < param_2) && (*(int *)(uVar2 + 0x1c) != 0)) {
            *local_18 = local_8;
            local_18 = (uint *)(local_8 + 0x1c);
            local_8 = *(uint *)(local_8 + 0x1c);
          }
        }
        else {
          uVar2 = *(uint *)(local_8 + 0x1c);
          if (uVar2 == 0) break;
          uVar3 = *(uint *)(uVar2 + 0x10);
          if ((uVar3 < param_2) && (*(int *)(uVar2 + 0x1c) != 0)) {
            *(undefined4 *)(local_8 + 0x1c) = *(undefined4 *)(uVar2 + 0x18);
            *(uint *)(uVar2 + 0x18) = local_8;
            local_8 = uVar2;
          }
          *local_18 = local_8;
          local_18 = (uint *)(local_8 + 0x1c);
          local_8 = *(uint *)(local_8 + 0x1c);
          if ((param_2 < uVar3) && (*(int *)(uVar2 + 0x18) != 0)) {
            *local_14 = local_8;
            local_14 = (uint *)(local_8 + 0x18);
            local_8 = *(uint *)(local_8 + 0x18);
          }
        }
      }
      param_1[3] = (uint)local_18;
      param_1[5] = (uint)local_14;
    }
    if (param_2 < *(uint *)(local_8 + 0x10)) {
      *(undefined4 *)param_1[3] = 0;
      *(uint *)param_1[5] = local_8;
    }
    else {
      *(uint *)param_1[3] = local_8;
      *(undefined4 *)param_1[5] = 0;
    }
    *(uint *)(param_3 + 0x18) = param_1[2];
    *(uint *)(param_3 + 0x1c) = param_1[4];
  }
  *(uint *)(param_3 + 0x10) = param_2;
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[3] = (uint)(param_1 + 2);
  param_1[5] = (uint)(param_1 + 4);
  return;
}

