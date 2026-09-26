
undefined8 sub_4056F98(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 extraout_D0u;
  undefined4 uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  uVar3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
  uVar4 = ~_page_mask;
  uVar2 = uVar4 & _page_mask + uVar3;
  bVar10 = CARRY4(_page_mask,uVar3) << 4 | ((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2;
  iVar1 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = 0;
  uVar5 = CONCAT22((sword)(uVar4 >> 0x10),4);
  if (iVar1 != 0) {
    _vm_read_EXTERNAL(*(undefined4 *)(param_1 + 0x4cc),*(undefined4 *)(param_1 + 0x24),uVar2,
                      &uStack_8,auStack_c);
    uVar3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24);
    cVar6 = (uVar3 >> 4 & 1) != 0;
    _kern_serv_log_data(iVar1,uStack_8,(int)uVar3 >> 5);
    _port_deallocate_EXTERNAL(*(undefined4 *)(param_1 + 8),iVar1);
    iVar1 = *(int *)(param_1 + 8);
    cVar7 = iVar1 < 0;
    cVar8 = iVar1 == 0;
    cVar9 = '\0';
    bVar10 = 0;
    _vm_deallocate_EXTERNAL(iVar1,uStack_8,uVar2);
    bVar10 = cVar6 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar10;
    iVar1 = *(int *)(param_1 + 0x24);
    *(int *)(param_1 + 0x28) = iVar1;
    uVar5 = CONCAT22(extraout_D0u,(word)(byte)((iVar1 < 0) << 3 | (iVar1 == 0) << 2));
  }
  return CONCAT44(uVar5,(int)(sword)(word)bVar10);
}

