/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00169124 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _calloutInitialize(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_001dfcbc == 0) {
    DAT_001e7244 = 0;
    DAT_001e7254 = &DAT_001e7250;
    DAT_001e7250 = &DAT_001e7250;
    _DAT_001e725c = &DAT_001e7258;
    DAT_001e7258 = &DAT_001e7258;
    DAT_001e724c = &DAT_001e7248;
    DAT_001e7248 = &DAT_001e7248;
    puVar2 = &DAT_001e6a48;
    puVar1 = &DAT_001e6a44;
    do {
      puVar3 = puVar1;
      *puVar3 = &DAT_001e7248;
      *puVar2 = DAT_001e724c;
      *(undefined4 **)*puVar2 = puVar3;
      puVar2 = puVar2 + 8;
      puVar1 = puVar3 + 8;
      DAT_001e724c = puVar3;
    } while (puVar3 + 8 < &DAT_001e7244);
    _kernel_thread(_kernel_task,FUN_00169ea0,0);
    _set_timer_expire_func(0,FUN_00169f44);
    DAT_001dfcbc = 1;
  }
  return;
}

