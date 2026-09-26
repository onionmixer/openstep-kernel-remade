/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010a384 */

int _uiomove(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 0;
  do {
    while( true ) {
      if (((int)param_2 < 1) || (param_4[5] == 0)) {
        return iVar2;
      }
      piVar1 = (int *)*param_4;
      uVar3 = piVar1[1];
      if (uVar3 != 0) break;
      *param_4 = piVar1 + 2;
      param_4[1] = param_4[1] + -1;
    }
    if (param_2 < uVar3) {
      uVar3 = param_2;
    }
    iVar4 = param_4[3];
    if (iVar4 == 1) {
      if (param_3 == 0) {
        iVar2 = param_1;
        iVar4 = *piVar1;
      }
      else {
        iVar2 = *piVar1;
        iVar4 = param_1;
      }
      iVar2 = _copywithin(iVar2,iVar4,uVar3);
    }
    else if (iVar4 < 2) {
      if (iVar4 == 0) {
LAB_0010a3d5:
        if (param_3 == 0) {
          iVar2 = _copyout(param_1,*piVar1,uVar3);
        }
        else {
          iVar2 = _copyin(*piVar1,param_1,uVar3);
        }
        if (iVar2 != 0) {
          return iVar2;
        }
      }
    }
    else if (iVar4 == 2) goto LAB_0010a3d5;
    *piVar1 = *piVar1 + uVar3;
    piVar1[1] = piVar1[1] - uVar3;
    param_4[5] = param_4[5] - uVar3;
    param_4[2] = param_4[2] + uVar3;
    param_1 = param_1 + uVar3;
    param_2 = param_2 - uVar3;
  } while( true );
}

