
/* WARNING: Removing unreachable block (ram,0xf0078524) */
/* WARNING: Removing unreachable block (ram,0xf007849c) */
/* WARNING: Removing unreachable block (ram,0xf00784dc) */

undefined8 _zone_collect(int param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint *puVar5;
  uint *puVar6;
  undefined4 unaff_l1;
  undefined *puVar7;
  undefined4 unaff_l3;
  uint *puVar8;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  uint uVar10;
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
  bool bVar11;
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
  puVar7 = *(undefined **)(param_1 + 0x3c);
  iVar9 = *(int *)(param_1 + 0x1c);
  if ((puVar7 != (undefined *)0x0) &&
     (puVar8 = (uint *)(puVar7 + 8), puVar7 != __zone_default_space)) {
    puVar1 = (uint *)*(uint *)(param_1 + 0x10);
    while (puVar1 != (uint *)0x0) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar9;
      puVar5 = (uint *)*puVar8;
      bVar11 = puVar5 == (uint *)0x0;
      uVar10 = *puVar1;
      if (!bVar11) {
        uVar2 = puVar5[1];
        while (puVar6 = puVar5, bVar11 = puVar6 == (uint *)0x0, puVar5 = puVar6,
              (int)puVar6 + uVar2 < puVar1) {
          puVar5 = (uint *)*puVar6;
          puVar8 = puVar6;
          if (puVar5 == (uint *)0x0) {
            bVar11 = true;
            break;
          }
          uVar2 = puVar5[1];
        }
      }
      if (bVar11) {
        puVar1[1] = iVar9;
loc_F00783FC:
        *puVar1 = (uint)puVar5;
        if (puVar5 != (uint *)0x0) {
          puVar5[2] = (uint)puVar1;
        }
        puVar1[2] = (uint)puVar8;
        *puVar8 = (uint)puVar1;
        *(int *)(puVar7 + 0xc) = *(int *)(puVar7 + 0xc) + 1;
        uVar2 = puVar1[1] >> ((byte)*(undefined4 *)(puVar7 + 0x10) & 0x1f);
        if ((int)*(uint *)(puVar7 + 0x18) < (int)uVar2) {
          uVar2 = *(uint *)(puVar7 + 0x18);
        }
        iVar3 = *(int *)(puVar7 + 0x14) + uVar2 * 0x10;
        uVar2 = *(uint *)(iVar3 + -0x10);
        if ((uVar2 == 0) || (puVar1 < uVar2)) {
          *(uint **)(iVar3 + -0x10) = puVar1;
        }
      }
      else {
        if ((uint *)((int)puVar1 + iVar9) < puVar5) {
          puVar1[1] = iVar9;
          goto loc_F00783FC;
        }
        uVar2 = puVar5[1];
        if ((uint *)((int)puVar1 + iVar9) == puVar5) {
          puVar1[1] = uVar2 + iVar9;
          iVar3 = *(int *)((int)puVar1 + iVar9);
          *puVar1 = iVar3;
          if (iVar3 != 0) {
            *(uint **)(iVar3 + 8) = puVar1;
          }
          puVar1[2] = (uint)puVar8;
          *puVar8 = (uint)puVar1;
          sub_F0077BC0(puVar7,puVar1,uVar2,puVar5);
        }
        else if ((uint *)((int)puVar5 + uVar2) == puVar1) {
          puVar5[1] = uVar2 + iVar9;
          uVar4 = (int)puVar5 + uVar2 + iVar9;
          if (uVar4 == *puVar5) {
            sub_F0077B04(puVar7,uVar4);
            puVar5[1] = puVar5[1] + *(int *)(*puVar5 + 4);
            uVar4 = *(uint *)*puVar5;
            *puVar5 = uVar4;
            if (uVar4 != 0) {
              *(uint **)(uVar4 + 8) = puVar5;
            }
            *(int *)(puVar7 + 0xc) = *(int *)(puVar7 + 0xc) + -1;
          }
          sub_F0077CDC(puVar7,puVar5,uVar2);
        }
      }
      *(uint *)(param_1 + 0x10) = uVar10;
      puVar1 = (uint *)uVar10;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return CONCAT44(param_2,param_1);
}
