
/* WARNING: Removing unreachable block (ram,0xf0033dfc) */

undefined8 _ip_optcopy(byte *param_1,int param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
  byte *pbVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined *puVar6;
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
  pbVar4 = param_1 + 0x14;
  puVar3 = (undefined *)(param_2 + 0x14);
  for (uVar2 = (*param_1 & 0xf) * 4 - 0x14; 0 < (int)uVar2; uVar2 = uVar2 - uVar5) {
    bVar1 = *pbVar4;
    if (bVar1 == 0) break;
    if (bVar1 == 1) {
      uVar5 = 1;
    }
    else {
      uVar5 = (uint)pbVar4[1];
    }
    if ((int)uVar2 < (int)uVar5) {
      uVar5 = uVar2;
    }
    if ((bVar1 & 0x80) != 0) {
      _bcopy(pbVar4,puVar3,uVar5);
      puVar3 = puVar3 + uVar5;
    }
    pbVar4 = pbVar4 + uVar5;
  }
  for (puVar6 = puVar3 + (-0x14 - param_2); ((uint)puVar6 & 3) != 0; puVar6 = puVar6 + 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return CONCAT44(param_2,puVar6);
}

