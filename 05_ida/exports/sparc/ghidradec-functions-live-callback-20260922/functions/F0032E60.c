
/* WARNING: Removing unreachable block (ram,0xf0032ed4) */
/* WARNING: Removing unreachable block (ram,0xf0032e78) */

undefined8 _ip_srcroute(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  iVar1 = 0;
  if ((_ip_nhops == 0) || (_m_get(0,10), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar2 = _ip_nhops * 4;
    *(sword *)(iVar1 + 8) = (sword)iVar2 + 4;
    *(undefined4 *)(iVar1 + *(int *)(iVar1 + 4)) = *(undefined4 *)(&DAT_f012f444 + iVar2);
    DAT_f012f444 = 1;
    _bcopy(&DAT_f012f444,iVar1 + *(int *)(iVar1 + 4) + 4,4);
    puVar3 = (undefined4 *)(iVar1 + *(int *)(iVar1 + 4) + 8);
    for (puVar4 = (undefined4 *)((int)&DAT_f012f440 + iVar2); DAT_f012f447 < puVar4;
        puVar4 = puVar4 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
    }
  }
  return CONCAT44(param_2,iVar1);
}

