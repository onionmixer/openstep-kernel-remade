/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e234 */

void _autoconf(void)

{
  undefined **ppuVar1;
  undefined4 *puVar2;
  
  FUN_0017e2e0();
  _IOInitGeneralFuncs();
  _volCheckInit();
  puVar2 = &_pseudo_inits;
  if (PTR__pty_init_001e4f84 != (undefined *)0x0) {
    ppuVar1 = &PTR__pty_init_001e4f84;
    do {
      (*(code *)*ppuVar1)(*puVar2);
      ppuVar1 = ppuVar1 + 2;
      puVar2 = puVar2 + 2;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  DAT_001e7314 = _objc_msgSend(PTR_s_NXConditionLock_001f9d64,PTR_s_alloc_001f9210);
  _objc_msgSend(DAT_001e7314,PTR_s_initWith__001f9214,0);
  _kernel_thread(_IOTask_kern,FUN_0017e4e8,0);
  _objc_msgSend(DAT_001e7314,PTR_s_lockWhen__001f9218,1);
  _objc_msgSend(DAT_001e7314,PTR_s_free_001f921c);
  return;
}

