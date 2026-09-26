
/* WARNING: Removing unreachable block (ram,0xf000dca4) */
/* WARNING: Removing unreachable block (ram,0xf000dc14) */
/* WARNING: Removing unreachable block (ram,0xf000dad4) */
/* WARNING: Removing unreachable block (ram,0xf000da38) */
/* WARNING: Removing unreachable block (ram,0xf000da50) */
/* WARNING: Removing unreachable block (ram,0xf000dba8) */
/* WARNING: Removing unreachable block (ram,0xf000dc9c) */
/* WARNING: Removing unreachable block (ram,0xf000dcdc) */
/* WARNING: Removing unreachable block (ram,0xf000da04) */

undefined8 _cloneproc(int param_1,undefined4 param_2,undefined4 *param_3)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  sword *psVar6;
  bool bVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  _mpid = _mpid + 1;
  iVar9 = *(int *)(*(int *)(param_1 + 0x68) + 0x38);
loc_F000D8EC:
  do {
    if (29999 < _mpid) {
      _mpid = 100;
      dword_F010B080 = 0;
    }
    bVar7 = false;
    if (dword_F010B080 <= _mpid) {
      dword_F010B080 = 30000;
      iVar8 = (int)_allproc;
      while( true ) {
        if (iVar8 != 0) {
          sVar1 = *(sword *)(iVar8 + 0x30);
          while( true ) {
            if ((sVar1 == _mpid) || (*(sword *)(iVar8 + 0x2e) == _mpid)) {
              _mpid = _mpid + 1;
              if (dword_F010B080 <= _mpid) goto loc_F000D8EC;
              sVar1 = *(sword *)(iVar8 + 0x30);
            }
            else {
              sVar1 = *(sword *)(iVar8 + 0x30);
            }
            iVar4 = (int)sVar1;
            if ((_mpid < iVar4) && (iVar4 < dword_F010B080)) {
              dword_F010B080 = iVar4;
            }
            iVar4 = (int)*(sword *)(iVar8 + 0x2e);
            if (_mpid < iVar4) {
              if (iVar4 < dword_F010B080) {
                dword_F010B080 = iVar4;
              }
              iVar8 = *(int *)(iVar8 + 8);
            }
            else {
              iVar8 = *(int *)(iVar8 + 8);
            }
            if (iVar8 == 0) break;
            sVar1 = *(sword *)(iVar8 + 0x30);
          }
        }
        if (bVar7) break;
        bVar7 = true;
        iVar8 = _zombproc;
      }
    }
    puVar2 = param_3;
    _insert_posix_proc(param_3,_mpid);
    if (puVar2 != (undefined4 *)0x0) {
      if (_freeproc == (undefined4 *)0x0) {
        _getproc();
        if (puVar2 == (undefined4 *)0x0) {
          _panic(aNoProcs);
        }
        puVar2[2] = _freeproc;
        puVar2[0x18] = 0;
      }
      else {
        _freeproc[0x18] = 0;
        puVar2 = _freeproc;
      }
      puVar2[0x17] = 0;
      _freeproc = (undefined4 *)puVar2[2];
      *(undefined *)((int)puVar2 + 0x13) = 4;
      puVar2[10] = *(uint *)(param_1 + 0x28) & 0x2108000 | 1;
      *(undefined2 *)(puVar2 + 0xb) = *(undefined2 *)(param_1 + 0x2c);
      puVar2[10] = puVar2[10] | *(uint *)(param_1 + 0x28) & 0x40000000;
      puVar2[5] = puVar2[5] & 0xffffbfff | *(uint *)(param_1 + 0x14) & 0x4000;
      iVar8 = (int)*(sword *)(param_1 + 0x30);
      _get_posix_proc();
      *(undefined2 *)(param_3 + 1) = *(undefined2 *)(iVar8 + 4);
      *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)(iVar8 + 6);
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(iVar8 + 8);
      param_3[4] = *(undefined4 *)(iVar8 + 0x10);
      param_3[5] = 0;
      param_3[6] = param_3[6] & 0x3fffffff;
      *(undefined2 *)((int)puVar2 + 0x2e) = *(undefined2 *)(param_1 + 0x2e);
      *(undefined *)((int)puVar2 + 0x15) = *(undefined *)(param_1 + 0x15);
      *(sword *)(puVar2 + 0xc) = (sword)*param_3;
      *(undefined2 *)((int)puVar2 + 0x32) = *(undefined2 *)(param_1 + 0x30);
      puVar2[0x11] = param_1;
      puVar2[0x13] = *(undefined4 *)(param_1 + 0x48);
      if (*(int *)(param_1 + 0x48) != 0) {
        *(undefined4 **)(*(int *)(param_1 + 0x48) + 0x50) = puVar2;
      }
      puVar2[0x14] = 0;
      puVar2[0x12] = 0;
      *(undefined4 **)(param_1 + 0x48) = puVar2;
      *(undefined *)(puVar2 + 5) = 0;
      *(undefined *)((int)puVar2 + 0x12) = 0;
      puVar2[7] = *(undefined4 *)(param_1 + 0x1c);
      puVar2[9] = *(undefined4 *)(param_1 + 0x24);
      puVar2[8] = *(undefined4 *)(param_1 + 0x20);
      puVar2[0x1f] = 0;
      puVar2[0x20] = 0;
      *(undefined2 *)(puVar2 + 0xd) = 0;
      puVar2[6] = 0;
      *(undefined *)((int)puVar2 + 0x17) = 0;
      puVar2[5] = puVar2[5] & 0xffff7fff;
      _pidhash_enter(puVar2);
      iVar4 = *(int *)(iVar9 + 0x15c);
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar9 + 0x160);
      }
      else {
        *(sword *)(iVar4 + 6) = *(sword *)(iVar4 + 6) + 1;
        iVar4 = *(int *)(iVar9 + 0x160);
      }
      if (iVar4 == 0) {
        psVar6 = *(sword **)(iVar9 + 0x1c);
      }
      else {
        *(sword *)(iVar4 + 6) = *(sword *)(iVar4 + 6) + 1;
        psVar6 = *(sword **)(iVar9 + 0x1c);
      }
      *psVar6 = *psVar6 + 1;
      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x100;
      puVar2[0x1c] = 0;
      puVar2[0x1d] = 0;
      puVar2[0x1e] = 0;
      puVar3 = puVar2;
      _procdup(puVar2,param_1);
      iVar9 = 0;
      if (*(uint *)(*(int *)(puVar2[0x1a] + 0x38) + 0x154) < 0x80000000) {
        iVar4 = *(int *)(puVar2[0x1a] + 0x38);
        while( true ) {
          iVar5 = *(int *)(*(int *)(iVar4 + 0x14c) + iVar9 * 4);
          if (iVar5 == 0) {
            iVar4 = puVar2[0x1a];
          }
          else {
            if (iVar5 == -0x10000) {
              *(undefined4 *)(*(int *)(iVar4 + 0x14c) + iVar9 * 4) = 0;
            }
            else {
              *(sword *)(iVar5 + 0xe) = *(sword *)(iVar5 + 0xe) + 1;
            }
            iVar4 = puVar2[0x1a];
          }
          iVar9 = iVar9 + 1;
          if (*(int *)(*(int *)(iVar4 + 0x38) + 0x154) < iVar9) break;
          iVar4 = *(int *)(iVar4 + 0x38);
        }
      }
      _lock_init(*(int *)(puVar2[0x1a] + 0x38) + 0x20,1);
      _uarea_init(puVar3);
      param_3[3] = *(undefined4 *)(iVar8 + 0xc);
      *(undefined4 **)(iVar8 + 0xc) = puVar2;
      puVar2[2] = _allproc;
      *(undefined4 **)((int)_allproc + 0xc) = puVar2 + 2;
      puVar2[3] = &_allproc;
      _allproc = puVar2;
      *(undefined *)((int)puVar2 + 0x13) = 3;
      _spl0();
      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffeff;
      return CONCAT44(param_2,puVar3);
    }
    _mpid = _mpid + 1;
  } while( true );
}

