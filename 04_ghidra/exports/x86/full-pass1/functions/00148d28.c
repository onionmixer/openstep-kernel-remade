/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00148d28 */

uint _ipc_kmsg_copyout_body
               (vm_address_t *param_1,vm_address_t *param_2,int param_3,vm_map_t param_4)

{
  vm_address_t vVar1;
  int *piVar2;
  bool bVar3;
  vm_address_t *pvVar4;
  byte bVar5;
  uint uVar6;
  vm_address_t *pvVar7;
  int iVar8;
  byte bVar9;
  int *piVar10;
  uint uVar11;
  vm_address_t *pvVar12;
  vm_address_t vVar13;
  vm_address_t *local_48;
  uint local_38;
  uint local_20;
  uint local_1c;
  int local_14;
  uint local_10;
  int *local_c;
  vm_address_t local_8;
  
  local_10 = 0;
  do {
    while( true ) {
      pvVar4 = param_1;
      if (param_2 <= param_1) {
        return local_10;
      }
      bVar5 = *(byte *)((int)param_1 + 3) >> 4;
      bVar9 = *(byte *)((int)param_1 + 3) >> 5;
      if ((bVar9 & 1) == 0) {
        local_1c = (uint)(byte)*param_1;
        uVar6 = (uint)*(byte *)((int)param_1 + 1);
        local_20 = *(ushort *)((int)param_1 + 2) & 0xfff;
        param_1 = param_1 + 1;
      }
      else {
        local_1c = (uint)(ushort)param_1[1];
        uVar6 = (uint)*(ushort *)((int)param_1 + 6);
        local_20 = param_1[2];
        param_1 = param_1 + 3;
      }
      uVar6 = uVar6 * local_20 + 7 >> 3;
      bVar3 = 5 < local_1c - 0x10;
      if (bVar3) break;
      if ((((bVar5 & 1) != 0) || (uVar6 == 0)) ||
         (local_14 = _vm_allocate(param_4,&local_8,uVar6,1), pvVar12 = pvVar4, local_14 == 0)) {
        pvVar12 = param_1;
        if ((bVar5 & 1) == 0) {
          pvVar12 = (vm_address_t *)*param_1;
        }
        local_48 = (vm_address_t *)0x0;
        if (local_20 != 0) {
          do {
            piVar2 = (int *)*pvVar12;
            if ((piVar2 == (int *)0x0) || (piVar2 == (int *)0xffffffff)) {
              *pvVar12 = *pvVar12;
LAB_00149042:
              uVar11 = 0;
            }
            else {
              if (local_1c == 0x11) {
                piVar10 = (int *)(param_3 + 8);
                do {
                  do {
                  } while (*piVar10 != 0);
                  LOCK();
                  iVar8 = *piVar10;
                  *piVar10 = 1;
                  UNLOCK();
                } while (iVar8 == 1);
                if (*(int *)(param_3 + 0xc) == 0) {
                  LOCK();
                  *(undefined4 *)(param_3 + 8) = 0;
                  UNLOCK();
                }
                else {
                  do {
                    do {
                    } while (*piVar2 != 0);
                    LOCK();
                    iVar8 = *piVar2;
                    *piVar2 = 1;
                    UNLOCK();
                  } while (iVar8 == 1);
                  if ((piVar2[2] < 0) &&
                     (iVar8 = _ipc_hash_local_lookup(param_3,piVar2,pvVar12,&local_c), iVar8 != 0))
                  {
                    piVar2[7] = piVar2[7] + -1;
                    piVar2[1] = piVar2[1] + -1;
                    LOCK();
                    *piVar2 = 0;
                    UNLOCK();
                    if ((short)(*local_c + 1) != -1) {
                      *local_c = *local_c + 1;
                    }
                    LOCK();
                    *(undefined4 *)(param_3 + 8) = 0;
                    UNLOCK();
                    goto LAB_00149042;
                  }
                  LOCK();
                  *piVar2 = 0;
                  UNLOCK();
                  LOCK();
                  *(undefined4 *)(param_3 + 8) = 0;
                  UNLOCK();
                }
              }
              iVar8 = _ipc_object_copyout(param_3,piVar2,local_1c,1,pvVar12);
              if (iVar8 == 0) goto LAB_00149042;
              _ipc_object_destroy(piVar2,local_1c);
              if (iVar8 == 0x14) {
                *pvVar12 = 0xffffffff;
                goto LAB_00149042;
              }
              *pvVar12 = 0;
              uVar11 = 0x2000;
              if (iVar8 == 6) {
                uVar11 = 0x800;
              }
            }
            local_10 = local_10 | uVar11;
            pvVar12 = pvVar12 + 1;
            local_48 = (vm_address_t *)((int)local_48 + 1);
          } while (local_48 < local_20);
        }
        break;
      }
      while (pvVar12 < param_1) {
        bVar5 = *(byte *)((int)pvVar12 + 3) >> 4;
        if ((*pvVar12 & 0x20000000) == 0) {
          local_38 = (uint)(byte)*pvVar12;
          uVar6 = (uint)*(byte *)((int)pvVar12 + 1);
          vVar13 = *(ushort *)((int)pvVar12 + 2) & 0xfff;
          pvVar12 = pvVar12 + 1;
        }
        else {
          local_38 = (uint)(ushort)pvVar12[1];
          uVar6 = (uint)*(ushort *)((int)pvVar12 + 6);
          vVar13 = pvVar12[2];
          pvVar12 = pvVar12 + 3;
        }
        uVar6 = uVar6 * vVar13 + 7 >> 3;
        bVar3 = local_38 - 0x10 < 6;
        if (bVar3) {
          if ((bVar5 & 1) == 0) {
            local_48 = (vm_address_t *)*pvVar12;
          }
          else {
            for (pvVar7 = pvVar12 + vVar13; local_48 = pvVar12, param_1 < pvVar7;
                pvVar7 = pvVar7 + -1) {
              vVar13 = vVar13 - 1;
            }
          }
          uVar11 = 0;
          if (vVar13 != 0) {
            do {
              vVar1 = local_48[uVar11];
              if ((vVar1 != 0) && (vVar1 != 0xffffffff)) {
                _ipc_object_destroy(vVar1,local_38);
              }
              uVar11 = uVar11 + 1;
            } while (uVar11 < vVar13);
          }
        }
        if ((bVar5 & 1) == 0) {
          if (uVar6 != 0) {
            if (bVar3) {
              _kfree(*pvVar12,uVar6);
            }
            else {
              _vm_deallocate(_ipc_soft_map,*pvVar12,uVar6);
            }
          }
          pvVar12 = pvVar12 + 1;
        }
        else {
          pvVar12 = (vm_address_t *)((int)pvVar12 + (uVar6 + 3 & 0xfffffffc));
        }
      }
LAB_001490f0:
      local_8 = 0;
      if ((bVar9 & 1) == 0) {
        *(byte *)((int)pvVar4 + 1) = 0;
      }
      else {
        ((byte *)((int)pvVar4 + 6))[0] = 0;
        ((byte *)((int)pvVar4 + 6))[1] = 0;
      }
      if (local_14 == 6) {
        local_10 = local_10 | 0x400;
      }
      else {
        local_10 = local_10 | 0x1000;
      }
LAB_00149127:
      *(byte *)((int)pvVar4 + 3) = *(byte *)((int)pvVar4 + 3) | 0x40;
      *param_1 = local_8;
      param_1 = param_1 + 1;
    }
    if ((bVar5 & 1) == 0) {
      vVar13 = *param_1;
      if (uVar6 == 0) {
        local_8 = 0;
      }
      else if (bVar3) {
        local_14 = _vm_move(_ipc_soft_map,vVar13,param_4,uVar6,0,&local_8);
        _vm_deallocate(_ipc_soft_map,vVar13,uVar6);
        if (local_14 != 0) goto LAB_001490f0;
      }
      else {
        _copyoutmap(param_4,vVar13,local_8,uVar6);
        _kfree(vVar13,uVar6);
      }
      goto LAB_00149127;
    }
    *(byte *)((int)pvVar4 + 3) = *(byte *)((int)pvVar4 + 3) & 0xbf;
    param_1 = (vm_address_t *)((int)param_1 + (uVar6 + 3 & 0xfffffffc));
  } while( true );
}

