/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb240. */
int __cdecl NXIsEqualHashTable(NXHashTable *table, NXHashTable *a2)
{
  unsigned int v2; // ebx
  void *data; // [esp+Ch] [ebp-Ch] BYREF
  NXHashState state; // [esp+10h] [ebp-8h] BYREF

  if ( table == a2 ) /*0x1cb251*/
    return 1; /*0x1cb292*/
  v2 = NXCountHashTable(table); /*0x1cb259*/
  if ( v2 == NXCountHashTable(a2) ) /*0x1cb266*/
  {
    state = NXInitHashState(table); /*0x1cb26e*/
    while ( NXNextHashState(table, &state, &data) ) /*0x1cb28b*/
    {
      if ( !NXHashMember(a2, data) ) /*0x1cb299*/
        return 0; /*0x1cb2a3*/
    }
    return 1; /*0x1cb28b*/
  }
  return 0; /*0x1cb2aa*/
}
