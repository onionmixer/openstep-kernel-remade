
void _dma_list(int param_1,undefined4 *param_2,uint param_3,int param_4,undefined4 param_5,
              int param_6,int param_7,uint param_8,uint param_9)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uStack_c;
  uint uStack_8;
  
  bVar1 = false;
  uVar3 = (param_4 - param_8) - param_9;
  puVar8 = param_2;
  uStack_8 = param_3;
  if ((param_3 & 0xf) != 0) {
    bVar1 = true;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x8000;
    *(uint *)(param_1 + 0xe4) = param_3;
    *(undefined4 *)(param_1 + 0xf4) = param_5;
    iVar7 = 0x10 - (param_3 & 0xf);
    *(int *)(param_1 + 0xe8) = iVar7;
    uVar5 = uVar3 - iVar7;
    *(uint *)(param_1 + 0xec) = uVar5;
    if ((int)uVar5 < 0) {
      uVar5 = uVar5 + 0xf;
    }
    *(uint *)(param_1 + 0xec) = uVar5 & 0xfffffff0;
    iVar7 = uVar3 - (uVar5 & 0xfffffff0);
    *(int *)(param_1 + 0xf0) = iVar7;
    if (param_6 == 0) {
      uVar2 = _pmap_kernel(iVar7);
      _vcopy(*(int *)(param_1 + 0xec) + param_3,param_5,*(undefined4 *)(param_1 + 0x3c),uVar2);
      _vcopy(param_3,param_5,*(int *)(param_1 + 0xe8) + param_3,param_5,
             *(undefined4 *)(param_1 + 0xec));
    }
    uStack_8 = param_3 + 0xf & 0xfffffff0;
    uVar3 = *(uint *)(param_1 + 0xec);
    param_3 = uStack_8;
  }
  while ((0 < param_4 || (bVar1))) {
    if ((param_8 == 0) && (uVar3 != 0)) {
      uStack_c = uStack_8;
    }
    else {
      uStack_c = param_3 & ~_m68k_page_mask;
    }
    iVar7 = _pmap_resident_extract(param_5,uStack_c);
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aDmaListZeroPfn);
    }
    uVar5 = _m68k_page_size - (_m68k_page_mask & uStack_c);
    if (param_8 == 0) {
      if (uVar3 == 0) {
        if (bVar1) {
          iVar6 = *(int *)(param_1 + 0xf0);
          iVar7 = *(int *)(param_1 + 0x40);
          if ((*(uint *)(param_1 + 0x2c) & 2) != 0) {
            iVar6 = iVar6 + 0x20;
          }
          uVar5 = iVar6 + 0xfU & 0xfffffff0;
          bVar1 = false;
        }
        else {
          if ((int)param_9 < (int)uVar5) {
            uVar5 = param_9;
          }
          param_9 = param_9 - uVar5;
        }
      }
      else {
        if ((int)uVar3 < (int)uVar5) {
          uVar5 = uVar3;
        }
        uVar3 = uVar3 - uVar5;
        uStack_8 = uVar5 + uStack_8;
      }
    }
    else {
      if ((int)param_8 < (int)uVar5) {
        uVar5 = param_8;
      }
      param_8 = param_8 - uVar5;
    }
    param_4 = param_4 - uVar5;
    puVar8[3] = 0;
    if ((((_dma_chip == 0x139) && (puVar8 != param_2)) && (iVar7 == puVar8[-5])) &&
       ((int)((uVar5 + iVar7) - puVar8[-6]) < 0x2000)) {
      puVar8 = puVar8 + -7;
    }
    else {
      puVar8[1] = iVar7;
    }
    puVar8[2] = uVar5 + iVar7;
    puVar4 = (undefined4 *)0x0;
    if (0 < param_4) {
      puVar4 = puVar8 + 7;
    }
    *puVar8 = puVar4;
    puVar8[4] = 0;
    puVar8 = puVar8 + 7;
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  puVar4 = puVar8 + -7;
  uVar3 = puVar8[-5];
  if ((((uVar3 & 0xf) != 0) || ((*(uint *)(param_1 + 0x2c) & 2) != 0)) &&
     (-1 < (sword)*(undefined4 *)(param_1 + 0x2c))) {
    if (param_6 == 0x40000) {
      iVar7 = (uVar3 - puVar8[-6] & 0xfffffff0) + 0x20;
      if (iVar7 < 0x81) {
        *(undefined4 *)(param_1 + 0x30) = puVar8[-6];
        *(undefined4 *)(param_1 + 0x34) = puVar8[-5] - puVar8[-6];
        puVar8 = puVar4;
      }
      else {
        *(uint *)(param_1 + 0x30) = uVar3 & 0xfffffff0;
        *(uint *)(param_1 + 0x34) = puVar8[-5] - (uVar3 & 0xfffffff0);
        iVar7 = 0x20;
        puVar8[-5] = *(undefined4 *)(param_1 + 0x30);
        *puVar4 = puVar8;
      }
      puVar8[1] = *(undefined4 *)(param_1 + 0x40);
      puVar8[2] = puVar8[1] + iVar7;
    }
    else {
      puVar8[-5] = uVar3 + 0xf & 0xfffffff0;
      *puVar4 = puVar8;
      puVar8[1] = *(undefined4 *)(param_1 + 0x40);
      puVar8[2] = puVar8[1] + 0x30;
    }
    *puVar8 = 0;
    puVar8[4] = 0;
    puVar8[3] = 0;
    puVar4 = puVar8;
  }
  if (((int)puVar4 - (int)param_2) * -0x49249249 >> 2 < param_7) {
    param_2[3] = 4;
    if ((_dma_chip == 0x139) && (_slot_id + 0x2000090 == *(int *)(param_1 + 0x1c))) {
      param_2[3] = param_2[3] | 1;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aDmaListDmaList);
}

