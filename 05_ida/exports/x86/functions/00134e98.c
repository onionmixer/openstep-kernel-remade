/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134e98. */
int __cdecl sub_134E98(unsigned int a1)
{
  int v1; // ebx
  int v2; // esi
  int v3; // esi
  int result; // eax

  v1 = a1; /*0x134e9d*/
  v2 = splimp(); /*0x134ea5*/
  while ( !*(_DWORD *)(a1 + 4) ) /*0x134ea7*/
    sleep(a1); /*0x134eb3*/
  splx(v2); /*0x134ec2*/
  (*(void (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 28) + 92))( /*0x134ed5*/
    *(_DWORD *)(a1 + 8),
    *(_DWORD *)(a1 + 12));
  vn_rele(*(_DWORD *)(a1 + 8)); /*0x134edb*/
  v3 = splimp(); /*0x134ee5*/
  LOBYTE(v1) = a1 & 0x80; /*0x134ee7*/
  if ( !*(_WORD *)(v1 + 10) ) /*0x134eed*/
    panic(aMfree_9); /*0x134efb*/
  --word_1E917C[*(__int16 *)(v1 + 10)]; /*0x134f08*/
  ++word_1E917C[0]; /*0x134f10*/
  *(_WORD *)(v1 + 10) = 0; /*0x134f17*/
  if ( *(_DWORD *)(v1 + 4) > 0x7Fu ) /*0x134f23*/
    mclput(v1); /*0x134f26*/
  *(_DWORD *)v1 = mfree; /*0x134f34*/
  *(_DWORD *)(v1 + 4) = 0; /*0x134f36*/
  *(_DWORD *)(v1 + 124) = 0; /*0x134f3d*/
  mfree = v1; /*0x134f44*/
  result = splx(v3); /*0x134f4b*/
  if ( m_want ) /*0x134f5a*/
  {
    m_want = 0; /*0x134f5c*/
    return wakeup((int)&mfree); /*0x134f6b*/
  }
  return result; /*0x134f73*/
}
