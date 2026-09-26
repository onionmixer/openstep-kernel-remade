
void _getgroups(void)

{
  uint *puVar1;
  undefined uVar2;
  int *piVar3;
  uint uVar4;
  sword *psVar5;
  int iVar6;
  int aiStack_44 [16];
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  for (uVar4 = *(int *)((int)_active_u + 0x1a) + 0x2a;
      (*(int *)((int)_active_u + 0x1a) + 10U < uVar4 && (*(sword *)(uVar4 - 2) == -1));
      uVar4 = uVar4 - 2) {
  }
  uVar4 = (int)((uVar4 - 10) - *(int *)((int)_active_u + 0x1a)) >> 1;
  if (*puVar1 < uVar4) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    *puVar1 = uVar4;
    if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
      psVar5 = (sword *)(*(int *)((int)_active_u + 0x1a) + 10);
      for (piVar3 = aiStack_44; piVar3 < aiStack_44 + uVar4; piVar3 = piVar3 + 1) {
        *piVar3 = (int)*psVar5;
        uVar4 = *puVar1;
        psVar5 = psVar5 + 1;
      }
      iVar6 = *puVar1 << 2;
      uVar4 = puVar1[1];
      piVar3 = aiStack_44;
    }
    else {
      iVar6 = uVar4 * 2;
      uVar4 = puVar1[1];
      piVar3 = (int *)(*(int *)((int)_active_u + 0x1a) + 10);
    }
    uVar2 = _copyoutmsg(piVar3,uVar4,iVar6);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      *(uint *)(dword_40B57D4 + 0x5c) = *puVar1;
    }
  }
  return;
}
