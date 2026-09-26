
/* WARNING: Removing unreachable block (ram,0xf009196c) */
/* WARNING: Removing unreachable block (ram,0xf0091940) */
/* WARNING: Removing unreachable block (ram,0xf0091960) */
/* WARNING: Removing unreachable block (ram,0xf009199c) */
/* WARNING: Removing unreachable block (ram,0xf0091934) */

undefined8 sub_F0091870(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (((((param_1[1] == 0x48) && (*param_1 < 0)) && ((param_1[6] & 0xfffffffcU) == 0x11200018)) &&
      ((param_1[8] == dword_F01122B0 && (param_1[10] == dword_F01122B4)))) &&
     ((param_1[0xc] == dword_F01122B8 &&
      ((param_1[0xe] == dword_F01122BC && (param_1[0x10] == dword_F01122C0)))))) {
    iVar1 = param_1[7];
    _convert_port_to_task(iVar1);
    iVar2 = param_1[2];
    _convert_port_to_dev();
    _kern_IOMapSparcDeviceMemory();
    *(int *)(param_2 + 0x1c) = iVar2;
    _task_deallocate(iVar1);
    if (*(int *)(param_2 + 0x1c) == 0) {
      if ((param_1[7] != 0) && (param_1[7] != -1)) {
        _ipc_port_release_send();
      }
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = dword_F01122C4;
      *(int *)(param_2 + 0x24) = param_1[0xd];
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}

