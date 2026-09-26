/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173898 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _vm_fault_wire_fast(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  
  _DAT_001f6514 = _DAT_001f6514 + 1;
  if ((*(byte *)(param_3 + 0x18) & 5) == 0) {
    iVar4 = *(int *)(param_3 + 0x10);
    iVar8 = *(int *)(param_3 + 8);
    iVar5 = *(int *)(param_3 + 0x14);
    uVar6 = *(uint *)(param_3 + 0x1c);
    piVar1 = (int *)(iVar4 + 0x10);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    *(short *)(iVar4 + 0x18) = *(short *)(iVar4 + 0x18) + 1;
    *(short *)(iVar4 + 0x44) = *(short *)(iVar4 + 0x44) + 1;
    iVar8 = _vm_page_lookup(iVar4,(param_2 - iVar8) + iVar5);
    if (((iVar8 == 0) || ((*(byte *)(iVar8 + 0x20) & 0x21) != 0)) ||
       ((*(uint *)(iVar8 + 0x28) & uVar6) != 0)) {
      *(short *)(iVar4 + 0x44) = *(short *)(iVar4 + 0x44) + -1;
      LOCK();
      *(undefined4 *)(iVar4 + 0x10) = 0;
      UNLOCK();
      _vm_object_deallocate(iVar4);
      uVar7 = 5;
    }
    else {
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_wire(iVar8);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      bVar3 = *(byte *)(iVar8 + 0x20);
      *(byte *)(iVar8 + 0x20) = bVar3 & 0xdf | 1;
      if (*(int *)(iVar4 + 0x1c) != 0) {
        if ((uVar6 & 2) != 0) {
          *(byte *)(iVar8 + 0x20) = bVar3 & 0xde;
          if ((bVar3 & 2) != 0) {
            *(byte *)(iVar8 + 0x20) = bVar3 & 0xdc;
            _thread_wakeup_prim(iVar8,0,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_unwire(iVar8);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          *(short *)(iVar4 + 0x44) = *(short *)(iVar4 + 0x44) + -1;
          LOCK();
          *(undefined4 *)(iVar4 + 0x10) = 0;
          UNLOCK();
          _vm_object_deallocate(iVar4);
          return 5;
        }
        *(byte *)(iVar8 + 0x21) = *(byte *)(iVar8 + 0x21) | 4;
      }
      if ((uVar6 & 2) != 0) {
        *(byte *)(iVar8 + 0x21) = *(byte *)(iVar8 + 0x21) & 0xfb;
      }
      piVar1 = (int *)(iVar4 + 0x10);
      LOCK();
      *(undefined4 *)(iVar4 + 0x10) = 0;
      UNLOCK();
      _pmap_enter(*(undefined4 *)(param_1 + 0x24),param_2,*(undefined4 *)(iVar8 + 0x24),uVar6,1);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      bVar3 = *(byte *)(iVar8 + 0x20);
      *(byte *)(iVar8 + 0x20) = bVar3 & 0xfe;
      if ((bVar3 & 2) != 0) {
        *(byte *)(iVar8 + 0x20) = bVar3 & 0xfc;
        _thread_wakeup_prim(iVar8,0,0);
      }
      *(short *)(iVar4 + 0x44) = *(short *)(iVar4 + 0x44) + -1;
      LOCK();
      *(undefined4 *)(iVar4 + 0x10) = 0;
      UNLOCK();
      _vm_object_deallocate(iVar4);
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 5;
  }
  return uVar7;
}

