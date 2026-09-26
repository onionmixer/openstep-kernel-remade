
/* WARNING: Removing unreachable block (ram,0xf0025b5c) */
/* WARNING: Removing unreachable block (ram,0xf0025b00) */

undefined8 _dnlc_lookup(int *param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  if (_doingcache == 0) {
    iVar5 = 0;
  }
  else {
    pcVar1 = param_2;
    _strlen();
    if ((int)pcVar1 < 0x21) {
      pcVar2 = pcVar1 + (int)*param_2 + (int)(pcVar1 + (int)param_2)[-1] + (int)param_1;
      sub_F0025EC0(param_1,param_2,pcVar1,(uint)pcVar2 & 0x3f,param_3);
      if (param_1 == (int *)0x0) {
        iVar5 = 0;
        DAT_f01355f4._0_4_ = DAT_f01355f4._0_4_ + 1;
      }
      else {
        _ncstats._0_4_ = _ncstats._0_4_ + 1;
        *(int *)(param_1[3] + 8) = param_1[2];
        *(int *)(param_1[2] + 0xc) = param_1[3];
        iVar5 = dword_F01355DC;
        iVar3 = *(int *)(dword_F01355DC + 8);
        *(int **)(dword_F01355DC + 8) = param_1;
        param_1[2] = iVar3;
        *(int **)(iVar3 + 0xc) = param_1;
        param_1[3] = iVar5;
        if ((undefined *)param_1[1] == _nc_hash + ((uint)pcVar2 & 0x3f) * 8) {
          iVar5 = param_1[4];
        }
        else {
          *(undefined **)(*param_1 + 4) = (undefined *)param_1[1];
          *(int *)param_1[1] = *param_1;
          piVar4 = *(int **)(param_1[1] + 4);
          *param_1 = *piVar4;
          param_1[1] = (int)piVar4;
          *(int **)(*piVar4 + 4) = param_1;
          *piVar4 = (int)param_1;
          iVar5 = param_1[4];
        }
      }
    }
    else {
      iVar5 = 0;
      DAT_f0135604._0_4_ = DAT_f0135604._0_4_ + 1;
    }
  }
  return CONCAT44(param_2,iVar5);
}

