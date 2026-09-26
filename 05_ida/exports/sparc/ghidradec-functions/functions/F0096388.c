
void _vik_cache_on(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = 0x4700;
  puVar1 = (uint *)segment(4);
  if ((*puVar1 & 0x800) == 0) {
    uVar3 = 0x54700;
  }
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 | uVar3;
  return;
}
