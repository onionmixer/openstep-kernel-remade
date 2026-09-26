/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151670 */

/* WARNING: Removing unreachable block (ram,0x00151793) */
/* WARNING: Removing unreachable block (ram,0x00151799) */
/* WARNING: Removing unreachable block (ram,0x00151781) */
/* WARNING: Removing unreachable block (ram,0x0015178c) */
/* WARNING: Removing unreachable block (ram,0x001517a6) */
/* WARNING: Removing unreachable block (ram,0x001517bd) */
/* WARNING: Removing unreachable block (ram,0x001517c3) */
/* WARNING: Removing unreachable block (ram,0x00151811) */
/* WARNING: Removing unreachable block (ram,0x00151817) */

int _ipc_splay_traverse_next(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  int local_c;
  int local_8;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 0x10);
  local_8 = iVar2;
  local_1c = iVar3;
  if (param_2 == 0) {
LAB_001518a4:
    iVar2 = *(int *)(local_8 + 0x1c);
    if (iVar2 != 0) {
      *(int *)(local_8 + 0x1c) = iVar3;
      local_1c = local_8;
      local_8 = iVar2;
LAB_0015187c:
      while (iVar2 = *(int *)(local_8 + 0x18), iVar2 != 0) {
        *(int *)(local_8 + 0x18) = local_1c;
        local_1c = local_8;
        local_8 = iVar2;
      }
      goto LAB_00151890;
    }
  }
  else {
    local_8 = *(int *)(iVar2 + 0x18);
    if (local_8 == 0) {
      local_8 = *(int *)(iVar2 + 0x1c);
      if (local_8 != 0) {
        _zfree(_ipc_tree_entry_zone,iVar2);
        goto LAB_0015187c;
      }
      if (iVar3 == 0) {
        local_8 = iVar2;
        _zfree(_ipc_tree_entry_zone,iVar2);
        *(undefined4 *)(param_1 + 4) = 0;
        return 0;
      }
      if (*(uint *)(iVar2 + 0x10) < *(uint *)(iVar3 + 0x10)) {
        local_8 = iVar2;
        _zfree(_ipc_tree_entry_zone,iVar2);
        local_1c = *(int *)(iVar3 + 0x18);
        *(undefined4 *)(iVar3 + 0x18) = 0;
        local_8 = iVar3;
        goto LAB_00151890;
      }
      local_8 = iVar2;
      _zfree(_ipc_tree_entry_zone,iVar2);
      local_1c = *(int *)(iVar3 + 0x1c);
      *(undefined4 *)(iVar3 + 0x1c) = 0;
      local_8 = iVar3;
    }
    else {
      if (*(int *)(iVar2 + 0x1c) != 0) {
        piVar1 = &local_c;
        iVar4 = *(int *)(local_8 + 0x10);
        iVar5 = local_8;
        while ((iVar4 != -1 && (iVar4 = *(int *)(iVar5 + 0x1c), iVar4 != 0))) {
          if ((*(int *)(iVar4 + 0x10) != -1) && (*(int *)(iVar4 + 0x1c) != 0)) {
            *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
            *(int *)(iVar4 + 0x18) = iVar5;
            iVar5 = iVar4;
          }
          *piVar1 = iVar5;
          piVar1 = (int *)(iVar5 + 0x1c);
          iVar5 = *(int *)(iVar5 + 0x1c);
          iVar4 = *(int *)(iVar5 + 0x10);
        }
        local_8 = iVar5;
        *piVar1 = *(int *)(iVar5 + 0x18);
        *(int *)(iVar5 + 0x18) = local_c;
        *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x1c);
        *(undefined4 *)(local_8 + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
        _zfree(_ipc_tree_entry_zone,iVar2);
        goto LAB_001518a4;
      }
      _zfree(_ipc_tree_entry_zone,iVar2);
    }
  }
  while( true ) {
    iVar2 = local_8;
    if (local_1c == 0) {
      *(int *)(param_1 + 4) = local_8;
      return 0;
    }
    if (*(uint *)(local_8 + 0x10) < *(uint *)(local_1c + 0x10)) break;
    local_8 = local_1c;
    iVar3 = *(int *)(local_1c + 0x1c);
    *(int *)(local_1c + 0x1c) = iVar2;
    local_1c = iVar3;
  }
  local_8 = local_1c;
  iVar3 = *(int *)(local_1c + 0x18);
  *(int *)(local_1c + 0x18) = iVar2;
  local_1c = iVar3;
LAB_00151890:
  *(int *)(param_1 + 8) = local_8;
  *(int *)(param_1 + 0x10) = local_1c;
  return local_8;
}

