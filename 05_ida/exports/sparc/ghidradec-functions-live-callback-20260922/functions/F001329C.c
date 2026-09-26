
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

