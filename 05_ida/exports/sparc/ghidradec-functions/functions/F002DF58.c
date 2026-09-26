
/* WARNING: Removing unreachable block (ram,0xf002df98) */
/* WARNING: Removing unreachable block (ram,0xf002e02c) */
/* WARNING: Removing unreachable block (ram,0xf002df8c) */

undefined8 _arptnew(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar5;
  int *piVar6;
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
  uVar4 = 0xffffffff;
  piVar3 = (int *)0x0;
  if (dword_F010C424 != 0) {
    dword_F010C424 = 0;
    _timeout(_arptimer,0,_hz);
  }
  iVar2 = *param_2;
  .urem(iVar2,0x13);
  piVar5 = (int *)(_arptab + iVar2 * 0xb4);
  iVar2 = 0;
  piVar6 = piVar5;
  do {
    if (*(byte *)((int)piVar5 + 0xb) == 0) goto loc_F002E034;
    if ((*(byte *)((int)piVar5 + 0xb) & 4) == 0) {
      if (piVar3 == (int *)0x0) {
        bVar1 = *(byte *)((int)piVar5 + 10);
      }
      else {
        if ((int)(uint)*(byte *)((int)piVar5 + 10) <= (int)uVar4) goto loc_F002E008;
        bVar1 = *(byte *)((int)piVar5 + 10);
      }
      uVar4 = (uint)bVar1;
      piVar3 = piVar5;
    }
loc_F002E008:
    iVar2 = iVar2 + 1;
    piVar5 = piVar5 + 5;
    piVar6 = piVar6 + 5;
  } while (iVar2 < 9);
  if (piVar3 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    _arptfree(piVar3);
    piVar6 = piVar3;
loc_F002E034:
    *piVar6 = *param_2;
    *(undefined *)((int)piVar6 + 0xb) = 1;
    piVar6[4] = param_1;
  }
  return CONCAT44(param_2,piVar6);
}
