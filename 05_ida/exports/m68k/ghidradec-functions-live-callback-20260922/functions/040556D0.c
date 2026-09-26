
uint * sub_40556D0(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  
  if (_zone_free_space_count < 8) {
    puVar1 = &_zone_free_space + _zone_free_space_count;
    _zone_free_space_count = _zone_free_space_count + 1;
    puVar2 = (uint *)_zget_space(&__zone_default_space,0x1c,0);
    *puVar2 = param_1;
    puVar2[1] = param_2;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
      puVar2[4] = puVar2[4] + 1;
    }
    uVar3 = puVar2[1] >> (puVar2[4] & 0x3f);
    puVar2[6] = uVar3;
    uVar3 = _zget_space(&__zone_default_space,uVar3 << 4,0);
    puVar2[5] = uVar3;
    _bzero(uVar3,puVar2[6] << 4);
    *puVar1 = puVar2;
  }
  else {
    puVar2 = (uint *)0x0;
  }
  return puVar2;
}

