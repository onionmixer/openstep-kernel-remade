
/* WARNING: Removing unreachable block (ram,0x0018ac50) */
/* WARNING: Removing unreachable block (ram,0x0018ac9d) */

void FUN_0018ac28(void)

{
  undefined4 *puVar1;
  
  _fp_configure();
  _machine_slot = 1;
  DAT_001e8e0c = 1;
  DAT_001e8e04 = 7;
  puVar1 = (undefined4 *)cpuid_Version_info(1);
  if (((byte)((uint)*puVar1 >> 8) & 0xf) == 5) {
    DAT_001e8e08 = 5;
  }
  else if ((_cpu_config & 3) == 2) {
    DAT_001e8e08 = 4;
  }
  else {
    DAT_001e8e08 = 0x84;
  }
  return;
}

