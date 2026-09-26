
undefined4 _iaccess(int param_1,uint param_2)

{
  int iVar1;
  word wVar2;
  undefined4 uVar3;
  uint uVar4;
  sword *psVar5;
  
  if ((char)param_2 < '\0') {
    if ((((*(char *)(*(int *)(param_1 + 0x4e) + 0xd2) != '\0') &&
         (wVar2 = *(word *)(param_1 + 0x62) & 0xf000, wVar2 != 0x2000)) && (wVar2 != 0x6000)) &&
       (wVar2 != 0x1000)) {
      return 0x1e;
    }
    if (((*(byte *)(param_1 + 0x11) & 2) != 0) &&
       (_vnode_uncache(param_1 + 0xc), (*(byte *)(param_1 + 0x11) & 2) != 0)) {
      return 0x1a;
    }
  }
  iVar1 = *(int *)(_active_u + 0x1a);
  if (*(sword *)(iVar1 + 2) == 0) {
    uVar3 = 0;
  }
  else {
    uVar4 = param_2;
    if ((*(sword *)(iVar1 + 2) != *(sword *)(param_1 + 0x66)) &&
       (uVar4 = (int)param_2 >> 3, *(sword *)(param_1 + 0x68) != *(sword *)(iVar1 + 4))) {
      for (psVar5 = (sword *)(iVar1 + 10); (psVar5 < (sword *)(iVar1 + 0x2a) && (*psVar5 != -1));
          psVar5 = psVar5 + 1) {
        if (*psVar5 == *(sword *)(param_1 + 0x68)) goto loc_40385CA;
      }
      uVar4 = (int)param_2 >> 6;
    }
loc_40385CA:
    uVar3 = 0;
    if (uVar4 != (uVar4 & *(word *)(param_1 + 0x62))) {
      uVar3 = 0xd;
    }
  }
  return uVar3;
}

