/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136e40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _svc_unregister(void)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  puVar1 = (undefined4 *)FUN_00136e88();
  if (puVar1 != (undefined4 *)0x0) {
    if (local_8 == (undefined4 *)0x0) {
      DAT_001e5a1c = *puVar1;
    }
    else {
      *local_8 = *puVar1;
    }
    *puVar1 = 0;
    _kfree(puVar1,0x10);
  }
  return;
}

