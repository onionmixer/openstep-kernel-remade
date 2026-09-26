
/* WARNING: Removing unreachable block (ram,0xf000903c) */
/* WARNING: Removing unreachable block (ram,0xf0009054) */
/* WARNING: Removing unreachable block (ram,0xf0008bbc) */
/* WARNING: Removing unreachable block (ram,0xf0008b90) */
/* WARNING: Removing unreachable block (ram,0xf0008b40) */
/* WARNING: Removing unreachable block (ram,0xf0008b24) */
/* WARNING: Removing unreachable block (ram,0xf0008cb0) */
/* WARNING: Removing unreachable block (ram,0xf0008c98) */
/* WARNING: Removing unreachable block (ram,0xf0008c3c) */
/* WARNING: Removing unreachable block (ram,0xf0008be8) */
/* WARNING: Removing unreachable block (ram,0xf0008d40) */
/* WARNING: Removing unreachable block (ram,0xf0008e98) */
/* WARNING: Removing unreachable block (ram,0xf0008fa4) */
/* WARNING: Removing unreachable block (ram,0xf0008a38) */
/* WARNING: Removing unreachable block (ram,0xf0008fac) */
/* WARNING: Removing unreachable block (ram,0xf0008d18) */
/* WARNING: Removing unreachable block (ram,0xf0008dac) */
/* WARNING: Removing unreachable block (ram,0xf0008c20) */
/* WARNING: Removing unreachable block (ram,0xf0008c78) */
/* WARNING: Removing unreachable block (ram,0xf0008ca0) */
/* WARNING: Removing unreachable block (ram,0xf0008cf4) */
/* WARNING: Removing unreachable block (ram,0xf0008e0c) */
/* WARNING: Removing unreachable block (ram,0xf0008b68) */
/* WARNING: Removing unreachable block (ram,0xf0008bb0) */
/* WARNING: Removing unreachable block (ram,0xf0008bc4) */
/* WARNING: Removing unreachable block (ram,0xf0009020) */
/* WARNING: Removing unreachable block (ram,0xf0009074) */
/* WARNING: Removing unreachable block (ram,0xf0008954) */

undefined8 _table(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_l0;
  undefined *puVar8;
  undefined4 unaff_l1;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  int *piVar12;
  undefined4 unaff_l6;
  uint uVar13;
  undefined4 unaff_l7;
  int *piVar14;
  undefined4 unaff_i0;
  int iVar15;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar16;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  piVar12 = *(int **)(dword_F0133DDC + 0x24);
  piVar14 = (int *)0x0;
  iVar15 = 0;
  if (piVar12[3] < 0) {
    iVar1 = *piVar12;
    _machine_table_setokay();
    if (((iVar1 != 0) && (0 < iVar1)) && (iVar1 == 1)) {
      iVar15 = 1;
      piVar12[3] = -piVar12[3];
      goto loc_F00089CC;
    }
  }
  else {
loc_F00089CC:
    *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
    if (*piVar12 != 1) goto loc_F00090C4;
    if (((piVar12[1] == (int)*(sword *)(*_active_u + 0x30)) || (piVar12[1] == 0)) &&
       (piVar12[3] == 1)) {
      iVar1 = piVar12[3];
      while (0 < iVar1) {
        iVar5 = *piVar12;
        piVar10 = (int *)0x0;
        uVar13 = 0;
        _machine_table(iVar5,piVar12[1],piVar12[2],iVar1,piVar12[4],iVar15);
        if (iVar5 != 0) {
          if (iVar5 < 1) goto def_F0008A80;
          if (iVar5 == 1) {
            iVar1 = piVar12[2];
            goto loc_F000908C;
          }
          goto loc_F0008FD4;
        }
        switch(*piVar12) {
        case :
          piVar7 = _active_u + 0x5a;
          if (_active_u[0x59] == 0) {
            *(undefined2 *)((int)register0x00000038 + -0xba) = 0xffff;
            piVar7 = (int *)((int)register0x00000038 + -0xba);
          }
          uVar11 = 2;
          break;
        case :
          iVar1 = piVar12[1];
          _pfind();
          if (iVar1 != 0) {
            piVar10 = *(int **)(iVar1 + 0x68);
            do {
              do {
              } while (*piVar10 != 0);
              piVar7 = piVar10;
              _simple_lock_try();
            } while (piVar7 == (int *)0x0);
            uVar11 = 0x7cc;
            if (0 < piVar10[9]) {
              iVar1 = piVar10[7];
              _thread_reference(iVar1);
              *piVar10 = 0;
              piVar10 = _kernel_pageable_map;
              _kmem_alloc_wait(_kernel_pageable_map,_page_mask + 0x7cc & ~_page_mask);
              _fake_u();
              _thread_deallocate(iVar1);
              uVar13 = (int)piVar10 + (_page_mask + 0x7cc & ~_page_mask);
              piVar7 = piVar10;
              break;
            }
            *piVar10 = 0;
          }
loc_F00089A4:
          *(undefined *)(dword_F0133DDC + 0x38) = 3;
          goto locret_F00090D4;
        case :
          if ((piVar12[1] == 0) && (piVar12[3] == 1)) {
            puVar8 = _avenrun;
            goto loc_F0008E04;
          }
          goto loc_F0008FD4;
        :
def_F0008A80:
          goto loc_F0008FD4;
        case :
          iVar1 = piVar12[1];
          piVar7 = (int *)((int)register0x00000038 + -0x18);
          _table_fsparam(iVar1,piVar7);
          if (iVar1 != 0) goto loc_F0008E20;
          goto loc_F0008FD4;
        case :
          iVar1 = piVar12[1];
          _pfind();
          if (iVar1 == 0) goto loc_F00089A4;
          uVar11 = piVar12[4];
          uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x68) + 0xc);
          if ((uVar11 == 0) || (iVar1 = *(int *)(iVar1 + 0x84), iVar1 == 0)) goto def_F0008A80;
          _vm_map_reference(uVar3);
          piVar10 = _kernel_pageable_map;
          _kmem_alloc_wait(_kernel_pageable_map,uVar11 + _page_mask & ~_page_mask);
          uVar4 = ~_page_mask;
          uVar13 = (int)piVar10 + _page_mask + uVar11 & uVar4;
          piVar7 = _kernel_pageable_map;
          _vm_map_copy(_kernel_pageable_map,uVar3,piVar10,uVar11 + _page_mask & uVar4,
                       iVar1 - uVar11 & uVar4,0,0);
          if (piVar7 != (int *)0x0) {
            _kmem_free_wakeup(_kernel_pageable_map,piVar10,uVar11 + _page_mask & ~_page_mask);
            _vm_map_deallocate(uVar3);
            goto loc_F0008FD4;
          }
          _vm_map_deallocate(uVar3);
          piVar7 = (int *)(uVar13 - uVar11);
          piVar6 = (int *)(uVar13 - 0xc);
          if (*(int *)(uVar13 - 0xc) != 0) {
            iVar1 = (int)piVar6 - (int)piVar7;
            do {
              if (iVar1 == 0) break;
              piVar6 = piVar6 + -1;
              iVar1 = (int)piVar6 - (int)piVar7;
            } while (*piVar6 != 0);
          }
          _bzero(piVar7,(int)piVar6 - (int)piVar7);
          break;
        case :
          if (piVar12[1] < 0) {
            piVar12[1] = -piVar12[1];
          }
          iVar1 = piVar12[1];
          _pfind();
          if (iVar1 == 0) goto loc_F00089A4;
          if (*(char *)(iVar1 + 0x13) == '\0') {
            _bzero((undefined *)((int)register0x00000038 + -0x58),0x30);
            *(undefined4 *)((int)register0x00000038 + -0x44) = 0;
          }
          else {
            *(int *)((int)register0x00000038 + -0x58) = (int)*(sword *)(iVar1 + 0x2c);
            *(int *)((int)register0x00000038 + -0x54) = (int)*(sword *)(iVar1 + 0x30);
            *(int *)((int)register0x00000038 + -0x50) = (int)*(sword *)(iVar1 + 0x32);
            *(int *)((int)register0x00000038 + -0x4c) = (int)*(sword *)(iVar1 + 0x2e);
            *(undefined4 *)((int)register0x00000038 + -0x40) = *(undefined4 *)(iVar1 + 0x28);
            if (*(int *)(iVar1 + 0x68) == 0) {
              uVar3 = 3;
            }
            else {
              iVar5 = *(int *)(*(int *)(iVar1 + 0x68) + 0x38);
              if (*(int *)(iVar5 + 0x164) == 0) {
                iVar2 = -1;
              }
              else {
                iVar2 = (int)*(sword *)(iVar5 + 0x168);
              }
              *(int *)((int)register0x00000038 + -0x48) = iVar2;
              _bcopy(iVar5 + 8,(undefined *)((int)register0x00000038 + -0x3c),0x10);
              *(undefined *)((int)register0x00000038 + -0x2c) = 0;
              uVar3 = 2;
              if ((*(uint *)(iVar1 + 0x28) & 0x400) == 0) {
                uVar3 = 1;
              }
            }
            *(undefined4 *)((int)register0x00000038 + -0x44) = uVar3;
          }
          uVar11 = 0x30;
          piVar7 = (int *)((int)register0x00000038 + -0x58);
          break;
        case :
          if ((piVar12[1] != 0) || (piVar12[3] != 1)) goto loc_F0008FD4;
          puVar8 = _mach_factor;
loc_F0008E04:
          piVar7 = (int *)((int)register0x00000038 + -0x28);
          _bcopy(puVar8,piVar7,0xc);
          *(undefined4 *)((int)register0x00000038 + -0x1c) = 1000;
loc_F0008E20:
          uVar11 = 0x10;
          break;
        case :
          if ((piVar12[1] == 0) && (piVar12[3] == 1)) {
            *(undefined4 *)((int)register0x00000038 + -0x6c) = 0;
            piVar7 = (int *)((int)register0x00000038 + -0x80);
            *(undefined4 *)((int)register0x00000038 + -0x80) = _cnt;
            *(undefined4 *)((int)register0x00000038 + -0x7c) = DAT_f0133fcc._0_4_;
            *(undefined4 *)((int)register0x00000038 + -0x78) = DAT_f0133fc8._0_4_;
            uVar11 = 0x28;
            *(undefined4 *)((int)register0x00000038 + -0x74) = DAT_f0133fc4._0_4_;
            *(undefined4 *)((int)register0x00000038 + -0x70) = _hz;
            _bcopy(_cp_time,(undefined *)((int)register0x00000038 + -0x68),0x10);
            uVar4 = piVar12[4];
            goto loc_F0008FF8;
          }
          goto loc_F0008FD4;
        case :
          if ((piVar12[1] != 0) || (piVar12[3] != 1)) goto loc_F0008FD4;
          iVar1 = 0;
          *(undefined4 *)((int)register0x00000038 + -0x98) = _tk_nin;
          *(undefined4 *)((int)register0x00000038 + -0x94) = _tk_nout;
          *(undefined4 *)((int)register0x00000038 + -0x90) = _dk_busy;
          *(undefined4 *)((int)register0x00000038 + -0x8c) = _dk_ndrive;
          for (puVar9 = _ifnet; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)puVar9[0x17]) {
            iVar1 = iVar1 + 1;
          }
          *(int *)((int)register0x00000038 + -0x88) = iVar1;
          uVar11 = 0x14;
          piVar7 = (int *)((int)register0x00000038 + -0x98);
          break;
        case :
          bVar16 = _ifnet == (undefined4 *)0x0;
          iVar1 = piVar12[1];
          puVar9 = _ifnet;
          if (!bVar16) {
            do {
              bVar16 = puVar9 == (undefined4 *)0x0;
              if (iVar1 == 0) goto loc_F0008F60;
              puVar9 = (undefined4 *)puVar9[0x17];
              iVar1 = iVar1 + -1;
            } while (puVar9 != (undefined4 *)0x0);
            bVar16 = true;
          }
loc_F0008F60:
          puVar8 = (undefined *)((int)register0x00000038 + -0xa4);
          if (bVar16) goto def_F0008A80;
          *(undefined4 *)((int)register0x00000038 + -0xb8) = puVar9[0x11];
          *(undefined4 *)((int)register0x00000038 + -0xb4) = puVar9[0x12];
          *(undefined4 *)((int)register0x00000038 + -0xb0) = puVar9[0x13];
          uVar11 = 0x1c;
          *(undefined4 *)((int)register0x00000038 + -0xac) = puVar9[0x14];
          *(undefined4 *)((int)register0x00000038 + -0xa8) = puVar9[0x15];
          _strncpy(puVar8,*puVar9,6);
          _strlen();
          ((undefined *)((int)register0x00000038 + -8) + (int)puVar8)[-0x9c] =
               *(char *)((int)puVar9 + 9) + '0';
          ((undefined *)((int)register0x00000038 + -8) + (int)puVar8)[-0x9b] = 0;
          piVar7 = (int *)((int)register0x00000038 + -0xb8);
        }
        uVar4 = piVar12[4];
loc_F0008FF8:
        if (uVar4 < uVar11) {
          uVar11 = uVar4;
        }
        if (uVar11 != 0) {
          if (iVar15 == 0) {
            _copyout(piVar7,piVar12[2],uVar11);
            piVar14 = piVar7;
          }
          else {
            piVar14 = (int *)piVar12[2];
            _copyin(piVar14,(undefined *)((int)register0x00000038 + -200),uVar11);
            if (piVar14 == (int *)0x0) {
              _bcopy((undefined *)((int)register0x00000038 + -200),piVar7,uVar11);
            }
          }
        }
        if (piVar10 != (int *)0x0) {
          _kmem_free_wakeup(_kernel_pageable_map,piVar10,uVar13 - (int)piVar10);
        }
        if (piVar14 != (int *)0x0) {
          *(char *)(dword_F0133DDC + 0x38) = (char)piVar14;
          break;
        }
        iVar1 = piVar12[2];
loc_F000908C:
        piVar12[2] = iVar1 + piVar12[4];
        piVar12[3] = piVar12[3] + -1;
        piVar12[1] = piVar12[1] + 1;
        *(int *)(dword_F0133DDC + 0x30) = *(int *)(dword_F0133DDC + 0x30) + 1;
loc_F00090C4:
        iVar1 = piVar12[3];
      }
      goto locret_F00090D4;
    }
loc_F0008FD4:
    if (*(int *)(dword_F0133DDC + 0x30) != 0) goto locret_F00090D4;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
locret_F00090D4:
  return CONCAT44(param_2,iVar15);
}

