/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae348 */

void FUN_001ae348(int param_1,undefined4 param_2,undefined4 *param_3,char *param_4)

{
  char *pcVar1;
  char local_7c [80];
  char local_2c [4];
  ushort local_28;
  
  local_7c[0] = '\0';
  switch(*param_3) {
  case 0:
    builtin_strncpy(local_2c,"Read",4);
    local_28 = local_28 & 0xff00;
    break;
  case 1:
    builtin_strncpy(local_2c,"Writ",4);
    local_28 = 0x65;
    break;
  case 2:
  case 3:
    pcVar1 = (char *)_IOFindNameForValue(*(undefined1 *)(param_3[5] + 2),&_IOSCSIOpcodeStrings);
    _strcpy(local_2c,pcVar1);
    goto LAB_001ae459;
  case 4:
    builtin_strncpy(local_2c,"Ejec",4);
    local_28 = 0x74;
    goto LAB_001ae459;
  default:
                    /* WARNING: Subroutine does not return */
    _panic("Bogus op in logOpInfo");
  }
  if ((param_4 == (char *)0x0) || (-1 < *param_4)) {
    _sprintf(local_7c,"block:%d blockCount:%d",param_3[1],param_3[2]);
  }
  else {
    _sprintf(local_7c,"block:%d",
             CONCAT31((uint3)(((uint)(ushort)((ushort)(((uint)(byte)param_4[3] << 0x18) >> 0x10) |
                                             (ushort)(byte)param_4[4]) << 0x10) >> 8) |
                      (uint3)(byte)param_4[5],param_4[6]));
  }
LAB_001ae459:
  _IOLog("   target:%d lun:%d op:%s %s\n",*(undefined1 *)(param_1 + 0x188),
         *(undefined1 *)(param_1 + 0x189),local_2c,local_7c);
  return;
}

