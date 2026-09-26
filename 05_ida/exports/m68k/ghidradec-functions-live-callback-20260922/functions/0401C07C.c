
int _ifconf(undefined4 param_1,uint *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char acStack_24 [16];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar4 = *param_2;
  iVar1 = 0;
  uVar5 = param_2[1];
  if (0x20 < uVar4) {
    puVar6 = _ifnet;
    do {
      if (puVar6 == (undefined4 *)0x0) break;
      _bcopy(*puVar6,acStack_24,0xe);
      for (pcVar2 = acStack_24; (pcVar2 < acStack_24 + 0xe && (*pcVar2 != '\0'));
          pcVar2 = pcVar2 + 1) {
      }
      *pcVar2 = *(char *)((int)puVar6 + 9) + '0';
      pcVar2[1] = '\0';
      puVar3 = *(undefined4 **)((int)puVar6 + 0x16);
      if (puVar3 == (undefined4 *)0x0) {
        _bzero(&uStack_14,0x10);
        iVar1 = _copyoutmsg(acStack_24,uVar5,0x20);
        if (iVar1 != 0) break;
        uVar4 = uVar4 - 0x20;
        uVar5 = uVar5 + 0x20;
      }
      else {
        for (; (0x20 < uVar4 && (puVar3 != (undefined4 *)0x0)); puVar3 = (undefined4 *)puVar3[9]) {
          uStack_14 = *puVar3;
          uStack_10 = puVar3[1];
          uStack_c = puVar3[2];
          uStack_8 = puVar3[3];
          iVar1 = _copyoutmsg(acStack_24,uVar5,0x20);
          if (iVar1 != 0) break;
          uVar4 = uVar4 - 0x20;
          uVar5 = uVar5 + 0x20;
        }
      }
      puVar6 = *(undefined4 **)((int)puVar6 + 0x5a);
    } while (0x20 < uVar4);
  }
  *param_2 = *param_2 - uVar4;
  return iVar1;
}

