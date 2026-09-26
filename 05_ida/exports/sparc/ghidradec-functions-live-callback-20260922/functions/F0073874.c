
/* WARNING: Removing unreachable block (ram,0xf00738e8) */
/* WARNING: Removing unreachable block (ram,0xf0073a14) */
/* WARNING: Removing unreachable block (ram,0xf00739e0) */
/* WARNING: Removing unreachable block (ram,0xf00739a8) */
/* WARNING: Removing unreachable block (ram,0xf0073924) */
/* WARNING: Removing unreachable block (ram,0xf0073980) */
/* WARNING: Removing unreachable block (ram,0xf00739c0) */
/* WARNING: Removing unreachable block (ram,0xf00739ec) */
/* WARNING: Removing unreachable block (ram,0xf0073968) */
/* WARNING: Removing unreachable block (ram,0xf00738f4) */
/* WARNING: Removing unreachable block (ram,0xf00738a0) */

undefined8 _task_threads(int *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 *puVar6;
  undefined4 unaff_l4;
  uint uVar7;
  undefined4 unaff_l5;
  undefined4 *puVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 *puVar9;
  undefined4 unaff_i0;
  undefined4 uVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_1 == (int *)0x0) {
    uVar10 = 4;
  }
  else {
    puVar9 = (undefined4 *)0x0;
    puVar6 = (undefined4 *)0x0;
    do {
      do {
        do {
        } while (*param_1 != 0);
        piVar1 = param_1;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (param_1[2] == 0) {
        *param_1 = 0;
        uVar10 = 5;
        goto locret_F0073A30;
      }
      uVar7 = param_1[9];
      puVar8 = (undefined4 *)(uVar7 * 4);
      if (puVar8 < puVar6 || (int)puVar8 - (int)puVar6 == 0) {
        uVar3 = 0;
        iVar4 = param_1[7];
        if (uVar7 != 0) {
          iVar5 = 0;
          do {
            _thread_reference(iVar4);
            *(int *)(iVar5 + (int)puVar9) = iVar4;
            iVar5 = iVar5 + 4;
            uVar3 = uVar3 + 1;
            iVar4 = *(int *)(iVar4 + 0x10);
          } while (uVar3 < uVar7);
        }
        *param_1 = 0;
        if (uVar7 == 0) {
          *param_2 = 0;
          *param_3 = 0;
          if (puVar6 != (undefined4 *)0x0) {
            _kfree(puVar9,puVar6);
            uVar10 = 0;
            goto locret_F0073A30;
          }
        }
        else {
          if (puVar8 < puVar6) {
            puVar2 = puVar8;
            _kalloc();
            if (puVar2 == (undefined4 *)0x0) {
              uVar3 = 0;
              iVar4 = 0;
              if (uVar7 != 0) {
                do {
                  uVar3 = uVar3 + 1;
                  _thread_deallocate(*(undefined4 *)(iVar4 + (int)puVar9));
                  iVar4 = iVar4 + 4;
                } while (uVar3 < uVar7);
              }
              _kfree(puVar9,puVar6);
              uVar10 = 6;
              goto locret_F0073A30;
            }
            _bcopy(puVar9,puVar2,puVar8);
            _kfree(puVar9,puVar6);
            *param_2 = (int)puVar2;
          }
          else {
            *param_2 = (int)puVar9;
            puVar2 = puVar9;
          }
          uVar3 = 0;
          *param_3 = uVar7;
          if (uVar7 != 0) {
            do {
              uVar10 = *puVar2;
              uVar3 = uVar3 + 1;
              _convert_thread_to_port();
              *puVar2 = uVar10;
              puVar2 = puVar2 + 1;
            } while (uVar3 < uVar7);
          }
        }
        uVar10 = 0;
        goto locret_F0073A30;
      }
      *param_1 = 0;
      if (puVar6 != (undefined4 *)0x0) {
        _kfree(puVar9,puVar6);
      }
      puVar9 = puVar8;
      _kalloc();
      puVar6 = puVar8;
    } while (puVar9 != (undefined4 *)0x0);
    uVar10 = 6;
  }
locret_F0073A30:
  return CONCAT44(param_2,uVar10);
}

