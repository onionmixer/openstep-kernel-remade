
int _core(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined uVar7;
  int iVar5;
  int iVar6;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined *puVar13;
  int iStack_ee;
  undefined auStack_da [4];
  undefined auStack_d6 [4];
  undefined auStack_d2 [4];
  undefined auStack_ce [4];
  uint uStack_ca;
  uint uStack_c6;
  int iStack_c2;
  int iStack_be;
  undefined4 *puStack_ba;
  uint uStack_b6;
  int iStack_b2;
  int aiStack_ae [20];
  undefined auStack_5e [32];
  undefined4 uStack_3e;
  undefined2 uStack_3a;
  sword sStack_2c;
  undefined4 uStack_2a;
  
  if ((*(byte *)(*_active_u + 0x28) & 2) == 0) {
    *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 2) =
         *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 6);
    *(undefined2 *)(*_active_u + 0x2c) = *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 6);
    *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 4) =
         *(undefined2 *)(*(int *)((int)_active_u + 0x1a) + 8);
    *(undefined *)(_active_u + 0x95) = 0;
    iVar8 = *(int *)(_active_threads + 0xc);
    iVar1 = *(int *)(iVar8 + 8);
    if (*(uint *)(iVar1 + 0x24) < *(uint *)((int)_active_u + 0x276)) {
      _task_halt(iVar8);
      *(undefined *)(dword_40B57D4 + 100) = 0;
      _vattr_null(&uStack_3e);
      uStack_3e = 1;
      uStack_3a = 0x1a4;
      _sprintf(auStack_5e,aCoresCoreD,(int)*(sword *)(*_active_u + 0x30));
      uVar7 = _vn_create(auStack_5e,1,&uStack_3e,0,0x80,&iStack_b2,
                         *(undefined4 *)((int)_active_u + 0x1a));
      *(undefined *)(dword_40B57D4 + 100) = uVar7;
      if (*(char *)(dword_40B57D4 + 100) != '\0') {
        *(undefined *)(dword_40B57D4 + 100) = 0;
        _vattr_null(&uStack_3e);
        uStack_3e = 1;
        uStack_3a = 0x1a4;
        uVar7 = _vn_create(&aCore,1,&uStack_3e,0,0x80,&iStack_b2,
                           *(undefined4 *)((int)_active_u + 0x1a));
        *(undefined *)(dword_40B57D4 + 100) = uVar7;
        if (*(char *)(dword_40B57D4 + 100) != '\0') {
          return 0;
        }
      }
      if (sStack_2c == 1) {
        _vattr_null(&uStack_3e);
        uStack_2a = 0;
        (**(code **)(*(int *)(iStack_b2 + 0x1c) + 0x18))
                  (iStack_b2,&uStack_3e,*(undefined4 *)((int)_active_u + 0x1a));
        *(word *)((int)_active_u + 0x23a) = *(word *)((int)_active_u + 0x23a) | 8;
        iVar10 = *(int *)(iVar8 + 0x20);
        iVar2 = *(int *)(iVar1 + 0x18);
        uStack_b6 = 0x14;
        iVar5 = _thread_getstatus(_active_threads,0,aiStack_ae,&uStack_b6);
        if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aCoreFlavorList);
        }
        uStack_b6 = uStack_b6 >> 1;
        iStack_ee = 0;
        uVar9 = 0;
        if (uStack_b6 != 0) {
          do {
            iStack_ee = iStack_ee + 8 + aiStack_ae[uVar9 * 2 + 1] * 4;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uStack_b6);
        }
        iVar5 = iVar10 * iStack_ee + (iVar10 + iVar2 * 7) * 8;
        iVar4 = iVar5 + 0x1c;
        _kmem_alloc_wired(_kernel_map,&puStack_ba,iVar4);
        *puStack_ba = 0xfeedface;
        puStack_ba[1] = dword_40B5DCC;
        puStack_ba[2] = dword_40B5DD0;
        puStack_ba[3] = 4;
        puStack_ba[4] = iVar10 + iVar2;
        puStack_ba[5] = iVar5;
        iVar5 = 0x1c;
        uVar9 = ~_page_mask & _page_mask + iVar4;
        iStack_be = 0;
        while ((0 < iVar2 &&
               (iVar6 = _vm_region(iVar1,&iStack_be,&iStack_c2,&uStack_c6,&uStack_ca,auStack_ce,
                                   auStack_d2,auStack_d6,auStack_da), iVar6 != 3))) {
          puVar11 = (undefined4 *)(iVar5 + (int)puStack_ba);
          *puVar11 = 1;
          puVar11[1] = 0x38;
          puVar11[6] = iStack_be;
          puVar11[7] = iStack_c2;
          puVar11[8] = uVar9;
          puVar11[9] = iStack_c2;
          puVar11[10] = uStack_ca;
          puVar11[0xb] = uStack_c6;
          puVar11[0xc] = 0;
          if ((uStack_c6 & 1) == 0) {
            _vm_protect(iVar1,iStack_be,iStack_c2,0,uStack_c6 | 1);
          }
          if ((uStack_ca & 1) != 0) {
            _vn_rdwr(1,iStack_b2,iStack_be,iStack_c2,uVar9,0,1,0);
          }
          iVar5 = iVar5 + 0x38;
          uVar9 = iStack_c2 + uVar9;
          iStack_be = iStack_c2 + iStack_be;
          iVar2 = iVar2 + -1;
        }
        iVar8 = *(int *)(iVar8 + 0x18);
        if (0 < iVar10) {
          do {
            *(undefined4 *)(iVar5 + (int)puStack_ba) = 4;
            ((undefined4 *)(iVar5 + (int)puStack_ba))[1] = iStack_ee + 8;
            iVar5 = iVar5 + 8;
            uVar9 = 0;
            piVar12 = aiStack_ae;
            puVar13 = &stack0xfffffffc;
            if (uStack_b6 != 0) {
              do {
                uVar3 = *(undefined4 *)(puVar13 + -0xa6);
                *(undefined4 *)(iVar5 + (int)puStack_ba) = *(undefined4 *)(puVar13 + -0xaa);
                *(undefined4 *)(iVar5 + 4 + (int)puStack_ba) = uVar3;
                _thread_getstatus(iVar8,*piVar12,iVar5 + 8 + (int)puStack_ba,piVar12 + 1);
                iVar5 = iVar5 + 8 + aiStack_ae[uVar9 * 2 + 1] * 4;
                uVar9 = uVar9 + 1;
                piVar12 = piVar12 + 2;
                puVar13 = puVar13 + 8;
              } while (uVar9 < uStack_b6);
            }
            iVar8 = *(int *)(iVar8 + 0x10);
            iVar10 = iVar10 + -1;
          } while (0 < iVar10);
        }
        iVar8 = _vn_rdwr(1,iStack_b2,puStack_ba,iVar4,0,1,1,0);
        _kmem_free(_kernel_map,puStack_ba,iVar4);
      }
      else {
        iVar8 = 0xe;
      }
      _vn_rele(iStack_b2);
      *(char *)(dword_40B57D4 + 100) = (char)iVar8;
      return -(int)-(iVar8 == 0);
    }
  }
  return 0;
}

