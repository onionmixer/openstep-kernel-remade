
/* WARNING: Removing unreachable block (ram,0x0401180a) */

uint _unputc(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  uint *puVar6;
  char *pcVar7;
  uint uVar8;
  
  if (*param_1 < 1) {
    uVar8 = 0xffffffff;
  }
  else {
    iVar3 = param_1[2];
    param_1[2] = iVar3 + -1;
    pcVar7 = (char *)(iVar3 + -1);
    cVar5 = *pcVar7;
    uVar8 = (uint)cVar5;
    iVar3 = (int)((uint)pcVar7 & 0x3f) >> 3;
    if (((int)*(char *)(iVar3 + 4 + ((uint)pcVar7 & 0xffffffc0)) &
        1 << (((uint)pcVar7 & 0x3f) + iVar3 * -8 & 0x1f)) != 0) {
      uVar8 = CONCAT22(cVar5 >> 7,(sword)cVar5) | 0x100;
    }
    iVar3 = *param_1;
    *param_1 = iVar3 + -1;
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      uVar4 = param_1[2];
      param_1[1] = 0;
      param_1[2] = 0;
      *(int *)(uVar4 & 0xffffffc0) = (int)_cfreelist;
      _cfreecount = _cfreecount + 0x34;
      _cfreelist = (int *)(uVar4 & 0xffffffc0);
    }
    else {
      uVar4 = param_1[2] & 0xffffffc0;
      if (uVar4 + 0xc == param_1[2]) {
        param_1[2] = uVar4;
        puVar6 = (uint *)(param_1[1] & 0xffffffc0);
        uVar1 = *puVar6;
        while (uVar4 != uVar1) {
          puVar6 = (uint *)*puVar6;
          uVar1 = *puVar6;
        }
        param_1[2] = (int)(puVar6 + 0x10);
        piVar2 = (int *)*puVar6;
        *piVar2 = (int)_cfreelist;
        _cfreecount = _cfreecount + 0x34;
        _cfreelist = piVar2;
        *puVar6 = 0;
      }
    }
  }
  return uVar8;
}
