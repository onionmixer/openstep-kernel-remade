
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _fc_thread(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  
  iVar9 = 0;
  piVar7 = &_fd_controller;
  do {
    piVar11 = piVar7;
    if (_fd_polling_mode == 0) {
      if ((piVar11[6] & 2U) == 0) break;
    }
    else if ((piVar11[6] & 1U) != 0) break;
    iVar9 = iVar9 + 1;
    piVar7 = (int *)((int)piVar11 + 0x262);
  } while (iVar9 < 1);
  if (iVar9 == 1) {
                    /* WARNING: Subroutine does not return */
    _panic(aFcThreadNoActi);
  }
  if (_fd_polling_mode == 0) {
    _fc_flags_bset(piVar11,2);
    _thread_wakeup_prim(piVar11 + 6,0,0);
  }
  piVar7 = piVar11 + 3;
  do {
    while( true ) {
      if (piVar7 == (int *)*piVar7) {
        do {
          _fc_flags_bclr(piVar11,1);
          _fd_thread_block(piVar11 + 6,1,piVar11 + 5);
        } while (piVar11 + 3 == (int *)piVar11[3]);
      }
      iVar9 = piVar11[3];
      piVar1 = *(int **)(iVar9 + 0x12a);
      piVar2 = *(int **)(iVar9 + 0x12e);
      if (piVar1 == piVar7) {
        piVar11[4] = (int)piVar2;
      }
      else {
        *(int **)((int)piVar1 + 0x12e) = piVar2;
      }
      if (piVar2 == piVar7) {
        *piVar7 = (int)piVar1;
      }
      else {
        *(int **)((int)piVar2 + 0x12a) = piVar1;
      }
      piVar11[7] = iVar9 + 0x60;
      if (*(int *)(iVar9 + 0x66) == 0x80) {
        puVar5 = (undefined4 *)((int)piVar11 + 0x256);
        puVar3 = (undefined4 *)*puVar5;
        while (puVar6 = puVar3, puVar6 != puVar5) {
          puVar3 = *(undefined4 **)((int)puVar6 + 0x12a);
          if (puVar6[1] == 0) {
            puVar4 = *(undefined4 **)((int)puVar6 + 0x12e);
            if (puVar3 == puVar5) {
              *(undefined4 **)((int)piVar11 + 0x25a) = puVar4;
            }
            else {
              *(undefined4 **)((int)puVar3 + 0x12e) = puVar4;
            }
            if (puVar4 == puVar5) {
              *puVar5 = puVar3;
            }
            else {
              *(undefined4 **)((int)puVar4 + 0x12a) = puVar3;
            }
            if (piVar11 == (int *)(&dword_40C3704)[puVar6[1] * 10]) {
              piVar1 = (int *)piVar11[4];
              if (piVar1 == piVar7) {
                *piVar1 = (int)puVar6;
              }
              else {
                *(undefined4 **)((int)piVar1 + 0x12a) = puVar6;
              }
              *(int **)((int)puVar6 + 0x12e) = piVar1;
              *(int **)((int)puVar6 + 0x12a) = piVar11 + 3;
              piVar11[4] = (int)puVar6;
            }
            else {
              _fc_start(puVar6);
            }
          }
        }
        goto loc_406CD2A;
      }
      if (*(int *)(iVar9 + 0x66) == 0x81) {
        puVar5 = (undefined4 *)((int)piVar11 + 0x256);
        puVar3 = (undefined4 *)*puVar5;
        while (puVar6 = puVar3, puVar6 != puVar5) {
          puVar3 = *(undefined4 **)((int)puVar6 + 0x12a);
          if ((*(byte *)((int)puVar6 + 0x127) & 0x10) != 0) {
            puVar4 = *(undefined4 **)((int)puVar6 + 0x12e);
            if (puVar3 == puVar5) {
              *(undefined4 **)((int)piVar11 + 0x25a) = puVar4;
            }
            else {
              *(undefined4 **)((int)puVar3 + 0x12e) = puVar4;
            }
            if (puVar4 == puVar5) {
              *puVar5 = puVar3;
            }
            else {
              *(undefined4 **)((int)puVar4 + 0x12a) = puVar3;
            }
            *(undefined4 *)((int)puVar6 + 0x9e) = 0x14;
            _fd_intr(puVar6);
          }
        }
        goto loc_406CD2A;
      }
      if (*(int *)(iVar9 + 4) == 0) break;
      _v2d_map(iVar9);
    }
    *(undefined *)(iVar9 + 0xb8) = byte_40C3703;
    *(undefined4 *)(iVar9 + 0x9e) = 0xffffffff;
    *(undefined4 *)(iVar9 + 0xa2) = 0;
    *(undefined4 *)(iVar9 + 0xa6) = 0;
    *(undefined4 *)(iVar9 + 0xaa) = 0;
    _fc_flags_bclr(piVar11,0x140d8);
    iVar8 = sub_406D476(piVar11,60000000);
    if (iVar8 != 0) {
loc_406CB92:
      *(int *)(iVar9 + 0x9e) = iVar8;
      goto loc_406CD0C;
    }
    if ((*(char *)(iVar9 + 0xb8) == '\x01') && ((*(byte *)*piVar11 & 0x40) != 0)) {
      *(undefined4 *)(iVar9 + 0x9e) = 5;
      goto loc_406CD2A;
    }
    uVar10 = (uint)*(sword *)(dword_40C3710 + 0xc);
    if ((-1 < (int)uVar10) && (*(int *)(iVar9 + 0x82) != 0)) {
      _dk_busy = 1 << (uVar10 & 0x3f) | _dk_busy;
      *(int *)(_dk_xfer + uVar10 * 4) = *(int *)(_dk_xfer + uVar10 * 4) + 1;
      *(int *)(_dk_seek + uVar10 * 4) = *(int *)(_dk_seek + uVar10 * 4) + 1;
      *(uint *)(_dk_wds + uVar10 * 4) =
           (*(uint *)(iVar9 + 0x82) >> 6) + *(int *)(_dk_wds + uVar10 * 4);
    }
    if (((piVar11[6] & 0x400U) != 0) && (iVar8 = _fc_82077_reset(piVar11,0), iVar8 != 0))
    goto loc_406CB92;
    if (3 < *(byte *)(iVar9 + 0xb8)) {
      *(undefined4 *)(iVar9 + 0x9e) = 5;
      goto loc_406CCB4;
    }
    iVar8 = *piVar11;
    *(byte *)(iVar8 + 2) =
         *(byte *)(iVar9 + 0xb8) | *(byte *)(iVar8 + 2) & 0xfc | *(byte *)(iVar8 + 2);
    switch(*(undefined4 *)(piVar11[7] + 6)) {
    case :
      _fc_cmd_xfr(piVar11,&_fd_drive);
      break;
    case :
      _DAT_40c371c = _DAT_40c371c | 4;
      _fc_eject(piVar11);
      (&dword_40C3708)[*(int *)(iVar9 + 4) * 10] = 0;
      *(undefined4 *)(iVar9 + 4) = 1;
      _DAT_40c371c = _DAT_40c371c & 0xfffffffb;
      break;
    case :
      _fc_motor_on(piVar11);
      goto loc_406CC4A;
    case :
      _fc_motor_off(piVar11);
loc_406CC4A:
      *(undefined4 *)(piVar11[7] + 0x3e) = 0;
      break;
    case :
      _fc_motor_on(piVar11);
      *(undefined4 *)(iVar9 + 0x9e) = 0;
      break;
    :
      *(undefined4 *)(iVar9 + 0x9e) = 4;
    }
    if ((piVar11[6] & 0x10U) != 0) {
      _fc_stop_timer(piVar11);
    }
    sub_406D0C0(piVar11,piVar11[7]);
    if (((byte)(0x10 << (*(byte *)(piVar11[7] + 0x58) & 0x3f)) & *(byte *)(*piVar11 + 2)) == 0) {
      _DAT_40c371c = _DAT_40c371c & 0xfffffffd;
    }
    else {
      _DAT_40c371c = _DAT_40c371c | 2;
    }
loc_406CCB4:
    _fc_flags_bclr(piVar11,0x80);
    if (*(int *)(iVar9 + 0x9e) == 1) {
      _fc_82077_reset(piVar11,aCommandTimeout);
    }
    if (*(int *)(iVar9 + 0x9e) == 10) {
      _fc_82077_reset(piVar11,aBadControllerP);
    }
    if ((piVar11[6] & 0x400U) != 0) {
      _fc_82077_reset(piVar11,aControllerHang);
    }
loc_406CD0C:
    if ((*(byte *)((int)piVar11 + 0x251) & 1) != 0) {
      _sfa_relinquish(*(undefined4 *)((int)piVar11 + 0x23a),(int)piVar11 + 0x23e,2);
    }
loc_406CD2A:
    _fd_intr(iVar9);
    if (_fd_polling_mode != 0) {
      return;
    }
  } while( true );
}

