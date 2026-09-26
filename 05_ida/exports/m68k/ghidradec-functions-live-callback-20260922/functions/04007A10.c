
void _setgroups(void)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined uVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  undefined4 auStack_44 [16];
  undefined2 *puVar8;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  iVar4 = _suser();
  if (iVar4 != 0) {
    if (*puVar2 < 0x11) {
      iVar4 = _crdup(*(undefined4 *)(_active_u + 0x1a));
      uVar5 = _copyinmsg(puVar2[1],auStack_44,*puVar2 << 2);
      *(undefined *)(dword_40B57D4 + 100) = uVar5;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        uVar1 = *puVar2;
        puVar7 = (undefined2 *)(iVar4 + 10);
        for (puVar6 = auStack_44; puVar6 < auStack_44 + uVar1; puVar6 = puVar6 + 1) {
          *puVar7 = (sword)*puVar6;
          uVar1 = *puVar2;
          puVar7 = puVar7 + 1;
        }
        uVar3 = *(undefined4 *)(_active_u + 0x1a);
        *(int *)(_active_u + 0x1a) = iVar4;
        _crfree(uVar3);
        puVar7 = (undefined2 *)(*(int *)(_active_u + 0x1a) + 10 + *puVar2 * 2);
        if (puVar7 < (undefined2 *)(*(int *)(_active_u + 0x1a) + 0x2a)) {
          do {
            puVar8 = puVar7 + 1;
            *puVar7 = 0xffff;
            puVar7 = puVar8;
          } while (puVar8 < (undefined2 *)(*(int *)(_active_u + 0x1a) + 0x2a));
        }
      }
      else {
        _crfree(iVar4);
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}

