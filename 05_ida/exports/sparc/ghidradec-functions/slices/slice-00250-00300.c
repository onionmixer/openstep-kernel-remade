/* GHIDRADEC_FUNCTION index=250 start=0xf0012fcc */

/* WARNING: Removing unreachable block (ram,0xf0013034) */
/* WARNING: Removing unreachable block (ram,0xf0012ff0) */
/* WARNING: Removing unreachable block (ram,0xf0013060) */
/* WARNING: Removing unreachable block (ram,0xf0012fd8) */

undefined8 _adjtime(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
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
  undefined auStackX_0 [92];
  
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    uVar2 = *puVar3;
    _copyin(uVar2,(undefined *)((int)register0x00000038 + -0x10),8);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      *(undefined4 *)((int)register0x00000038 + -0x20) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x1c) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      *(undefined4 *)((int)register0x00000038 + -0x30) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x2c) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      _host_adjust_time(dword_F0135174,(undefined *)((int)register0x00000038 + -0x30),
                        (undefined *)((int)register0x00000038 + -0x28));
      if (puVar3[1] != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x18) =
             *(undefined4 *)((int)register0x00000038 + -0x28);
        *(undefined4 *)((int)register0x00000038 + -0x14) =
             *(undefined4 *)((int)register0x00000038 + -0x24);
        _copyout((undefined *)((int)register0x00000038 + -0x18),puVar3[1],8);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=251 start=0xf0013070 */

/* WARNING: Removing unreachable block (ram,0xf0013130) */
/* WARNING: Removing unreachable block (ram,0xf0013160) */
/* WARNING: Removing unreachable block (ram,0xf0013154) */
/* WARNING: Removing unreachable block (ram,0xf0013120) */
/* WARNING: Removing unreachable block (ram,0xf001316c) */
/* WARNING: Removing unreachable block (ram,0xf00130a4) */
/* WARNING: Removing unreachable block (ram,0xf0013094) */

uint _inittodr(void)

{
  uint uVar1;
  undefined *puVar2;
  undefined8 in_o0_1;
  uint uVar3;
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
  undefined auStackX_0 [92];
  
  uVar1 = (uint)((qword)in_o0_1 >> 0x20);
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
  if ((uVar1 < 0x1ff46b80) || ((int)uVar1 < 0)) {
    _printf(aWarningPrepost);
  }
  else {
    _microtime((undefined *)((int)register0x00000038 + -0x10));
    _boottime = *(uint *)((int)register0x00000038 + -0x10);
    DAT_f013516c = 0;
    uVar3 = _boottime - uVar1;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((uVar3 < 0x2a300) && ((int)uVar1 < (int)_boottime)) {
      DAT_f013516c = 0;
      return uVar1;
    }
    if (_boottime < 0x1e13380) {
      puVar2 = aWarningClockNo;
    }
    else {
      if (uVar3 < 0x76a701) {
        .udiv();
        _printf(aWarningClockLo);
        goto loc_F001316C;
      }
      puVar2 = aWarningPrepost_0;
    }
    _printf(puVar2);
    *(uint *)((int)register0x00000038 + -0x10) = uVar1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    _setthetime((undefined *)((int)register0x00000038 + -0x10));
    _boottime = (uint)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
    DAT_f013516c = (undefined4)*(undefined8 *)((int)register0x00000038 + -0x10);
  }
loc_F001316C:
  _printf(aCheckAndResetT);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=252 start=0xf001317c */

/* WARNING: Removing unreachable block (ram,0xf0013270) */
/* WARNING: Removing unreachable block (ram,0xf00131c0) */
/* WARNING: Removing unreachable block (ram,0xf0013238) */
/* WARNING: Removing unreachable block (ram,0xf0013280) */
/* WARNING: Removing unreachable block (ram,0xf00131a8) */

undefined8 _getitimer(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  uint *puVar6;
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
  undefined auStackX_0 [92];
  
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
  puVar6 = *(uint **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar6;
  if (2 < uVar1) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    goto locret_F0013294;
  }
  _spltty();
  uVar4 = *puVar6;
  if (uVar4 == 0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x20));
    iVar5 = *_active_u;
    *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(iVar5 + 0x54);
    *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(iVar5 + 0x58);
    iVar2 = *(int *)(iVar5 + 0x5c);
    *(int *)((int)register0x00000038 + -0x10) = iVar2;
    iVar5 = *(int *)(iVar5 + 0x60);
    *(int *)((int)register0x00000038 + -0xc) = iVar5;
    if ((iVar2 != 0) || (iVar5 != 0)) {
      if (iVar2 < *(int *)((int)register0x00000038 + -0x20)) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      }
      else {
        if ((iVar2 != *(int *)((int)register0x00000038 + -0x20)) ||
           (*(int *)((int)register0x00000038 + -0x1c) <= iVar5)) {
          _timevalsub((undefined *)((int)register0x00000038 + -0x10),
                      (undefined *)((int)register0x00000038 + -0x20));
          goto loc_F0013270;
        }
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      }
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
  }
  else {
    *(int *)((int)register0x00000038 + -0x18) = _active_u[uVar4 * 4 + 0x7f];
    *(int *)((int)register0x00000038 + -0x14) = _active_u[uVar4 * 4 + 0x80];
    *(int *)((int)register0x00000038 + -0x10) = _active_u[uVar4 * 4 + 0x81];
    *(int *)((int)register0x00000038 + -0xc) = _active_u[uVar4 * 4 + 0x82];
  }
loc_F0013270:
  _splx(uVar1);
  puVar3 = (undefined *)((int)register0x00000038 + -0x18);
  _copyout(puVar3,puVar6[1],0x10);
  *(char *)(dword_F0133DDC + 0x38) = (char)puVar3;
locret_F0013294:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=253 start=0xf001329c */

/* WARNING: Removing unreachable block (ram,0xf00133c4) */
/* WARNING: Removing unreachable block (ram,0xf00133ac) */
/* WARNING: Removing unreachable block (ram,0xf0013370) */
/* WARNING: Removing unreachable block (ram,0xf0013334) */
/* WARNING: Removing unreachable block (ram,0xf00132fc) */
/* WARNING: Removing unreachable block (ram,0xf0013320) */
/* WARNING: Removing unreachable block (ram,0xf0013354) */
/* WARNING: Removing unreachable block (ram,0xf0013384) */
/* WARNING: Removing unreachable block (ram,0xf00133b4) */
/* WARNING: Removing unreachable block (ram,0xf001341c) */
/* WARNING: Removing unreachable block (ram,0xf00132e0) */

undefined8 _setitimer(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined *puVar4;
  undefined4 unaff_l1;
  uint *puVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
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
  undefined auStackX_0 [92];
  
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
  puVar5 = *(uint **)(dword_F0133DDC + 0x24);
  iVar6 = *_active_u;
  if (*puVar5 < 3) {
    uVar3 = puVar5[1];
    if (puVar5[2] != 0) {
      puVar5[1] = puVar5[2];
      _getitimer();
    }
    if (uVar3 != 0) {
      puVar7 = (undefined *)((int)register0x00000038 + -0x18);
      _copyin(uVar3,puVar7,0x10);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
      puVar4 = (undefined *)((int)register0x00000038 + -0x10);
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        puVar2 = puVar4;
        _itimerfix();
        if ((puVar2 == (undefined *)0x0) && (_itimerfix(), puVar7 == (undefined *)0x0)) {
          _spltty();
          piVar1 = _active_u;
          uVar3 = *puVar5;
          if (uVar3 == 0) {
            _getthetime((undefined *)((int)register0x00000038 + -0x20));
            _untimeout(_realitexpire,iVar6);
            if ((*(int *)((int)register0x00000038 + -0x10) != 0) ||
               (*(int *)((int)register0x00000038 + -0xc) != 0)) {
              _timevaladd(puVar4,(undefined *)((int)register0x00000038 + -0x20));
              _hzto(puVar4);
              _timeout(_realitexpire,iVar6,puVar4);
            }
            *(undefined4 *)(iVar6 + 0x54) = *(undefined4 *)((int)register0x00000038 + -0x18);
            *(undefined4 *)(iVar6 + 0x58) = *(undefined4 *)((int)register0x00000038 + -0x14);
            *(undefined4 *)(iVar6 + 0x5c) = *(undefined4 *)((int)register0x00000038 + -0x10);
            *(undefined4 *)(iVar6 + 0x60) = *(undefined4 *)((int)register0x00000038 + -0xc);
          }
          else {
            _active_u[uVar3 * 4 + 0x7f] = *(int *)((int)register0x00000038 + -0x18);
            piVar1[uVar3 * 4 + 0x80] = *(int *)((int)register0x00000038 + -0x14);
            piVar1[uVar3 * 4 + 0x81] = *(int *)((int)register0x00000038 + -0x10);
            piVar1[uVar3 * 4 + 0x82] = *(int *)((int)register0x00000038 + -0xc);
          }
          _splx(puVar7);
        }
        else {
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        }
      }
    }
  }
  else {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=254 start=0xf001342c */

/* WARNING: Removing unreachable block (ram,0xf001351c) */
/* WARNING: Removing unreachable block (ram,0xf0013530) */
/* WARNING: Removing unreachable block (ram,0xf00134d8) */
/* WARNING: Removing unreachable block (ram,0xf00134b8) */
/* WARNING: Removing unreachable block (ram,0xf0013468) */
/* WARNING: Removing unreachable block (ram,0xf0013470) */
/* WARNING: Removing unreachable block (ram,0xf00134c8) */
/* WARNING: Removing unreachable block (ram,0xf001350c) */
/* WARNING: Removing unreachable block (ram,0xf00134a4) */
/* WARNING: Removing unreachable block (ram,0xf0013524) */
/* WARNING: Removing unreachable block (ram,0xf0013434) */

undefined8 _realitexpire(int param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  undefined auStackX_0 [92];
  
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
  _psignal(param_1,0xe);
  if ((*(int *)(param_1 + 0x54) == 0) && (*(int *)(param_1 + 0x58) == 0)) {
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  else {
    puVar1 = (undefined *)((int)register0x00000038 + -0x10);
    _getthetime(puVar1);
    _spltty();
    iVar2 = param_1 + 0x5c;
    if (*(int *)(param_1 + 0x5c) < *(int *)((int)register0x00000038 + -0x10) + -10) {
      *(int *)(param_1 + 0x5c) = *(int *)((int)register0x00000038 + -0x10);
      *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)((int)register0x00000038 + -0xc);
      _hzto(iVar2);
    }
    else {
      _splx(puVar1);
      iVar2 = param_1 + 0x5c;
      while( true ) {
        _spltty();
        _timevaladd(iVar2,param_1 + 0x54);
        if ((*(int *)((int)register0x00000038 + -0x10) < *(int *)(param_1 + 0x5c)) ||
           ((*(int *)(param_1 + 0x5c) == *(int *)((int)register0x00000038 + -0x10) &&
            (*(int *)((int)register0x00000038 + -0xc) < *(int *)(param_1 + 0x60))))) break;
        _splx(puVar1);
      }
      _hzto(iVar2);
    }
    _timeout(_realitexpire,param_1,iVar2);
    _splx(puVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=255 start=0xf0013544 */

undefined8 _itimerfix(uint *param_1)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  uint uVar3;
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
  uVar3 = *param_1;
  if (uVar3 < 0x5f5e101) {
    uVar1 = param_1[1];
    if (uVar1 < 1000000) {
      if (uVar3 == 0) {
        if (uVar1 == 0) {
          uVar2 = 0;
        }
        else {
          if ((int)uVar1 < (int)_tick) {
            param_1[1] = _tick;
          }
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
      goto locret_F00135A8;
    }
  }
  uVar2 = 0x16;
locret_F00135A8:
  return CONCAT44(uVar3,uVar2);
}
/* GHIDRADEC_FUNCTION index=256 start=0xf00135b0 */

undefined8 _itimerdecr(int *param_1,int param_2)

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
  iVar2 = param_1[3];
  if (iVar2 < param_2) {
    if (param_1[2] != 0) {
      param_1[3] = iVar2 + 1000000;
      param_1[2] = param_1[2] + -1;
      iVar1 = param_1[3];
      goto loc_F00135F8;
    }
    iVar2 = param_2 - iVar2;
    iVar1 = *param_1;
  }
  else {
    iVar1 = param_1[3];
loc_F00135F8:
    param_1[3] = iVar1 - param_2;
    iVar2 = 0;
    if ((param_1[2] != 0) || (iVar1 - param_2 != 0)) {
      uVar3 = 1;
      goto locret_F0013674;
    }
    iVar1 = *param_1;
  }
  if ((iVar1 == 0) && (param_1[1] == 0)) {
    param_1[3] = 0;
  }
  else {
    param_1[2] = iVar1;
    iVar2 = param_1[1] - iVar2;
    param_1[3] = iVar2;
    if (iVar2 < 0) {
      param_1[3] = iVar2 + 1000000;
      param_1[2] = param_1[2] + -1;
    }
  }
  uVar3 = 0;
locret_F0013674:
  return CONCAT44(iVar2,uVar3);
}
/* GHIDRADEC_FUNCTION index=257 start=0xf001367c */

/* WARNING: Removing unreachable block (ram,0xf00136a0) */

undefined8 _timevaladd(int *param_1,int *param_2)

{
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
  *param_1 = *param_1 + *param_2;
  param_1[1] = param_1[1] + param_2[1];
  _timevalfix();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=258 start=0xf00136b0 */

/* WARNING: Removing unreachable block (ram,0xf00136d4) */

undefined8 _timevalsub(int *param_1,int *param_2)

{
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
  *param_1 = *param_1 - *param_2;
  param_1[1] = param_1[1] - param_2[1];
  _timevalfix();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=259 start=0xf00136e4 */

undefined8 _timevalfix(int *param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = param_1[1];
  if (param_1[1] < 0) {
    *param_1 = *param_1 + -1;
    param_1[1] = iVar1 + 1000000;
    iVar1 = param_1[1];
  }
  if (999999 < iVar1) {
    *param_1 = *param_1 + 1;
    param_1[1] = param_1[1] + -1000000;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=260 start=0xf0013754 */

/* WARNING: Removing unreachable block (ram,0xf0013838) */
/* WARNING: Removing unreachable block (ram,0xf00137f4) */
/* WARNING: Removing unreachable block (ram,0xf00137ac) */
/* WARNING: Removing unreachable block (ram,0xf00137dc) */
/* WARNING: Removing unreachable block (ram,0xf0013820) */
/* WARNING: Removing unreachable block (ram,0xf001386c) */
/* WARNING: Removing unreachable block (ram,0xf0013778) */

undefined8 _uname(undefined4 param_1,undefined4 param_2)

{
  undefined uVar2;
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined *puVar4;
  undefined4 unaff_l3;
  int *piVar5;
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
  undefined auStackX_0 [92];
  
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
  uVar2 = 0x18;
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  puVar4 = (undefined *)((int)register0x00000038 + -0x2c);
  _copyoutstr(aNextstep,*piVar5,0x20,puVar4);
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    uVar2 = 0x30;
    _copyoutstr(_hostname,*piVar5 + 0x20,0x20,puVar4);
    *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
    puVar3 = (undefined *)((int)register0x00000038 + -0x28);
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      _sprintf(puVar3,&aD_0,0);
      puVar1 = puVar3;
      _copyoutstr(puVar3,*piVar5 + 0x40,0x20,puVar4);
      *(char *)(dword_F0133DDC + 0x38) = (char)puVar1;
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        _sprintf(puVar3,&aD_1,4);
        _copyoutstr(puVar3,*piVar5 + 0x60,0x20,puVar4);
        *(char *)(dword_F0133DDC + 0x38) = (char)puVar3;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          uVar2 = 0x38;
          _copyoutstr(&aUnknown,*piVar5 + 0x80,0x20,puVar4);
          *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=261 start=0xf0013884 */

undefined8 _gethostid(undefined4 param_1,undefined4 param_2)

{
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
  *(undefined4 *)(dword_F0133DDC + 0x30) = _hostid;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=262 start=0xf00138a4 */

/* WARNING: Removing unreachable block (ram,0xf00138b0) */

undefined8 _sethostid(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    _hostid = *puVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=263 start=0xf00138d4 */

/* WARNING: Removing unreachable block (ram,0xf0013908) */

undefined8 _gethostname(undefined4 param_1,undefined4 param_2)

{
  undefined uVar1;
  uint uVar2;
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
  uVar2 = (*(undefined4 **)(dword_F0133DDC + 0x24))[1];
  if (_hostnamelen + 1U < uVar2) {
    uVar2 = _hostnamelen + 1U;
  }
  uVar1 = 0x30;
  _copyout(_hostname,**(undefined4 **)(dword_F0133DDC + 0x24),uVar2);
  *(undefined *)(dword_F0133DDC + 0x38) = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=264 start=0xf0013920 */

/* WARNING: Removing unreachable block (ram,0xf0013974) */
/* WARNING: Removing unreachable block (ram,0xf001392c) */

undefined8 _sethostname(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    if ((uint)puVar3[1] < 0x100) {
      uVar2 = *puVar3;
      _hostnamelen = puVar3[1];
      _copyin(uVar2,_hostname,puVar3[1]);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
      _hostname[_hostnamelen] = 0;
    }
    else {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=265 start=0xf0013994 */

/* WARNING: Removing unreachable block (ram,0xf00139c8) */

undefined8 _getdomainname(undefined4 param_1,undefined4 param_2)

{
  undefined uVar1;
  uint uVar2;
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
  uVar2 = (*(undefined4 **)(dword_F0133DDC + 0x24))[1];
  if (_domainnamelen + 1U < uVar2) {
    uVar2 = _domainnamelen + 1U;
  }
  uVar1 = 0;
  _copyout(_domainname,**(undefined4 **)(dword_F0133DDC + 0x24),uVar2);
  *(undefined *)(dword_F0133DDC + 0x38) = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=266 start=0xf00139e0 */

/* WARNING: Removing unreachable block (ram,0xf0013a34) */
/* WARNING: Removing unreachable block (ram,0xf00139ec) */

undefined8 _setdomainname(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    if ((uint)puVar3[1] < 0x100) {
      uVar2 = *puVar3;
      _domainnamelen = puVar3[1];
      _copyin(uVar2,_domainname,puVar3[1]);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
      _domainname[_domainnamelen] = 0;
    }
    else {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=267 start=0xf0013a54 */

/* WARNING: Removing unreachable block (ram,0xf0013a90) */
/* WARNING: Removing unreachable block (ram,0xf0013abc) */
/* WARNING: Removing unreachable block (ram,0xf0013a58) */

undefined8 _reboot(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
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
  undefined auStackX_0 [92];
  
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
  *(undefined *)((int)register0x00000038 + -0x48) = 0;
  iVar1 = param_1;
  _suser();
  if (iVar1 != 0) {
    if ((**(uint **)(dword_F0133DDC + 0x24) & 0x100000) != 0) {
      uVar2 = (*(uint **)(dword_F0133DDC + 0x24))[1];
      _copyinstr(uVar2,(undefined *)((int)register0x00000038 + -0x48),0x40,0);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
    }
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      _boot(1,**(undefined4 **)(dword_F0133DDC + 0x24),
            (undefined *)((int)register0x00000038 + -0x48));
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=268 start=0xf0013acc */

/* WARNING: Removing unreachable block (ram,0xf0013d00) */
/* WARNING: Removing unreachable block (ram,0xf0013bb8) */
/* WARNING: Removing unreachable block (ram,0xf0013d08) */
/* WARNING: Removing unreachable block (ram,0xf0013b24) */

undefined8 _ptrace(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  piVar6 = *(int **)(dword_F0133DDC + 0x24);
  if (*piVar6 < 1) {
    *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x10;
    *(undefined4 *)(*_active_u + 0x7c) = *(undefined4 *)(*_active_u + 0x44);
    *(int *)(*(int *)(*_active_u + 0x44) + 0x80) = *_active_u;
    goto locret_F0013D24;
  }
  iVar1 = piVar6[1];
  _pfind();
  if (iVar1 == 0) {
loc_F0013B3C:
    uVar2 = 3;
  }
  else {
    iVar3 = *piVar6;
    iVar7 = *(int *)(iVar1 + 0x68);
    if (iVar3 == 10) {
      iVar3 = *_active_u;
      if (*(sword *)(iVar3 + 0x2c) == 0) {
        uVar4 = *(uint *)(iVar1 + 0x28);
      }
      else {
        if (*(sword *)(iVar1 + 0x2c) != *(sword *)(iVar3 + 0x2c)) goto loc_F0013B3C;
        uVar4 = *(uint *)(iVar1 + 0x28);
      }
      if (((uVar4 & 0x10) == 0) && (*(int *)(iVar3 + 0x80) == 0)) {
        *(uint *)(iVar1 + 0x28) = uVar4 | 0x10;
        *(int *)(iVar1 + 0x7c) = *_active_u;
        *(int *)(iVar3 + 0x80) = iVar1;
        _psignal(iVar1,0x11);
        goto locret_F0013D24;
      }
      goto loc_F0013B3C;
    }
    if ((((*(int *)(iVar7 + 0x44) == 0) || (*(char *)(iVar1 + 0x13) != '\x06')) ||
        (iVar5 = *(int *)(iVar1 + 0x7c), iVar5 != *_active_u)) ||
       ((*(uint *)(iVar1 + 0x28) & 0x10) == 0)) goto loc_F0013B3C;
    if (iVar3 == 8) {
      *(char *)(iVar1 + 0x17) = *(char *)(iVar1 + 0x17) + ' ';
loc_F0013CDC:
      *(undefined *)(iVar1 + 0x13) = 3;
      if ((*(int *)(iVar1 + 0x6c) != 0) && (*(char *)(iVar1 + 0x17) != '\0')) {
        _clear_wait(*(int *)(iVar1 + 0x6c),2,1);
      }
      _task_resume(iVar7);
      goto locret_F0013D24;
    }
    if (iVar3 < 9) {
      if (iVar3 == 7) {
        iVar3 = *(int *)(iVar7 + 0x1c);
loc_F0013C80:
        if ((uint)piVar6[3] < 0x21) {
          if ((0x1ef8 >> (*(char *)(iVar1 + 0x17) - 1U & 0x1f) & 1U) != 0) {
            *(undefined *)(*(int *)(iVar3 + 0x84) + 0x48) = 0;
          }
          *(char *)(iVar1 + 0x17) = (char)piVar6[3];
          if ((0x1ef8 >> ((char)piVar6[3] - 1U & 0x1f) & 1U) != 0) {
            *(char *)(*(int *)(iVar3 + 0x84) + 0x48) = (char)piVar6[3];
          }
          goto loc_F0013CDC;
        }
      }
loc_F0013D18:
      uVar2 = 5;
    }
    else {
      if (iVar3 == 9) {
        iVar3 = *(int *)(iVar7 + 0x1c);
        goto loc_F0013C80;
      }
      if (iVar3 != 0xb) goto loc_F0013D18;
      iVar3 = *(int *)(iVar5 + 0x80);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 0x7c) = 0;
        *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & 0xffffffef;
        *(undefined4 *)(iVar5 + 0x80) = 0;
        goto loc_F0013CDC;
      }
      uVar2 = 0x16;
    }
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
locret_F0013D24:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=269 start=0xf0013d2c */

/* WARNING: Removing unreachable block (ram,0xf0013d68) */
/* WARNING: Removing unreachable block (ram,0xf0013da8) */
/* WARNING: Removing unreachable block (ram,0xf0013d5c) */

undefined8 _thread_psignal(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar3;
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
  if (param_2 < (int *)0x21) {
    uVar3 = 1 << ((char)param_2 - 1U & 0x1f);
    if ((uVar3 & 0x1ef8) == 0) {
      _printf(aSignalD);
      _panic(aThreadPsignalS);
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    iVar1 = *(int *)(iVar1 + 0x3c);
    param_2 = (int *)(iVar1 + 0x70);
    if (((*(uint *)(iVar1 + 0x20) & uVar3) == 0) || ((*(uint *)(iVar1 + 0x28) & 0x10) != 0)) {
      do {
        do {
        } while (*param_2 != 0);
        piVar2 = param_2;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *(uint *)(*(int *)(param_1 + 0x84) + 0x4c) =
           *(uint *)(*(int *)(param_1 + 0x84) + 0x4c) | uVar3;
      *(undefined4 *)(iVar1 + 0x70) = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=270 start=0xf0013dd8 */

/* WARNING: Removing unreachable block (ram,0xf0013e30) */
/* WARNING: Removing unreachable block (ram,0xf0013e18) */

undefined8 _qsort(undefined *param_1,undefined *param_2,int param_3,code *param_4)

{
  undefined uVar1;
  int iVar2;
  undefined uVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined *puVar6;
  undefined4 unaff_i3;
  undefined *puVar7;
  undefined *puVar8;
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
  if (1 < (int)param_2) {
    dword_F010B484 = param_3 << 2;
    dword_F010B488 = param_3 * 6;
    puVar5 = param_2;
    dword_F010B47C = param_4;
    dword_F010B480 = param_3;
    .umul(param_2,param_3);
    puVar5 = param_1 + (int)puVar5;
    puVar8 = puVar5;
    if (3 < (int)param_2) {
      sub_F0013FA4(param_1,puVar5);
      puVar8 = param_1 + dword_F010B484;
    }
    param_2 = param_1 + dword_F010B480;
    iVar2 = 0;
    puVar6 = param_1;
    if (param_2 < puVar8) {
      do {
        puVar7 = puVar6;
        (*dword_F010B47C)(puVar6,param_2);
        if (0 < (int)puVar7) {
          puVar6 = param_2;
        }
        param_2 = param_2 + dword_F010B480;
      } while (param_2 < puVar8);
      iVar2 = (int)puVar6 - (int)param_1;
    }
    if (iVar2 != 0) {
      puVar7 = param_1 + dword_F010B480;
      for (puVar8 = param_1; puVar8 < puVar7; puVar8 = puVar8 + 1) {
        uVar1 = *puVar6;
        *puVar6 = *puVar8;
        *puVar8 = uVar1;
        puVar6 = puVar6 + 1;
      }
    }
    for (param_1 = param_1 + dword_F010B480; puVar8 = param_1, param_1 < puVar5;
        param_1 = param_1 + dword_F010B480) {
      do {
        puVar8 = puVar8 + -dword_F010B480;
        puVar6 = puVar8;
        (*dword_F010B47C)(puVar8,param_1);
      } while (0 < (int)puVar6);
      puVar8 = puVar8 + dword_F010B480;
      if (puVar8 != param_1) {
        param_2 = param_1 + dword_F010B480;
        while (param_2 = param_2 + -1, param_1 <= param_2) {
          puVar7 = param_2 + -dword_F010B480;
          uVar1 = *param_2;
          puVar6 = param_2;
          if (puVar8 <= puVar7) {
            uVar3 = *puVar7;
            puVar4 = param_2;
            puVar6 = puVar7;
            while( true ) {
              *puVar4 = uVar3;
              puVar7 = puVar6 + -dword_F010B480;
              if (puVar7 < puVar8) break;
              uVar3 = *puVar7;
              puVar4 = puVar6;
              puVar6 = puVar7;
            }
          }
          *puVar6 = uVar1;
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=271 start=0xf00141d0 */

/* WARNING: Removing unreachable block (ram,0xf0014214) */

undefined8 _logopen(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  if (_log_open == 0) {
    dword_F0135184 = 0;
    dword_F0135188 = (int)*(sword *)(*_active_u + 0x2e);
    pcVar2 = sub_F001449C;
    _calloutEntryAllocate(sub_F001449C,0);
    piVar1 = _pmsgbuf;
    _log_open = 1;
    uVar5 = 0;
    dword_F013518C = pcVar2;
    if (*_pmsgbuf != 0x63061) {
      *_pmsgbuf = 0x63061;
      piVar1[2] = 0;
      piVar1[1] = 0;
      uVar3 = 0;
      do {
        uVar4 = uVar3 + 1;
        *(undefined *)((int)_pmsgbuf + uVar3 + 0xc) = 0;
        uVar3 = uVar4;
      } while (uVar4 < 0xff4);
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0x10;
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=272 start=0xf0014280 */

/* WARNING: Removing unreachable block (ram,0xf00142b8) */
/* WARNING: Removing unreachable block (ram,0xf00142a4) */
/* WARNING: Removing unreachable block (ram,0xf00142ac) */
/* WARNING: Removing unreachable block (ram,0xf00142cc) */
/* WARNING: Removing unreachable block (ram,0xf001429c) */

undefined8 _logclose(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
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
  
  uVar2 = dword_F013518C;
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
  _log_open = 0;
  dword_F013518C = 0;
  _calloutEntryRemove(uVar2);
  _calloutEntryFree(uVar2);
  _logsoftc = 0;
  _splusclock();
  iVar1 = dword_F0135184;
  dword_F0135184 = 0;
  _splx();
  if (iVar1 != 0) {
    _thread_deallocate(iVar1);
  }
  dword_F0135188 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=273 start=0xf00142e0 */

/* WARNING: Removing unreachable block (ram,0xf0014358) */
/* WARNING: Removing unreachable block (ram,0xf0014320) */
/* WARNING: Removing unreachable block (ram,0xf0014338) */
/* WARNING: Removing unreachable block (ram,0xf00143c4) */
/* WARNING: Removing unreachable block (ram,0xf00142e4) */

undefined8 _logread(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  iVar4 = 0;
  _splusclock();
  if (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4)) {
    do {
      if ((_logsoftc & 2) != 0) {
        _splx(param_1);
        iVar4 = 0x23;
        goto locret_F001440C;
      }
      _logsoftc = _logsoftc | 8;
      _sleep(_pmsgbuf,0x1a);
    } while (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4));
  }
  _splx(param_1);
  _logsoftc = _logsoftc & 0xfffffff7;
  iVar1 = *(int *)(param_2 + 0x14);
  while (0 < iVar1) {
    iVar3 = *(int *)(_pmsgbuf + 8);
    iVar1 = *(int *)(_pmsgbuf + 4) - iVar3;
    if (iVar1 < 0) {
      iVar1 = 0xff4 - iVar3;
    }
    if (*(int *)(param_2 + 0x14) < iVar1) {
      iVar1 = *(int *)(param_2 + 0x14);
    }
    if (iVar1 == 0) break;
    iVar4 = _pmsgbuf + iVar3 + 0xc;
    _uiomove(iVar4,iVar1,0,param_2);
    iVar3 = _pmsgbuf;
    if (iVar4 != 0) break;
    uVar2 = *(int *)(_pmsgbuf + 8) + iVar1;
    *(uint *)(_pmsgbuf + 8) = uVar2;
    if (((int)uVar2 < 0) || (0xff3 < uVar2)) {
      *(undefined4 *)(iVar3 + 8) = 0;
      iVar1 = *(int *)(param_2 + 0x14);
    }
    else {
      iVar1 = *(int *)(param_2 + 0x14);
    }
  }
locret_F001440C:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=274 start=0xf0014414 */

/* WARNING: Removing unreachable block (ram,0xf0014458) */
/* WARNING: Removing unreachable block (ram,0xf0014448) */
/* WARNING: Removing unreachable block (ram,0xf0014460) */
/* WARNING: Removing unreachable block (ram,0xf0014418) */

undefined8 _logselect(undefined4 param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  _splusclock();
  if (param_2 == 1) {
    if (*(int *)(_pmsgbuf + 8) != *(int *)(_pmsgbuf + 4)) {
      _splx(param_1);
      uVar1 = 1;
      goto locret_F001446C;
    }
    _selthreadcache(&dword_F0135184);
  }
  _splx(param_1);
  uVar1 = 0;
locret_F001446C:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=275 start=0xf0014474 */

/* WARNING: Removing unreachable block (ram,0xf001448c) */

undefined8 _logwakeup(undefined4 param_1,undefined4 param_2)

{
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
  if (_log_open != 0) {
    _calloutEntryDispatch(dword_F013518C);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=276 start=0xf0014534 */

/* WARNING: Removing unreachable block (ram,0xf00145c0) */
/* WARNING: Removing unreachable block (ram,0xf00145a8) */

undefined8 _logioctl(int param_1,int *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 uVar2;
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
  if (param_1 == -0x7ffb8b8a) {
    dword_F0135188 = *param_2;
  }
  else if (param_1 < -0x7ffb8b89) {
    if (param_1 == -0x7ffb9983) {
      if (*param_2 == 0) {
        _logsoftc = _logsoftc & 0xfffffffb;
      }
      else {
        _logsoftc = _logsoftc | 4;
      }
    }
    else {
      if (param_1 != -0x7ffb9982) {
        uVar2 = 0xffffffff;
        goto locret_F0014650;
      }
      if (*param_2 == 0) {
        _logsoftc = _logsoftc & 0xfffffffd;
      }
      else {
        _logsoftc = _logsoftc | 2;
      }
    }
  }
  else if (param_1 == 0x4004667f) {
    _splusclock();
    iVar1 = *(int *)(_pmsgbuf + 4) - *(int *)(_pmsgbuf + 8);
    _splx();
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xff4;
    }
    *param_2 = iVar1;
  }
  else {
    if (param_1 != 0x40047477) {
      uVar2 = 0xffffffff;
      goto locret_F0014650;
    }
    *param_2 = dword_F0135188;
  }
  uVar2 = 0;
locret_F0014650:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=277 start=0xf0014658 */

/* WARNING: Removing unreachable block (ram,0xf0014690) */
/* WARNING: Removing unreachable block (ram,0xf001467c) */

sqword _printf(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6)

{
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
  undefined auStackX_0 [92];
  
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
  *(uint *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  _prf(param_1,(undefined *)((int)register0x00000038 + 0x48),5,0);
  if (param_1 != 0) {
    _logwakeup();
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=278 start=0xf00146a0 */

/* WARNING: Removing unreachable block (ram,0xf00146e4) */
/* WARNING: Removing unreachable block (ram,0xf00146d0) */

undefined8
_uprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
        undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  iVar1 = *(int *)(_active_u + 0x164);
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  if (iVar1 != 0) {
    _ttycheckoutq(iVar1,1);
    _prf(param_1,(undefined *)((int)register0x00000038 + 0x48),2,iVar1);
    param_1 = 0;
  }
  return CONCAT44(iVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=279 start=0xf00146f8 */

/* WARNING: Removing unreachable block (ram,0xf0014750) */
/* WARNING: Removing unreachable block (ram,0xf0014730) */
/* WARNING: Removing unreachable block (ram,0xf0014758) */
/* WARNING: Removing unreachable block (ram,0xf0014710) */

sqword _tprintf(undefined *param_1,uint param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
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
  undefined4 uVar2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  uVar2 = 6;
  sub_F0014868(6);
  if (param_1 == (undefined *)0x0) {
    param_1 = _cons;
  }
  puVar1 = param_1;
  _ttycheckoutq(param_1,0);
  if (puVar1 == (undefined *)0x0) {
    uVar2 = 4;
  }
  _prf(param_2,(undefined *)((int)register0x00000038 + 0x4c),uVar2,param_1);
  _logwakeup();
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=280 start=0xf0014768 */

/* WARNING: Removing unreachable block (ram,0xf001478c) */

undefined8
_sprintf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
        undefined4 param_6)

{
  undefined *puVar1;
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
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  *(int *)((int)register0x00000038 + -0xc) = param_1;
  _prf(param_2,(undefined *)((int)register0x00000038 + 0x4c),8,
       (undefined *)((int)register0x00000038 + -0xc));
  puVar1 = *(undefined **)((int)register0x00000038 + -0xc);
  *(undefined **)((int)register0x00000038 + -0xc) = puVar1 + 1;
  *puVar1 = 0;
  return CONCAT44(param_2,*(int *)((int)register0x00000038 + -0xc) - param_1);
}
/* GHIDRADEC_FUNCTION index=281 start=0xf00147b4 */

/* WARNING: Removing unreachable block (ram,0xf001481c) */
/* WARNING: Removing unreachable block (ram,0xf00147f0) */
/* WARNING: Removing unreachable block (ram,0xf00147d0) */
/* WARNING: Removing unreachable block (ram,0xf00147e8) */
/* WARNING: Removing unreachable block (ram,0xf0014814) */
/* WARNING: Removing unreachable block (ram,0xf0014824) */
/* WARNING: Removing unreachable block (ram,0xf00147c4) */

sqword _log(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
           ,undefined4 param_6)

{
  undefined4 uVar1;
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
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  uVar1 = param_1;
  _splusclock();
  sub_F0014868(param_1);
  _prf(param_2,(undefined *)((int)register0x00000038 + 0x4c),4,0);
  _splx(uVar1);
  if (_log_open == 0) {
    _prf(param_2,(undefined *)((int)register0x00000038 + 0x4c),1,0);
  }
  _logwakeup();
  _splx(uVar1);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=282 start=0xf0014834 */

/* WARNING: Removing unreachable block (ram,0xf0014858) */
/* WARNING: Removing unreachable block (ram,0xf0014844) */

sqword _vlog(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
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
  uVar1 = param_2;
  _prf(param_2,param_3,5,0);
  if (uVar1 != 0) {
    _logwakeup();
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=283 start=0xf00148a0 */

/* WARNING: Removing unreachable block (ram,0xf00148bc) */

undefined8
__printf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
        undefined4 param_5,undefined4 param_6)

{
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
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  _prf(param_3,(undefined *)((int)register0x00000038 + 0x50),param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=284 start=0xf00148cc */

/* WARNING: Removing unreachable block (ram,0xf0014d04) */
/* WARNING: Removing unreachable block (ram,0xf001501c) */
/* WARNING: Removing unreachable block (ram,0xf0014fd4) */
/* WARNING: Removing unreachable block (ram,0xf0014f4c) */
/* WARNING: Removing unreachable block (ram,0xf0014ee0) */
/* WARNING: Removing unreachable block (ram,0xf0014ea0) */
/* WARNING: Removing unreachable block (ram,0xf0014e24) */
/* WARNING: Removing unreachable block (ram,0xf0014d60) */
/* WARNING: Removing unreachable block (ram,0xf0014bb4) */
/* WARNING: Removing unreachable block (ram,0xf0014ba0) */
/* WARNING: Removing unreachable block (ram,0xf0014c30) */
/* WARNING: Removing unreachable block (ram,0xf0014b18) */
/* WARNING: Removing unreachable block (ram,0xf0014b60) */
/* WARNING: Removing unreachable block (ram,0xf0014c50) */
/* WARNING: Removing unreachable block (ram,0xf0014bfc) */
/* WARNING: Removing unreachable block (ram,0xf0014d44) */
/* WARNING: Removing unreachable block (ram,0xf0014d88) */
/* WARNING: Removing unreachable block (ram,0xf0014e74) */
/* WARNING: Removing unreachable block (ram,0xf0014ec0) */
/* WARNING: Removing unreachable block (ram,0xf0014dc4) */
/* WARNING: Removing unreachable block (ram,0xf0014f74) */
/* WARNING: Removing unreachable block (ram,0xf0015000) */
/* WARNING: Removing unreachable block (ram,0xf0014ae8) */
/* WARNING: Removing unreachable block (ram,0xf00148ec) */
/* WARNING: Removing unreachable block (ram,0xf0014cbc) */

undefined8 _prf(char *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 unaff_l0;
  int iVar6;
  int iVar7;
  undefined4 unaff_l1;
  char *pcVar8;
  char *pcVar9;
  uint *puVar10;
  uint *puVar11;
  byte bVar12;
  char cVar13;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 uVar14;
  uint uVar15;
  undefined4 unaff_l6;
  undefined4 uVar16;
  undefined4 unaff_l7;
  undefined4 uVar17;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar18;
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
  uVar16 = 0;
  uVar17 = 1;
loc_F00148F4:
  iVar6 = (int)*param_1;
def_F0014968:
  param_1 = param_1 + 1;
  if (iVar6 == 0x25) {
loc_F0014904:
    iVar6 = (int)*param_1;
    if (iVar6 == 0x30) {
      uVar16 = 0x30;
    }
    while (param_1 = param_1 + 1, iVar6 - 0x30U < 10) {
      iVar6 = (int)*param_1;
    }
    switch(iVar6) {
    case :
      iVar6 = 0x25;
      goto loc_F00148E8;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      goto loc_F00148F4;
    case :
      goto loc_F0014CE4;
    case :
    case :
    case :
      uVar14 = 10;
      break;
    case :
      uVar17 = 0;
      goto loc_F00148F4;
    case :
    case :
      uVar15 = *param_2;
      puVar10 = (uint *)param_2[1];
      goto loc_F0014FA8;
    case :
    case :
      uVar14 = 8;
      break;
    case :
    case :
      uVar15 = *param_2;
      puVar10 = (uint *)param_2[1];
      if (iVar6 == 0x52) {
        sub_F001503C(&unk_F010B490,param_3,param_4);
        sub_F0015074(uVar15,0x10,param_3,param_4,0,0);
      }
      bVar2 = false;
      if ((iVar6 != 0x72) && (uVar15 == 0)) {
        iVar6 = (int)*param_1;
        param_2 = param_2 + 2;
        goto def_F0014968;
      }
      sub_F00152F0(0x3c,param_3,param_4);
      if (*puVar10 == 0) goto loc_F0014F68;
      puVar11 = puVar10 + 4;
      uVar3 = *puVar10;
      goto loc_F0014DA8;
    case :
    case :
      uVar14 = 0x10;
      break;
    case :
      uVar15 = *param_2;
      iVar6 = 0;
      pcVar9 = (char *)param_2[1] + 1;
      sub_F0015074(uVar15,(int)*(char *)param_2[1],param_3,param_4,0,0);
      if (uVar15 != 0) {
        cVar13 = *pcVar9;
        goto loc_F0014C88;
      }
      iVar6 = (int)*param_1;
      param_2 = param_2 + 2;
      goto def_F0014968;
    case :
      uVar15 = *param_2;
      iVar6 = 0x18;
      bVar12 = 0x18;
      do {
        uVar3 = (int)uVar15 >> bVar12 & 0x7f;
        if (uVar3 != 0) {
          sub_F00152F0(uVar3,param_3,param_4);
        }
        iVar6 = iVar6 + -8;
        bVar12 = (byte)iVar6 & 0x1f;
      } while (-1 < iVar6);
      iVar6 = (int)*param_1;
      param_2 = param_2 + 1;
      goto def_F0014968;
    case :
      goto loc_F0014904;
    case :
      puVar10 = param_2 + 1;
      pcVar9 = (char *)*param_2;
      iVar6 = (int)*pcVar9;
      param_2 = puVar10;
      if (iVar6 == 0) goto loc_F00148F4;
      do {
        pcVar9 = pcVar9 + 1;
        sub_F00152F0(iVar6,param_3,param_4);
        iVar6 = (int)*pcVar9;
      } while (iVar6 != 0);
      iVar6 = (int)*param_1;
      goto def_F0014968;
    :
      goto loc_f0014950;
    }
    sub_F0015074(*param_2,uVar14,param_3,param_4,uVar16);
    iVar6 = (int)*param_1;
    param_2 = param_2 + 1;
    goto def_F0014968;
  }
  if (iVar6 == 0) {
    return CONCAT44(param_2,uVar17);
  }
  goto loc_F00148E8;
loc_f0014950:
  iVar6 = (int)*param_1;
  goto def_F0014968;
loc_F0014C88:
  pcVar8 = pcVar9 + 1;
  if (cVar13 != '\0') {
    if (*pcVar8 < '!') {
      iVar6 = iVar6 + 1;
      if (iVar6 != 1) {
        sub_F00152F0(0x2c,param_3,param_4);
      }
      cVar1 = *pcVar8;
      pcVar9 = pcVar8;
      while( true ) {
        pcVar9 = pcVar9 + 1;
        if (*pcVar9 < 0x21) break;
        sub_F00152F0((int)*pcVar9,param_3,param_4);
      }
      sub_F0015074((int)uVar15 >> (cVar1 - 1U & 0x1f) & (2 << (cVar13 - cVar1 & 0x1fU)) - 1U,8,
                   param_3,param_4,0,0);
      cVar13 = *pcVar9;
    }
    else if (((int)uVar15 >> (cVar13 - 1U & 0x1f) & 1U) == 0) {
      for (pcVar8 = pcVar9 + 2; ' ' < *pcVar8; pcVar8 = pcVar8 + 1) {
      }
loc_F0014C84:
      cVar13 = *pcVar8;
      pcVar9 = pcVar8;
    }
    else {
      uVar14 = 0x3c;
      if (iVar6 != 0) {
        uVar14 = 0x2c;
      }
      sub_F00152F0(uVar14,param_3,param_4);
      iVar7 = (int)*pcVar8;
      iVar6 = 1;
      if (iVar7 < 0x21) goto loc_F0014C84;
      do {
        sub_F00152F0(iVar7,param_3,param_4);
        pcVar8 = pcVar8 + 1;
        iVar7 = (int)*pcVar8;
      } while (0x20 < iVar7);
      cVar13 = *pcVar8;
      pcVar9 = pcVar8;
    }
    goto loc_F0014C88;
  }
  iVar6 = 0x3e;
  param_2 = param_2 + 2;
  goto loc_F00148E8;
loc_F0014DA8:
  do {
    bVar12 = (byte)puVar11[-3];
    if ((int)puVar11[-3] < 1) {
      uVar3 = (uVar15 & uVar3) >> (-bVar12 & 0x1f);
    }
    else {
      uVar3 = (uVar15 & uVar3) << (bVar12 & 0x1f);
    }
    if (bVar2) {
      if ((puVar11[-1] == 0) && (*puVar11 == 0)) {
        uVar4 = 0;
        if (puVar11[-2] == 0) goto loc_F0014E30;
        if (uVar3 != 0) goto loc_F0014E20;
      }
      else {
loc_F0014E20:
        sub_F00152F0(0x2c,param_3,param_4);
      }
      uVar4 = puVar11[-2];
    }
    else {
      uVar4 = puVar11[-2];
    }
loc_F0014E30:
    if (uVar4 == 0) {
      uVar4 = puVar11[-1];
    }
    else {
      if (puVar11[-1] == 0) {
        if (*puVar11 != 0) {
          uVar4 = puVar11[-2];
          goto loc_F0014E6C;
        }
        if (uVar3 != 0) {
          uVar4 = puVar11[-2];
          goto loc_F0014E6C;
        }
        uVar4 = puVar11[-1];
      }
      else {
        uVar4 = puVar11[-2];
loc_F0014E6C:
        bVar2 = true;
        sub_F001503C(uVar4,param_3,param_4);
        uVar4 = puVar11[-1];
      }
      if ((uVar4 != 0) || (*puVar11 != 0)) {
        sub_F00152F0(0x3d,param_3,param_4);
        bVar2 = true;
      }
      uVar4 = puVar11[-1];
    }
    if (uVar4 == 0) {
loc_F0014EE8:
      puVar5 = (uint *)*puVar11;
      bVar18 = puVar5 == (uint *)0x0;
    }
    else {
      __printf(param_3,param_4,uVar4,uVar3);
      bVar18 = *puVar11 == 0;
      bVar2 = true;
      puVar5 = (uint *)0x0;
      if (!bVar18) {
        sub_F00152F0(0x3a,param_3,param_4);
        goto loc_F0014EE8;
      }
    }
    if (!bVar18) {
      bVar18 = puVar5[1] == 0;
      bVar2 = true;
      if (!bVar18) {
        uVar4 = *puVar5;
        while (uVar3 != uVar4) {
          if (puVar5[3] == 0) {
            uVar3 = puVar5[3];
            goto loc_F0014F34;
          }
          uVar4 = puVar5[2];
          puVar5 = puVar5 + 2;
        }
        sub_F001503C(puVar5[1],param_3,param_4);
        uVar3 = puVar5[1];
loc_F0014F34:
        bVar18 = uVar3 == 0;
      }
      if (bVar18) {
        sub_F001503C(&unk_F010B498,param_3,param_4);
      }
    }
    puVar10 = puVar10 + 5;
    uVar3 = *puVar10;
    puVar11 = puVar11 + 5;
  } while (uVar3 != 0);
loc_F0014F68:
  iVar6 = 0x3e;
  param_2 = param_2 + 2;
loc_F00148E8:
  sub_F00152F0(iVar6,param_3,param_4);
  goto loc_F00148F4;
loc_F0014FA8:
  if (puVar10[1] == 0) goto loc_f0014fb8;
  if (uVar15 == *puVar10) {
    sub_F001503C(puVar10[1],param_3,param_4);
    uVar3 = puVar10[1];
    goto loc_F0014FBC;
  }
  puVar10 = puVar10 + 2;
  goto loc_F0014FA8;
loc_f0014fb8:
  uVar3 = puVar10[1];
loc_F0014FBC:
  if (uVar3 == 0) {
    sub_F001503C(unk_F010B4A0,param_3,param_4);
  }
  if ((iVar6 == 0x4e) || (puVar10[1] == 0)) {
    sub_F00152F0(0x3a,param_3,param_4);
    sub_F0015074(uVar15,10,param_3,param_4,0,0);
    iVar6 = (int)*param_1;
    param_2 = param_2 + 2;
  }
  else {
    iVar6 = (int)*param_1;
    param_2 = param_2 + 2;
  }
  goto def_F0014968;
loc_F0014CE4:
  uVar15 = *param_2;
  iVar6 = 0x18;
  bVar12 = 0x18;
  do {
    uVar3 = (int)uVar15 >> bVar12 & 0xff;
    if (uVar3 != 0) {
      sub_F00152F0(uVar3,param_3,param_4);
    }
    iVar6 = iVar6 + -8;
    bVar12 = (byte)iVar6 & 0x1f;
  } while (-1 < iVar6);
  iVar6 = (int)*param_1;
  param_2 = param_2 + 1;
  goto def_F0014968;
}
/* GHIDRADEC_FUNCTION index=285 start=0xf001515c */

undefined8 _panic_init(undefined4 param_1,undefined4 param_2)

{
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
  _panic_lock = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=286 start=0xf0015170 */

/* WARNING: Removing unreachable block (ram,0xf0015230) */
/* WARNING: Removing unreachable block (ram,0xf0015200) */
/* WARNING: Removing unreachable block (ram,0xf00151d0) */
/* WARNING: Removing unreachable block (ram,0xf0015214) */
/* WARNING: Removing unreachable block (ram,0xf0015244) */
/* WARNING: Removing unreachable block (ram,0xf0015190) */

undefined8 _panic(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar2;
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
  uVar2 = 0;
  do {
    do {
    } while (_panic_lock != 0);
    puVar1 = &_panic_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if (_panicstr == 0) {
    _paniccpu = 0;
    _panicstr = param_1;
  }
  else if (_paniccpu == 0) {
    uVar2 = 4;
  }
  else {
    _panic_lock = 0;
    _halt_cpu();
  }
  _panic_lock = 0;
  _printf(aPanicCpuDS,_paniccpu,param_1);
  _printf(aPanicS,_version);
  _mini_mon(&aPanic,aSystemPanic,_boothowto);
  _boot(0,uVar2,&unk_F010B500);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=287 start=0xf0015254 */

/* WARNING: Removing unreachable block (ram,0xf0015274) */
/* WARNING: Removing unreachable block (ram,0xf0015260) */

undefined8 _tablefull(undefined4 param_1,undefined4 param_2)

{
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
  _printf(aSTableIsFull,param_1);
  _log(3,aSTableIsFull_0,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=288 start=0xf0015284 */

/* WARNING: Removing unreachable block (ram,0xf00152a8) */

undefined8 _harderr(int param_1,undefined4 param_2)

{
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
  _printf(aSDCHardErrorSn,param_2,(*(word *)(param_1 + 0x1e) & 0xff) >> 3,
          (*(word *)(param_1 + 0x1e) & 7) + 0x61,*(undefined4 *)(param_1 + 0x24));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=289 start=0xf00152b8 */

/* WARNING: Removing unreachable block (ram,0xf00152c4) */

sqword _putchar(undefined4 param_1,uint param_2)

{
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
  sub_F00152F0(param_1,0,0);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=290 start=0xf00152d4 */

/* WARNING: Removing unreachable block (ram,0xf00152e0) */

undefined8 _logchar(undefined4 param_1,undefined4 param_2)

{
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
  sub_F00152F0(param_1,4,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=291 start=0xf0015440 */

undefined8 _nodev(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,0x13);
}
/* GHIDRADEC_FUNCTION index=292 start=0xf001544c */

sqword _nulldev(undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=293 start=0xf0015458 */

undefined8 _errsys(undefined4 param_1,undefined4 param_2)

{
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
  *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=294 start=0xf0015474 */

undefined8 _nullsys(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=295 start=0xf0015480 */

/* WARNING: Removing unreachable block (ram,0xf00154bc) */

undefined8 _nosys(undefined4 param_1,undefined4 param_2)

{
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
  if ((*(int *)(_active_u + 0x60) == 1) || (*(int *)(_active_u + 0x60) == 3)) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
  _exception_from_kernel(5,0x10000,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=296 start=0xf00154cc */

undefined8 _imin(int param_1,int param_2)

{
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
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=297 start=0xf00154e4 */

undefined8 _imax(int param_1,int param_2)

{
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
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=298 start=0xf00154fc */

undefined8 _min(uint param_1,uint param_2)

{
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
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=299 start=0xf0015514 */

undefined8 _max(uint param_1,uint param_2)

{
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
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  return CONCAT44(param_2,param_1);
}

