/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155e46 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00155e46(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  
LAB_00155e49:
  do {
    while( true ) {
      *unaff_EBX = *(uint *)(unaff_EBP + -0x18);
      unaff_EBX = unaff_EBX + 1;
      unaff_ESI = unaff_ESI + 1;
      if (*(uint *)(unaff_EBP + -0xc) <= unaff_ESI) {
        uVar2 = _vm_move(_ipc_kernel_map,*(undefined4 *)(unaff_EBP + -4),_ipc_soft_map,
                         *(undefined4 *)(unaff_EBP + -0x10),1);
        **(undefined4 **)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -8);
        return uVar2;
      }
      uVar1 = *unaff_EBX & 0x1f0000;
      if (uVar1 != 0x30000) break;
LAB_00155e24:
      *(undefined4 *)(unaff_EBP + -0x18) = 7;
    }
    if (uVar1 < 0x30001) {
      if (uVar1 != 0x10000) {
        if (uVar1 != 0x20000) goto LAB_00155e3c;
        goto LAB_00155e24;
      }
    }
    else {
      if (uVar1 == 0x80000) {
        *(undefined4 *)(unaff_EBP + -0x18) = 9;
        goto LAB_00155e49;
      }
      if (uVar1 < 0x80001) {
        if (uVar1 != 0x40000) {
LAB_00155e3c:
                    /* WARNING: Subroutine does not return */
          _panic(s_convert_port_type__strange_port_t_001deafd);
        }
      }
      else if (uVar1 != 0x100000) goto LAB_00155e3c;
    }
    *(undefined4 *)(unaff_EBP + -0x18) = 1;
  } while( true );
}

