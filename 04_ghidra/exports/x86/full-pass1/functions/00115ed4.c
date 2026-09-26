/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00115ed4 */

undefined4 _sogetopt(short *param_1,int param_2,uint param_3,int *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 != 0xffff) {
    if ((*(int *)(param_1 + 6) != 0) &&
       (pcVar1 = *(code **)(*(int *)(param_1 + 6) + 0x18), pcVar1 != (code *)0x0)) {
      uVar2 = (*pcVar1)(0,param_1,param_2,param_3,param_4);
      return uVar2;
    }
    return 0x2a;
  }
  iVar3 = _m_get(1,10);
  *(undefined2 *)(iVar3 + 8) = 4;
  if (param_3 != 0x100) {
    if (0x100 < (int)param_3) {
      if (param_3 == 0x1004) {
        *(uint *)(*(int *)(iVar3 + 4) + iVar3) = (uint)(ushort)param_1[0x16];
      }
      else if ((int)param_3 < 0x1005) {
        if (param_3 == 0x1002) {
          *(uint *)(*(int *)(iVar3 + 4) + iVar3) = (uint)(ushort)param_1[0x13];
        }
        else if ((int)param_3 < 0x1003) {
          if (param_3 != 0x1001) goto LAB_00116098;
          *(uint *)(*(int *)(iVar3 + 4) + iVar3) = (uint)(ushort)param_1[0x1f];
        }
        else {
          *(uint *)(*(int *)(iVar3 + 4) + iVar3) = (uint)(ushort)param_1[0x22];
        }
      }
      else if (param_3 == 0x1006) {
        *(int *)(*(int *)(iVar3 + 4) + iVar3) = (int)param_1[0x17];
      }
      else if ((int)param_3 < 0x1006) {
        *(int *)(*(int *)(iVar3 + 4) + iVar3) = (int)param_1[0x23];
      }
      else if (param_3 == 0x1007) {
        *(uint *)(*(int *)(iVar3 + 4) + iVar3) = (uint)(ushort)param_1[0x2b];
        param_1[0x2b] = 0;
      }
      else {
        if (param_3 != 0x1008) goto LAB_00116098;
        *(int *)(*(int *)(iVar3 + 4) + iVar3) = (int)*param_1;
      }
      goto LAB_001160a8;
    }
    if (param_3 != 0x10) {
      if ((int)param_3 < 0x11) {
        if (param_3 != 4) {
          if ((int)param_3 < 5) {
            if (param_3 != 1) goto LAB_00116098;
          }
          else if (param_3 != 8) goto LAB_00116098;
        }
      }
      else if (param_3 != 0x40) {
        if (0x40 < (int)param_3) {
          if (param_3 == 0x80) {
            *(undefined2 *)(iVar3 + 8) = 8;
            *(uint *)(*(int *)(iVar3 + 4) + iVar3) = *(byte *)(param_1 + 1) & 0x80;
            *(int *)(*(int *)(iVar3 + 4) + 4 + iVar3) = (int)param_1[2];
            goto LAB_001160a8;
          }
LAB_00116098:
          _m_free(iVar3);
          return 0x2a;
        }
        if (param_3 != 0x20) goto LAB_00116098;
      }
    }
  }
  *(uint *)(*(int *)(iVar3 + 4) + iVar3) = (int)param_1[1] & param_3;
LAB_001160a8:
  *param_4 = iVar3;
  return 0;
}

