
void _zone_free_space_reclaim(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *piVar11;
  
  piVar7 = (int *)0x0;
  piVar10 = &_zone_free_space;
  iVar8 = 1;
  if (1 < _zone_free_space_count) {
    do {
      piVar10 = piVar10 + 1;
      piVar3 = (int *)(*piVar10 + 8);
      while (piVar11 = piVar3, piVar3 = (int *)*piVar11, piVar3 != (int *)0x0) {
        if (_page_size <= (uint)piVar3[1]) {
          piVar4 = (int *)(~_page_mask & _page_mask + (int)piVar3);
          piVar5 = (int *)(~_page_mask & piVar3[1] + (int)piVar3);
          if (((piVar4 < piVar5) && (_zone_min <= piVar4)) && (piVar5 <= _zone_max)) {
            sub_4054D62(*piVar10,piVar3);
            if (piVar5 == (int *)(piVar3[1] + (int)piVar3)) {
              if (piVar4 == piVar3) {
                iVar1 = *piVar3;
                *piVar11 = iVar1;
                if (iVar1 != 0) {
                  *(int **)(*piVar3 + 8) = piVar11;
                }
                *(int *)(*piVar10 + 0xc) = *(int *)(*piVar10 + 0xc) + -1;
              }
              else {
                piVar3[1] = (int)piVar4 - (int)piVar3;
                iVar1 = *piVar10;
                uVar6 = (uint)((int)piVar4 - (int)piVar3) >> (*(uint *)(iVar1 + 0x10) & 0x3f);
                if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar6) {
                  uVar6 = *(uint *)(iVar1 + 0x18);
                }
                puVar9 = (undefined4 *)(uVar6 * 0x10 + *(int *)(iVar1 + 0x14) + -0x10);
                piVar2 = (int *)*puVar9;
                if ((piVar2 == (int *)0x0) || (piVar3 < piVar2)) {
                  *puVar9 = piVar3;
                }
              }
            }
            else {
              piVar5[1] = (piVar3[1] + (int)piVar3) - (int)piVar5;
              iVar1 = *piVar3;
              *piVar5 = iVar1;
              if (iVar1 != 0) {
                *(int **)(iVar1 + 8) = piVar5;
              }
              if (piVar4 == piVar3) {
                *piVar11 = (int)piVar5;
                piVar5[2] = (int)piVar11;
              }
              else {
                piVar3[1] = (int)piVar4 - (int)piVar3;
                *piVar3 = (int)piVar5;
                piVar5[2] = (int)piVar3;
                *(int *)(*piVar10 + 0xc) = *(int *)(*piVar10 + 0xc) + 1;
                iVar1 = *piVar10;
                uVar6 = (uint)piVar3[1] >> (*(uint *)(iVar1 + 0x10) & 0x3f);
                if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar6) {
                  uVar6 = *(uint *)(iVar1 + 0x18);
                }
                puVar9 = (undefined4 *)(uVar6 * 0x10 + *(int *)(iVar1 + 0x14) + -0x10);
                piVar2 = (int *)*puVar9;
                if ((piVar2 == (int *)0x0) || (piVar3 < piVar2)) {
                  *puVar9 = piVar3;
                }
              }
              iVar1 = *piVar10;
              uVar6 = (uint)piVar5[1] >> (*(uint *)(iVar1 + 0x10) & 0x3f);
              if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar6) {
                uVar6 = *(uint *)(iVar1 + 0x18);
              }
              puVar9 = (undefined4 *)(uVar6 * 0x10 + *(int *)(iVar1 + 0x14) + -0x10);
              piVar3 = (int *)*puVar9;
              if ((piVar3 == (int *)0x0) || (piVar5 < piVar3)) {
                *puVar9 = piVar5;
              }
            }
            piVar4[1] = (int)piVar5 - (int)piVar4;
            *piVar4 = (int)piVar7;
            piVar7 = piVar4;
            piVar3 = piVar11;
          }
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < _zone_free_space_count);
  }
  while (piVar7 != (int *)0x0) {
    piVar10 = (int *)*piVar7;
    _kmem_free(_zone_map,piVar7,piVar7[1]);
    piVar7 = piVar10;
  }
  return;
}
