/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb1d8. */
void __cdecl NXFreeHashTable(NXHashTable *table)
{
  sub_1CB174(table, 1); /*0x1cb1e2*/
  free(table->buckets); /*0x1cb1eb*/
  free(table); /*0x1cb1f1*/
}
