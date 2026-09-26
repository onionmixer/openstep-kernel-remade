/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012ee3c */

void FUN_0012ee3c(int *param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 < 2) && (-1 < *piVar1)) {
    for (puVar2 = (undefined2 *)&_unixauthtab; puVar2 < &_unixauthtab + _MAXCLIENTS * 8;
        puVar2 = puVar2 + 4) {
      if (*(int **)(puVar2 + 2) == piVar1) {
        *puVar2 = 0;
        goto LAB_0012eeac;
      }
    }
    (**(code **)(piVar1[8] + 0x10))(piVar1);
  }
  else {
    _printf(s_authfree__unknown_authflavor__d_001dc2ec,*piVar1);
  }
LAB_0012eeac:
  _clntkudp_freecred(param_1);
  *param_1 = 0;
  puVar3 = &_chtable;
  while( true ) {
    if (&_chtable + _MAXCLIENTS * 3 <= puVar3) {
      (**(code **)(param_1[1] + 0x10))(param_1);
      return;
    }
    if ((int *)puVar3[2] == param_1) break;
    puVar3 = puVar3 + 3;
  }
  puVar3[1] = 0;
  return;
}

