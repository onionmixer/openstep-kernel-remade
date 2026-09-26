/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f4ec */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _makenfsnode(void *param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  int iVar7;
  
  bVar3 = false;
  puVar4 = (undefined4 *)FUN_0012f8a8(param_1,param_3);
  puVar5 = _rpfreelist;
  if (puVar4 == (undefined4 *)0x0) {
    if ((_rpfreelist == (undefined4 *)0x0) || (_rnew < _nrnode)) {
      if (_rnode_zone == 0) {
        _rnode_zone = _zinit(200,&DAT_001e8480,0,0,s_rnode_structures_001dc530);
      }
      puVar5 = (undefined4 *)_zalloc(_rnode_zone);
      puVar5[3] = 0;
      _vm_info_init(puVar5 + 3);
      _rnew = _rnew + 1;
    }
    else {
      _rpfreelist = (undefined4 *)*_rpfreelist;
      FUN_0012f7d0(puVar5);
      _rp_rmhash(puVar5);
      _rinactive(puVar5);
      __rreuse = __rreuse + 1;
    }
    uVar2 = puVar5[3];
    _bzero(puVar5,200);
    puVar5[3] = uVar2;
    _mfs_uncache(puVar5 + 3);
    *(undefined4 *)puVar5[3] = 0;
    *(undefined4 *)(puVar5[3] + 0x14) = puVar5[0x26];
    _bcopy(param_1,puVar5 + 0x10,0x20);
    *(undefined2 *)((int)puVar5 + 0x12) = 1;
    puVar5[10] = &_nfs_vnodeops;
    if (param_2 != (int *)0x0) {
      iVar7 = *param_2;
      if ((iVar7 == 4) && (param_2[7] == -1)) {
        iVar7 = 8;
      }
      puVar5[0xd] = iVar7;
      if ((*param_2 == 4) && (param_2[7] == -1)) {
        uVar6 = 0;
      }
      else {
        uVar6 = (undefined2)param_2[7];
      }
      *(undefined2 *)(puVar5 + 0xe) = uVar6;
    }
    puVar5[0xf] = puVar5;
    puVar5[0xc] = param_3;
    FUN_0012f698(puVar5);
    piVar1 = (int *)(*(int *)(param_3 + 0x128) + 0x18);
    *piVar1 = *piVar1 + 1;
    bVar3 = true;
    puVar4 = puVar5;
  }
  puVar4 = puVar4 + 3;
  if (param_2 != (int *)0x0) {
    if (!bVar3) {
      _nfs_cache_check(puVar4,param_2[0xd],param_2[0xe],param_2[5],0);
    }
    _nfs_attrcache(puVar4,param_2);
  }
  return puVar4;
}

