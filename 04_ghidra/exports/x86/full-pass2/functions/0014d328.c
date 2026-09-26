/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d328 */

int _ipc_port_alloc_compat(uint param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint local_18;
  uint *local_c;
  uint local_8;
  
  piVar4 = (int *)_zalloc(_ipc_object_zones);
  puVar2 = _ipc_table_dnrequests;
  if (piVar4 == (int *)0x0) {
    iVar5 = 6;
  }
  else {
    puVar6 = (uint *)_ipc_table_alloc(*_ipc_table_dnrequests * 8);
    if (puVar6 == (uint *)0x0) {
      _zfree(_ipc_object_zones,piVar4);
      iVar5 = 6;
    }
    else {
      iVar5 = _ipc_entry_alloc(param_1,&local_8,&local_c);
      if (iVar5 == 0) {
        local_c[1] = (uint)piVar4;
        local_c[2] = 1;
        *local_c = *local_c | 0x420000;
        *piVar4 = 0;
        do {
          do {
          } while (*piVar4 != 0);
          LOCK();
          iVar5 = *piVar4;
          *piVar4 = 1;
          UNLOCK();
        } while (iVar5 == 1);
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        piVar4[1] = 1;
        piVar4[2] = -0x80000000;
        piVar4[3] = param_1;
        piVar4[4] = local_8;
        piVar4[6] = 0;
        piVar4[7] = 0;
        piVar4[8] = 0;
        piVar4[9] = 0;
        piVar4[10] = 0;
        piVar4[0xb] = 0;
        piVar4[0xc] = 0;
        piVar4[0xd] = 0;
        piVar4[0xe] = 0;
        piVar4[0xf] = 5;
        _ipc_mqueue_init(piVar4 + 0x10);
        piVar4[0x13] = 0;
        uVar1 = *puVar2;
        local_18 = 0;
        uVar3 = 2;
        if (2 < uVar1) {
          do {
            uVar7 = uVar3;
            (puVar6 + uVar7 * 2)[1] = 0;
            puVar6[uVar7 * 2] = local_18;
            uVar3 = uVar7 + 1;
            local_18 = uVar7;
          } while (uVar7 + 1 < uVar1);
        }
        *puVar6 = local_18;
        puVar6[1] = (uint)puVar2;
        piVar4[0xb] = (int)puVar6;
        puVar6[3] = local_8;
        puVar6[2] = param_1 | 1;
        _ipc_space_reference(param_1);
        *param_2 = local_8;
        *param_3 = piVar4;
        iVar5 = 0;
      }
      else {
        _zfree(_ipc_object_zones,piVar4);
        _ipc_table_free(*puVar2 * 8,puVar6);
      }
    }
  }
  return iVar5;
}

