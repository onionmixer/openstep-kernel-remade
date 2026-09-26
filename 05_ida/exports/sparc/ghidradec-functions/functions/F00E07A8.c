
/* WARNING: Removing unreachable block (ram,0xf00e0acc) */
/* WARNING: Removing unreachable block (ram,0xf00e09dc) */
/* WARNING: Removing unreachable block (ram,0xf00e086c) */
/* WARNING: Removing unreachable block (ram,0xf00e087c) */
/* WARNING: Removing unreachable block (ram,0xf00e09ec) */
/* WARNING: Removing unreachable block (ram,0xf00e0ae4) */
/* WARNING: Removing unreachable block (ram,0xf00e0814) */

undefined8 _get_disk_label(undefined *param_1,undefined *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  undefined *puVar8;
  undefined4 unaff_l6;
  undefined *puVar9;
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
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  param_2[8] = param_1[8];
  param_2[9] = param_1[9];
  param_2[10] = param_1[10];
  param_2[0xb] = param_1[0xb];
  _bcopy(param_1 + 0xc,param_2 + 0xc,0x18);
  param_2[0x24] = param_1[0x24];
  param_2[0x25] = param_1[0x25];
  param_2[0x26] = param_1[0x26];
  puVar9 = param_1 + 0x2c;
  param_2[0x27] = param_1[0x27];
  puVar8 = param_2 + 0x2c;
  param_2[0x28] = param_1[0x28];
  param_2[0x29] = param_1[0x29];
  param_2[0x2a] = param_1[0x2a];
  param_2[0x2b] = param_1[0x2b];
  _bcopy(puVar9,puVar8,0x18);
  _bcopy(param_1 + 0x44,param_2 + 0x44,0x18);
  param_2[0x5c] = param_1[0x5c];
  param_2[0x5d] = param_1[0x5d];
  param_2[0x5e] = param_1[0x5e];
  param_2[0x5f] = param_1[0x5f];
  param_2[0x60] = param_1[0x60];
  param_2[0x61] = param_1[0x61];
  param_2[0x62] = param_1[0x62];
  param_2[99] = param_1[99];
  param_2[100] = param_1[100];
  param_2[0x65] = param_1[0x65];
  param_2[0x66] = param_1[0x66];
  param_2[0x67] = param_1[0x67];
  param_2[0x68] = param_1[0x68];
  param_2[0x69] = param_1[0x69];
  param_2[0x6a] = param_1[0x6a];
  param_2[0x6b] = param_1[0x6b];
  param_2[0x6c] = param_1[0x6c];
  param_2[0x6d] = param_1[0x6d];
  param_2[0x6e] = param_1[0x6e];
  param_2[0x6f] = param_1[0x6f];
  param_2[0x70] = param_1[0x70];
  param_2[0x71] = param_1[0x71];
  param_2[0x72] = param_1[0x72];
  param_2[0x73] = param_1[0x73];
  param_2[0x74] = param_1[0x74];
  param_2[0x75] = param_1[0x75];
  param_2[0x76] = param_1[0x76];
  puVar5 = param_1 + 0x7c;
  param_2[0x77] = param_1[0x77];
  puVar4 = param_2 + 0x7c;
  param_2[0x78] = param_1[0x78];
  iVar3 = 0;
  param_2[0x79] = param_1[0x79];
  puVar2 = param_2 + 0x7f;
  param_2[0x7a] = param_1[0x7a];
  puVar1 = param_1 + 0x7f;
  param_2[0x7b] = param_1[0x7b];
  do {
    iVar3 = iVar3 + 1;
    *puVar4 = *puVar5;
    puVar2[-2] = puVar1[-2];
    puVar5 = puVar5 + 4;
    puVar2[-1] = puVar1[-1];
    puVar4 = puVar4 + 4;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (iVar3 < 2);
  _bcopy(param_1 + 0x84,param_2 + 0x84,0x18);
  _bcopy(param_1 + 0x9c,param_2 + 0x9c,0x20);
  iVar7 = 0;
  param_2[0xbc] = param_1[0xbc];
  iVar6 = 0;
  param_2[0xbd] = param_1[0xbd];
  puVar1 = puVar9;
  iVar3 = 0;
  do {
    puVar8[iVar3 + 0x94] = puVar1[0x92];
    puVar8[iVar3 + 0x95] = puVar1[0x93];
    puVar8[iVar3 + 0x96] = puVar1[0x94];
    puVar8[iVar3 + 0x97] = puVar1[0x95];
    puVar8[iVar3 + 0x98] = puVar1[0x96];
    puVar8[iVar3 + 0x99] = puVar1[0x97];
    puVar8[iVar3 + 0x9a] = puVar1[0x98];
    puVar8[iVar3 + 0x9b] = puVar1[0x99];
    puVar8[iVar3 + 0x9c] = puVar1[0x9a];
    puVar8[iVar3 + 0x9d] = puVar1[0x9b];
    puVar8[iVar3 + 0x9e] = puVar1[0x9c];
    puVar8[iVar3 + 0x9f] = puVar1[0x9d];
    puVar8[iVar3 + 0xa0] = puVar1[0x9e];
    puVar8[iVar3 + 0xa2] = puVar1[0xa0];
    iVar6 = iVar6 + 0x2e;
    puVar8[iVar3 + 0xa3] = puVar1[0xa1];
    iVar7 = iVar7 + 1;
    puVar8[iVar3 + 0xa4] = puVar1[0xa2];
    puVar8[iVar3 + 0xa5] = puVar1[0xa3];
    puVar8[iVar3 + 0xa6] = puVar1[0xa4];
    puVar8[iVar3 + 0xa7] = puVar1[0xa5];
    _bcopy(puVar1 + 0xa6,puVar8 + iVar3 + 0xa8,0x10);
    puVar8[iVar3 + 0xb8] = puVar1[0xb6];
    _bcopy(puVar1 + 0xb7,puVar8 + iVar3 + 0xb9,8);
    puVar1 = puVar9 + iVar6;
    iVar3 = iVar3 + 0x30;
  } while (iVar7 < 8);
  puVar4 = param_1 + 0x22e;
  iVar3 = 0;
  puVar1 = param_2 + 0x240;
  puVar2 = param_1 + 0x231;
  do {
    *puVar1 = *puVar4;
    iVar3 = iVar3 + 1;
    puVar1[1] = puVar2[-2];
    puVar1[2] = puVar2[-1];
    puVar4 = puVar4 + 4;
    puVar1[3] = *puVar2;
    puVar2 = puVar2 + 4;
    puVar1 = puVar1 + 4;
  } while (iVar3 < 0x686);
  param_2[0x1c58] = param_1[0x1c46];
  param_2[0x1c59] = param_1[0x1c47];
  param_2[0x240] = param_1[0x22e];
  param_2[0x241] = param_1[0x22f];
  return CONCAT44(param_2,param_1);
}
