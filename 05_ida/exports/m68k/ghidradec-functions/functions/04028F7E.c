
undefined4 * _makenfsnode(undefined4 param_1,int *param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined2 uVar6;
  
  bVar2 = false;
  puVar3 = (undefined4 *)sub_40293F4(param_1,param_3);
  puVar4 = _rpfreelist;
  if (puVar3 == (undefined4 *)0x0) {
    if ((_rpfreelist == (undefined4 *)0x0) || (_rnew < _nrnode)) {
      if (_rnode_zone == 0) {
        _rnode_zone = _zinit(0xbe,1900000,0,0,aRnodeStructure);
      }
      puVar4 = (undefined4 *)_zalloc(_rnode_zone);
      puVar4[3] = 0;
      _vm_info_init(puVar4 + 3);
      _rnew = _rnew + 1;
    }
    else {
      _rpfreelist = (undefined4 *)*_rpfreelist;
      sub_402935A(puVar4);
      _rp_rmhash(puVar4);
      _rinactive(puVar4);
      _rreuse = _rreuse + 1;
    }
    piVar1 = puVar4 + 3;
    iVar5 = *piVar1;
    _bzero(puVar4,0xbe);
    *piVar1 = iVar5;
    _mfs_uncache(piVar1);
    *(undefined4 *)*piVar1 = 0;
    *(undefined4 *)(*piVar1 + 0x14) = puVar4[0x24];
    _bcopy(param_1,(int)puVar4 + 0x3e,0x20);
    *(undefined2 *)((int)puVar4 + 0x12) = 1;
    puVar4[10] = _nfs_vnodeops;
    if (param_2 != (int *)0x0) {
      iVar5 = *param_2;
      if ((iVar5 == 4) && (param_2[7] == -1)) {
        iVar5 = 8;
      }
      puVar4[0xd] = iVar5;
      if ((*param_2 == 4) && (param_2[7] == -1)) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(undefined2 *)((int)param_2 + 0x1e);
      }
      *(undefined2 *)(puVar4 + 0xe) = uVar6;
    }
    *(undefined4 **)((int)puVar4 + 0x3a) = puVar4;
    puVar4[0xc] = param_3;
    sub_4029110(puVar4);
    piVar1 = (int *)(*(int *)(param_3 + 0x126) + 0x16);
    *piVar1 = *piVar1 + 1;
    bVar2 = true;
    puVar3 = puVar4;
  }
  puVar3 = puVar3 + 3;
  if (param_2 != (int *)0x0) {
    if (!bVar2) {
      _nfs_cache_check(puVar3,param_2[0xd],param_2[0xe],param_2[5],0);
    }
    _nfs_attrcache(puVar3,param_2);
  }
  return puVar3;
}
