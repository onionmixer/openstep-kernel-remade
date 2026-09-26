/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001638de */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001638de(void)

{
  int iVar1;
  uint uVar2;
  int *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_EDI;
  
  do {
    LOCK();
    unaff_EBX[8] = 0;
    UNLOCK();
    do {
      unaff_EBX = *(int **)(unaff_EBP + -0x10);
      if (*(int **)(unaff_EBP + -8) == unaff_EBX) {
        LOCK();
        *unaff_EDI = 0;
        UNLOCK();
        _splx();
        __c_thread_invoke_hits = __c_thread_invoke_hits + 1;
        _spl0();
        _call_continuation();
        return 1;
      }
      *(int *)(unaff_EBP + -0x10) = *unaff_EBX;
    } while (unaff_EBX[0xf] != *(int *)(unaff_EBP + -4));
    *(int **)(unaff_EBP + -0x14) = unaff_EBX + 8;
    do {
      do {
      } while (**(int **)(unaff_EBP + -0x14) != 0);
      LOCK();
      iVar1 = **(int **)(unaff_EBP + -0x14);
      **(int **)(unaff_EBP + -0x14) = 1;
      UNLOCK();
    } while (iVar1 == 1);
    *(int *)(*unaff_EBX + 4) = unaff_EBX[1];
    *(int *)unaff_EBX[1] = *unaff_EBX;
    unaff_EBX[0xf] = 0;
    if (unaff_EBX[0x51] != 0) {
      _reset_timeout();
    }
    uVar2 = unaff_EBX[0x13];
    *(uint *)(unaff_EBP + -0x14) = uVar2;
    switch(uVar2 & 0xf) {
    case 1:
    case 9:
    case 0xb:
      unaff_EBX[0x13] = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe | 4;
      unaff_EBX[0x11] = 0;
      _thread_setrun(unaff_EBX);
      break;
    default:
                    /* WARNING: Subroutine does not return */
      _panic(s_thread_wakeup_001df556);
    case 3:
    case 5:
    case 7:
    case 0xd:
    case 0xf:
      unaff_EBX[0x13] = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
      unaff_EBX[0x11] = 0;
    }
  } while( true );
}

