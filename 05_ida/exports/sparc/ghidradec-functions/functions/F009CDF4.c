
/* WARNING: Removing unreachable block (ram,0xf009ce04) */

undefined8 _is_ptes_contiguous(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
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
  undefined4 uVar5;
  uint *puVar6;
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
  param_1 = (undefined4 *)*param_1;
  uVar1 = 0x40;
  .div(0x40,_pmap_info);
  if (*(byte *)((int)param_1 + 0xf) == uVar1) {
    if (param_1[4] == _wmap0) {
      if (param_1[5] == _wmap1) {
        if (param_1[6] == 0) {
          if (param_1[7] == 0) {
            puVar6 = (uint *)*param_1;
            uVar1 = *puVar6 >> 8;
            if ((uVar1 & 0x3f) == 0) {
              *param_2 = 0;
              *param_3 = 0;
              iVar4 = 0;
              uVar2 = *puVar6;
              do {
                uVar3 = *puVar6;
                if (uVar3 >> 8 != uVar1) {
                  uVar5 = 0;
                  goto locret_F009CF1C;
                }
                if ((uVar3 >> 7 & 1) != (uVar2 >> 7 & 1)) {
                  uVar5 = 0;
                  goto locret_F009CF1C;
                }
                if ((uVar3 >> 2 & 7) != (uVar2 >> 2 & 7)) {
                  uVar5 = 0;
                  goto locret_F009CF1C;
                }
                if ((uVar3 & 0x40) != 0) {
                  *param_2 = 1;
                }
                if ((*puVar6 & 0x20) != 0) {
                  *param_3 = 1;
                }
                puVar6 = puVar6 + 1;
                iVar4 = iVar4 + 1;
                uVar1 = uVar1 + 1;
              } while (iVar4 < 0x40);
              uVar5 = 1;
            }
            else {
              uVar5 = 0;
            }
          }
          else {
            uVar5 = 0;
          }
        }
        else {
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
locret_F009CF1C:
  return CONCAT44(param_2,uVar5);
}
