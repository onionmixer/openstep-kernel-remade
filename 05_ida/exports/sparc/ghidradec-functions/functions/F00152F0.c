
/* WARNING: Removing unreachable block (ram,0xf0015350) */
/* WARNING: Removing unreachable block (ram,0xf0015340) */
/* WARNING: Removing unreachable block (ram,0xf0015334) */
/* WARNING: Removing unreachable block (ram,0xf0015348) */
/* WARNING: Removing unreachable block (ram,0xf0015410) */
/* WARNING: Removing unreachable block (ram,0xf0015300) */

undefined8 sub_F00152F0(int param_1,uint param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
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
  if ((param_2 & 2) != 0) {
    iVar4 = param_1;
    _spltty();
    if ((param_3 != (int *)0x0) && ((param_3[0x10] & 0x14U) == 0x14)) {
      if (param_1 == 10) {
        _ttyoutput(0xd,param_3);
      }
      _ttyoutput(param_1,param_3);
      _ttstart(param_3);
    }
    _splx(iVar4);
  }
  piVar1 = _pmsgbuf;
  if (((((param_2 & 4) != 0) && (param_1 != 0)) && (param_1 != 0xd)) && (param_1 != 0x7f)) {
    if (*_pmsgbuf != 0x63061) {
      *_pmsgbuf = 0x63061;
      piVar1[2] = 0;
      piVar1[1] = 0;
      uVar2 = 0;
      do {
        uVar3 = uVar2 + 1;
        *(undefined *)((int)_pmsgbuf + uVar2 + 0xc) = 0;
        uVar2 = uVar3;
      } while (uVar3 < 0xff4);
    }
    piVar1 = _pmsgbuf;
    iVar4 = _pmsgbuf[1];
    _pmsgbuf[1] = iVar4 + 1;
    *(char *)((int)piVar1 + iVar4 + 0xc) = (char)param_1;
    if ((_pmsgbuf[1] < 0) || (0xff3 < (uint)_pmsgbuf[1])) {
      _pmsgbuf[1] = 0;
    }
  }
  if (((param_2 & 1) != 0) && (param_1 != 0)) {
    _cnputc(param_1);
  }
  if ((param_2 & 8) != 0) {
    *(char *)*param_3 = (char)param_1;
    *param_3 = *param_3 + 1;
  }
  return CONCAT44(param_2,param_1);
}
