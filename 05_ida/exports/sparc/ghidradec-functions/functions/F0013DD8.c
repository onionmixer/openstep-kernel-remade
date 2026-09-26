
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
