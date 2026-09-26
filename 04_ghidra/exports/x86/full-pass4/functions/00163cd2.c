/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163cd2 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00163cd2(void)

{
  int iVar1;
  uint uVar2;
  int *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  do {
    LOCK();
    unaff_EBX[8] = 0;
    UNLOCK();
    do {
      unaff_EBX = *(int **)(unaff_EBP + -0xc);
      if (*(int **)(unaff_EBP + -4) == unaff_EBX) {
        LOCK();
        *unaff_ESI = 0;
        UNLOCK();
        _splx();
        return;
      }
      *(int *)(unaff_EBP + -0xc) = *unaff_EBX;
    } while (unaff_EBX[0xf] != unaff_EDI);
    *(int **)(unaff_EBP + -0x10) = unaff_EBX + 8;
    do {
      do {
      } while (**(int **)(unaff_EBP + -0x10) != 0);
      LOCK();
      iVar1 = **(int **)(unaff_EBP + -0x10);
      **(int **)(unaff_EBP + -0x10) = 1;
      UNLOCK();
    } while (iVar1 == 1);
    *(int *)(*unaff_EBX + 4) = unaff_EBX[1];
    *(int *)unaff_EBX[1] = *unaff_EBX;
    unaff_EBX[0xf] = 0;
    if (unaff_EBX[0x51] != 0) {
      _reset_timeout();
    }
    uVar2 = unaff_EBX[0x13];
    *(uint *)(unaff_EBP + -0x10) = uVar2;
    switch(uVar2 & 0xf) {
    case 1:
    case 9:
    case 0xb:
      unaff_EBX[0x13] = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe | 4;
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
      unaff_EBX[0x13] = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
      unaff_EBX[0x11] = 0;
    }
  } while( true );
}

