
/* WARNING: Removing unreachable block (ram,0xf008a2e8) */
/* WARNING: Removing unreachable block (ram,0xf008a2b4) */
/* WARNING: Removing unreachable block (ram,0xf008a2f4) */
/* WARNING: Removing unreachable block (ram,0xf008a27c) */

undefined8 _task_by_unix_pid(int param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  _pfind();
  if (param_2 == 0) {
    *param_3 = 0;
  }
  else if (*(int *)(param_1 + 0x3c) == 0) {
    *param_3 = 0;
  }
  else {
    iVar2 = (int)*(sword *)(*(int *)(param_1 + 0x3c) + 0x2c);
    if (*(sword *)(param_2 + 0x2c) == iVar2) {
      cVar1 = *(char *)(param_2 + 0x13);
    }
    else {
      _suser();
      if (iVar2 == 0) {
        *param_3 = 0;
        goto loc_F008A334;
      }
      cVar1 = *(char *)(param_2 + 0x13);
    }
    if (cVar1 != '\x05') {
      iVar2 = 0;
      if (*(int *)(param_2 + 0x68) != 0) {
        _task_reference();
        iVar2 = *(int *)(param_2 + 0x68);
      }
      *param_3 = iVar2;
      _suser();
      if ((iVar2 != 0) && (iVar2 = *(int *)(*(int *)(_active_threads + 0xc) + 0x3c), iVar2 != 0)) {
        *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x8000;
      }
      uVar3 = 0;
      goto locret_F008A338;
    }
    *param_3 = 0;
  }
loc_F008A334:
  uVar3 = 5;
locret_F008A338:
  return CONCAT44(param_2,uVar3);
}
