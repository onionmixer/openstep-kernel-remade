
/* WARNING: Removing unreachable block (ram,0xf002c05c) */
/* WARNING: Removing unreachable block (ram,0xf002c118) */
/* WARNING: Removing unreachable block (ram,0xf002c050) */

undefined8
_if_attach(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  bool bVar1;
  undefined5 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  undefined4 uVar7;
  undefined4 unaff_l4;
  undefined4 uVar8;
  undefined4 unaff_l5;
  undefined4 uVar9;
  undefined4 unaff_l6;
  undefined4 uVar10;
  undefined4 unaff_l7;
  undefined4 uVar11;
  undefined4 unaff_i0;
  undefined4 *puVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar10 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x60);
  uVar8 = *(undefined4 *)((int)register0x00000038 + 100);
  uVar9 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar6 = *(uint *)((int)register0x00000038 + 0x6c);
  bVar1 = false;
  uVar11 = *(undefined4 *)((int)register0x00000038 + 0x70);
  puVar12 = _ifnet;
  if (_ifnet != (undefined4 *)0x0) {
    puVar2 = (undefined5 *)*_ifnet;
    do {
      if (puVar2 == &aNull) {
        if (puVar12[5] == uVar6) {
          bVar1 = true;
          break;
        }
        puVar12 = (undefined4 *)puVar12[0x17];
      }
      else {
        puVar12 = (undefined4 *)puVar12[0x17];
      }
      if (puVar12 == (undefined4 *)0x0) break;
      puVar2 = (undefined5 *)*puVar12;
    } while( true );
  }
  if (bVar1) {
    *puVar12 = param_6;
  }
  else {
    puVar12 = (undefined4 *)0x60;
    _kalloc();
    _bzero();
    *puVar12 = param_6;
  }
  puVar12[1] = uVar7;
  *(sword *)(puVar12 + 2) = (sword)uVar10;
  *(sword *)((int)puVar12 + 10) = (sword)uVar8;
  *(sword *)(puVar12 + 3) = (sword)uVar9;
  puVar12[4] = 0;
  puVar12[6] = 0;
  puVar12[0xc] = param_1;
  puVar12[0xd] = param_3;
  puVar12[0xe] = param_5;
  puVar12[0xf] = param_2;
  puVar12[0x10] = param_4;
  puVar12[0x16] = uVar11;
  puVar12[5] = uVar6;
  puVar12[0x11] = 0;
  puVar12[0x12] = 0;
  puVar12[0x13] = 0;
  puVar12[0x14] = 0;
  puVar12[0x15] = 0;
  puVar12[10] = _ifqmaxlen;
  if (!bVar1) {
    piVar5 = (int *)&_ifnet;
    puVar3 = _ifnet;
    while (puVar3 != (undefined4 *)0x0) {
      iVar4 = *piVar5;
      if (*(uint *)(iVar4 + 0x14) < uVar6) {
        iVar4 = *piVar5;
        goto loc_F002C100;
      }
      piVar5 = (int *)(iVar4 + 0x5c);
      puVar3 = *(undefined4 **)(iVar4 + 0x5c);
    }
    iVar4 = *piVar5;
loc_F002C100:
    puVar12[0x17] = iVar4;
    *piVar5 = (int)puVar12;
  }
  if (puVar12[5] == 0) {
    sub_F002BF04(puVar12);
  }
  return CONCAT44(param_2,puVar12);
}

