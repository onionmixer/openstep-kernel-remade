
void _swift_cache_on(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (_use_ic != 0) {
    uVar3 = 0x200;
  }
  if (_use_dc != 0) {
    uVar3 = uVar3 | 0x100;
  }
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 & 0xfffffcff | uVar3;
  return;
}

