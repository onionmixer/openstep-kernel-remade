/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011315c */

/* WARNING: Removing unreachable block (ram,0x00113218) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _putc(int param_1,FILE *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  uVar2 = _spltty();
  puVar1 = _cfreelist;
  puVar4 = (undefined4 *)param_2->_w;
  if ((puVar4 == (undefined4 *)0x0) || ((int)param_2->_p < 0)) {
    if (_cfreelist == (undefined4 *)0x0) {
      _splx(uVar2);
      return -1;
    }
    __cfreecount = __cfreecount + -0x34;
    puVar4 = (undefined4 *)*_cfreelist;
    *_cfreelist = 0;
    _cfreelist = puVar4;
    _bzero(puVar1 + 1,8);
    puVar4 = puVar1 + 3;
    param_2->_r = (int)puVar4;
  }
  else if (((uint)puVar4 & 0x3f) == 0) {
    puVar4[-0x10] = _cfreelist;
    if (puVar1 == (undefined4 *)0x0) {
      _splx(uVar2);
      return -1;
    }
    _cfreelist = (undefined4 *)*puVar1;
    __cfreecount = __cfreecount + -0x34;
    *puVar1 = 0;
    puVar4 = puVar1 + 3;
  }
  if ((param_1 & 0x100U) != 0) {
    iVar3 = (int)((uint)puVar4 & 0x3f) >> 3;
    *(byte *)(((uint)puVar4 & 0xffffffc0) + 4 + iVar3) =
         *(byte *)(((uint)puVar4 & 0xffffffc0) + 4 + iVar3) |
         (byte)(1 << ((char)((uint)puVar4 & 0x3f) - (char)(iVar3 << 3) & 0x1fU));
  }
  *(undefined1 *)puVar4 = (undefined1)param_1;
  param_2->_p = param_2->_p + 1;
  param_2->_w = (int)puVar4 + 1;
  _splx(uVar2);
  return 0;
}

