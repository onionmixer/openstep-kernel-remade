/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf348. */
void __cdecl sub_1CF348(NXHashTable *table, const char **data, unsigned int a3)
{
  int *v3; // esi
  int *v4; // edi
  char *v5; // esi
  char *v6; // ebx
  const char *v7; // [esp-Ch] [ebp-18h]

  v3 = (int *)sub_1CF25C((unsigned int)data); /*0x1cf35a*/
  v4 = (int *)sub_1CF25C(a3); /*0x1cf362*/
  v5 = _nameForHeader(*v3); /*0x1cf36c*/
  v6 = _nameForHeader(*v4); /*0x1cf376*/
  _objc_inform("Both %s and %s have implementations of class %s.", v5, v6, data[2]); /*0x1cf386*/
  if ( *(_DWORD *)(*v4 + 12) == 3 ) /*0x1cf394*/
  {
    NXHashInsert(table, data); /*0x1cf39e*/
    _objc_inform("Using implementation from %s.", v5); /*0x1cf3a4*/
  }
  else
  {
    _objc_inform("Using implementation from %s.", v7); /*0x1cf3ae*/
  }
}
