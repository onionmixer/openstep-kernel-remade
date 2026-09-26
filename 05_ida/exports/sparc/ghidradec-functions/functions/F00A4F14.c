
/* WARNING: Removing unreachable block (ram,0xf00a5110) */
/* WARNING: Removing unreachable block (ram,0xf00a50a0) */
/* WARNING: Removing unreachable block (ram,0xf00a5120) */

undefined8 _rmfree(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  uint *puVar5;
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
  if ((param_3 != 0) && (0 < (int)param_2)) {
    do {
      puVar4 = (uint *)(param_1 + 2);
      puVar6 = puVar4;
      if (param_3 < (uint)param_1[3]) {
loc_F00A4F64:
        iVar2 = (int)puVar6 - (int)puVar4;
      }
      else {
        uVar1 = *puVar4;
        puVar5 = puVar4;
        while (iVar2 = (int)puVar5 - (int)puVar4, puVar6 = puVar5, uVar1 != 0) {
          puVar6 = puVar5 + 2;
          if (param_3 < puVar5[3]) goto loc_F00A4F64;
          puVar5 = puVar6;
          uVar1 = *puVar6;
        }
      }
      if (iVar2 != 0) {
        uVar1 = puVar6[-1] + puVar6[-2];
        if (uVar1 < param_3) {
          uVar1 = *puVar6;
          goto loc_F00A5008;
        }
        if (param_3 < uVar1) break;
        uVar1 = puVar6[-2] + param_2;
        puVar6[-2] = uVar1;
        if (*puVar6 == 0) goto loc_F00A50FC;
        param_2 = param_3 + param_2;
        if (param_2 < puVar6[1]) {
          iVar2 = param_1[1];
          goto loc_F00A5100;
        }
        if (param_2 == puVar6[1]) {
          puVar6[-2] = uVar1 + *puVar6;
          if (*puVar6 != 0) {
            puVar4 = puVar6 + 1;
            do {
              *puVar6 = puVar4[1];
              puVar6 = puVar6 + 2;
              *puVar4 = puVar4[2];
              puVar4 = puVar4 + 2;
            } while (*puVar6 != 0);
          }
          iVar2 = *param_1 + 1;
          goto loc_F00A50F8;
        }
        break;
      }
      uVar1 = *puVar6;
loc_F00A5008:
      if (uVar1 == 0) {
        iVar2 = *param_1;
      }
      else {
        uVar1 = puVar6[1];
        if (uVar1 <= param_3 + param_2) {
          if (uVar1 < param_3 + param_2) break;
          puVar6[1] = uVar1 - param_2;
          *puVar6 = *puVar6 + param_2;
          goto loc_F00A50FC;
        }
        iVar2 = *param_1;
      }
      puVar4 = puVar6 + 1;
      if (iVar2 != 0) goto loc_F00A50CC;
      uVar1 = *puVar6;
      while (uVar1 != 0) {
        puVar6 = puVar6 + 2;
        uVar1 = *puVar6;
      }
      puVar4 = puVar6 + -2;
      if ((int)puVar6[-4] < (int)puVar6[-2]) {
        puVar4 = puVar6 + -4;
      }
      _printf(aSRmapOverflowL,puVar6[1],puVar4[1],puVar4[1] + *puVar4);
      *puVar4 = puVar4[2];
      puVar4[1] = puVar4[3];
      puVar4[2] = 0;
      *param_1 = *param_1 + 1;
    } while( true );
  }
  _panic(aBadRmfree);
locret_F00A5128:
  return CONCAT44(param_2,param_1);
loc_F00A50CC:
  do {
    uVar1 = *puVar4;
    *puVar4 = param_3;
    uVar3 = *puVar6;
    puVar4 = puVar4 + 2;
    *puVar6 = param_2;
    puVar6 = puVar6 + 2;
    param_2 = uVar3;
    param_3 = uVar1;
  } while (uVar3 != 0);
  iVar2 = *param_1 + -1;
  param_2 = 0;
loc_F00A50F8:
  *param_1 = iVar2;
loc_F00A50FC:
  iVar2 = param_1[1];
loc_F00A5100:
  if (iVar2 != 0) {
    param_1[1] = 0;
    _wakeup(param_1);
  }
  goto locret_F00A5128;
}
