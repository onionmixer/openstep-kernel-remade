/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9284 */

int __regparm1 _IOConvertPort(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  
  if (param_3 == 1) {
    iVar1 = __io_get_kern_port(param_2);
  }
  else {
    iVar1 = param_2;
    if (((param_3 != 0) && (iVar1 = param_1, param_3 == 2)) &&
       (iVar1 = __io_convert_port_in(param_2), iVar1 == 0)) {
      _IOLog("IOConvertPort: Bad Port\n");
      return 0;
    }
  }
  if (param_4 == 1) {
    iVar2 = __io_task_get_port(iVar1);
  }
  else {
    iVar2 = iVar1;
    if ((param_4 != 0) && (iVar2 = unaff_EBX, param_4 == 2)) {
      iVar2 = __io_convert_port_out(iVar1);
    }
  }
  return iVar2;
}

