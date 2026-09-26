/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016ab34 */

undefined4 _zone_free_space_reclaim(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  uint local_24;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_c = (int *)0x0;
  local_10 = &_zone_free_space;
  local_14 = 1;
  do {
    uVar7 = _zget_space_lock;
    if (_zone_free_space_count <= local_14) {
      LOCK();
      _zget_space_lock = 0;
      UNLOCK();
      while (local_c != (int *)0x0) {
        piVar4 = (int *)*local_c;
        uVar7 = _kmem_free(_zone_map,local_c,local_c[1]);
        local_c = piVar4;
      }
      return uVar7;
    }
    local_10 = local_10 + 1;
    piVar4 = (int *)(*local_10 + 8);
    for (local_8 = *(int **)(*local_10 + 8); local_8 != (int *)0x0; local_8 = (int *)*local_8) {
      uVar11 = local_8[1];
      if (_page_size <= uVar11) {
        piVar8 = (int *)(_page_mask + (int)local_8 & ~_page_mask);
        piVar9 = (int *)(uVar11 + (int)local_8 & ~_page_mask);
        if (((piVar8 < piVar9) && (_zone_min <= piVar8)) && (piVar9 <= _zone_max)) {
          iVar10 = *local_10;
          uVar2 = *(uint *)(iVar10 + 0x18);
          local_24 = uVar11 >> ((byte)*(undefined4 *)(iVar10 + 0x10) & 0x1f);
          if ((int)uVar2 < (int)local_24) {
            local_24 = uVar2;
          }
          iVar5 = local_24 * 0x10 + *(int *)(iVar10 + 0x14);
          piVar1 = (int *)(iVar5 + -0x10);
          if (*(int **)(iVar5 + -0x10) == local_8) {
            if ((int)local_24 < (int)uVar2) {
              for (puVar3 = (undefined4 *)*local_8;
                  (puVar3 != (undefined4 *)0x0 && (puVar3[1] != uVar11));
                  puVar3 = (undefined4 *)*puVar3) {
              }
              *piVar1 = (int)puVar3;
            }
            else {
              piVar6 = (int *)*local_8;
              if (piVar6 != (int *)0x0) {
                do {
                  if (*(uint *)(iVar10 + 4) <= (uint)piVar6[1]) break;
                  piVar6 = (int *)*piVar6;
                } while (piVar6 != (int *)0x0);
              }
              *piVar1 = (int)piVar6;
            }
          }
          if (piVar9 == (int *)((int)local_8 + local_8[1])) {
            if (piVar8 == local_8) {
              iVar10 = *local_8;
              *piVar4 = iVar10;
              if (iVar10 != 0) {
                *(int **)(*local_8 + 8) = piVar4;
              }
              *(int *)(*local_10 + 0xc) = *(int *)(*local_10 + 0xc) + -1;
            }
            else {
              local_8[1] = (int)piVar8 - (int)local_8;
              iVar10 = *local_10;
              uVar11 = (uint)((int)piVar8 - (int)local_8) >>
                       ((byte)*(undefined4 *)(iVar10 + 0x10) & 0x1f);
              if ((int)*(uint *)(iVar10 + 0x18) < (int)uVar11) {
                uVar11 = *(uint *)(iVar10 + 0x18);
              }
              iVar10 = *(int *)(iVar10 + 0x14) + uVar11 * 0x10;
              piVar1 = *(int **)(iVar10 + -0x10);
              if ((piVar1 == (int *)0x0) || (local_8 < piVar1)) {
                *(int **)(iVar10 + -0x10) = local_8;
              }
            }
          }
          else {
            piVar9[1] = ((int)local_8 + local_8[1]) - (int)piVar9;
            iVar10 = *local_8;
            *piVar9 = iVar10;
            if (iVar10 != 0) {
              *(int **)(iVar10 + 8) = piVar9;
            }
            if (piVar8 == local_8) {
              *piVar4 = (int)piVar9;
              piVar9[2] = (int)piVar4;
            }
            else {
              local_8[1] = (int)piVar8 - (int)local_8;
              *local_8 = (int)piVar9;
              piVar9[2] = (int)local_8;
              *(int *)(*local_10 + 0xc) = *(int *)(*local_10 + 0xc) + 1;
              iVar10 = *local_10;
              uVar11 = (uint)local_8[1] >> ((byte)*(undefined4 *)(iVar10 + 0x10) & 0x1f);
              if ((int)*(uint *)(iVar10 + 0x18) < (int)uVar11) {
                uVar11 = *(uint *)(iVar10 + 0x18);
              }
              iVar10 = *(int *)(iVar10 + 0x14) + uVar11 * 0x10;
              piVar1 = *(int **)(iVar10 + -0x10);
              if ((piVar1 == (int *)0x0) || (local_8 < piVar1)) {
                *(int **)(iVar10 + -0x10) = local_8;
              }
            }
            iVar10 = *local_10;
            uVar11 = (uint)piVar9[1] >> ((byte)*(undefined4 *)(iVar10 + 0x10) & 0x1f);
            if ((int)*(uint *)(iVar10 + 0x18) < (int)uVar11) {
              uVar11 = *(uint *)(iVar10 + 0x18);
            }
            iVar10 = *(int *)(iVar10 + 0x14) + uVar11 * 0x10;
            piVar1 = *(int **)(iVar10 + -0x10);
            if ((piVar1 == (int *)0x0) || (piVar9 < piVar1)) {
              *(int **)(iVar10 + -0x10) = piVar9;
            }
          }
          piVar8[1] = (int)piVar9 - (int)piVar8;
          *piVar8 = (int)local_c;
          local_c = piVar8;
          local_8 = piVar4;
        }
      }
      piVar4 = local_8;
    }
    local_14 = local_14 + 1;
  } while( true );
}

