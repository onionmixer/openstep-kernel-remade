
int _zinit(int param_1,int param_2,int param_3,byte param_4,undefined4 param_5)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  if (_zone_zone == 0) {
    iVar3 = _zget_space(&__zone_default_space,0x3a,0);
  }
  else {
    iVar3 = _zalloc(_zone_zone);
  }
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aZinit);
  }
  if (param_3 == 0) {
    param_3 = _page_size;
  }
  if (param_1 == 0) {
    param_1 = 4;
  }
  uVar4 = ~_page_mask & _page_mask + param_2;
  uVar1 = ~_page_mask & param_3 + _page_mask;
  if (uVar4 < uVar1) {
    uVar4 = uVar1;
  }
  *(undefined4 *)(iVar3 + 0xc) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0x10) = 0;
  *(uint *)(iVar3 + 0x14) = uVar4;
  *(uint *)(iVar3 + 0x18) = param_1 + 0xfU & 0xfffffff0;
  *(uint *)(iVar3 + 0x1c) = uVar1;
  *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & 0x7fffffff | (uint)param_4 << 0x1f;
  *(undefined4 *)(iVar3 + 0x24) = param_5;
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 0x20) = 0;
  bVar2 = *(byte *)(iVar3 + 0x28) & 0x9f | 0x10;
  *(byte *)(iVar3 + 0x28) = bVar2;
  if ((char)bVar2 < '\0') {
    _lock_init(iVar3 + 0x2a,1);
  }
  sub_405577E(iVar3);
  *(undefined4 *)(iVar3 + 0x36) = 0;
  *_last_zone = iVar3;
  _last_zone = (int *)(iVar3 + 0x36);
  _num_zones = _num_zones + 1;
  return iVar3;
}

