
/* WARNING: Removing unreachable block (ram,0xf001013c) */
/* WARNING: Removing unreachable block (ram,0xf00100e8) */
/* WARNING: Removing unreachable block (ram,0xf0010100) */
/* WARNING: Removing unreachable block (ram,0xf001014c) */
/* WARNING: Removing unreachable block (ram,0xf0010074) */

undefined8 _donice(int *param_1,int param_2)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
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
  sVar1 = *(sword *)(*(int *)(_active_u + 0x1c) + 2);
  if ((((sVar1 == 0) || (sVar2 = *(sword *)(*(int *)(_active_u + 0x1c) + 6), sVar2 == 0)) ||
      (sVar1 == *(sword *)(param_1 + 0xb))) || (sVar2 == *(sword *)(param_1 + 0xb))) {
    if (0x14 < param_2) {
      param_2 = 0x14;
    }
    if (param_2 < -0x14) {
      param_2 = -0x14;
    }
    iVar3 = (int)*(char *)((int)param_1 + 0x15);
    if (param_2 < iVar3) {
      _suser();
      if (iVar3 == 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0xd;
        goto locret_F0010174;
      }
      piVar6 = (int *)param_1[0x1a];
    }
    else {
      piVar6 = (int *)param_1[0x1a];
    }
    iVar3 = (uint)*(byte *)((int)param_1 + 0x15) << 0x18;
    iVar5 = piVar6[0x12];
    *(char *)((int)param_1 + 0x15) = (char)param_2;
    param_2 = (iVar5 + ((iVar3 >> 0x18) - (iVar3 >> 0x1f) >> 1)) - param_2 / 2;
    _task_priority(piVar6,param_2,0);
    do {
      do {
      } while (*piVar6 != 0);
      piVar4 = piVar6;
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    param_1 = (int *)piVar6[7];
    if (piVar6 + 7 != param_1) {
      iVar3 = param_1[0x15];
      while( true ) {
        if (iVar3 < param_2) {
          _thread_max_priority(param_1,param_1[100],param_2);
        }
        piVar4 = param_1;
        _thread_priority(param_1,param_2,1);
        if (piVar4 != (int *)0x0) break;
        param_1 = (int *)param_1[4];
        if (piVar6 + 7 == param_1) goto loc_F0010170;
        iVar3 = param_1[0x15];
      }
      *(undefined *)(dword_F0133DDC + 0x38) = 1;
    }
loc_F0010170:
    *piVar6 = 0;
  }
  else {
    *(undefined *)(dword_F0133DDC + 0x38) = 1;
  }
locret_F0010174:
  return CONCAT44(param_2,param_1);
}

