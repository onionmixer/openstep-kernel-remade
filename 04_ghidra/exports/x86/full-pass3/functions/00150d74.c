/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00150d74 */

/* WARNING: Removing unreachable block (ram,0x00150f47) */
/* WARNING: Removing unreachable block (ram,0x00150f4d) */
/* WARNING: Removing unreachable block (ram,0x00150f35) */
/* WARNING: Removing unreachable block (ram,0x00150f40) */
/* WARNING: Removing unreachable block (ram,0x00150f5a) */
/* WARNING: Removing unreachable block (ram,0x00150f71) */
/* WARNING: Removing unreachable block (ram,0x00150f77) */
/* WARNING: Removing unreachable block (ram,0x00150fc5) */
/* WARNING: Removing unreachable block (ram,0x00150fcb) */

void _ipc_splay_tree_delete(uint *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *local_24;
  uint *local_20;
  uint local_8;
  
  local_8 = param_1[1];
  if (*param_1 != param_2) {
    puVar1 = (undefined4 *)param_1[5];
    *(undefined4 *)param_1[3] = *(undefined4 *)(local_8 + 0x18);
    *puVar1 = *(undefined4 *)(local_8 + 0x1c);
    *(uint *)(local_8 + 0x18) = param_1[2];
    *(uint *)(local_8 + 0x1c) = param_1[4];
    local_24 = param_1 + 2;
    local_20 = param_1 + 4;
    while (param_2 != *(uint *)(local_8 + 0x10)) {
      if (param_2 < *(uint *)(local_8 + 0x10)) {
        uVar5 = *(uint *)(local_8 + 0x18);
        if (uVar5 == 0) break;
        uVar2 = *(uint *)(uVar5 + 0x10);
        if ((param_2 < uVar2) && (*(int *)(uVar5 + 0x18) != 0)) {
          *(undefined4 *)(local_8 + 0x18) = *(undefined4 *)(uVar5 + 0x1c);
          *(uint *)(uVar5 + 0x1c) = local_8;
          local_8 = uVar5;
        }
        *local_20 = local_8;
        local_20 = (uint *)(local_8 + 0x18);
        local_8 = *(uint *)(local_8 + 0x18);
        if ((uVar2 < param_2) && (*(int *)(uVar5 + 0x1c) != 0)) {
          *local_24 = local_8;
          local_24 = (uint *)(local_8 + 0x1c);
          local_8 = *(uint *)(local_8 + 0x1c);
        }
      }
      else {
        uVar5 = *(uint *)(local_8 + 0x1c);
        if (uVar5 == 0) break;
        uVar2 = *(uint *)(uVar5 + 0x10);
        if ((uVar2 < param_2) && (*(int *)(uVar5 + 0x1c) != 0)) {
          *(undefined4 *)(local_8 + 0x1c) = *(undefined4 *)(uVar5 + 0x18);
          *(uint *)(uVar5 + 0x18) = local_8;
          local_8 = uVar5;
        }
        *local_24 = local_8;
        local_24 = (uint *)(local_8 + 0x1c);
        local_8 = *(uint *)(local_8 + 0x1c);
        if ((param_2 < uVar2) && (*(int *)(uVar5 + 0x18) != 0)) {
          *local_20 = local_8;
          local_20 = (uint *)(local_8 + 0x18);
          local_8 = *(uint *)(local_8 + 0x18);
        }
      }
    }
    param_1[3] = (uint)local_24;
    param_1[5] = (uint)local_20;
  }
  *(undefined4 *)param_1[3] = *(undefined4 *)(local_8 + 0x18);
  *(undefined4 *)param_1[5] = *(undefined4 *)(local_8 + 0x1c);
  _zfree(_ipc_tree_entry_zone,local_8);
  uVar5 = param_1[2];
  uVar2 = param_1[4];
  local_8 = uVar2;
  if ((uVar5 != 0) && (local_8 = uVar5, uVar2 != 0)) {
    puVar6 = param_1 + 2;
    iVar3 = *(int *)(uVar5 + 0x10);
    while ((iVar3 != -1 && (uVar4 = *(uint *)(uVar5 + 0x1c), uVar4 != 0))) {
      if ((*(int *)(uVar4 + 0x10) != -1) && (*(int *)(uVar4 + 0x1c) != 0)) {
        *(undefined4 *)(uVar5 + 0x1c) = *(undefined4 *)(uVar4 + 0x18);
        *(uint *)(uVar4 + 0x18) = uVar5;
        uVar5 = uVar4;
      }
      *puVar6 = uVar5;
      puVar6 = (uint *)(uVar5 + 0x1c);
      uVar5 = *(uint *)(uVar5 + 0x1c);
      iVar3 = *(int *)(uVar5 + 0x10);
    }
    param_1[3] = (uint)puVar6;
    param_1[5] = (uint)(param_1 + 4);
    puVar1 = (undefined4 *)param_1[5];
    *(undefined4 *)param_1[3] = *(undefined4 *)(uVar5 + 0x18);
    *puVar1 = *(undefined4 *)(uVar5 + 0x1c);
    *(uint *)(uVar5 + 0x18) = param_1[2];
    *(uint *)(uVar5 + 0x1c) = param_1[4];
    *(uint *)(uVar5 + 0x1c) = uVar2;
    local_8 = uVar5;
  }
  param_1[1] = local_8;
  if (local_8 != 0) {
    *param_1 = *(uint *)(local_8 + 0x10);
    param_1[3] = (uint)(param_1 + 2);
    param_1[5] = (uint)(param_1 + 4);
  }
  return;
}

