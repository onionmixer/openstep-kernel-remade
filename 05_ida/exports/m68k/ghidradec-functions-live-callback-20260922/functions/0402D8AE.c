
undefined4 _authkern_marshal(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  sword *psVar8;
  sword *psVar9;
  undefined4 auStack_24 [2];
  undefined auStack_1c [4];
  int iStack_18;
  
  psVar8 = (sword *)(*(int *)(_active_u + 0x1a) + 10);
  for (psVar9 = (sword *)(*(int *)(_active_u + 0x1a) + 0x2a);
      (psVar8 < psVar9 && (psVar9[-1] == -1)); psVar9 = psVar9 + -1) {
  }
  iVar6 = (int)psVar9 - (int)psVar8 >> 1;
  uVar3 = _hostnamelen + 3;
  if ((int)uVar3 < 0) {
    uVar3 = _hostnamelen + 6;
  }
  iVar1 = (uVar3 & 0xfffffffc) + 0x14 + iVar6 * 4;
  puVar2 = (undefined4 *)(**(code **)(*(int *)(param_2 + 4) + 0x18))(param_2,iVar1 + 0x10);
  if (puVar2 == (undefined4 *)0x0) {
    uVar5 = _kalloc(400);
    _xdrmem_create(auStack_1c,uVar5,400,0);
    iVar6 = _xdr_authkern(auStack_1c);
    if (iVar6 == 0) {
      _printf(aAuthkernMarsha);
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)(iStack_18 + 0x10))(auStack_1c);
      *(undefined4 *)(param_1 + 8) = uVar4;
      *(undefined4 *)(param_1 + 4) = uVar5;
      iVar6 = _xdr_opaque_auth(param_2,param_1);
      if ((iVar6 == 0) || (iVar6 = _xdr_opaque_auth(param_2,param_1 + 0xc), iVar6 == 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
    }
    _kfree(uVar5,400);
  }
  else {
    _getthetime(auStack_24);
    *puVar2 = 1;
    puVar2[1] = iVar1;
    puVar2[2] = auStack_24[0];
    puVar2[3] = _hostnamelen;
    _bcopy(_hostname,puVar2 + 4,_hostnamelen);
    uVar3 = _hostnamelen + 3;
    if ((int)uVar3 < 0) {
      uVar3 = _hostnamelen + 6;
    }
    piVar7 = (int *)((uVar3 & 0xfffffffc) + (int)(puVar2 + 4));
    *piVar7 = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 2);
    piVar7[1] = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 4);
    piVar7[2] = iVar6;
    piVar7 = piVar7 + 3;
    for (; psVar8 < psVar9; psVar8 = psVar8 + 1) {
      *piVar7 = (int)*psVar8;
      piVar7 = piVar7 + 1;
    }
    *piVar7 = 0;
    piVar7[1] = 0;
    uVar4 = 1;
  }
  return uVar4;
}

