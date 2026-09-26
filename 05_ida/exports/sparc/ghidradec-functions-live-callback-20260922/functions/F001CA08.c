
/* WARNING: Removing unreachable block (ram,0xf001cb0c) */
/* WARNING: Removing unreachable block (ram,0xf001cac0) */
/* WARNING: Removing unreachable block (ram,0xf001cb40) */
/* WARNING: Removing unreachable block (ram,0xf001ca0c) */

undefined8 _ndflush(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
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
  bool bVar7;
  bool bVar8;
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
  piVar3 = param_1;
  _spltty();
  if (0 < *param_1) {
    iVar4 = *param_1;
    if (param_2 < 1) {
loc_F001CB28:
      bVar8 = iVar4 == 0;
    }
    else {
      while( true ) {
        piVar1 = _cfreelist;
        bVar7 = iVar4 == 0;
        iVar4 = 0;
        bVar8 = true;
        if (bVar7) break;
        piVar5 = (int *)param_1[2];
        piVar6 = (int *)(param_1[1] & 0xffffffc0);
        if (piVar6 != (int *)((int)piVar5 - 1U & 0xffffffc0)) {
          piVar5 = piVar6 + 0x10;
        }
        iVar4 = (int)piVar5 - param_1[1];
        if (param_2 < iVar4) {
          *param_1 = *param_1 - param_2;
          param_1[1] = param_1[1] + param_2;
          cVar2 = _cwaiting._0_1_;
          if (*param_1 < 1) {
            *piVar6 = (int)_cfreelist;
            _cfreecount = _cfreecount + 0x34;
            _cfreelist = piVar6;
            if (cVar2 != '\0') {
              _wakeup(&_cwaiting);
              _cwaiting._0_1_ = '\0';
            }
          }
loc_F001CB24:
          iVar4 = *param_1;
          goto loc_F001CB28;
        }
        param_2 = param_2 - iVar4;
        *param_1 = *param_1 - iVar4;
        _cfreecount = _cfreecount + 0x34;
        bVar8 = _cwaiting._0_1_ != '\0';
        _cfreelist = piVar6;
        param_1[1] = *piVar6 + 0xc;
        *piVar6 = (int)piVar1;
        if (bVar8) {
          _wakeup(&_cwaiting);
          _cwaiting._0_1_ = '\0';
        }
        if (param_2 < 1) goto loc_F001CB24;
        iVar4 = *param_1;
      }
    }
    if (bVar8 || iVar4 < 0) {
      param_1[2] = 0;
      param_1[1] = 0;
      *param_1 = 0;
    }
  }
  _splx(piVar3);
  return CONCAT44(param_2,param_1);
}

