/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016edcc */

void FUN_0016edcc(int *param_1,uint *param_2)

{
  int iVar1;
  processor_set_name_t pVar2;
  host_priv_t host_priv;
  uint uVar3;
  processor_set_name_t set_name;
  processor_set_t *set;
  processor_set_t local_8;
  
  if (((param_1[1] == 0x20) && (*param_1 < 0)) && ((param_1[6] & 0x3fffffffU) == 0x10012011)) {
    pVar2 = _convert_port_to_pset_name(param_1[7]);
    set = &local_8;
    set_name = pVar2;
    host_priv = _convert_port_to_host_priv(param_1[2]);
    uVar3 = _host_processor_set_priv(host_priv,set_name,set);
    param_2[7] = uVar3;
    _pset_deallocate(pVar2);
    if (param_2[7] == 0) {
      iVar1 = param_1[7];
      if ((iVar1 != 0) && (iVar1 != -1)) {
        _ipc_port_release_send(iVar1);
      }
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e01bc;
      uVar3 = _convert_pset_to_port(local_8);
      param_2[9] = uVar3;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

