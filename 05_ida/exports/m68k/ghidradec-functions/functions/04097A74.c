
uint * _pmap_create(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    puVar1 = (uint *)_zalloc(_pmap_zone);
    _bzero(puVar1,0x18);
    puVar1[3] = 1;
    *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfe | 2;
    *puVar1 = *puVar1 & 0x8000ffff | (_m68k_pt1_entries - 1U & 0x7fff) << 0x10;
    uVar2 = sub_4096FD0(_pt_zone);
    puVar1[2] = uVar2;
    puVar1[1] = uVar2 & 0xfffffff0 | puVar1[1] & 0xf;
  }
  else {
    puVar1 = (uint *)0x0;
  }
  return puVar1;
}
