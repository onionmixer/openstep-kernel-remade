/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143b64 */

int FUN_00143b64(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  int local_8;
  
  iVar1 = _lookupname(param_1,0,1,0,&local_8);
  if (iVar1 == 0) {
    if (*(int *)(local_8 + 0x28) == 3) {
      *param_2 = *(undefined2 *)(local_8 + 0x2c);
      _vn_rele(local_8);
      if ((int)(uint)*(byte *)((int)param_2 + 1) < _nblkdev) {
        iVar1 = 0;
      }
      else {
        iVar1 = 6;
      }
    }
    else {
      _vn_rele(local_8);
      iVar1 = 0xf;
    }
  }
  else if (*(char *)(DAT_001e875c + 0x68) == '\x02') {
    iVar1 = 0x13;
  }
  return iVar1;
}

