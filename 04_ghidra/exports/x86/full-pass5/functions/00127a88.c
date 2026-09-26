/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00127a88 */

undefined4 _ip_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = *(int *)(param_2 + 8);
  if (param_3 == 0) {
    if (param_1 == 0) {
      if (param_4 == 1) {
        iVar2 = _m_get(1,10);
        *param_5 = iVar2;
        if (*(int *)(iVar1 + 0x38) == 0) {
          *(undefined2 *)(iVar2 + 8) = 0;
        }
        else {
          *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(*(int *)(iVar1 + 0x38) + 4);
          *(undefined2 *)(*param_5 + 8) = *(undefined2 *)(*(int *)(iVar1 + 0x38) + 8);
          iVar2 = *param_5;
          _bcopy((void *)(*(int *)(iVar1 + 0x38) + *(int *)(*(int *)(iVar1 + 0x38) + 4)),
                 (void *)(iVar2 + *(int *)(iVar2 + 4)),(int)*(short *)(iVar2 + 8));
        }
        goto LAB_00127b71;
      }
      if (((0 < param_4) && (param_4 < 8)) && (2 < param_4)) {
        uVar3 = _ip_getmoptions(param_4,*(undefined4 *)(iVar1 + 0x3c),param_5);
        goto LAB_00127b71;
      }
    }
    else {
      if (param_1 != 1) {
        return 0;
      }
      if (param_4 == 1) {
        uVar3 = _ip_pcbopts(iVar1 + 0x38,*param_5);
        return uVar3;
      }
      if (((0 < param_4) && (param_4 < 8)) && (2 < param_4)) {
        uVar3 = _ip_setmoptions(param_4,iVar1 + 0x3c,*param_5);
        goto LAB_00127b71;
      }
    }
  }
  uVar3 = 0x16;
LAB_00127b71:
  if ((param_1 == 1) && (*param_5 != 0)) {
    _m_free(*param_5);
  }
  return uVar3;
}

