/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014f100 */

undefined8 _ipc_right_copyin_check(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar2 = *param_3;
  switch(param_4) {
  case 0x10:
  case 0x14:
  case 0x15:
    uVar2 = uVar2 & 0x20000;
joined_r0x0014f18f:
    if (uVar2 == 0) {
LAB_0014f140:
      uVar4 = 0;
      goto LAB_0014f1af;
    }
    break;
  case 0x11:
  case 0x12:
  case 0x13:
    if ((uVar2 & 0x100000) == 0) {
      if ((uVar2 & 0x50000) != 0) {
        piVar3 = (int *)param_3[1];
        do {
          do {
          } while (*piVar3 != 0);
          LOCK();
          iVar1 = *piVar3;
          *piVar3 = 1;
          UNLOCK();
        } while (iVar1 == 1);
        LOCK();
        param_3 = (uint *)*piVar3;
        *piVar3 = 0;
        UNLOCK();
        if (piVar3[2] < 0) {
          if (param_4 == 0x12) {
            uVar2 = uVar2 & 0x40000;
          }
          else {
            uVar2 = uVar2 & 0x10000;
          }
          goto joined_r0x0014f18f;
        }
        if ((uVar2 & 0x400000) == 0) break;
      }
      goto LAB_0014f140;
    }
    break;
  default:
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_right_copyin_check__strange_r_001de9b7);
  }
  uVar4 = 1;
LAB_0014f1af:
  return CONCAT44(param_3,uVar4);
}

