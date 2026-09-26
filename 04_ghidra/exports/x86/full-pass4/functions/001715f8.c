/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001715f8 */

void FUN_001715f8(int *param_1,uint *param_2)

{
  ipc_info_name_array_t piVar1;
  ipc_info_tree_name_t *piVar2;
  ipc_space_t task;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  uint local_810;
  mach_msg_type_number_t local_7fc;
  ipc_info_tree_name_t *local_7f8;
  mach_msg_type_number_t local_7f4;
  ipc_info_name_array_t local_7f0;
  ipc_info_tree_name_t local_7ec [56];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e0774)) &&
     (param_1[8] == DAT_001e0778)) {
    task = _convert_port_to_space(param_1[2]);
    piVar1 = (ipc_info_name_array_t)(param_2 + 0x12);
    local_7f4 = 0x38;
    if ((uint)param_1[7] < 0x38) {
      local_7f4 = param_1[7];
    }
    piVar2 = local_7ec;
    local_7fc = 0x2e;
    if ((uint)param_1[9] < 0x2e) {
      local_7fc = param_1[9];
    }
    local_7f8 = piVar2;
    local_7f0 = piVar1;
    uVar3 = _mach_port_space_info
                      (task,(ipc_info_space_t *)(param_2 + 9),&local_7f0,&local_7f4,&local_7f8,
                       &local_7fc);
    param_2[7] = uVar3;
    _space_deallocate(task);
    if (param_2[7] == 0) {
      param_2[8] = DAT_001e077c;
      param_2[0xf] = DAT_001e0780;
      param_2[0x10] = (uint)PTR_s__62I__001e0784;
      param_2[0x11] = DAT_001e0788;
      bVar5 = local_7f0 != piVar1;
      if (bVar5) {
        *(byte *)((int)param_2 + 0x3f) = *(byte *)((int)param_2 + 0x3f) & 0xef | 0x40;
        param_2[0x12] = (uint)local_7f0;
      }
      param_2[0x11] = local_7f4 * 9;
      iVar4 = 4;
      if ((*(byte *)((int)param_2 + 0x3f) & 0x10) != 0) {
        iVar4 = local_7f4 * 0x24;
      }
      *(undefined4 *)((int)param_2 + iVar4 + 0x48) = DAT_001e078c;
      *(undefined **)((int)param_2 + iVar4 + 0x4c) = PTR_s__62I__001e0790;
      *(undefined4 *)((int)param_2 + iVar4 + 0x50) = DAT_001e0794;
      bVar6 = piVar2 == local_7f8;
      if (bVar6) {
        _memcpy((void *)((int)param_2 + iVar4 + 0x54),local_7f8,local_7fc * 0x2c);
      }
      else {
        *(byte *)((int)param_2 + iVar4 + 0x4b) =
             *(byte *)((int)param_2 + iVar4 + 0x4b) & 0xef | 0x40;
        *(ipc_info_tree_name_t **)((int)param_2 + iVar4 + 0x54) = local_7f8;
      }
      *(mach_msg_type_number_t *)((int)param_2 + iVar4 + 0x50) = local_7fc * 0xb;
      if ((*(byte *)((int)param_2 + iVar4 + 0x4b) & 0x10) == 0) {
        local_810 = iVar4 + 0x58;
      }
      else {
        local_810 = iVar4 + 0x54 + local_7fc * 0x2c;
      }
      if (!bVar6 || bVar5) {
        *param_2 = *param_2 | 0x80000000;
      }
      param_2[1] = local_810;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

