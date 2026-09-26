
int sub_404C460(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iStack_42;
  undefined4 uStack_3e;
  undefined4 uStack_3a;
  undefined4 uStack_36;
  undefined4 uStack_32;
  int iStack_2e;
  undefined auStack_20 [28];
  
  pcVar3 = (char *)(*(int *)(param_1 + 8) + param_1);
  pcVar9 = pcVar3;
  do {
    if ((char *)(*(int *)(param_1 + 4) + param_1) <= pcVar9) {
      return 2;
    }
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  iVar4 = sub_404C5D6(pcVar3,auStack_20,&uStack_36,&uStack_3a,&uStack_3e);
  if (iVar4 == 0) {
    uVar5 = _pmap_create(uStack_3a,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),1
                        );
    iVar4 = _vm_map_create(uVar5);
    _bzero(&uStack_32,0x12);
    uStack_32 = 0;
    iVar6 = sub_404BC42(uStack_3e,iVar4,auStack_20,uStack_36,uStack_3a,param_3,0,&uStack_32);
    if (iVar6 == 0) {
      if (*(int *)(iVar4 + 0x18) < 1) {
        iVar6 = 4;
      }
      else {
        iVar1 = *(int *)(*(int *)(iVar4 + 0xc) + 8);
        iVar8 = *(int *)(*(int *)(iVar4 + 8) + 0xc) - iVar1;
        iStack_42 = iVar1;
        iVar7 = _vm_map_find(param_2,0,0,&iStack_42,iVar8,0);
        if (((iVar7 != 0) && (iVar7 = _vm_map_find(param_2,0,0,&iStack_42,iVar8,1), iVar7 != 0)) ||
           (iVar8 = _vm_map_copy(param_2,iVar4,iStack_42,iVar8,iVar1,0,0), iVar8 != 0)) {
          iVar6 = 5;
        }
        if (iVar1 != iStack_42) {
          iStack_2e = (iStack_42 - iVar1) + iStack_2e;
        }
      }
      if (iVar6 == 0) {
        *(byte *)(param_4 + 0x10) = *(byte *)(param_4 + 0x10) | 0x40;
        *(int *)(param_4 + 4) = iStack_2e;
      }
    }
    _vm_map_deallocate(iVar4);
    _vn_rele(uStack_3e);
    return iVar6;
  }
  return iVar4;
}
