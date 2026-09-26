/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccfbc */

int * _class_poseAs(int *param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint local_124;
  uint local_114;
  int *local_110;
  undefined8 local_10c;
  char local_104 [256];
  
  uVar2 = __objc_headerCount();
  iVar3 = __objc_headerVector(0);
  if (param_2 != param_1) {
    if ((int *)param_1[1] == param_2) {
      if (param_1[6] == 0) {
        local_104[0] = '_';
        local_104[1] = '%';
        local_104[2] = 0;
        _strcat(local_104,(char *)param_2[2]);
        uVar9 = 0xffffffff;
        pcVar4 = local_104;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        pcVar4 = (char *)FUN_001cd3b0(~uVar9);
        _strcpy(pcVar4,local_104);
        FUN_001ccf4c(param_2);
        FUN_001ccf4c(param_1);
        uVar5 = _objc_getClasses();
        _NXHashRemove(uVar5,param_1);
        _NXHashRemove(uVar5,param_2);
        piVar6 = (int *)_object_copy(param_1,0);
        _NXHashInsert(uVar5,piVar6);
        *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) | 8;
        *(byte *)(*param_1 + 0x10) = *(byte *)(*param_1 + 0x10) | 8;
        param_1[2] = param_2[2];
        *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_2 + 8);
        param_1[3] = param_2[3];
        local_10c = _NXInitHashState(uVar5);
LAB_001cd12c:
        iVar7 = _NXNextHashState(uVar5,&local_10c,&local_110);
        if (iVar7 != 0) {
          if ((local_110 != (int *)0x0) && (local_110 != param_1)) {
            while (local_110 != piVar6) {
              if ((int *)local_110[1] == param_2) {
                local_110[1] = (int)param_1;
                *(int *)(*local_110 + 4) = *param_1;
                break;
              }
              local_110 = (int *)local_110[1];
              if ((local_110 == (int *)0x0) || (local_110 == param_1)) break;
            }
          }
          goto LAB_001cd12c;
        }
        for (local_124 = 0; local_124 < uVar2; local_124 = local_124 + 1) {
          pcVar8 = _getsectdatafromheader
                             (*(mach_header **)(iVar3 + local_124 * 0x18),"__OBJC","__cls_refs",
                              &local_114);
          if ((pcVar8 != (char *)0x0) && (uVar9 = 0, local_114 >> 2 != 0)) {
            do {
              if (*(int **)(pcVar8 + uVar9 * 4) == param_2) {
                *(int **)(pcVar8 + uVar9 * 4) = param_1;
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < local_114 >> 2);
          }
        }
        param_2[2] = (int)(pcVar4 + 1);
        *(char **)(*param_2 + 8) = pcVar4;
        _NXHashInsert(uVar5,param_1);
        _NXHashInsert(uVar5,param_2);
      }
      else {
        param_1 = (int *)_objc_msgSend(param_1,PTR_s_error__001f9d20,
                                       "[%s poseAs:%s]: %s defines new instance variables",
                                       param_1[2],param_2[2],param_1[2]);
      }
    }
    else {
      param_1 = (int *)_objc_msgSend(param_1,PTR_s_error__001f9d20,
                                     "[%s poseAs:%s]: target not immediate superclass",param_1[2],
                                     param_2[2]);
    }
  }
  return param_1;
}

