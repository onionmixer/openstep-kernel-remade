/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001133fc */

/* WARNING: Removing unreachable block (ram,0x00113445) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _unputc(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint local_c;
  
  uVar4 = _spltty();
  if (*param_1 < 1) {
    local_c = 0xffffffff;
  }
  else {
    iVar1 = param_1[2];
    param_1[2] = iVar1 + -1;
    local_c = (uint)*(char *)(iVar1 + -1);
    uVar6 = iVar1 - 1U & 0x3f;
    iVar5 = (int)uVar6 >> 3;
    if (((uint)(int)*(char *)((iVar1 - 1U & 0xffffffc0) + 4 + iVar5) >> (uVar6 + iVar5 * -8 & 0x1f)
        & 1) != 0) {
      local_c = local_c | 0x100;
    }
    iVar1 = *param_1;
    *param_1 = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      uVar6 = param_1[2];
      param_1[1] = 0;
      param_1[2] = 0;
      *(int *)(uVar6 & 0xffffffc0) = (int)_cfreelist;
      __cfreecount = __cfreecount + 0x34;
      _cfreelist = (int *)(uVar6 & 0xffffffc0);
    }
    else {
      uVar6 = param_1[2] & 0xffffffc0;
      if (param_1[2] == uVar6 + 0xc) {
        param_1[2] = uVar6;
        puVar7 = (uint *)(param_1[1] & 0xffffffc0);
        uVar2 = *puVar7;
        while (uVar2 != uVar6) {
          puVar7 = (uint *)*puVar7;
          uVar2 = *puVar7;
        }
        param_1[2] = (int)(puVar7 + 0x10);
        piVar3 = (int *)*puVar7;
        *piVar3 = (int)_cfreelist;
        __cfreecount = __cfreecount + 0x34;
        _cfreelist = piVar3;
        *puVar7 = 0;
      }
    }
  }
  _splx(uVar4);
  return local_c;
}

