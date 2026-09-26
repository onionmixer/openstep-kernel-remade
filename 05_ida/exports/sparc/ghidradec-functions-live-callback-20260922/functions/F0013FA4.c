
/* WARNING: Removing unreachable block (ram,0xf00141ac) */
/* WARNING: Removing unreachable block (ram,0xf0013fd0) */
/* WARNING: Removing unreachable block (ram,0xf001418c) */
/* WARNING: Removing unreachable block (ram,0xf0013fc0) */

undefined8 sub_F0013FA4(undefined *param_1,undefined *param_2)

{
  undefined uVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  undefined4 unaff_l1;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined4 unaff_l3;
  int iVar9;
  undefined *puVar10;
  undefined *puVar11;
  int iVar12;
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
  bool bVar13;
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
  iVar9 = (int)param_2 - (int)param_1;
  do {
    iVar12 = dword_F010B480;
    iVar2 = iVar9;
    div(iVar9,dword_F010B480);
    umul(iVar12,iVar2 >> 1);
    puVar6 = param_1 + iVar12;
    if (dword_F010B488 <= iVar9) {
      puVar7 = param_1;
      (*dword_F010B47C)(param_1,puVar6);
      puVar5 = puVar6;
      if (0 < (int)puVar7) {
        puVar5 = param_1;
      }
      puVar10 = param_2 + -dword_F010B480;
      puVar7 = puVar5;
      (*dword_F010B47C)(puVar5,puVar10);
      if (0 < (int)puVar7) {
        puVar7 = param_1;
        if (puVar5 == param_1) {
          puVar7 = puVar6;
        }
        puVar3 = puVar7;
        (*dword_F010B47C)(puVar7,puVar10);
        puVar5 = puVar7;
        if ((int)puVar3 < 0) {
          puVar5 = puVar10;
        }
      }
      iVar9 = dword_F010B480;
      puVar7 = puVar6;
      if (puVar5 != puVar6) {
        do {
          uVar1 = *puVar7;
          iVar9 = iVar9 + -1;
          *puVar7 = *puVar5;
          *puVar5 = uVar1;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar9 != 0);
      }
    }
    puVar5 = param_2 + -dword_F010B480;
    puVar7 = param_1;
    while( true ) {
      for (; puVar7 < puVar6; puVar7 = puVar7 + dword_F010B480) {
        puVar10 = puVar7;
        (*dword_F010B47C)(puVar7,puVar6);
        if (0 < (int)puVar10) goto loc_F0014100;
      }
      iVar9 = (int)puVar5 - (int)puVar6;
      puVar10 = puVar5;
      while (puVar3 = puVar7, puVar6 <= puVar10 && iVar9 != 0) {
        puVar5 = puVar6;
        (*dword_F010B47C)(puVar6,puVar10);
        if (0 < (int)puVar5) {
          bVar13 = puVar7 == puVar6;
          iVar9 = dword_F010B480;
          puVar4 = puVar10;
          puVar8 = puVar6;
          puVar11 = puVar7 + dword_F010B480;
          puVar6 = puVar10;
          puVar5 = puVar10;
          if (bVar13) goto loc_F001412C;
          goto loc_F0014124;
        }
        puVar5 = puVar10 + -dword_F010B480;
loc_F0014100:
        puVar10 = puVar5;
        iVar9 = (int)puVar5 - (int)puVar6;
      }
      puVar4 = puVar6;
      puVar8 = puVar7;
      puVar11 = puVar7;
      if (puVar7 == puVar6) break;
loc_F0014124:
      puVar5 = puVar10 + -dword_F010B480;
      iVar9 = dword_F010B480;
      puVar10 = puVar4;
      puVar6 = puVar8;
loc_F001412C:
      do {
        puVar7 = puVar11;
        uVar1 = *puVar3;
        iVar9 = iVar9 + -1;
        *puVar3 = *puVar10;
        *puVar10 = uVar1;
        puVar10 = puVar10 + 1;
        puVar3 = puVar3 + 1;
        puVar11 = puVar7;
      } while (iVar9 != 0);
    }
    iVar12 = (int)puVar6 - (int)param_1;
    puVar7 = puVar6 + dword_F010B480;
    iVar9 = (int)param_2 - (int)puVar7;
    if (iVar9 < iVar12) {
      bVar13 = dword_F010B484 <= iVar9;
      iVar9 = iVar12;
      puVar5 = param_1;
      puVar10 = puVar6;
      if (bVar13) {
        sub_F0013FA4(puVar7,param_2);
      }
    }
    else {
      puVar5 = puVar7;
      puVar10 = param_2;
      if (dword_F010B484 <= iVar12) {
        sub_F0013FA4(param_1,puVar6);
      }
    }
    param_1 = puVar5;
    param_2 = puVar10;
    if (iVar9 < dword_F010B484) {
      return CONCAT44(puVar10,puVar5);
    }
  } while( true );
}

