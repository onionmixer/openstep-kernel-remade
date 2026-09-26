/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162f20 */

void _assert_wait(uint param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  
  puVar5 = _active_threads;
  if (_active_threads[0xf] == 0) {
    uVar6 = _splsched();
    if (param_1 == 0) {
      piVar2 = puVar5 + 8;
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar7 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      if (param_2 == 0) {
        *(byte *)(puVar5 + 0x13) = *(byte *)(puVar5 + 0x13) | 9;
      }
      else {
        *(byte *)(puVar5 + 0x13) = *(byte *)(puVar5 + 0x13) | 1;
      }
      LOCK();
      puVar5[8] = 0;
      UNLOCK();
    }
    else {
      uVar4 = param_1;
      if ((int)param_1 < 0) {
        uVar4 = ~param_1;
      }
      iVar7 = (int)uVar4 % 0x3b;
      piVar2 = &_wait_lock + iVar7;
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar3 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      piVar1 = puVar5 + 8;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      *puVar5 = &_wait_queue + iVar7 * 2;
      puVar5[1] = (&DAT_001f6a14)[iVar7 * 2];
      *(undefined4 **)puVar5[1] = puVar5;
      (&DAT_001f6a14)[iVar7 * 2] = puVar5;
      puVar5[0xf] = param_1;
      if (param_2 == 0) {
        *(byte *)(puVar5 + 0x13) = *(byte *)(puVar5 + 0x13) | 9;
      }
      else {
        *(byte *)(puVar5 + 0x13) = *(byte *)(puVar5 + 0x13) | 1;
      }
      LOCK();
      puVar5[8] = 0;
      UNLOCK();
      LOCK();
      *piVar2 = 0;
      UNLOCK();
    }
    _splx(uVar6);
    return;
  }
  _printf(s_assert_wait__already_asserted_ev_001df520,_active_threads[0xf]);
                    /* WARNING: Subroutine does not return */
  _panic(s_assert_wait_001df54a);
}

