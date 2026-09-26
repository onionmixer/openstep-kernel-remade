/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0f74 */

void FUN_001c0f74(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  bool bVar6;
  
  piVar2 = DAT_001e871c;
  bVar6 = false;
  cVar3 = _objc_msgSend(param_1,PTR_s_isEISAPresent_001f9784);
  piVar5 = DAT_001e8728;
  if ((cVar3 == '\0') && (_dmaLockDisable == 0)) {
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar1 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (*piVar2 != param_1) {
      LOCK();
      *DAT_001e8728 = 0;
      UNLOCK();
      uVar4 = _objc_msgSend(param_1,PTR_s_name_001f9228);
      _IOLog("%s: releaseDmaLock when not holding lock\n",uVar4);
                    /* WARNING: Subroutine does not return */
      _panic("releaseDMALock");
    }
    iVar1 = piVar2[1];
    piVar2[1] = iVar1 + -1;
    piVar5 = (int *)0x0;
    if (iVar1 == 1) {
      DAT_001e871c = (int *)piVar2[2];
      bVar6 = DAT_001e871c != (int *)0x0;
      piVar5 = piVar2;
    }
    LOCK();
    *DAT_001e8728 = 0;
    UNLOCK();
    if (bVar6) {
      _thread_wakeup(&DAT_001e8724);
    }
    if (piVar5 != (int *)0x0) {
      _IOFree(piVar5,0xc);
    }
  }
  return;
}

