/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192790 */

void _unix_syscall(int param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int local_34;
  int local_2c;
  short *local_18;
  
  iVar4 = _active_threads;
  local_2c = 0;
  bVar1 = *(byte *)(*(int *)(_active_threads + 0x28) + 0xf0);
  if ((bVar1 & 1) != 0) {
    *(byte *)(*(int *)(_active_threads + 0x28) + 0xf0) = bVar1 & 0xfe;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
  }
  piVar2 = *(int **)(iVar4 + 0x84);
  *piVar2 = param_1;
  *(undefined1 *)(DAT_001e875c + 0x68) = 0;
  iVar4 = *(int *)(param_1 + 0x44);
  local_34 = iVar4 + 4;
  if ((int)(uint)*(ushort *)(param_1 + 0x2c) < _nsysent) {
    local_18 = (short *)(&_sysent + (uint)*(ushort *)(param_1 + 0x2c) * 8);
  }
  else {
    local_18 = &DAT_001da22c;
  }
  if (local_18 == (short *)&_sysent) {
    uVar3 = _fuword(local_34);
    local_34 = iVar4 + 8;
    if ((int)(uVar3 & 0xffff) < _nsysent) {
      local_18 = (short *)(&_sysent + (uVar3 & 0xffff) * 8);
    }
    else {
      local_18 = &DAT_001da22c;
    }
  }
  if (((int)*local_18 << 2 != 0) &&
     (local_2c = _copyin(local_34,piVar2 + 1,(int)*local_18 << 2), local_2c != 0)) {
    *(int *)(param_1 + 0x2c) = local_2c;
    *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) | 1;
    _thread_exception_return();
  }
  piVar2[0x18] = 0;
  piVar2[0x19] = *(int *)(param_1 + 0x24);
  iVar4 = _set_label(piVar2 + 10);
  if (iVar4 == 0) {
    *(undefined1 *)((int)piVar2 + 0x69) = 3;
    *(undefined1 *)(piVar2 + 0x1c) = 0;
    piVar2[0x1b] = 0;
    (**(code **)(local_18 + 2))();
    local_2c = (int)(char)piVar2[0x1a];
  }
  else if (((char)piVar2[0x1a] == '\0') && (*(char *)((int)piVar2 + 0x69) != '\x02')) {
    local_2c = 4;
  }
  _unix_syscall_return(local_2c);
  return;
}

