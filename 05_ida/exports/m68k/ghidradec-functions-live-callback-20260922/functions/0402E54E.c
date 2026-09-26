
int sub_402E54E(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  word wVar5;
  undefined2 *puVar6;
  
  iVar2 = _m_get(1,8);
  if (iVar2 == 0) {
    _printf(aBindresvportCo);
    iVar3 = 0x37;
  }
  else {
    puVar6 = (undefined2 *)(*(int *)(iVar2 + 4) + iVar2);
    *puVar6 = 2;
    *(undefined4 *)(puVar6 + 2) = 0;
    *(undefined2 *)(iVar2 + 8) = 0x10;
    uVar4 = _crdup(*(undefined4 *)(_active_u + 0x1a));
    uVar1 = *(undefined4 *)(_active_u + 0x1a);
    *(undefined4 *)(_active_u + 0x1a) = uVar4;
    *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2) = 0;
    iVar3 = 0x30;
    wVar5 = 0x3ff;
    do {
      if (wVar5 < 0x200) break;
      puVar6[1] = wVar5;
      iVar3 = _sobind(param_1,iVar2);
      wVar5 = wVar5 - 1;
    } while (iVar3 == 0x30);
    _m_freem(iVar2);
    *(undefined4 *)(_active_u + 0x1a) = uVar1;
    _crfree(uVar4);
  }
  return iVar3;
}

