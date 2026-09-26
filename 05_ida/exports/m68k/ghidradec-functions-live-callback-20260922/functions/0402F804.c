
undefined4 __svcauth_unix(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uStack_1c;
  int iStack_18;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  puVar1[1] = puVar1 + 6;
  puVar1[5] = puVar1 + 0x46;
  uVar2 = *(uint *)(param_2 + 0x20);
  _xdrmem_create(&uStack_1c,*(undefined4 *)(param_2 + 0x1c),uVar2,1);
  puVar3 = (undefined4 *)(**(code **)(iStack_18 + 0x18))(&uStack_1c,uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    iVar6 = _xdr_authunix_parms(&uStack_1c,puVar1);
    if (iVar6 == 0) {
      uStack_1c = 2;
      _xdr_authunix_parms(&uStack_1c,puVar1);
      uVar7 = 1;
      goto loc_402F926;
    }
loc_402F912:
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x1e) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x26) = 0;
    uVar7 = 0;
  }
  else {
    *puVar1 = *puVar3;
    iVar6 = puVar3[1];
    if (iVar6 < 0x100) {
      _bcopy(puVar3 + 2,puVar1[1],iVar6);
      *(undefined *)(iVar6 + puVar1[1]) = 0;
      uVar4 = iVar6 + 3;
      if ((int)uVar4 < 0) {
        uVar4 = iVar6 + 6;
      }
      puVar3 = (undefined4 *)((uVar4 & 0xfffffffc) + (int)(puVar3 + 2));
      puVar1[2] = *puVar3;
      puVar1[3] = puVar3[1];
      iVar6 = puVar3[2];
      if (iVar6 < 0x11) {
        puVar1[4] = iVar6;
        iVar5 = 0;
        puVar3 = puVar3 + 3;
        if (0 < iVar6) {
          do {
            *(undefined4 *)(puVar1[5] + iVar5 * 4) = *puVar3;
            iVar5 = iVar5 + 1;
            puVar3 = puVar3 + 1;
          } while (iVar5 < iVar6);
        }
        if (uVar2 < (uVar4 & 0xfffffffc) + 0x14 + iVar6 * 4) {
          _printf(aBadAuthLenGidD,iVar6,uVar2,uVar2);
          uVar7 = 1;
          goto loc_402F926;
        }
        goto loc_402F912;
      }
    }
    uVar7 = 1;
  }
loc_402F926:
  (**(code **)(iStack_18 + 0x1c))(&uStack_1c);
  return uVar7;
}

