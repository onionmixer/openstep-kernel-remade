/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017802c */

undefined4
_vm_map_lookup(int *param_1,uint param_2,uint param_3,int *param_4,undefined4 *param_5,int *param_6,
              uint *param_7,uint *param_8,uint *param_9)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  undefined4 *local_8;
  
  iVar6 = *param_1;
  do {
    _lock_read(iVar6);
    piVar5 = (int *)(iVar6 + 0x3c);
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar3 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    local_8 = *(undefined4 **)(iVar6 + 0x38);
    LOCK();
    *(undefined4 *)(iVar6 + 0x3c) = 0;
    UNLOCK();
    *param_4 = (int)local_8;
    if (((local_8 == (undefined4 *)(iVar6 + 0xc)) || (param_2 < (uint)local_8[2])) ||
       ((uint)local_8[3] <= param_2)) {
      piVar5 = (int *)(iVar6 + 0x3c);
      do {
        do {
        } while (*piVar5 != 0);
        LOCK();
        iVar3 = *piVar5;
        *piVar5 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      local_8 = *(undefined4 **)(iVar6 + 0x38);
      LOCK();
      *(undefined4 *)(iVar6 + 0x3c) = 0;
      UNLOCK();
      puVar2 = (undefined4 *)(iVar6 + 0xc);
      if (local_8 == puVar2) {
        local_8 = *(undefined4 **)(iVar6 + 0x10);
      }
      if (param_2 < (uint)local_8[2]) {
        puVar2 = (undefined4 *)local_8[1];
        local_8 = *(undefined4 **)(iVar6 + 0x10);
LAB_001780ff:
        while( true ) {
          if (local_8 == puVar2) goto LAB_00178103;
          if (param_2 < (uint)local_8[3]) break;
          local_8 = (undefined4 *)local_8[1];
        }
        if (param_2 < (uint)local_8[2]) {
LAB_00178103:
          uVar4 = *local_8;
          piVar5 = (int *)(iVar6 + 0x3c);
          do {
            do {
            } while (*piVar5 != 0);
            LOCK();
            iVar3 = *piVar5;
            *piVar5 = 1;
            UNLOCK();
          } while (iVar3 == 1);
          *(undefined4 *)(iVar6 + 0x38) = uVar4;
          LOCK();
          *(undefined4 *)(iVar6 + 0x3c) = 0;
          UNLOCK();
          _lock_done(iVar6);
          return 1;
        }
        piVar5 = (int *)(iVar6 + 0x3c);
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar3 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        *(undefined4 **)(iVar6 + 0x38) = local_8;
        LOCK();
        *(undefined4 *)(iVar6 + 0x3c) = 0;
        UNLOCK();
      }
      else {
        if (local_8 == puVar2) goto LAB_00178103;
        if ((uint)local_8[3] <= param_2) goto LAB_001780ff;
      }
      *param_4 = (int)local_8;
    }
    if ((*(byte *)(local_8 + 6) & 4) != 0) {
      iVar3 = local_8[4];
      *param_1 = iVar3;
      goto LAB_00178335;
    }
    local_14 = local_8[7];
    if (param_3 != (param_3 & local_14)) {
      _lock_done(iVar6);
      return 2;
    }
    sVar1 = *(short *)(local_8 + 10);
    *param_8 = (uint)(sVar1 != 0);
    if ((sVar1 != 0) != 0) {
      param_3 = local_8[7];
      local_14 = param_3;
    }
    local_18 = ~(uint)*(byte *)(local_8 + 6) & 1;
    if (local_18 == 0) {
      local_1c = local_8[4];
      local_10 = (param_2 - local_8[2]) + local_8[5];
      _lock_read(local_1c);
      piVar5 = (int *)(local_1c + 0x3c);
      do {
        do {
        } while (*piVar5 != 0);
        LOCK();
        iVar3 = *piVar5;
        *piVar5 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      local_8 = *(undefined4 **)(local_1c + 0x38);
      LOCK();
      *(undefined4 *)(local_1c + 0x3c) = 0;
      UNLOCK();
      puVar2 = (undefined4 *)(local_1c + 0xc);
      if (local_8 == puVar2) {
        local_8 = *(undefined4 **)(local_1c + 0x10);
      }
      if (local_10 < (uint)local_8[2]) {
        puVar2 = (undefined4 *)local_8[1];
        local_8 = *(undefined4 **)(local_1c + 0x10);
      }
      else {
        if (local_8 == puVar2) goto LAB_0017826f;
        if (local_10 < (uint)local_8[3]) goto LAB_001782b7;
      }
      while( true ) {
        if (local_8 == puVar2) goto LAB_0017826f;
        if (local_10 < (uint)local_8[3]) break;
        local_8 = (undefined4 *)local_8[1];
      }
      if (local_10 < (uint)local_8[2]) {
LAB_0017826f:
        uVar4 = *local_8;
        piVar5 = (int *)(local_1c + 0x3c);
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar3 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        *(undefined4 *)(local_1c + 0x38) = uVar4;
        LOCK();
        *(undefined4 *)(local_1c + 0x3c) = 0;
        UNLOCK();
        _lock_done(local_1c);
        _lock_done(iVar6);
        return 1;
      }
      piVar5 = (int *)(local_1c + 0x3c);
      do {
        do {
        } while (*piVar5 != 0);
        LOCK();
        iVar3 = *piVar5;
        *piVar5 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      *(undefined4 **)(local_1c + 0x38) = local_8;
      LOCK();
      *(undefined4 *)(local_1c + 0x3c) = 0;
      UNLOCK();
    }
    else {
      local_10 = param_2;
      local_1c = iVar6;
    }
LAB_001782b7:
    if ((*(byte *)(local_8 + 6) & 0x40) != 0) {
      if ((param_3 & 2) == 0) {
        local_14 = local_14 & 0xfffffffd;
        goto LAB_00178310;
      }
      iVar3 = _lock_read_to_write(local_1c);
      if (iVar3 == 0) {
        _vm_object_shadow(local_8 + 4,local_8 + 5,local_8[3] - local_8[2]);
        *(byte *)(local_8 + 6) = *(byte *)(local_8 + 6) & 0xbf;
        _lock_write_to_read(local_1c);
        goto LAB_00178310;
      }
      goto LAB_0017832c;
    }
LAB_00178310:
    if (local_8[4] != 0) goto LAB_0017836c;
    iVar3 = _lock_read_to_write(local_1c);
    if (iVar3 == 0) {
      uVar4 = _vm_object_allocate(local_8[3] - local_8[2]);
      local_8[4] = uVar4;
      local_8[5] = 0;
      _lock_write_to_read(local_1c);
LAB_0017836c:
      *param_6 = (local_10 - local_8[2]) + local_8[5];
      *param_5 = local_8[4];
      if (local_18 == 0) {
        piVar5 = (int *)(local_1c + 0x34);
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar6 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar6 == 1);
        local_18 = (uint)(*(int *)(local_1c + 0x30) == 1);
        LOCK();
        *(undefined4 *)(local_1c + 0x34) = 0;
        UNLOCK();
      }
      *param_7 = local_14;
      *param_9 = local_18;
      return 0;
    }
LAB_0017832c:
    iVar3 = iVar6;
    if (local_1c != iVar6) {
LAB_00178335:
      _lock_done(iVar6);
      iVar6 = iVar3;
    }
  } while( true );
}

