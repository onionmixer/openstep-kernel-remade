/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c051 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0015c051(void)

{
  undefined4 *puVar1;
  
  _bzero(_mtime,_page_size);
  _splhigh();
  _get_calendar_time_value(&_time);
  puVar1 = _mtime;
  if (_mtime != (undefined4 *)0x0) {
    _mtime[2] = _time;
    puVar1[1] = DAT_001dee3c;
    *puVar1 = _time;
  }
  _splx();
  return;
}

