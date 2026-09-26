/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113500 */

/* WARNING: Removing unreachable block (ram,0x0011359a) */
/* WARNING: Removing unreachable block (ram,0x001136fb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _catq(int *param_1,int *param_2)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint local_10;
  undefined1 local_8;
  
  uVar4 = _spltty();
  if (*param_2 == 0) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    _splx(uVar4);
    return;
  }
LAB_00113549:
  _splx(uVar4);
  uVar4 = _spltty();
  if (*param_1 < 1) {
    local_10 = 0xffffffff;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  else {
    pbVar1 = (byte *)param_1[1];
    local_10 = (uint)*pbVar1;
    iVar6 = (int)((uint)pbVar1 & 0x3f) >> 3;
    if (((uint)(int)*(char *)(((uint)pbVar1 & 0xffffffc0) + 4 + iVar6) >>
         (((uint)pbVar1 & 0x3f) + iVar6 * -8 & 0x1f) & 1) != 0) {
      local_10 = local_10 | 0x100;
    }
    param_1[1] = (int)(pbVar1 + 1);
    iVar6 = *param_1;
    *param_1 = iVar6 + -1;
    if (iVar6 == 1 || iVar6 + -1 < 0) {
      puVar5 = (undefined4 *)(param_1[1] - 1U & 0xffffffc0);
      param_1[1] = 0;
      param_1[2] = 0;
      *puVar5 = _cfreelist;
    }
    else {
      uVar2 = param_1[1];
      if ((uVar2 & 0x3f) != 0) goto LAB_00113635;
      param_1[1] = *(int *)(uVar2 - 0x40) + 0xc;
      *(undefined4 **)(uVar2 - 0x40) = _cfreelist;
      puVar5 = (undefined4 *)(uVar2 - 0x40);
    }
    __cfreecount = __cfreecount + 0x34;
    _cfreelist = puVar5;
    if (_cwaiting != '\0') {
      _wakeup(&_cwaiting);
      _cwaiting = '\0';
    }
  }
LAB_00113635:
  _splx(uVar4);
  if ((int)local_10 < 0) {
    return;
  }
  uVar4 = _spltty();
  puVar3 = _cfreelist;
  puVar5 = (undefined4 *)param_2[2];
  if ((puVar5 == (undefined4 *)0x0) || (*param_2 < 0)) goto LAB_00113666;
  if (((uint)puVar5 & 0x3f) == 0) {
    puVar5[-0x10] = _cfreelist;
    if (puVar3 != (undefined4 *)0x0) {
      _cfreelist = (undefined4 *)*puVar3;
      __cfreecount = __cfreecount + -0x34;
      *puVar3 = 0;
      puVar5 = puVar3 + 3;
      goto LAB_001136e2;
    }
    goto LAB_00113549;
  }
  goto LAB_001136e2;
LAB_00113666:
  if (_cfreelist == (undefined4 *)0x0) goto LAB_00113549;
  __cfreecount = __cfreecount + -0x34;
  puVar5 = (undefined4 *)*_cfreelist;
  *_cfreelist = 0;
  _cfreelist = puVar5;
  _bzero(puVar3 + 1,8);
  puVar5 = puVar3 + 3;
  param_2[1] = (int)puVar5;
LAB_001136e2:
  if ((local_10 & 0x100) != 0) {
    iVar6 = (int)((uint)puVar5 & 0x3f) >> 3;
    *(byte *)(((uint)puVar5 & 0xffffffc0) + 4 + iVar6) =
         *(byte *)(((uint)puVar5 & 0xffffffc0) + 4 + iVar6) |
         (byte)(1 << ((char)((uint)puVar5 & 0x3f) - (char)(iVar6 << 3) & 0x1fU));
  }
  local_8 = (undefined1)local_10;
  *(undefined1 *)puVar5 = local_8;
  *param_2 = *param_2 + 1;
  param_2[2] = (int)puVar5 + 1;
  goto LAB_00113549;
}

