
void _p4m35_memerr_disable_asm(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = (uint *)segment(4);
  puVar2 = (uint *)segment(4);
  *puVar2 = *puVar1 & 0xffffefff;
  return;
}
