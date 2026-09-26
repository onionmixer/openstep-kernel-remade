
/* WARNING: Removing unreachable block (ram,0xf001b15c) */
/* WARNING: Removing unreachable block (ram,0xf001b104) */
/* WARNING: Removing unreachable block (ram,0xf001b1a4) */
/* WARNING: Removing unreachable block (ram,0xf001b0ec) */

undefined8 _ttynty(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  iVar1 = param_1;
  _spltty();
  if (param_1 == 0) {
    _panic(aTtynty0);
  }
  bVar5 = dword_F012F200 == (int *)0x0;
  piVar3 = (int *)&dword_F012F200;
  piVar4 = dword_F012F200;
  if (!bVar5) {
    iVar2 = *dword_F012F200;
    while (bVar5 = piVar4 == (int *)0x0, iVar2 != param_1) {
      piVar3 = piVar4 + 1;
      piVar4 = (int *)piVar4[1];
      if (piVar4 == (int *)0x0) {
        bVar5 = true;
        break;
      }
      iVar2 = *piVar4;
    }
  }
  if (bVar5) {
    piVar4 = (int *)0x18;
    _kalloc();
    *piVar4 = param_1;
    piVar4[4] = 0x1c251a1c;
    *(undefined *)(piVar4 + 5) = 0x5c;
    *(undefined *)((int)piVar4 + 0x15) = 1;
    *(undefined *)((int)piVar4 + 0x16) = 0;
    piVar4[2] = 0;
    piVar4[3] = 0;
  }
  else {
    *piVar3 = piVar4[1];
  }
  piVar4[1] = (int)dword_F012F200;
  dword_F012F200 = piVar4;
  _splx(iVar1);
  return CONCAT44(param_2,piVar4);
}
