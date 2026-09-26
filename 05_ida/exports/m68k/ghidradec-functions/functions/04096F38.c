
void _m68k_protection_init(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x4096f5c;
  do {
    if (puVar1 < (undefined4 *)0x4096f79) {
                    /* WARNING: Jumptable at 0x04096f5a did not pass sanity check. */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar1)();
      return;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x4096f79);
  return;
}
