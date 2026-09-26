
void _od_ctrl_start(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  int *piVar8;
  
  iVar5 = *(sword *)(param_1 + 4) * 0x28c;
  piVar8 = (int *)0x0;
  if (*(int *)(param_1 + 0x20) == 0) {
    while( true ) {
      piVar2 = *(int **)(param_1 + 0x18);
      piVar4 = (int *)(param_1 + 0x18);
      if (piVar2 == piVar4) break;
      puVar6 = (undefined *)_disksort_first(piVar2);
      if (puVar6 == (undefined *)0x0) {
        piVar1 = (int *)*piVar2;
        piVar2 = (int *)piVar2[1];
        if (piVar1 == piVar4) {
          *(int **)(param_1 + 0x1c) = piVar2;
        }
        else {
          piVar1[1] = (int)piVar2;
        }
        *piVar2 = (int)piVar1;
      }
      else {
        *(byte *)(piVar2 + 3) = *(byte *)(piVar2 + 3) | 0x10;
        iVar7 = (sword)(word)((uint)*(undefined4 *)(puVar6 + 0x1f) >> 0x1b) * 0xda;
        if (piVar2 == piVar8) {
          if (_od_runout == 0) {
            _timeout(_od_run_out,param_1,(int)_od_runout_time);
            _od_runout = 1;
            return;
          }
          if (_od_runout == 1) {
            return;
          }
          _od_runout = 0;
          if (_hz * 0x14 == (int)_od_runout_time) {
            iVar5 = _hz;
            if (_hz < 0) {
              iVar5 = _hz + 1;
            }
            _od_runout_time = (sword)(iVar5 >> 1);
          }
          if (_od_requested != 0) {
            _od_runout = 0;
            return;
          }
          if (_od_spinup != 0) {
            _od_runout = 0;
            return;
          }
          _od_requested = 1;
          _wakeup(&_od_requested);
          return;
        }
        if (((DAT_40c3f32 + iVar7 == puVar6) &&
            ((*(sword *)(DAT_40c3f32 + iVar7 + 0x6a) == 0xf1 ||
             (*(sword *)(DAT_40c3f32 + iVar7 + 0x6a) == 0xf6)))) ||
           ((DAT_40c3fa1[iVar7] & 0x40) == 0)) {
          if (_od_runout != 0) {
            if (DAT_40c3f32 + iVar7 == puVar6) {
              iVar7 = _hz;
              if (_hz < 0) {
                iVar7 = _hz + 1;
              }
              if (iVar7 >> 1 != (int)_od_runout_time) goto loc_4075854;
            }
            if (_hz * 0x14 == (int)_od_runout_time) {
              iVar7 = _hz;
              if (_hz < 0) {
                iVar7 = _hz + 1;
              }
              _od_runout_time = (sword)(iVar7 >> 1);
            }
            if (_od_runout == 1) {
              _untimeout(_od_run_out,param_1);
            }
            _od_runout = 0;
          }
loc_4075854:
          *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
          *(code **)(DAT_40c3dfc + iVar5 + 4) = _od_go;
          *(int *)(DAT_40c3dfc + iVar5 + 8) = param_1;
          _sfa_arbitrate(*(undefined4 *)(DAT_40c3dfc + iVar5),iVar5 + 0x40c3e00);
          return;
        }
        piVar1 = (int *)*piVar2;
        puVar3 = (undefined4 *)piVar2[1];
        if (piVar1 == piVar4) {
          *(undefined4 **)(param_1 + 0x1c) = puVar3;
        }
        else {
          piVar1[1] = (int)puVar3;
        }
        *puVar3 = piVar1;
        puVar3 = *(undefined4 **)(param_1 + 0x1c);
        *puVar3 = piVar2;
        piVar2[1] = (int)puVar3;
        *piVar2 = param_1 + 0x18;
        *(int **)(param_1 + 0x1c) = piVar2;
        if (piVar8 == (int *)0x0) {
          piVar8 = piVar2;
        }
      }
    }
  }
  return;
}
