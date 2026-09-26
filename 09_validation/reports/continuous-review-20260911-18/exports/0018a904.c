
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _locate_gdt(undefined4 param_1)

{
  __gdt_base = (undefined2)param_1;
  uRam001e17b4 = (undefined2)((uint)param_1 >> 0x10);
  __gdt_limit = 0xff;
  GlobalDescriptorTableRegister(CONCAT22(__gdt_base,0xff));
  return;
}

