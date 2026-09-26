/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194044 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00194044(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  _defaultBus = _objc_msgSend();
  iVar1 = _eisa_id(0,unaff_EBP + -4);
  if (iVar1 == 0) {
    _printf(s_ISA_bus_001e2a7a);
    _is_ISA = 1;
  }
  else {
    _printf(s_CPU__EISA_id__08x_001e2a4b);
    iVar1 = 1;
    do {
      iVar2 = _eisa_id();
      if (iVar2 != 0) {
        _printf(s_slot__x__EISA_id__08x_001e2a5e);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    _led_msg();
    _is_ISA = 0;
  }
  _objc_msgSend();
  _printf(s_DriverKit_version__d_001e2a83);
  *(undefined4 *)(unaff_EBP + -8) = 1;
  while( true ) {
    iVar1 = _findBootConfigString();
    if (iVar1 == 0) break;
    FUN_00194140();
    *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 1;
  }
  _IOFree();
  return;
}

