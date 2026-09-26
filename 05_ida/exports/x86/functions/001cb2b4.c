/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb2b4. */
BOOL __cdecl NXCompareHashTables(NXHashTable *table1, NXHashTable *table2)
{
  unsigned int v2; // ebx
  void *data; // [esp+Ch] [ebp-Ch] BYREF
  NXHashState state; // [esp+10h] [ebp-8h] BYREF

  if ( table1 == table2 ) /*0x1cb2c5*/
    return 1; /*0x1cb306*/
  v2 = NXCountHashTable(table1); /*0x1cb2cd*/
  if ( v2 == NXCountHashTable(table2) ) /*0x1cb2da*/
  {
    state = NXInitHashState(table1); /*0x1cb2e2*/
    while ( NXNextHashState(table1, &state, &data) ) /*0x1cb2ff*/
    {
      if ( !NXHashMember(table2, data) ) /*0x1cb30d*/
        return 0; /*0x1cb317*/
    }
    return 1; /*0x1cb2ff*/
  }
  return 0; /*0x1cb31e*/
}
