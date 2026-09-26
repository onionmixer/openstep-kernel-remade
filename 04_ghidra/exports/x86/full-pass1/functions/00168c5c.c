/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168c5c */

kern_return_t
_processor_set_stack_usage
          (processor_set_t pset,uint *ltotal,vm_size_t *space,vm_size_t *resident,
          vm_size_t *maxusage,vm_offset_t *maxstack)

{
  uint uVar1;
  vm_offset_t vVar2;
  kern_return_t kVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int local_18;
  uint local_14;
  vm_offset_t local_c;
  uint local_8;
  
  if (pset == 0) {
    kVar3 = 4;
  }
  else {
    local_14 = 0;
    local_18 = 0;
    piVar8 = (int *)(pset + 0x158);
    do {
      do {
        do {
        } while (*piVar8 != 0);
        LOCK();
        iVar7 = *piVar8;
        *piVar8 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      if (*(int *)(pset + 0x154) == 0) {
        LOCK();
        *(undefined4 *)(pset + 0x158) = 0;
        UNLOCK();
        return 4;
      }
      uVar1 = *(uint *)(pset + 0x140);
      uVar9 = uVar1 * 4;
      if (uVar9 <= local_14) {
        uVar9 = 0;
        iVar7 = *(int *)(pset + 0x138);
        if (uVar1 != 0) {
          do {
            if (iVar7 != 0) {
              uVar4 = _splsched();
              piVar8 = (int *)(iVar7 + 0x20);
              do {
                do {
                } while (*piVar8 != 0);
                LOCK();
                iVar5 = *piVar8;
                *piVar8 = 1;
                UNLOCK();
              } while (iVar5 == 1);
              *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) + 1;
              LOCK();
              *(undefined4 *)(iVar7 + 0x20) = 0;
              UNLOCK();
              _splx(uVar4);
            }
            *(int *)(local_18 + uVar9 * 4) = iVar7;
            uVar9 = uVar9 + 1;
            iVar7 = *(int *)(iVar7 + 0x18);
          } while (uVar9 < uVar1);
        }
        LOCK();
        *(undefined4 *)(pset + 0x158) = 0;
        UNLOCK();
        uVar9 = 0;
        local_8 = 0;
        local_c = 0;
        uVar10 = 0;
        if (uVar1 != 0) {
          do {
            vVar2 = *(vm_offset_t *)(local_18 + uVar10 * 4);
            iVar7 = 0;
            if ((*(byte *)(vVar2 + 0x4d) & 1) == 0) {
              iVar7 = *(int *)(vVar2 + 0x2c);
              iVar5 = 0;
              do {
                if ((&_active_threads)[iVar5] == vVar2) {
                  iVar7 = (&_active_stacks)[iVar5];
                  break;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < 1);
            }
            if ((iVar7 != 0) && (uVar9 = uVar9 + 1, _stack_check_usage != 0)) {
              uVar6 = 0;
              do {
                if (*(int *)(iVar7 + uVar6 * 4) != -0x21524111) break;
                uVar6 = uVar6 + 1;
              } while (uVar6 < 0x3fd);
              uVar6 = uVar6 * -4 + 0xff4;
              if (local_8 < uVar6) {
                local_c = vVar2;
                local_8 = uVar6;
              }
            }
            _thread_deallocate(vVar2);
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar1);
        }
        if (local_14 != 0) {
          _kfree(local_18,local_14);
        }
        *ltotal = uVar9;
        uVar9 = _page_mask + uVar9 * 0xff4 & ~_page_mask;
        *space = uVar9;
        *resident = uVar9;
        *maxusage = local_8;
        *maxstack = local_c;
        return 0;
      }
      LOCK();
      *(undefined4 *)(pset + 0x158) = 0;
      UNLOCK();
      if (local_14 != 0) {
        _kfree(local_18,local_14);
      }
      local_18 = _kalloc(uVar9);
      local_14 = uVar9;
    } while (local_18 != 0);
    kVar3 = 6;
  }
  return kVar3;
}

