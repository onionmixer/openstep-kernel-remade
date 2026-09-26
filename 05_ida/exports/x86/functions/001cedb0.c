/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cedb0. */
void __cdecl objc_addClass(Class myClass)
{
  if ( !myClass->cache ) /*0x1cedb6*/
  {
    myClass->cache = (objc_cache *)&emptyCache; /*0x1cedbc*/
    myClass->info = 1; /*0x1cedc3*/
  }
  if ( !myClass->isa->cache ) /*0x1cedcc*/
  {
    myClass->isa->cache = (objc_cache *)&emptyCache; /*0x1cedd2*/
    myClass->isa->info = 2; /*0x1ceddb*/
  }
  NXHashInsert(dword_1E5600, myClass); /*0x1cedea*/
}
