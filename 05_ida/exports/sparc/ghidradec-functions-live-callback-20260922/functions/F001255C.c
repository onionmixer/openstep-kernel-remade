
/* WARNING: Removing unreachable block (ram,0xf00125f8) */
/* WARNING: Removing unreachable block (ram,0xf0012610) */
/* WARNING: Removing unreachable block (ram,0xf0012624) */
/* WARNING: Removing unreachable block (ram,0xf0012588) */

undefined8 _uwritec(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  uint uVar4;
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
  uVar3 = 0xffffffff;
  if (0 < (int)param_1[5]) {
    do {
      if ((int)param_1[1] < 1) {
        _panic(&aUwritec);
        puVar2 = (uint *)*param_1;
      }
      else {
        puVar2 = (uint *)*param_1;
      }
      if (puVar2[1] != 0) {
        iVar1 = param_1[3];
        if (iVar1 == 1) {
          uVar4 = (uint)*(byte *)*puVar2;
        }
        else if (iVar1 < 2) {
          if (iVar1 == 0) {
            uVar4 = *puVar2;
            _fubyte();
          }
          else {
loc_F0012620:
            uVar4 = 0;
            _panic(aUwritecBogusUi);
          }
        }
        else {
          if (iVar1 != 2) goto loc_F0012620;
          uVar4 = *puVar2;
          _fuibyte();
        }
        uVar3 = uVar4 & 0xff;
        if ((int)uVar4 < 0) {
          uVar3 = 0xffffffff;
        }
        else {
          *puVar2 = *puVar2 + 1;
          puVar2[1] = puVar2[1] - 1;
          param_1[5] = param_1[5] + -1;
          param_1[2] = param_1[2] + 1;
        }
        goto locret_F0012670;
      }
      iVar1 = param_1[1];
      *param_1 = puVar2 + 2;
      param_1[1] = iVar1 + -1;
    } while (iVar1 + -1 != 0);
    uVar3 = 0xffffffff;
  }
locret_F0012670:
  return CONCAT44(param_2,uVar3);
}

