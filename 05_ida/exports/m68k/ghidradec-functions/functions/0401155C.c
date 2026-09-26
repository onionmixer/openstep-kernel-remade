
/* WARNING: Removing unreachable block (ram,0x04011608) */

undefined4 _putc(uint param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar2 = _cfreelist;
  puVar4 = (undefined4 *)param_2[2];
  if ((puVar4 == (undefined4 *)0x0) || (*param_2 < 0)) {
    if (_cfreelist == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    _cfreecount = _cfreecount + -0x34;
    puVar3 = _cfreelist + 1;
    puVar4 = (undefined4 *)*_cfreelist;
    *_cfreelist = 0;
    _cfreelist = puVar4;
    _bzero(puVar3,8);
    puVar4 = puVar2 + 3;
    param_2[1] = (int)puVar4;
  }
  else if (((uint)puVar4 & 0x3f) == 0) {
    puVar4[-0x10] = _cfreelist;
    if (puVar2 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    _cfreelist = (undefined4 *)*puVar2;
    _cfreecount = _cfreecount + -0x34;
    *puVar2 = 0;
    puVar4 = puVar2 + 3;
  }
  if ((param_1 & 0x100) != 0) {
    iVar1 = (int)((uint)puVar4 & 0x3f) >> 3;
    *(byte *)(((uint)puVar4 & 0xffffffc0) + 4 + iVar1) =
         (byte)(1 << (((uint)puVar4 & 0x3f) + iVar1 * -8 & 0x3f)) |
         *(byte *)(((uint)puVar4 & 0xffffffc0) + 4 + iVar1);
  }
  *(char *)puVar4 = (char)param_1;
  *param_2 = *param_2 + 1;
  param_2[2] = (int)puVar4 + 1;
  return 0;
}
