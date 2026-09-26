
/* WARNING: Removing unreachable block (ram,0xf0099174) */
/* WARNING: Removing unreachable block (ram,0xf0099208) */
/* WARNING: Removing unreachable block (ram,0xf009914c) */

undefined8 _remintr(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (param_2 != 0) {
    if (0x4f < param_1) {
      _panic(aRemintrVectorN);
    }
    piVar3 = *(int **)(_vectorlist + param_1 * 4);
    iVar2 = 0;
    if (piVar3 == (int *)0x0) {
      _panic(aRemintrSpecifi);
      iVar2 = 0;
    }
loc_F0099180:
    if (*piVar3 != 0) {
      iVar2 = iVar2 + 1;
      if (*piVar3 != param_2) goto loc_F00991F4;
      if (iVar2 < 10) {
        piVar1 = piVar3 + 5;
        do {
          iVar2 = iVar2 + 1;
          *piVar3 = piVar1[1];
          piVar3 = piVar3 + 6;
          piVar1[-4] = piVar1[2];
          piVar1[-3] = piVar1[3];
          piVar1[-2] = piVar1[4];
          piVar1[-1] = piVar1[5];
          *piVar1 = piVar1[6];
          piVar1 = piVar1 + 6;
        } while (iVar2 < 10);
        goto loc_F00991EC;
      }
      uVar4 = 0;
      goto locret_F0099214;
    }
    goto loc_F0099200;
  }
loc_F00991EC:
  uVar4 = 0;
locret_F0099214:
  return CONCAT44(param_2,uVar4);
loc_F00991F4:
  piVar3 = piVar3 + 6;
  if (9 < iVar2) goto loc_F0099200;
  goto loc_F0099180;
loc_F0099200:
  _printf(aRemintrDriverN,param_1);
  uVar4 = 0xffffffff;
  goto locret_F0099214;
}
