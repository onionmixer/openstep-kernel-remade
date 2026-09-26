
/* WARNING: Removing unreachable block (ram,0xf0055d1c) */
/* WARNING: Removing unreachable block (ram,0xf0055ce4) */
/* WARNING: Removing unreachable block (ram,0xf0055de8) */
/* WARNING: Removing unreachable block (ram,0xf0055dc8) */
/* WARNING: Removing unreachable block (ram,0xf0055d88) */
/* WARNING: Removing unreachable block (ram,0xf0055d50) */
/* WARNING: Removing unreachable block (ram,0xf0055c68) */
/* WARNING: Removing unreachable block (ram,0xf0055bf8) */
/* WARNING: Removing unreachable block (ram,0xf0055ba8) */
/* WARNING: Removing unreachable block (ram,0xf0055b78) */
/* WARNING: Removing unreachable block (ram,0xf0055b38) */
/* WARNING: Removing unreachable block (ram,0xf00559ac) */
/* WARNING: Removing unreachable block (ram,0xf0055a00) */
/* WARNING: Removing unreachable block (ram,0xf0055ac4) */
/* WARNING: Removing unreachable block (ram,0xf0055a94) */
/* WARNING: Removing unreachable block (ram,0xf0055a38) */
/* WARNING: Removing unreachable block (ram,0xf0055908) */
/* WARNING: Removing unreachable block (ram,0xf0055898) */
/* WARNING: Removing unreachable block (ram,0xf00554f4) */
/* WARNING: Removing unreachable block (ram,0xf0055748) */
/* WARNING: Removing unreachable block (ram,0xf0055688) */
/* WARNING: Removing unreachable block (ram,0xf00556ac) */
/* WARNING: Removing unreachable block (ram,0xf00557c8) */
/* WARNING: Removing unreachable block (ram,0xf0055564) */
/* WARNING: Removing unreachable block (ram,0xf00558c4) */
/* WARNING: Removing unreachable block (ram,0xf0055928) */
/* WARNING: Removing unreachable block (ram,0xf0055a64) */
/* WARNING: Removing unreachable block (ram,0xf0055abc) */
/* WARNING: Removing unreachable block (ram,0xf00559ec) */
/* WARNING: Removing unreachable block (ram,0xf0055980) */
/* WARNING: Removing unreachable block (ram,0xf0055b0c) */
/* WARNING: Removing unreachable block (ram,0xf0055b64) */
/* WARNING: Removing unreachable block (ram,0xf0055b8c) */
/* WARNING: Removing unreachable block (ram,0xf0055bd4) */
/* WARNING: Removing unreachable block (ram,0xf0055c1c) */
/* WARNING: Removing unreachable block (ram,0xf0055c94) */
/* WARNING: Removing unreachable block (ram,0xf0055d74) */
/* WARNING: Removing unreachable block (ram,0xf0055da8) */
/* WARNING: Removing unreachable block (ram,0xf0055de0) */
/* WARNING: Removing unreachable block (ram,0xf0055df4) */
/* WARNING: Removing unreachable block (ram,0xf0055d00) */
/* WARNING: Removing unreachable block (ram,0xf0055d24) */
/* WARNING: Removing unreachable block (ram,0xf00555dc) */

undefined8 _ipc_kmsg_copyin_header(uint *param_1,uint *param_2,int param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 unaff_l1;
  uint *puVar11;
  uint uVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar13;
  undefined4 unaff_l5;
  uint uVar14;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar15;
  undefined4 uVar16;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar17;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  uVar6 = *param_1;
  uVar14 = param_1[2];
  uVar13 = param_1[3];
  if (param_3 == 0) {
    uVar7 = uVar6 & 0xffff;
    if (uVar7 == 0x13) {
      if (uVar13 == 0) {
        do {
          do {
          } while (param_2[2] != 0);
          puVar11 = param_2 + 2;
          _simple_lock_try();
        } while (puVar11 == (uint *)0x0);
        if (((param_2[3] == 0) || (param_2[6] <= uVar14 >> 8)) ||
           (iVar8 = (uVar14 >> 8) * 0x10,
           (*(uint *)(param_2[5] + iVar8) & 0xff010000) != (uVar14 << 0x18 | 0x10000)))
        goto loc_F0055828;
        piVar15 = *(int **)(param_2[5] + iVar8 + 4);
        do {
          do {
          } while (*piVar15 != 0);
          piVar10 = piVar15;
          _simple_lock_try();
        } while (piVar10 == (int *)0x0);
        param_2[2] = 0;
        if (piVar15[2] < 0) {
          piVar15[7] = piVar15[7] + 1;
          piVar15[1] = piVar15[1] + 1;
          *piVar15 = 0;
          *param_1 = uVar6 & 0xbfff0000 | 0x11;
          param_1[2] = (uint)piVar15;
          uVar16 = 0;
          goto locret_F0055E48;
        }
        *piVar15 = 0;
      }
    }
    else if (uVar7 < 0x14) {
      if ((uVar7 == 0x12) && (uVar13 == 0)) {
        do {
          do {
          } while (param_2[2] != 0);
          puVar11 = param_2 + 2;
          _simple_lock_try();
        } while (puVar11 == (uint *)0x0);
        uVar7 = uVar14 >> 8;
        if (param_2[3] != 0) {
          uVar12 = param_2[5];
          if (((uVar7 < param_2[6]) &&
              (puVar11 = (uint *)(uVar12 + uVar7 * 0x10),
              (*(uint *)(uVar12 + uVar7 * 0x10) & 0xff840000) == (uVar14 << 0x18 | 0x40000))) &&
             (puVar11[2] == 0)) {
            piVar15 = (int *)puVar11[1];
            do {
              do {
              } while (*piVar15 != 0);
              piVar10 = piVar15;
              _simple_lock_try();
            } while (piVar10 == (int *)0x0);
            if (piVar15[2] < 0) {
              *piVar15 = 0;
              uVar16 = 0;
              puVar11[2] = *(uint *)(uVar12 + 8);
              *(uint *)(uVar12 + 8) = uVar7;
              *puVar11 = uVar14 << 0x18;
              puVar11[1] = 0;
              param_2[2] = 0;
              *param_1 = uVar6 & 0xbfff0000 | 0x12;
              param_1[2] = (uint)piVar15;
              goto locret_F0055E48;
            }
            *piVar15 = 0;
          }
        }
loc_F0055828:
        param_2[2] = 0;
      }
    }
    else if (uVar7 == 0x1513) {
      do {
        do {
        } while (param_2[2] != 0);
        puVar11 = param_2 + 2;
        _simple_lock_try();
      } while (puVar11 == (uint *)0x0);
      if (param_2[3] != 0) {
        uVar7 = param_2[5];
        if (uVar14 >> 8 < param_2[6]) {
          iVar8 = (uVar14 >> 8) * 0x10;
          if ((*(uint *)(uVar7 + iVar8) & 0xff010000) == (uVar14 << 0x18 | 0x10000)) {
            piVar15 = *(int **)(uVar7 + iVar8 + 4);
            if ((uVar13 >> 8 < param_2[6]) &&
               (iVar8 = (uVar13 >> 8) * 0x10,
               (*(uint *)(uVar7 + iVar8) & 0xff020000) == (uVar13 << 0x18 | 0x20000))) {
              puVar9 = *(undefined4 **)(uVar7 + iVar8 + 4);
              do {
                do {
                } while (*piVar15 != 0);
                piVar10 = piVar15;
                _simple_lock_try();
              } while (piVar10 == (int *)0x0);
              if ((piVar15[2] < 0) &&
                 (puVar1 = puVar9, _simple_lock_try(), puVar1 != (undefined4 *)0x0)) {
                param_2[2] = 0;
                piVar15[7] = piVar15[7] + 1;
                piVar15[1] = piVar15[1] + 1;
                *piVar15 = 0;
                puVar9[8] = puVar9[8] + 1;
                puVar9[1] = puVar9[1] + 1;
                *puVar9 = 0;
                *param_1 = uVar6 & 0xbfff0000 | 0x1211;
                param_1[2] = (uint)piVar15;
                param_1[3] = (uint)puVar9;
                uVar16 = 0;
                goto locret_F0055E48;
              }
              *piVar15 = 0;
            }
          }
        }
      }
      goto loc_F0055828;
    }
  }
  uVar7 = uVar6 & 0xff;
  uVar17 = 0;
  uVar12 = (uVar6 & 0xff00) >> 8;
  if (4 < uVar7 - 0x11) {
loc_F0055880:
    uVar16 = 0x10000010;
    goto locret_F0055E48;
  }
  if (uVar12 == 0) {
    if (uVar13 != 0) goto loc_F0055880;
  }
  else if (4 < uVar12 - 0x11) goto loc_F0055880;
  do {
    do {
      puVar11 = param_2 + 2;
    } while (*puVar11 != 0);
    _simple_lock_try();
  } while (puVar11 == (uint *)0x0);
  if (param_2[3] == 0) goto loc_F0055E2C;
  if (param_3 != 0) {
    puVar11 = param_2;
    _ipc_entry_lookup(param_2,param_3);
    if ((puVar11 == (uint *)0x0) || ((*puVar11 & 0x20000) == 0)) {
      param_2[2] = 0;
      uVar16 = 0x1000000b;
      goto locret_F0055E48;
    }
    uVar17 = puVar11[1];
  }
  if (uVar14 != uVar13) {
    if ((uVar13 == 0) || (uVar13 == 0xffffffff)) {
      puVar11 = param_2;
      _ipc_entry_lookup(param_2,uVar14);
      if ((puVar11 != (uint *)0x0) &&
         (puVar2 = param_2,
         _ipc_right_copyin(param_2,uVar14,puVar11,uVar7,0,
                           (undefined *)((int)register0x00000038 + -0xc),
                           (undefined *)((int)register0x00000038 + -0x10)), puVar2 == (uint *)0x0))
      {
        if ((*puVar11 & 0x1f0000) == 0) {
          _ipc_entry_dealloc(param_2,uVar14,puVar11);
          *(uint *)((int)register0x00000038 + -0x14) = uVar13;
        }
        else {
          *(uint *)((int)register0x00000038 + -0x14) = uVar13;
        }
        *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
        goto loc_F0055D94;
      }
loc_F0055E2C:
      param_2[2] = 0;
    }
    else {
      puVar11 = param_2;
      _ipc_entry_lookup(param_2,uVar14);
      if (puVar11 == (uint *)0x0) goto loc_F0055E2C;
      puVar2 = param_2;
      _ipc_entry_lookup(param_2,uVar13);
      if (puVar2 == (uint *)0x0) {
loc_F0055E3C:
        param_2[2] = 0;
        uVar16 = 0x10000009;
        goto locret_F0055E48;
      }
      puVar3 = param_2;
      _ipc_right_copyin_check(param_2,uVar13,puVar2,uVar12);
      if (puVar3 == (uint *)0x0) goto loc_F0055E3C;
      puVar3 = param_2;
      _ipc_right_copyin(param_2,uVar14,puVar11,uVar7,0,(undefined *)((int)register0x00000038 + -0xc)
                        ,(undefined *)((int)register0x00000038 + -0x10));
      if (puVar3 != (uint *)0x0) goto loc_F0055E2C;
      piVar15 = (int *)puVar2[1];
      if (piVar15 != (int *)0x0) {
        _ipc_object_reference(piVar15);
      }
      puVar3 = param_2;
      _ipc_right_copyin(param_2,uVar13,puVar2,uVar12,1,
                        (undefined *)((int)register0x00000038 + -0x14),
                        (undefined *)((int)register0x00000038 + -0x18));
      if (puVar3 != (uint *)0x0) {
        *(undefined4 *)((int)register0x00000038 + -0x14) = 0xffffffff;
        *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
loc_F0055D58:
        uVar5 = *puVar11;
loc_F0055D60:
        if ((uVar5 & 0x1f0000) == 0) {
          _ipc_entry_dealloc(param_2,uVar14,puVar11);
        }
        if (piVar15 != (int *)0x0) {
          _ipc_object_release(piVar15);
        }
        goto loc_F0055D94;
      }
      if (piVar15 == (int *)0x0) {
loc_F0055D34:
        uVar5 = *puVar2;
loc_F0055D38:
        if ((uVar5 & 0x1f0000) == 0) {
          _ipc_entry_dealloc(param_2,uVar13,puVar2);
          goto loc_F0055D58;
        }
        uVar5 = *puVar11;
        goto loc_F0055D60;
      }
      if (*(int *)((int)register0x00000038 + -0x14) != -1) {
        uVar5 = *puVar2;
        goto loc_F0055D38;
      }
      piVar10 = *(int **)((int)register0x00000038 + -0xc);
      do {
        do {
        } while (*piVar15 != 0);
        piVar4 = piVar15;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      iVar8 = piVar15[3];
      *piVar15 = 0;
      do {
        do {
        } while (*piVar10 != 0);
        piVar4 = piVar10;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      uVar5 = 0;
      if (-1 < piVar10[2]) {
        uVar5 = (uint)(piVar10[3] - iVar8) >> 0x1f;
      }
      *piVar10 = 0;
      if (uVar5 == 0) goto loc_F0055D34;
      _ipc_right_copyin_undo
                (param_2,uVar14,puVar11,uVar7,*(undefined4 *)((int)register0x00000038 + -0xc),
                 *(undefined4 *)((int)register0x00000038 + -0x10));
      _ipc_right_copyin_undo
                (param_2,uVar13,puVar2,uVar12,*(undefined4 *)((int)register0x00000038 + -0x14),
                 *(undefined4 *)((int)register0x00000038 + -0x18));
      iVar8 = *(int *)((int)register0x00000038 + -0x10);
      param_2[2] = 0;
      if (iVar8 != 0) {
        _ipc_notify_dead_name(iVar8,uVar14);
      }
      _ipc_object_release(piVar15);
    }
    uVar16 = 0x10000003;
    goto locret_F0055E48;
  }
  puVar11 = param_2;
  _ipc_entry_lookup(param_2,uVar13);
  if (puVar11 == (uint *)0x0) goto loc_F0055E2C;
  puVar2 = param_2;
  _ipc_right_copyin_check(param_2,uVar13,puVar11,uVar12);
  if (puVar2 == (uint *)0x0) goto loc_F0055E3C;
  if ((uVar7 == 0x12) || (uVar12 == 0x12)) goto loc_F0055E2C;
  if ((uVar7 - 0x14 < 2) || (uVar12 - 0x14 < 2)) {
    puVar2 = param_2;
    _ipc_right_copyin(param_2,uVar13,puVar11,uVar7,0,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
    if (puVar2 != (uint *)0x0) goto loc_F0055E2C;
    _ipc_right_copyin(param_2,uVar13,puVar11,uVar12,1,(undefined *)((int)register0x00000038 + -0x14)
                      ,(undefined *)((int)register0x00000038 + -0x18));
  }
  else if ((uVar7 == 0x13) && (uVar12 == 0x13)) {
    puVar2 = param_2;
    _ipc_right_copyin(param_2,uVar13,puVar11,0x13,0,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
    if (puVar2 != (uint *)0x0) goto loc_F0055E2C;
    uVar16 = *(undefined4 *)((int)register0x00000038 + -0xc);
    _ipc_port_copy_send();
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar16;
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  }
  else if ((uVar7 == 0x11) && (uVar12 == 0x11)) {
    puVar2 = param_2;
    _ipc_right_copyin_two
              (param_2,uVar13,puVar11,(undefined *)((int)register0x00000038 + -0xc),
               (undefined *)((int)register0x00000038 + -0x10));
    if (puVar2 != (uint *)0x0) goto loc_F0055E2C;
    uVar16 = *(undefined4 *)((int)register0x00000038 + -0xc);
    if ((*puVar11 & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_2,uVar13,puVar11);
      uVar16 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar16;
  }
  else {
    puVar2 = param_2;
    _ipc_right_copyin(param_2,uVar13,puVar11,0x11,0,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x1c));
    if (puVar2 != (uint *)0x0) goto loc_F0055E2C;
    if ((*puVar11 & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_2,uVar13,puVar11);
    }
    uVar16 = *(undefined4 *)((int)register0x00000038 + -0xc);
    _ipc_port_copy_send();
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar16;
    if (uVar7 == 0x11) {
      *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x10) =
           *(undefined4 *)((int)register0x00000038 + -0x1c);
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x18) =
           *(undefined4 *)((int)register0x00000038 + -0x1c);
    }
  }
loc_F0055D94:
  uVar5 = *(uint *)((int)register0x00000038 + -0x10);
  if (param_3 == 0) {
loc_F0055DB4:
    uVar5 = *(uint *)((int)register0x00000038 + -0x10);
  }
  else if (uVar5 == uVar17) {
    _ipc_port_release_sonce();
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    goto loc_F0055DB4;
  }
  param_2[2] = 0;
  if (uVar5 == 0) {
    iVar8 = *(int *)((int)register0x00000038 + -0x18);
  }
  else {
    _ipc_notify_port_deleted(uVar5,uVar14);
    iVar8 = *(int *)((int)register0x00000038 + -0x18);
  }
  if (iVar8 != 0) {
    _ipc_notify_port_deleted(iVar8,uVar13);
  }
  _ipc_object_copyin_type();
  _ipc_object_copyin_type();
  *param_1 = uVar6 & 0xbfff0000 | uVar7 | uVar12 << 8;
  uVar16 = 0;
  uVar6 = *(uint *)((int)register0x00000038 + -0x14);
  param_1[2] = *(uint *)((int)register0x00000038 + -0xc);
  param_1[3] = uVar6;
locret_F0055E48:
  return CONCAT44(param_2,uVar16);
}

