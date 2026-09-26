
int _getport_loop(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  iVar4 = 0;
  do {
    iVar2 = _pmap_kgetport(param_1,param_2,param_3,param_4);
    if (iVar2 < 1) {
      if (iVar4 != 0) {
        puVar5 = aPortmapperOk;
loc_402E7F2:
        _printf(puVar5);
      }
      return iVar2;
    }
    if ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
loc_402E7C8:
      puVar5 = aPortmapperNotR;
      goto loc_402E7F2;
    }
    iVar3 = *_active_u;
    uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18);
    if ((uVar1 != 0) &&
       (((*(byte *)(iVar3 + 0x2b) & 0x10) != 0 ||
        ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) != 0)))) {
      iVar3 = _issig(0);
      if (iVar3 != 0) goto loc_402E7C8;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 1) {
      _printf(aPortmapperNotR_0);
    }
  } while( true );
}

