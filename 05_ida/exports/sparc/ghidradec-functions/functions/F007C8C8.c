
/* WARNING: Removing unreachable block (ram,0xf007c960) */
/* WARNING: Removing unreachable block (ram,0xf007c94c) */
/* WARNING: Removing unreachable block (ram,0xf007c938) */
/* WARNING: Removing unreachable block (ram,0xf007c958) */
/* WARNING: Removing unreachable block (ram,0xf007c990) */
/* WARNING: Removing unreachable block (ram,0xf007c92c) */

undefined8 sub_F007C8C8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
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
  if ((((param_1[1] == 0x28) && (*param_1 < 0)) && ((param_1[6] & 0xfffffffcU) == 0x11200018)) &&
     (param_1[8] == dword_F01110B8)) {
    iVar1 = param_1[2];
    _convert_port_to_task();
    iVar2 = param_1[7];
    _convert_port_to_pset(iVar2);
    iVar3 = iVar1;
    _task_assign(iVar1,iVar2,param_1[9]);
    *(int *)(param_2 + 0x1c) = iVar3;
    _pset_deallocate(iVar2);
    _task_deallocate(iVar1);
    if (((*(int *)(param_2 + 0x1c) == 0) && (param_1[7] != 0)) && (param_1[7] != -1)) {
      _ipc_port_release_send();
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
