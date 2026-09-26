
/* WARNING: Removing unreachable block (ram,0xf001825c) */
/* WARNING: Removing unreachable block (ram,0xf0018130) */
/* WARNING: Removing unreachable block (ram,0xf0018178) */
/* WARNING: Removing unreachable block (ram,0xf0018158) */
/* WARNING: Removing unreachable block (ram,0xf00181e0) */
/* WARNING: Removing unreachable block (ram,0xf00180dc) */
/* WARNING: Removing unreachable block (ram,0xf0018144) */
/* WARNING: Removing unreachable block (ram,0xf001816c) */
/* WARNING: Removing unreachable block (ram,0xf0018128) */
/* WARNING: Removing unreachable block (ram,0xf001823c) */
/* WARNING: Removing unreachable block (ram,0xf0018274) */
/* WARNING: Removing unreachable block (ram,0xf00180b0) */

undefined8 _ttyinput(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
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
  piVar1 = param_2;
  _ttynty();
  if ((piVar1[4] & 0x800U) == 0) goto locret_F001827C;
  if ((param_2[0xf] & 0x20000000U) != 0) {
    _ttypend(param_2);
  }
  _tk_nin = _tk_nin + 1;
  if (((param_1 & 0xff000000) == 0) && ((param_2[0xf] & 0x20U) != 0)) {
    if (*param_2 < 0x401) {
      uVar2 = param_1;
      _putc(param_1,param_2);
      if ((int)uVar2 < 0) {
        uVar2 = param_2[0xf];
      }
      else {
        piVar3 = piVar1;
        _ttcheckwakeup();
        if (piVar3 != (int *)0x0) {
          _ttwakeup(param_2);
        }
        _ttyecho(param_1,piVar1);
        uVar2 = param_2[0xf];
      }
    }
    else {
      _log(4,aTtyDRawInputOv,(int)*(sword *)(param_2 + 0xe));
      _ttwakeup(param_2);
      uVar2 = param_2[0xf];
    }
    param_2[0xf] = uVar2 & 0xff7fffff;
    if ((piVar1[4] & 0x10U) == 0) goto loc_F00181E8;
    if ((uVar2 & 0x40000000) == 0) {
      uVar2 = param_2[0x10];
loc_F00181D0:
      param_2[0x10] = uVar2 & 0xfffffeff;
      goto loc_F00181E8;
    }
    if (*(char *)((int)param_2 + 0x52) == -1) {
      iVar4 = *param_2;
    }
    else {
      if (*(char *)((int)param_2 + 0x52) == *(char *)((int)param_2 + 0x51)) {
        uVar2 = param_2[0x10];
        goto loc_F00181D0;
      }
      iVar4 = *param_2;
    }
  }
  else {
    _ttcooked(param_1,piVar1);
loc_F00181E8:
    iVar4 = *param_2;
  }
  if ((0x1ff < iVar4 + param_2[3]) && (((param_2[0xf] & 0x22U) != 0 || (0 < param_2[3])))) {
    if ((param_2[0xf] & 1U) == 0) {
      uVar2 = param_2[0x10];
    }
    else if (*(char *)((int)param_2 + 0x52) == -1) {
      uVar2 = param_2[0x10];
    }
    else {
      iVar4 = (int)*(char *)((int)param_2 + 0x52);
      _putc(iVar4,param_2 + 6);
      if (iVar4 == 0) {
        param_2[0x10] = param_2[0x10] | 0x400;
        _ttstart(param_2);
        uVar2 = param_2[0x10];
      }
      else {
        uVar2 = param_2[0x10];
      }
    }
    param_2[0x10] = uVar2 | 0x800000;
  }
  _ttstart(param_2);
locret_F001827C:
  return CONCAT44(param_2,param_1);
}
