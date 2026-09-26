
/* WARNING: Removing unreachable block (ram,0xf001c960) */
/* WARNING: Removing unreachable block (ram,0xf001c8f4) */
/* WARNING: Removing unreachable block (ram,0xf001c88c) */
/* WARNING: Removing unreachable block (ram,0xf001c948) */
/* WARNING: Removing unreachable block (ram,0xf001c838) */
/* WARNING: Removing unreachable block (ram,0xf001c818) */

undefined8 _q_to_b(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar7;
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
  iVar7 = param_2;
  if (param_3 < 1) {
    param_2 = 0;
  }
  else {
    piVar2 = param_1;
    _spltty();
    if (*param_1 < 1) {
      *param_1 = 0;
      param_1[2] = 0;
      param_1[1] = 0;
      _splx();
      param_2 = 0;
    }
    else {
      uVar4 = param_1[1];
      while( true ) {
        iVar6 = 0x40 - (uVar4 & 0x3f);
        if (param_3 < iVar6) {
          iVar6 = param_3;
        }
        if (*param_1 < iVar6) {
          iVar6 = *param_1;
        }
        _bcopy(uVar4,iVar7,iVar6);
        param_3 = param_3 - iVar6;
        iVar7 = iVar7 + iVar6;
        iVar3 = *param_1;
        param_1[1] = param_1[1] + iVar6;
        *param_1 = iVar3 - iVar6;
        if (iVar3 - iVar6 < 1) break;
        uVar4 = param_1[1];
        if ((uVar4 & 0x3f) == 0) {
          param_1[1] = *(int *)(uVar4 - 0x40) + 0xc;
          *(undefined4 **)(uVar4 - 0x40) = _cfreelist;
          _cfreecount = _cfreecount + 0x34;
          _cfreelist = (undefined4 *)(uVar4 - 0x40);
          if (_cwaiting._0_1_ != '\0') {
            _wakeup(&_cwaiting);
            _cwaiting._0_1_ = '\0';
          }
        }
        if (param_3 == 0) goto loc_F001C960;
        uVar4 = param_1[1];
      }
      param_1[2] = 0;
      cVar1 = _cwaiting._0_1_;
      puVar5 = (undefined4 *)(param_1[1] - 1U & 0xffffffc0);
      param_1[1] = 0;
      *puVar5 = _cfreelist;
      _cfreecount = _cfreecount + 0x34;
      _cfreelist = puVar5;
      if (cVar1 != '\0') {
        _wakeup(&_cwaiting);
        _cwaiting._0_1_ = '\0';
      }
loc_F001C960:
      _splx(piVar2);
      param_2 = iVar7 - param_2;
    }
  }
  return CONCAT44(iVar7,param_2);
}

