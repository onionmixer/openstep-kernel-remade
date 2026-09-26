
int * sub_40297DA(int param_1,int *param_2,int *param_3)

{
  sword *psVar1;
  byte *pbVar2;
  bool bVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  undefined *puVar9;
  int **ppiVar10;
  int *piStack_18c;
  int iStack_16a;
  int iStack_166;
  char acStack_162 [32];
  int iStack_142;
  int *piStack_13e;
  int aiStack_136 [8];
  undefined auStack_116 [258];
  undefined auStack_14 [16];
  
  piStack_18c = param_3;
  _getfsname(&aRoot);
  _pn_alloc(&iStack_142);
  piVar7 = piStack_13e;
  bVar3 = false;
  ppiVar10 = (int **)&stack0xfffffe78;
  while( true ) {
    piStack_18c = piVar7;
    piVar4 = (int *)&aRoot;
    if (*(char *)param_3 != '\0') {
      piVar4 = param_3;
    }
    piVar4 = (int *)sub_402A078(piVar4,auStack_116,auStack_14);
    if (piVar4 != (int *)0x3c) break;
    if (!bVar3) {
      piStack_18c = (int *)&aRoot;
      if (*(char *)param_3 != '\0') {
        piStack_18c = param_3;
      }
      _printf(off_40AEE7A);
      bVar3 = true;
    }
  }
  if (piVar4 == (int *)0x0) {
    if (bVar3) {
      piStack_18c = (int *)aBootparamRespo;
      _printf();
    }
    piStack_18c = aiStack_136;
    piVar4 = (int *)sub_402A1E8(auStack_14,auStack_116,piVar7);
    if (piVar4 == (int *)0x0) {
      piStack_18c = (int *)0x0;
      piVar4 = (int *)sub_402A56C(&iStack_166,param_1,auStack_14,aiStack_136,auStack_116,0,
                                  0xffffffff);
      if (piVar4 == (int *)0x0) {
        piStack_18c = (int *)0x0;
        piVar4 = (int *)_vfs_add(0,param_1);
        if (piVar4 == (int *)0x0) {
          *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x5e) = 0xe10;
          *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x62) = 36000;
          *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x66) = 0xe10;
          *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x6a) = 36000;
          pbVar2 = (byte *)(*(int *)(param_1 + 0x126) + 0x14);
          *pbVar2 = *pbVar2 | 4;
          piStack_18c = *(int **)(iStack_166 + 0x24);
          _vfs_unlock();
          *param_2 = iStack_166;
          puVar5 = (undefined *)_strcpy(param_3,auStack_116);
          *puVar5 = 0x3a;
          _strcpy(puVar5 + 1,piVar7);
          acStack_162[0] = '\0';
          _getfsname(&aPrivate,acStack_162);
          bVar3 = false;
          while( true ) {
            piStack_18c = piVar7;
            pcVar8 = "private";
            if (acStack_162[0] != '\0') {
              pcVar8 = acStack_162;
            }
            piVar4 = (int *)sub_402A078(pcVar8,auStack_116,auStack_14);
            if (piVar4 != (int *)0x3c) break;
            if (!bVar3) {
              piStack_18c = (int *)&aPrivate;
              if (acStack_162[0] != '\0') {
                piStack_18c = (int *)acStack_162;
              }
              _printf(off_40AEE7A);
              bVar3 = true;
            }
          }
          if (piVar4 == (int *)0x0) {
            if (bVar3) {
              piStack_18c = (int *)aBootparamRespo;
              _printf();
            }
            piStack_18c = (int *)0x40;
            puVar5 = (undefined *)_index(piVar7);
            if (puVar5 == (undefined *)0x0) {
              puVar9 = aPrivate_0;
            }
            else {
              puVar9 = puVar5 + 1;
              *puVar5 = 0;
            }
            piStack_18c = aiStack_136;
            piVar4 = (int *)sub_402A1E8(auStack_14,auStack_116,piVar7);
            if (piVar4 == (int *)0x0) {
              piStack_18c = &_rootdir;
              iVar6 = (**(code **)(*(int *)(_rootvfs + 4) + 8))(_rootvfs);
              if (iVar6 != 0) {
                piStack_18c = (int *)aNfsMountrootCa;
                    /* WARNING: Subroutine does not return */
                _panic();
              }
              *(undefined4 *)(_active_u + 0x156) = _rootdir;
              psVar1 = (sword *)(*(int *)(_active_u + 0x156) + 6);
              *psVar1 = *psVar1 + 1;
              *(undefined4 *)(_active_u + 0x15a) = 0;
              piStack_18c = &iStack_16a;
              piVar4 = (int *)_lookupname(puVar9,1,1,0);
              if ((piVar4 == (int *)0x0) && (iStack_16a != 0)) {
                piStack_18c = *(int **)(_active_u + 0x156);
                _vn_rele();
                _vn_rele(_rootdir);
                _dnlc_purge();
                piVar7 = (int *)_kalloc(0x12a);
                *piVar7 = 0;
                piVar7[1] = (int)_nfs_vfsops;
                piVar7[3] = 0;
                piVar7[7] = 0;
                *(undefined4 *)((int)piVar7 + 0x126) = 0;
                piVar7[0x48] = 0;
                *(undefined2 *)(piVar7 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2);
                piVar4 = (int *)sub_402A56C(&iStack_166,piVar7,auStack_14,aiStack_136,auStack_116,0,
                                            0xffffffff,0);
                if (piVar4 == (int *)0x0) {
                  piStack_18c = (int *)0x0;
                  piVar4 = (int *)_vfs_add(iStack_16a,piVar7);
                  if (piVar4 == (int *)0x0) {
                    *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x62) = 6000;
                    *(undefined4 *)(*(int *)(param_1 + 0x126) + 0x6a) = 6000;
                    piStack_18c = (int *)0xff;
                    _strncpy(param_1 + 0x20,piStack_13e);
                    _vfs_unlock(*(undefined4 *)(iStack_166 + 0x24));
                    _nfs_netboot_prealloc(*(undefined4 *)(param_1 + 0x126));
                    _pn_free(&iStack_142);
                    return (int *)0;
                  }
                  ppiVar10 = &piStack_18c;
                  piStack_18c = piVar7;
                  sub_402A788();
                }
                *(int **)((int)ppiVar10 + -4) = &iStack_142;
                *(undefined4 *)((int)ppiVar10 + -8) = 0x4029c5c;
                _pn_free();
                *(undefined4 *)((int)ppiVar10 + -8) = 0x12a;
                *(int **)((int)ppiVar10 + -0xc) = piVar7;
                *(undefined4 *)((int)ppiVar10 + -0x10) = 0x4029c68;
                _kfree();
              }
              else {
                piStack_18c = (int *)aNfsMountrootNo;
                _printf();
                _vn_rele(*(undefined4 *)(_active_u + 0x156));
                _pn_free(&iStack_142);
              }
            }
            else {
              piStack_18c = &iStack_142;
              _pn_free();
              _printf(aMountPrivateSS,auStack_116,piVar7,piVar4);
            }
          }
          else {
            if (piVar4 == (int *)0x16) {
              piStack_18c = (int *)aUsingPrivateFr;
              _printf();
              piVar4 = (int *)0x0;
            }
            else {
              piStack_18c = piVar4;
              _printf(aRpcErrorDuring);
            }
            piStack_18c = &iStack_142;
            _pn_free();
          }
        }
        else {
          piStack_18c = &iStack_142;
          _pn_free();
        }
      }
      else {
        piStack_18c = &iStack_142;
        _pn_free();
      }
    }
    else {
      piStack_18c = &iStack_142;
      _pn_free();
      _printf(aMountRootSSFai,auStack_116,piVar7,piVar4);
    }
  }
  else {
    piStack_18c = piVar4;
    _printf(aRpcErrorDuring);
    _pn_free(&iStack_142);
  }
  return piVar4;
}
