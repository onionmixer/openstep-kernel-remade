/* GHIDRADEC_FUNCTION index=470 start=0x4016798 */

void _unp_discard(int param_1)

{
  *(sword *)(param_1 + 0x10) = *(sword *)(param_1 + 0x10) + -1;
  _unp_rights = _unp_rights + -1;
  _closef(param_1);
  return;
}

