
undefined4 _ipc_kmsg_get(undefined4 param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = _ipc_kmsg_cache;
  if (((param_2 < 0x18) || ((param_2 & 3) != 0)) || (0 < param_3)) {
    return 0x10000008;
  }
  if (param_2 < 0xed) {
    if (_ipc_kmsg_cache != 0) {
      _ipc_kmsg_cache = 0;
      goto loc_403D238;
    }
    iVar1 = _kalloc(0x100);
    if (iVar1 == 0) {
      return 0x1000000d;
    }
    *(undefined4 *)(iVar1 + 8) = 0x100;
  }
  else {
    iVar1 = _kalloc(param_2 + 0x14);
    if (iVar1 == 0) {
      return 0x1000000d;
    }
    *(uint *)(iVar1 + 8) = param_2 + 0x14;
  }
  *(undefined4 *)(iVar1 + 0xc) = 0;
loc_403D238:
  *(undefined4 *)(iVar1 + 0x10) = 0;
  iVar2 = _copyinmsg(param_1,iVar1 + 0x14,param_3 + param_2);
  if (iVar2 == 0) {
    *(int *)(iVar1 + 0x10) = param_3;
    *(uint *)(iVar1 + 0x18) = param_2;
    *param_4 = iVar1;
    uVar3 = 0;
  }
  else {
    if (*(int *)(iVar1 + 8) < 1) {
      _ipc_kmsg_free(iVar1);
    }
    else {
      _kfree(iVar1,*(int *)(iVar1 + 8));
    }
    uVar3 = 0x10000002;
  }
  return uVar3;
}

