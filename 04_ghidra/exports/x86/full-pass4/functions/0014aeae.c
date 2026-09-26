/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014aeae */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0014aeae(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_EBX;
  int *piVar4;
  int unaff_EBP;
  int *unaff_EDI;
  
  do {
    iVar1 = **(int **)(unaff_EBP + -8);
    *(int *)(unaff_EBP + -0xc) = iVar1;
    if (iVar1 != 0) {
      if (*(uint *)(unaff_EBP + 0x10) < *(uint *)(iVar1 + 0x18)) {
        **(uint **)(unaff_EBP + 0x20) = *(uint *)(iVar1 + 0x18);
        LOCK();
        *unaff_EDI = 0;
        UNLOCK();
        return 0x10004004;
      }
      piVar4 = *(int **)(unaff_EBP + -0xc);
      piVar2 = (int *)*piVar4;
      if (piVar2 == piVar4) {
        **(undefined4 **)(unaff_EBP + -8) = 0;
      }
      else {
        piVar4 = (int *)piVar4[1];
        **(int **)(unaff_EBP + -8) = (int)piVar2;
        piVar2[1] = (int)piVar4;
        *piVar4 = (int)piVar2;
      }
      piVar4 = *(int **)(*(int *)(unaff_EBP + -0xc) + 0x1c);
      *(int *)(unaff_EBP + -4) = piVar4[0xd];
      piVar4[0xd] = piVar4[0xd] + 1;
LAB_0014aeb8:
      LOCK();
      *unaff_EDI = 0;
      UNLOCK();
      iVar1 = *(int *)(unaff_EBP + -0xc);
      if (*(int *)(iVar1 + 0xc) != 0) {
        _ipc_marequest_destroy();
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      if (piVar4[2] < 0) {
        iVar1 = piVar4[0xe];
        piVar4[0xe] = iVar1 + -1;
        iVar3 = piVar4[0x13];
        if ((iVar3 != 0) && (iVar1 - 1U < (uint)piVar4[0xf])) {
          _ipc_thread_rmqueue(piVar4 + 0x13);
          *(undefined4 *)(iVar3 + 0x98) = 0;
          _thread_go(iVar3);
        }
      }
      LOCK();
      *piVar4 = 0;
      UNLOCK();
      **(undefined4 **)(unaff_EBP + 0x20) = *(undefined4 *)(unaff_EBP + -0xc);
      **(undefined4 **)(unaff_EBP + 0x24) = *(undefined4 *)(unaff_EBP + -4);
      return 0;
    }
    if ((*(uint *)(unaff_EBP + 0xc) & 0x100) == 0) {
      _thread_will_wait();
    }
    else {
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        LOCK();
        *unaff_EDI = 0;
        UNLOCK();
        return 0x10004003;
      }
      _thread_will_wait_with_timeout();
    }
    iVar1 = unaff_EDI[2];
    if (iVar1 == 0) {
      unaff_EDI[2] = unaff_EBX;
    }
    else {
      iVar3 = *(int *)(iVar1 + 0x94);
      *(int *)(unaff_EBX + 0x90) = iVar1;
      *(int *)(unaff_EBX + 0x94) = iVar3;
      *(int *)(iVar1 + 0x94) = unaff_EBX;
      *(int *)(iVar3 + 0x90) = unaff_EBX;
    }
    *(undefined4 *)(unaff_EBX + 0x98) = 0x10004001;
    *(undefined4 *)(unaff_EBX + 0x9c) = *(undefined4 *)(unaff_EBP + 0x10);
    LOCK();
    *unaff_EDI = 0;
    UNLOCK();
    _thread_block_with_continuation();
    do {
      do {
      } while (*unaff_EDI != 0);
      LOCK();
      iVar1 = *unaff_EDI;
      *unaff_EDI = 1;
      UNLOCK();
    } while (iVar1 == 1);
    iVar1 = *(int *)(unaff_EBX + 0x98);
    if (iVar1 == 0) {
      iVar1 = *(int *)(unaff_EBX + 0x9c);
      *(int *)(unaff_EBP + -0xc) = iVar1;
      *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EBX + 0xa0);
      piVar4 = *(int **)(iVar1 + 0x1c);
      goto LAB_0014aeb8;
    }
    if (iVar1 == 0x10004004) {
      **(undefined4 **)(unaff_EBP + 0x20) = *(undefined4 *)(unaff_EBX + 0x9c);
LAB_0014ae53:
      LOCK();
      *unaff_EDI = 0;
      UNLOCK();
      return *(undefined4 *)(unaff_EBX + 0x98);
    }
    if (0x10004004 < iVar1) {
      if ((iVar1 == 0x10004006) || (iVar1 == 0x10004009)) goto LAB_0014ae53;
LAB_0014aea4:
                    /* WARNING: Subroutine does not return */
      _panic(s_ipc_mqueue_receive__strange_ith__001de72e);
    }
    if (iVar1 != 0x10004001) goto LAB_0014aea4;
    _ipc_thread_rmqueue(unaff_EDI + 2);
    iVar1 = *(int *)(unaff_EBX + 0x44);
    if (iVar1 == 1) {
      *(undefined4 *)(unaff_EBP + 0x14) = 0;
    }
    else if ((0 < iVar1) && (iVar1 < 4)) {
      LOCK();
      *unaff_EDI = 0;
      UNLOCK();
      return 0x10004005;
    }
  } while( true );
}

