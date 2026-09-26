
/* WARNING: Removing unreachable block (ram,0xf003d53c) */

undefined8 _rflush(int param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
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
  puVar3 = _rtable;
  iVar2 = _rtable._0_4_;
  while (iVar2 == 0) {
loc_F003D558:
    puVar3 = (undefined *)((int)puVar3 + 4);
    if (_rtable + 0xff < puVar3) {
      return CONCAT44(param_2,param_1);
    }
    iVar2 = *(int *)puVar3;
  }
  wVar1 = *(word *)(iVar2 + 0x10);
  do {
    if ((wVar1 & 0x80) == 0) {
      if ((*(uint *)(*(int *)(iVar2 + 0x30) + 0xc) & 1) == 0) {
        if ((param_1 == 0) || (*(int *)(iVar2 + 0x30) == param_1)) {
          _sync_vp(iVar2 + 0xc);
          goto loc_F003D544;
        }
        iVar2 = *(int *)(iVar2 + 8);
      }
      else {
        iVar2 = *(int *)(iVar2 + 8);
      }
    }
    else {
loc_F003D544:
      iVar2 = *(int *)(iVar2 + 8);
    }
    if (iVar2 == 0) goto loc_F003D558;
    wVar1 = *(word *)(iVar2 + 0x10);
  } while( true );
}
