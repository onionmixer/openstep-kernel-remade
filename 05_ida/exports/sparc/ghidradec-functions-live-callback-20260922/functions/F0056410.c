
/* WARNING: Removing unreachable block (ram,0xf0056908) */
/* WARNING: Removing unreachable block (ram,0xf0056a0c) */
/* WARNING: Removing unreachable block (ram,0xf005698c) */
/* WARNING: Removing unreachable block (ram,0xf0056960) */
/* WARNING: Removing unreachable block (ram,0xf0056bd8) */
/* WARNING: Removing unreachable block (ram,0xf0056b64) */
/* WARNING: Removing unreachable block (ram,0xf0056a6c) */
/* WARNING: Removing unreachable block (ram,0xf0056948) */
/* WARNING: Removing unreachable block (ram,0xf00568c0) */
/* WARNING: Removing unreachable block (ram,0xf0056894) */
/* WARNING: Removing unreachable block (ram,0xf005681c) */
/* WARNING: Removing unreachable block (ram,0xf00567bc) */
/* WARNING: Removing unreachable block (ram,0xf0056ae4) */
/* WARNING: Removing unreachable block (ram,0xf005668c) */
/* WARNING: Removing unreachable block (ram,0xf0056598) */
/* WARNING: Removing unreachable block (ram,0xf00564f8) */
/* WARNING: Removing unreachable block (ram,0xf0056740) */
/* WARNING: Removing unreachable block (ram,0xf0056484) */
/* WARNING: Removing unreachable block (ram,0xf0056550) */
/* WARNING: Removing unreachable block (ram,0xf00565bc) */
/* WARNING: Removing unreachable block (ram,0xf0056ab8) */
/* WARNING: Removing unreachable block (ram,0xf0056b2c) */
/* WARNING: Removing unreachable block (ram,0xf00567ec) */
/* WARNING: Removing unreachable block (ram,0xf0056840) */
/* WARNING: Removing unreachable block (ram,0xf00568a8) */
/* WARNING: Removing unreachable block (ram,0xf00568e4) */
/* WARNING: Removing unreachable block (ram,0xf0056a58) */
/* WARNING: Removing unreachable block (ram,0xf0056a84) */
/* WARNING: Removing unreachable block (ram,0xf0056bac) */
/* WARNING: Removing unreachable block (ram,0xf0056c54) */
/* WARNING: Removing unreachable block (ram,0xf0056970) */
/* WARNING: Removing unreachable block (ram,0xf00569e4) */
/* WARNING: Removing unreachable block (ram,0xf00569c8) */
/* WARNING: Removing unreachable block (ram,0xf0056910) */
/* WARNING: Removing unreachable block (ram,0xf00566d8) */

undefined8 _ipc_kmsg_copyout_header(uint *param_1,uint *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  int *piVar8;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar10;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar11;
  undefined4 uVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
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
  uVar10 = *param_1;
  piVar8 = (int *)param_1[2];
  if (param_3 == 0) {
    uVar5 = uVar10 & 0xffff;
    if (uVar5 == 0x12) {
      do {
        do {
        } while (*piVar8 != 0);
        piVar7 = piVar8;
        _simple_lock_try();
      } while (piVar7 == (int *)0x0);
      if (piVar8[2] < 0) {
        if ((uint *)piVar8[3] == param_2) {
          piVar8[1] = piVar8[1] + -1;
          piVar8[8] = piVar8[8] + -1;
          uVar5 = piVar8[4];
          *piVar8 = 0;
        }
        else {
          *piVar8 = 0;
          _ipc_notify_send_once(piVar8);
          uVar5 = 0;
        }
        *param_1 = uVar10 & 0xffff0000 | 0x1200;
        param_1[3] = uVar5;
loc_F0056768:
        param_1[2] = 0;
        uVar12 = 0;
        goto locret_F0056C88;
      }
loc_F00566FC:
      *piVar8 = 0;
      piVar7 = (int *)param_1[3];
    }
    else if (uVar5 < 0x13) {
      if (uVar5 == 0x11) {
        do {
          do {
          } while (*piVar8 != 0);
          piVar7 = piVar8;
          _simple_lock_try();
        } while (piVar7 == (int *)0x0);
        if (-1 < piVar8[2]) goto loc_F00566FC;
        piVar8[1] = piVar8[1] + -1;
        uVar5 = 0;
        if ((uint *)piVar8[3] == param_2) {
          uVar5 = piVar8[4];
        }
        iVar4 = piVar8[7];
        piVar8[7] = iVar4 + -1;
        if ((iVar4 + -1 == 0) && (iVar4 = piVar8[9], iVar4 != 0)) {
          piVar8[9] = 0;
          *piVar8 = 0;
          _ipc_notify_no_senders(iVar4,piVar8[6]);
        }
        else {
          *piVar8 = 0;
        }
        *param_1 = uVar10 & 0xffff0000 | 0x1100;
        param_1[3] = uVar5;
        goto loc_F0056768;
      }
      piVar7 = (int *)param_1[3];
    }
    else {
      piVar7 = (int *)param_1[3];
      if (uVar5 == 0x1211) {
        if ((piVar7 == (int *)0x0) || (piVar7 == (int *)0xffffffff)) goto loc_F0056780;
        do {
          do {
          } while (param_2[2] != 0);
          puVar11 = param_2 + 2;
          _simple_lock_try();
        } while (puVar11 == (uint *)0x0);
        if (param_2[3] != 0) {
          uVar5 = param_2[5];
          iVar4 = *(int *)(uVar5 + 8);
          if (iVar4 != 0) {
            do {
              do {
              } while (*piVar8 != 0);
              piVar1 = piVar8;
              _simple_lock_try();
            } while (piVar1 == (int *)0x0);
            if ((piVar8[2] < 0) && (piVar1 = piVar7, _simple_lock_try(), piVar1 != (int *)0x0)) {
              if (piVar7[2] < 0) {
                *piVar7 = 0;
                iVar9 = iVar4 * 0x10;
                iVar6 = uVar5 + iVar9;
                *(undefined4 *)(uVar5 + 8) = *(undefined4 *)(iVar6 + 8);
                *(undefined4 *)(iVar6 + 8) = 0;
                uVar2 = *(int *)(uVar5 + iVar9) + 0x1000000;
                *(uint *)(uVar5 + iVar9) = uVar2 | 0x40001;
                *(int **)(iVar6 + 4) = piVar7;
                param_2[2] = 0;
                piVar8[1] = piVar8[1] + -1;
                uVar5 = 0;
                if ((uint *)piVar8[3] == param_2) {
                  uVar5 = piVar8[4];
                }
                iVar9 = piVar8[7];
                piVar8[7] = iVar9 + -1;
                if ((iVar9 + -1 == 0) && (iVar9 = piVar8[9], iVar9 != 0)) {
                  piVar8[9] = 0;
                  *piVar8 = 0;
                  _ipc_notify_no_senders(iVar9,piVar8[6]);
                }
                else {
                  *piVar8 = 0;
                }
                *param_1 = uVar10 & 0xffff0000 | 0x1112;
                param_1[3] = uVar5;
                param_1[2] = iVar4 << 8 | uVar2 >> 0x18;
                uVar12 = 0;
                goto locret_F0056C88;
              }
              *piVar7 = 0;
            }
            *piVar8 = 0;
          }
        }
        param_2[2] = 0;
        piVar7 = (int *)param_1[3];
      }
    }
  }
  else {
loc_F0056780:
    piVar7 = (int *)param_1[3];
  }
  uVar5 = (uVar10 & 0xff00) >> 8;
  if ((piVar7 == (int *)0x0) || (piVar7 == (int *)0xffffffff)) {
    do {
      do {
      } while (param_2[2] != 0);
      puVar11 = param_2 + 2;
      _simple_lock_try();
    } while (puVar11 == (uint *)0x0);
    if (param_2[3] != 0) {
      if ((param_3 == 0) ||
         ((puVar11 = param_2, _ipc_entry_lookup(param_2,param_3), puVar11 != (uint *)0x0 &&
          ((*puVar11 & 0x20000) != 0)))) {
        do {
          do {
          } while (*piVar8 != 0);
          piVar1 = piVar8;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        param_2[2] = 0;
loc_F0056B44:
        *(int **)((int)register0x00000038 + -0xc) = piVar7;
        iVar4 = piVar8[2];
loc_F0056B4C:
        if (iVar4 < 0) {
          _ipc_object_copyout_dest
                    (param_2,piVar8,uVar10 & 0xff,(undefined *)((int)register0x00000038 + -0x18));
        }
        else {
          iVar9 = piVar8[3];
          iVar4 = piVar8[1];
          piVar8[1] = iVar4 + -1;
          *piVar8 = 0;
          if (iVar4 + -1 == 0) {
            _zfree((&_ipc_object_zones)[(piVar8[2] & 0x7fffffffU) >> 0x10],piVar8);
          }
          if ((piVar7 == (int *)0x0) || (piVar7 == (int *)0xffffffff)) {
            *(undefined4 *)((int)register0x00000038 + -0x18) = 0xffffffff;
          }
          else {
            do {
              do {
              } while (*piVar7 != 0);
              piVar8 = piVar7;
              _simple_lock_try();
            } while (piVar8 == (int *)0x0);
            if ((piVar7[2] < 0) || (iVar9 - piVar7[3] < 0)) {
              *(undefined4 *)((int)register0x00000038 + -0x18) = 0xffffffff;
            }
            else {
              *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
            }
            *piVar7 = 0;
          }
        }
        if ((piVar7 != (int *)0x0) && (piVar7 != (int *)0xffffffff)) {
          _ipc_object_release(piVar7);
        }
        *param_1 = uVar10 & 0xffff0000 | uVar5 | (uVar10 & 0xff) << 8;
        uVar12 = 0;
        uVar10 = *(uint *)((int)register0x00000038 + -0xc);
        param_1[3] = *(uint *)((int)register0x00000038 + -0x18);
        param_1[2] = uVar10;
      }
      else {
loc_F0056B0C:
        param_2[2] = 0;
        uVar12 = 0x10004007;
      }
      goto locret_F0056C88;
    }
  }
  else {
    do {
      do {
      } while (param_2[2] != 0);
      puVar11 = param_2 + 2;
      _simple_lock_try();
    } while (puVar11 == (uint *)0x0);
    uVar2 = param_2[3];
    while (uVar2 != 0) {
      if (param_3 == 0) {
        puVar11 = (uint *)0x0;
      }
      else {
        puVar11 = param_2;
        _ipc_port_lookup_notify(param_2,param_3);
        if (puVar11 == (uint *)0x0) goto loc_F0056B0C;
      }
      if ((uVar5 != 0x12) &&
         (puVar3 = param_2,
         _ipc_right_reverse(param_2,piVar7,(undefined *)((int)register0x00000038 + -0xc),
                            (undefined *)((int)register0x00000038 + -0x10)), puVar3 != (uint *)0x0))
      {
        iVar4 = piVar7[1];
loc_F0056A3C:
        piVar7[1] = iVar4 + 1;
        _ipc_right_copyout(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                           *(undefined4 *)((int)register0x00000038 + -0x10),uVar5,1,piVar7);
        if (puVar11 != (uint *)0x0) {
          _ipc_port_release_sonce(puVar11);
        }
        do {
          do {
          } while (*piVar8 != 0);
          piVar1 = piVar8;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        param_2[2] = 0;
        iVar4 = piVar8[2];
        goto loc_F0056B4C;
      }
      do {
        do {
        } while (*piVar7 != 0);
        piVar1 = piVar7;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (-1 < piVar7[2]) {
        iVar4 = piVar7[1];
        piVar7[1] = iVar4 + -1;
        *piVar7 = 0;
        if (iVar4 + -1 == 0) {
          _zfree((&_ipc_object_zones)[(piVar7[2] & 0x7fffffffU) >> 0x10],piVar7);
        }
        if (puVar11 != (uint *)0x0) {
          _ipc_port_release_sonce(puVar11);
        }
        do {
          do {
          } while (*piVar8 != 0);
          piVar7 = piVar8;
          _simple_lock_try();
        } while (piVar7 == (int *)0x0);
        param_2[2] = 0;
        piVar7 = (int *)0xffffffff;
        goto loc_F0056B44;
      }
      puVar3 = param_2;
      _ipc_entry_get(param_2,(undefined *)((int)register0x00000038 + -0xc),
                     (undefined *)((int)register0x00000038 + -0x10));
      if (puVar3 == (uint *)0x0) {
        if (puVar11 == (uint *)0x0) {
          *(int **)(*(int *)((int)register0x00000038 + -0x10) + 4) = piVar7;
loc_F0056A38:
          iVar4 = piVar7[1];
          goto loc_F0056A3C;
        }
        piVar1 = piVar7;
        _ipc_port_dnrequest(piVar7,*(undefined4 *)((int)register0x00000038 + -0xc),puVar11,
                            (undefined *)((int)register0x00000038 + -0x14));
        iVar4 = *(int *)((int)register0x00000038 + -0x10);
        if (piVar1 == (int *)0x0) {
          puVar11 = (uint *)0x0;
          uVar12 = *(undefined4 *)((int)register0x00000038 + -0x14);
          *(int **)(iVar4 + 4) = piVar7;
          *(undefined4 *)(iVar4 + 8) = uVar12;
          goto loc_F0056A38;
        }
        *piVar7 = 0;
        _ipc_port_release_sonce(puVar11);
        _ipc_entry_dealloc(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                           *(undefined4 *)((int)register0x00000038 + -0x10));
        param_2[2] = 0;
        do {
          do {
          } while (*piVar7 != 0);
          piVar1 = piVar7;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        if (piVar7[2] < 0) {
          piVar1 = piVar7;
          _ipc_port_dngrow();
          if (piVar1 != (int *)0x0) goto loc_F0056C30;
          do {
            do {
            } while (param_2[2] != 0);
            puVar11 = param_2 + 2;
            _simple_lock_try();
          } while (puVar11 == (uint *)0x0);
          uVar2 = param_2[3];
        }
        else {
          *piVar7 = 0;
          do {
            do {
            } while (param_2[2] != 0);
            puVar11 = param_2 + 2;
            _simple_lock_try();
          } while (puVar11 == (uint *)0x0);
          uVar2 = param_2[3];
        }
      }
      else {
        *piVar7 = 0;
        if (puVar11 != (uint *)0x0) {
          _ipc_port_release_sonce(puVar11);
        }
        puVar11 = param_2;
        _ipc_entry_grow_table();
        if (puVar11 != (uint *)0x0) {
          if (puVar11 != (uint *)0x6) goto loc_F0056C28;
loc_F0056C30:
          uVar12 = 0x1000480b;
          goto locret_F0056C88;
        }
        uVar2 = param_2[3];
      }
    }
  }
  param_2[2] = 0;
loc_F0056C28:
  uVar12 = 0x1000600b;
locret_F0056C88:
  return CONCAT44(param_2,uVar12);
}

