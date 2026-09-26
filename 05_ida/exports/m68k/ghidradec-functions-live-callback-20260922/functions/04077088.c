
undefined4 _od_issue_cmd(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  
  iVar1 = param_1[0x84];
  iVar5 = *(int *)(param_2 + 8);
  if (((param_1[0x88] & 0x20000000) != 0) && ((*(byte *)(param_1 + 0x97) & 0xc3) != 0)) {
    param_1[0x88] = param_1[0x88] | 0x100000;
    iVar7 = 0;
    if ((*(byte *)(param_1 + 0x97) & 0x82) != 0) {
      iVar7 = 0x40000;
    }
    param_1[0xb] = -(int)-(iVar7 == 0x40000);
    iVar2 = *(int *)(*(int *)(iVar5 + 0xae) + 0x5c);
    if (((param_1[0x88] & 0x800) == 0) || (*(char *)(param_1 + 0x97) != '\x02')) {
      uVar3 = param_1[0x86];
    }
    else {
      uVar3 = _pmap_kernel(iVar7,10,iVar2 * *(char *)((int)param_1 + 0x265),
                           iVar2 * *(char *)((int)param_1 + 0x266));
    }
    if (((param_1[0x88] & 0x800) == 0) || (uVar4 = _od_rathole, *(char *)(param_1 + 0x97) != '\x02')
       ) {
      uVar4 = param_1[0x85];
    }
    _dma_list(param_1,param_1 + 0x3e,uVar4,
              *(int *)(*(int *)(iVar5 + 0xae) + 0x5c) *
              ((int)*(char *)((int)param_1 + 0x266) +
              (int)*(char *)((int)param_1 + 0x265) + param_1[0x91]),uVar3);
    param_1[5] = param_1;
    *param_1 = param_1 + 0x3e;
    _dma_start(param_1,*param_1,iVar7);
  }
  bVar6 = (byte)(param_2 + -0x40c3e18 >> 5);
  *(byte *)((int)param_1 + 0x272) = bVar6;
  if ((param_1[0x88] & 0x40000000) == 0) {
    *(byte *)(iVar1 + 6) = bVar6 | 0x80;
  }
  else {
    uVar3 = 6;
    if ((param_1[0x88] & 0x20000000) != 0) {
      uVar3 = 10;
    }
    iVar5 = _od_drive_cmd(param_1,param_2,*(undefined2 *)(param_1 + 0x96),uVar3);
    if (iVar5 < 0) {
      return 0xffffffff;
    }
  }
  if ((param_1[0x88] & 0x20000000) != 0) {
    if ((param_1[0x88] & 0x40000000) == 0) {
      _od_block_async(param_1,param_2);
    }
    *(undefined *)(param_1 + 0x98) = 6;
    if ((*(byte *)(param_1 + 0x97) & 0x82) == 0) {
      if ((*(byte *)(param_1 + 0x97) & 8) == 0) {
        param_1[0x88] = param_1[0x88] | 0x8000000;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 4;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf6;
        *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0xfc;
        bVar6 = byte_40B1FE3 | *(byte *)((int)param_1 + 0x26f);
      }
      else {
        param_1[0x88] = param_1[0x88] | 0x8000000;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 8;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfa;
        *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0xfc;
        bVar6 = byte_40B1FDF | *(byte *)((int)param_1 + 0x26f);
      }
    }
    else {
      *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf2;
      param_1[0x88] = param_1[0x88] | 0x18000000;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0xfc;
      bVar6 = byte_40B1FDB | *(byte *)((int)param_1 + 0x26f);
    }
    *(byte *)((int)param_1 + 0x26f) = bVar6;
    *(undefined *)(iVar1 + 0xc) = *(undefined *)((int)param_1 + 0x26f);
    *(undefined *)(iVar1 + 7) = 0;
    *(undefined *)(iVar1 + 7) = *(undefined *)(param_1 + 0x97);
  }
  return 0;
}

