/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d3fc */

int FUN_0015d3fc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined1 local_20 [28];
  
  pcVar8 = (char *)(param_1 + *(int *)(param_1 + 8));
  pcVar7 = pcVar8;
  do {
    if ((char *)(param_1 + *(int *)(param_1 + 4)) <= pcVar7) {
      return 2;
    }
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  iVar3 = FUN_0015d57c(pcVar8,local_20,&local_38,&local_3c,&local_40);
  if (iVar3 == 0) {
    uVar4 = _pmap_create(local_3c,*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),1)
    ;
    iVar3 = _vm_map_create(uVar4);
    _memset(&local_34,0,0x14);
    local_34 = 0;
    iVar5 = FUN_0015cb1c(local_40,iVar3,local_20,local_38,local_3c,param_3,0,&local_34);
    if (iVar5 == 0) {
      if (*(int *)(iVar3 + 0x1c) < 1) {
        iVar5 = 4;
      }
      else {
        iVar2 = *(int *)(*(int *)(iVar3 + 0x10) + 8);
        iVar9 = *(int *)(*(int *)(iVar3 + 0xc) + 0xc) - iVar2;
        local_44 = iVar2;
        iVar6 = _vm_map_find(param_2,0,0,&local_44,iVar9,0);
        if (((iVar6 != 0) && (iVar6 = _vm_map_find(param_2,0,0,&local_44,iVar9,1), iVar6 != 0)) ||
           (iVar6 = _vm_map_copy(param_2,iVar3,local_44,iVar9,iVar2,0,0), iVar6 != 0)) {
          iVar5 = 5;
        }
        if (iVar2 != local_44) {
          local_30 = local_30 + (local_44 - iVar2);
        }
      }
      if (iVar5 == 0) {
        *(byte *)(param_4 + 0x10) = *(byte *)(param_4 + 0x10) | 2;
        *(int *)(param_4 + 4) = local_30;
      }
    }
    _vm_map_deallocate(iVar3);
    _vn_rele(local_40);
    return iVar5;
  }
  return iVar3;
}

