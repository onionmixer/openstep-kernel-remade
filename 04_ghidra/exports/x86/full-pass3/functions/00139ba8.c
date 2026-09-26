/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139ba8 */

int FUN_00139ba8(int *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 local_6;
  
  uVar4 = *(uint *)(*param_1 + 0x30);
  local_6 = *(ushort *)(uVar4 + 0x42);
  switch(*(undefined4 *)(*param_1 + 0x28)) {
  case 3:
    if (_nblkdev <= (uint)(int)(short)(local_6 >> 8)) {
      return 6;
    }
    iVar3 = (*(code *)(&_bdevsw)[(short)(local_6 >> 8) * 6])((int)(short)local_6,param_2);
    if (iVar3 != 0) {
      return iVar3;
    }
    _set_blocksize(uVar4,(int)(short)local_6);
    iVar3 = 0;
    break;
  case 4:
  case 9:
    while( true ) {
      uVar1 = local_6;
      if (_nchrdev <= local_6._1_1_) {
        return 6;
      }
      iVar3 = (int)(short)local_6;
      while (iVar2 = _isclosing(iVar3,*(undefined4 *)(*param_1 + 0x28)), iVar2 != 0) {
        _sleep(uVar4);
      }
      iVar3 = (*(code *)(&_cdevsw)[(short)(uVar1 >> 8) * 0xb])(iVar3,param_2,&local_6);
      if ((local_6 == uVar1) || (((iVar3 != 0 && (iVar3 != 0xb)) && (iVar3 != 0x11)))) break;
      iVar3 = _specvp(*param_1,(int)(short)local_6,4);
      uVar4 = *(uint *)(iVar3 + 0x30);
      _vn_rele(*param_1);
      *param_1 = iVar3;
    }
    break;
  default:
    iVar3 = 0;
    break;
  case 6:
    return 0x2d;
  case 8:
    _printf(s_spec_open__got_a_VFIFO____001dd75c);
    return 0x2d;
  }
  if (iVar3 == 0) {
    *(int *)(uVar4 + 100) = *(int *)(uVar4 + 100) + 1;
  }
  return iVar3;
}

