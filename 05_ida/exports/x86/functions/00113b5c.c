/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113b5c. */
int mbinit()
{
  vm_size_t v0; // ebx
  int v1; // esi
  int v2; // ebx

  if ( page_size > 0xFFF ) /*0x113b6d*/
    v0 = 1; /*0x113b80*/
  else
    v0 = 0x1000 / page_size; /*0x113b7a*/
  v1 = splimp(); /*0x113b8a*/
  v2 = 10 * v0; /*0x113b93*/
  if ( !m_clalloc(v2, 0) || !m_clalloc(v2, 1) ) /*0x113ba7*/
    panic(aMbinit); /*0x113bc1*/
  return splx(v1); /*0x113bc9*/
}
