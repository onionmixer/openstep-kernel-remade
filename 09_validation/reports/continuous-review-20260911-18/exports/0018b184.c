
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _locate_idt(undefined4 param_1)

{
  __idt_base = (undefined2)param_1;
  uRam001e17bc = (undefined2)((uint)param_1 >> 0x10);
  __idt_limit = 0x7ff;
  InterruptDescriptorTableRegister(CONCAT22(__idt_base,0x7ff));
  return;
}

