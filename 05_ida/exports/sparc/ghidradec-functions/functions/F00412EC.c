
/* WARNING: Removing unreachable block (ram,0xf00415f0) */
/* WARNING: Removing unreachable block (ram,0xf00415a4) */
/* WARNING: Removing unreachable block (ram,0xf0041584) */
/* WARNING: Removing unreachable block (ram,0xf004157c) */
/* WARNING: Removing unreachable block (ram,0xf00414e4) */
/* WARNING: Removing unreachable block (ram,0xf0041398) */
/* WARNING: Removing unreachable block (ram,0xf00414b8) */
/* WARNING: Removing unreachable block (ram,0xf0041480) */
/* WARNING: Removing unreachable block (ram,0xf00413e0) */
/* WARNING: Removing unreachable block (ram,0xf0041388) */
/* WARNING: Removing unreachable block (ram,0xf00413c8) */
/* WARNING: Removing unreachable block (ram,0xf00413f4) */
/* WARNING: Removing unreachable block (ram,0xf00414c4) */
/* WARNING: Removing unreachable block (ram,0xf004149c) */
/* WARNING: Removing unreachable block (ram,0xf00414f4) */
/* WARNING: Removing unreachable block (ram,0xf0041554) */
/* WARNING: Removing unreachable block (ram,0xf0041570) */
/* WARNING: Removing unreachable block (ram,0xf004158c) */
/* WARNING: Removing unreachable block (ram,0xf0041600) */
/* WARNING: Removing unreachable block (ram,0xf004161c) */
/* WARNING: Removing unreachable block (ram,0xf0041338) */

undefined8 sub_F00412EC(int *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  sword *psVar5;
  uint uVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
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
  iVar9 = 0;
  iVar7 = param_1[0xc];
  if (((_active_threads == _pageoutThread) && ((*(word *)(iVar7 + 0x60) & 1) != 0)) &&
     (*(int *)(*(int *)(iVar7 + 0x68) + 0x198) != 0)) {
    uVar10 = 2;
  }
  else {
    iVar4 = iVar7;
    _rlock_timeout(iVar7,5);
    if (iVar4 == 1) {
      uVar10 = 2;
    }
    else {
      psVar5 = *(sword **)(*param_1 + 0x30);
      uVar8 = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x24);
      if (psVar5 == (sword *)0x0) {
        if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) == 0) {
          _printf(aNfsFailureOnPa_0);
loc_F004158C:
          _runlock(iVar7);
          uVar10 = 2;
          goto locret_F0041628;
        }
        psVar5 = (sword *)_active_u[7];
      }
      *psVar5 = *psVar5 + 1;
      if (*(int *)(iVar7 + 0x70) == 0) {
        *(sword **)(iVar7 + 0x70) = psVar5;
      }
      else {
        _crfree();
        *(sword **)(iVar7 + 0x70) = psVar5;
      }
      do {
        uVar1 = param_4;
        .udiv(param_4,uVar8);
        uVar2 = param_4;
        .urem(param_4,uVar8);
        uVar6 = param_3;
        if (uVar8 - uVar2 < param_3) {
          uVar6 = uVar8 - uVar2;
        }
        (**(code **)(param_1[7] + 0x50))
                  (param_1,uVar1,(undefined *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0x10));
        if (*(sword *)(iVar7 + 0x62) != 0) {
          *(int *)(*param_1 + 0x34) = (int)*(sword *)(iVar7 + 0x62);
          if (*(sword *)(*param_1 + 4) == 0) {
            if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
              _printf(aSD_2,_active_u + 2,(int)*(sword *)(*_active_u + 0x30));
            }
            if (*(sword *)(iVar7 + 0x62) == 0x1c) {
              _printf(aNfsWriteErrorO_0);
              *(undefined2 *)(iVar7 + 0x62) = 0;
            }
            else if (*(sword *)(iVar7 + 0x62) == 0x46) {
              _printf(aNfsWriteErrorO_1);
            }
            else {
              _printf(aNfsWriteErrorD_0);
            }
          }
          goto loc_F004158C;
        }
        iVar4 = *(int *)((int)register0x00000038 + -0x10);
        if (iVar4 < 0) {
          _printf(aNfsMappingErro);
          goto loc_F004158C;
        }
        puVar3 = *(uint **)((int)register0x00000038 + -0xc);
        if (uVar6 == uVar8) {
          _getblk(puVar3,iVar4,uVar6);
        }
        else {
          _bread(puVar3,iVar4,uVar8);
        }
        if ((*puVar3 & 4) != 0) {
          *(int *)(*param_1 + 0x34) = (int)*(sword *)(puVar3 + 7);
          if (*(sword *)(*param_1 + 4) == 0) {
            if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
              _printf(aSD_3,_active_u + 2,(int)*(sword *)(*_active_u + 0x30));
            }
            if (*(sword *)(puVar3 + 7) == 0x46) {
              _printf(aNfsReadErrorOn_0);
            }
            else {
              _printf(aNfsReadErrorDO_0);
            }
          }
          _brelse(puVar3);
          goto loc_F004158C;
        }
        _copy_from_phys(param_2 + iVar9,puVar3[8] + uVar2,uVar6);
        param_4 = param_4 + uVar6;
        if (*(uint *)(iVar7 + 0x98) < param_4) {
          *(uint *)(iVar7 + 0x98) = param_4;
        }
        param_3 = param_3 - uVar6;
        iVar9 = iVar9 + uVar6;
        *(word *)(iVar7 + 0x60) = *(word *)(iVar7 + 0x60) | 0x10;
        if (uVar6 + uVar2 == uVar8) {
          *puVar3 = *puVar3 | 0x400000;
          _bawrite();
        }
        else {
          _bdwrite(puVar3);
        }
      } while ((param_3 != 0) && (uVar6 != 0));
      _runlock(iVar7);
      uVar10 = 0;
    }
  }
locret_F0041628:
  return CONCAT44(param_2,uVar10);
}
